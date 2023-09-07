/* M. Nielsen. Sept 2002. mniel@cbs.dtu.dk */

/*= 
	Fasta utils 
=*/


typedef struct fsalist  {
        struct 	fsalist *next;
        char   	*seq;
        char   	name[255];
	int	len;
	float	score;
	int	*i;
} FSALIST;

extern	void    set_fsa_verbose( int type );

extern	void    fsalist_free( FSALIST *fsa );

extern	FSALIST *fsalist_alloc();

extern	FSALIST *fsalist_read( FILENAME filename );

extern	FSALIST *fsalist_read_single( FILE *fp );

extern	FSALIST *fsalist_read_single_long( FILE *fp );

extern	FSALIST *fsalist_find( char *name, FSALIST *list, char *pattern );

extern	void    fsa_print( FSALIST *l );

extern	FSALIST	*fsalist_append( FSALIST *list, FSALIST *n, FSALIST **last );

extern	FSALIST	*fsalist_insert( FSALIST *list, FSALIST *n );

extern	FSALIST **fsalist_table( int n );

extern  void    fsa_print_fp( FSALIST *l, FILE *fp );

extern	void    fsalist_seq2upper( FSALIST *fsalist );

extern	void    fsalist_checkalpha( FSALIST *fsalist );

extern FSALIST *fsalist_check_names( FSALIST *fsalist );

extern	PRF	*fsalist2prf( FSALIST *fsalist );

extern	PEPLIST    *fsalist2pep( FSALIST *fsalist, int l );

extern	PEPLIST    *fsalist2pep_single( FSALIST *fsa, int l, int step );

extern	PEPLIST    *fsalist2pep_single_klast( FSALIST *fsa, int l, int step, PEPLIST **peplast );

extern	void    fsalist_iassign_profile_order( FSALIST *fsalist );

extern	void    fsalist_write_filename( FSALIST *fsalist, char *filename );

extern	FSALIST *fsalist_find_new( FSALIST *list, char *name );

extern	void    fsalist_write_filename_single( FSALIST *fsa, char *filename );

extern	void    fsalist_checkalphabet( FSALIST *fsalist, char *alphabet );

extern	void    fsalist_checkalphabet_replace( FSALIST *fsalist, char *alphabet, char c );

extern	FSALIST *fsalist_sort( FSALIST *fsalist );
