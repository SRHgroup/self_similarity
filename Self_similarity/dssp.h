/*
 * dssp.h : types for dssp entry manipulation
 */

#ifndef SRC_DSSP_H
#define SRC_DSSP_H

#define DSSPDIR "/usr/cbs/databases/pdb/alldssp/"
#include "err.h"

struct DSSPrestype {
    int dsspnum;	/* dssp index number */
    int resnum;		/* residue number */
    char insres;	/* insertion code */
    char chainid;	/* chain id */
    char aaid;		/* AA 1 char id */
    char secstr;	/* structure */
    struct structure {
	char th3;	/* 3-turns/helix */
	char th4;	/* 4-turns/helix */
	char th5;	/* 5-turns/helix */
	char geobend;	/* geometrical bend */
	char chirality;	/* chirality */
	char bblab1;	/* beta bridge label */
	char bblab2;	/* beta bridge label */
    } structure; 
    int bp1;		/* beta bridge partner resnum */
    int bp2;		/* beta bridge partner resnum */
    char bslab;		/* beta sheet label */
    int acc;		/* solvent accessibility */
    int nho11;		/* N-H-->O (1) */
    float nho12;	/* N-H-->O (2) */
    int ohn11;		/* O-->H-N (1) */
    float ohn12;	/* O-->H-N (2) */
    int nho21;		/* N-H-->O (1) */
    float nho22;	/* N-H-->O (2) */
    int ohn21;		/* O-->H-N (1) */
    float ohn22;	/* O-->H-N (2) */
    float tco;		/* TCO */
    float kappa;	/* KAPPA */
    float alpha;	/* ALPHA */
    float phi;		/* PHI */
    float psi;		/* PSI */
    float xca;		/* X-CA */
    float yca;		/* Y-CA */
    float zca;		/* Z-CA */
    char cysbch;	/* cysteine bridge partner char id */
    int cysb;		/* cysteine bridge partner */
};

struct DSSPchaintype {
  char chainid;			/* chain id */
  int chainsz;			/* chain size in residues */
  struct DSSPrestype *residues;	/* chain residues */    
};

struct DSSPtype {
    char *reference;	/* reference field */
    char *fclass;	/* Functional classification */
    char *compnd;	/* Compound fields */
    char *source;	/* Source fields */
    char *ddate;	/* Date of deposition */
    char *pdbid;	/* pdb id */
    char *author;	/* author fields */
    int sstot;		/* SS bridges total */
    int ssintra;	/* SS bridges intra chain */
    int ssinter;	/* SS bridges inter chain */
    float acc;		/* surface accesability */
    /* hydrogen bonds */
    struct hbond {
      int j;	/* hydrogen bonds of type O(I)-->H-N(J) */
      int pb;	/* hydrogen bonds in parallel bridges */
      int apb;	/* hydrogen bonds in antiparallel bridges */
      int im5;	/* hydrogen bonds of type O(I)-->H-N(I-5) */
      int im4;	/* hydrogen bonds of type O(I)-->H-N(I-4) */
      int im3;	/* hydrogen bonds of type O(I)-->H-N(I-3) */
      int im2;	/* hydrogen bonds of type O(I)-->H-N(I-2) */
      int im1;	/* hydrogen bonds of type O(I)-->H-N(I-1) */
      int ip0;	/* hydrogen bonds of type O(I)-->H-N(I+0) */
      int ip1;	/* hydrogen bonds of type O(I)-->H-N(I+1) */
      int ip2;	/* hydrogen bonds of type O(I)-->H-N(I+2) */
      int ip3;	/* hydrogen bonds of type O(I)-->H-N(I+3) */
      int ip4;	/* hydrogen bonds of type O(I)-->H-N(I+4) */
      int ip5;	/* hydrogen bonds of type O(I)-->H-N(I+5) */	
    } hbond;
    /* histograms */
    struct his {
      int ahelix[30]; /* histogram of residues per alpha helix */
      int pbladd[30]; /* histogram of parallel bridges per ladder */
      int apbladd[30];/* histogram of antiparallel bridges per ladder */
      int lsheet[30]; /* histogram of ladders per sheet */
    } his;
    
    int segmentcnt;	/* number of segments (chains, etc.) */
    int chaincnt;	/* number of chains */
    struct DSSPchaintype *chains;    /* chains */
    
    int aacnt;		/* number of residues */
    struct DSSPrestype *residues; /* residues */
};

/* init dssp entry */
extern void DSSPinit(struct DSSPtype *dssp, char *err);

/* reads a DSSP entry */
extern int DSSPreadfile(struct DSSPtype *dssp, char *dsspfname, char *err);

/* return index to residue */
extern struct DSSPrestype *DSSPgetres(struct DSSPtype *dssp, int dsspnum);

/* free dssp entry */
extern void DSSPfree(struct DSSPtype *dssp, char *err);

#endif /* ! SRC_DSSP_H */
