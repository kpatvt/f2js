/* demo5.f -- translated by f2c (version 20160102).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal aa, ee, gg, bb, dprey, dpred;
} pcom0_;

#define pcom0_1 pcom0_

struct {
    doublereal ax, ay, acoef[400]	/* was [20][20] */, bcoef[20], dx, dy,
	     alph, diff[20], cox[20], coy[20];
    integer ns, mx, my, mxns;
} pcom1_;

#define pcom1_1 pcom1_

struct {
    doublereal uround, srur;
    integer mp, mq, mpsq, itmax;
} pcom2_;

#define pcom2_1 pcom2_

struct {
    integer meshx, meshy, ngx, ngy, ngrp, mxmp, jgx[21], jgy[21], jigx[50], 
	    jigy[50], jxr[20], jyr[20];
} pcom3_;

#define pcom3_1 pcom3_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__0 = 0;

/* ----------------------------------------------------------------------- */
/* Demonstration program for DLSODPK. */
/* ODE system from ns-species interaction pde in 2 dimensions. */
/* This is the version of 14 June 2001. */

/* This version is in double precision. */
/* ----------------------------------------------------------------------- */
/* This program solves a stiff ODE system that arises from a system */
/* of partial differential equations.  The PDE system is a food web */
/* population model, with predator-prey interaction and diffusion on */
/* the unit square in two dimensions.  The dependent variable vector is */

/*         1   2        ns */
/*   c = (c , c , ..., c  ) */

/* and the PDEs are as follows: */

/*     i               i      i */
/*   dc /dt  =  d(i)*(c    + c   )  +  f (x,y,c)  (i=1,...,ns) */
/*                     xx     yy        i */

/* where */
/*                  i          ns         j */
/*   f (x,y,c)  =  c *(b(i) + sum a(i,j)*c ) */
/*    i                       j=1 */

/* The number of species is ns = 2*np, with the first np being prey and */
/* the last np being predators.  The coefficients a(i,j), b(i), d(i) are: */

/*   a(i,i) = -a  (all i) */
/*   a(i,j) = -g  (i .le. np, j .gt. np) */
/*   a(i,j) =  e  (i .gt. np, j .le. np) */
/*   b(i) =  b*(1 + alpha*x*y)  (i .le. np) */
/*   b(i) = -b*(1 + alpha*x*y)  (i .gt. np) */
/*   d(i) = dprey  (i .le. np) */
/*   d(i) = dpred  (i .gt. np) */

/* The various scalar parameters are set in subroutine setpar. */

/* The boundary conditions are: normal derivative = 0. */
/* A polynomial in x and y is used to set the initial conditions. */

/* The PDEs are discretized by central differencing on a mx by my mesh. */

/* The ODE system is solved by DLSODPK using method flag values */
/* mf = 10, 21, 22, 23, 24, 29.  The final time is tmax = 10, except */
/* that for mf = 10 it is tmax = 1.0d-3 because the problem is stiff, */
/* and for mf = 23 and 24 it is tmax = 2 because the lack of symmetry */
/* in the problem makes these methods more costly. */

/* Two preconditioner matrices are used.  One uses a fixed number of */
/* Gauss-Seidel iterations based on the diffusion terms only. */
/* The other preconditioner is a block-diagonal matrix based on */
/* the partial derivatives of the interaction terms f only, using */
/* block-grouping (computing only a subset of the ns by ns blocks). */
/* For mf = 21 and 22, these two preconditioners are applied on */
/* the left and right, respectively, and for mf = 23 and 24 the product */
/* of the two is used as the one preconditioner matrix. */
/* For mf = 29, the inverse of the product is applied. */

