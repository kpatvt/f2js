/* demo6.f -- translated by f2c (version 20160102).
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
    doublereal q1, q2, q3, q4, a3, a4, om, c3, dz, hdco, vdco, haco;
    integer mx, mz, mm;
} pcom_;

#define pcom_1 pcom_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;

/* ----------------------------------------------------------------------- */
/* Demonstration program for the DLSODKR package. */
/* This is the version of 27 April 2005. */

/* This version is in double precision. */

/* An ODE system is generated from the following 2-species diurnal */
/* kinetics advection-diffusion PDE system in 2 space dimensions: */

/* dc(i)/dt = Kh*(d/dx)**2 c(i) + V*dc(i)/dx + (d/dz)(Kv(z)*dc(i)/dz) */
/*                 + Ri(c1,c2,t)      for i = 1,2,   where */
/*   R1(c1,c2,t) = -q1*c1*c3 - q2*c1*c2 + 2*q3(t)*c3 + q4(t)*c2 , */
/*   R2(c1,c2,t) =  q1*c1*c3 - q2*c1*c2 - q4(t)*c2 , */
/*   Kv(z) = Kv0*exp(z/5) , */
/* Kh, V, Kv0, q1, q2, and c3 are constants, and q3(t) and q4(t) */
/* vary diurnally.  The species are oxygen singlet and ozone. */
/* The problem is posed on the square */
/*   0 .le. x .le. 20,    30 .le. z .le. 50   (all in km), */
/* with homogeneous Neumann boundary conditions, and for time t in */
/*   0 .le. t .le. 86400 sec (1 day). */

/* The PDE system is treated by central differences on a uniform */
/* 10 x 10 mesh, with simple polynomial initial profiles. */

/* The problem is solved with DLSODKR, with the BDF/GMRES method and */
/* the block-diagonal part of the Jacobian as a left preconditioner. */
/* At intervals of 7200 sec (2 hrs), output includes sample values */
/* of c1, c2, and c2tot = total of all c2 values. */

/* Roots of the function g = d(c2tot)/dt are found, i.e. the points at */
/* which the total c2 (ozone) is stationary. */

