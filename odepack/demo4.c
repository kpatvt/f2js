/* demo4.f -- translated by f2c (version 20160102).
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
/* Demonstration program for the DLSODAR package. */
/* This is the version of 14 June 2001. */

/* This version is in double precision. */

/* The DLSODAR package is used to solve two simple problems, */
/* one nonstiff and one intermittently stiff. */
/* If the errors are too large, or other difficulty occurs, */
/* a warning message is printed.  All output is on unit lout = 6. */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static integer lout = 6;

    /* Format strings */
    static char fmt_110[] = "(/\002 Demonstration program for DLSODAR pack"
	    "age\002////\002 First problem\002///\002 Problem is  dy/dt = ((2"
	    "*log(y)+8)/t - 5)*y,  y(1) = 1\002//\002 Solution is  y(t) = exp"
	    "(-t**2 + 5*t - 4)\002//\002 Root functions are:\002/10x,\002 g1 "
	    "= dy/dt  (root at t = 2.5)\002/10x,\002 g2 = log(y) - 2.2491  (r"
	    "oots at t = 2.47 and t = 2.53)\002//\002 itol =\002,i3,\002   rt"
	    "ol =\002,d10.1,\002   atol =\002,d10.1//\002 jt =\002,i3///)";
    static char fmt_130[] = "(\002 At t =\002,d15.7,5x,\002y =\002,d15.7,5x"
	    ",\002error =\002,d12.4)";
    static char fmt_140[] = "(//\002 Warning: error exceeds 1000 * toleranc"
	    "e\002//)";
    static char fmt_150[] = "(/\002 Root found at t =\002,d15.7,5x,\002jroot"
	    " =\002,2i5)";
    static char fmt_160[] = "(\002 Error in t location of root is\002,d12.4/)"
	    ;
    static char fmt_170[] = "(//\002 Warning: root error exceeds 1.0d-3\002/"
	    "/)";
    static char fmt_190[] = "(//\002 Final statistics for this run:\002/\002"
	    " rwork size =\002,i4,\002   iwork size =\002,i4/\002 number of s"
	    "teps =\002,i5/\002 number of f-s   =\002,i5/\002 (excluding j-s)"
	    " =\002,i5/\002 number of j-s   =\002,i5/\002 number of g-s   "
	    "=\002,i5/\002 error overrun =\002,d10.2)";
    static char fmt_200[] = "(////80(\002*\002)//\002 Second problem (Van de"
	    "r Pol oscillator)\002//\002 Problem is dy1/dt = y2,  dy2/dt = 10"
	    "0*(1-y1**2)*y2 - y1\002/\002            y1(0) = 2,  y2(0) = 0"
	    "\002//\002 Root function is  g = y1\002//\002 itol =\002,i3,\002"
	    "   rtol =\002,d10.1,\002   atol =\002,2d10.1)";
    static char fmt_210[] = "(///\002 Solution with jt =\002,i2//)";
    static char fmt_230[] = "(\002 At t =\002,d15.7,5x,\002y1 =\002,d15.7,"
	    "5x,\002y2 =\002,d15.7)";
    static char fmt_240[] = "(/\002 Root found at t =\002,d15.7)";
    static char fmt_250[] = "(\002 Error in t location of root is\002,d12.4/"
	    "/)";
    static char fmt_260[] = "(//\002 Warning: root error exceeds 1.0d-1\002/"
	    "/)";
    static char fmt_280[] = "(//\002 Final statistics for this run:\002/\002"
	    "  rwork size =\002,i4,\002   iwork size =\002,i4/\002  number of"
	    " steps =\002,i5/\002  number of f-s   =\002,i5/\002  (excluding "
	    "j-s) =\002,i5/\002  number of j-s   =\002,i5/\002  number of g-s"
	    "   =\002,i5)";
    static char fmt_300[] = "(///\002 Total number of errors encountered "
	    "=\002,i3)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double exp(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal t, y[2];
    extern /* Subroutine */ int f1_(), f2_();
    static integer ng;
    static doublereal er;
    static integer jt;
    static doublereal yt;
    extern /* Subroutine */ int gr1_(), gr2_();
    static integer nfe, nge, nje, neq;
    static doublereal ero;
    static integer liw, lrw, nst;
    extern /* Subroutine */ int jac2_();
    static integer nfea;
    static doublereal atol[2];
    static integer jdum, nerr, itol, iopt;
    static doublereal errt;
    static integer iout;
    static doublereal rtol, tout;
    static integer itask, leniw, lenrw, iwork[22], jroot[2], kroot;
    static doublereal tzero, rwork[57];
    static integer istate;
    extern /* Subroutine */ int dlsodar_();

    /* Fortran I/O blocks */
    static cilist io___17 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_160, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_170, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_190, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_230, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_240, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_250, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_260, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_280, 0 };
    static cilist io___49 = { 0, 0, 0, fmt_300, 0 };



    nerr = 0;