/* Two output files are written: one with the problem description and */
/* and performance statistics on unit 6, and one with solution profiles */
/* at selected output times (for mf = 22 only) on unit 8. */
/* ----------------------------------------------------------------------- */
/* Note: In addition to the main program and 10 subroutines */
/* given below, this program requires the LINPACK subroutines */
/* DGEFA and DGESL, and the BLAS routine DAXPY. */
/* ----------------------------------------------------------------------- */
/* Reference: */
/*     Peter N. Brown and Alan C. Hindmarsh, */
/*     Reduced Storage Matrix Methods in Stiff ODE Systems, */
/*     J. Appl. Math. & Comp., 31 (1989), pp. 40-91; */
/*     Also LLNL Report UCRL-95088, Rev. 1, June 1987. */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static integer lrw = 5213;
    static integer liw = 67;

    /* Format strings */
    static char fmt_20[] = "(\002 Demonstration program for DLSODPK packag"
	    "e\002//\002 Food web problem with ns species, ns =\002,i4/\002 P"
	    "redator-prey interaction and diffusion on a 2-d square\002//\002"
	    " Mesh dimensions (mx,my) =\002,2i4/\002 Total system size is neq"
	    " =\002,i7//)";
    static char fmt_25[] = "(\002 Matrix parameters:  a =\002,d12.4,\002   e"
	    " =\002,d12.4,\002   g =\002,d12.4/20x,\002 b =\002,d12.4//\002 D"
	    "iffusion coefficients: dprey =\002,d12.4,\002   dpred =\002,d12."
	    "4/\002 Rate parameter alpha =\002,d12.4//)";
    static char fmt_30[] = "(\002 Preconditioning uses interaction-only bloc"
	    "k-diagonal\002,\002 matrix\002/\002 with block-grouping, and Gau"
	    "ss-Seidel iterations\002//\002 Number of diagonal block groups ="
	    " ngrp =\002,i4,\002   (ngx by ngy, ngx =\002,i2,\002  ngy =\002,"
	    "i2,\002 )\002//\002 G-S preconditioner uses itmax iterations, it"
	    "max =\002,i3//\002 Tolerance parameters: rtol =\002,d10.2,\002  "
	    " atol =\002,d10.2)";
    static char fmt_40[] = "(//80(\002-\002)//\002 Solution with mf =\002,i3"
	    "//\002   t       nstep  nfe  nni  nli  npe  nq\002,4x,\002h     "
	    "     avdim    ncf rate    lcf rate\002)";
    static char fmt_50[] = "(d10.2,i5,i6,3i5,i4,2d11.2,d10.2,d12.2)";
    static char fmt_60[] = "(//\002 final time reached =\002,d12.4//)";
    static char fmt_80[] = "(//\002 Final statistics for this run:\002/\002 "
	    "rwork size =\002,i8,\002   iwork size =\002,i6/\002 number of ti"
	    "me steps            =\002,i5/\002 number of f evaluations       "
	    "  =\002,i5/\002 number of preconditioner evals. =\002,i5/\002 nu"
	    "mber of preconditioner solves =\002,i5/\002 number of nonlinear "
	    "iterations  =\002,i5/\002 number of linear iterations     =\002,"
	    "i5/\002 average subspace dimension  =\002,f8.4/i5,\002 nonlinear"
	    " conv. failures,\002,i5,\002 linear conv. failures\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;
    olist o__1;

    /* Builtin functions */
    integer f_open(olist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal t, cc[576];
    static integer mf;
    static doublereal hu;
    static integer nfe, nli, neq, nni, npe, nps, nqu, nst, ncfl;
    extern /* Subroutine */ int fweb_();
    static integer ncfn;
    static doublereal rcfl, rcfn, atol;
    static integer jpre;
    extern /* Subroutine */ int gset_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer itol, iopt, iout;
    static doublereal rtol;
    static integer nout;
    static doublereal tout;
    static integer imod3;
    extern /* Subroutine */ int jacbg_();
    static doublereal avdim;
    static integer nsdif;
    extern /* Subroutine */ int cinit_(doublereal *);
    static integer itask, leniw, lenrw, iwork[67];
    static doublereal rwork[5213];
    static integer jacflg;
    extern doublereal dumach_(void);
    static integer nfldif, nfndif, nlidif, nnidif;
    extern /* Subroutine */ int solsbg_();
    static integer istate;
    extern /* Subroutine */ int setpar_(void), outweb_(doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *), 
	    dlsodpk_(U_fp, integer *, doublereal *, doublereal *, doublereal *
	    , integer *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, U_fp, 
	    U_fp, integer *);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___6 = { 0, 6, 0, fmt_25, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___42 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___44 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___48 = { 0, 6, 0, fmt_80, 0 };



/* The problem Common blocks below allow for up to 20 species, */
/* up to a 50x50 mesh, and up to a 20x20 group structure. */

/* The dimension of cc below must be .ge. 2*neq, where neq = ns*mx*my. */
/* The dimension lrw of rwork must be .ge. 17*neq + ns*ns*ngrp + 61, */
/* and the dimension liw of iwork must be .ge. 35 + ns*ngrp. */

    o__1.oerr = 0;
    o__1.ounit = 6;
    o__1.ofnmlen = 6;
    o__1.ofnm = "demout";
    o__1.orl = 0;
    o__1.osta = "new";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 8;
    o__1.ofnmlen = 5;
    o__1.ofnm = "ccout";
    o__1.orl = 0;
    o__1.osta = "new";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    pcom1_1.ax = 1.;
    pcom1_1.ay = 1.;

/* Call setpar to set problem parameters. */
    setpar_();

/* Set remaining problem parameters. */
    neq = pcom1_1.ns * pcom1_1.mx * pcom1_1.my;
    pcom1_1.mxns = pcom1_1.mx * pcom1_1.ns;
    pcom1_1.dx = pcom1_1.ax / (pcom1_1.mx - 1);
    pcom1_1.dy = pcom1_1.ay / (pcom1_1.my - 1);
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	d__1 = pcom1_1.dx;
	pcom1_1.cox[i__ - 1] = pcom1_1.diff[i__ - 1] / (d__1 * d__1);
/* L10: */
/* Computing 2nd power */
	d__1 = pcom1_1.dy;
	pcom1_1.coy[i__ - 1] = pcom1_1.diff[i__ - 1] / (d__1 * d__1);
    }

/* Write heading. */
    s_wsfe(&io___5);
    do_fio(&c__1, (char *)&pcom1_1.ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&pcom1_1.mx, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&pcom1_1.my, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&neq, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___6);
    do_fio(&c__1, (char *)&pcom0_1.aa, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&pcom0_1.ee, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&pcom0_1.gg, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&pcom0_1.bb, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&pcom0_1.dprey, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&pcom0_1.dpred, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&pcom1_1.alph, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* Set remaining method parameters. */
    jpre = 3;
    jacflg = 1;
    iwork[2] = jpre;
    iwork[3] = jacflg;
    iopt = 0;
    pcom2_1.mp = pcom1_1.ns;
    pcom2_1.mq = pcom1_1.mx * pcom1_1.my;
    pcom2_1.mpsq = pcom1_1.ns * pcom1_1.ns;
    pcom2_1.uround = dumach_();
    pcom2_1.srur = sqrt(pcom2_1.uround);
    pcom3_1.meshx = pcom1_1.mx;
    pcom3_1.meshy = pcom1_1.my;
    pcom3_1.mxmp = pcom3_1.meshx * pcom2_1.mp;
    pcom3_1.ngx = 2;
    pcom3_1.ngy = 2;
    pcom3_1.ngrp = pcom3_1.ngx * pcom3_1.ngy;
    gset_(&pcom3_1.meshx, &pcom3_1.ngx, pcom3_1.jgx, pcom3_1.jigx, 
	    pcom3_1.jxr);
    gset_(&pcom3_1.meshy, &pcom3_1.ngy, pcom3_1.jgy, pcom3_1.jigy, 
	    pcom3_1.jyr);
    iwork[0] = pcom2_1.mpsq * pcom3_1.ngrp;
    iwork[1] = pcom2_1.mp * pcom3_1.ngrp;
    pcom2_1.itmax = 5;
    itol = 1;
    rtol = 1e-5;
    atol = rtol;
    itask = 1;
    s_wsfe(&io___15);
    do_fio(&c__1, (char *)&pcom3_1.ngrp, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&pcom3_1.ngx, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&pcom3_1.ngy, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&pcom2_1.itmax, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
    e_wsfe();


/* Loop over mf values 10, 21, ..., 24, 29. */

    for (mf = 10; mf <= 29; ++mf) {
	if (mf > 10 && mf < 21) {
	    goto L90;
	}
	if (mf > 24 && mf < 29) {
	    goto L90;
	}
	s_wsfe(&io___17);
	do_fio(&c__1, (char *)&mf, (ftnlen)sizeof(integer));
	e_wsfe();

	t = 0.;
	tout = 1e-8;
	nout = 18;
	if (mf == 10) {
	    nout = 6;
	}
	if (mf == 23 || mf == 24) {
	    nout = 10;
	}
	cinit_(cc);
	if (mf == 22) {
	    outweb_(&t, cc, &pcom1_1.ns, &pcom1_1.mx, &pcom1_1.my, &c__8);
	}
	istate = 1;
	nli = 0;
	nni = 0;
	ncfn = 0;
	ncfl = 0;
	nst = 0;

/* Loop over output times and call DLSODPK. */

	i__1 = nout;
	for (iout = 1; iout <= i__1; ++iout) {
	    dlsodpk_((U_fp)fweb_, &neq, cc, &t, &tout, &itol, &rtol, &atol, &
		    itask, &istate, &iopt, rwork, &lrw, iwork, &liw, (U_fp)
		    jacbg_, (U_fp)solsbg_, &mf);
	    nsdif = iwork[10] - nst;
	    nst = iwork[10];
	    nfe = iwork[11];
	    npe = iwork[12];
	    nnidif = iwork[18] - nni;
	    nni = iwork[18];
	    nlidif = iwork[19] - nli;
	    nli = iwork[19];
	    nfndif = iwork[21] - ncfn;
	    ncfn = iwork[21];
	    nfldif = iwork[22] - ncfl;
	    ncfl = iwork[22];
	    nqu = iwork[13];
	    hu = rwork[10];
	    avdim = 0.;
	    rcfn = 0.;
	    rcfl = 0.;
	    if (nnidif > 0) {
		avdim = (real) nlidif / (real) nnidif;
	    }
	    if (nsdif > 0) {
		rcfn = (real) nfndif / (real) nsdif;
	    }
	    if (nnidif > 0) {
		rcfl = (real) nfldif / (real) nnidif;
	    }
	    s_wsfe(&io___42);
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nni, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nli, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nqu, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&hu, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&avdim, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&rcfn, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&rcfl, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    imod3 = iout - iout / 3 * 3;
	    if (mf == 22 && imod3 == 0) {
		outweb_(&t, cc, &pcom1_1.ns, &pcom1_1.mx, &pcom1_1.my, &c__8);
	    }
	    if (istate == 2) {
		goto L65;
	    }
	    s_wsfe(&io___44);
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    goto L75;
L65:
	    if (tout > .9) {
		tout += 1.;
	    }
	    if (tout < .9) {
		tout *= 10.;
	    }
/* L70: */
	}

L75:
	nst = iwork[10];
	nfe = iwork[11];
	npe = iwork[12];
	lenrw = iwork[16];
	leniw = iwork[17];
	nni = iwork[18];
	nli = iwork[19];
	nps = iwork[20];
	if (nni > 0) {
	    avdim = (real) nli / (real) nni;
	}
	ncfn = iwork[21];
	ncfl = iwork[22];
	s_wsfe(&io___48);
	do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nps, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nni, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nli, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&avdim, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ncfn, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ncfl, (ftnlen)sizeof(integer));
	e_wsfe();

L90:
	;
    }
    s_stop("", (ftnlen)0);
/* ------  end of main program for DLSODPK demonstration program ---------- */
    return 0;
} /* MAIN__ */

/* Subroutine */ int setpar_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, np;

/* ----------------------------------------------------------------------- */
/* This routine sets the problem parameters. */
/* It set ns, mx, my, and problem coefficients acoef, bcoef, diff, alph, */
/* using parameters np, aa, ee, gg, bb, dprey, dpred. */
/* ----------------------------------------------------------------------- */

    np = 3;
    pcom1_1.mx = 6;
    pcom1_1.my = 6;
    pcom0_1.aa = 1.;
    pcom0_1.ee = 1e4;
    pcom0_1.gg = 5e-7;
    pcom0_1.bb = 1.;
    pcom0_1.dprey = 1.;
    pcom0_1.dpred = .5;
    pcom1_1.alph = 1.;
    pcom1_1.ns = np << 1;
    i__1 = np;
    for (j = 1; j <= i__1; ++j) {
	i__2 = np;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    pcom1_1.acoef[np + i__ + j * 20 - 21] = pcom0_1.ee;
	    pcom1_1.acoef[i__ + (np + j) * 20 - 21] = -pcom0_1.gg;
/* L60: */
	}
	pcom1_1.acoef[j + j * 20 - 21] = -pcom0_1.aa;
	pcom1_1.acoef[np + j + (np + j) * 20 - 21] = -pcom0_1.aa;
	pcom1_1.bcoef[j - 1] = pcom0_1.bb;
	pcom1_1.bcoef[np + j - 1] = -pcom0_1.bb;
	pcom1_1.diff[j - 1] = pcom0_1.dprey;
	pcom1_1.diff[np + j - 1] = pcom0_1.dpred;
/* L70: */
    }

    return 0;
