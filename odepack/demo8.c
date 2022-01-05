/* demo8.f -- translated by f2c (version 20160102).
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
    doublereal r6d, eodsq[3];
    integer ncomp, nip, nm1;
} par_;

#define par_1 par_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;

/* ----------------------------------------------------------------------- */
/* Demonstration program for the DLSOIBT package. */
/* This is the version of 14 June 2001. */

/* This version is in double precision. */

/* This program solves a semi-discretized form of the following system */
/* Of three PDEs (each similar to a Burgers equation): */

/*   u(i)   =  -(u(1)+u(2)+u(3)) u(i)   +  eta(i) u(i)    (i=1,2,3), */
/*       t                           x                xx */

/* on the interval  -1 .le. x .le. 1, and with time t .ge. 0. */
/* The diffusion coefficients are eta(*) = .1, .02, .01. */
/* The boundary conditions are u(i) = 0 at x = -1 and x = 1 for all i. */
/* The initial profile for each u(i) is a square wave: */
/*     u(i) = 0         on 1/2 .lt. abs(x) .le. 1 */
/*     u(i) = amp(i)/2  on abs(x) = 1/2 */
/*     u(i) = amp(i)    on 0 .le. abs(x) .lt. 1/2 */
/* where the amplitudes are amp(*) = .2, .3, .5. */

/* A simplified Galerkin treatment of the spatial variable x is used, */
/* with piecewise linear basis functions on a uniform mesh of 100 */
/* intervals.  The result is a system of ODEs in the discrete values */
/* u(i,k) approximating u(i)  (i=1,2,3) at the interior points */
/* (k = 1,...,99).  The ODEs are: */

/*    .            .        . */
/*   (u(i,k-1) + 4 u(i,k) + u(i,k+1))/6  = */

/*     -(1/6dx) (c(k-1)dul(i) + 2c(k)(dul(i)+dur(i)) + c(k+1)dur(i)) */

/*     + (eta(i)/dx**2) (dur(i) - dul(i))     (i=1,2,3,  k=1,...,99), */

/* where */
/*     c(j) = u(1,j)+u(2,j)+u(3,j),   dx = .02 = the interval size, */
/*     dul(i) = u(i,k) - u(i,k-1),   dur(i) = u(i,k+1) - u(i,k). */
/* Terms involving boundary values (subscripts 0 or 100) are dropped */
/* from the equations for k = 1 and k = 99 above. */

/* The problem is run for each of the 4 values of mf, and for two values */
/* of the tolerances.  Output is taken at t = .1, .2, .3, .4. */
/* Output is on unit lout, set to 6 in a data statement below. */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static doublereal eta[3] = { .1,.02,.01 };
    static integer nout = 4;
    static integer lrw = 7447;
    static integer liw = 317;
    static integer itol = 1;
    static doublereal tols[2] = { .001,1e-6 };
    static doublereal tinit = 0.;
    static doublereal tlast = .4;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal six = 6.;
    static doublereal hun = 100.;
    static doublereal tout[4] = { .1,.2,.3,.4 };
    static integer lout = 6;

    /* Format strings */
    static char fmt_1000[] = "(/20x,\002 Demonstration Problem for DLSOIB"
	    "T\002//10x,\002Galerkin method solution of system of 3 PDEs:\002"
	    "//10x,\002  u(i)   =  -(u(1)+u(2)+u(3)) u(i)   +  eta(i) u(i)"
	    "\002,5x,\002(i=1,2,3)\002,/16x,\002t\002,27x,\002x\002,16x,\002xx"
	    "\002//10x,\002x interval is -1 to 1,  zero boundary condition"
	    "s\002/10x,\002x discretized using piecewise linear basis functio"
	    "ns\002)";
    static char fmt_1100[] = "(/10x,\002Fixed parameters are as follows:\002"
	    "/13x,\002Diffusion coefficients are eta =\002,3d10.2/13x,\002t0 "
	    "= \002,d12.5/13x,\002tlast = \002,d12.5/13x,\002Uniform mesh, nu"
	    "mber of intervals =\002,i4/13x,\002Block size mb =\002,i2/13x"
	    ",\002Number of blocks nb =\002,i4/13x,\002ODE system size neq "
	    "=\002,i5//)";
    static char fmt_1200[] = "(/\002Initial profiles:\002/)";
    static char fmt_1500[] = "(////90(\002*\002)//\002Run with rtol =\002,d9"
	    ".1,\002  atol =\002,d9.1,\002   mf =\002,i3///)";
    static char fmt_2000[] = "(\002 At time t =\002,d12.5,\002  current h "
	    "=\002,d12.5,\002  current order =\002,i2,\002  current nst =\002"
	    ",i5/)";
    static char fmt_4000[] = "(//20x,\002Final time reached for mf = \002,"
	    "i2,\002 was t = \002,d12.5/25x,\002at which istate = \002,i2//)";
    static char fmt_3000[] = "(//\002Final statistics for mf = \002,i2,\002"
	    ":\002,i5,\002 steps,\002,i6,\002 res,\002,i6,\002 jacobians,\002"
	    "/30x,\002rwork size =\002,i6,\002,  iwork size =\002,i6)";
    static char fmt_5000[] = "(\002Final output is correct to within \002,d9"
	    ".2,\002  times local error tolerance. \002)";
    static char fmt_5100[] = "(\002Final output is wrong by \002,d9.2,\002  "
	    "times local error tolerance.\002)";
    static char fmt_6000[] = "(//90(\002*\002)//\002Run completed: \002,i3"
	    ",\002 errors encountered\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal t, y[297];
    static integer mf, io;
    static doublereal dx;
    static integer neq;
    extern /* Subroutine */ int res_();
    extern /* Subroutine */ int edit_(doublereal *, integer *, integer *, 
	    integer *);
    static integer meth;
    static doublereal atol;
    static integer nerr, jtol, nint;
    static doublereal rtol;
    extern /* Subroutine */ int jacbt_();
    extern /* Subroutine */ int setic_(integer *, integer *, doublereal *);
    static integer miter;
    static doublereal ydoti[297];
    static integer iwork[317];
    static doublereal rwork[7447];
    extern /* Subroutine */ int addabt_();
    static doublereal errfac, abermx;
    static integer istate;
    extern /* Subroutine */ int maxerr_(doublereal *, integer *, integer *, 
	    doublereal *), dlsoibt_(U_fp, U_fp, U_fp, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, doublereal *
	    , doublereal *, integer *, integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___22 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_1100, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_1200, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_1500, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_4000, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_5000, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_5100, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_6000, 0 };


