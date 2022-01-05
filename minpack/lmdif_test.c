/* lmdif_test.f -- translated by f2c (version 20160102).
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
    integer nprob, nfev, njev;
} refnum_;

#define refnum_1 refnum_

/* Table of constant values */

static integer c__1 = 1;

/*     ********** */

/*     THIS PROGRAM TESTS CODES FOR THE LEAST-SQUARES SOLUTION OF */
/*     M NONLINEAR EQUATIONS IN N VARIABLES. IT CONSISTS OF A DRIVER */
/*     AND AN INTERFACE SUBROUTINE FCN. THE DRIVER READS IN DATA, */
/*     CALLS THE NONLINEAR LEAST-SQUARES SOLVER, AND FINALLY PRINTS */
/*     OUT INFORMATION ON THE PERFORMANCE OF THE SOLVER. THIS IS */
/*     ONLY A SAMPLE DRIVER, MANY OTHER DRIVERS ARE POSSIBLE. THE */
/*     INTERFACE SUBROUTINE FCN IS NECESSARY TO TAKE INTO ACCOUNT THE */
/*     FORMS OF CALLING SEQUENCES USED BY THE FUNCTION AND JACOBIAN */
/*     SUBROUTINES IN THE VARIOUS NONLINEAR LEAST-SQUARES SOLVERS. */

/*     SUBPROGRAMS CALLED */

/*       USER-SUPPLIED ...... FCN */

/*       MINPACK-SUPPLIED ... DPMPAR,ENORM,INITPT,LMDIF1,SSQFCN */

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
    static char fmt_50[] = "(4i5)";
    static char fmt_60[] = "(////5x,\002 PROBLEM\002,i5,5x,\002 DIMENSION"
	    "S\002,2i5,5x//)";
    static char fmt_70[] = "(5x,\002 INITIAL L2 NORM OF THE RESIDUALS\002,d1"
	    "5.7//5x,\002 FINAL L2 NORM OF THE RESIDUALS  \002,d15.7//5x,\002"
	    " NUMBER OF FUNCTION EVALUATIONS  \002,i10//5x,\002 NUMBER OF JAC"
	    "OBIAN EVALUATIONS  \002,i10//5x,\002 EXIT PARAMETER\002,18x,i10/"
	    "/5x,\002 FINAL APPROXIMATE SOLUTION\002//(5x,5d15.7))";
    static char fmt_80[] = "(\0021SUMMARY OF \002,i3,\002 CALLS TO LMDIF1"
	    "\002/)";
    static char fmt_90[] = "(\002 NPROB   N    M   NFEV  NJEV  INFO  FINAL L"
	    "2 NORM\002/)";
    static char fmt_100[] = "(3i5,3i6,1x,d15.7)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, k, m, n;
    static doublereal x[40];
    static integer ic, ma[60], na[60], nf[60], nj[60];
    static doublereal wa[2865];
    static integer np[60], nx[60];
    extern /* Subroutine */ int fcn_();
    static integer iwa[40];
    static doublereal fnm[60];
    static integer lwa;
    static doublereal tol, fvec[65];
    static integer info;
    extern doublereal enorm_(integer *, doublereal *);
    extern /* Subroutine */ int lmdif1_(U_fp, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, integer *);
    static doublereal fnorm1, fnorm2, factor;
    extern doublereal dpmpar_(integer *);
    extern /* Subroutine */ int ssqfcn_(integer *, integer *, doublereal *, 
	    doublereal *, integer *);
    static integer ntries;
    extern /* Subroutine */ int initpt_(integer *, doublereal *, integer *, 
	    doublereal *);

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 0, 0, fmt_50, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_60, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_70, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_80, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_90, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_100, 0 };



/*     LOGICAL INPUT UNIT IS ASSUMED TO BE NUMBER 5. */
/*     LOGICAL OUTPUT UNIT IS ASSUMED TO BE NUMBER 6. */


    tol = sqrt(dpmpar_(&c__1));
    lwa = 2865;
    ic = 0;