/* Note: The preconditioner routines call LINPACK routines DGEFA, DGESL, */
/* and the BLAS routines DCOPY and DSCAL. */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static doublereal dkh = 4e-6;
    static integer liw = 235;
    static integer mf = 22;
    static integer jpre = 1;
    static integer jacflg = 1;
    static doublereal vel = .001;
    static doublereal dkv0 = 1e-8;
    static doublereal halfda = 43200.;
    static doublereal pi = 3.1415926535898;
    static doublereal twohr = 7200.;
    static doublereal rtol = 1e-5;
    static doublereal floor = 100.;
    static integer lrw = 4264;

    /* Format strings */
    static char fmt_30[] = "(\002Demonstration program for DLSODKR packag"
	    "e\002//\0022D diurnal kinetics-transport PDE system with 2 speci"
	    "es\002/\002Spatial mesh is\002,i3,\002 by\002,i3/\002Method flag"
	    " is mf =\002,i3,\002   Tolerances are rtol =\002,d8.1,\002   ato"
	    "l =\002,d8.1/\002Left preconditioner uses block-diagonal part of"
	    " Jacobian\002/\002Root function finds stationary points of total"
	    " ozone,\002/\002  i.e. roots of (d/dt)(sum of c2 over all mesh p"
	    "oints)\002/)";
    static char fmt_50[] = "(/\002 t =\002,d10.3,4x,\002no. steps =\002,i5"
	    ",\002   order =\002,i2,\002   stepsize =\002,d10.3)";
    static char fmt_60[] = "(\002   c1 (bot.left/middle/top rt.) =\002,3d12."
	    "3/\002   c2 (bot.left/middle/top rt.) =\002,3d12.3)";
    static char fmt_62[] = "(\002   total c2 =\002,d15.6,\002   jroot =\002,"
	    "i2\002 (1 = root found, 0 = no root)\002)";
    static char fmt_65[] = "(\002DLSODKR returned istate = \002,i3)";
    static char fmt_80[] = "(//\002 Final statistics:\002/\002 rwork size "
	    "=\002,i5,5x,\002 iwork size =\002,i4/\002 number of steps       "
	    " =\002,i5,5x,\002no. fnal. iter. steps  =\002,i5/\002 number of "
	    "f evals.     =\002,i5,5x,\002number of g evals.     =\002,i5/"
	    "\002 number of prec. evals. =\002,i5,5x,\002number of Jac. evals"
	    ".  =\002,i5/\002 number of prec. solves =\002,i5/\002 number of "
	    "nonl. iters. =\002,i5,5x,\002number of lin. iters.  =\002,i5/"
	    "\002 average Krylov subspace dimension (nli/nni)  =\002,f8.4/"
	    "\002 number of conv. failures:  nonlinear =\002,i3,\002  linear ="
	    "\002,i3)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal t, x, y[200]	/* was [2][10][10] */, z__, cx, dx, 
	    cz;
    static integer jx, jz, nfe, nge, npe, neq, nni, nli, nps, nst;
    extern /* Subroutine */ int fdem_(), gdem_();
    static integer ncfl, ncfn, nsfi;
    static doublereal atol;
    static integer njev, iout;
    static doublereal tout;
    extern /* Subroutine */ int c2sum_(doublereal *, integer *, integer *, 
	    doublereal *);
    static doublereal c2tot;
    extern /* Subroutine */ int jacbd_();
    static doublereal avdim;
    extern /* Subroutine */ int solbd_();
    static integer leniw, lenrw, iwork[235], jroot;
    static doublereal rwork[4264];
    static integer istate;
    extern /* Subroutine */ int dlsodkr_(U_fp, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *, integer *, integer *, doublereal *, integer *, 
	    integer *, integer *, U_fp, U_fp, integer *, U_fp, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___29 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___32 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___34 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___35 = { 0, 6, 0, fmt_62, 0 };
    static cilist io___36 = { 0, 6, 0, fmt_65, 0 };
    static cilist io___51 = { 0, 6, 0, fmt_80, 0 };



/* Load Common block of problem parameters. */
    pcom_1.mx = 10;
    pcom_1.mz = 10;
    pcom_1.mm = pcom_1.mx * pcom_1.mz;
    pcom_1.q1 = 1.63e-16;
    pcom_1.q2 = 4.66e-16;
    pcom_1.a3 = 22.62;
    pcom_1.a4 = 7.601;
    pcom_1.om = pi / halfda;
    pcom_1.c3 = 3.7e16;
    dx = 20. / (pcom_1.mx - 1.);
    pcom_1.dz = 20. / (pcom_1.mz - 1.);
/* Computing 2nd power */
    d__1 = dx;
    pcom_1.hdco = dkh / (d__1 * d__1);
    pcom_1.haco = vel / (dx * 2.);
/* Computing 2nd power */
    d__1 = pcom_1.dz;
    pcom_1.vdco = 1. / (d__1 * d__1) * dkv0;
/* Set other input arguments. */
    atol = rtol * floor;
    neq = (pcom_1.mx << 1) * pcom_1.mz;
    iwork[0] = (pcom_1.mx << 3) * pcom_1.mz;
    iwork[1] = neq;
    iwork[2] = jpre;
    iwork[3] = jacflg;
    t = 0.;
    tout = 0.;
    istate = 1;
/* Initialize values for tout = 0 output. */
    iwork[10] = 0;
    iwork[13] = 0;
    rwork[10] = 0.;
/* Set initial profiles. */
    i__1 = pcom_1.mz;
    for (jz = 1; jz <= i__1; ++jz) {
	z__ = (jz - 1.) * pcom_1.dz + 30.;
/* Computing 2nd power */
	d__1 = (z__ - 40.) * .1;
	cz = d__1 * d__1;
/* Computing 2nd power */
	d__1 = cz;
	cz = 1. - cz + d__1 * d__1 * .5;
	i__2 = pcom_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    x = (jx - 1.) * dx;
/* Computing 2nd power */
	    d__1 = (x - 10.) * .1;
	    cx = d__1 * d__1;
/* Computing 2nd power */
	    d__1 = cx;
	    cx = 1. - cx + d__1 * d__1 * .5;
	    y[(jx + jz * 10 << 1) - 22] = cx * 1e6 * cz;
	    y[(jx + jz * 10 << 1) - 21] = cx * 1e12 * cz;
/* L10: */
	}
/* L20: */
    }

