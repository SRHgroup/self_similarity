/* M. Nielsen. Feb 2003. mniel@cbs.dtu.dk */

/*=
        Gibbss Utilities

=*/


typedef struct mhclist {
        struct mhclist *next;
        WORD    mhc;
        char    *mhcseq;
        float   *mhcenc;
        int     mhcl;
	int	*i;
	THRLIST *thrlist;
} MHCLIST;


typedef struct seqlist {
        struct seqlist *next;
        char    *seq;
        int     len;
        int     *i;
	int	*im;
	int	*ic;
        float   w;
        int     u;
	int     trash;
	int	clen;
	int	*mask;
	float	**wlf;
	float	**wrf;
	float	**enc;
	int	offset;
	float	aff;
	WORD	mhc;
	char	*mhcseq;
	float	*mhcenc;
	int	mhcl;
	float	*fvec;
	int	*toff;
        int	ngap;   
	int	pgap;
	int	lgap;
	int	pins;
	int	lins;
        char    *contextseq;
        float   *contextenc;
        int     contextl;
	MHCLIST	*mhclist;
	MHCLIST	*bestml;
	int	nmhc;
	float   exp;
} SEQLIST;

typedef struct allelelist {
        struct allelelist *next;
        MHCLIST *mhclist;
        WORD   mhc;
	int     nmhc;
} ALLELELIST;


extern	SEQLIST *seqlist_alloc();

extern	SEQLIST *fsalist2seqlist( FSALIST *list );

extern	SEQLIST **seqlist_table( int n );

extern  SEQLIST ***seqlist_matrix( int n, int m );

extern SEQLIST *seqlist_read( FILENAME filename );

extern SEQLIST *seqlist_read_wexp( FILENAME filename );

extern	SEQLIST *seqlist_read_wmhc( FILENAME filename );

extern  SEQLIST *seqlist_read_wmhc_wexp( FILENAME filename );

extern	SEQLIST *seqlist_read_wmhc_wcontext( FILENAME filename );

extern	SEQLIST *seqlist_read_wmhc_wcontext_wexp( FILENAME filename );

extern  SEQLIST *seqlist_read_wmhc_woffset( FILENAME filename );

extern	SEQLIST *seqlist_read_woffset( FILENAME filename );

extern	float   cal_w( SEQLIST *slist, int *o );

extern	void    lowcount_correct( float **aafrec, float neff, int l,
		float **blf, float wlowcount );

extern	float   cal_aalomat( SEQLIST *slist, float **aafrec, float **aalo, 
		int *startpos, float **aacounts, float *aabgfrec, 
		float **aaraw, float **blf, float wlowcount );

extern	int     *phase_shift( int nseq, int *startpos, SEQLIST *slist, float *aabgfrec, float *en, int ns, float **blf, float wlowcount, char *p1letters );


extern	void    gib_print_aln( FILENAME filename, SEQLIST *list, int *startpos );

extern 	int     remove_seq( SEQLIST *slist, float **aalo, float thr );

extern	int     *phase_shift_bias( int nseq, int *startpos, SEQLIST *slist, float *aabgfrec, float *en, int ns, float **blf, float wlowcount, float **mbias, float wbias );

extern	float   cal_w_cluster( SEQLIST *slist, int *startpos, float thr );

extern	float   cal_w_cluster_bl( SEQLIST *slist, int *startpos, float thr, float **blm );

extern	float   cal_w_cluster_wMHC( SEQLIST *slist, int *startpos, float thr );

extern	void    set_seqwtype( int type );

extern	void    set_idthr( float thr );

extern	void    set_weights( float *weights, int n );

extern	void    set_nocount_aalo( float score );

extern	void    set_posC( int i );

extern	void	set_factor( float factor );

extern	void    set_NAA( int n );

extern	void    set_ex_pseudo_p1( int n );

extern	void	set_blsim( void );

extern	MHCLIST *mhclist_alloc();

extern	MHCLIST *mhclist_read( char *filename );

extern	MHCLIST *mhclist_feature_read( char *filename );

extern	void    mhclist_encode( MHCLIST *mhclist, float **blmat, char *alphabet, float max, float min, int bl, int aX, int rescale );

extern	void    mhclist_encode_reset( MHCLIST *mhclist, char *alphabet );

extern	MHCLIST *mhclist_find( MHCLIST *mhclist, char *mhc );

extern  int     mhclist_find_index( MHCLIST *mhclist, char *mhc );

extern  MHCLIST **mhclist_table( int n );

extern  MHCLIST ***mhclist_matrix( int n, int m );

extern	ALLELELIST *allelelist_alloc();

extern	ALLELELIST *allelelist_read( char *filename, MHCLIST *mhclist );

extern	ALLELELIST      *allelelist_find( ALLELELIST *allelelist, char *mhc );