/* ------------  end of subroutine setpar  ------------------------------- */
} /* setpar_ */

/* Subroutine */ int gset_(integer *m, integer *ng, integer *jg, integer *jig,
	 integer *jr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, ig, len1, ngm1, mper;

/* ----------------------------------------------------------------------- */
/* This routine sets arrays jg, jig, and jr describing */
/* a uniform partition of (1,2,...,m) into ng groups. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jr;
    --jig;
    --jg;

    /* Function Body */
    mper = *m / *ng;
    i__1 = *ng;
    for (ig = 1; ig <= i__1; ++ig) {
/* L10: */
	jg[ig] = (ig - 1) * mper + 1;
    }
    jg[*ng + 1] = *m + 1;

    ngm1 = *ng - 1;
    len1 = ngm1 * mper;
    i__1 = len1;
    for (j = 1; j <= i__1; ++j) {
/* L20: */
	jig[j] = (j - 1) / mper + 1;
    }
    ++len1;
    i__1 = *m;
    for (j = len1; j <= i__1; ++j) {
/* L25: */
	jig[j] = *ng;
    }

    i__1 = ngm1;
    for (ig = 1; ig <= i__1; ++ig) {
/* L30: */
	jr[ig] = (integer) ((ig - .5) * mper + .5);
    }
    jr[*ng] = (integer) ((ngm1 * mper + 1 + *m) * .5);

    return 0;
/* ------------  end of subroutine gset  --------------------------------- */
} /* gset_ */

