#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

FILENAME p_blosum;
int    p_verbose;
int	p_printall;
FILENAME p_blosum_qij;
float  p_beta;
int    p_kmax;
int    p_kmin;
int     p_exself;

PARAM   param[] = {
	"-v", VSWITCH	p_verbose, "Verbose mode", "0",
	"-blf", VFNAME p_blosum, "Blosum matrix filename", "/home/projects/vaccine/people/morni/matrices/BLOSUM50",
	"-pa", VSWITCH	p_printall, "Print all against all score [default is best score only", "0",
	"-beta", VFLOAT p_beta, "Hadamard power of blosum matrix", "0.11387",
        "-kmin", VINT p_kmin, "Min value of k for k-mers", "1",
        "-kmax", VINT p_kmax, "Max value of k for k-mers", "30",
        "-blqij", VFNAME p_blosum_qij, "Blosum qij matrix filename", "/home/projects/vaccine/people/morni/matrices/blosum62.qij",
	"-xs", VSWITCH  p_exself, "Exclude self", "0",
	0
};

/* global variables */
float	**k1;

float	**fmatrix_k1( float **blm_qij )

{
	int	k, j;
	float	*marg;
	float	sum;

	marg = fvector( 0, 19 );
        k1 = fmatrix(0, 19, 0 , 19);

/*normalize matrix by marginal frequencies*/
        for (j=0;j<20;j++) {
              sum = 0;
              for (k=0;k<20;k++) 
                  sum+=blm_qij[j][k];
              marg[j]=sum;
        }

        /*calculate K1*/
        for (j=0;j<20;j++) {
              for (k=0;k<20;k++) {
                  k1[j][k] = blm_qij[j][k]/(marg[j]*marg[k]);
                  k1[j][k] = pow( k1[j][k], p_beta );
              }
        }

	return( k1 );
}

float    k2_prod( SEQLIST *s1, SEQLIST *s2, int start1, int start2, int k )

{
        float k2;
        int x, i1, i2;

        k2 = 1;
        for (x=0; x<k; x++) {
             i1 = s1->i[x+start1];
             i2 = s2->i[x+start2];
             k2 *= k1[i1][i2];
        }
        return( k2 );
}

float    k3_sum( SEQLIST *s1, SEQLIST *s2 )

{
        float k3, prod;
        int k,l1,l2;
        int start1,start2;

        k3 = 0;
        l1 = s1->len;
        l2 = s2->len;

        for (k=p_kmin; k<=p_kmax; k++) {
          for (start1=0; start1<=l1-k; start1++) {
              for (start2=0; start2<=l2-k; start2++) {
                  prod = k2_prod( s1, s2, start1, start2, k);
                  k3 += prod;
              }
          }
        }
        return( k3 );
}

float	**read_blosummat_qij( char *filename, char **alphabet )

{

	int	i,j, nc;
	LINELIST	*linelist, *ln;
	float	**mat;
	float	*tvec;

	linelist = linelist_read( filename );

	if ( ! linelist ) {
		printf( "Error. Cannot read linelist from %s\n", filename );
		exit( 1 );
	}

	mat = fmatrix( 0, 19, 0 ,19 );
	*alphabet = cvector( 0, 20 );

	for ( ln = linelist; ln; ln=ln->next ) {

		if ( strlen( ln->line ) <= 0 ) continue;

		if ( strncmp( ln->line, "#", 1 ) == 0 ) continue;

		if ( strncmp( ln->line, "   A", 4 ) == 0 ) {

                        for ( i=0;i<20;i++ )
                                (*alphabet)[i] = ln->line[i*7+3];

                        (*alphabet)[20] = 0;
			j=0;
                }
		else {
			tvec = fvector_split_3( ln->line, &nc , " ");
			
			for ( i=0; i<nc; i++ ) {
				mat[j][i] = tvec[i];
				mat[i][j] = tvec[i];		
			}

			j++;

			fvector_free( tvec, 0, nc-1 );
		}
	}

	linelist_free( linelist );

	return( mat );
}

int main( int argc, char *argv[] )

{
	SEQLIST	 *pep1, *peplist1, *pl1;
	SEQLIST  *pep2, *peplist2, *pl2;
	SEQLIST	*bestp;
	char	*alphabet;
	float	best_sco, sco;
	int	j, ix;
	float	**blm_qij;

	/* Parse command line options */
	pparse( &argc, &argv, param, 2, "seqfile1 seqdb" );

	/***************************/
       /* Read BLOSUM matrix */   

	bl_init_file( p_blosum );

	blm_qij = read_blosummat_qij( p_blosum_qij, &alphabet );

	k1 = fmatrix_k1( blm_qij );

      /***** READ LIST OF PEPTIDES FROM FILES *********/
        	
       peplist1 = seqlist_read( argv[1] );
 	   	   
       /*encode as blosum indices, and calculate normalization factor for k3*/
       for ( pep1=peplist1; pep1; pep1=pep1->next ) {

	     	pep1->i = ivector( 0, pep1->len-1 );

	     	for ( j=0; j<pep1->len; j++) {

			ix = strpos( alphabet, pep1->seq[j] );

			if ( ix < 0 ) {
				printf( "Error. Unknown amino acid %c\n", pep1->seq[j] );
				exit( 1 );
			}

	        	pep1->i[j] = ix; 

	     	}

		pep1->aff = k3_sum(pep1,pep1);
	}

	peplist2 = seqlist_read( argv[2] );

	for ( pep2=peplist2; pep2; pep2=pep2->next ) {

             	pep2->i = ivector( 0, pep2->len-1 );

             	for ( j=0; j<pep2->len; j++) {

                	ix = strpos( alphabet, pep2->seq[j] );

                	if ( ix < 0 ) {
                        	printf( "Error. Unknown amino acid %c\n", pep2->seq[j] );
                        	exit( 1 );
                	}

                	pep2->i[j] = ix;

             	}

		pep2->aff = k3_sum(pep2,pep2);
        }

       	for (pep1=peplist1; pep1; pep1=pep1->next ) {

		bestp = NULL;
		best_sco = -99.9;

		for ( pep2=peplist2; pep2; pep2=pep2->next ) {

			if ( p_exself && strcmp( pep1->seq, pep2->seq ) == 0 )
                                continue;

			sco =  k3_sum(pep1,pep2)/sqrt( pep1->aff * pep2->aff );

			if ( sco > best_sco ) {
				best_sco = sco;
				bestp = pep2;
			}

			if ( p_printall ) 
				printf( "ALL %s %s %f\n", pep1->seq, pep2->seq, sco );
		}

		printf( "Best %s %s %f\n", pep1->seq, bestp->seq, best_sco );

       	}

       	exit( 0 );
}
