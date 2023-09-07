/* M. Nielsen. Nov 2002. mniel@cbs.dtu.dk */

/*=
	Polytope Utils

*/

typedef struct epitope {
        struct epitope *next;
	WORD	desc;
        char    *seq;
        int     l;
        int     s;
	int	os;
	int	bs;
	float	aff;
	int	fixed;
	int	isclassI;
	WORD	type;
} EPITOPE;

typedef struct linker {
        struct linker *next;
        char    *seq;
        int     l;
	int	first;
	int	fixed;
	int	ncys;
} LINKER;

typedef struct bindlist {
	struct bindlist *next;
	WORD	method;
	float	threshold;
	FILENAME file;
	WORD	type;
	float	*epipred;
	float	*howlin_inp;
	float	**howlin_x;
	SYNAPS	*syn;
	char	*alphabet;
	float	**hmmmat;
} BINDLIST;

typedef struct matlist_poly {
        struct matlist_poly *next;
        WORD    all;
        WORD    method;
	int	l;
	float	**mat;
	char	*alphabet;
	float	*pred;
        int	npred;
} MATLIST_POLY;

extern	EPITOPE	*epitope_alloc();

extern	EPITOPE        *epitope_append( EPITOPE *list, EPITOPE *n,
        		EPITOPE **last );

extern	LINKER	*linker_alloc();

extern	LINKER        *linker_append( LINKER *list, LINKER *n,
        		LINKER **last );

extern	void    print_polytope( LINKER **linker, EPITOPE **epitope, int n );

extern	void	linker_defmaxlnk( int mlnk );

extern	void	linker_defcodeaa( char aa );

extern	void	def_epithr( float epim );

extern	void	def_epilength( int epilen );

extern	EPITOPE	*is_epi( EPITOPE **epi_tab, int n, int i );

extern	void    epi_swap( EPITOPE **epi1, EPITOPE **epi2 );

extern	void    print_perf_table_c( EPITOPE **epi_tab, int n, float *howlin_nn, 
		float *how_nn,
                int len, int sum, int endcc, float cthr, float cthrne,
                float eepi, float ecc, float ewc );

extern	void    print_perf_table_supertype( EPITOPE **epi_tab, int n, 
		BINDLIST *bindlist, 
		float *how_nn,
                int len, int sum, int endcc, float cthr, float cthrne,
                float eepi, float ecc, float ewc );

extern	void    print_perf_table_mat( EPITOPE **epi_tab, int n, 
		MATLIST_POLY *matlist, 
		float *how_nn,
                int len, int sum, int endcc, float cthr, float cthrne,
                float eepi, float ecc, float ewc, float bthr );

extern  void    print_perf_table_d( EPITOPE **epi_tab, int n, float *howlin_nn,
		float *how_nn,
		int len, int endcc, float cthr, float dwithin, float cthrne );

extern	void    print_performance_c( EPITOPE **epi_tab, int nepitope,
	char *seq, float *howlin_nn, float *how_nn,
        float cthrne, float cthr, int endcc );

extern	void    print_performance_supertype( EPITOPE **epi_tab, int nepitope,
	char *seq, BINDLIST *bindlist, float *how_nn,
        float cthrne, float cthr, int endcc );

extern	void    print_performance_mat( EPITOPE **epi_tab, int nepitope,
	char *seq, MATLIST_POLY *matlist, float *how_nn,
        float cthrne, float cthr, int endcc, float bthr );

extern	void    print_performance_d( EPITOPE **epi_tab, int nepitope,
	char *seq, float *howlin_nn, float *how_nn,
	float dwithin, float cthrne, float cthr, int endcc );

extern void    print_annfile( FILENAME filename, EPITOPE **epi_tab, int n, int len );

extern void    print_colfile( FILENAME filename, float *howlin_nn, float *how_nn, char *seq );

extern void	define_polytope( FILENAME filename, EPITOPE ***epitope_tab, int *nepi, 
		LINKER ***linker_tab, int *nlnk, int *ll, int pfix );

extern EPITOPE         *read_epitope( FILENAME filename );

extern EPITOPE *find_epitope( EPITOPE *epitope, char *seq );

extern BINDLIST	*bindlist_read( FILENAME filename );

extern BINDLIST        *bindlist_alloc();

typedef struct mlist {
        struct mlist *next;
        WORD    st;
        WORD    type;
        WORD    all;
        WORD    method;
        float   resc;
} MLIST;

extern	MLIST   *mlist_find( MLIST *list, char *st );

extern	MLIST   *mlist_read( FILENAME filename );

extern	MLIST *mlist_alloc();

extern	void    set_mlist_verbose( int i);

extern	MATLIST_POLY   *matlist_poly_find( MATLIST_POLY *list, char *all, int l );

extern	MATLIST_POLY   *matlist_poly_read( FILENAME filename );

extern	MATLIST_POLY *matlist_poly_alloc();

extern	void    set_matlist_poly_verbose( int i);
