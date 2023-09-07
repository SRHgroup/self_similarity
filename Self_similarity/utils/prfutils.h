/* Morten Nielsen 21 May 2006. mniel@cbs.dtu.dk */

/* PRF database utilities */

typedef struct prf {
	struct prf *next;
	/* PRF variables */
	int	*n;
	WORD    name;		/* entry name */
	int     chlen;		/* chain length */
	WORD    code;		/* PDB file code */
	WORD    swpr;		/* Swiss Prot code */
	char    chain;		/* PDB chain id */
	int     breaks;		/* PDB chain breaks */
	int     len;		/* PDB chain length */
	int	slen;		/* PDB structtuer length */
	WORD    resol;		/* PDB resolution string */
	WORD    pdbdate;	/* PDB deposition date */
	WORD    prfdate;	/* PRF creation date */
	char   *seq;		/* sequence in single letters */
	char   *hseq;		/* PDB hit sequence */
	char   *chn;		/* chain id */
	int    *res;		/* residue index number */
	char   *ins;		/* residue insertion code */
	char   *sec;		/* secondary structure */
	float  *acc;		/* accessibility */
	float  *kap;		/* kappa */
	float  *tau;		/* alpha */
	float  *T;              /* T */
	float  *phi;		/* phi dihedral angle */
	float  *psi;		/* phi dihedral angle */
	THREED *xyz;		/* CA coordinate */
	float  *b;		/* B factors */
	int    *isx;		/* is XYZ a real atom coordinate ? */
	float **f;		/* profile (or AA frequencies ) */
	int     nf;		/* length of profile vector */
	float **a;		/* activities (or probabilities ) */
	int     na;		/* length of activity vector */
	int	*i;		/* User assignable int vector */
	int	ztype;		/* type for score fit */
	float	*z;		/* Parameters for Z score fit */
	int	nz;		/* Number of zscore fit parameters */
	int	nbz;		/* Number of bins for sdev */
	int	*zlbin;		/* chlen thresholds for sdev bins */
	float	*s1;		/* Mean for z score */
	float	*sdev;		/* Sdev for z score */
	float	za;
	float	zb;
	float **d;		/* D User-assignable float vector */
	int     nd;		/* dimensions of D */
	float **g;		/* gap penalty */
	int     ng;		/* dimensions of G */
} PRF;

extern PRF *prf_alloc();

extern PRF *prf_read_single_fp(FILE * fp);

extern PRF *prf_read(char *filename);

extern void prf_free_single( PRF * p );

extern	void    prf_print_single( PRF *prf );

extern void prf_iassign_profile_order( PRF *prf );

extern	PRF     *prf_act_merge( PRF *p, ACTLIST *alist );

extern	PRF     *prf_add_ss2act( PRF *p );

extern	PRF     *prf_ave_sec_act( PRF *p );

extern	PRF     *prf_act_n2norm( PRF *p );

extern	PRF     *prf_act_rescale( PRF *p );

extern	PRF    *prf_read_single( char *filename, char *pfmt, char *afmt, char *ssfmt );

extern	PRF    *prf_readlist(char *filename, char *pfmt, char *afmt, char *ssfmt );

extern	PRF     *prf_add_zscore( PRF *prflist, char *zmt );

extern	PRF     *prf_add_zscore_bz( PRF *prflist, char *zfmt );

extern	PRF     *prf_add_zscore_new( PRF *prflist, char *zfmt, char *dir );

extern	PRF     *prflist_ave_sec_act( PRF *list );

extern	void    prf_ss2dssp( PRF * prf, int min, int max);

extern	void    prf_gap_assign_DSSP( PRF * prf);

extern	void    prf_gap_assign_exposure(PRF * prf);

extern	PRF    *prf_readlist_new(char *filename, char *pdir, char *pfmt, char *afmt, char *ssfmt );

extern	PRF    *prf_read_single_new( char *filename, char *pdir, char *pfmt, char *afmt, char *ssfmt );

extern	PRF    *prf_readlist_new2(char *filename, char *pdir, char *pfmt, char *afmt, char *ssfmt, char *rsfmt );

extern	PRF    *prf_read_single_new2( char *filename, char *pdir, char *pfmt, char *afmt, char *ssfmt, char *rsfmt );

extern  PRF    *prf_read_single_new_user( char *name, char *pdir );

extern	PRF     *prf_add_zscore_user( PRF *prflist, char *dir, char *postfix  );

extern	float *read_rsascale( FILENAME filename, char **alphabet );

extern  PRF     *prflist_ave_rsa_act( PRF *list, float *rsascale, char *rsa_alphabet );

extern 	PRF     *prf_ave_rsa_act( PRF *list, float *rsascale, char *rsa_alphabet );

extern	PRF     *prflist_assign_rsa_act( PRF *list, float *rsascale, char *rsa_alphabet );

extern	PRF     *prf_assign_rsa_act( PRF *list, float *rsascale, char *rsa_alphabet );

extern	void set_prf_verbose( int type );

extern	void    prf_write_bin_fp( PRF *p, FILE *fp );

extern	void    prf_write_bin( PRF *p, char *postfix, char *prfdir );
	
extern	PRF     *prf_read_bin( char *name, char *postfix, char *prfdir );

extern	void    prf_print_single_wact( PRF *prf );

extern	PRF	*prflist_read_bin( char *filename, char *pdir, char *postfix );

extern	PRF     *prf_db_read_bin( char *filename );

extern	int     prf_is_ca( PRF *p );

extern	void    prf_print_single_wact2( PRF *prf, int act, int z );

extern	PRF     *prf_find( PRF *db, char *id );