/* Subroutine */ int cinit_(doublereal *cc)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__;
    static doublereal x, y;
    static integer jx, jy, ici, ioff;
    static doublereal argx, argy;
    static integer iyoff;

/* ----------------------------------------------------------------------- */
/* This routine computes and loads the vector of initial values. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --cc;

    /* Function Body */
    i__1 = pcom1_1.my;
    for (jy = 1; jy <= i__1; ++jy) {
	y = (jy - 1) * pcom1_1.dy;
	argy = y * 16. * y * (pcom1_1.ay - y) * (pcom1_1.ay - y);
	iyoff = pcom1_1.mxns * (jy - 1);
	i__2 = pcom1_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    x = (jx - 1) * pcom1_1.dx;
	    argx = x * 16. * x * (pcom1_1.ax - x) * (pcom1_1.ax - x);
	    ioff = iyoff + pcom1_1.ns * (jx - 1);
	    i__3 = pcom1_1.ns;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		ici = ioff + i__;
		cc[ici] = i__ * argx * argy + 10.;
/* L5: */
	    }
/* L10: */
	}
/* L20: */
    }
    return 0;
/* ------------  end of subroutine cinit  -------------------------------- */
} /* cinit_ */

/* Subroutine */ int outweb_(doublereal *t, doublereal *c__, integer *ns, 
	integer *mx, integer *my, integer *lun)
{
    /* Format strings */
    static char fmt_10[] = "(/80(\002-\002)/30x,\002At time t = \002,d16.8/8"
	    "0(\002-\002))";
    static char fmt_20[] = "(\002 the species c(\002,i2,\002) values are:"
	    "\002)";
    static char fmt_25[] = "(6(1x,g12.6))";
    static char fmt_35[] = "(80(\002-\002),/)";

    /* System generated locals */
    integer c_dim1, c_dim2, c_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, jx, jy;

    /* Fortran I/O blocks */
    static cilist io___67 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___69 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___71 = { 0, 0, 0, fmt_25, 0 };
    static cilist io___73 = { 0, 0, 0, fmt_35, 0 };


/* ----------------------------------------------------------------------- */
/* This routine prints the values of the individual species densities */
/* at the current time t.  The write statements use unit lun. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    c_dim1 = *ns;
    c_dim2 = *mx;
    c_offset = 1 + c_dim1 * (1 + c_dim2);
    c__ -= c_offset;

    /* Function Body */
    io___67.ciunit = *lun;
    s_wsfe(&io___67);
    do_fio(&c__1, (char *)&(*t), (ftnlen)sizeof(doublereal));
    e_wsfe();

    i__1 = *ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	io___69.ciunit = *lun;
	s_wsfe(&io___69);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	for (jy = *my; jy >= 1; --jy) {
	    io___71.ciunit = *lun;
	    s_wsfe(&io___71);
	    i__2 = *mx;
	    for (jx = 1; jx <= i__2; ++jx) {
		do_fio(&c__1, (char *)&c__[i__ + (jx + jy * c_dim2) * c_dim1],
			 (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
/* L30: */
	}
	io___73.ciunit = *lun;
	s_wsfe(&io___73);
	e_wsfe();
/* L40: */
    }

    return 0;
/* ------------  end of subroutine outweb  ------------------------------- */
} /* outweb_ */

/* Subroutine */ int fweb_(integer *neq, doublereal *t, doublereal *cc, 
	doublereal *cdot)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__;
    static doublereal x, y;
    static integer ic, jx, jy, ici;
    extern /* Subroutine */ int webr_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *);
    static integer idxl, idyl, idxu, idyu;
    static doublereal dcxli, dcyli;
    static integer iyoff;
    static doublereal dcxui, dcyui;

/* ----------------------------------------------------------------------- */
/* This routine computes the derivative of cc and returns it in cdot. */
/* The interaction rates are computed by calls to webr, and these are */
/* saved in cc(neq+1),...,cc(2*neq) for use in preconditioning. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --cdot;
    --cc;

    /* Function Body */
    i__1 = pcom1_1.my;
    for (jy = 1; jy <= i__1; ++jy) {
	y = (jy - 1) * pcom1_1.dy;
	iyoff = pcom1_1.mxns * (jy - 1);
	idyu = pcom1_1.mxns;
	if (jy == pcom1_1.my) {
	    idyu = -pcom1_1.mxns;
	}
	idyl = pcom1_1.mxns;
	if (jy == 1) {
	    idyl = -pcom1_1.mxns;
	}
	i__2 = pcom1_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    x = (jx - 1) * pcom1_1.dx;
	    ic = iyoff + pcom1_1.ns * (jx - 1) + 1;
/* Get interaction rates at one point (x,y). */
	    webr_(&x, &y, t, &cc[ic], &cc[*neq + ic]);
	    idxu = pcom1_1.ns;
	    if (jx == pcom1_1.mx) {
		idxu = -pcom1_1.ns;
	    }
	    idxl = pcom1_1.ns;
	    if (jx == 1) {
		idxl = -pcom1_1.ns;
	    }
	    i__3 = pcom1_1.ns;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		ici = ic + i__ - 1;
/* Do differencing in y. */
		dcyli = cc[ici] - cc[ici - idyl];
		dcyui = cc[ici + idyu] - cc[ici];
/* Do differencing in x. */
		dcxli = cc[ici] - cc[ici - idxl];
		dcxui = cc[ici + idxu] - cc[ici];
/* Collect terms and load cdot elements. */
		cdot[ici] = pcom1_1.coy[i__ - 1] * (dcyui - dcyli) + 
			pcom1_1.cox[i__ - 1] * (dcxui - dcxli) + cc[*neq + 
			ici];
/* L80: */
	    }
/* L90: */
	}
