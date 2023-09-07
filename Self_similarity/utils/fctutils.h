/* M. Nielsen. August 2002. mniel@cbs.dtu.dk */

/*=
	PROTFUN Utilities

=*/

typedef struct fct {
	struct 	fct *next;
	WORD    name;
	float	*prob;
	float	*odds;
	WORD	*desc;
	int	ncl;
} FCT;

extern FCT *fct_alloc();

extern FCT *protfun_read(char *filename);

extern	FCT *euklid_read( char *filename );

extern	void	fct_free( FCT *list );

extern	FCT *find_fct( WORD name, FCT *list );

typedef struct nnep {
        struct nnep *next;
	WORD	name;
	float	*vec;
} NNEP;

extern NNEP *nnepalloc();

extern NNEP *nnep_read(char *filename);

extern void	nnep_free( NNEP *list );

extern NNEP    *find_nnep( WORD name, NNEP *list );
