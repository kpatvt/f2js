/* demo2.f -- translated by f2c (version 20160102).
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
/* Demonstration program for the DLSODES package. */
/* This is the version of 14 June 2001. */

/* This version is in double precision. */

/* The package is used for each of the relevant values of mf to solve */
/* the problem ydot = A * y, where A is the 9 by 9 sparse matrix */

/*               -4  1     1 */
/*                1 -4  1     1 */
/*                   1 -4        1 */
/*                        -4  1     1 */
/*       A =               1 -4  1     1 */
/*                            1 -4        1 */
/*                                 -4  1 */
/*                                  1 -4  1 */
/*                                     1 -4 */

/* The initial conditions are  y(0) = (1, 2, 3, ..., 9). */
/* Output is printed at t = 1, 2, and 3. */
/* Each case is solved first with nominal (large) values of lrw and liw, */
/* and then with values given by lenrw and leniw (optional outputs) */
/* on the first run, as a check on these computed work array lengths. */
/* If the errors are too large, or other difficulty occurs, */
/* a warning message is printed. */
/* All output is on unit lout, which is data-loaded to 6 below. */
/* ----------------------------------------------------------------------- */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static integer lout = 6;

    /* Format strings */
    static char fmt_10[] = "(/\002Demonstration problem for the DLSODES pack"
	    "age\002//)";
    static char fmt_80[] = "(\002 neq =\002,i4,5x,\002t0 =\002,f4.1,5x,\002r"
	    "tol =\002,d12.3,5x,\002atol =\002,d12.3//\002 Initial y vector ="
	    "  \002,9f5.1)";
    static char fmt_100[] = "(//80(\002*\002))";
    static char fmt_120[] = "(//\002Run with mf =\002,i4,\002.\002,5x,\002In"
	    "put work lengths lrw, liw =\002,2i6/)";
    static char fmt_140[] = "(\002At t =\002,f5.1,3x,\002nst =\002,i4,3x,"
	    "\002hu =\002,d12.3,3x,\002nqu =\002,i3,3x,\002 max. err. =\002,d"
	    "11.3/\002  y array =    \002,4d15.6/5d15.6)";
    static char fmt_150[] = "(//\002 Warning: error exceeds 100 * toleranc"
	    "e\002//)";
    static char fmt_180[] = "(/\002Final statistics for this run:\002/\002 r"
	    "work size =\002,i4,\002   iwork size =\002,i4/\002 number of ste"
	    "ps =\002,i5/\002 number of f-s   =\002,i5/\002 (excluding J-s) "
	    "=\002,i5/\002 number of J-s   =\002,i5/\002 error overrun =\002,"
	    "d10.2)";
    static char fmt_185[] = "(\002 number of nonzeros in J = \002,i5/\002 nu"
	    "mber of J index groups =\002,i5/\002 number of LU decomp-s    "
	    "=\002,i5/\002 nonzeros in strict lower factor =\002,i5/\002 nonz"
	    "eros in strict upper factor =\002,i5)";
    static char fmt_200[] = "(//\002Number of errors encountered =\002,i3)";

    /* System generated locals */
    integer i__1, i__2;
    static integer equiv_1[90];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal t, y[9];
#define ia (equiv_1 + 30)
#define ja (equiv_1 + 40)
    static integer mf;
    static doublereal hu;
    static integer nfe, nje, neq, ngp;
    static doublereal erm, ero;
    static integer liw, nlu, nqu, lrw, nnz, nst, nzl, nzu, nfea;
    extern /* Subroutine */ int fdem_(), jdem_();
    extern /* Subroutine */ int edit_(doublereal *, integer *, doublereal *);
    static integer meth;
    static doublereal atol;
    static integer nerr, itol, iopt, irun, iout, moss;
    static doublereal rtol;
    static integer nout;
    static doublereal tout;
    static integer igrid, itask, leniw, miter, lenrw;
#define iwork (equiv_1)
    static doublereal rwork[1000];
    extern /* Subroutine */ int ssout_(integer *neq, integer *iwk, integer *iwork, 
	integer *lout);
    static integer istate;
    extern /* Subroutine */ int dlsodes_(U_fp, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *, integer *, integer *, doublereal *, integer *, 
	    integer *, integer *, U_fp, integer *);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_80, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_140, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_150, 0 };
    static cilist io___53 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_185, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_200, 0 };



/* Write heading and set fixed parameters. */
    io___5.ciunit = lout;
    s_wsfe(&io___5);
    e_wsfe();
    nerr = 0;
    igrid = 3;