/* Pass problem parameters in the common block par. */

/* Set problem parameters and run parameters */

/* Set mesh parameters nint, dxc etc. */
    nint = 100;
    par_1.ncomp = 3;
    dx = two / nint;
    par_1.r6d = one / (six * dx);
    i__1 = par_1.ncomp;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
/* Computing 2nd power */
	d__1 = dx;
	par_1.eodsq[i__ - 1] = eta[i__ - 1] / (d__1 * d__1);
    }
    par_1.nip = nint - 1;
    neq = par_1.ncomp * par_1.nip;
    par_1.nm1 = par_1.nip - 1;
    iwork[0] = par_1.ncomp;
    iwork[1] = par_1.nip;

    nerr = 0;

/* Set the initial conditions (for output purposes only). */
    setic_(&nint, &par_1.ncomp, y);

    io___22.ciunit = lout;
    s_wsfe(&io___22);
    e_wsfe();
    io___23.ciunit = lout;
    s_wsfe(&io___23);
    i__1 = par_1.ncomp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&eta[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    do_fio(&c__1, (char *)&tinit, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tlast, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&nint, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&par_1.ncomp, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&par_1.nip, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&neq, (ftnlen)sizeof(integer));
    e_wsfe();
    io___24.ciunit = lout;
    s_wsfe(&io___24);
    e_wsfe();
    edit_(y, &par_1.ncomp, &par_1.nip, &lout);

/* The jtol loop is over error tolerances. */
    for (jtol = 1; jtol <= 2; ++jtol) {
	rtol = tols[jtol - 1];
	atol = rtol;

/* The meth/miter loops cover 4 values of method flag mf. */
	for (meth = 1; meth <= 2; ++meth) {
	    for (miter = 1; miter <= 2; ++miter) {
		mf = meth * 10 + miter;

/* Set the initial conditions. */
		setic_(&nint, &par_1.ncomp, y);
		t = tinit;
		istate = 0;

		io___33.ciunit = lout;
		s_wsfe(&io___33);
		do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&mf, (ftnlen)sizeof(integer));
		e_wsfe();

/* Loop over output times for each case */
		i__1 = nout;
		for (io = 1; io <= i__1; ++io) {

		    dlsoibt_((U_fp)res_, (U_fp)addabt_, (U_fp)jacbt_, &neq, y,
			     ydoti, &t, &tout[io - 1], &itol, &rtol, &atol, &
			    c__1, &istate, &c__0, rwork, &lrw, iwork, &liw, &
			    mf);

		    io___37.ciunit = lout;
		    s_wsfe(&io___37);
		    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&rwork[10], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, (char *)&iwork[13], (ftnlen)sizeof(integer))
			    ;
		    do_fio(&c__1, (char *)&iwork[10], (ftnlen)sizeof(integer))
			    ;
		    e_wsfe();
		    if (io == nout) {
			edit_(y, &par_1.ncomp, &par_1.nip, &lout);
		    }

/* If istate is not 2 on return, print message and go to next case. */
		    if (istate != 2) {
			io___38.ciunit = lout;
			s_wsfe(&io___38);
			do_fio(&c__1, (char *)&mf, (ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
			do_fio(&c__1, (char *)&istate, (ftnlen)sizeof(integer)
				);
			e_wsfe();
			++nerr;
			goto L100;
		    }

/* L80: */
		}

/* Print final statistics. */
		io___39.ciunit = lout;
		s_wsfe(&io___39);
		do_fio(&c__1, (char *)&mf, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&iwork[10], (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&iwork[11], (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&iwork[12], (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&iwork[16], (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&iwork[17], (ftnlen)sizeof(integer));
		e_wsfe();

/* Estimate final error and print result. */
		maxerr_(y, &par_1.ncomp, &par_1.nip, &abermx);
		errfac = abermx / tols[jtol - 1];
		if (errfac < hun) {
		    io___42.ciunit = lout;
		    s_wsfe(&io___42);
		    do_fio(&c__1, (char *)&errfac, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
		} else {
		    io___43.ciunit = lout;
		    s_wsfe(&io___43);
		    do_fio(&c__1, (char *)&errfac, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
		    ++nerr;
		}
L100:
		;
	    }
	}
/* L200: */
    }

    io___44.ciunit = lout;
    s_wsfe(&io___44);
    do_fio(&c__1, (char *)&nerr, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);







/* end of main program for the DLSOIBT demonstration problem */
    return 0;
} /* MAIN__ */

/* Subroutine */ int setic_(integer *nint, integer *mb, doublereal *y)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal half = .5;
    static doublereal amp[3] = { .2,.3,.5 };

    /* System generated locals */
    integer y_dim1, y_offset, i__1, i__2;

    /* Local variables */
    static integer i__, k, n14, n34, nip;

/* This routine loads the y array with initial data based on a */
/* square wave profile for each of the mb PDE variables. */

    /* Parameter adjustments */
    y_dim1 = *mb;
    y_offset = 1 + y_dim1;
    y -= y_offset;

    /* Function Body */

    nip = *nint - 1;
    n14 = *nint / 4;
    n34 = n14 * 3;

    i__1 = n14 - 1;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    y[i__ + k * y_dim1] = zero;
	}
/* L15: */
    }

    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	y[i__ + n14 * y_dim1] = half * amp[i__ - 1];
    }

    i__1 = n34 - 1;
    for (k = n14 + 1; k <= i__1; ++k) {
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L30: */
	    y[i__ + k * y_dim1] = amp[i__ - 1];
	}
/* L35: */
    }

    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	y[i__ + n34 * y_dim1] = half * amp[i__ - 1];
    }

    i__1 = nip;
    for (k = n34 + 1; k <= i__1; ++k) {
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L50: */
	    y[i__ + k * y_dim1] = zero;
	}
/* L55: */
    }

    return 0;
