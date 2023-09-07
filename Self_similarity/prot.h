/* 
 * prot.h : types for general protein utilities
 */

#ifndef SRC_PROT_H
#define SRC_PROT_H

#define AA_ALA 0 /* Alanine */
#define AA_ARG 1 /* Arginine */
#define AA_ASN 2 /* Asparagine */
#define AA_ASP 3 /* Aspartate */
#define AA_CYS 4 /* Cysteine */
#define AA_GLN 5 /* Glutamine */
#define AA_GLU 6 /* Glutamate */
#define AA_GLY 7 /* Glycine */
#define AA_HIS 8 /* Histidine */
#define AA_ILE 9 /* Isoleucine */
#define AA_LEU 10 /* Leucine */
#define AA_LYS 11 /* Lysine */
#define AA_MET 12 /* Metheonine */
#define AA_PHE 13 /* Phenylalanine */
#define AA_PRO 14 /* Proline */
#define AA_SER 15 /* Serine */
#define AA_THR 16 /* Threonine */
#define AA_TRP 17 /* Tryptophane */
#define AA_TYR 18 /* Tyrosine */
#define AA_VAL 19 /* Valine */
#define AA_XXX 20 /* unknown */

#define SRC_PROT_C
#ifndef SRC_PROT_C
extern struct aadeftype aadef[21];
#endif /* ! SRC_PROT_C */

/* structure for known AA constants */
struct aadeftype {
    char *aaid;		/* 3 letter code        */
    char aach;		/* 1 letter code        */
    char *name;		/* long name of AA      */
    char *atoms;	/* heavy atoms in AA    */
    char *hatoms;	/* hydrogen atoms in AA */
};

/* add atom to collection */
void addcoll(char *coll, char *atom);

/* clear collection */
void clearcoll(char *coll);

/* check collection 'c' against 'o' */
void checkcoll(char *collo, char *collc, char* err);

/* find aa number */
int findaa(char *aaid);

/* used to read in fields of datafiles */
char *getfield(char *line, int b, int e);

#endif /* ! SRC_PROT_H */