/* ----------------------------------------------------------------------- */
/* First problem. */
/* The initial value problem is: */
/*   dy/dt = ((2*log(y) + 8)/t - 5)*y,  y(1) = 1,  1 .le. t .le. 6 */
/* The solution is  y(t) = exp(-t**2 + 5*t - 4) */
/* The two root functions are: */
/*   g1 = ((2*log(y)+8)/t - 5)*y (= dy/dt)  (with root at t = 2.5), */
/*   g2 = log(y) - 2.2491  (with roots at t = 2.47 and 2.53) */
/* ----------------------------------------------------------------------- */
/* Set all input parameters and print heading. */
    neq = 1;
    y[0] = 1.;
    t = 1.;
    tout = 2.;
    itol = 1;
    rtol = 1e-6;
    atol[0] = 1e-6;
    itask = 1;
    istate = 1;
    iopt = 0;
    lrw = 44;
    liw = 21;
    jt = 2;
    ng = 2;
    io___17.ciunit = lout;
    s_wsfe(&io___17);
    do_fio(&c__1, (char *)&itol, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jt, (ftnlen)sizeof(integer));
    e_wsfe();

/* Call DLSODAR in loop over tout values 2,3,4,5,6. */
    ero = 0.;
    for (iout = 1; iout <= 5; ++iout) {
L120:
	dlsodar_((U_fp)f1_, &neq, y, &t, &tout, &itol, &rtol, atol, &itask, &
		istate, &iopt, rwork, &lrw, iwork, &liw, &jdum, &jt, (U_fp)
		gr1_, &ng, jroot);

/* Print y and error in y, and print warning if error too large. */
	yt = exp(-t * t + t * 5. - 4.);
	er = y[0] - yt;
	io___26.ciunit = lout;
	s_wsfe(&io___26);
	do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&er, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (istate < 0) {
	    goto L185;
	}
	er = abs(er) / (rtol * abs(y[0]) + atol[0]);
	ero = max(ero,er);
	if (er > 1e3) {
	    io___27.ciunit = lout;
	    s_wsfe(&io___27);
	    e_wsfe();
	    ++nerr;
	}
	if (istate != 3) {
	    goto L175;
	}

/* If a root was found, write results and check root location. */
/* Then reset istate to 2 and return to DLSODAR call. */
	io___28.ciunit = lout;
	s_wsfe(&io___28);
	do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&jroot[0], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jroot[1], (ftnlen)sizeof(integer));
	e_wsfe();
	if (jroot[0] == 1) {
	    errt = t - 2.5;
	}
	if (jroot[1] == 1 && t <= 2.5) {
	    errt = t - 2.47;
	}
	if (jroot[1] == 1 && t > 2.5) {
	    errt = t - 2.53;
	}
	io___30.ciunit = lout;
	s_wsfe(&io___30);
	do_fio(&c__1, (char *)&errt, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (abs(errt) > .001) {
	    io___31.ciunit = lout;
	    s_wsfe(&io___31);
	    e_wsfe();
	    ++nerr;
	}
	istate = 2;
	goto L120;

/* If no root found, increment tout and loop back. */
L175:
	tout += 1.;
/* L180: */
    }

/* Problem complete.  Print final statistics. */
L185:
    if (istate < 0) {
	++nerr;
    }
    nst = iwork[10];
    nfe = iwork[11];
    nje = iwork[12];
    nge = iwork[9];
    lenrw = iwork[16];
    leniw = iwork[17];
    nfea = nfe;
    if (jt == 2) {
	nfea = nfe - neq * nje;
    }
    io___39.ciunit = lout;
    s_wsfe(&io___39);
    do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nfea, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nje, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nge, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ero, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* ----------------------------------------------------------------------- */
/* Second problem (Van der Pol oscillator). */
/* The initial value problem is (after reduction of 2nd order ODE): */
/*   dy1/dt = y2,  dy2/dt = 100*(1 - y1**2)*y2 - y1, */
/*   y1(0) = 2,  y2(0) = 0,  0 .le. t .le. 200 */
/* The root function is  g = y1. */
/* An analytic solution is not known, but the zeros of y1 are known */
/* to 15 figures for purposes of checking the accuracy. */
/* ----------------------------------------------------------------------- */
/* Set tolerance parameters and print heading. */
    itol = 2;
    rtol = 1e-6;
    atol[0] = 1e-6;
    atol[1] = 1e-4;
    io___40.ciunit = lout;
    s_wsfe(&io___40);
    do_fio(&c__1, (char *)&itol, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol[1], (ftnlen)sizeof(doublereal));
    e_wsfe();

