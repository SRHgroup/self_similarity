/* M. Nielsen. Sept 2002. mniel@cbs.dtu.dk */

/*= 
	PEP utils 
=*/

typedef struct peplist  {
        struct 	peplist *next;
        WORD	pep;
	int	len;
	float	score;
	float	aff;
	float	rank;
	float	nM;
	int	nn;
	int	*iv;
	LINE	line;
} PEPLIST;

extern	void    set_pep_verbose( int type );

extern	void    peplist_free( PEPLIST *pep );

extern	PEPLIST *peplist_alloc();

extern	PEPLIST *peplist_read( FILENAME filename );

extern  PEPLIST *peplist_read2( FILENAME filename );

extern	PEPLIST *peplist_read_XX( FILENAME filename );

extern	PEPLIST *peplist_read_thr( FILENAME filename, float thr );

extern	PEPLIST *peplist_pread( FILENAME filename );

extern	PEPLIST *peplist_read_single( FILE *fp );

extern	void    pep_print( PEPLIST *l );

extern	PEPLIST	*peplist_append( PEPLIST *list, PEPLIST *n, PEPLIST **last );

extern	PEPLIST	*peplist_insert( PEPLIST *list, PEPLIST *n );

extern  void    pep_print_fp( PEPLIST *l, FILE *fp );

extern	void peplist_print_fp( PEPLIST *peplist, FILE *fp );

extern	void peplist_print_file( PEPLIST *peplist, FILENAME filename, int ws );

extern PEPLIST **peplist_table( int n );

extern	PEPLIST *peplist_find( PEPLIST *list, char *pep );

extern	PEPLIST *peplist_sort( PEPLIST *list, int desc );

extern	void    peplist_check_replace( PEPLIST *list, char *alphabet, char c );

typedef struct longpeplist  {
        struct 	longpeplist *next;
        LINE	pep;
	int	len;
	float	score;
	float	aff;
	int	nn;
	int	*iv;
	LONGLINE	line;
} LONGPEPLIST;

extern  LONGPEPLIST *longpeplist_alloc();

extern  LONGPEPLIST *longpeplist_read( FILENAME filename );

extern  void    longpeplist_free( LONGPEPLIST *pep );