/* end of subroutine setic */
} /* setic_ */

/* Subroutine */ int res_(integer *n, doublereal *t, doublereal *y, 
	doublereal *v, doublereal *r__, integer *ires)
{
    extern /* Subroutine */ int gfun_(doublereal *, doublereal *, doublereal *
	    , integer *), subav_(doublereal *, doublereal *, integer *);

/* This subroutine computes the residual vector */
/*   r = g(t,y) - A(t,y)*v */
/* using routines gfun and subav. */
/* If ires = -1, only g(t,y) is returned in r, since A(t,y) does */
/* not depend on y. */
/* No changes need to be made to this routine if nip is changed. */


    /* Parameter adjustments */
    --r__;
    --v;
    --y;

    /* Function Body */
    gfun_(t, &y[1], &r__[1], &par_1.ncomp);
    if (*ires == -1) {
	return 0;
    }

    subav_(&r__[1], &v[1], &par_1.ncomp);

    return 0;
/* end of subroutine res */
} /* res_ */

/* Subroutine */ int gfun_(doublereal *t, doublereal *y, doublereal *g, 
	integer *mb)
{
    /* Initialized data */

    static doublereal two = 2.;

    /* System generated locals */
    integer g_dim1, g_offset, y_dim1, y_offset, i__1, i__2;

    /* Local variables */
    static integer i__, k;
    static doublereal cc, cl, cr, dli, dri;

/* This subroutine computes the right-hand side function g(y,t). */
/* It uses r6d = 1/(6*dx), eodsq(*) = eta(*)/dx**2, nip, */
/* and nm1 = nip - 1 from the Common block par. */

    /* Parameter adjustments */
    g_dim1 = *mb;
    g_offset = 1 + g_dim1;
    g -= g_offset;
    y_dim1 = *mb;
    y_offset = 1 + y_dim1;
    y -= y_offset;

    /* Function Body */

/* left-most interior point (k = 1) */
    cc = y[(0 + (0 + (1 + 1 * y_dim1 << 3))) / 8] + y[(0 + (0 + (2 + 1 * 
	    y_dim1 << 3))) / 8] + y[(0 + (0 + (3 + 1 * y_dim1 << 3))) / 8];
    cr = y[(y_dim1 << 1) + 1] + y[(y_dim1 << 1) + 2] + y[(y_dim1 << 1) + 3];
    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dri = y[i__ + (y_dim1 << 1)] - y[i__ + y_dim1];
	g[i__ + g_dim1] = -par_1.r6d * (two * cc * y[i__ + (y_dim1 << 1)] + 
		cr * dri) + par_1.eodsq[i__ - 1] * (dri - y[i__ + y_dim1]);
/* L10: */
    }

