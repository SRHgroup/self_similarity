/* M. Nielsen Mar 2020. mniel@cbs.dtu.dk */

typedef struct thrlist {
        struct thrlist *next;
        WORD    all;
        float   thr;
        float   score;
}THRLIST;

extern THRLIST        *thrlist_alloc();

extern THRLIST        *thrlist_read( char *filename );

extern void    thrlist_free( THRLIST *thrlist );

extern float   find_thr_score( THRLIST *thrlist, float score );

extern	THRLIST *find_thr( THRLIST *thrlist, float score );
