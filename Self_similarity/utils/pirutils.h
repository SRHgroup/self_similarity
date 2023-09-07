/* Morten Nielsen August 2008. mniel@cbs.dtu.dk */

/* PIR utilities */

typedef struct pirlist  {
        struct  pirlist *next;
        char    *seq;
        char    name[255];
        int     len;
        float   w;
} PIRLIST;

extern	PIRLIST **pirlist_table( int n );

extern	PIRLIST *pirlist_alloc();

extern	PIRLIST *pirlist_read( char *filename );

extern	PIRLIST *fsalist2pirlist( FSALIST *fsalist );

extern	void pirlist_write( PIRLIST *list );

extern  PIRLIST *pirlist_find( char *name, PIRLIST *list );