/* Write heading, problem parameters, solution parameters. */
    s_wsfe(&io___29);
    do_fio(&c__1, (char *)&pcom_1.mx, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&pcom_1.mz, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&mf, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* Loop over output points, call DLSODKR, print sample solution values. */
    for (iout = 1; iout <= 13; ++iout) {
L40:
	dlsodkr_((U_fp)fdem_, &neq, y, &t, &tout, &c__1, &rtol, &atol, &c__1, 
		&istate, &c__0, rwork, &lrw, iwork, &liw, (U_fp)jacbd_, (U_fp)
		solbd_, &mf, (U_fp)gdem_, &c__1, &jroot);
	s_wsfe(&io___32);
	do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&iwork[10], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&iwork[13], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rwork[10], (ftnlen)sizeof(doublereal));
	e_wsfe();
	c2sum_(y, &pcom_1.mx, &pcom_1.mz, &c2tot);
	s_wsfe(&io___34);
	do_fio(&c__1, (char *)&y[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[88], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[198], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[89], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[199], (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&c2tot, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&jroot, (ftnlen)sizeof(integer));
	e_wsfe();
	if (istate < 0) {
	    s_wsfe(&io___36);
	    do_fio(&c__1, (char *)&istate, (ftnlen)sizeof(integer));
	    e_wsfe();
	    goto L75;
	}
	if (istate == 3) {
	    istate = 2;
	    goto L40;
	}
	tout += twohr;
/* L70: */
    }

/* Print final statistics. */
L75:
    lenrw = iwork[16];
    leniw = iwork[17];
    nst = iwork[10];
    nsfi = iwork[23];
    nfe = iwork[11];
    nge = iwork[9];
    npe = iwork[12];
    njev = iwork[24];
    nps = iwork[20];
    nni = iwork[18];
    nli = iwork[19];
    avdim = (real) nli / (real) nni;
    ncfn = iwork[21];
    ncfl = iwork[22];
    s_wsfe(&io___51);
    do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nsfi, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nge, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&njev, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nps, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nni, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nli, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&avdim, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ncfn, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ncfl, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Subroutine */ int fdem_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *ydot)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sin(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal s, c1, c2;
    static integer jx, jz;
    static doublereal qq1, qq2, qq3, qq4;
    static integer idn;
    static doublereal zdn;
    static integer iup;
    static doublereal zup, c1dn, c2dn, c1lt, c2lt, c1up, c1rt, c2up, c2rt, 
	    czdn, czup, hord1, hord2, rkin1, rkin2;
    static integer iblok, ileft;
    static doublereal horad1, horad2;
    static integer iblok0;
    static doublereal vertd1, vertd2;
    static integer iright;


/* Set diurnal rate coefficients. */
    /* Parameter adjustments */
    ydot -= 3;
    y -= 3;

    /* Function Body */
    s = sin(pcom_1.om * *t);
    if (s > 0.) {
	pcom_1.q3 = exp(-pcom_1.a3 / s);
	pcom_1.q4 = exp(-pcom_1.a4 / s);
    } else {
	pcom_1.q3 = 0.;
	pcom_1.q4 = 0.;
    }
/* Loop over all grid points. */
    i__1 = pcom_1.mz;
    for (jz = 1; jz <= i__1; ++jz) {
	zdn = (jz - 1.5) * pcom_1.dz + 30.;
	zup = zdn + pcom_1.dz;
	czdn = pcom_1.vdco * exp(zdn * .2);
	czup = pcom_1.vdco * exp(zup * .2);
	iblok0 = (jz - 1) * pcom_1.mx;
	idn = -pcom_1.mx;
	if (jz == 1) {
	    idn = pcom_1.mx;
	}
	iup = pcom_1.mx;
	if (jz == pcom_1.mz) {
	    iup = -pcom_1.mx;
	}
	i__2 = pcom_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    iblok = iblok0 + jx;
	    c1 = y[(iblok << 1) + 1];
	    c2 = y[(iblok << 1) + 2];
/* Set kinetic rate terms. */
	    qq1 = pcom_1.q1 * c1 * pcom_1.c3;
	    qq2 = pcom_1.q2 * c1 * c2;
	    qq3 = pcom_1.q3 * pcom_1.c3;
	    qq4 = pcom_1.q4 * c2;
	    rkin1 = -qq1 - qq2 + qq3 * 2. + qq4;
	    rkin2 = qq1 - qq2 - qq4;
/* Set vertical diffusion terms. */
	    c1dn = y[(iblok + idn << 1) + 1];
	    c2dn = y[(iblok + idn << 1) + 2];
	    c1up = y[(iblok + iup << 1) + 1];
	    c2up = y[(iblok + iup << 1) + 2];
	    vertd1 = czup * (c1up - c1) - czdn * (c1 - c1dn);
	    vertd2 = czup * (c2up - c2) - czdn * (c2 - c2dn);
/* Set horizontal diffusion and advection terms. */
	    ileft = -1;
	    if (jx == 1) {
		ileft = 1;
	    }
	    iright = 1;
	    if (jx == pcom_1.mx) {
		iright = -1;
	    }
	    c1lt = y[(iblok + ileft << 1) + 1];
	    c2lt = y[(iblok + ileft << 1) + 2];
	    c1rt = y[(iblok + iright << 1) + 1];
	    c2rt = y[(iblok + iright << 1) + 2];
	    hord1 = pcom_1.hdco * (c1rt - c1 * 2. + c1lt);
	    hord2 = pcom_1.hdco * (c2rt - c2 * 2. + c2lt);
	    horad1 = pcom_1.haco * (c1rt - c1lt);
	    horad2 = pcom_1.haco * (c2rt - c2lt);
/* Load all terms into ydot. */
	    ydot[(iblok << 1) + 1] = vertd1 + hord1 + horad1 + rkin1;
	    ydot[(iblok << 1) + 2] = vertd2 + hord2 + horad2 + rkin2;
/* L10: */
	}
/* L20: */
    }
    return 0;
} /* fdem_ */

