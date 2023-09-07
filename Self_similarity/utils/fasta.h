/*
 * fasta.h : types for fasta entry manipulation
 */

#ifndef SRC_FASTA_H
#define SRC_FASTA_H

/* structure for fasta files */
struct FASTAtype {
    int aacnt;
    char name[255];
    char *aach;
	 char *comment;
    int alloccnt;	/* allocated AA - internal */
};

/* init fasta entry */
void FASTAinit(struct FASTAtype *fasta, char *err);

/* read fasta entry from file */
int FASTAreadfile(FILE *fastaf, struct FASTAtype *fasta, char *err);

/* write fasta entry to file */
int FASTAwritefile(FILE *fastaf, struct FASTAtype *fasta, char *err);

/* find entry in fasta file */
int FASTAfindfile(FILE *fastaf, char *name, char *err);

/* add aa end of fasta entry */
void FASTAaddres(struct FASTAtype *fasta, char aach, char *err);

/* free data in fasta entry */
void FASTAfree(struct FASTAtype *fasta, char *err);

#endif /* ! SRC_FASTA_H */
