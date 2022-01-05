/* hybrd_test.f -- translated by f2c (version 20160102).
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
    integer nprob, nfev;
} refnum_;

#define refnum_1 refnum_

/* Table of constant values */

static integer c__1 = 1;

/*     ********** */

/*     THIS PROGRAM TESTS CODES FOR THE SOLUTION OF N NONLINEAR */
/*     EQUATIONS IN N VARIABLES. IT CONSISTS OF A DRIVER AND AN */
/*     INTERFACE SUBROUTINE FCN. THE DRIVER READS IN DATA, CALLS THE */
/*     NONLINEAR EQUATION SOLVER, AND FINALLY PRINTS OUT INFORMATION */
/*     ON THE PERFORMANCE OF THE SOLVER. THIS IS ONLY A SAMPLE DRIVER, */
/*     MANY OTHER DRIVERS ARE POSSIBLE. THE INTERFACE SUBROUTINE FCN */
/*     IS NECESSARY TO TAKE INTO ACCOUNT THE FORMS OF CALLING */
/*     SEQUENCES USED BY THE FUNCTION SUBROUTINES IN THE VARIOUS */
/*     NONLINEAR EQUATION SOLVERS. */

/*     SUBPROGRAMS CALLED */

/*       USER-SUPPLIED ...... FCN */

/*       MINPACK-SUPPLIED ... DPMPAR,ENORM,HYBRD1,INITPT,VECFCN */

/*       FORTRAN-SUPPLIED ... DSQRT */

/*     ARGONNE NATIONAL LABORATORY. MINPACK PROJECT. MARCH 1980. */
/*     BURTON S. GARBOW, KENNETH E. HILLSTROM, JORGE J. MORE */

/*     ********** */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static integer nread = 5;
    static integer nwrite = 6;
    static doublereal one = 1.;
    static doublereal ten = 10.;

    /* Format strings */
    static char fmt_50[] = "(3i5)";
    static char fmt_60[] = "(////5x,\002 PROBLEM\002,i5,5x,\002 DIMENSION"
	    "\002,i5,5x//)";
    static char fmt_70[] = "(5x,\002 INITIAL L2 NORM OF THE RESIDUALS\002,d1"
	    "5.7//5x,\002 FINAL L2 NORM OF THE RESIDUALS  \002,d15.7//5x,\002"
	    " NUMBER OF FUNCTION EVALUATIONS  \002,i10//5x,\002 EXIT PARAMETER"
	    "\002,18x,i10//5x,\002 FINAL APPROXIMATE SOLUTION\002//(5x,5d15.7"
	    "))";
    static char fmt_80[] = "(\0021SUMMARY OF \002,i3,\002 CALLS TO HYBRD1"
	    "\002/)";
    static char fmt_90[] = "(\002 NPROB   N    NFEV  INFO  FINAL L2 NORM\002"
	    "/)";
    static char fmt_100[] = "(i4,i6,i7,i6,1x,d15.7)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, k, n;
    static doublereal x[40];
    static integer ic, na[60], nf[60];
    static doublereal wa[2660];
    static integer np[60], nx[60];
    extern /* Subroutine */ int fcn_();
    static doublereal fnm[60];
    static integer lwa;
    static doublereal tol, fvec[40];
    static integer info;
    extern doublereal enorm_(integer *, doublereal *);
    extern /* Subroutine */ int hybrd1_(U_fp, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, integer *);
    static doublereal fnorm1, fnorm2;
    extern /* Subroutine */ int vecfcn_(integer *, doublereal *, doublereal *,
	     integer *);
    static doublereal factor;
    extern doublereal dpmpar_(integer *);
    static integer ntries;
    extern /* Subroutine */ int initpt_(integer *, doublereal *, integer *, 
	    doublereal *);

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 0, 0, fmt_50, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_60, 0 };
    static cilist io___25 = { 0, 0, 0, fmt_70, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_80, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_90, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_100, 0 };