/* interior points k = 2 to nip-1 */
    i__1 = par_1.nm1;
    for (k = 2; k <= i__1; ++k) {
	cl = y[(k - 1) * y_dim1 + 1] + y[(k - 1) * y_dim1 + 2] + y[(k - 1) * 
		y_dim1 + 3];
	cc = y[k * y_dim1 + 1] + y[k * y_dim1 + 2] + y[k * y_dim1 + 3];
	cr = y[(k + 1) * y_dim1 + 1] + y[(k + 1) * y_dim1 + 2] + y[(k + 1) * 
		y_dim1 + 3];
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    dli = y[i__ + k * y_dim1] - y[i__ + (k - 1) * y_dim1];
	    dri = y[i__ + (k + 1) * y_dim1] - y[i__ + k * y_dim1];
	    g[i__ + k * g_dim1] = -par_1.r6d * (cl * dli + two * cc * (dli + 
		    dri) + cr * dri) + par_1.eodsq[i__ - 1] * (dri - dli);
/* L15: */
	}
/* L20: */
    }

/* right-most interior point (k = nip) */
    cl = y[par_1.nm1 * y_dim1 + 1] + y[par_1.nm1 * y_dim1 + 2] + y[par_1.nm1 *
	     y_dim1 + 3];
    cc = y[par_1.nip * y_dim1 + 1] + y[par_1.nip * y_dim1 + 2] + y[par_1.nip *
	     y_dim1 + 3];
    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dli = y[i__ + par_1.nip * y_dim1] - y[i__ + par_1.nm1 * y_dim1];
	g[i__ + par_1.nip * g_dim1] = -par_1.r6d * (cl * dli - two * cc * y[
		i__ + par_1.nm1 * y_dim1]) - par_1.eodsq[i__ - 1] * (y[i__ + 
		par_1.nip * y_dim1] + dli);
/* L30: */
    }

    return 0;
/* end of subroutine gfun */
} /* gfun_ */

/* Subroutine */ int subav_(doublereal *r__, doublereal *v, integer *mb)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal four = 4.;
    static doublereal six = 6.;

    /* System generated locals */
    integer r_dim1, r_offset, v_dim1, v_offset, i__1, i__2;

    /* Local variables */
    static integer i__, k;
    static doublereal aa1, aa4;

/* This routine subtracts the matrix a time the vector v from r, */
/* in order to form the residual vector, stored in r. */

    /* Parameter adjustments */
    v_dim1 = *mb;
    v_offset = 1 + v_dim1;
    v -= v_offset;
    r_dim1 = *mb;
    r_offset = 1 + r_dim1;
    r__ -= r_offset;

    /* Function Body */

    aa1 = one / six;
    aa4 = four / six;

    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	r__[i__ + r_dim1] -= aa4 * v[i__ + v_dim1] + aa1 * v[i__ + (v_dim1 << 
		1)];
    }

    i__1 = par_1.nm1;
    for (k = 2; k <= i__1; ++k) {
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L15: */
	    r__[i__ + k * r_dim1] -= aa1 * v[i__ + (k - 1) * v_dim1] + aa4 * 
		    v[i__ + k * v_dim1] + aa1 * v[i__ + (k + 1) * v_dim1];
	}
