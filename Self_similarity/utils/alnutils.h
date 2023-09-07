/* Morten Nielsen 21 May 2006. mniel@cbs.dtu.dk */

/* ALN database utilities */

typedef struct aln {
	struct aln *next;

	int     alen;
	WORD    type;

	WORD    qname;
	int     qchlen;		/* query chain length */
	int     qlen;		/* query structure length */
	int     qof;
	char   *qal;		/* alen */
	char   *qssp;		/* alen */
	char   *qseq;		/* qlen */
	THREED *qxyz;		/* qlen - assignable */
	float  *qvec;		/* qlen - assignable */
	float   qsscore;	/* q selfscore */

	WORD    dname;
	int     dchlen;		/* database chain length */
	int     dlen;		/* database structure length */
	int     dof;
	char   *dal;		/* alen */
	char   *dssp;		/* alen */
	char   *dseq;		/* dlen */
	THREED *dxyz;		/* dlen - assignable */
	float  *dvec;		/* dlen - assignable */
	float   dsscore;	/* d selfscore */

	int     mlen, nid, ngap, slen;
	float   score, sscore, rscore, zscore;
	float   armsd, qv;
	int     c1, c2, c3, c4;
	float   f1, f2, n3, n4;
	float  *svec;		/* alen */

	float ***mx;		/* [nx][qchlen][dchlen] */
	int     nx;		/* number of temp matrices */

} ALN;

extern void set_aln_verbose(int mode);

extern ALN *aln_alloc();

extern void aln_qalloc(ALN * a, PRF * q);

extern void aln_dalloc(ALN * a, PRF * d);

extern void aln_rmsd(ALN * a);

extern void aln_rmsd_rot_trans(ALN * a, THREED **cen, float ***rot);

extern ALN *aln_read(char *filename);

extern ALN *aln_read_fp( FILE * fp);

extern ALN *aln_pread( char *filename );

extern void aln_free(ALN * aln);

extern void aln_print_single(ALN * p);

extern void aln_print(ALN * aln);

extern void aln_write_single_fp(ALN * a, FILE * fp);

void aln_write_single(ALN * a );

extern void aln_write(ALN * aln, char *filename, int ff );

extern void aln_nid(ALN * aln);

/* SW and NW Source code provided by O. Lund: */

extern void nw_sco(float **m,	/* Scoring matrix */
	int l1,			/* Length of first sequence */
	int l2,			/* Length of second sequence */
	float fg,		/* Penalty for first gap */
	float ng,		/* Penalty for each of subsequent gaps */
	float eg,		/* Penalty for end gaps [0|1] */
	float **sco,		/* cumulative/max score matrix */
	int **from_i,		/* Trace back vector 1 */
	int **from_j /* Trace back vector 2 */ );

extern void nw_sco2(float **m,	/* Scoring matrix */
	int l1,			/* Length of first sequence */
	int l2,			/* Length of second sequence */
	float fg,		/* Penalty for first gap */
	float ng,		/* Penalty for each of subsequent gaps */
	float eg,		/* Penalty for end gaps [0|1] */
	float *score,		/* Maxscore */
	float **msco /* Match scores */ );

extern void nw_ali(int l1,	/* Length of first sequence */
	int l2,			/* Length of second sequence */
	int **from_i,		/* Trace back vector 1 */
	int **from_j,		/* Trace back vector 2 */
	char *dseq,		/* First sequence */
	char *qseq,		/* Second sequence */
	char *dpal,		/* Alignment of first sequence */
	char *qpal,		/* Alignment of second sequence */
	int *allen /* Length of alignment */ );

extern void nw_ali2(int l1,	/* Length of first sequence */
	int l2,			/* Length of second sequence */
	float fg,		/* Penalty for first gap */
	float ng,		/* Penalty for each of subsequent gaps */
	float eg,		/* Penalty for end gaps [0|1] */
	float **msco,		/* Match scores */
	char *s1,		/* First sequence */
	char *s2,		/* Second sequence */
	char *al1,		/* Alignment of first sequence */
	char *al2,		/* Alignment of second sequence */
	int *allen /* Length of alignment */ );