/*     LOGICAL INPUT UNIT IS ASSUMED TO BE NUMBER 5. */
/*     LOGICAL OUTPUT UNIT IS ASSUMED TO BE NUMBER 6. */


    tol = sqrt(dpmpar_(&c__1));
    lwa = 2660;
    ic = 0;
L10:
    io___8.ciunit = nread;
    s_rsfe(&io___8);
    do_fio(&c__1, (char *)&refnum_1.nprob, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ntries, (ftnlen)sizeof(integer));
    e_rsfe();
    if (refnum_1.nprob <= 0) {
	goto L30;
    }
    factor = one;
    i__1 = ntries;
    for (k = 1; k <= i__1; ++k) {
	++ic;
	initpt_(&n, x, &refnum_1.nprob, &factor);
	vecfcn_(&n, x, fvec, &refnum_1.nprob);
	fnorm1 = enorm_(&n, fvec);
	io___16.ciunit = nwrite;
	s_wsfe(&io___16);
	do_fio(&c__1, (char *)&refnum_1.nprob, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
	e_wsfe();
	refnum_1.nfev = 0;
	hybrd1_((U_fp)fcn_, &n, x, fvec, &tol, &info, wa, &lwa);
	fnorm2 = enorm_(&n, fvec);
	np[ic - 1] = refnum_1.nprob;
	na[ic - 1] = n;
	nf[ic - 1] = refnum_1.nfev;
	nx[ic - 1] = info;
	fnm[ic - 1] = fnorm2;
	io___25.ciunit = nwrite;
	s_wsfe(&io___25);
	do_fio(&c__1, (char *)&fnorm1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fnorm2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&refnum_1.nfev, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&info, (ftnlen)sizeof(integer));
	i__2 = n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&x[i__ - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	factor = ten * factor;
/* L20: */
    }
    goto L10;
L30:
    io___27.ciunit = nwrite;
    s_wsfe(&io___27);
    do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
    e_wsfe();
    io___28.ciunit = nwrite;
    s_wsfe(&io___28);
    e_wsfe();
    i__1 = ic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	io___29.ciunit = nwrite;
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&np[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&na[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nf[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nx[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&fnm[i__ - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L40: */
    }
    s_stop("", (ftnlen)0);

/*     LAST CARD OF DRIVER. */

    return 0;
} /* MAIN__ */

/* Subroutine */ int fcn_(integer *n, doublereal *x, doublereal *fvec, 
	integer *iflag)
{
    extern /* Subroutine */ int vecfcn_(integer *, doublereal *, doublereal *,
	     integer *);

/*     ********** */

/*     THE CALLING SEQUENCE OF FCN SHOULD BE IDENTICAL TO THE */
/*     CALLING SEQUENCE OF THE FUNCTION SUBROUTINE IN THE NONLINEAR */
/*     EQUATION SOLVER. FCN SHOULD ONLY CALL THE TESTING FUNCTION */
/*     SUBROUTINE VECFCN WITH THE APPROPRIATE VALUE OF PROBLEM */
/*     NUMBER (NPROB). */

/*     SUBPROGRAMS CALLED */

/*       MINPACK-SUPPLIED ... VECFCN */

/*     ARGONNE NATIONAL LABORATORY. MINPACK PROJECT. MARCH 1980. */
/*     BURTON S. GARBOW, KENNETH E. HILLSTROM, JORGE J. MORE */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;

    /* Function Body */
    vecfcn_(n, &x[1], &fvec[1], &refnum_1.nprob);
    ++refnum_1.nfev;
    return 0;

/*     LAST CARD OF INTERFACE SUBROUTINE FCN. */

} /* fcn_ */

/* Subroutine */ int vecfcn_(integer *n, doublereal *x, doublereal *fvec, 
	integer *nprob)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal three = 3.;
    static doublereal five = 5.;
    static doublereal eight = 8.;
    static doublereal ten = 10.;
    static doublereal c1 = 1e4;
    static doublereal c2 = 1.0001;
    static doublereal c3 = 200.;
    static doublereal c4 = 20.2;
    static doublereal c5 = 19.8;
    static doublereal c6 = 180.;
    static doublereal c7 = .25;
    static doublereal c8 = .5;
    static doublereal c9 = 29.;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), exp(doublereal), atan(doublereal), d_sign(
	    doublereal *, doublereal *), cos(doublereal), sin(doublereal);

    /* Local variables */
    static doublereal h__;
    static integer i__, j, k, k1, k2, ml;
    static doublereal ti, tj, tk;
    static integer mu, kp1, iev;
    static doublereal tpi, sum, sum1, sum2, prod, temp, temp1, temp2;

/*     ********** */

/*     SUBROUTINE VECFCN */

/*     THIS SUBROUTINE DEFINES FOURTEEN TEST FUNCTIONS. THE FIRST */
/*     FIVE TEST FUNCTIONS ARE OF DIMENSIONS 2,4,2,4,3, RESPECTIVELY, */
/*     WHILE THE REMAINING TEST FUNCTIONS ARE OF VARIABLE DIMENSION */
/*     N FOR ANY N GREATER THAN OR EQUAL TO 1 (PROBLEM 6 IS AN */
/*     EXCEPTION TO THIS, SINCE IT DOES NOT ALLOW N = 1). */

/*     THE SUBROUTINE STATEMENT IS */

/*       SUBROUTINE VECFCN(N,X,FVEC,NPROB) */

/*     WHERE */

/*       N IS A POSITIVE INTEGER INPUT VARIABLE. */

/*       X IS AN INPUT ARRAY OF LENGTH N. */

/*       FVEC IS AN OUTPUT ARRAY OF LENGTH N WHICH CONTAINS THE NPROB */
/*         FUNCTION VECTOR EVALUATED AT X. */

/*       NPROB IS A POSITIVE INTEGER INPUT VARIABLE WHICH DEFINES THE */
/*         NUMBER OF THE PROBLEM. NPROB MUST NOT EXCEED 14. */

/*     SUBPROGRAMS CALLED */

/*       FORTRAN-SUPPLIED ... DATAN,DCOS,DEXP,DSIGN,DSIN,DSQRT, */
/*                            MAX0,MIN0 */

/*     ARGONNE NATIONAL LABORATORY. MINPACK PROJECT. MARCH 1980. */
/*     BURTON S. GARBOW, KENNETH E. HILLSTROM, JORGE J. MORE */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;

    /* Function Body */

/*     PROBLEM SELECTOR. */

    switch (*nprob) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L120;
	case 8:  goto L170;
	case 9:  goto L200;
	case 10:  goto L220;
	case 11:  goto L270;
	case 12:  goto L300;
	case 13:  goto L330;
	case 14:  goto L350;
    }

/*     ROSENBROCK FUNCTION. */

L10:
    fvec[1] = one - x[1];
/* Computing 2nd power */
    d__1 = x[1];
    fvec[2] = ten * (x[2] - d__1 * d__1);
    goto L380;

/*     POWELL SINGULAR FUNCTION. */

L20:
    fvec[1] = x[1] + ten * x[2];
    fvec[2] = sqrt(five) * (x[3] - x[4]);
/* Computing 2nd power */
    d__1 = x[2] - two * x[3];
    fvec[3] = d__1 * d__1;
/* Computing 2nd power */
    d__1 = x[1] - x[4];
    fvec[4] = sqrt(ten) * (d__1 * d__1);
    goto L380;

/*     POWELL BADLY SCALED FUNCTION. */

L30:
    fvec[1] = c1 * x[1] * x[2] - one;
    fvec[2] = exp(-x[1]) + exp(-x[2]) - c2;
    goto L380;

/*     WOOD FUNCTION. */

L40:
/* Computing 2nd power */
    d__1 = x[1];
    temp1 = x[2] - d__1 * d__1;
/* Computing 2nd power */
    d__1 = x[3];
    temp2 = x[4] - d__1 * d__1;
    fvec[1] = -c3 * x[1] * temp1 - (one - x[1]);
    fvec[2] = c3 * temp1 + c4 * (x[2] - one) + c5 * (x[4] - one);
    fvec[3] = -c6 * x[3] * temp2 - (one - x[3]);
    fvec[4] = c6 * temp2 + c4 * (x[4] - one) + c5 * (x[2] - one);
    goto L380;

/*     HELICAL VALLEY FUNCTION. */

L50:
    tpi = eight * atan(one);
    temp1 = d_sign(&c7, &x[2]);
    if (x[1] > zero) {
	temp1 = atan(x[2] / x[1]) / tpi;
    }
    if (x[1] < zero) {
	temp1 = atan(x[2] / x[1]) / tpi + c8;
    }
/* Computing 2nd power */
    d__1 = x[1];
/* Computing 2nd power */
    d__2 = x[2];
    temp2 = sqrt(d__1 * d__1 + d__2 * d__2);
    fvec[1] = ten * (x[3] - ten * temp1);
    fvec[2] = ten * (temp2 - one);
    fvec[3] = x[3];
    goto L380;

/*     WATSON FUNCTION. */

L60:
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fvec[k] = zero;
/* L70: */
    }
    for (i__ = 1; i__ <= 29; ++i__) {
	ti = (doublereal) i__ / c9;
	sum1 = zero;
	temp = one;
	i__1 = *n;
	for (j = 2; j <= i__1; ++j) {
	    i__2 = j - 1;
	    sum1 += (doublereal) i__2 * temp * x[j];
	    temp = ti * temp;
/* L80: */
	}
	sum2 = zero;
	temp = one;
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    sum2 += temp * x[j];
	    temp = ti * temp;
/* L90: */
	}
/* Computing 2nd power */
	d__1 = sum2;
	temp1 = sum1 - d__1 * d__1 - one;
	temp2 = two * ti * sum2;
	temp = one / ti;
	i__1 = *n;
	for (k = 1; k <= i__1; ++k) {
	    i__2 = k - 1;
	    fvec[k] += temp * ((doublereal) i__2 - temp2) * temp1;
	    temp = ti * temp;
/* L100: */
	}
/* L110: */
    }
/* Computing 2nd power */
    d__1 = x[1];
    temp = x[2] - d__1 * d__1 - one;
    fvec[1] += x[1] * (one - two * temp);
    fvec[2] += temp;
    goto L380;

/*     CHEBYQUAD FUNCTION. */

L120:
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fvec[k] = zero;
/* L130: */
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	temp1 = one;
	temp2 = two * x[j] - one;
	temp = two * temp2;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    fvec[i__] += temp2;
	    ti = temp * temp2 - temp1;
	    temp1 = temp2;
	    temp2 = ti;
/* L140: */
	}