/* Loop over jt = 1, 2.  Set remaining parameters and print jt. */
    for (jt = 1; jt <= 2; ++jt) {
	neq = 2;
	y[0] = 2.;
	y[1] = 0.;
	t = 0.;
	tout = 20.;
	itask = 1;
	istate = 1;
	iopt = 0;
	lrw = 57;
	liw = 22;
	ng = 1;
	io___41.ciunit = lout;
	s_wsfe(&io___41);
	do_fio(&c__1, (char *)&jt, (ftnlen)sizeof(integer));
	e_wsfe();

/* Call DLSODAR in loop over tout values 20,40,...,200. */
	for (iout = 1; iout <= 10; ++iout) {
L220:
	    dlsodar_((U_fp)f2_, &neq, y, &t, &tout, &itol, &rtol, atol, &
		    itask, &istate, &iopt, rwork, &lrw, iwork, &liw, (U_fp)
		    jac2_, &jt, (U_fp)gr2_, &ng, jroot);

/* Print y1 and y2. */
	    io___42.ciunit = lout;
	    s_wsfe(&io___42);
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[0], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (istate < 0) {
		goto L275;
	    }
	    if (istate != 3) {
		goto L265;
	    }

/* If a root was found, write results and check root location. */
/* Then reset istate to 2 and return to DLSODAR call. */
	    io___43.ciunit = lout;
	    s_wsfe(&io___43);
	    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    kroot = (integer) (t / 81.2 + .5);
	    tzero = (kroot - 1) * 81.41853556212 + 81.17237787055;
	    errt = t - tzero;
	    io___46.ciunit = lout;
	    s_wsfe(&io___46);
	    do_fio(&c__1, (char *)&errt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (abs(errt) > .1) {
		io___47.ciunit = lout;
		s_wsfe(&io___47);
		e_wsfe();
		++nerr;
	    }
	    istate = 2;
	    goto L220;

/* If no root found, increment tout and loop back. */
L265:
	    tout += 20.;
/* L270: */
	}

/* Problem complete.  Print final statistics. */
L275:
	if (istate < 0) {
	    ++nerr;
	}
	nst = iwork[10];
	nfe = iwork[11];
	nje = iwork[12];
	nge = iwork[9];
	lenrw = iwork[16];
	leniw = iwork[17];
	nfea = nfe;
	if (jt == 2) {
	    nfea = nfe - neq * nje;
	}
	io___48.ciunit = lout;
	s_wsfe(&io___48);
	do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nfea, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nje, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nge, (ftnlen)sizeof(integer));
	e_wsfe();
/* L290: */
    }

    io___49.ciunit = lout;
    s_wsfe(&io___49);
    do_fio(&c__1, (char *)&nerr, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Subroutine */ int f1_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *ydot)
{
    /* Builtin functions */
    double log(doublereal);

    /* Parameter adjustments */
    --ydot;
    --y;

    /* Function Body */
    ydot[1] = ((log(y[1]) * 2. + 8.) / *t - 5.) * y[1];
    return 0;
} /* f1_ */

/* Subroutine */ int gr1_(integer *neq, doublereal *t, doublereal *y, integer 
	*ng, doublereal *groot)
{
    /* Builtin functions */
    double log(doublereal);

    /* Parameter adjustments */
    --groot;
    --y;

    /* Function Body */
    groot[1] = ((log(y[1]) * 2. + 8.) / *t - 5.) * y[1];
    groot[2] = log(y[1]) - 2.2491;
    return 0;
} /* gr1_ */

/* Subroutine */ int f2_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *ydot)
{
    /* Parameter adjustments */
    --ydot;
    --y;

    /* Function Body */
    ydot[1] = y[2];
    ydot[2] = (1. - y[1] * y[1]) * 100. * y[2] - y[1];
    return 0;
} /* f2_ */

/* Subroutine */ int jac2_(integer *neq, doublereal *t, doublereal *y, 
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
    pd[pd_dim1 + 2] = y[1] * -200. * y[2] - 1.;
    pd[(pd_dim1 << 1) + 2] = (1. - y[1] * y[1]) * 100.;
    return 0;
} /* jac2_ */

/* Subroutine */ int gr2_(integer *neq, doublereal *t, doublereal *y, integer 
	*ng, doublereal *groot)
{
    /* Parameter adjustments */
    --groot;
    --y;

    /* Function Body */
    groot[1] = y[1];
    return 0;
} /* gr2_ */

