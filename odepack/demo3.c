/* demo3.f -- translated by f2c (version 20160102).
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

/* Table of constant values */

static integer c__1 = 1;

/* ----------------------------------------------------------------------- */
/* Demonstration program for the DLSODA package. */
/* This is the version of 14 June 2001. */

/* This version is in double precision. */

/* The package is used to solve two simple problems, */
/* one with a full Jacobian, the other with a banded Jacobian, */
/* with the 2 appropriate values of jt in each case. */
/* If the errors are too large, or other difficulty occurs, */
/* a warning message is printed.  All output is on unit lout = 6. */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static integer lout = 6;
    static doublereal tout1 = 16.921743;
    static doublereal dtout = 17.341162;

    /* Format strings */
    static char fmt_110[] = "(/\002Demonstration program for DLSODA packag"
	    "e\002////\002 Problem 1:   Van der Pol oscillator:\002/\002     "
	    "         xdotdot - 20*(1 - x**2)*xdot + x = 0, \002,\002   x(0) "
	    "= 2, xdot(0) = 0\002/\002 neq =\002,i2/\002 itol =\002,i3,\002  "
	    " rtol =\002,d10.1,\002   atol =\002,d10.1//)";
    static char fmt_120[] = "(//\002 Solution with jt =\002,i3//\002  t     "
	    "          x               xdot       meth\002,\002   nq     h   "
	    "        tsw\002//)";
    static char fmt_140[] = "(d12.5,d16.5,d14.3,2i6,2d13.3)";
    static char fmt_150[] = "(//\002 Warning: value at root exceeds 1.0d-"
	    "2\002//)";
    static char fmt_180[] = "(//\002 Final statistics for this run:\002/\002"
	    " rwork size =\002,i4,\002   iwork size =\002,i4/\002 number of s"
	    "teps =\002,i5/\002 number of f-s   =\002,i5/\002 (excluding J-s)"
	    " =\002,i5/\002 number of J-s   =\002,i5/\002 max. error at root ="
	    "\002,d10.2)";
    static char fmt_210[] = "(///80(\002-\002)///\002 Problem 2: ydot = A * "
	    "y , where\002,\002  A is a banded lower triangular matrix\002"
	    "/\002            derived from 2-D advection PDE\002/\002 neq "
	    "=\002,i3,\002   ml =\002,i2,\002   mu =\002,i2/\002 itol =\002,i"
	    "3,\002   rtol =\002,d10.1,\002   atol =\002,d10.1//)";
    static char fmt_220[] = "(//\002 Solution with jt =\002,i3//\002     t  "
	    "           max.err.     meth   \002,\002nq      h            ts"
	    "w\002//)";
    static char fmt_240[] = "(d15.5,d14.3,2i6,2d14.3)";
    static char fmt_280[] = "(//\002 Final statistics for this run:\002/\002"
	    " rwork size =\002,i4,\002   iwork size =\002,i4/\002 number of s"
	    "teps =\002,i5/\002 number of f-s   =\002,i5/\002 (excluding J-s)"
	    " =\002,i5/\002 number of J-s   =\002,i5/\002 error overrun =\002"
	    ",d10.2)";
    static char fmt_300[] = "(///\002 Number of errors encountered =\002,i3)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal t, y[25];
    extern /* Subroutine */ int f1_(), f2_();
    static doublereal er;
    static integer ml;
    static doublereal hu;
    static integer jt, mu, nfe, nje, neq;
    static doublereal erm, ero;
    static integer liw, nqu, lrw, nst;
    static doublereal tsw;
    extern /* Subroutine */ int jac1_(), jac2_();
    static integer nfea;
    static doublereal atol;
    static integer nerr, itol, iopt, iout;
    static doublereal rtol;
    static integer nout;
    static doublereal tout;
    extern /* Subroutine */ int edit2_(doublereal *, doublereal *, doublereal 
	    *);
    static integer mband, iopar, itask, mused, leniw, lenrw, iwork[45];
    static doublereal rwork[522], dtout0, dtout1;
    extern /* Subroutine */ int dlsoda_(U_fp, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *, integer *, integer *, doublereal *, integer *, 
	    integer *, integer *, U_fp, integer *);
    static integer istate;

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___45 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_220, 0 };
    static cilist io___49 = { 0, 0, 0, fmt_240, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___51 = { 0, 0, 0, fmt_280, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_300, 0 };



    nerr = 0;
    itol = 1;
    rtol = 0.;
    atol = 1e-8;
    lrw = 522;
    liw = 45;
    iopt = 0;

/* First problem */

    neq = 2;
    nout = 4;
    io___13.ciunit = lout;
    s_wsfe(&io___13);
    do_fio(&c__1, (char *)&neq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itol, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
    e_wsfe();

    for (jt = 1; jt <= 2; ++jt) {
	io___15.ciunit = lout;
	s_wsfe(&io___15);
	do_fio(&c__1, (char *)&jt, (ftnlen)sizeof(integer));
	e_wsfe();
	t = 0.;
	y[0] = 2.;
	y[1] = 0.;
	itask = 1;
	istate = 1;
	dtout0 = tout1 * .5;
	dtout1 = dtout * .5;
	tout = dtout0;
	ero = 0.;
	i__1 = nout;
	for (iout = 1; iout <= i__1; ++iout) {
	    dlsoda_((U_fp)f1_, &neq, y, &t, &tout, &itol, &rtol, &atol, &
		    itask, &istate, &iopt, rwork, &lrw, iwork, &liw, (U_fp)
		    jac1_, &jt);
	    hu = rwork[10];
	    tsw = rwork[14];
	    nqu = iwork[13];
	    mused = iwork[18];
	    io___31.ciunit = lout;
	    s_wsfe(&io___31);
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[0], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&mused, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nqu, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&hu, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tsw, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (istate < 0) {
		goto L175;
	    }
	    iopar = iout - (iout / 2 << 1);
	    if (iopar != 0) {
		goto L160;
	    }
	    er = abs(y[0]);
	    ero = max(ero,er);
	    if (er > .01) {
		io___34.ciunit = lout;
		s_wsfe(&io___34);
		e_wsfe();
		++nerr;
	    }
L160:
	    if (iout == 1) {
		tout += dtout0;
	    }
	    if (iout > 1) {
		tout += dtout1;
	    }
/* L170: */
	}
L175:
	if (istate < 0) {
	    ++nerr;
	}
	nst = iwork[10];
	nfe = iwork[11];
	nje = iwork[12];
	lenrw = iwork[16];
	leniw = iwork[17];
	nfea = nfe;
	if (jt == 2) {
	    nfea = nfe - neq * nje;
	}
	io___41.ciunit = lout;
	s_wsfe(&io___41);
	do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfea, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nje, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ero, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L190: */
    }

/* Second problem */

    neq = 25;
    ml = 5;
    mu = 0;
    iwork[0] = ml;
    iwork[1] = mu;
    mband = ml + mu + 1;
    atol = 1e-6;
    nout = 5;
    io___45.ciunit = lout;
    s_wsfe(&io___45);
    do_fio(&c__1, (char *)&neq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ml, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&mu, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itol, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
    e_wsfe();
    for (jt = 4; jt <= 5; ++jt) {
	io___46.ciunit = lout;
	s_wsfe(&io___46);
	do_fio(&c__1, (char *)&jt, (ftnlen)sizeof(integer));
	e_wsfe();
	t = 0.;
	i__1 = neq;
	for (i__ = 2; i__ <= i__1; ++i__) {
/* L230: */
	    y[i__ - 1] = 0.;
	}
	y[0] = 1.;
	itask = 1;
	istate = 1;
	tout = .01;
	ero = 0.;
	i__1 = nout;
	for (iout = 1; iout <= i__1; ++iout) {
	    dlsoda_((U_fp)f2_, &neq, y, &t, &tout, &itol, &rtol, &atol, &
		    itask, &istate, &iopt, rwork, &lrw, iwork, &liw, (U_fp)
		    jac2_, &jt);
	    edit2_(y, &t, &erm);
	    hu = rwork[10];
	    tsw = rwork[14];
	    nqu = iwork[13];
	    mused = iwork[18];
	    io___49.ciunit = lout;
	    s_wsfe(&io___49);
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&erm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&mused, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nqu, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&hu, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tsw, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (istate < 0) {
		goto L275;
	    }
	    er = erm / atol;
	    ero = max(ero,er);
	    if (er > 1e3) {
		io___50.ciunit = lout;
		s_wsfe(&io___50);
		e_wsfe();
		++nerr;
	    }
/* L270: */
	    tout *= 10.;
	}
L275:
	if (istate < 0) {
	    ++nerr;
	}
	nst = iwork[10];
	nfe = iwork[11];
	nje = iwork[12];
	lenrw = iwork[16];
	leniw = iwork[17];
	nfea = nfe;
	if (jt == 5) {
	    nfea = nfe - mband * nje;
	}
	io___51.ciunit = lout;
	s_wsfe(&io___51);
	do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfea, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nje, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ero, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L290: */
    }
    io___52.ciunit = lout;
    s_wsfe(&io___52);
    do_fio(&c__1, (char *)&nerr, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Subroutine */ int f1_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *ydot)
{
    /* Parameter adjustments */
    --ydot;
    --y;

    /* Function Body */
    ydot[1] = y[2];
    ydot[2] = (1. - y[1] * y[1]) * 20. * y[2] - y[1];
    return 0;
} /* f1_ */

/* Subroutine */ int jac1_(integer *neq, doublereal *t, doublereal *y, 
	integer *ml, integer *mu, doublereal *pd, integer *nrowpd)
{
    /* System generated locals */
    integer pd_dim1, pd_offset;

    /* Parameter adjustments */
    --y;
    pd_dim1 = *nrowpd;
    pd_offset = 1 + pd_dim1;
    pd -= pd_offset;

    /* Function Body */
    pd[pd_dim1 + 1] = 0.;
    pd[(pd_dim1 << 1) + 1] = 1.;
    pd[pd_dim1 + 2] = y[1] * -40. * y[2] - 1.;
    pd[(pd_dim1 << 1) + 2] = (1. - y[1] * y[1]) * 20.;
    return 0;
} /* jac1_ */

/* Subroutine */ int f2_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *ydot)
{
    /* Initialized data */

    static doublereal alph1 = 1.;
    static doublereal alph2 = 1.;
    static integer ng = 5;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal d__;
    static integer i__, j, k;

    /* Parameter adjustments */
    --ydot;
    --y;

    /* Function Body */
    i__1 = ng;
    for (j = 1; j <= i__1; ++j) {
	i__2 = ng;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    k = i__ + (j - 1) * ng;
	    d__ = y[k] * -2.;
	    if (i__ != 1) {
		d__ += y[k - 1] * alph1;
	    }
	    if (j != 1) {
		d__ += y[k - ng] * alph2;
	    }
/* L10: */
	    ydot[k] = d__;
	}
    }
    return 0;
} /* f2_ */

/* Subroutine */ int jac2_(integer *neq, doublereal *t, doublereal *y, 
	integer *ml, integer *mu, doublereal *pd, integer *nrowpd)
{
    /* Initialized data */

    static doublereal alph1 = 1.;
    static doublereal alph2 = 1.;
    static integer ng = 5;

    /* System generated locals */
    integer pd_dim1, pd_offset, i__1, i__2;

    /* Local variables */
    static integer j, mu1, mu2, mband;

    /* Parameter adjustments */
    --y;
    pd_dim1 = *nrowpd;
    pd_offset = 1 + pd_dim1;
    pd -= pd_offset;

    /* Function Body */
    mband = *ml + *mu + 1;
    mu1 = *mu + 1;
    mu2 = *mu + 2;
    i__1 = *neq;
    for (j = 1; j <= i__1; ++j) {
	pd[mu1 + j * pd_dim1] = -2.;
	pd[mu2 + j * pd_dim1] = alph1;
/* L10: */
	pd[mband + j * pd_dim1] = alph2;
    }
    i__1 = *neq;
    i__2 = ng;
    for (j = ng; i__2 < 0 ? j >= i__1 : j <= i__1; j += i__2) {
/* L20: */
	pd[mu2 + j * pd_dim1] = 0.;
    }
    return 0;
} /* jac2_ */

/* Subroutine */ int edit2_(doublereal *y, doublereal *t, doublereal *erm)
{
    /* Initialized data */

    static doublereal alph1 = 1.;
    static doublereal alph2 = 1.;
    static integer ng = 5;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double exp(doublereal), pow_di(doublereal *, integer *);

    /* Local variables */
    static integer i__, j, k;
    static doublereal a1, a2, er, ex, yt;

    /* Parameter adjustments */
    --y;

    /* Function Body */
    *erm = 0.;
    if (*t == 0.) {
	return 0;
    }
    ex = 0.;
    if (*t <= 30.) {
	ex = exp(*t * -2.);
    }
    a2 = 1.;
    i__1 = ng;
    for (j = 1; j <= i__1; ++j) {
	a1 = 1.;
	i__2 = ng;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    k = i__ + (j - 1) * ng;
	    i__3 = i__ + j - 2;
	    yt = pow_di(t, &i__3) * ex * a1 * a2;
	    er = (d__1 = y[k] - yt, abs(d__1));
	    *erm = max(*erm,er);
	    a1 = a1 * alph1 / i__;
/* L50: */
	}
	a2 = a2 * alph2 / j;
/* L60: */
    }
    return 0;
} /* edit2_ */