/* L20: */
    }

    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	r__[i__ + par_1.nip * r_dim1] -= aa1 * v[i__ + par_1.nm1 * v_dim1] + 
		aa4 * v[i__ + par_1.nip * v_dim1];
    }

    return 0;
/* end of subroutine subav */
} /* subav_ */

/* Subroutine */ int addabt_(integer *n, doublereal *t, doublereal *y, 
	integer *mb, integer *nb, doublereal *pa, doublereal *pb, doublereal *
	pc)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal four = 4.;
    static doublereal six = 6.;

    /* System generated locals */
    integer y_dim1, y_offset, pa_dim1, pa_dim2, pa_offset, pb_dim1, pb_dim2, 
	    pb_offset, pc_dim1, pc_dim2, pc_offset, i__1, i__2;

    /* Local variables */
    static integer i__, k;
    static doublereal aa1, aa4;

/* This subroutine computes the elements of the matrix A, */
/* and adds them to pa, pb, and pc in the appropriate manner. */
/* The matrix A is tridiagonal, of order n, with */
/* nonzero elements (reading across) of 1/6, 4/6, 1/6. */

    /* Parameter adjustments */
    pc_dim1 = *mb;
    pc_dim2 = *mb;
    pc_offset = 1 + pc_dim1 * (1 + pc_dim2);
    pc -= pc_offset;
    pb_dim1 = *mb;
    pb_dim2 = *mb;
    pb_offset = 1 + pb_dim1 * (1 + pb_dim2);
    pb -= pb_offset;
    pa_dim1 = *mb;
    pa_dim2 = *mb;
    pa_offset = 1 + pa_dim1 * (1 + pa_dim2);
    pa -= pa_offset;
    y_dim1 = *mb;
    y_offset = 1 + y_dim1;
    y -= y_offset;

    /* Function Body */

    aa1 = one / six;
    aa4 = four / six;
    i__1 = *nb;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    pa[i__ + (i__ + k * pa_dim2) * pa_dim1] += aa4;
	}
	if (k != *nb) {
	    i__2 = *mb;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L20: */
		pb[i__ + (i__ + k * pb_dim2) * pb_dim1] += aa1;
	    }
	}
	if (k != 1) {
	    i__2 = *mb;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L30: */
		pc[i__ + (i__ + k * pc_dim2) * pc_dim1] += aa1;
	    }
	}
/* L50: */
    }

    return 0;
/* end of subroutine addabt */
} /* addabt_ */

/* Subroutine */ int jacbt_(integer *n, doublereal *t, doublereal *y, 
	doublereal *s, integer *mb, integer *nb, doublereal *pa, doublereal *
	pb, doublereal *pc)
{
    /* Initialized data */

    static doublereal two = 2.;

    /* System generated locals */
    integer y_dim1, y_offset, pa_dim1, pa_dim2, pa_offset, pb_dim1, pb_dim2, 
	    pb_offset, pc_dim1, pc_dim2, pc_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k;
    static doublereal cc, cl, cr, dlj, drj, paij, pbij, pcij, terma, termb, 
	    termc;

/* This subroutine computes the Jacobian dg/dy = d(g-A*s)/dy */
/* which has block-tridiagonal structure.  The main, upper, and */
/* lower diagonals are stored in pa, pb, and pc, respectively. */

    /* Parameter adjustments */
    --s;
    pc_dim1 = *mb;
    pc_dim2 = *mb;
    pc_offset = 1 + pc_dim1 * (1 + pc_dim2);
    pc -= pc_offset;
    pb_dim1 = *mb;
    pb_dim2 = *mb;
    pb_offset = 1 + pb_dim1 * (1 + pb_dim2);
    pb -= pb_offset;
    pa_dim1 = *mb;
    pa_dim2 = *mb;
    pa_offset = 1 + pa_dim1 * (1 + pa_dim2);
    pa -= pa_offset;
    y_dim1 = *mb;
    y_offset = 1 + y_dim1;
    y -= y_offset;

    /* Function Body */

/* left-most interior point (k = 1) */
    cc = y[(0 + (0 + (1 + 1 * y_dim1 << 3))) / 8] + y[(0 + (0 + (2 + 1 * 
	    y_dim1 << 3))) / 8] + y[(0 + (0 + (3 + 1 * y_dim1 << 3))) / 8];
    cr = y[(y_dim1 << 1) + 1] + y[(y_dim1 << 1) + 2] + y[(y_dim1 << 1) + 3];
    terma = par_1.r6d * cr;
    termb = -par_1.r6d * (two * cc + cr);
    i__1 = *mb;
    for (j = 1; j <= i__1; ++j) {
	drj = y[j + (y_dim1 << 1)] - y[j + y_dim1];
	paij = -par_1.r6d * two * y[j + (y_dim1 << 1)];
	pbij = -par_1.r6d * drj;
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    pa[i__ + (j + pa_dim2) * pa_dim1] = paij;
/* L10: */
	    pb[i__ + (j + pb_dim2) * pb_dim1] = pbij;
	}
	pa[j + (j + pa_dim2) * pa_dim1] = pa[j + (j + pa_dim2) * pa_dim1] + 
		terma - two * par_1.eodsq[j - 1];
	pb[j + (j + pb_dim2) * pb_dim1] = pb[j + (j + pb_dim2) * pb_dim1] + 
		termb + par_1.eodsq[j - 1];
/* L20: */
    }