extern void nw_n3(float **m,	/* Scoring matrix */
	int l1,			/* Length of first sequence */
	int l2,			/* Length of second sequence */
	float fg,		/* Penalty for first gap */
	float ng,		/* Penalty for each of subsequent gaps */
	float eg,		/* Penalty for end gaps [0|1] */
	char *s1,		/* First sequence */
	char *s2,		/* Second sequence */
	char *al1,		/* Alignment of first sequence */
	char *al2,		/* Alignment of second sequence */
	int *allen,		/* Length of alignment */
	float *maxscore /* Score of alignment */ );

extern float blosum62_score_function(PRF *q, int i, PRF *d, int j);

extern float **sm_b62(PRF *q, PRF *d);

extern	float **sm_b62_fsa( FSALIST *q, FSALIST *d );

extern float ss_b62(PRF *q);

extern float ss_b62_fsa( FSALIST *q );

extern float proalign_score_function(PRF *q, int i, PRF *d, int j);

extern float **sm_proalign(PRF *q, PRF *d);

extern float ss_proalign(PRF *q);

extern void sw_sco(float **m,	/* Scoring matrix */
	int l1,			/* Length of first sequence */
	int l2,			/* Length of second sequence */
	float fg,		/* Penalty for first gap */
	float ng,		/* Penalty for each of subsequent gaps */
	float *score,		/* maxscore */
	float **msco,		/* match scores */
	int *firsti,		/* first residue in sequence 1 */
	int *firstj		/* first residue in sequence 2 */
);

extern void sw_ali(int l1, int l2, float fg, float ng, float **sco,
	char *s1, char *s2, char *al1, char *al2, int *alen, int firsti,
	int firstj);

extern void sw_align(int stype, float frstgap, float nextgap,
	PRF *q, PRF *d, char *qal, char *dal, int *qof, int *dof,
	char *type, float *score, int *alen, int *mlen, int *nid, int *ngp,
	float *rmsd, FILE *fp);

extern ALN *aln_prf_sw(int stype, float frstgap, float nextgap,
	PRF *q, PRF *d);

extern ALN *aln_sw_setup(int stype,	/* Score matrix type */
	PRF *q,		/* PRF entry Q (Query) */
	PRF *d		/* PRF entry D (Database) */
);

extern void aln_sw(ALN *a,	/* alignment structure */
	float frstgap,		/* First gap penalty */
	float nextgap		/* Next gap penalty */
);

extern void aln_free_single(ALN * a);

extern float gf_linear(PRF * q, PRF * d, float fg, float ng,
        int qstart, int qend, int dstart, int dend);

extern float gf_chbrk(PRF * q, PRF * d, float fg, float ng,
        int qstart, int qend, int dstart, int dend);

extern void swagl(
        float **m,              /* Score matrix */
        PRF * q,                /* query pef structures */
        PRF * d,                /* database pef structures */
        float fg,               /* Penalty for first gap */
        float ng,               /* Penalty for each subsequent gap */
        int mg,                 /* Maximal gap length ( not used ) */
        float   (*gf) (PRF *, PRF *, float, float, int, int, int, int),
                                /* Name of gap function */
        char *al1,              /* Alignment of first sequence */
        char *al2,              /* Alignment of second sequence */
        int *alen,              /* Length of alignment */
        float *maxscore,        /* Score of alignment */
        int *firsti,            /* First res in first seq in best local aln */
        int *firstj             /* First res in second seq in best local aln */
);


extern	ALN     *aln_insert( ALN *list, ALN *last, ALN *new, int type );

extern	ALN     *aln_isx( PRF *q, PRF *db, ALN *aln );

extern	ALN     *fsa_align( char *s1, int l1, char *s2, int l2 );

extern	ALN	*fsa_align_bls( char *s1, int l1, char *s2, int l2, int bls, float gf, float gn );
