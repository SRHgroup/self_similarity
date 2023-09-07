/* October 2009 Morten Nielsen */

typedef struct pdbatomlist {
	struct	pdbatomlist	*next;
	THREED	xyz;
	int	resnum;
	char	inscode;
	char	atom_type[5];
	char	res[4];	
} PDBATOMLIST;

typedef struct pdblist  {
        struct  pdblist *next;
        char    *seq;
        char    name[255];
        int     nres;
	char	**res;
	char	chain;
	THREED	*caxyz;
	THREED  *cmxyz;
	char	*inscode;
	int	*resnum;
	char	**atom_type;
	PDBATOMLIST	**atoms;
} PDBLIST;

extern	void    pdblist_free_single( PDBLIST *pdb );

extern PDBLIST *pdblist_alloc();

extern PDBLIST *pdblist_read_ch( FILENAME filename, char ch );

extern	void    pdblist_print( PDBLIST  *pdb );

extern	char single_letter_hetcode(char *type);