L10:
    io___8.ciunit = nread;
    s_rsfe(&io___8);
    do_fio(&c__1, (char *)&refnum_1.nprob, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&m, (ftnlen)sizeof(integer));
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
	ssqfcn_(&m, &n, x, fvec, &refnum_1.nprob);
	fnorm1 = enorm_(&m, fvec);
	io___17.ciunit = nwrite;
	s_wsfe(&io___17);
	do_fio(&c__1, (char *)&refnum_1.nprob, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&m, (ftnlen)sizeof(integer));
	e_wsfe();
	refnum_1.nfev = 0;
	refnum_1.njev = 0;
	lmdif1_((U_fp)fcn_, &m, &n, x, fvec, &tol, &info, iwa, wa, &lwa);
	ssqfcn_(&m, &n, x, fvec, &refnum_1.nprob);
	fnorm2 = enorm_(&m, fvec);
	np[ic - 1] = refnum_1.nprob;
	na[ic - 1] = n;
	ma[ic - 1] = m;
	nf[ic - 1] = refnum_1.nfev;
	refnum_1.njev /= n;
	nj[ic - 1] = refnum_1.njev;
	nx[ic - 1] = info;
	fnm[ic - 1] = fnorm2;
	io___29.ciunit = nwrite;
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&fnorm1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fnorm2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&refnum_1.nfev, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&refnum_1.njev, (ftnlen)sizeof(integer));
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
    io___31.ciunit = nwrite;
    s_wsfe(&io___31);
    do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
    e_wsfe();
    io___32.ciunit = nwrite;
    s_wsfe(&io___32);
    e_wsfe();
    i__1 = ic;
    for (i__ = 1; i__ <= i__1; ++i__) {
	io___33.ciunit = nwrite;
	s_wsfe(&io___33);
	do_fio(&c__1, (char *)&np[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&na[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ma[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nf[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nj[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nx[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&fnm[i__ - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L40: */
    }
    s_stop("", (ftnlen)0);

/*     LAST CARD OF DRIVER. */

    return 0;
} /* MAIN__ */

/* Subroutine */ int fcn_(integer *m, integer *n, doublereal *x, doublereal *
	fvec, integer *iflag)
{
    extern /* Subroutine */ int ssqfcn_(integer *, integer *, doublereal *, 
	    doublereal *, integer *);

/*     ********** */

/*     THE CALLING SEQUENCE OF FCN SHOULD BE IDENTICAL TO THE */
/*     CALLING SEQUENCE OF THE FUNCTION SUBROUTINE IN THE NONLINEAR */
/*     LEAST-SQUARES SOLVER. FCN SHOULD ONLY CALL THE TESTING */
/*     FUNCTION SUBROUTINE SSQFCN WITH THE APPROPRIATE VALUE OF */
/*     PROBLEM NUMBER (NPROB). */

/*     SUBPROGRAMS CALLED */

/*       MINPACK-SUPPLIED ... SSQFCN */

/*     ARGONNE NATIONAL LABORATORY. MINPACK PROJECT. MARCH 1980. */
/*     BURTON S. GARBOW, KENNETH E. HILLSTROM, JORGE J. MORE */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;

    /* Function Body */
    ssqfcn_(m, n, &x[1], &fvec[1], &refnum_1.nprob);
    if (*iflag == 1) {
	++refnum_1.nfev;
    }
    if (*iflag == 2) {
	++refnum_1.njev;
    }
    return 0;

/*     LAST CARD OF INTERFACE SUBROUTINE FCN. */

} /* fcn_ */

/* Subroutine */ int ssqfcn_(integer *m, integer *n, doublereal *x, 
	doublereal *fvec, integer *nprob)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal zp25 = .25;
    static doublereal zp5 = .5;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal five = 5.;
    static doublereal eight = 8.;
    static doublereal ten = 10.;
    static doublereal c13 = 13.;
    static doublereal c14 = 14.;
    static doublereal c29 = 29.;
    static doublereal c45 = 45.;
    static doublereal v[11] = { 4.,2.,1.,.5,.25,.167,.125,.1,.0833,.0714,
	    .0625 };
    static doublereal y1[15] = { .14,.18,.22,.25,.29,.32,.35,.39,.37,.58,.73,
	    .96,1.34,2.1,4.39 };
    static doublereal y2[11] = { .1957,.1947,.1735,.16,.0844,.0627,.0456,
	    .0342,.0323,.0235,.0246 };
    static doublereal y3[16] = { 34780.,28610.,23650.,19630.,16370.,13720.,
	    11540.,9744.,8261.,7030.,6005.,5147.,4427.,3820.,3307.,2872. };
    static doublereal y4[33] = { .844,.908,.932,.936,.925,.908,.881,.85,.818,
	    .784,.751,.718,.685,.658,.628,.603,.58,.558,.538,.522,.506,.49,
	    .478,.467,.457,.448,.438,.431,.424,.42,.414,.411,.406 };
    static doublereal y5[65] = { 1.366,1.191,1.112,1.013,.991,.885,.831,.847,
	    .786,.725,.746,.679,.608,.655,.616,.606,.602,.626,.651,.724,.649,
	    .649,.694,.644,.624,.661,.612,.558,.533,.495,.5,.423,.395,.375,
	    .372,.391,.396,.405,.428,.429,.523,.562,.607,.653,.672,.708,.633,
	    .668,.645,.632,.591,.559,.597,.625,.739,.71,.729,.72,.636,.581,
	    .428,.292,.162,.098,.054 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double atan(doublereal), d_sign(doublereal *, doublereal *), sqrt(
	    doublereal), exp(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal s1, s2, dx, ti;
    static integer nm1;
    static doublereal div;
    static integer iev;
    static doublereal tpi, sum, tmp1, tmp2, tmp3, tmp4, prod, temp;

/*     ********** */

/*     SUBROUTINE SSQFCN */

/*     THIS SUBROUTINE DEFINES THE FUNCTIONS OF EIGHTEEN NONLINEAR */
/*     LEAST SQUARES PROBLEMS. THE ALLOWABLE VALUES OF (M,N) FOR */
/*     FUNCTIONS 1,2 AND 3 ARE VARIABLE BUT WITH M .GE. N. */
/*     FOR FUNCTIONS 4,5,6,7,8,9 AND 10 THE VALUES OF (M,N) ARE */
/*     (2,2),(3,3),(4,4),(2,2),(15,3),(11,4) AND (16,3), RESPECTIVELY. */
/*     FUNCTION 11 (WATSON) HAS M = 31 WITH N USUALLY 6 OR 9. */
/*     HOWEVER, ANY N, N = 2,...,31, IS PERMITTED. */
/*     FUNCTIONS 12,13 AND 14 HAVE N = 3,2 AND 4, RESPECTIVELY, BUT */
/*     ALLOW ANY M .GE. N, WITH THE USUAL CHOICES BEING 10,10 AND 20. */
/*     FUNCTION 15 (CHEBYQUAD) ALLOWS M AND N VARIABLE WITH M .GE. N. */
/*     FUNCTION 16 (BROWN) ALLOWS N VARIABLE WITH M = N. */
/*     FOR FUNCTIONS 17 AND 18, THE VALUES OF (M,N) ARE */
/*     (33,5) AND (65,11), RESPECTIVELY. */

/*     THE SUBROUTINE STATEMENT IS */

/*       SUBROUTINE SSQFCN(M,N,X,FVEC,NPROB) */

/*     WHERE */

/*       M AND N ARE POSITIVE INTEGER INPUT VARIABLES. N MUST NOT */
/*         EXCEED M. */

/*       X IS AN INPUT ARRAY OF LENGTH N. */

/*       FVEC IS AN OUTPUT ARRAY OF LENGTH M WHICH CONTAINS THE NPROB */
/*         FUNCTION EVALUATED AT X. */

/*       NPROB IS A POSITIVE INTEGER INPUT VARIABLE WHICH DEFINES THE */
/*         NUMBER OF THE PROBLEM. NPROB MUST NOT EXCEED 18. */

/*     SUBPROGRAMS CALLED */

/*       FORTRAN-SUPPLIED ... DATAN,DCOS,DEXP,DSIN,DSQRT,DSIGN */

/*     ARGONNE NATIONAL LABORATORY. MINPACK PROJECT. MARCH 1980. */
/*     BURTON S. GARBOW, KENNETH E. HILLSTROM, JORGE J. MORE */

/*     ********** */
    /* Parameter adjustments */
    --fvec;
    --x;

    /* Function Body */

/*     FUNCTION ROUTINE SELECTOR. */

    switch (*nprob) {
	case 1:  goto L10;
	case 2:  goto L40;
	case 3:  goto L70;
	case 4:  goto L110;
	case 5:  goto L120;
	case 6:  goto L130;
	case 7:  goto L140;
	case 8:  goto L150;
	case 9:  goto L170;
	case 10:  goto L190;
	case 11:  goto L210;
	case 12:  goto L250;
	case 13:  goto L270;
	case 14:  goto L290;
	case 15:  goto L310;
	case 16:  goto L360;
	case 17:  goto L390;
	case 18:  goto L410;
    }

/*     LINEAR FUNCTION - FULL RANK. */

L10:
    sum = zero;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	sum += x[j];
/* L20: */
    }
    temp = two * sum / (doublereal) (*m) + one;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fvec[i__] = -temp;
	if (i__ <= *n) {
	    fvec[i__] += x[i__];
	}
/* L30: */
    }
    goto L430;

/*     LINEAR FUNCTION - RANK 1. */

L40:
    sum = zero;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	sum += (doublereal) j * x[j];
/* L50: */
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fvec[i__] = (doublereal) i__ * sum - one;
/* L60: */
    }
    goto L430;

/*     LINEAR FUNCTION - RANK 1 WITH ZERO COLUMNS AND ROWS. */

L70:
    sum = zero;
    nm1 = *n - 1;
    if (nm1 < 2) {
	goto L90;
    }
    i__1 = nm1;
    for (j = 2; j <= i__1; ++j) {
	sum += (doublereal) j * x[j];
/* L80: */
    }
L90:
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	fvec[i__] = (doublereal) i__2 * sum - one;
/* L100: */
    }
    fvec[*m] = -one;
    goto L430;

/*     ROSENBROCK FUNCTION. */

L110:
/* Computing 2nd power */
    d__1 = x[1];
    fvec[1] = ten * (x[2] - d__1 * d__1);
    fvec[2] = one - x[1];
    goto L430;

/*     HELICAL VALLEY FUNCTION. */

L120:
    tpi = eight * atan(one);
    tmp1 = d_sign(&zp25, &x[2]);
    if (x[1] > zero) {
	tmp1 = atan(x[2] / x[1]) / tpi;
    }
    if (x[1] < zero) {
	tmp1 = atan(x[2] / x[1]) / tpi + zp5;
    }
/* Computing 2nd power */
    d__1 = x[1];
/* Computing 2nd power */
    d__2 = x[2];
    tmp2 = sqrt(d__1 * d__1 + d__2 * d__2);
    fvec[1] = ten * (x[3] - ten * tmp1);
    fvec[2] = ten * (tmp2 - one);
    fvec[3] = x[3];
    goto L430;

/*     POWELL SINGULAR FUNCTION. */

L130:
    fvec[1] = x[1] + ten * x[2];
    fvec[2] = sqrt(five) * (x[3] - x[4]);
/* Computing 2nd power */
    d__1 = x[2] - two * x[3];
    fvec[3] = d__1 * d__1;
/* Computing 2nd power */
    d__1 = x[1] - x[4];
    fvec[4] = sqrt(ten) * (d__1 * d__1);
    goto L430;

/*     FREUDENSTEIN AND ROTH FUNCTION. */

L140:
    fvec[1] = -c13 + x[1] + ((five - x[2]) * x[2] - two) * x[2];
    fvec[2] = -c29 + x[1] + ((one + x[2]) * x[2] - c14) * x[2];
    goto L430;

/*     BARD FUNCTION. */

L150:
    for (i__ = 1; i__ <= 15; ++i__) {
	tmp1 = (doublereal) i__;
	i__1 = 16 - i__;
	tmp2 = (doublereal) i__1;
	tmp3 = tmp1;
	if (i__ > 8) {
	    tmp3 = tmp2;
	}
	fvec[i__] = y1[i__ - 1] - (x[1] + tmp1 / (x[2] * tmp2 + x[3] * tmp3));
/* L160: */
    }
    goto L430;

/*     KOWALIK AND OSBORNE FUNCTION. */

L170:
    for (i__ = 1; i__ <= 11; ++i__) {
	tmp1 = v[i__ - 1] * (v[i__ - 1] + x[2]);
	tmp2 = v[i__ - 1] * (v[i__ - 1] + x[3]) + x[4];
	fvec[i__] = y2[i__ - 1] - x[1] * tmp1 / tmp2;
/* L180: */
    }
    goto L430;

/*     MEYER FUNCTION. */

L190:
    for (i__ = 1; i__ <= 16; ++i__) {
	temp = five * (doublereal) i__ + c45 + x[3];
	tmp1 = x[2] / temp;
	tmp2 = exp(tmp1);
	fvec[i__] = x[1] * tmp2 - y3[i__ - 1];
/* L200: */
    }
    goto L430;

/*     WATSON FUNCTION. */

L210:
    for (i__ = 1; i__ <= 29; ++i__) {
	div = (doublereal) i__ / c29;
	s1 = zero;
	dx = one;
	i__1 = *n;
	for (j = 2; j <= i__1; ++j) {
	    i__2 = j - 1;
	    s1 += (doublereal) i__2 * dx * x[j];
	    dx = div * dx;
/* L220: */
	}
	s2 = zero;
	dx = one;
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    s2 += dx * x[j];
	    dx = div * dx;
/* L230: */
	}
/* Computing 2nd power */
	d__1 = s2;
	fvec[i__] = s1 - d__1 * d__1 - one;
/* L240: */
    }
    fvec[30] = x[1];
/* Computing 2nd power */
    d__1 = x[1];
    fvec[31] = x[2] - d__1 * d__1 - one;
    goto L430;

/*     BOX 3-DIMENSIONAL FUNCTION. */

L250:
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	temp = (doublereal) i__;
	tmp1 = temp / ten;
	fvec[i__] = exp(-tmp1 * x[1]) - exp(-tmp1 * x[2]) + (exp(-temp) - exp(
		-tmp1)) * x[3];
/* L260: */
    }
    goto L430;

/*     JENNRICH AND SAMPSON FUNCTION. */

L270:
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	temp = (doublereal) i__;
	fvec[i__] = two + two * temp - exp(temp * x[1]) - exp(temp * x[2]);
/* L280: */
    }
    goto L430;

/*     BROWN AND DENNIS FUNCTION. */

L290:
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	temp = (doublereal) i__ / five;
	tmp1 = x[1] + temp * x[2] - exp(temp);
	tmp2 = x[3] + sin(temp) * x[4] - cos(temp);
/* Computing 2nd power */
	d__1 = tmp1;
/* Computing 2nd power */
	d__2 = tmp2;
	fvec[i__] = d__1 * d__1 + d__2 * d__2;
/* L300: */
    }
    goto L430;

/*     CHEBYQUAD FUNCTION. */

L310:
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fvec[i__] = zero;
/* L320: */
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	tmp1 = one;
	tmp2 = two * x[j] - one;
	temp = two * tmp2;
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    fvec[i__] += tmp2;
	    ti = temp * tmp2 - tmp1;
	    tmp1 = tmp2;
	    tmp2 = ti;
/* L330: */
	}