/* L100: */
    }
    return 0;
/* ------------  end of subroutine fweb  --------------------------------- */
} /* fweb_ */

/* Subroutine */ int webr_(doublereal *x, doublereal *y, doublereal *t, 
	doublereal *c__, doublereal *rate)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal fac;
    extern /* Subroutine */ int daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);

/* ----------------------------------------------------------------------- */
/* This routine computes the interaction rates for the species */
/* c(1),...,c(ns), at one spatial point and at time t. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --rate;
    --c__;

    /* Function Body */
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	rate[i__] = 0.;
    }
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	daxpy_(&pcom1_1.ns, &c__[i__], &pcom1_1.acoef[i__ * 20 - 20], &c__1, &
		rate[1], &c__1);
/* L15: */
    }
    fac = pcom1_1.alph * *x * *y + 1.;
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	rate[i__] = c__[i__] * (pcom1_1.bcoef[i__ - 1] * fac + rate[i__]);
    }
    return 0;
/* ------------  end of subroutine webr  --------------------------------- */
} /* webr_ */

/* Subroutine */ int jacbg_(U_fp f, integer *neq, doublereal *t, doublereal *
	cc, doublereal *ccsv, doublereal *rewt, doublereal *f0, doublereal *
	f1, doublereal *hl0, doublereal *bd, integer *ipbd, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer i__, j, n;
    static doublereal r__, r0;
    static integer ig, jj, jx, jy, if0;
    static doublereal fac;
    static integer ibd, if00;
    extern /* Subroutine */ int fbg_(integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *);
    static integer iip, igx, igy;
    extern /* Subroutine */ int dgefa_(doublereal *, integer *, integer *, 
	    integer *, integer *);
    static integer idiag;
    extern doublereal dvnorm_(integer *, doublereal *, doublereal *);

/* ----------------------------------------------------------------------- */
/* This routine generates part of the block-diagonal part of the */
/* Jacobian, multiplies by -hl0, adds the identity matrix, */
/* and calls DGEFA to do LU decomposition of each diagonal block. */
/* The computation of the diagonal blocks uses the block and grouping */
/* information in /pcom1/ and /pcom2/.  One block per group is computed. */
/* The Jacobian elements are generated by difference quotients */
/* using calls to the routine fbg. */
/* ----------------------------------------------------------------------- */
/* The two Common blocks below are used for internal communication. */
/* The variables used are: */
/*   mp     = size of blocks in block-diagonal preconditioning matrix. */
/*   mq     = number of blocks in each direction (neq = mp*mq). */
/*   mpsq   = mp*mp. */
/*   uround = unit roundoff, generated by a call uround = dumach(). */
/*   srur   = sqrt(uround). */
/*   meshx  = x mesh size */
/*   meshy  = y mesh size (mesh is meshx by meshy) */
/*   ngx    = no. groups in x direction in block-grouping scheme. */
/*   ngy    = no. groups in y direction in block-grouping scheme. */
/*   ngrp   = total number of groups = ngx*ngy. */
/*   mxmp   = meshx*mp. */
/*   jgx    = length ngx+1 array of group boundaries in x direction. */
/*            group igx has x indices jx = jgx(igx),...,jgx(igx+1)-1. */
/*   jigx   = length meshx array of x group indices vs x node index. */
/*            x node index jx is in x group jigx(jx). */
/*   jxr    = length ngx array of x indices representing the x groups. */
/*            the index for x group igx is jx = jxr(igx). */
/*   jgy, jigy, jyr = analogous arrays for grouping in y direction. */
/* ----------------------------------------------------------------------- */


    /* Parameter adjustments */
    --f1;
    --f0;
    --rewt;
    --ccsv;
    --cc;
    --bd;
    --ipbd;

    /* Function Body */
    n = *neq;

/* ----------------------------------------------------------------------- */
/* Make mp calls to fbg to approximate each diagonal block of Jacobian. */
/* Here cc(neq+1),...,cc(2*neq) contains the base fb value. */
/* r0 is a minimum increment factor for the difference quotient. */
/* ----------------------------------------------------------------------- */
/* L200: */
    fac = dvnorm_(&n, &f0[1], &rewt[1]);
    r0 = abs(*hl0) * 1e3 * pcom2_1.uround * n * fac;
    if (r0 == 0.) {
	r0 = 1.;
    }
    ibd = 0;
    i__1 = pcom3_1.ngy;
    for (igy = 1; igy <= i__1; ++igy) {
	jy = pcom3_1.jyr[igy - 1];
	if00 = (jy - 1) * pcom3_1.mxmp;
	i__2 = pcom3_1.ngx;
	for (igx = 1; igx <= i__2; ++igx) {
	    jx = pcom3_1.jxr[igx - 1];
	    if0 = if00 + (jx - 1) * pcom2_1.mp;
	    i__3 = pcom2_1.mp;
	    for (j = 1; j <= i__3; ++j) {
		jj = if0 + j;
/* Computing MAX */
		d__2 = pcom2_1.srur * (d__1 = cc[jj], abs(d__1)), d__3 = r0 / 
			rewt[jj];
		r__ = max(d__2,d__3);
		cc[jj] += r__;
		fac = -(*hl0) / r__;
		fbg_(neq, t, &cc[1], &jx, &jy, &f1[1]);
		i__4 = pcom2_1.mp;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L210: */
		    bd[ibd + i__] = (f1[i__] - cc[*neq + if0 + i__]) * fac;
		}
		cc[jj] = ccsv[jj];
		ibd += pcom2_1.mp;
/* L220: */
	    }
/* L230: */
	}
/* L240: */
    }

