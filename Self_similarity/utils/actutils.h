/* M. Nielsen. Sept 2004. mniel@cbs.dtu.dk */

/*=
        ACT utils
=*/

typedef struct actlist {
        struct actlist *next;
	char	asn;
	char	aa;
        WORD    name;
	int	n;
	float	*act;
	int	na;
} ACTLIST;

extern	ACTLIST *actlist_alloc();

extern	void    actlist_free( ACTLIST   *actlist );

extern	ACTLIST *actlist_read( FILE *fp, char *lastline );

extern	ACTLIST *actlist_paste( ACTLIST *actlist, FILE *fp );

extern	ACTLIST *actlist_addsparse( ACTLIST *actlist, char *alphain, float imin, float imax );

extern	ACTLIST **actlist_table( int n );

extern	void    actlist_table_free( ACTLIST **table, int n );

extern void    actmult( ACTLIST *actlist, float factor );

extern	float   *act2howinp( ACTLIST **act_table, int i, int ninp, float imin, float imax,int whz, int alen );

extern	float   *act2howinp_new2( ACTLIST **act_table, int i, int ninp, float imin, float imax,int whz, int alen,
        float *comp, int ncomp, float lsize, int lenpos, int enc_end );

extern	float   *act2howinp_new3( ACTLIST **act_table, int i, int ninp, float imin, float imax,int whz, int alen,
        float *comp, int ncomp, float lsize, int lenpos, int enc_end, int iholel, int iholer, int show );

extern	float   *act2howinp_new( ACTLIST **act_table, int i, int ninp, float imin, float imax,int whz, int alen,
        float *comp, int ncomp, float lsize, int lenpos );
extern ACTLIST *actlist_cpy( ACTLIST   *actlist );

extern ACTLIST *actlist_pastelist( ACTLIST *actlist1, ACTLIST *actlist2 );

extern void    actlist_free2( ACTLIST  *actlist );

ACTLIST *actlist_filename_read( char *filename );