/* L340: */
    }
    dx = one / (doublereal) (*n);
    iev = -1;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fvec[i__] = dx * fvec[i__];
	if (iev > 0) {
/* Computing 2nd power */
	    d__1 = (doublereal) i__;
	    fvec[i__] += one / (d__1 * d__1 - one);
	}
	iev = -iev;
/* L350: */
    }
    goto L430;

/*     BROWN ALMOST-LINEAR FUNCTION. */

L360:
    i__1 = *n + 1;
    sum = -((doublereal) i__1);
    prod = one;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	sum += x[j];
	prod = x[j] * prod;
/* L370: */
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fvec[i__] = x[i__] + sum;
/* L380: */
    }
    fvec[*n] = prod - one;
    goto L430;

/*     OSBORNE 1 FUNCTION. */

L390:
    for (i__ = 1; i__ <= 33; ++i__) {
	i__1 = i__ - 1;
	temp = ten * (doublereal) i__1;
	tmp1 = exp(-x[4] * temp);
	tmp2 = exp(-x[5] * temp);
	fvec[i__] = y4[i__ - 1] - (x[1] + x[2] * tmp1 + x[3] * tmp2);
/* L400: */
    }
    goto L430;

/*     OSBORNE 2 FUNCTION. */

L410:
    for (i__ = 1; i__ <= 65; ++i__) {
	i__1 = i__ - 1;
	temp = (doublereal) i__1 / ten;
	tmp1 = exp(-x[5] * temp);
/* Computing 2nd power */
	d__1 = temp - x[9];
	tmp2 = exp(-x[6] * (d__1 * d__1));
/* Computing 2nd power */
	d__1 = temp - x[10];
	tmp3 = exp(-x[7] * (d__1 * d__1));
/* Computing 2nd power */
	d__1 = temp - x[11];
	tmp4 = exp(-x[8] * (d__1 * d__1));
	fvec[i__] = y5[i__ - 1] - (x[1] * tmp1 + x[2] * tmp2 + x[3] * tmp3 + 
		x[4] * tmp4);
/* L420: */
    }