/* interior points k = 2 to nip-1 */
    i__1 = par_1.nm1;
    for (k = 2; k <= i__1; ++k) {
	cl = y[(k - 1) * y_dim1 + 1] + y[(k - 1) * y_dim1 + 2] + y[(k - 1) * 
		y_dim1 + 3];
	cc = y[k * y_dim1 + 1] + y[k * y_dim1 + 2] + y[k * y_dim1 + 3];
	cr = y[(k + 1) * y_dim1 + 1] + y[(k + 1) * y_dim1 + 2] + y[(k + 1) * 
		y_dim1 + 3];
	terma = par_1.r6d * (cr - cl);
	termb = -par_1.r6d * (two * cc + cr);
	termc = par_1.r6d * (two * cc + cl);
	i__2 = *mb;
	for (j = 1; j <= i__2; ++j) {
	    dlj = y[j + k * y_dim1] - y[j + (k - 1) * y_dim1];
	    drj = y[j + (k + 1) * y_dim1] - y[j + k * y_dim1];
	    paij = -par_1.r6d * two * (dlj + drj);
	    pbij = -par_1.r6d * drj;
	    pcij = -par_1.r6d * dlj;
	    i__3 = *mb;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		pa[i__ + (j + k * pa_dim2) * pa_dim1] = paij;
		pb[i__ + (j + k * pb_dim2) * pb_dim1] = pbij;
/* L30: */
		pc[i__ + (j + k * pc_dim2) * pc_dim1] = pcij;
	    }
	    pa[j + (j + k * pa_dim2) * pa_dim1] = pa[j + (j + k * pa_dim2) * 
		    pa_dim1] + terma - two * par_1.eodsq[j - 1];
	    pb[j + (j + k * pb_dim2) * pb_dim1] = pb[j + (j + k * pb_dim2) * 
		    pb_dim1] + termb + par_1.eodsq[j - 1];
	    pc[j + (j + k * pc_dim2) * pc_dim1] = pc[j + (j + k * pc_dim2) * 
		    pc_dim1] + termc + par_1.eodsq[j - 1];
/* L40: */
	}
/* L50: */
    }

/* right-most interior point (k = nip) */
    cl = y[par_1.nm1 * y_dim1 + 1] + y[par_1.nm1 * y_dim1 + 2] + y[par_1.nm1 *
	     y_dim1 + 3];
    cc = y[par_1.nip * y_dim1 + 1] + y[par_1.nip * y_dim1 + 2] + y[par_1.nip *
	     y_dim1 + 3];
    terma = -par_1.r6d * cl;
    termc = par_1.r6d * (two * cc + cl);
    i__1 = *mb;
    for (j = 1; j <= i__1; ++j) {
	dlj = y[j + par_1.nip * y_dim1] - y[j + par_1.nm1 * y_dim1];
	paij = par_1.r6d * two * y[j + par_1.nm1 * y_dim1];
	pcij = -par_1.r6d * dlj;
	i__2 = *mb;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    pa[i__ + (j + par_1.nip * pa_dim2) * pa_dim1] = paij;
/* L60: */
	    pc[i__ + (j + par_1.nip * pc_dim2) * pc_dim1] = pcij;
	}
	pa[j + (j + par_1.nip * pa_dim2) * pa_dim1] = pa[j + (j + par_1.nip * 
		pa_dim2) * pa_dim1] + terma - two * par_1.eodsq[j - 1];
	pc[j + (j + par_1.nip * pc_dim2) * pc_dim1] = pc[j + (j + par_1.nip * 
		pc_dim2) * pc_dim1] + termc + par_1.eodsq[j - 1];
/* L70: */
    }

    return 0;
/* end of subroutine jacbt */
} /* jacbt_ */