/* L150: */
    }
    tk = one / (doublereal) (*n);
    iev = -1;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fvec[k] = tk * fvec[k];
	if (iev > 0) {
/* Computing 2nd power */
	    d__1 = (doublereal) k;
	    fvec[k] += one / (d__1 * d__1 - one);
	}
	iev = -iev;
/* L160: */
    }
    goto L380;

/*     BROWN ALMOST-LINEAR FUNCTION. */

L170:
    i__1 = *n + 1;
    sum = -((doublereal) i__1);
    prod = one;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	sum += x[j];
	prod = x[j] * prod;
/* L180: */
    }
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fvec[k] = x[k] + sum;
/* L190: */
    }
    fvec[*n] = prod - one;
    goto L380;

/*     DISCRETE BOUNDARY VALUE FUNCTION. */

L200:
    i__1 = *n + 1;
    h__ = one / (doublereal) i__1;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
/* Computing 3rd power */
	d__1 = x[k] + (doublereal) k * h__ + one;
	temp = d__1 * (d__1 * d__1);
	temp1 = zero;
	if (k != 1) {
	    temp1 = x[k - 1];
	}
	temp2 = zero;
	if (k != *n) {
	    temp2 = x[k + 1];
	}
/* Computing 2nd power */
	d__1 = h__;
	fvec[k] = two * x[k] - temp1 - temp2 + temp * (d__1 * d__1) / two;