/* Add identity matrix and do LU decompositions on blocks. -------------- */
/* L260: */
    ibd = 1;
    iip = 1;
    i__1 = pcom3_1.ngrp;
    for (ig = 1; ig <= i__1; ++ig) {
	idiag = ibd;
	i__2 = pcom2_1.mp;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    bd[idiag] += 1.;
/* L270: */
	    idiag += pcom2_1.mp + 1;
	}
	dgefa_(&bd[ibd], &pcom2_1.mp, &pcom2_1.mp, &ipbd[iip], ier);
	if (*ier != 0) {
	    goto L290;
	}
	ibd += pcom2_1.mpsq;
	iip += pcom2_1.mp;
/* L280: */
    }
L290:
    return 0;
/* ------------  end of subroutine jacbg  -------------------------------- */
} /* jacbg_ */

/* Subroutine */ int fbg_(integer *neq, doublereal *t, doublereal *cc, 
	integer *jx, integer *jy, doublereal *cdot)
{
    static doublereal x, y;
    static integer ic;
    extern /* Subroutine */ int webr_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *);
    static integer iblok;

/* ----------------------------------------------------------------------- */
/* This routine computes one block of the interaction terms of the */
/* system, namely block (jx,jy), for use in preconditioning. */
/* ----------------------------------------------------------------------- */


    /* Parameter adjustments */
    --cdot;
    --cc;

    /* Function Body */
    iblok = *jx + (*jy - 1) * pcom1_1.mx;
    y = (*jy - 1) * pcom1_1.dy;
    x = (*jx - 1) * pcom1_1.dx;
    ic = pcom1_1.ns * (iblok - 1) + 1;
    webr_(&x, &y, t, &cc[ic], &cdot[1]);
    return 0;
/* ------------  end of subroutine fbg  ---------------------------------- */
} /* fbg_ */

