/*
 * how.h : types for how entry manipulation
 */

#ifndef SRC_HOW_H
#define SRC_HOW_H

/* structure for how files */
struct HOWtype {
  int aacnt;
  char name[255];
  char *comment;
  char *aach;
  char *data;

  char f_old; /* use old count (5 digits) format */
  char f_num; /* use line numbering */

  int alloccnt;	/* allocated AA - internal */
};

/* init how entry */
void HOWinit(struct HOWtype *how, char *err);

/* read how entry from file */
int HOWreadfile(FILE *howf, struct HOWtype *how, char *err);

/* write how entry to file */
int HOWwritefile(FILE *howf, struct HOWtype *how, char *err);

/* find entry in how file */
int HOWfindfile(FILE *howf, char *name, char *err);

/* add aa and data to end of how entry */
void HOWaddres(struct HOWtype *how, char aach, char data, char *err);

/* free data in how entry */
void HOWfree(struct HOWtype *how, char *err);

#endif /* ! SRC_HOW_H */
