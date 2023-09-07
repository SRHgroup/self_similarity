/* M. Nielsen April 2002. mniel@cbs.dtu.dk */

/*      Blosum Matrix Utilities
        Various Routines to make blosum score matrices
*/

#define DNA_ORDER "ACGTRYMWSKDHVBN"

extern	void    bl_init( int type );

extern	void    bl_init_file( FILENAME filename);

extern	void    bl_show();

extern	int	bl_s( int qi, int di );

extern	float   **read_realblosum( FILENAME filename, char **alphabet );

extern	float   **read_realblosum_ext( FILENAME filename, char **alphabet );

extern	void	set_bl_verbose( int type );

extern	void    dna_init_file( FILENAME filename);