/* Subroutine */ int gdem_(integer *neq, doublereal *t, doublereal *y, 
	integer *ng, doublereal *gout)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sin(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal s, c1, c2;
    static integer jx, jz;
    static doublereal qq1, qq2, qq4;
    static integer idn;
    static doublereal zdn;
    static integer iup;
    static doublereal sum, zup, c2dn, c2lt, c2up, c2rt, czdn, czup, c2dot, 
	    hord2, rkin2;
    static integer iblok, ileft;
    static doublereal horad2;
    static integer iblok0;
    static doublereal vertd2;
    static integer iright;


/* This routine computes the rates for c2 and adds them. */

/* Set diurnal rate coefficient q4. */
    /* Parameter adjustments */
    y -= 3;

    /* Function Body */
    s = sin(pcom_1.om * *t);
    if (s > 0.) {
	pcom_1.q4 = exp(-pcom_1.a4 / s);
    } else {
	pcom_1.q4 = 0.;
    }
    sum = 0.;
/* Loop over all grid points. */
    i__1 = pcom_1.mz;
    for (jz = 1; jz <= i__1; ++jz) {
	zdn = (jz - 1.5) * pcom_1.dz + 30.;
	zup = zdn + pcom_1.dz;
	czdn = pcom_1.vdco * exp(zdn * .2);
	czup = pcom_1.vdco * exp(zup * .2);
	iblok0 = (jz - 1) * pcom_1.mx;
	idn = -pcom_1.mx;
	if (jz == 1) {
	    idn = pcom_1.mx;
	}
	iup = pcom_1.mx;
	if (jz == pcom_1.mz) {
	    iup = -pcom_1.mx;
	}
	i__2 = pcom_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    iblok = iblok0 + jx;
	    c1 = y[(iblok << 1) + 1];
	    c2 = y[(iblok << 1) + 2];
/* Set kinetic rate term for c2. */
	    qq1 = pcom_1.q1 * c1 * pcom_1.c3;
	    qq2 = pcom_1.q2 * c1 * c2;
	    qq4 = pcom_1.q4 * c2;
	    rkin2 = qq1 - qq2 - qq4;
/* Set vertical diffusion terms for c2. */
	    c2dn = y[(iblok + idn << 1) + 2];
	    c2up = y[(iblok + iup << 1) + 2];
	    vertd2 = czup * (c2up - c2) - czdn * (c2 - c2dn);
/* Set horizontal diffusion and advection terms for c2. */
	    ileft = -1;
	    if (jx == 1) {
		ileft = 1;
	    }
	    iright = 1;
	    if (jx == pcom_1.mx) {
		iright = -1;
	    }
	    c2lt = y[(iblok + ileft << 1) + 2];
	    c2rt = y[(iblok + iright << 1) + 2];
	    hord2 = pcom_1.hdco * (c2rt - c2 * 2. + c2lt);
	    horad2 = pcom_1.haco * (c2rt - c2lt);
/* Load all terms into c2dot and sum. */
	    c2dot = vertd2 + hord2 + horad2 + rkin2;
	    sum += c2dot;
/* L10: */
	}
/* L20: */
    }
    *gout = sum;
    return 0;
} /* gdem_ */

/* Subroutine */ int jacbd_(U_fp f, integer *neq, doublereal *t, doublereal *
	y, doublereal *ysv, doublereal *rewt, doublereal *f0, doublereal *f1, 
	doublereal *hl0, integer *jok, doublereal *bd, integer *ipbd, integer 
	*ier)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double exp(doublereal);

    /* Local variables */
    static doublereal c1, c2;
    static integer jx, jz;
    static doublereal zdn, zup, diag, czdn, temp, czup;
    extern /* Subroutine */ int dgefa_(doublereal *, integer *, integer *, 
	    integer *, integer *);
    static integer lenbd;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *);
    static integer iblok;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static integer iblok0;


    /* Parameter adjustments */
    --f1;
    --f0;
    --rewt;
    --ysv;
    y -= 3;
    bd -= 7;
    ipbd -= 3;

    /* Function Body */
    lenbd = pcom_1.mm << 2;
