/* M. Nielsen. Sept 2002. mniel@cbs.dtu.dk */

/*= 
	HOW utils 
=*/

typedef struct howlist  {
        struct 	howlist *next;
        char   	*aach;
	char	*data;
        char   	name[255];
	int	len;
	float	score;
} HOWLIST;

extern	void    howlist_free( HOWLIST *how );

extern	HOWLIST *howlist_alloc();

extern	HOWLIST *howlist_read( FILENAME filename );

extern	HOWLIST *howlist_read_single( FILE *fp );

extern	HOWLIST *howlist_find( char *name, HOWLIST *list, char *pattern );

extern	void    how_print( HOWLIST *l );

extern	HOWLIST	*howlist_append( HOWLIST *list, HOWLIST *n, HOWLIST **last );

extern	HOWLIST	*howlist_insert( HOWLIST *list, HOWLIST *n );

extern  void    how_print_fp( HOWLIST *l, FILE *fp );
