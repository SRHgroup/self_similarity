/* Morten Nielsen July 2002. mniel@cbs.dtu.dk */

/*
	Alphabet utils

*/

typedef struct alphabet {
        struct alphabet *next;
        WORD    letter;
        char    trans;
        WORD    descr;
} ALPHABET;

extern	ALPHABET        *alphabet_alloc();

extern	ALPHABET        *read_alphabet( FILENAME filename, int *alen );

extern	char    translate_char( char c, ALPHABET *alpha );

extern	char    *translate( char *seq, ALPHABET *alpha );