L430:
    return 0;

/*     LAST CARD OF SUBROUTINE SSQFCN. */

} /* ssqfcn_ */

/* Subroutine */ int initpt_(integer *n, doublereal *x, integer *nprob, 
	doublereal *factor)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal half = .5;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal three = 3.;
    static doublereal five = 5.;
    static doublereal seven = 7.;
    static doublereal ten = 10.;
    static doublereal twenty = 20.;
    static doublereal twntf = 25.;
    static doublereal c1 = 1.2;
    static doublereal c2 = .25;
    static doublereal c3 = .39;
    static doublereal c4 = .415;
    static doublereal c5 = .02;
    static doublereal c6 = 4e3;
    static doublereal c7 = 250.;
    static doublereal c8 = .3;
    static doublereal c9 = .4;
    static doublereal c10 = 1.5;
    static doublereal c11 = .01;
    static doublereal c12 = 1.3;
    static doublereal c13 = .65;
    static doublereal c14 = .7;
    static doublereal c15 = .6;
    static doublereal c16 = 4.5;
    static doublereal c17 = 5.5;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal h__;
    static integer j;

/*     ********** */

/*     SUBROUTINE INITPT */

/*     THIS SUBROUTINE SPECIFIES THE STANDARD STARTING POINTS FOR THE */
/*     FUNCTIONS DEFINED BY SUBROUTINE SSQFCN. THE SUBROUTINE RETURNS */
/*     IN X A MULTIPLE (FACTOR) OF THE STANDARD STARTING POINT. FOR */
/*     THE 11TH FUNCTION THE STANDARD STARTING POINT IS ZERO, SO IN */
/*     THIS CASE, IF FACTOR IS NOT UNITY, THEN THE SUBROUTINE RETURNS */
/*     THE VECTOR  X(J) = FACTOR, J=1,...,N. */