/* L210: */
    }
    goto L380;

/*     DISCRETE INTEGRAL EQUATION FUNCTION. */

L220:
    i__1 = *n + 1;
    h__ = one / (doublereal) i__1;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	tk = (doublereal) k * h__;
	sum1 = zero;
	i__2 = k;
	for (j = 1; j <= i__2; ++j) {
	    tj = (doublereal) j * h__;
/* Computing 3rd power */
	    d__1 = x[j] + tj + one;
	    temp = d__1 * (d__1 * d__1);
	    sum1 += tj * temp;
/* L230: */
	}
	sum2 = zero;
	kp1 = k + 1;
	if (*n < kp1) {
	    goto L250;
	}
	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    tj = (doublereal) j * h__;
/* Computing 3rd power */
	    d__1 = x[j] + tj + one;
	    temp = d__1 * (d__1 * d__1);
	    sum2 += (one - tj) * temp;
/* L240: */
	}
L250:
	fvec[k] = x[k] + h__ * ((one - tk) * sum1 + tk * sum2) / two;
/* L260: */
    }
    goto L380;

/*     TRIGONOMETRIC FUNCTION. */

L270:
    sum = zero;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	fvec[j] = cos(x[j]);
	sum += fvec[j];
/* L280: */
    }
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *n + k;
	fvec[k] = (doublereal) i__2 - sin(x[k]) - sum - (doublereal) k * fvec[
		k];