/* If jok = 1, copy saved block-diagonal approximate Jacobian into bd. */
    if (*jok == 1) {
	dcopy_(&lenbd, &bd[((pcom_1.mm + 1 << 1) + 1 << 1) + 1], &c__1, &bd[7]
		, &c__1);
	goto L30;
    }

/* If jok = -1, compute and save diagonal Jacobian blocks */
/*  (using q3 and q4 values computed on last f call). */
    i__1 = pcom_1.mz;
    for (jz = 1; jz <= i__1; ++jz) {
	zdn = (jz - 1.5) * pcom_1.dz + 30.;
	zup = zdn + pcom_1.dz;
	czdn = pcom_1.vdco * exp(zdn * .2);
	czup = pcom_1.vdco * exp(zup * .2);
	diag = -(czdn + czup + pcom_1.hdco * 2.);
	iblok0 = (jz - 1) * pcom_1.mx;
	i__2 = pcom_1.mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    iblok = iblok0 + jx;
	    c1 = y[(iblok << 1) + 1];
	    c2 = y[(iblok << 1) + 2];
	    bd[((iblok << 1) + 1 << 1) + 1] = -pcom_1.q1 * pcom_1.c3 - 
		    pcom_1.q2 * c2 + diag;
	    bd[((iblok << 1) + 2 << 1) + 1] = -pcom_1.q2 * c1 + pcom_1.q4;
	    bd[((iblok << 1) + 1 << 1) + 2] = pcom_1.q1 * pcom_1.c3 - 
		    pcom_1.q2 * c2;
	    bd[((iblok << 1) + 2 << 1) + 2] = -pcom_1.q2 * c1 - pcom_1.q4 + 
		    diag;
/* L10: */
	}
/* L20: */
    }
    dcopy_(&lenbd, &bd[7], &c__1, &bd[((pcom_1.mm + 1 << 1) + 1 << 1) + 1], &
	    c__1);
/* Scale by -hl0, add identity matrix and LU-decompose blocks. */
L30:
    temp = -(*hl0);
    dscal_(&lenbd, &temp, &bd[7], &c__1);
    i__1 = pcom_1.mm;
    for (iblok = 1; iblok <= i__1; ++iblok) {
	bd[((iblok << 1) + 1 << 1) + 1] += 1.;
	bd[((iblok << 1) + 2 << 1) + 2] += 1.;
	dgefa_(&bd[((iblok << 1) + 1 << 1) + 1], &c__2, &c__2, &ipbd[(iblok <<
		 1) + 1], ier);
	if (*ier != 0) {
	    return 0;
	}
/* L40: */
    }
    return 0;
} /* jacbd_ */

/* Subroutine */ int solbd_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *f0, doublereal *wk, doublereal *hl0, doublereal *bd, 
	integer *ipbd, doublereal *v, integer *lr, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int dgesl_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *);

/* Solve the block-diagonal system Px = v using LU factors stored in bd */
/* and pivot data in ipbd, and return the solution in v. */
    /* Parameter adjustments */
    --wk;
    --f0;
    --y;
    bd -= 7;
    ipbd -= 3;
    v -= 3;

    /* Function Body */
    *ier = 0;
    i__1 = pcom_1.mm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dgesl_(&bd[((i__ << 1) + 1 << 1) + 1], &c__2, &c__2, &ipbd[(i__ << 1) 
		+ 1], &v[(i__ << 1) + 1], &c__0);
/* L10: */
    }
    return 0;
} /* solbd_ */

/* Subroutine */ int c2sum_(doublereal *y, integer *mx, integer *mz, 
	doublereal *c2tot)
{
    /* System generated locals */
    integer y_dim2, y_offset, i__1, i__2;

    /* Local variables */
    static integer jx, jz;
    static doublereal sum;

/* Sum the c2 values. */
    /* Parameter adjustments */
    y_dim2 = *mx;
    y_offset = 1 + 2 * (1 + y_dim2);
    y -= y_offset;

    /* Function Body */
    sum = 0.;
    i__1 = *mz;
    for (jz = 1; jz <= i__1; ++jz) {
	i__2 = *mx;
	for (jx = 1; jx <= i__2; ++jx) {
/* L20: */
	    sum += y[(jx + jz * y_dim2 << 1) + 2];
	}
    }
    *c2tot = sum;
    return 0;
} /* c2sum_ */