/*     THE SUBROUTINE STATEMENT IS */

/*       SUBROUTINE INITPT(N,X,NPROB,FACTOR) */

/*     WHERE */

/*       N IS A POSITIVE INTEGER INPUT VARIABLE. */

/*       X IS AN OUTPUT ARRAY OF LENGTH N WHICH CONTAINS THE STANDARD */
/*         STARTING POINT FOR PROBLEM NPROB MULTIPLIED BY FACTOR. */

/*       NPROB IS A POSITIVE INTEGER INPUT VARIABLE WHICH DEFINES THE */
/*         NUMBER OF THE PROBLEM. NPROB MUST NOT EXCEED 18. */

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
	case 2:  goto L10;
	case 3:  goto L10;
	case 4:  goto L30;
	case 5:  goto L40;
	case 6:  goto L50;
	case 7:  goto L60;
	case 8:  goto L70;
	case 9:  goto L80;
	case 10:  goto L90;
	case 11:  goto L100;
	case 12:  goto L120;
	case 13:  goto L130;
	case 14:  goto L140;
	case 15:  goto L150;
	case 16:  goto L170;
	case 17:  goto L190;
	case 18:  goto L200;
    }

/*     LINEAR FUNCTION - FULL RANK OR RANK 1. */

L10:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = one;
/* L20: */
    }
    goto L210;