/* L290: */
    }
    goto L380;

/*     VARIABLY DIMENSIONED FUNCTION. */

L300:
    sum = zero;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	sum += (doublereal) j * (x[j] - one);
/* L310: */
    }
/* Computing 2nd power */
    d__1 = sum;
    temp = sum * (one + two * (d__1 * d__1));
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fvec[k] = x[k] - one + (doublereal) k * temp;
/* L320: */
    }
    goto L380;

/*     BROYDEN TRIDIAGONAL FUNCTION. */

L330:
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	temp = (three - two * x[k]) * x[k];
	temp1 = zero;
	if (k != 1) {
	    temp1 = x[k - 1];
	}
	temp2 = zero;
	if (k != *n) {
	    temp2 = x[k + 1];
	}
	fvec[k] = temp - temp1 - two * temp2 + one;
/* L340: */
    }
    goto L380;

/*     BROYDEN BANDED FUNCTION. */

L350:
    ml = 5;
    mu = 1;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
/* Computing MAX */
	i__2 = 1, i__3 = k - ml;
	k1 = max(i__2,i__3);
/* Computing MIN */
	i__2 = k + mu;
	k2 = min(i__2,*n);
	temp = zero;
	i__2 = k2;
	for (j = k1; j <= i__2; ++j) {
	    if (j != k) {
		temp += x[j] * (one + x[j]);
	    }
/* L360: */
	}
/* Computing 2nd power */
	d__1 = x[k];
	fvec[k] = x[k] * (two + five * (d__1 * d__1)) + one - temp;
/* L370: */
    }
L380:
    return 0;

/*     LAST CARD OF SUBROUTINE VECFCN. */

} /* vecfcn_ */

/* Subroutine */ int initpt_(integer *n, doublereal *x, integer *nprob, 
	doublereal *factor)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal half = .5;
    static doublereal one = 1.;
    static doublereal three = 3.;
    static doublereal c1 = 1.2;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal h__;
    static integer j;
    static doublereal tj;

/*     ********** */

/*     SUBROUTINE INITPT */

/*     THIS SUBROUTINE SPECIFIES THE STANDARD STARTING POINTS FOR */
/*     THE FUNCTIONS DEFINED BY SUBROUTINE VECFCN. THE SUBROUTINE */
/*     RETURNS IN X A MULTIPLE (FACTOR) OF THE STANDARD STARTING */
/*     POINT. FOR THE SIXTH FUNCTION THE STANDARD STARTING POINT IS */
/*     ZERO, SO IN THIS CASE, IF FACTOR IS NOT UNITY, THEN THE */
/*     SUBROUTINE RETURNS THE VECTOR  X(J) = FACTOR, J=1,...,N. */

