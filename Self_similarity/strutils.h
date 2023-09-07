/* Morten Nielsen April 2002. mniel@cbs.dtu.dk */
/* Modified from Garry Gippert source code */
/* Modified from GAP source code */

/*=
	String Utilities
	Routines to manipulate strings and regular expressions.
	Provides standard definitions for WORD, LINE, FILENAME.
=*/

#define REDIRECT_DEVNULL "/dev/null 2>&1"
#define	PROFILE_ORDER	"ARNDCQEGHILKMFPSTWYVX"

#define WORDSIZE 56
typedef char WORD[WORDSIZE];

#define FILENAMESIZE 256
typedef char FILENAME[FILENAMESIZE];

#define LINESIZE 1024
typedef char LINE[LINESIZE];

#define LONGLINESIZE 500000
typedef char LONGLINE[LONGLINESIZE];

#define GETLINE (fgets(line, sizeof line, fp) != NULL)

/* routines for opening files with g(un)zip or (un)compress */

extern FILE *stream_input(char *filename, int *comp, int *fformat);
extern FILE *stream_output(char *filename, int *comp, int fformat);
extern void stream_close(FILE * fp, int comp, char *filename);

extern void skip_comments(FILE * fp);

extern int strpos(char *s, char c);

extern char *uppercase(char *s);
extern char *lowercase(char *s);

extern char **split( char *line, int *n );
extern	void    def_sepchars( char *s );

extern char    **split_2( char *string, int *n, char *stringsep );
extern	char    **split_3( char *line, int *n, char *stringsep );

extern	char	*string_filter( char *s );

float  *gfvectorsplit(char *line, int *n);

extern char single_letter_code(char *type);

extern int G_regexp(char *l, char *p); 

extern int G_regexp2(char *l, char *p);

extern char   *triple_letter_code(char code, char *type);

/* end strutils.h */