/*     ROSENBROCK FUNCTION. */

L30:
    x[1] = -c1;
    x[2] = one;
    goto L210;

/*     HELICAL VALLEY FUNCTION. */

L40:
    x[1] = -one;
    x[2] = zero;
    x[3] = zero;
    goto L210;

/*     POWELL SINGULAR FUNCTION. */

L50:
    x[1] = three;
    x[2] = -one;
    x[3] = zero;
    x[4] = one;
    goto L210;

/*     FREUDENSTEIN AND ROTH FUNCTION. */

L60:
    x[1] = half;
    x[2] = -two;
    goto L210;

/*     BARD FUNCTION. */

L70:
    x[1] = one;
    x[2] = one;
    x[3] = one;
    goto L210;

/*     KOWALIK AND OSBORNE FUNCTION. */

L80:
    x[1] = c2;
    x[2] = c3;
    x[3] = c4;
    x[4] = c3;
    goto L210;

/*     MEYER FUNCTION. */

L90:
    x[1] = c5;
    x[2] = c6;
    x[3] = c7;
    goto L210;

/*     WATSON FUNCTION. */

L100:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = zero;
/* L110: */
    }
    goto L210;

/*     BOX 3-DIMENSIONAL FUNCTION. */

L120:
    x[1] = zero;
    x[2] = ten;
    x[3] = twenty;
    goto L210;