/* Subroutine */ int edit_(doublereal *y, integer *mb, integer *nip, integer *
	lout)
{
    /* Format strings */
    static char fmt_20[] = "(\002 Values of PDE component i =\002,i3/15(7d12"
	    ".4/))";

    /* System generated locals */
    integer y_dim1, y_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, k;

    /* Fortran I/O blocks */
    static cilist io___91 = { 0, 0, 0, fmt_20, 0 };


/* This routine prints output.  For each of the mb PDE components, the */
/* values at the nip points are printed.  All output is on unit lout. */


    /* Parameter adjustments */
    y_dim1 = *mb;
    y_offset = 1 + y_dim1;
    y -= y_offset;

    /* Function Body */
    i__1 = *mb;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	io___91.ciunit = *lout;
	s_wsfe(&io___91);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	i__2 = *nip;
	for (k = 1; k <= i__2; ++k) {
	    do_fio(&c__1, (char *)&y[i__ + k * y_dim1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }


    return 0;
/* end of subroutine edit */
} /* edit_ */

/* Subroutine */ int maxerr_(doublereal *y, integer *mb, integer *nb, 
	doublereal *abermx)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static struct {
	doublereal e_1[99];
	} equiv_13 = { 7.17416019e-6, 1.70782645e-5, 3.31245126e-5, 
		6.01588363e-5, 1.05339286e-4, 1.79174771e-4, 2.96719122e-4, 
		4.78862606e-4, 7.53598916e-4, .0011570786, .00173420412, 
		.00253849668, .0036309911, .00507800919, .00694782549, 
		.00930645443, .0122130079, .0157152366, .0198459102, 
		.0246205841, .0300370492, .0360764461, .0427057301, 
		.049880982, .0575510102, .0656607602, .0741541974, 
		.0829764928, .0920754824, .101402468, .110912474, .120564094, 
		.130319039, .140141489, .149997326, .159853293, .169676126, 
		.17943168, .189084097, .198595037, .207923034, .217023055, 
		.225846345, .234340694, .24245124, .250121934, .257297724, 
		.263927433, .26996717, .275383917, .28015884, .284289739, 
		.287792167, .290698875, .293057586, .294927384, .296374262, 
		.297466488, .29827039, .298847025, .299249945, .29952408, 
		.299705593, .29982245, .299895431, .299939301, .299963931, 
		.299975129, .299974996, .299961526, .299927041, .299854809, 
		.299712769, .299442742, .298942676, .298038511, .296441259, 
		.293684573, .289040478, .281421884, .269315148, .250874185, 
		.22445768, .189885662, .149894358, .109927672, .0754041273, 
		.0490259517, .0306080023, .0185165524, .0109104125, 
		.0062772696, .0035300268, .00194049735, .00104218859, 
		5.45964314e-4, 2.77379128e-4, 1.33343739e-4, 5.32660444e-5 };

    static struct {
	doublereal e_1[99];
	} equiv_20 = { 1.86765383e-10, 1.96772458e-9, 1.19111389e-8, 
		5.54964761e-8, 2.18340713e-7, 7.55899524e-7, 2.35604385e-6, 
		6.70801745e-6, 1.76224112e-5, 4.30351929e-5, 9.82592148e-5, 
		2.10736217e-4, 4.26209304e-4, 8.15657041e-4, .00148160943, 
		.00256186555, .00422851247, .0066807897, .0101317466, 
		.0147903961, .0208424987, .0284336008, .0376573037, 
		.0485502549, .0610936693, .0752198901, .0908218891, .10776366,
		 .125889931, .145034247, .165025016, .185689556, .206856371, 
		.228356037, .250021072, .271685149, .293181998, .314344301, 
		.335002907, .354986687, .374123404, .392241969, .409176451, 
		.424772089, .43889332, .451433444, .462324969, .471549073, 
		.479142163, .485197409, .48985981, .493314543, .495770115, 
		.497439231, .498520996, .499187563, .499576941, .499791928, 
		.499903753, .499958343, .499983239, .499993785, .499997902, 
		.499999367, .499999835, .499999965, .499999995, .5, .5, 
		.499999997, .499999976, .499999863, .499999315, .499996914, 
		.4999873, .49995174, .499829328, .49943513, .498245007, 
		.4948834, .486081966, .465174923, .42185665, .347885738, 
		.249649938, .151648615, .0780173239, .0347983164, .0138686441,
		 .00505765688, .00171052539, 5.38966324e-4, 1.57923694e-4, 
		4.27352191e-5, 1.05512005e-5, 2.33068621e-6, 4.45404604e-7, 
		6.88336884e-8, 7.23875975e-9 };

    static struct {
	doublereal e_1[99];
	} equiv_6 = { .00170956682, .00343398445, .00518783349, .00698515842, 
		.00883921016, .0107622016, .0127650806, .0148573251, 
		.0170467655, .0193394396, .0217394852, .0242490773, 
		.0268684152, .029595766, .0324275691, .0353586054, 
		.0383822285, .041490652, .0446752791, .0479270545, 
		.0512368132, .0545956048, .0579949684, .061427146, 
		.0648852271, .0683632267, .0718561029, .0753597274, 
		.0788708192, .0823868545, .0859059616, .0894268082, 
		.0929484864, .0964703968, .0999921344, .103513375, .10703376, 
		.110552783, .114069668, .117583246, .121091827, .124593066, 
		.128083828, .131560049, .135016617, .138447256, .141844451, 
		.145199401, .148502033, .151741065, .154904135, .157977973, 
		.160948623, .16380167, .166522463, .169096305, .171508595, 
		.173744902, .175790974, .177632682, .179255895, .180646319, 
		.181789276, .18266947, .183270725, .183575716, .183565712, 
		.183220322, .182517279, .181432251, .179938706, .178007835, 
		.17560854, .172707519, .169269456, .165257378, .160633244, 
		.155358941, .149398029, .142718981, .135301474, .127148627, 
		.11830873, .108905085, .0991559295, .0893515884, .0797824293, 
		.0706663514, .0621244732, .0541994827, .0468848207, 
		.0401465202, .0339357642, .0281954415, .0228635569, 
		.0178750916, .0131630892, .00865933391, .00429480447 };


    /* System generated locals */
    integer y_dim1, y_offset;
    doublereal d__1;

    /* Local variables */
    static integer k;
#define u1 ((doublereal *)&equiv_6)
#define u2 ((doublereal *)&equiv_13)
#define u3 ((doublereal *)&equiv_20)
    static doublereal ae1, ae2, ae3;
#define u1a ((doublereal *)&equiv_6)
#define u1b ((doublereal *)&equiv_6 + 16)
#define u1c ((doublereal *)&equiv_6 + 32)
#define u1d ((doublereal *)&equiv_6 + 48)
#define u1e ((doublereal *)&equiv_6 + 64)
#define u1f ((doublereal *)&equiv_6 + 80)
#define u1g ((doublereal *)&equiv_6 + 96)
#define u2a ((doublereal *)&equiv_13)
#define u2b ((doublereal *)&equiv_13 + 16)
#define u2c ((doublereal *)&equiv_13 + 32)
#define u2d ((doublereal *)&equiv_13 + 48)
#define u2e ((doublereal *)&equiv_13 + 64)
#define u2f ((doublereal *)&equiv_13 + 80)
#define u2g ((doublereal *)&equiv_13 + 96)
#define u3a ((doublereal *)&equiv_20)
#define u3b ((doublereal *)&equiv_20 + 16)
#define u3c ((doublereal *)&equiv_20 + 32)
#define u3d ((doublereal *)&equiv_20 + 48)
#define u3e ((doublereal *)&equiv_20 + 64)
#define u3f ((doublereal *)&equiv_20 + 80)
#define u3g ((doublereal *)&equiv_20 + 96)

/* This routine computes the maximum absolute error in the y array, */
/* as a computed solution at t = 0.4, using data-loaded values for */
/* accurate answers (from running with much smaller tolerances). */


    /* Parameter adjustments */
    y_dim1 = *mb;
    y_offset = 1 + y_dim1;
    y -= y_offset;

    /* Function Body */

    *abermx = zero;
    for (k = 1; k <= 99; ++k) {
	ae1 = (d__1 = y[k * y_dim1 + 1] - u1[k - 1], abs(d__1));
	ae2 = (d__1 = y[k * y_dim1 + 2] - u2[k - 1], abs(d__1));
	ae3 = (d__1 = y[k * y_dim1 + 3] - u3[k - 1], abs(d__1));
/* Computing MAX */
	d__1 = max(*abermx,ae1), d__1 = max(d__1,ae2);
	*abermx = max(d__1,ae3);
/* L10: */
    }

    return 0;
/* end of subroutine maxerr */
} /* maxerr_ */

#undef u3g
#undef u3f
#undef u3e
#undef u3d
#undef u3c
#undef u3b
#undef u3a
#undef u2g
#undef u2f
#undef u2e
#undef u2d
#undef u2c
#undef u2b
#undef u2a
#undef u1g
#undef u1f
#undef u1e
#undef u1d
#undef u1c
#undef u1b
#undef u1a
#undef u3
#undef u2
#undef u1


