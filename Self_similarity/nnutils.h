/* M. Nielsen. April 2002. mniel@cbs.dtu.dk */

/*=
	Network Input Utilities

=*/

#define MAXLAY 10

typedef struct synaps {
	struct synaps *next;
	LINE    nin, nout;
	FILENAME wgtfile;
	int     nlay, *nnlay; /* number of layers, number of neurons in layer */
	float ***wgt;
	float	w;
	int     maxnper;
	LINE	comment;
} SYNAPS;

extern SYNAPS *synaps_alloc();

extern SYNAPS *synaps_read_file(char *filename);

extern	SYNAPS *synaps_read(char *filename);

extern	SYNAPS *synaps_read_pfix(char *filename, char *prefix);

extern	SYNAPS    *synaps_read_nfile(char *filename, int *n);

extern  SYNAPS *synaps_read_fp( FILE *fp );

extern	SYNAPS  *synaps_read_bin_fp( FILE *fp );

extern	SYNAPS  *synlist_read_bin( char *filename );

extern	SYNAPS  *synaps_read_bin_pfix(char *filename, char *prefix);

extern	void    synaps_write_bin_fp( SYNAPS *s, FILE *fp );

extern	void    synaps_write_bin( SYNAPS *syn, char *filename );

/* How synaps definitions */

typedef struct synaps_how {
        struct synaps_how *next;
        LINE    nin, nout;
        FILENAME wgtfile;
        int     nlay, *nnlay; /* number of layers, number of neurons in layer */
        float ***wgt;
        int     maxnper;
	WORD	alphain, alphaout; /* input and output translation alphabet */
	int	wsize;
	int	lenpos;
        int	lsize;
        int	lcomp;
        float	pfac;
        int	iact;
        int	iprof;
	float	weight; /* weight on predictor in average */
	int	nialph;
	int	input;
	int	iholel;
	int	iholer;
} SYNAPS_HOW;

extern SYNAPS_HOW *synaps_how_alloc();

extern SYNAPS_HOW *synaps_how_read_file(char *filename);

extern	SYNAPS_HOW      *synaps_how_read(char *filename);

extern SYNAPS_HOW *synaps_how_read_file_new(char *filename);

extern SYNAPS_HOW *synaps_how_read_file_new2(char *filename);

extern  SYNAPS_HOW      *synaps_how_read_new(char *filename);

extern	void    set_nn_verbose( int type );

extern void    set_nn_nin_pep( int nin_pep );

extern 	void    set_nn_cnn( int cnn );		

extern void	set_nn_cnn_pep( int pep );

/* end nnutils.h */