/*     JENNRICH AND SAMPSON FUNCTION. */

L130:
    x[1] = c8;
    x[2] = c9;
    goto L210;

/*     BROWN AND DENNIS FUNCTION. */

L140:
    x[1] = twntf;
    x[2] = five;
    x[3] = -five;
    x[4] = -one;
    goto L210;

/*     CHEBYQUAD FUNCTION. */

L150:
    i__1 = *n + 1;
    h__ = one / (doublereal) i__1;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = (doublereal) j * h__;
/* L160: */
    }
    goto L210;

/*     BROWN ALMOST-LINEAR FUNCTION. */

L170:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = half;
/* L180: */
    }
    goto L210;

/*     OSBORNE 1 FUNCTION. */

L190:
    x[1] = half;
    x[2] = c10;
    x[3] = -one;
    x[4] = c11;
    x[5] = c5;
    goto L210;

/*     OSBORNE 2 FUNCTION. */

L200:
    x[1] = c12;
    x[2] = c13;
    x[3] = c13;
    x[4] = c14;
    x[5] = c15;
    x[6] = three;
    x[7] = five;
    x[8] = seven;
    x[9] = two;
    x[10] = c16;
    x[11] = c17;
L210:

/*     COMPUTE MULTIPLE OF INITIAL POINT. */

    if (*factor == one) {
	goto L260;
    }
    if (*nprob == 11) {
	goto L230;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = *factor * x[j];
/* L220: */
    }
    goto L250;
L230:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	x[j] = *factor;
/* L240: */
    }
L250:
L260:
    return 0;

/*     LAST CARD OF SUBROUTINE INITPT. */

} /* initpt_ */

