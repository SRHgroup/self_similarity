/* Morten Nielsen may 2006 */
/* modified from GAP source GPG */

/*=
	Overlay Utilities
	Routines to perform standard superposition of coordinate sets
	and related transformations.
=*/

extern void ovl_verbose(int mode);

extern float coordinate_rmsd(int n,
	THREED * xyza, THREED * xyzb, THREED * tmpa, THREED * tmpb);

extern float coordinate_wrmsd(int n, int *msk, float *wgt,
	THREED * xyza, THREED * xyzb, THREED * tmpa, THREED * tmpb);

extern void overlay(int n, int *mask, float *wgt, THREED * x, THREED * rx);

extern void overlayr(int n, int *mask, float *wgt,
	THREED * x, THREED * rx, THREED ** cen, float ***rot);

extern int superimpose(THREED * xyz, THREED * r_xyz,
	int nm, int nu, int *u, float *wt);

extern int superimposer(THREED * xyz, THREED * r_xyz,
	int nm, int nu, int *u, float *wt, THREED ** cen, float ***rot);

extern int superimposem(THREED * xyz, THREED * r_xyz,
	int nm, int *m, float *wt);

extern float rmsd(THREED * x, THREED * xr, int nm, int nu, int *u);

extern float wrmsd(THREED * x, THREED * xr, int nm, int nu, int *u,
	float *w);

extern float wrmsdm(THREED * x, THREED * xr, int nm, int *ms, float *w);

extern float lsqrms(int n_atom, float *a_wt, THREED * a_pos,
	THREED * a_pos0, float rotmat[3][3]);

extern float *ellipsoid(THREED * x, float *w, int n, int *ne);

extern void principal_axis_transformation(THREED * x,
	float *w, float *a, int n, int report);

extern float grmsd(THREED * x1, THREED * x2, int n, int mir);

extern float grmsd_rot_trans( THREED * x1, THREED * x2, int n, int mir, THREED **cen, float ***rot);

extern float wgrmsd(THREED * x1, THREED * x2, float *w, int n, int mir);

extern int nrmsd(THREED * x1, THREED * x2, int n, float thr, float rad,
	int mir);

extern float lrmsd(THREED * x1, THREED * x2, int n, float thr, float rad,
	int mir);

extern float wlrmsd(THREED * x1, THREED * x2, float *w, int n, float
	thr, float rad, int mir);

extern void altem(THREED ** xyz, float **wgt, int **msk, int ml,
	char *s1, int o1, char *s2, int o2, THREED * x2);

extern int alndx(int n1, char *s1, int o1,
	int n2, char *s2, int o2, int **ai1, int **ai2, int *nm);

extern int alivec(int *v1, int n1, char *s1, int o1,
	int *v2, int n2, char *s2, int o2, int **av1, int **av2, int *nm);

extern int alfvec(float *v1, int n1, char *s1, int o1,
	float *v2, int n2, char *s2, int o2,
	float **av1, float **av2, int *nm);

extern int alcvec(char *v1, int n1, char *s1, int o1,
	char *v2, int n2, char *s2, int o2,
	char **av1, char **av2, int *nm);

extern int alnvec(THREED * v1, int n1, char *s1, int o1,
	THREED * v2, int n2, char *s2, int o2,
	THREED ** av1, THREED ** av2, int *n);

extern int alignable(char *name1, THREED * x1, char *q1, int *r1, int n1,
	char *s1, int o1, char *name2, THREED * x2, char *q2, int *r2,
	int n2, char *s2, int o2, int *nm, THREED ** ax1, THREED ** ax2,
	char **aq1, char **aq2, int **ar1, int **ar2);


extern void armsdn4(THREED * x1, int n1, char *s1, int o1,
	THREED * x2, int n2, char *s2, int o2,
	int *nm, float *g, int *n4, int mir);

extern void armsd(THREED * x1, int n1, char *s1, int o1,
	THREED * x2, int n2, char *s2, int o2,
	int *n, float *g, float *f1, float *f2, int *n4,
	float rad, float thr, int mir);

extern void warmsd(THREED * x1, int n1, char *s1, int o1,
	THREED * x2, int n2, char *s2, int o2,
	float *aw,
	int *n, float *g, float *f1, float *f2, int *n4,
	float rad, float thr, int mir);

extern void armsd_view(char *name1, THREED * x1, int *r1, int n1, char *s1,
	int o1, char *name2, THREED * x2, int *r2, int n2, char *s2,
	int o2, float *as, int *n, float *g, float *f1, float *f2, int *n4,
	float rad, float thr, int mir, int pat, char *view);

extern float *rms_coordinate_deviation(THREED ** x, int n, int m);

extern float *rms_distance_deviation(THREED ** x, int n, int m);

extern float *wrms_distance_deviation(THREED ** x, float **w, int **s,
	int n, int m);

extern float total_coordinate_deviation(THREED ** x, int n, int m);

extern THREED *mean_structure(THREED ** x, int n, int m, float **s,
	float *mrms, int pat, int replace, int report);

extern THREED *wmean_structure(THREED ** x, float **w, int n, int m,
	float *mrms, int pat, int replace, int report);

extern THREED *wmean_structure2(THREED ** x, float **sw, float **aw,
	int n, int m, float *mrms, int pat, int replace, int report);

extern THREED *wmean_structure3(THREED ** x, float **aw, int **ms,
	float *sw, int n, int m, float *mrms, int pat, int replace,
	int report);

extern int *xyzmaxsub(THREED * x1, THREED * x2, int n, int n0,
	int length, int niter, float dthreshold,
	int *nsub, float *score, float *rmsd, float *rmsd0);

extern int *xyzmaxsubr(THREED * x1, THREED * x2, int n, int n0,
	int length, int niter, float dthreshold,
	int *nsub, float *score, float *rmsd, float *rmsd0,
	THREED ** cen, float ***rot);

/* end ovlutils.h */
