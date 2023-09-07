
/* G.P.Gippert Jan 27 1999 garry@strubix.dk */

/*=
	XYZ Utilities
	Routines for many standard mathematical functions, including many
	scalar, linear algegra and matrix operations. Provides dynamic
	allocation of integer, float and double vectors and matrices.
	Defines numerical constants, and definitions for trivial functions.
	Defines the THREED type.
=*/

#define PI              3.1415926535897932384626433832795028841972
#define DEGPERRAD       (180.0/PI)   
#define SANG(a)         (fabs(a)<=1.0?sqrt(1.0-((a)*(a))):0.0)

/* operations returning a float */

extern float vlen(THREED xa);	/* length of A */

extern float vdot(THREED xa, THREED xb);	/* dot prod A.B */
extern float vcosang(THREED xa, THREED xb);	/* cosangle A and B */
extern float vdis(THREED xa, THREED xb);	/* distance A to B */
extern float vdsq(THREED xa, THREED xb);	/* square dist A to B */

extern float vara(THREED xa, THREED xb, THREED xc);	/* triangle area ABC */
extern float vtrp(THREED xa, THREED xb, THREED xc);	/* trip prod (AxB).C */
extern float vcos(THREED xa, THREED xb, THREED xc);	/* cosine angle ABC */
extern float vang(THREED xa, THREED xb, THREED xc);	/* angle ABC (deg) */
extern float vkap(THREED xa, THREED xb, THREED xc);	/* kappa curv. ABC */

extern float vtau(THREED xa, THREED xb, THREED xc, THREED xd);	/* tau torsion ABCD */
extern float vtai(THREED xa, THREED xb, THREED xc, THREED xd);	/* tau I torsion ABCD */
extern float vtar(THREED xa, THREED xb, THREED xc, THREED xd);	/* tau R torsion ABCD */
extern float vdih(THREED xa, THREED xb, THREED xc, THREED xd);	/* dihedral ABCD rad */
extern float vvol(THREED xa, THREED xb, THREED xc, THREED xd);	/* volume ABCD */
extern float vvon(THREED xa, THREED xb, THREED xc, THREED xd);	/* normal vol ABCD */
extern float vtpr(THREED xa, THREED xb, THREED xc, THREED xd);	/* topo profile */

extern float costodeg(float cang);

/* operations assigning a vector (in last position) */

extern void vnrm(THREED xa);	/* unit length A */
extern void vadd(THREED xa, THREED xb, THREED xc);	/* A+B */
extern void vsub2(THREED xa, THREED xb, THREED xc);	/* B-A */
extern void vcrs2(THREED xa, THREED xb, THREED xc);	/* AxB */
extern void vpno(THREED xa, THREED xb, THREED xc, THREED xn);	/* (B-A)x(C-A) */
extern void vrot(THREED x, float **r, THREED X);
extern void vunrot(THREED x, float **r, THREED X);

extern void vpos(THREED xa, THREED xb, THREED xc, THREED xd, float r, float theta, float phi);

		/* spherical coordinate transformation for D
		   in coordinate system ABC (bond rotation) */

/* Determinants */
extern float determinant(float **m, int n);
extern float cmdet3(THREED x1, THREED x2, THREED x3);
extern float cmdet4(THREED x1, THREED x2, THREED x3, THREED x4);

extern float **xyz_read(char *filename, int *n);