/* Subroutine */ int solsbg_(integer *n, doublereal *t, doublereal *cc, 
	doublereal *f0, doublereal *wk, doublereal *hl0, doublereal *bd, 
	integer *ipbd, doublereal *v, integer *lr, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    extern /* Subroutine */ int gs_(integer *, doublereal *, doublereal *, 
	    doublereal *);
    static integer iv, jx, jy, ig0, ibd, iip, igx, igy, igm1;
    extern /* Subroutine */ int dgesl_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *);

/* ----------------------------------------------------------------------- */
/* This routine applies one or two inverse preconditioner matrices */
/* to the array v, using the interaction-only block-diagonal Jacobian */
/* with block-grouping, and Gauss-Seidel applied to the diffusion terms. */
/* When lr = 1 or 3, it calls gs for a Gauss-Seidel approximation */
/* to ((I-hl0*Jd)-inverse)*v, and stores the result in v. */
/* When lr = 2 or 3, it computes ((I-hl0*dg/dc)-inverse)*v, using LU */
/* factors of the blocks in bd, and pivot information in ipbd. */
/* In both cases, the array v is overwritten with the solution. */
/* ----------------------------------------------------------------------- */


    /* Parameter adjustments */
    --v;
    --wk;
    --f0;
    --cc;
    --bd;
    --ipbd;

    /* Function Body */
    *ier = 0;

    if (*lr == 0 || *lr == 1 || *lr == 3) {
	gs_(n, hl0, &v[1], &wk[1]);
    }
    if (*lr == 0 || *lr == 2 || *lr == 3) {
	iv = 1;
	i__1 = pcom3_1.meshy;
	for (jy = 1; jy <= i__1; ++jy) {
	    igy = pcom3_1.jigy[jy - 1];
	    ig0 = (igy - 1) * pcom3_1.ngx;
	    i__2 = pcom3_1.meshx;
	    for (jx = 1; jx <= i__2; ++jx) {
		igx = pcom3_1.jigx[jx - 1];
		igm1 = igx - 1 + ig0;
		ibd = igm1 * pcom2_1.mpsq + 1;
		iip = igm1 * pcom2_1.mp + 1;
		dgesl_(&bd[ibd], &pcom2_1.mp, &pcom2_1.mp, &ipbd[iip], &v[iv],
			 &c__0);
		iv += pcom2_1.mp;
/* L10: */
	    }
/* L20: */
	}
    }

    return 0;
/* ------------  end of subroutine solsbg  ------------------------------- */
} /* solsbg_ */

/* Subroutine */ int gs_(integer *n, doublereal *hl0, doublereal *z__, 
	doublereal *x)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, ic, jx, jy, ici;
    static doublereal cof1[20], beta[20];
    static integer iter;
    static doublereal beta2[20], gamma[20];
    static integer iyoff;
    static doublereal gamma2[20], elamda;

/* ----------------------------------------------------------------------- */
/* This routine performs itmax Gauss-Seidel iterations */
/* to compute an approximation to P-inverse*z, where P = I - hl0*Jd, and */
/* Jd represents the diffusion contributions to the Jacobian. */
/* z contains the answer on return. */
/* The dimensions below assume ns .le. 20. */
/* ----------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */
/* Write matrix as P = D - L - U. */
/* Load local arrays beta, beta2, gamma, gamma2, and cof1. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --x;
    --z__;

    /* Function Body */
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	elamda = 1. / (*hl0 * 2. * (pcom1_1.cox[i__ - 1] + pcom1_1.coy[i__ - 
		1]) + 1.);
	beta[i__ - 1] = *hl0 * pcom1_1.cox[i__ - 1] * elamda;
	beta2[i__ - 1] = beta[i__ - 1] * 2.;
	gamma[i__ - 1] = *hl0 * pcom1_1.coy[i__ - 1] * elamda;
	gamma2[i__ - 1] = gamma[i__ - 1] * 2.;
	cof1[i__ - 1] = elamda;
/* L10: */
    }
/* ----------------------------------------------------------------------- */
/* Begin iteration loop. */
/* Load array x with (D-inverse)*z for first iteration. */
/* ----------------------------------------------------------------------- */
    iter = 1;

    i__1 = pcom1_1.my;
    for (jy = 1; jy <= i__1; ++jy) {
	iyoff = pcom1_1.mxns * (jy - 1);
	i__2 = pcom1_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    ic = iyoff + pcom1_1.ns * (jx - 1);
	    i__3 = pcom1_1.ns;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		ici = ic + i__;
		x[ici] = cof1[i__ - 1] * z__[ici];
		z__[ici] = 0.;
/* L30: */
	    }
/* L40: */
	}
/* L50: */
    }
    goto L160;
/* ----------------------------------------------------------------------- */
/* Calculate (D-inverse)*U*x. */
/* ----------------------------------------------------------------------- */
L70:
    ++iter;
    jy = 1;
    jx = 1;
    ic = pcom1_1.ns * (jx - 1);
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
/* L75: */
	x[ici] = beta2[i__ - 1] * x[ici + pcom1_1.ns] + gamma2[i__ - 1] * x[
		ici + pcom1_1.mxns];
    }
    i__1 = pcom1_1.mx - 1;
    for (jx = 2; jx <= i__1; ++jx) {
	ic = pcom1_1.ns * (jx - 1);
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
/* L80: */
	    x[ici] = beta[i__ - 1] * x[ici + pcom1_1.ns] + gamma2[i__ - 1] * 
		    x[ici + pcom1_1.mxns];
	}