/* Computing 2nd power */
    i__1 = igrid;
    neq = i__1 * i__1;
    t = 0.;
    itol = 1;
    rtol = 0.;
    atol = 1e-5;
    itask = 1;
    iopt = 0;
    i__1 = neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	y[i__ - 1] = (doublereal) i__;
    }
    ia[0] = 1;
    k = 1;
    i__1 = igrid;
    for (m = 1; m <= i__1; ++m) {
	i__2 = igrid;
	for (l = 1; l <= i__2; ++l) {
	    j = l + (m - 1) * igrid;
	    if (m > 1) {
		ja[k - 1] = j - igrid;
		++k;
	    }
/* L30: */
	    if (l > 1) {
		ja[k - 1] = j - 1;
		++k;
	    }
/* L35: */
	    ja[k - 1] = j;
	    ++k;
	    if (l < igrid) {
		ja[k - 1] = j + 1;
		++k;
	    }
/* L40: */
	    ia[j] = k;
/* L50: */
	}
/* L60: */
    }
    io___21.ciunit = lout;
    s_wsfe(&io___21);
    do_fio(&c__1, (char *)&neq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rtol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
    i__1 = neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

/* Loop over all relevant values of mf. */
    for (moss = 0; moss <= 2; ++moss) {
	for (meth = 1; meth <= 2; ++meth) {
	    for (miter = 0; miter <= 3; ++miter) {
		if ((miter == 0 || miter == 3) && moss != 0) {
		    goto L191;
		}
		mf = moss * 100 + meth * 10 + miter;
		io___26.ciunit = lout;
		s_wsfe(&io___26);
		e_wsfe();
/* First run: nominal work array lengths, 3 output points. */
		irun = 1;
		lrw = 1000;
		liw = 90;
		nout = 3;
L110:
		io___31.ciunit = lout;
		s_wsfe(&io___31);
		do_fio(&c__1, (char *)&mf, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&lrw, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&liw, (ftnlen)sizeof(integer));
		e_wsfe();
		i__1 = neq;
		for (i__ = 1; i__ <= i__1; ++i__) {
/* L125: */
		    y[i__ - 1] = (doublereal) i__;
		}
		t = 0.;
		tout = 1.;
		istate = 1;
		ero = 0.;
/* Loop over output points.  Do output and accuracy check at each. */
		i__1 = nout;
		for (iout = 1; iout <= i__1; ++iout) {
		    dlsodes_((U_fp)fdem_, &neq, y, &t, &tout, &itol, &rtol, &
			    atol, &itask, &istate, &iopt, rwork, &lrw, iwork, 
			    &liw, (U_fp)jdem_, &mf);
		    nst = iwork[10];
		    hu = rwork[10];
		    nqu = iwork[13];
		    edit_(y, &iout, &erm);
		    io___41.ciunit = lout;
		    s_wsfe(&io___41);
		    do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&hu, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&nqu, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&erm, (ftnlen)sizeof(doublereal));
		    i__2 = neq;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			do_fio(&c__1, (char *)&y[i__ - 1], (ftnlen)sizeof(
				doublereal));
		    }
		    e_wsfe();
		    if (istate < 0) {
			goto L175;
		    }
		    erm /= atol;
		    ero = max(ero,erm);
		    if (erm > 100.) {
			io___42.ciunit = lout;
			s_wsfe(&io___42);
			e_wsfe();
			++nerr;
		    }
		    tout += 1.;
/* L170: */
		}
L175:
		if (istate < 0) {
		    ++nerr;
		}
		if (irun == 2) {
		    goto L191;
		}
/* Print final statistics (first run only) */
		nst = iwork[10];
		nfe = iwork[11];
		nje = iwork[12];
		lenrw = iwork[16];
		leniw = iwork[17];
		nnz = iwork[18];
		ngp = iwork[19];
		nlu = iwork[20];
		nzl = iwork[24];
		nzu = iwork[25];
		nfea = nfe;
		if (miter == 2) {
		    nfea = nfe - ngp * nje;
		}
		if (miter == 3) {
		    nfea = nfe - nje;
		}
		io___53.ciunit = lout;
		s_wsfe(&io___53);
		do_fio(&c__1, (char *)&lenrw, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&leniw, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&nst, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&nfe, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&nfea, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&nje, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&ero, (ftnlen)sizeof(doublereal));
		e_wsfe();
		if (miter == 1 || miter == 2) {
		    io___54.ciunit = lout;
		    s_wsfe(&io___54);
		    do_fio(&c__1, (char *)&nnz, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&ngp, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&nlu, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&nzl, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&nzu, (ftnlen)sizeof(integer));
		    e_wsfe();
		}
		if (istate < 0) {
		    goto L191;
		}
		if (miter == 1 || miter == 2) {
		    ssout_(&neq, &rwork[20], iwork, &lout);
		}
/* Return for second run: minimal work array lengths, 1 output point. */
		++irun;
		lrw = lenrw;
		liw = leniw;
		nout = 1;
		goto L110;
L191:
		;
	    }
/* L192: */
	}