/*     THE SUBROUTINE STATEMENT IS */

/*       SUBROUTINE INITPT(N,X,NPROB,FACTOR) */

/*     WHERE */

/*       N IS A POSITIVE INTEGER INPUT VARIABLE. */

/*       X IS AN OUTPUT ARRAY OF LENGTH N WHICH CONTAINS THE STANDARD */
/*         STARTING POINT FOR PROBLEM NPROB MULTIPLIED BY FACTOR. */

/*       NPROB IS A POSITIVE INTEGER INPUT VARIABLE WHICH DEFINES THE */
/*         NUMBER OF THE PROBLEM. NPROB MUST NOT EXCEED 14. */

/*       FACTOR IS AN INPUT VARIABLE WHICH SPECIFIES THE MULTIPLE OF */
/*         THE STANDARD STARTING POINT. IF FACTOR IS UNITY, NO */
/*         MULTIPLICATION IS PERFORMED. */

/*     ARGONNE NATIONAL LABORATORY. MINPACK PROJECT. MARCH 1980. */
/*     BURTON S. GARBOW, KENNETH E. HILLSTROM, JORGE J. MORE */

/*     ********** */
    /* Parameter adjustments */
    --x;

    /* Function Body */

/*     SELECTION OF INITIAL POINT. */

    switch (*nprob) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L80;
	case 8:  goto L100;
	case 9:  goto L120;
	case 10:  goto L120;
	case 11:  goto L140;
	case 12:  goto L160;
	case 13:  goto L180;
	case 14:  goto L180;
    }

/*     ROSENBROCK FUNCTION. */

L10:
    x[1] = -c1;
    x[2] = one;
    goto L200;

/*     POWELL SINGULAR FUNCTION. */

L20:
    x[1] = three;
    x[2] = -one;
    x[3] = zero;
    x[4] = one;
    goto L200;

/*     POWELL BADLY SCALED FUNCTION. */

L30:
    x[1] = zero;
    x[2] = one;
    goto L200;

/*     WOOD FUNCTION. */

L40:
    x[1] = -three;
    x[2] = -one;
    x[3] = -three;
    x[4] = -one;
    goto L200;

/*     HELICAL VALLEY FUNCTION. */

L50:
    x[1] = -one;
    x[2] = zero;
    x[3] = zero;
    goto L200;

/*     WATSON FUNCTION. */

L60:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = zero;
/* L70: */
    }
    goto L200;

/*     CHEBYQUAD FUNCTION. */

L80:
    i__1 = *n + 1;
    h__ = one / (doublereal) i__1;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = (doublereal) j * h__;
/* L90: */
    }
    goto L200;

/*     BROWN ALMOST-LINEAR FUNCTION. */

L100:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = half;
/* L110: */
    }
    goto L200;

/*     DISCRETE BOUNDARY VALUE AND INTEGRAL EQUATION FUNCTIONS. */

L120:
    i__1 = *n + 1;
    h__ = one / (doublereal) i__1;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	tj = (doublereal) j * h__;
	x[j] = tj * (tj - one);
/* L130: */
    }
    goto L200;

/*     TRIGONOMETRIC FUNCTION. */

L140:
    h__ = one / (doublereal) (*n);
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = h__;
/* L150: */
    }
    goto L200;

/*     VARIABLY DIMENSIONED FUNCTION. */

L160:
    h__ = one / (doublereal) (*n);
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = one - (doublereal) j * h__;
/* L170: */
    }
    goto L200;

/*     BROYDEN TRIDIAGONAL AND BANDED FUNCTIONS. */

L180:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = -one;
/* L190: */
    }
L200:

/*     COMPUTE MULTIPLE OF INITIAL POINT. */

    if (*factor == one) {
	goto L250;
    }
    if (*nprob == 6) {
	goto L220;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = *factor * x[j];
/* L210: */
    }
    goto L240;
L220:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = *factor;
/* L230: */
    }
L240:
L250:
    return 0;

/*     LAST CARD OF SUBROUTINE INITPT. */

} /* initpt_ */