/* L85: */
    }
    jx = pcom1_1.mx;
    ic = pcom1_1.ns * (jx - 1);
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
/* L90: */
	x[ici] = gamma2[i__ - 1] * x[ici + pcom1_1.mxns];
    }
    i__1 = pcom1_1.my - 1;
    for (jy = 2; jy <= i__1; ++jy) {
	iyoff = pcom1_1.mxns * (jy - 1);
	jx = 1;
	ic = iyoff;
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
/* L95: */
	    x[ici] = beta2[i__ - 1] * x[ici + pcom1_1.ns] + gamma[i__ - 1] * 
		    x[ici + pcom1_1.mxns];
	}
	i__2 = pcom1_1.mx - 1;
	for (jx = 2; jx <= i__2; ++jx) {
	    ic = iyoff + pcom1_1.ns * (jx - 1);
	    i__3 = pcom1_1.ns;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		ici = ic + i__;
/* L100: */
		x[ici] = beta[i__ - 1] * x[ici + pcom1_1.ns] + gamma[i__ - 1] 
			* x[ici + pcom1_1.mxns];
	    }
/* L105: */
	}
	jx = pcom1_1.mx;
	ic = iyoff + pcom1_1.ns * (jx - 1);
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
/* L110: */
	    x[ici] = gamma[i__ - 1] * x[ici + pcom1_1.mxns];
	}
/* L115: */
    }
    jy = pcom1_1.my;
    iyoff = pcom1_1.mxns * (jy - 1);
    jx = 1;
    ic = iyoff;
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
/* L120: */
	x[ici] = beta2[i__ - 1] * x[ici + pcom1_1.ns];
    }
    i__1 = pcom1_1.mx - 1;
    for (jx = 2; jx <= i__1; ++jx) {
	ic = iyoff + pcom1_1.ns * (jx - 1);
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
/* L125: */
	    x[ici] = beta[i__ - 1] * x[ici + pcom1_1.ns];
	}
/* L130: */
    }
    jx = pcom1_1.mx;
    ic = iyoff + pcom1_1.ns * (jx - 1);
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
/* L135: */
	x[ici] = 0.;
    }
/* ----------------------------------------------------------------------- */
/* Calculate (I - (D-inverse)*L)-inverse * x. */
/* ----------------------------------------------------------------------- */
L160:
    jy = 1;
    i__1 = pcom1_1.mx - 1;
    for (jx = 2; jx <= i__1; ++jx) {
	ic = pcom1_1.ns * (jx - 1);
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
/* L170: */
	    x[ici] += beta[i__ - 1] * x[ici - pcom1_1.ns];
	}
/* L175: */
    }
    jx = pcom1_1.mx;
    ic = pcom1_1.ns * (jx - 1);
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
/* L180: */
	x[ici] += beta2[i__ - 1] * x[ici - pcom1_1.ns];
    }
    i__1 = pcom1_1.my - 1;
    for (jy = 2; jy <= i__1; ++jy) {
	iyoff = pcom1_1.mxns * (jy - 1);
	jx = 1;
	ic = iyoff;
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
/* L185: */
	    x[ici] += gamma[i__ - 1] * x[ici - pcom1_1.mxns];
	}
	i__2 = pcom1_1.mx - 1;
	for (jx = 2; jx <= i__2; ++jx) {
	    ic = iyoff + pcom1_1.ns * (jx - 1);
	    i__3 = pcom1_1.ns;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		ici = ic + i__;
		x[ici] = x[ici] + beta[i__ - 1] * x[ici - pcom1_1.ns] + gamma[
			i__ - 1] * x[ici - pcom1_1.mxns];
/* L195: */
	    }
/* L200: */
	}
	jx = pcom1_1.mx;
	ic = iyoff + pcom1_1.ns * (jx - 1);
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
	    x[ici] = x[ici] + beta2[i__ - 1] * x[ici - pcom1_1.ns] + gamma[
		    i__ - 1] * x[ici - pcom1_1.mxns];
/* L205: */
	}
/* L210: */
    }
    jy = pcom1_1.my;
    iyoff = pcom1_1.mxns * (jy - 1);
    jx = 1;
    ic = iyoff;
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
/* L215: */
	x[ici] += gamma2[i__ - 1] * x[ici - pcom1_1.mxns];
    }
    i__1 = pcom1_1.mx - 1;
    for (jx = 2; jx <= i__1; ++jx) {
	ic = iyoff + pcom1_1.ns * (jx - 1);
	i__2 = pcom1_1.ns;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ici = ic + i__;
	    x[ici] = x[ici] + beta[i__ - 1] * x[ici - pcom1_1.ns] + gamma2[
		    i__ - 1] * x[ici - pcom1_1.mxns];
/* L220: */
	}
/* L225: */
    }
    jx = pcom1_1.mx;
    ic = iyoff + pcom1_1.ns * (jx - 1);
    i__1 = pcom1_1.ns;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ici = ic + i__;
	x[ici] = x[ici] + beta2[i__ - 1] * x[ici - pcom1_1.ns] + gamma2[i__ - 
		1] * x[ici - pcom1_1.mxns];
/* L230: */
    }
/* ----------------------------------------------------------------------- */
/* Add increment x to z. */
/* ----------------------------------------------------------------------- */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L300: */
	z__[i__] += x[i__];
    }

    if (iter < pcom2_1.itmax) {
	goto L70;
    }
    return 0;
/* ------------  end of subroutine gs  ----------------------------------- */
} /* gs_ */