/* L193: */
    }

    io___55.ciunit = lout;
    s_wsfe(&io___55);
    e_wsfe();
    io___56.ciunit = lout;
    s_wsfe(&io___56);
    do_fio(&c__1, (char *)&nerr, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

#undef iwork
#undef ja
#undef ia


/* Subroutine */ int fdem_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *ydot)
{
    /* Initialized data */

    static integer igrid = 3;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, l, m;

    /* Parameter adjustments */
    --ydot;
    --y;

    /* Function Body */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L5: */
	ydot[i__] = 0.;
    }
    i__1 = igrid;
    for (m = 1; m <= i__1; ++m) {
	i__2 = igrid;
	for (l = 1; l <= i__2; ++l) {
	    j = l + (m - 1) * igrid;
	    if (m != 1) {
		ydot[j - igrid] += y[j];
	    }
	    if (l != 1) {
		ydot[j - 1] += y[j];
	    }
	    ydot[j] -= y[j] * 4.;
	    if (l != igrid) {
		ydot[j + 1] += y[j];
	    }
/* L10: */
	}
/* L20: */
    }
    return 0;
} /* fdem_ */

/* Subroutine */ int jdem_(integer *neq, doublereal *t, doublereal *y, 
	integer *j, integer *ia, integer *ja, doublereal *pdj)
{
    /* Initialized data */

    static integer igrid = 3;

    static integer l, m;

    /* Parameter adjustments */
    --pdj;
    --y;
    --ia;
    --ja;

    /* Function Body */
    m = (*j - 1) / igrid + 1;
    l = *j - (m - 1) * igrid;
    pdj[*j] = -4.;
    if (m != 1) {
	pdj[*j - igrid] = 1.;
    }
    if (l != 1) {
	pdj[*j - 1] = 1.;
    }
    if (l != igrid) {
	pdj[*j + 1] = 1.;
    }
    return 0;
} /* jdem_ */

/* Subroutine */ int edit_(doublereal *y, integer *iout, doublereal *erm)
{
    /* Initialized data */

    static integer neq = 9;
    static doublereal yex[27]	/* was [9][3] */ = { .6687279,.990191,
	    .7603061,.8077979,1.170226,.8810605,.5013331,.7201389,.5379644,
	    .1340488,.1917157,.1374034,.1007882,.1437868,.102801,.03844343,
	    .05477593,.03911435,.01929166,.02735444,.01939611,.01055981,
	    .01496753,.01060897,.002913689,.004128975,.002925977 };

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal er;

    /* Parameter adjustments */
    --y;

    /* Function Body */
    *erm = 0.;
    i__1 = neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	er = (d__1 = y[i__] - yex[i__ + *iout * 9 - 10], abs(d__1));
/* L10: */
	*erm = max(*erm,er);
    }
    return 0;
} /* edit_ */

/* Subroutine */ int ssout_(integer *neq, integer *iwk, integer *iwork, 
	integer *lout)
{
    /* Format strings */
    static char fmt_10[] = "(/\002 structure descriptor array ian =\002/(20i"
	    "4))";
    static char fmt_20[] = "(/\002 structure descriptor array jan =\002/(20i"
	    "4))";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, i1, i2, nnz, ipian, ipjan;

    /* Fortran I/O blocks */
    static cilist io___74 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___76 = { 0, 0, 0, fmt_20, 0 };


    /* Parameter adjustments */
    --iwork;
    --iwk;

    /* Function Body */
    ipian = iwork[23];
    ipjan = iwork[24];
    nnz = iwork[19];
    i1 = ipian;
    i2 = i1 + *neq;
    io___74.ciunit = *lout;
    s_wsfe(&io___74);
    i__1 = i2;
    for (i__ = i1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&iwk[i__], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    i1 = ipjan;
    i2 = i1 + nnz - 1;
    io___76.ciunit = *lout;
    s_wsfe(&io___76);
    i__1 = i2;
    for (i__ = i1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&iwk[i__], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    return 0;
} /* ssout_ */

