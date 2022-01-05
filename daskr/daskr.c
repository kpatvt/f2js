/* daskr.f -- translated by f2c (version 20160102).
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
    doublereal srur;
    integer mp, mpd, mpsq, meshx, meshy, mxmp;
} drpre1_;

#define drpre1_1 drpre1_

struct {
    integer ngx, ngy, ngrp, jgx[51], jgy[51], jigx[50], jigy[50], jxr[50], 
	    jyr[50];
} rpre2_;

#define rpre2_1 rpre2_

/* Table of constant values */

static doublereal c_b3 = 1.;
static integer c__1 = 1;
static integer c__0 = 0;
static logical c_false = FALSE_;
static integer c__2 = 2;
static logical c_true = TRUE_;
static integer c__4 = 4;
static integer c__49 = 49;
static integer c__201 = 201;
static doublereal c_b83 = 0.;
static integer c__47 = 47;
static integer c__202 = 202;
static integer c__41 = 41;
static integer c__203 = 203;
static doublereal c_b113 = .6667;
static integer c__56 = 56;
static integer c__501 = 501;
static integer c__502 = 502;
static integer c__503 = 503;
static integer c__3 = 3;
static integer c__38 = 38;
static integer c__610 = 610;
static integer c__48 = 48;
static integer c__611 = 611;
static integer c__620 = 620;
static integer c__621 = 621;
static integer c__43 = 43;
static integer c__622 = 622;
static integer c__630 = 630;
static integer c__28 = 28;
static integer c__631 = 631;
static integer c__44 = 44;
static integer c__640 = 640;
static integer c__57 = 57;
static integer c__641 = 641;
static integer c__650 = 650;
static integer c__651 = 651;
static integer c__40 = 40;
static integer c__652 = 652;
static integer c__655 = 655;
static integer c__46 = 46;
static integer c__656 = 656;
static integer c__660 = 660;
static integer c__661 = 661;
static integer c__670 = 670;
static integer c__45 = 45;
static integer c__671 = 671;
static integer c__672 = 672;
static integer c__675 = 675;
static integer c__51 = 51;
static integer c__676 = 676;
static integer c__677 = 677;
static integer c__680 = 680;
static integer c__36 = 36;
static integer c__681 = 681;
static integer c__685 = 685;
static integer c__686 = 686;
static integer c__690 = 690;
static integer c__35 = 35;
static integer c__691 = 691;
static integer c__695 = 695;
static integer c__50 = 50;
static integer c__696 = 696;
static integer c__25 = 25;
static integer c__34 = 34;
static integer c__60 = 60;
static integer c__5 = 5;
static integer c__39 = 39;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__8 = 8;
static integer c__54 = 54;
static integer c__9 = 9;
static integer c__10 = 10;
static integer c__11 = 11;
static integer c__29 = 29;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__14 = 14;
static integer c__15 = 15;
static integer c__52 = 52;
static integer c__17 = 17;
static integer c__18 = 18;
static integer c__19 = 19;
static integer c__20 = 20;
static integer c__21 = 21;
static integer c__22 = 22;
static integer c__58 = 58;
static integer c__23 = 23;
static integer c__24 = 24;
static integer c__26 = 26;
static integer c__27 = 27;
static integer c__30 = 30;
static integer c__31 = 31;
static integer c__701 = 701;
static integer c__702 = 702;
static integer c__901 = 901;
static integer c__902 = 902;
static integer c__903 = 903;
static integer c__904 = 904;
static integer c__905 = 905;
static integer c__42 = 42;
static integer c__906 = 906;
static integer c__921 = 921;
static integer c__922 = 922;
static integer c__923 = 923;
static integer c__924 = 924;
static integer c__925 = 925;
static integer c__926 = 926;
static integer c__80 = 80;
static real c_b1235 = 0.f;

/* DECK D1MACH */
doublereal d1mach_(integer *idummy)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    static doublereal u, comp;
    extern /* Subroutine */ int dumsum_(doublereal *, doublereal *, 
	    doublereal *);

/* ***BEGIN PROLOGUE  D1MACH */
/* ***PURPOSE  Compute the unit roundoff of the machine. */
/* ***CATEGORY  R1 */
/* ***TYPE      DOUBLE PRECISION (R1MACH-S, D1MACH-D) */
/* ***KEYWORDS  MACHINE CONSTANTS */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */
/* *Usage: */
/*        DOUBLE PRECISION  A, D1MACH */
/*        A = D1MACH(idummy)  [The argument is ignored.] */

/* *Function Return Values: */
/*     A : the unit roundoff of the machine. */

/* *Description: */
/*     The unit roundoff is defined as the smallest positive machine */
/*     number u such that  1.0 + u .ne. 1.0.  This is computed by D1MACH */
/*     in a machine-independent manner. */

/* ***REFERENCES  (NONE) */
/* ***ROUTINES CALLED  DUMSUM */
/* ***REVISION HISTORY  (YYYYMMDD) */
/*   19930216  DATE WRITTEN */
/*   19930818  Added SLATEC-format prologue.  (FNF) */
/*   20030707  Added DUMSUM to force normal storage of COMP.  (ACH) */
/* ***END PROLOGUE  D1MACH */

/* ***FIRST EXECUTABLE STATEMENT  D1MACH */
    u = 1.;
L10:
    u *= .5;
    dumsum_(&c_b3, &u, &comp);
    if (comp != 1.) {
	goto L10;
    }
    ret_val = u * 2.;
    return ret_val;
/* ----------------------- End of Function D1MACH ------------------------ */
} /* d1mach_ */

/* Subroutine */ int dumsum_(doublereal *a, doublereal *b, doublereal *c__)
{
/*     Routine to force normal storing of A + B, for D1MACH. */
    *c__ = *a + *b;
    return 0;
} /* dumsum_ */

/* DECK XERRWD */
/* Subroutine */ int xerrwd_(char *msg, integer *nmes, integer *nerr, integer 
	*level, integer *ni, integer *i1, integer *i2, integer *nr, 
	doublereal *r1, doublereal *r2, ftnlen msg_len)
{
    /* Format strings */
    static char fmt_10[] = "(1x,a)";
    static char fmt_20[] = "(6x,\002In above message,  I1 =\002,i10)";
    static char fmt_30[] = "(6x,\002In above message,  I1 =\002,i10,3x,\002I"
	    "2 =\002,i10)";
    static char fmt_40[] = "(6x,\002In above message,  R1 =\002,d21.13)";
    static char fmt_50[] = "(6x,\002In above,  R1 =\002,d21.13,3x,\002R2 "
	    "=\002,d21.13)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern integer ixsav_(integer *, integer *, logical *);
    static integer lunit, mesflg;

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_50, 0 };


/* ***BEGIN PROLOGUE  XERRWD */
/* ***SUBSIDIARY */
/* ***PURPOSE  Write error message with values. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3C */
/* ***TYPE      DOUBLE PRECISION (XERRWV-S, XERRWD-D) */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */

/*  Subroutines XERRWD, XSETF, XSETUN, and the function routine IXSAV, */
/*  as given here, constitute a simplified version of the SLATEC error */
/*  handling package. */

/*  All arguments are input arguments. */

/*  MSG    = The message (character array). */
/*  NMES   = The length of MSG (number of characters). */
/*  NERR   = The error number (not used). */
/*  LEVEL  = The error level.. */
/*           0 or 1 means recoverable (control returns to caller). */
/*           2 means fatal (run is aborted--see note below). */
/*  NI     = Number of integers (0, 1, or 2) to be printed with message. */
/*  I1,I2  = Integers to be printed, depending on NI. */
/*  NR     = Number of reals (0, 1, or 2) to be printed with message. */
/*  R1,R2  = Reals to be printed, depending on NR. */

/*  Note..  this routine is machine-dependent and specialized for use */
/*  in limited context, in the following ways.. */
/*  1. The argument MSG is assumed to be of type CHARACTER, and */
/*     the message is printed with a format of (1X,A). */
/*  2. The message is assumed to take only one line. */
/*     Multi-line messages are generated by repeated calls. */
/*  3. If LEVEL = 2, control passes to the statement   STOP */
/*     to abort the run.  This statement may be machine-dependent. */
/*  4. R1 and R2 are assumed to be in double precision and are printed */
/*     in D21.13 format. */

/* ***ROUTINES CALLED  IXSAV */
/* ***REVISION HISTORY  (YYMMDD) */
/*   920831  DATE WRITTEN */
/*   921118  Replaced MFLGSV/LUNSAV by IXSAV. (ACH) */
/*   930329  Modified prologue to SLATEC format. (FNF) */
/*   930407  Changed MSG from CHARACTER*1 array to variable. (FNF) */
/*   930922  Minor cosmetic change. (FNF) */
/* ***END PROLOGUE  XERRWD */

/* *Internal Notes: */

/* For a different default logical unit number, IXSAV (or a subsidiary */
/* routine that it calls) will need to be modified. */
/* For a different run-abort command, change the statement following */
/* statement 100 at the end. */
/* ----------------------------------------------------------------------- */
/* Subroutines called by XERRWD.. None */
/* Function routine called by XERRWD.. IXSAV */
/* ----------------------------------------------------------------------- */
/* **End */

/*  Declare arguments. */


/*  Declare local variables. */


/*  Get logical unit number and message print flag. */

/* ***FIRST EXECUTABLE STATEMENT  XERRWD */
    lunit = ixsav_(&c__1, &c__0, &c_false);
    mesflg = ixsav_(&c__2, &c__0, &c_false);
    if (mesflg == 0) {
	goto L100;
    }

/*  Write the message. */

    io___5.ciunit = lunit;
    s_wsfe(&io___5);
    do_fio(&c__1, msg, msg_len);
    e_wsfe();
    if (*ni == 1) {
	io___6.ciunit = lunit;
	s_wsfe(&io___6);
	do_fio(&c__1, (char *)&(*i1), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*ni == 2) {
	io___7.ciunit = lunit;
	s_wsfe(&io___7);
	do_fio(&c__1, (char *)&(*i1), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*i2), (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*nr == 1) {
	io___8.ciunit = lunit;
	s_wsfe(&io___8);
	do_fio(&c__1, (char *)&(*r1), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (*nr == 2) {
	io___9.ciunit = lunit;
	s_wsfe(&io___9);
	do_fio(&c__1, (char *)&(*r1), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*r2), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/*  Abort the run if LEVEL = 2. */

L100:
    if (*level != 2) {
	return 0;
    }
    s_stop("", (ftnlen)0);
/* ----------------------- End of Subroutine XERRWD ---------------------- */
    return 0;
} /* xerrwd_ */

/* DECK XSETF */
/* Subroutine */ int xsetf_(integer *mflag)
{
    static integer junk;
    extern integer ixsav_(integer *, integer *, logical *);

/* ***BEGIN PROLOGUE  XSETF */
/* ***PURPOSE  Reset the error print control flag. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3A */
/* ***TYPE      ALL (XSETF-A) */
/* ***KEYWORDS  ERROR CONTROL */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */

/*   XSETF sets the error print control flag to MFLAG: */
/*      MFLAG=1 means print all messages (the default). */
/*      MFLAG=0 means no printing. */

/* ***SEE ALSO  XERMSG, XERRWD, XERRWV */
/* ***REFERENCES  (NONE) */
/* ***ROUTINES CALLED  IXSAV */
/* ***REVISION HISTORY  (YYMMDD) */
/*   921118  DATE WRITTEN */
/*   930329  Added SLATEC format prologue. (FNF) */
/*   930407  Corrected SEE ALSO section. (FNF) */
/*   930922  Made user-callable, and other cosmetic changes. (FNF) */
/* ***END PROLOGUE  XSETF */

/* Subroutines called by XSETF.. None */
/* Function routine called by XSETF.. IXSAV */
/* ----------------------------------------------------------------------- */
/* **End */

/* ***FIRST EXECUTABLE STATEMENT  XSETF */
    if (*mflag == 0 || *mflag == 1) {
	junk = ixsav_(&c__2, mflag, &c_true);
    }
    return 0;
/* ----------------------- End of Subroutine XSETF ----------------------- */
} /* xsetf_ */

/* DECK XSETUN */
/* Subroutine */ int xsetun_(integer *lun)
{
    static integer junk;
    extern integer ixsav_(integer *, integer *, logical *);

/* ***BEGIN PROLOGUE  XSETUN */
/* ***PURPOSE  Reset the logical unit number for error messages. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3B */
/* ***TYPE      ALL (XSETUN-A) */
/* ***KEYWORDS  ERROR CONTROL */
/* ***DESCRIPTION */

/*   XSETUN sets the logical unit number for error messages to LUN. */

/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***SEE ALSO  XERMSG, XERRWD, XERRWV */
/* ***REFERENCES  (NONE) */
/* ***ROUTINES CALLED  IXSAV */
/* ***REVISION HISTORY  (YYMMDD) */
/*   921118  DATE WRITTEN */
/*   930329  Added SLATEC format prologue. (FNF) */
/*   930407  Corrected SEE ALSO section. (FNF) */
/*   930922  Made user-callable, and other cosmetic changes. (FNF) */
/* ***END PROLOGUE  XSETUN */

/* Subroutines called by XSETUN.. None */
/* Function routine called by XSETUN.. IXSAV */
/* ----------------------------------------------------------------------- */
/* **End */

/* ***FIRST EXECUTABLE STATEMENT  XSETUN */
    if (*lun > 0) {
	junk = ixsav_(&c__1, lun, &c_true);
    }
    return 0;
/* ----------------------- End of Subroutine XSETUN ---------------------- */
} /* xsetun_ */

/* DECK IXSAV */
integer ixsav_(integer *ipar, integer *ivalue, logical *iset)
{
    /* Initialized data */

    static integer lunit = -1;
    static integer lundef = 6;
    static integer mesflg = 1;

    /* System generated locals */
    integer ret_val;

/* ***BEGIN PROLOGUE  IXSAV */
/* ***SUBSIDIARY */
/* ***PURPOSE  Save and recall error message control parameters. */
/* ***LIBRARY   MATHLIB */
/* ***CATEGORY  R3C */
/* ***TYPE      ALL (IXSAV-A) */
/* ***AUTHOR  Hindmarsh, Alan C., (LLNL) */
/* ***DESCRIPTION */

/*  IXSAV saves and recalls one of two error message parameters: */
/*    LUNIT, the logical unit number to which messages are printed, and */
/*    MESFLG, the message print flag. */
/*  This is a modification of the SLATEC library routine J4SAVE. */

/*  Saved local variables.. */
/*   LUNIT  = Logical unit number for messages. */
/*   LUNDEF = Default logical unit number, data-loaded to 6 below */
/*            (may be machine-dependent). */
/*   MESFLG = Print control flag.. */
/*            1 means print all messages (the default). */
/*            0 means no printing. */

/*  On input.. */
/*    IPAR   = Parameter indicator (1 for LUNIT, 2 for MESFLG). */
/*    IVALUE = The value to be set for the parameter, if ISET = .TRUE. */
/*    ISET   = Logical flag to indicate whether to read or write. */
/*             If ISET = .TRUE., the parameter will be given */
/*             the value IVALUE.  If ISET = .FALSE., the parameter */
/*             will be unchanged, and IVALUE is a dummy argument. */

/*  On return.. */
/*    IXSAV = The (old) value of the parameter. */

/* ***SEE ALSO  XERMSG, XERRWD, XERRWV */
/* ***ROUTINES CALLED  NONE */
/* ***REVISION HISTORY  (YYMMDD) */
/*   921118  DATE WRITTEN */
/*   930329  Modified prologue to SLATEC format. (FNF) */
/*   941025  Minor modification re default unit number. (ACH) */
/* ***END PROLOGUE  IXSAV */

/* **End */
/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
/* The following Fortran-77 declaration is to cause the values of the */
/* listed (local) variables to be saved between calls to this routine. */
/* ----------------------------------------------------------------------- */

/* ***FIRST EXECUTABLE STATEMENT  IXSAV */
    if (*ipar == 1) {
	if (lunit == -1) {
	    lunit = lundef;
	}
	ret_val = lunit;
	if (*iset) {
	    lunit = *ivalue;
	}
    }

    if (*ipar == 2) {
	ret_val = mesflg;
	if (*iset) {
	    mesflg = *ivalue;
	}
    }

    return ret_val;
/* ----------------------- End of Function IXSAV ------------------------- */
} /* ixsav_ */

/* ----------------------------------------------------------------------- */

/*             Preconditioner Routines for Banded Problems */
/*                          14 September 1995 */

/* The following pair of subroutines -- DBANJA and DBANPS -- provides a */
/* general-purpose banded preconditioner matrix for use with the DDASPK */
/* solver, with the Krylov linear system method.  When using DDASPK to */
/* solve a problem G(t,y,y') = 0, whose iteration matrix (Jacobian) */
/*    J = dG/dy + c * dG/dy'  (c = scalar) */
/* is either banded or approximately equal to a banded matrix, these */
/* routines can be used to generate a banded approximation to J as the */
/* preconditioner and to solve the resulting banded linear system, in */
/* conjunction with the Krylov method option (INFO(12) = 1) in DDASPK. */

/* Other than the user-supplied residual routine RES defining G(t,y,y'), */
/* the only other inputs required by these routines are the */
/* half-bandwidth parameters ML and MU of the approximate banded */
/* Jacobian.  If the system size is NEQ, the half-bandwidths are */
/* defined as integers between 0 and NEQ - 1 such that only elements */
/* with indices (i,j) satisfying */
/*    -ML .le. j - i .le. MU */
/* are to be retained in the preconditioner.  E.g., if ML = MU = 0, a */
/* diagonal matrix will be generated as the preconditioner.  The banded */
/* preconditioner is obtained by difference quotient approximations.  If */
/* the true problem Jacobian is not banded but is approximately equal to */
/* a matrix that is banded, the procedure used here will have the effect */
/* of lumping the elements outside of the band onto the elements within */
/* the band. */

/* To use these routines in conjunction with DDASPK, the user's calling */
/* program should include the following, in addition to setting the other */
/* DDASPK input parameters. */

/* (a) Dimension the array IPAR to have length at least 2, and load the */
/*     half-bandwidths into IPAR as */
/*       IPAR(1) = ML   and   IPAR(2) = MU */
/*     IPAR is used to communicate these parameters to DBANJA and DBANPS. */
/*     If the user program also uses IPAR for communication with RES, */
/*     that data should be located beyond the first 2 words of IPAR. */

/* (b) Include the names DBANJA and DBANPS in an EXTERNAL statement. */
/*     Set INFO(15) = 1 to indicate that a JAC routine exists. */
/*     Then in the call to DDASPK, pass the names DBANJA and DBANPS as */
/*     the arguments JAC and PSOL, respectively. */

/* (c) The DDASPK work arrays RWORK and IWORK must include segments WP */
/*     and IWP for use by DBANJA/DBANPS.  The lengths of these depend on */
/*     the problem size and half-bandwidths, as follows: */
/*       LWP =  length of RWORK segment WP = */
/*                     (2*ML + MU + 1)*NEQ + 2*( (NEQ/(ML+MU+1)) + 1) */
/*       LIWP = length of IWORK segment IWP = NEQ */
/*     (Note the integer divide in LWP.)  Load these lengths in IWORK as */
/*       IWORK(27) = LWP */
/*       IWORK(28) = LIWP */
/*     and include these values in the declared size of RWORK and IWORK. */


/* The DBANJA and DBANPS routines generate and solve the banded */
/* preconditioner matrix P within the preconditioned Krylov algorithm */
/* used by DDASPK when INFO(12) = 1.  P is generated and LU-factored */
/* periodically during the integration, and the factors are used to */
/* solve systems Px = b as needed. */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int dbanja_(S_fp res, integer *ires, integer *neq, 
	doublereal *t, doublereal *y, doublereal *yprime, doublereal *rewt, 
	doublereal *savr, doublereal *wk, doublereal *h__, doublereal *cj, 
	doublereal *wp, integer *iwp, integer *ier, doublereal *rpar, integer 
	*ipar)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, n, i1, i2, ii, ml, mu, mba;
    static doublereal del;
    static integer meb1, lenp;
    static doublereal squr;
    extern /* Subroutine */ int dgbfa_(doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    static integer mband, isave, msave;
    extern doublereal d1mach_(integer *);
    static integer meband;
    static doublereal delinv;
    static integer ipsave;
    static doublereal uround;


/* ***BEGIN PROLOGUE  DBANJA */
/* ***DATE WRITTEN   891204   (YYMMDD) */
/* ***REVISION DATE  900122 */
/* ***REVISION DATE  920929   CJ in RES call sequence */
/* ***REVISION DATE  950914   Name change, minor revisions throughout */
/* ***AUTHORS  L. R. Petzold, P. N. Brown, A. C. Hindmarsh, C. W. Ulrich */
/*            Numerical Mathematics Group */
/*            Lawrence Livermore National Laboratory */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* Subroutine DBANJA generates a banded preconditioner matrix P that */
/* approximates the DDASPK iteration matrix  J = dG/dy + CJ*dG/dy', */
/* where the DAE system is  G(t,y,y') = 0.  The band matrix P has */
/* half-bandwidths ML and MU.  It is computed by making (ML + MU + 1) */
/* calls to the user's RES routine and forming difference quotients, */
/* exactly as in the banded direct method option of DDASPK. */
/* DBANJA calls the LINPACK routine DGBFA to do an LU factorization of */
/* this matrix. */

/* The call sequence parameters have the following meanings. */

/*     RES      = External user-supplied subroutine to evaluate the */
/*                residuals.  See RES description in DDASPK prologue. */
/*     IRES     = Output flag set by RES.  See RES description in DDASPK. */
/*     NEQ      = Problem size. */
/*     T        = Independent variable t. */
/*     Y        = Array containing current dependent variables y. */
/*     YPRIME   = Array containing current derivative y'. */
/*     REWT     = Vector of reciprocal error weights, used here for */
/*                computing increments. */
/*     SAVR     = Current residual evaluated at (T,Y,YPRIME). */
/*     WK       = Real work space of length NEQ. */
/*     H        = Current step size. */
/*     CJ       = Scalar proportional to 1/H. */
/*     WP       = Real work array for P etc.  On output, it contains */
/*                the LU decomposition of the banded approximation P. */
/*     IWP      = Integer work space for matrix pivot information. */
/*     IER      = Output flag, > 0 if P is singular, and 0 otherwise. */
/*     RPAR,IPAR= Real and integer arrays used for communication between */
/*                the calling program and external user routines. */
/*                IPAR(1) and IPAR(2) must contain ML and MU, resp. */
/*                RPAR is not used here. */

/* ***ROUTINES CALLED */
/*   D1MACH, DGBFA, RES */

/* ***END PROLOGUE  DBANJA */


/* Set band parameters. */
    /* Parameter adjustments */
    --ipar;
    --rpar;
    --iwp;
    --wp;
    --wk;
    --savr;
    --rewt;
    --yprime;
    --y;

    /* Function Body */
    ml = ipar[1];
    mu = ipar[2];
    mband = ml + mu + 1;
    mba = min(mband,*neq);
    meband = mband + ml;
    meb1 = meband - 1;

/* Set the machine unit roundoff UROUND and SQRT(UROUND), used to */
/* set increments in the difference quotient procedure. */
    uround = d1mach_(&c__4);
    squr = sqrt(uround);

/* Set pointers into WP.  LENP is the length of the segment for P. */
/* Following that are two segments of size (NEQ/MBAND), with offsets */
/* ISAVE and IPSAVE, for temporary storage of Y and YPRIME elements. */
    lenp = ((ml << 1) + mu + 1) * *neq;
    msave = *neq / mband + 1;
    isave = lenp;
    ipsave = isave + msave;

/* Initialize error flags. */
    *ier = 0;
    *ires = 0;

/* Generate the banded approximate iteration matrix P using */
/* difference quotients on the results of calls to RES. */

    i__1 = mba;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *neq;
	i__3 = mband;
	for (n = j; i__3 < 0 ? n >= i__2 : n <= i__2; n += i__3) {
	    k = (n - j) / mband + 1;
	    wp[isave + k] = y[n];
	    wp[ipsave + k] = yprime[n];
/* Computing MAX */
	    d__4 = (d__1 = y[n], abs(d__1)), d__5 = (d__2 = *h__ * yprime[n], 
		    abs(d__2)), d__4 = max(d__4,d__5), d__5 = (d__3 = 1. / 
		    rewt[n], abs(d__3));
	    del = squr * max(d__4,d__5);
	    d__1 = *h__ * yprime[n];
	    del = d_sign(&del, &d__1);
	    del = y[n] + del - y[n];
	    y[n] += del;
	    yprime[n] += *cj * del;
/* L10: */
	}
	(*res)(t, &y[1], &yprime[1], cj, &wk[1], ires, &rpar[1], &ipar[1]);
	if (*ires < 0) {
	    return 0;
	}
	i__3 = *neq;
	i__2 = mband;
	for (n = j; i__2 < 0 ? n >= i__3 : n <= i__3; n += i__2) {
	    k = (n - j) / mband + 1;
	    y[n] = wp[isave + k];
	    yprime[n] = wp[ipsave + k];
/* Computing MAX */
	    d__4 = (d__1 = y[n], abs(d__1)), d__5 = (d__2 = *h__ * yprime[n], 
		    abs(d__2)), d__4 = max(d__4,d__5), d__5 = (d__3 = 1. / 
		    rewt[n], abs(d__3));
	    del = squr * max(d__4,d__5);
	    d__1 = *h__ * yprime[n];
	    del = d_sign(&del, &d__1);
	    del = y[n] + del - y[n];
	    delinv = 1. / del;
/* Computing MAX */
	    i__4 = 1, i__5 = n - mu;
	    i1 = max(i__4,i__5);
/* Computing MIN */
	    i__4 = *neq, i__5 = n + ml;
	    i2 = min(i__4,i__5);
	    ii = n * meb1 - ml;
	    i__4 = i2;
	    for (i__ = i1; i__ <= i__4; ++i__) {
/* L20: */
		wp[ii + i__] = (wk[i__] - savr[i__]) * delinv;
	    }
/* L30: */
	}
/* L40: */
    }

/* Do LU decomposition of the band matrix P. */

    dgbfa_(&wp[1], &meband, neq, &ml, &mu, &iwp[1], ier);
    return 0;

/* ------------  End of Subroutine DBANJA  ------------------------------- */
} /* dbanja_ */

/* Subroutine */ int dbanps_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *yprime, doublereal *savr, doublereal *wk, doublereal *cj, 
	doublereal *wght, doublereal *wp, integer *iwp, doublereal *b, 
	doublereal *eplin, integer *ier, doublereal *rpar, integer *ipar)
{
    static integer ml, mu;
    extern /* Subroutine */ int dgbsl_(doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *);
    static integer meband;


/* ***BEGIN PROLOGUE  DBANPS */
/* ***DATE WRITTEN   891204   (YYMMDD) */
/* ***REVISION DATE  900110   (YYMMDD) */
/* ***REVISION DATE  950914   Name change, minor revisions throughout */
/* ***AUTHORS  L. R. Petzold, P. N. Brown, A. C. Hindmarsh, C. W. Ulrich */
/*            Numerical Mathematics Group */
/*            Lawrence Livermore National Laboratory */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* Subroutine DBANPS uses the factors produced by DBANJA to solve linear */
/* systems P x = b for the banded preconditioner P and a given vector b. */
/* It calls the LINPACK routine SGBSL for this. */

/* The call sequence parameters have the following meanings. */

/*     NEQ      = Problem size. */
/*     T        = Independent variable t (not used). */
/*     Y        = Array containing current dependent vars. (not used). */
/*     YPRIME   = Array containing current derivative (not used). */
/*     SAVR     = Current residual evaluated at (T,Y,YPRIME) (not used). */
/*     WK       = Real work space of length NEQ (not used). */
/*     CJ       = Scalar proportional to 1/H (H = step size) (not used). */
/*     WGHT     = Vector of error weights for computing norms (not used). */
/*     WP       = Real work array containing the LU decomposition of P. */
/*     IWP      = Integer array containing matrix pivot information. */
/*     B        = Right-hand side vector on input; solution on output. */
/*     EPLIN    = tolerance on linear system solver (not used). */
/*     IER      = Output error flag (not used; assumed 0 on input). */
/*     RPAR,IPAR= Real and integer arrays used for communication between */
/*                the calling program and external user routines. */
/*                IPAR(1) and IPAR(2) must contain ML and MU, resp. */
/*                RPAR is not used here. */

/* ***ROUTINES CALLED */
/*   DGBSL */

/* ***END PROLOGUE  DBANPS */


    /* Parameter adjustments */
    --ipar;
    --rpar;
    --b;
    --iwp;
    --wp;

    /* Function Body */
    ml = ipar[1];
    mu = ipar[2];
    meband = (ml << 1) + mu + 1;
    dgbsl_(&wp[1], &meband, neq, &ml, &mu, &iwp[1], &b[1], &c__0);
    return 0;

/* ------------  End of Subroutine DBANPS  ------------------------------- */
} /* dbanps_ */

/* Subroutine */ int ddaskr_(U_fp res, integer *neq, doublereal *t, 
	doublereal *y, doublereal *yprime, doublereal *tout, integer *info, 
	doublereal *rtol, doublereal *atol, integer *idid, doublereal *rwork, 
	integer *lrw, integer *iwork, integer *liw, doublereal *rpar, integer 
	*ipar, U_fp jac, U_fp psol, U_fp rt, integer *nrt, integer *jroot)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ void s_copy(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal), d_sign(
	    doublereal *, doublereal *);

    /* Local variables */
    static doublereal h__;
    static integer i__;
    static doublereal r__, h0;
    static integer le;
    static doublereal rh, tn;
    static integer lr0, lr1, ici, idi, lid, ier;
    static char msg[80];
    static integer lwm, irt, lvt, lwt, lrx, nwt, nli0, nni0;
    static logical lcfl, lcfn, done;
    static doublereal rcfl;
    static integer nnid;
    static logical lavl;
    static integer maxl, iret;
    static doublereal hmax;
    static integer lphi;
    static doublereal hmin;
    static integer lyic, lpwk, nstd;
    static doublereal rcfn;
    static integer ncfl0, ncfn0;
    extern /* Subroutine */ int dnedd_();
    static integer mband;
    extern /* Subroutine */ int dnedk_();
    static integer lenic, lenid, ncphi, lenpd, lsoff, msave, index, itemp, 
	    leniw, nzflg;
    static doublereal atoli;
    static integer lypic;
    static logical lwarn;
    static integer lenwp, lenrw, mxord, nwarn;
    static doublereal rtoli;
    static integer lsavr;
    extern doublereal d1mach_(integer *);
    static doublereal tdist, tnext, avlin, fmaxl, tstop;
    extern /* Subroutine */ int ddstp_(doublereal *, doublereal *, doublereal 
	    *, integer *, U_fp, U_fp, U_fp, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, integer *, integer *,
	     integer *, U_fp), dcnst0_(integer *, doublereal *, integer *, 
	    integer *), ddasic_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *, U_fp, U_fp, U_fp, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, U_fp)
	    ;
    extern /* Subroutine */ int ddasid_(), ddasik_();
    extern /* Subroutine */ int drchek_(integer *, U_fp, integer *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, integer *, integer *, doublereal *, integer *, 
	    doublereal *, integer *, doublereal *, integer *);
    static integer icnflg;
    static doublereal tscale, epconi;
    extern /* Subroutine */ int ddatrp_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *);
    static doublereal floatn;
    static integer nonneg;
    extern /* Subroutine */ int ddawts_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer leniwp;
    extern /* Subroutine */ int xerrwd_(char *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, ftnlen), dinvwt_(integer *, doublereal *, integer *)
	    ;
    static doublereal uround, ypnorm;


/* ***BEGIN PROLOGUE  DDASKR */
/* ***REVISION HISTORY  (YYMMDD) */
/*   020815  DATE WRITTEN */
/*   021105  Changed yprime argument in DRCHEK calls to YPRIME. */
/*   021217  Modified error return for zeros found too close together. */
/*   021217  Added root direction output in JROOT. */
/*   040518  Changed adjustment to X2 in Subr. DROOTS. */
/*   050511  Revised stopping tests in statements 530 - 580; reordered */
/*           to test for tn at tstop before testing for tn past tout. */
/*   060712  In DMATD, changed minimum D.Q. increment to 1/EWT(j). */
/*   071003  In DRCHEK, fixed bug in TEMP2 (HMINR) below 110. */
/*   110608  In DRCHEK, fixed bug in setting of T1 at 300. */
/* ***CATEGORY NO.  I1A2 */
/* ***KEYWORDS  DIFFERENTIAL/ALGEBRAIC, BACKWARD DIFFERENTIATION FORMULAS, */
/*             IMPLICIT DIFFERENTIAL SYSTEMS, KRYLOV ITERATION */
/* ***AUTHORS   Linda R. Petzold, Peter N. Brown, Alan C. Hindmarsh, and */
/*                  Clement W. Ulrich */
/*             Center for Computational Sciences & Engineering, L-316 */
/*             Lawrence Livermore National Laboratory */
/*             P.O. Box 808, */
/*             Livermore, CA 94551 */
/* ***PURPOSE  This code solves a system of differential/algebraic */
/*            equations of the form */
/*               G(t,y,y') = 0 , */
/*            using a combination of Backward Differentiation Formula */
/*            (BDF) methods and a choice of two linear system solution */
/*            methods: direct (dense or band) or Krylov (iterative). */
/*            This version is in double precision. */
/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* *Usage: */

/*      IMPLICIT DOUBLE PRECISION(A-H,O-Z) */
/*      INTEGER NEQ, INFO(N), IDID, LRW, LIW, IWORK(LIW), IPAR(*) */
/*      DOUBLE PRECISION T, Y(*), YPRIME(*), TOUT, RTOL(*), ATOL(*), */
/*         RWORK(LRW), RPAR(*) */
/*      EXTERNAL RES, JAC, PSOL, RT */

/*      CALL DDASKR (RES, NEQ, T, Y, YPRIME, TOUT, INFO, RTOL, ATOL, */
/*     *             IDID, RWORK, LRW, IWORK, LIW, RPAR, IPAR, JAC, PSOL, */
/*     *             RT, NRT, JROOT) */

/*  Quantities which may be altered by the code are: */
/*     T, Y(*), YPRIME(*), INFO(1), RTOL, ATOL, IDID, RWORK(*), IWORK(*) */


/* *Arguments: */

/*  RES:EXT          This is the name of a subroutine which you */
/*                   provide to define the residual function G(t,y,y') */
/*                   of the differential/algebraic system. */

/*  NEQ:IN           This is the number of equations in the system. */

/*  T:INOUT          This is the current value of the independent */
/*                   variable. */

/*  Y(*):INOUT       This array contains the solution components at T. */

/*  YPRIME(*):INOUT  This array contains the derivatives of the solution */
/*                   components at T. */

/*  TOUT:IN          This is a point at which a solution is desired. */

/*  INFO(N):IN       This is an integer array used to communicate details */
/*                   of how the solution is to be carried out, such as */
/*                   tolerance type, matrix structure, step size and */
/*                   order limits, and choice of nonlinear system method. */
/*                   N must be at least 20. */

/*  RTOL,ATOL:INOUT  These quantities represent absolute and relative */
/*                   error tolerances (on local error) which you provide */
/*                   to indicate how accurately you wish the solution to */
/*                   be computed.  You may choose them to be both scalars */
/*                   or else both arrays of length NEQ. */

/*  IDID:OUT         This integer scalar is an indicator reporting what */
/*                   the code did.  You must monitor this variable to */
/*                   decide what action to take next. */

/*  RWORK:WORK       A real work array of length LRW which provides the */
/*                   code with needed storage space. */

/*  LRW:IN           The length of RWORK. */

/*  IWORK:WORK       An integer work array of length LIW which provides */
/*                   the code with needed storage space. */

/*  LIW:IN           The length of IWORK. */

/*  RPAR,IPAR:IN     These are real and integer parameter arrays which */
/*                   you can use for communication between your calling */
/*                   program and the RES, JAC, and PSOL subroutines. */

/*  JAC:EXT          This is the name of a subroutine which you may */
/*                   provide (optionally) for calculating Jacobian */
/*                   (partial derivative) data involved in solving linear */
/*                   systems within DDASKR. */

/*  PSOL:EXT         This is the name of a subroutine which you must */
/*                   provide for solving linear systems if you selected */
/*                   a Krylov method.  The purpose of PSOL is to solve */
/*                   linear systems involving a left preconditioner P. */

/*  RT:EXT           This is the name of the subroutine for defining */
/*                   constraint functions Ri(T,Y,Y')) whose roots are */
/*                   desired during the integration.  This name must be */
/*                   declared external in the calling program. */

/*  NRT:IN           This is the number of constraint functions */
/*                   Ri(T,Y,Y').  If there are no constraints, set */
/*                   NRT = 0, and pass a dummy name for RT. */

/*  JROOT:OUT        This is an integer array of length NRT for output */
/*                   of root information. */

/* *Overview */

/*  The DDASKR solver uses the backward differentiation formulas of */
/*  orders one through five to solve a system of the form G(t,y,y') = 0 */
/*  for y = Y and y' = YPRIME.  Values for Y and YPRIME at the initial */
/*  time must be given as input.  These values should be consistent, */
/*  that is, if T, Y, YPRIME are the given initial values, they should */
/*  satisfy G(T,Y,YPRIME) = 0.  However, if consistent values are not */
/*  known, in many cases you can have DDASKR solve for them -- see */
/*  INFO(11). (This and other options are described in detail below.) */

/*  Normally, DDASKR solves the system from T to TOUT.  It is easy to */
/*  continue the solution to get results at additional TOUT.  This is */
/*  the interval mode of operation.  Intermediate results can also be */
/*  obtained easily by specifying INFO(3). */

/*  On each step taken by DDASKR, a sequence of nonlinear algebraic */
/*  systems arises.  These are solved by one of two types of */
/*  methods: */
/*    * a Newton iteration with a direct method for the linear */
/*      systems involved (INFO(12) = 0), or */
/*    * a Newton iteration with a preconditioned Krylov iterative */
/*      method for the linear systems involved (INFO(12) = 1). */

/*  The direct method choices are dense and band matrix solvers, */
/*  with either a user-supplied or an internal difference quotient */
/*  Jacobian matrix, as specified by INFO(5) and INFO(6). */
/*  In the band case, INFO(6) = 1, you must supply half-bandwidths */
/*  in IWORK(1) and IWORK(2). */

/*  The Krylov method is the Generalized Minimum Residual (GMRES) */
/*  method, in either complete or incomplete form, and with */
/*  scaling and preconditioning.  The method is implemented */
/*  in an algorithm called SPIGMR.  Certain options in the Krylov */
/*  method case are specified by INFO(13) and INFO(15). */

/*  If the Krylov method is chosen, you may supply a pair of routines, */
/*  JAC and PSOL, to apply preconditioning to the linear system. */
/*  If the system is A*x = b, the matrix is A = dG/dY + CJ*dG/dYPRIME */
/*  (of order NEQ).  This system can then be preconditioned in the form */
/*  (P-inverse)*A*x = (P-inverse)*b, with left preconditioner P. */
/*  (DDASKR does not allow right preconditioning.) */
/*  Then the Krylov method is applied to this altered, but equivalent, */
/*  linear system, hopefully with much better performance than without */
/*  preconditioning.  (In addition, a diagonal scaling matrix based on */
/*  the tolerances is also introduced into the altered system.) */

/*  The JAC routine evaluates any data needed for solving systems */
/*  with coefficient matrix P, and PSOL carries out that solution. */
/*  In any case, in order to improve convergence, you should try to */
/*  make P approximate the matrix A as much as possible, while keeping */
/*  the system P*x = b reasonably easy and inexpensive to solve for x, */
/*  given a vector b. */

/*  While integrating the given DAE system, DDASKR also searches for */
/*  roots of the given constraint functions Ri(T,Y,Y') given by RT. */
/*  If DDASKR detects a sign change in any Ri(T,Y,Y'), it will return */
/*  the intermediate value of T and Y for which Ri(T,Y,Y') = 0. */
/*  Caution: If some Ri has a root at or very near the initial time, */
/*  DDASKR may fail to find it, or may find extraneous roots there, */
/*  because it does not yet have a sufficient history of the solution. */

/* *Description */

/* ------INPUT - WHAT TO DO ON THE FIRST CALL TO DDASKR------------------- */


/*  The first call of the code is defined to be the start of each new */
/*  problem.  Read through the descriptions of all the following items, */
/*  provide sufficient storage space for designated arrays, set */
/*  appropriate variables for the initialization of the problem, and */
/*  give information about how you want the problem to be solved. */


/*  RES -- Provide a subroutine of the form */

/*             SUBROUTINE RES (T, Y, YPRIME, CJ, DELTA, IRES, RPAR, IPAR) */

/*         to define the system of differential/algebraic */
/*         equations which is to be solved. For the given values */
/*         of T, Y and YPRIME, the subroutine should return */
/*         the residual of the differential/algebraic system */
/*             DELTA = G(T,Y,YPRIME) */
/*         DELTA is a vector of length NEQ which is output from RES. */

/*         Subroutine RES must not alter T, Y, YPRIME, or CJ. */
/*         You must declare the name RES in an EXTERNAL */
/*         statement in your program that calls DDASKR. */
/*         You must dimension Y, YPRIME, and DELTA in RES. */

/*         The input argument CJ can be ignored, or used to rescale */
/*         constraint equations in the system (see Ref. 2, p. 145). */
/*         Note: In this respect, DDASKR is not downward-compatible */
/*         with DDASSL, which does not have the RES argument CJ. */

/*         IRES is an integer flag which is always equal to zero */
/*         on input.  Subroutine RES should alter IRES only if it */
/*         encounters an illegal value of Y or a stop condition. */
/*         Set IRES = -1 if an input value is illegal, and DDASKR */
/*         will try to solve the problem without getting IRES = -1. */
/*         If IRES = -2, DDASKR will return control to the calling */
/*         program with IDID = -11. */

/*         RPAR and IPAR are real and integer parameter arrays which */
/*         you can use for communication between your calling program */
/*         and subroutine RES. They are not altered by DDASKR. If you */
/*         do not need RPAR or IPAR, ignore these parameters by treat- */
/*         ing them as dummy arguments. If you do choose to use them, */
/*         dimension them in your calling program and in RES as arrays */
/*         of appropriate length. */

/*  NEQ -- Set it to the number of equations in the system (NEQ .GE. 1). */

/*  T -- Set it to the initial point of the integration. (T must be */
/*       a variable.) */

/*  Y(*) -- Set this array to the initial values of the NEQ solution */
/*          components at the initial point.  You must dimension Y of */
/*          length at least NEQ in your calling program. */

/*  YPRIME(*) -- Set this array to the initial values of the NEQ first */
/*               derivatives of the solution components at the initial */
/*               point.  You must dimension YPRIME at least NEQ in your */
/*               calling program. */

/*  TOUT - Set it to the first point at which a solution is desired. */
/*         You cannot take TOUT = T.  Integration either forward in T */
/*         (TOUT .GT. T) or backward in T (TOUT .LT. T) is permitted. */

/*         The code advances the solution from T to TOUT using step */
/*         sizes which are automatically selected so as to achieve the */
/*         desired accuracy.  If you wish, the code will return with the */
/*         solution and its derivative at intermediate steps (the */
/*         intermediate-output mode) so that you can monitor them, */
/*         but you still must provide TOUT in accord with the basic */
/*         aim of the code. */

/*         The first step taken by the code is a critical one because */
/*         it must reflect how fast the solution changes near the */
/*         initial point.  The code automatically selects an initial */
/*         step size which is practically always suitable for the */
/*         problem.  By using the fact that the code will not step past */
/*         TOUT in the first step, you could, if necessary, restrict the */
/*         length of the initial step. */

/*         For some problems it may not be permissible to integrate */
/*         past a point TSTOP, because a discontinuity occurs there */
/*         or the solution or its derivative is not defined beyond */
/*         TSTOP.  When you have declared a TSTOP point (see INFO(4) */
/*         and RWORK(1)), you have told the code not to integrate past */
/*         TSTOP.  In this case any tout beyond TSTOP is invalid input. */

/*  INFO(*) - Use the INFO array to give the code more details about */
/*            how you want your problem solved.  This array should be */
/*            dimensioned of length 20, though DDASKR uses only the */
/*            first 15 entries.  You must respond to all of the following */
/*            items, which are arranged as questions.  The simplest use */
/*            of DDASKR corresponds to setting all entries of INFO to 0. */

/*       INFO(1) - This parameter enables the code to initialize itself. */
/*              You must set it to indicate the start of every new */
/*              problem. */

/*          **** Is this the first call for this problem ... */
/*                yes - set INFO(1) = 0 */
/*                 no - not applicable here. */
/*                      See below for continuation calls.  **** */

/*       INFO(2) - How much accuracy you want of your solution */
/*              is specified by the error tolerances RTOL and ATOL. */
/*              The simplest use is to take them both to be scalars. */
/*              To obtain more flexibility, they can both be arrays. */
/*              The code must be told your choice. */

/*          **** Are both error tolerances RTOL, ATOL scalars ... */
/*                yes - set INFO(2) = 0 */
/*                      and input scalars for both RTOL and ATOL */
/*                 no - set INFO(2) = 1 */
/*                      and input arrays for both RTOL and ATOL **** */

/*       INFO(3) - The code integrates from T in the direction of TOUT */
/*              by steps.  If you wish, it will return the computed */
/*              solution and derivative at the next intermediate step */
/*              (the intermediate-output mode) or TOUT, whichever comes */
/*              first.  This is a good way to proceed if you want to */
/*              see the behavior of the solution.  If you must have */
/*              solutions at a great many specific TOUT points, this */
/*              code will compute them efficiently. */

/*          **** Do you want the solution only at */
/*               TOUT (and not at the next intermediate step) ... */
/*                yes - set INFO(3) = 0 (interval-output mode) */
/*                 no - set INFO(3) = 1 (intermediate-output mode) **** */

/*       INFO(4) - To handle solutions at a great many specific */
/*              values TOUT efficiently, this code may integrate past */
/*              TOUT and interpolate to obtain the result at TOUT. */
/*              Sometimes it is not possible to integrate beyond some */
/*              point TSTOP because the equation changes there or it is */
/*              not defined past TSTOP.  Then you must tell the code */
/*              this stop condition. */

/*           **** Can the integration be carried out without any */
/*                restrictions on the independent variable T ... */
/*                 yes - set INFO(4) = 0 */
/*                  no - set INFO(4) = 1 */
/*                       and define the stopping point TSTOP by */
/*                       setting RWORK(1) = TSTOP **** */

/*       INFO(5) - used only when INFO(12) = 0 (direct methods). */
/*              To solve differential/algebraic systems you may wish */
/*              to use a matrix of partial derivatives of the */
/*              system of differential equations.  If you do not */
/*              provide a subroutine to evaluate it analytically (see */
/*              description of the item JAC in the call list), it will */
/*              be approximated by numerical differencing in this code. */
/*              Although it is less trouble for you to have the code */
/*              compute partial derivatives by numerical differencing, */
/*              the solution will be more reliable if you provide the */
/*              derivatives via JAC.  Usually numerical differencing is */
/*              more costly than evaluating derivatives in JAC, but */
/*              sometimes it is not - this depends on your problem. */

/*           **** Do you want the code to evaluate the partial deriv- */
/*                atives automatically by numerical differences ... */
/*                 yes - set INFO(5) = 0 */
/*                  no - set INFO(5) = 1 */
/*                       and provide subroutine JAC for evaluating the */
/*                       matrix of partial derivatives **** */

/*       INFO(6) - used only when INFO(12) = 0 (direct methods). */
/*              DDASKR will perform much better if the matrix of */
/*              partial derivatives, dG/dY + CJ*dG/dYPRIME (here CJ is */
/*              a scalar determined by DDASKR), is banded and the code */
/*              is told this.  In this case, the storage needed will be */
/*              greatly reduced, numerical differencing will be performed */
/*              much cheaper, and a number of important algorithms will */
/*              execute much faster.  The differential equation is said */
/*              to have half-bandwidths ML (lower) and MU (upper) if */
/*              equation i involves only unknowns Y(j) with */
/*                             i-ML .le. j .le. i+MU . */
/*              For all i=1,2,...,NEQ.  Thus, ML and MU are the widths */
/*              of the lower and upper parts of the band, respectively, */
/*              with the main diagonal being excluded.  If you do not */
/*              indicate that the equation has a banded matrix of partial */
/*              derivatives the code works with a full matrix of NEQ**2 */
/*              elements (stored in the conventional way).  Computations */
/*              with banded matrices cost less time and storage than with */
/*              full matrices if  2*ML+MU .lt. NEQ.  If you tell the */
/*              code that the matrix of partial derivatives has a banded */
/*              structure and you want to provide subroutine JAC to */
/*              compute the partial derivatives, then you must be careful */
/*              to store the elements of the matrix in the special form */
/*              indicated in the description of JAC. */

/*          **** Do you want to solve the problem using a full (dense) */
/*               matrix (and not a special banded structure) ... */
/*                yes - set INFO(6) = 0 */
/*                 no - set INFO(6) = 1 */
/*                       and provide the lower (ML) and upper (MU) */
/*                       bandwidths by setting */
/*                       IWORK(1)=ML */
/*                       IWORK(2)=MU **** */

/*       INFO(7) - You can specify a maximum (absolute value of) */
/*              stepsize, so that the code will avoid passing over very */
/*              large regions. */

/*          ****  Do you want the code to decide on its own the maximum */
/*                stepsize ... */
/*                 yes - set INFO(7) = 0 */
/*                  no - set INFO(7) = 1 */
/*                       and define HMAX by setting */
/*                       RWORK(2) = HMAX **** */

/*       INFO(8) -  Differential/algebraic problems may occasionally */
/*              suffer from severe scaling difficulties on the first */
/*              step.  If you know a great deal about the scaling of */
/*              your problem, you can help to alleviate this problem */
/*              by specifying an initial stepsize H0. */

/*          ****  Do you want the code to define its own initial */
/*                stepsize ... */
/*                 yes - set INFO(8) = 0 */
/*                  no - set INFO(8) = 1 */
/*                       and define H0 by setting */
/*                       RWORK(3) = H0 **** */

/*       INFO(9) -  If storage is a severe problem, you can save some */
/*              storage by restricting the maximum method order MAXORD. */
/*              The default value is 5.  For each order decrease below 5, */
/*              the code requires NEQ fewer locations, but it is likely */
/*              to be slower.  In any case, you must have */
/*              1 .le. MAXORD .le. 5. */
/*          ****  Do you want the maximum order to default to 5 ... */
/*                 yes - set INFO(9) = 0 */
/*                  no - set INFO(9) = 1 */
/*                       and define MAXORD by setting */
/*                       IWORK(3) = MAXORD **** */

/*       INFO(10) - If you know that certain components of the */
/*              solutions to your equations are always nonnegative */
/*              (or nonpositive), it may help to set this */
/*              parameter.  There are three options that are */
/*              available: */
/*              1.  To have constraint checking only in the initial */
/*                  condition calculation. */
/*              2.  To enforce nonnegativity in Y during the integration. */
/*              3.  To enforce both options 1 and 2. */

/*              When selecting option 2 or 3, it is probably best to try */
/*              the code without using this option first, and only use */
/*              this option if that does not work very well. */

/*          ****  Do you want the code to solve the problem without */
/*                invoking any special inequality constraints ... */
/*                 yes - set INFO(10) = 0 */
/*                  no - set INFO(10) = 1 to have option 1 enforced */
/*                  no - set INFO(10) = 2 to have option 2 enforced */
/*                  no - set INFO(10) = 3 to have option 3 enforced **** */

/*                  If you have specified INFO(10) = 1 or 3, then you */
/*                  will also need to identify how each component of Y */
/*                  in the initial condition calculation is constrained. */
/*                  You must set: */
/*                  IWORK(40+I) = +1 if Y(I) must be .GE. 0, */
/*                  IWORK(40+I) = +2 if Y(I) must be .GT. 0, */
/*                  IWORK(40+I) = -1 if Y(I) must be .LE. 0, while */
/*                  IWORK(40+I) = -2 if Y(I) must be .LT. 0, while */
/*                  IWORK(40+I) =  0 if Y(I) is not constrained. */

/*       INFO(11) - DDASKR normally requires the initial T, Y, and */
/*              YPRIME to be consistent.  That is, you must have */
/*              G(T,Y,YPRIME) = 0 at the initial T.  If you do not know */
/*              the initial conditions precisely, in some cases */
/*              DDASKR may be able to compute it. */

/*              Denoting the differential variables in Y by Y_d */
/*              and the algebraic variables by Y_a, DDASKR can solve */
/*              one of two initialization problems: */
/*              1.  Given Y_d, calculate Y_a and Y'_d, or */
/*              2.  Given Y', calculate Y. */
/*              In either case, initial values for the given */
/*              components are input, and initial guesses for */
/*              the unknown components must also be provided as input. */

/*          ****  Are the initial T, Y, YPRIME consistent ... */

/*                 yes - set INFO(11) = 0 */
/*                  no - set INFO(11) = 1 to calculate option 1 above, */
/*                    or set INFO(11) = 2 to calculate option 2 **** */

/*                  If you have specified INFO(11) = 1, then you */
/*                  will also need to identify  which are the */
/*                  differential and which are the algebraic */
/*                  components (algebraic components are components */
/*                  whose derivatives do not appear explicitly */
/*                  in the function G(T,Y,YPRIME)).  You must set: */
/*                  IWORK(LID+I) = +1 if Y(I) is a differential variable */
/*                  IWORK(LID+I) = -1 if Y(I) is an algebraic variable, */
/*                  where LID = 40 if INFO(10) = 0 or 2 and LID = 40+NEQ */
/*                  if INFO(10) = 1 or 3. */

/*       INFO(12) - Except for the addition of the RES argument CJ, */
/*              DDASKR by default is downward-compatible with DDASSL, */
/*              which uses only direct (dense or band) methods to solve */
/*              the linear systems involved.  You must set INFO(12) to */
/*              indicate whether you want the direct methods or the */
/*              Krylov iterative method. */
/*          ****   Do you want DDASKR to use standard direct methods */
/*                 (dense or band) or the Krylov (iterative) method ... */
/*                   direct methods - set INFO(12) = 0. */
/*                   Krylov method  - set INFO(12) = 1, */
/*                       and check the settings of INFO(13) and INFO(15). */

/*       INFO(13) - used when INFO(12) = 1 (Krylov methods). */
/*              DDASKR uses scalars MAXL, KMP, NRMAX, and EPLI for the */
/*              iterative solution of linear systems.  INFO(13) allows */
/*              you to override the default values of these parameters. */
/*              These parameters and their defaults are as follows: */
/*              MAXL = maximum number of iterations in the SPIGMR */
/*                 algorithm (MAXL .le. NEQ).  The default is */
/*                 MAXL = MIN(5,NEQ). */
/*              KMP = number of vectors on which orthogonalization is */
/*                 done in the SPIGMR algorithm.  The default is */
/*                 KMP = MAXL, which corresponds to complete GMRES */
/*                 iteration, as opposed to the incomplete form. */
/*              NRMAX = maximum number of restarts of the SPIGMR */
/*                 algorithm per nonlinear iteration.  The default is */
/*                 NRMAX = 5. */
/*              EPLI = convergence test constant in SPIGMR algorithm. */
/*                 The default is EPLI = 0.05. */
/*              Note that the length of RWORK depends on both MAXL */
/*              and KMP.  See the definition of LRW below. */
/*          ****   Are MAXL, KMP, and EPLI to be given their */
/*                 default values ... */
/*                  yes - set INFO(13) = 0 */
/*                   no - set INFO(13) = 1, */
/*                        and set all of the following: */
/*                        IWORK(24) = MAXL (1 .le. MAXL .le. NEQ) */
/*                        IWORK(25) = KMP  (1 .le. KMP .le. MAXL) */
/*                        IWORK(26) = NRMAX  (NRMAX .ge. 0) */
/*                        RWORK(10) = EPLI (0 .lt. EPLI .lt. 1.0) **** */

/*        INFO(14) - used with INFO(11) > 0 (initial condition */
/*               calculation is requested).  In this case, you may */
/*               request control to be returned to the calling program */
/*               immediately after the initial condition calculation, */
/*               before proceeding to the integration of the system */
/*               (e.g. to examine the computed Y and YPRIME). */
/*               If this is done, and if the initialization succeeded */
/*               (IDID = 4), you should reset INFO(11) to 0 for the */
/*               next call, to prevent the solver from repeating the */
/*               initialization (and to avoid an infinite loop). */
/*          ****   Do you want to proceed to the integration after */
/*                 the initial condition calculation is done ... */
/*                 yes - set INFO(14) = 0 */
/*                  no - set INFO(14) = 1                        **** */

/*        INFO(15) - used when INFO(12) = 1 (Krylov methods). */
/*               When using preconditioning in the Krylov method, */
/*               you must supply a subroutine, PSOL, which solves the */
/*               associated linear systems using P. */
/*               The usage of DDASKR is simpler if PSOL can carry out */
/*               the solution without any prior calculation of data. */
/*               However, if some partial derivative data is to be */
/*               calculated in advance and used repeatedly in PSOL, */
/*               then you must supply a JAC routine to do this, */
/*               and set INFO(15) to indicate that JAC is to be called */
/*               for this purpose.  For example, P might be an */
/*               approximation to a part of the matrix A which can be */
/*               calculated and LU-factored for repeated solutions of */
/*               the preconditioner system.  The arrays WP and IWP */
/*               (described under JAC and PSOL) can be used to */
/*               communicate data between JAC and PSOL. */
/*          ****   Does PSOL operate with no prior preparation ... */
/*                 yes - set INFO(15) = 0 (no JAC routine) */
/*                  no - set INFO(15) = 1 */
/*                       and supply a JAC routine to evaluate and */
/*                       preprocess any required Jacobian data.  **** */

/*         INFO(16) - option to exclude algebraic variables from */
/*               the error test. */
/*          ****   Do you wish to control errors locally on */
/*                 all the variables... */
/*                 yes - set INFO(16) = 0 */
/*                  no - set INFO(16) = 1 */
/*                       If you have specified INFO(16) = 1, then you */
/*                       will also need to identify  which are the */
/*                       differential and which are the algebraic */
/*                       components (algebraic components are components */
/*                       whose derivatives do not appear explicitly */
/*                       in the function G(T,Y,YPRIME)).  You must set: */
/*                       IWORK(LID+I) = +1 if Y(I) is a differential */
/*                                      variable, and */
/*                       IWORK(LID+I) = -1 if Y(I) is an algebraic */
/*                                      variable, */
/*                       where LID = 40 if INFO(10) = 0 or 2 and */
/*                       LID = 40 + NEQ if INFO(10) = 1 or 3. */

/*       INFO(17) - used when INFO(11) > 0 (DDASKR is to do an */
/*              initial condition calculation). */
/*              DDASKR uses several heuristic control quantities in the */
/*              initial condition calculation.  They have default values, */
/*              but can  also be set by the user using INFO(17). */
/*              These parameters and their defaults are as follows: */
/*              MXNIT  = maximum number of Newton iterations */
/*                 per Jacobian or preconditioner evaluation. */
/*                 The default is: */
/*                 MXNIT =  5 in the direct case (INFO(12) = 0), and */
/*                 MXNIT = 15 in the Krylov case (INFO(12) = 1). */
/*              MXNJ   = maximum number of Jacobian or preconditioner */
/*                 evaluations.  The default is: */
/*                 MXNJ = 6 in the direct case (INFO(12) = 0), and */
/*                 MXNJ = 2 in the Krylov case (INFO(12) = 1). */
/*              MXNH   = maximum number of values of the artificial */
/*                 stepsize parameter H to be tried if INFO(11) = 1. */
/*                 The default is MXNH = 5. */
/*                 NOTE: the maximum number of Newton iterations */
/*                 allowed in all is MXNIT*MXNJ*MXNH if INFO(11) = 1, */
/*                 and MXNIT*MXNJ if INFO(11) = 2. */
/*              LSOFF  = flag to turn off the linesearch algorithm */
/*                 (LSOFF = 0 means linesearch is on, LSOFF = 1 means */
/*                 it is turned off).  The default is LSOFF = 0. */
/*              STPTOL = minimum scaled step in linesearch algorithm. */
/*                 The default is STPTOL = (unit roundoff)**(2/3). */
/*              EPINIT = swing factor in the Newton iteration convergence */
/*                 test.  The test is applied to the residual vector, */
/*                 premultiplied by the approximate Jacobian (in the */
/*                 direct case) or the preconditioner (in the Krylov */
/*                 case).  For convergence, the weighted RMS norm of */
/*                 this vector (scaled by the error weights) must be */
/*                 less than EPINIT*EPCON, where EPCON = .33 is the */
/*                 analogous test constant used in the time steps. */
/*                 The default is EPINIT = .01. */
/*          ****   Are the initial condition heuristic controls to be */
/*                 given their default values... */
/*                  yes - set INFO(17) = 0 */
/*                   no - set INFO(17) = 1, */
/*                        and set all of the following: */
/*                        IWORK(32) = MXNIT (.GT. 0) */
/*                        IWORK(33) = MXNJ (.GT. 0) */
/*                        IWORK(34) = MXNH (.GT. 0) */
/*                        IWORK(35) = LSOFF ( = 0 or 1) */
/*                        RWORK(14) = STPTOL (.GT. 0.0) */
/*                        RWORK(15) = EPINIT (.GT. 0.0)  **** */

/*         INFO(18) - option to get extra printing in initial condition */
/*                calculation. */
/*          ****   Do you wish to have extra printing... */
/*                 no  - set INFO(18) = 0 */
/*                 yes - set INFO(18) = 1 for minimal printing, or */
/*                       set INFO(18) = 2 for full printing. */
/*                       If you have specified INFO(18) .ge. 1, data */
/*                       will be printed with the error handler routines. */
/*                       To print to a non-default unit number L, include */
/*                       the line  CALL XSETUN(L)  in your program.  **** */

/*   RTOL, ATOL -- You must assign relative (RTOL) and absolute (ATOL) */
/*               error tolerances to tell the code how accurately you */
/*               want the solution to be computed.  They must be defined */
/*               as variables because the code may change them. */
/*               you have two choices -- */
/*                     Both RTOL and ATOL are scalars (INFO(2) = 0), or */
/*                     both RTOL and ATOL are vectors (INFO(2) = 1). */
/*               In either case all components must be non-negative. */

/*               The tolerances are used by the code in a local error */
/*               test at each step which requires roughly that */
/*                        abs(local error in Y(i)) .le. EWT(i) , */
/*               where EWT(i) = RTOL*abs(Y(i)) + ATOL is an error weight */
/*               quantity, for each vector component. */
/*               (More specifically, a root-mean-square norm is used to */
/*               measure the size of vectors, and the error test uses the */
/*               magnitude of the solution at the beginning of the step.) */

/*               The true (global) error is the difference between the */
/*               true solution of the initial value problem and the */
/*               computed approximation.  Practically all present day */
/*               codes, including this one, control the local error at */
/*               each step and do not even attempt to control the global */
/*               error directly. */

/*               Usually, but not always, the true accuracy of */
/*               the computed Y is comparable to the error tolerances. */
/*               This code will usually, but not always, deliver a more */
/*               accurate solution if you reduce the tolerances and */
/*               integrate again.  By comparing two such solutions you */
/*               can get a fairly reliable idea of the true error in the */
/*               solution at the larger tolerances. */

/*               Setting ATOL = 0. results in a pure relative error test */
/*               on that component.  Setting RTOL = 0. results in a pure */
/*               absolute error test on that component.  A mixed test */
/*               with non-zero RTOL and ATOL corresponds roughly to a */
/*               relative error test when the solution component is */
/*               much bigger than ATOL and to an absolute error test */
/*               when the solution component is smaller than the */
/*               threshold ATOL. */

/*               The code will not attempt to compute a solution at an */
/*               accuracy unreasonable for the machine being used.  It */
/*               will advise you if you ask for too much accuracy and */
/*               inform you as to the maximum accuracy it believes */
/*               possible. */

/*  RWORK(*) -- a real work array, which should be dimensioned in your */
/*               calling program with a length equal to the value of */
/*               LRW (or greater). */

/*  LRW -- Set it to the declared length of the RWORK array.  The */
/*               minimum length depends on the options you have selected, */
/*               given by a base value plus additional storage as */
/*               described below. */

/*               If INFO(12) = 0 (standard direct method), the base value */
/*               is BASE = 60 + max(MAXORD+4,7)*NEQ + 3*NRT. */
/*               The default value is MAXORD = 5 (see INFO(9)).  With the */
/*               default MAXORD, BASE = 60 + 9*NEQ + 3*NRT. */
/*               Additional storage must be added to the base value for */
/*               any or all of the following options: */
/*                 If INFO(6) = 0 (dense matrix), add NEQ**2. */
/*                 If INFO(6) = 1 (banded matrix), then: */
/*                    if INFO(5) = 0, add (2*ML+MU+1)*NEQ */
/*                                           + 2*[NEQ/(ML+MU+1) + 1], and */
/*                    if INFO(5) = 1, add (2*ML+MU+1)*NEQ. */
/*                 If INFO(16) = 1, add NEQ. */

/*               If INFO(12) = 1 (Krylov method), the base value is */
/*               BASE = 60 + (MAXORD+5)*NEQ + 3*NRT */
/*                         + [MAXL + 3 + min(1,MAXL-KMP)]*NEQ */
/*                         + (MAXL+3)*MAXL + 1 + LENWP. */
/*               See PSOL for description of LENWP.  The default values */
/*               are: MAXORD = 5 (see INFO(9)), MAXL = min(5,NEQ) and */
/*               KMP = MAXL  (see INFO(13)).  With these default values, */
/*               BASE = 101 + 18*NEQ + 3*NRT + LENWP. */
/*               Additional storage must be added to the base value for */
/*               the following option: */
/*                 If INFO(16) = 1, add NEQ. */


/*  IWORK(*) -- an integer work array, which should be dimensioned in */
/*              your calling program with a length equal to the value */
/*              of LIW (or greater). */

/*  LIW -- Set it to the declared length of the IWORK array.  The */
/*             minimum length depends on the options you have selected, */
/*             given by a base value plus additions as described below. */

/*             If INFO(12) = 0 (standard direct method), the base value */
/*             is BASE = 40 + NEQ. */
/*             IF INFO(10) = 1 or 3, add NEQ to the base value. */
/*             If INFO(11) = 1 or INFO(16) =1, add NEQ to the base value. */

/*             If INFO(12) = 1 (Krylov method), the base value is */
/*             BASE = 40 + LENIWP.  See PSOL for description of LENIWP. */
/*             If INFO(10) = 1 or 3, add NEQ to the base value. */
/*             If INFO(11) = 1 or INFO(16) =1, add NEQ to the base value. */


/*  RPAR, IPAR -- These are arrays of double precision and integer type, */
/*             respectively, which are available for you to use */
/*             for communication between your program that calls */
/*             DDASKR and the RES subroutine (and the JAC and PSOL */
/*             subroutines).  They are not altered by DDASKR. */
/*             If you do not need RPAR or IPAR, ignore these */
/*             parameters by treating them as dummy arguments. */
/*             If you do choose to use them, dimension them in */
/*             your calling program and in RES (and in JAC and PSOL) */
/*             as arrays of appropriate length. */

/*  JAC -- This is the name of a routine that you may supply */
/*         (optionally) that relates to the Jacobian matrix of the */
/*         nonlinear system that the code must solve at each T step. */
/*         The role of JAC (and its call sequence) depends on whether */
/*         a direct (INFO(12) = 0) or Krylov (INFO(12) = 1) method */
/*         is selected. */

/*         **** INFO(12) = 0 (direct methods): */
/*           If you are letting the code generate partial derivatives */
/*           numerically (INFO(5) = 0), then JAC can be absent */
/*           (or perhaps a dummy routine to satisfy the loader). */
/*           Otherwise you must supply a JAC routine to compute */
/*           the matrix A = dG/dY + CJ*dG/dYPRIME.  It must have */
/*           the form */

/*           SUBROUTINE JAC (T, Y, YPRIME, PD, CJ, RPAR, IPAR) */

/*           The JAC routine must dimension Y, YPRIME, and PD (and RPAR */
/*           and IPAR if used).  CJ is a scalar which is input to JAC. */
/*           For the given values of T, Y, and YPRIME, the JAC routine */
/*           must evaluate the nonzero elements of the matrix A, and */
/*           store these values in the array PD.  The elements of PD are */
/*           set to zero before each call to JAC, so that only nonzero */
/*           elements need to be defined. */
/*           The way you store the elements into the PD array depends */
/*           on the structure of the matrix indicated by INFO(6). */
/*           *** INFO(6) = 0 (full or dense matrix) *** */
/*               Give PD a first dimension of NEQ.  When you evaluate the */
/*               nonzero partial derivatives of equation i (i.e. of G(i)) */
/*               with respect to component j (of Y and YPRIME), you must */
/*               store the element in PD according to */
/*                  PD(i,j) = dG(i)/dY(j) + CJ*dG(i)/dYPRIME(j). */
/*           *** INFO(6) = 1 (banded matrix with half-bandwidths ML, MU */
/*                            as described under INFO(6)) *** */
/*               Give PD a first dimension of 2*ML+MU+1.  When you */
/*               evaluate the nonzero partial derivatives of equation i */
/*               (i.e. of G(i)) with respect to component j (of Y and */
/*               YPRIME), you must store the element in PD according to */
/*                  IROW = i - j + ML + MU + 1 */
/*                  PD(IROW,j) = dG(i)/dY(j) + CJ*dG(i)/dYPRIME(j). */

/*          **** INFO(12) = 1 (Krylov method): */
/*            If you are not calculating Jacobian data in advance for use */
/*            in PSOL (INFO(15) = 0), JAC can be absent (or perhaps a */
/*            dummy routine to satisfy the loader).  Otherwise, you may */
/*            supply a JAC routine to compute and preprocess any parts of */
/*            of the Jacobian matrix  A = dG/dY + CJ*dG/dYPRIME that are */
/*            involved in the preconditioner matrix P. */
/*            It is to have the form */

/*            SUBROUTINE JAC (RES, IRES, NEQ, T, Y, YPRIME, REWT, SAVR, */
/*                            WK, H, CJ, WP, IWP, IER, RPAR, IPAR) */

/*           The JAC routine must dimension Y, YPRIME, REWT, SAVR, WK, */
/*           and (if used) WP, IWP, RPAR, and IPAR. */
/*           The Y, YPRIME, and SAVR arrays contain the current values */
/*           of Y, YPRIME, and the residual G, respectively. */
/*           The array WK is work space of length NEQ. */
/*           H is the step size.  CJ is a scalar, input to JAC, that is */
/*           normally proportional to 1/H.  REWT is an array of */
/*           reciprocal error weights, 1/EWT(i), where EWT(i) is */
/*           RTOL*abs(Y(i)) + ATOL (unless you supplied routine DDAWTS */
/*           instead), for use in JAC if needed.  For example, if JAC */
/*           computes difference quotient approximations to partial */
/*           derivatives, the REWT array may be useful in setting the */
/*           increments used.  The JAC routine should do any */
/*           factorization operations called for, in preparation for */
/*           solving linear systems in PSOL.  The matrix P should */
/*           be an approximation to the Jacobian, */
/*           A = dG/dY + CJ*dG/dYPRIME. */

/*           WP and IWP are real and integer work arrays which you may */
/*           use for communication between your JAC routine and your */
/*           PSOL routine.  These may be used to store elements of the */
/*           preconditioner P, or related matrix data (such as factored */
/*           forms).  They are not altered by DDASKR. */
/*           If you do not need WP or IWP, ignore these parameters by */
/*           treating them as dummy arguments.  If you do use them, */
/*           dimension them appropriately in your JAC and PSOL routines. */
/*           See the PSOL description for instructions on setting */
/*           the lengths of WP and IWP. */

/*           On return, JAC should set the error flag IER as follows.. */
/*             IER = 0    if JAC was successful, */
/*             IER .ne. 0 if JAC was unsuccessful (e.g. if Y or YPRIME */
/*                        was illegal, or a singular matrix is found). */
/*           (If IER .ne. 0, a smaller stepsize will be tried.) */
/*           IER = 0 on entry to JAC, so need be reset only on a failure. */
/*           If RES is used within JAC, then a nonzero value of IRES will */
/*           override any nonzero value of IER (see the RES description). */

/*         Regardless of the method type, subroutine JAC must not */
/*         alter T, Y(*), YPRIME(*), H, CJ, or REWT(*). */
/*         You must declare the name JAC in an EXTERNAL statement in */
/*         your program that calls DDASKR. */

/* PSOL --  This is the name of a routine you must supply if you have */
/*         selected a Krylov method (INFO(12) = 1) with preconditioning. */
/*         In the direct case (INFO(12) = 0), PSOL can be absent */
/*         (a dummy routine may have to be supplied to satisfy the */
/*         loader).  Otherwise, you must provide a PSOL routine to */
/*         solve linear systems arising from preconditioning. */
/*         When supplied with INFO(12) = 1, the PSOL routine is to */
/*         have the form */

/*         SUBROUTINE PSOL (NEQ, T, Y, YPRIME, SAVR, WK, CJ, WGHT, */
/*                          WP, IWP, B, EPLIN, IER, RPAR, IPAR) */

/*         The PSOL routine must solve linear systems of the form */
/*         P*x = b where P is the left preconditioner matrix. */

/*         The right-hand side vector b is in the B array on input, and */
/*         PSOL must return the solution vector x in B. */
/*         The Y, YPRIME, and SAVR arrays contain the current values */
/*         of Y, YPRIME, and the residual G, respectively. */

/*         Work space required by JAC and/or PSOL, and space for data to */
/*         be communicated from JAC to PSOL is made available in the form */
/*         of arrays WP and IWP, which are parts of the RWORK and IWORK */
/*         arrays, respectively.  The lengths of these real and integer */
/*         work spaces WP and IWP must be supplied in LENWP and LENIWP, */
/*         respectively, as follows.. */
/*           IWORK(27) = LENWP = length of real work space WP */
/*           IWORK(28) = LENIWP = length of integer work space IWP. */

/*         WK is a work array of length NEQ for use by PSOL. */
/*         CJ is a scalar, input to PSOL, that is normally proportional */
/*         to 1/H (H = stepsize).  If the old value of CJ */
/*         (at the time of the last JAC call) is needed, it must have */
/*         been saved by JAC in WP. */

/*         WGHT is an array of weights, to be used if PSOL uses an */
/*         iterative method and performs a convergence test.  (In terms */
/*         of the argument REWT to JAC, WGHT is REWT/sqrt(NEQ).) */
/*         If PSOL uses an iterative method, it should use EPLIN */
/*         (a heuristic parameter) as the bound on the weighted norm of */
/*         the residual for the computed solution.  Specifically, the */
/*         residual vector R should satisfy */
/*              SQRT (SUM ( (R(i)*WGHT(i))**2 ) ) .le. EPLIN */

/*         PSOL must not alter NEQ, T, Y, YPRIME, SAVR, CJ, WGHT, EPLIN. */

/*         On return, PSOL should set the error flag IER as follows.. */
/*           IER = 0 if PSOL was successful, */
/*           IER .lt. 0 if an unrecoverable error occurred, meaning */
/*                 control will be passed to the calling routine, */
/*           IER .gt. 0 if a recoverable error occurred, meaning that */
/*                 the step will be retried with the same step size */
/*                 but with a call to JAC to update necessary data, */
/*                 unless the Jacobian data is current, in which case */
/*                 the step will be retried with a smaller step size. */
/*           IER = 0 on entry to PSOL so need be reset only on a failure. */

/*         You must declare the name PSOL in an EXTERNAL statement in */
/*         your program that calls DDASKR. */

/* RT --   This is the name of the subroutine for defining the vector */
/*         R(T,Y,Y') of constraint functions Ri(T,Y,Y'), whose roots */
/*         are desired during the integration.  It is to have the form */
/*             SUBROUTINE RT(NEQ, T, Y, YP, NRT, RVAL, RPAR, IPAR) */
/*             DIMENSION Y(NEQ), YP(NEQ), RVAL(NRT), */
/*         where NEQ, T, Y and NRT are INPUT, and the array RVAL is */
/*         output.  NEQ, T, Y, and YP have the same meaning as in the */
/*         RES routine, and RVAL is an array of length NRT. */
/*         For i = 1,...,NRT, this routine is to load into RVAL(i) the */
/*         value at (T,Y,Y') of the i-th constraint function Ri(T,Y,Y'). */
/*         DDASKR will find roots of the Ri of odd multiplicity */
/*         (that is, sign changes) as they occur during the integration. */
/*         RT must be declared EXTERNAL in the calling program. */

/*         CAUTION.. Because of numerical errors in the functions Ri */
/*         due to roundoff and integration error, DDASKR may return */
/*         false roots, or return the same root at two or more nearly */
/*         equal values of T.  If such false roots are suspected, */
/*         the user should consider smaller error tolerances and/or */
/*         higher precision in the evaluation of the Ri. */

/*         If a root of some Ri defines the end of the problem, */
/*         the input to DDASKR should nevertheless allow */
/*         integration to a point slightly past that root, so */
/*         that DDASKR can locate the root by interpolation. */

/* NRT --  The number of constraint functions Ri(T,Y,Y').  If there are */
/*         no constraints, set NRT = 0 and pass a dummy name for RT. */

/* JROOT -- This is an integer array of length NRT, used only for output. */
/*         On a return where one or more roots were found (IDID = 5), */
/*         JROOT(i) = 1 or -1 if Ri(T,Y,Y') has a root at T, and */
/*         JROOT(i) = 0 if not.  If nonzero, JROOT(i) shows the direction */
/*         of the sign change in Ri in the direction of integration: */
/*         JROOT(i) = 1  means Ri changed from negative to positive. */
/*         JROOT(i) = -1 means Ri changed from positive to negative. */


/*  OPTIONALLY REPLACEABLE SUBROUTINE: */

/*  DDASKR uses a weighted root-mean-square norm to measure the */
/*  size of various error vectors.  The weights used in this norm */
/*  are set in the following subroutine: */

/*    SUBROUTINE DDAWTS (NEQ, IWT, RTOL, ATOL, Y, EWT, RPAR, IPAR) */
/*    DIMENSION RTOL(*), ATOL(*), Y(*), EWT(*), RPAR(*), IPAR(*) */

/*  A DDAWTS routine has been included with DDASKR which sets the */
/*  weights according to */
/*    EWT(I) = RTOL*ABS(Y(I)) + ATOL */
/*  in the case of scalar tolerances (IWT = 0) or */
/*    EWT(I) = RTOL(I)*ABS(Y(I)) + ATOL(I) */
/*  in the case of array tolerances (IWT = 1).  (IWT is INFO(2).) */
/*  In some special cases, it may be appropriate for you to define */
/*  your own error weights by writing a subroutine DDAWTS to be */
/*  called instead of the version supplied.  However, this should */
/*  be attempted only after careful thought and consideration. */
/*  If you supply this routine, you may use the tolerances and Y */
/*  as appropriate, but do not overwrite these variables.  You */
/*  may also use RPAR and IPAR to communicate data as appropriate. */
/*  ***Note: Aside from the values of the weights, the choice of */
/*  norm used in DDASKR (weighted root-mean-square) is not subject */
/*  to replacement by the user.  In this respect, DDASKR is not */
/*  downward-compatible with the original DDASSL solver (in which */
/*  the norm routine was optionally user-replaceable). */


/* ------OUTPUT - AFTER ANY RETURN FROM DDASKR---------------------------- */

/*  The principal aim of the code is to return a computed solution at */
/*  T = TOUT, although it is also possible to obtain intermediate */
/*  results along the way.  To find out whether the code achieved its */
/*  goal or if the integration process was interrupted before the task */
/*  was completed, you must check the IDID parameter. */


/*   T -- The output value of T is the point to which the solution */
/*        was successfully advanced. */

/*   Y(*) -- contains the computed solution approximation at T. */

/*   YPRIME(*) -- contains the computed derivative approximation at T. */

/*   IDID -- reports what the code did, described as follows: */

/*                     *** TASK COMPLETED *** */
/*                Reported by positive values of IDID */

/*           IDID = 1 -- A step was successfully taken in the */
/*                   interval-output mode.  The code has not */
/*                   yet reached TOUT. */

/*           IDID = 2 -- The integration to TSTOP was successfully */
/*                   completed (T = TSTOP) by stepping exactly to TSTOP. */

/*           IDID = 3 -- The integration to TOUT was successfully */
/*                   completed (T = TOUT) by stepping past TOUT. */
/*                   Y(*) and YPRIME(*) are obtained by interpolation. */

/*           IDID = 4 -- The initial condition calculation, with */
/*                   INFO(11) > 0, was successful, and INFO(14) = 1. */
/*                   No integration steps were taken, and the solution */
/*                   is not considered to have been started. */

/*           IDID = 5 -- The integration was successfully completed */
/*                   by finding one or more roots of R(T,Y,Y') at T. */

/*                    *** TASK INTERRUPTED *** */
/*                Reported by negative values of IDID */

/*           IDID = -1 -- A large amount of work has been expended */
/*                     (about 500 steps). */

/*           IDID = -2 -- The error tolerances are too stringent. */

/*           IDID = -3 -- The local error test cannot be satisfied */
/*                     because you specified a zero component in ATOL */
/*                     and the corresponding computed solution component */
/*                     is zero.  Thus, a pure relative error test is */
/*                     impossible for this component. */

/*           IDID = -5 -- There were repeated failures in the evaluation */
/*                     or processing of the preconditioner (in JAC). */

/*           IDID = -6 -- DDASKR had repeated error test failures on the */
/*                     last attempted step. */

/*           IDID = -7 -- The nonlinear system solver in the time */
/*                     integration could not converge. */

/*           IDID = -8 -- The matrix of partial derivatives appears */
/*                     to be singular (direct method). */

/*           IDID = -9 -- The nonlinear system solver in the integration */
/*                     failed to achieve convergence, and there were */
/*                     repeated  error test failures in this step. */

/*           IDID =-10 -- The nonlinear system solver in the integration */
/*                     failed to achieve convergence because IRES was */
/*                     equal  to -1. */

/*           IDID =-11 -- IRES = -2 was encountered and control is */
/*                     being returned to the calling program. */

/*           IDID =-12 -- DDASKR failed to compute the initial Y, YPRIME. */

/*           IDID =-13 -- An unrecoverable error was encountered inside */
/*                     the user's PSOL routine, and control is being */
/*                     returned to the calling program. */

/*           IDID =-14 -- The Krylov linear system solver could not */
/*                     achieve convergence. */

/*           IDID =-15,..,-32 -- Not applicable for this code. */

/*                    *** TASK TERMINATED *** */
/*                reported by the value of IDID=-33 */

/*           IDID = -33 -- The code has encountered trouble from which */
/*                   it cannot recover.  A message is printed */
/*                   explaining the trouble and control is returned */
/*                   to the calling program.  For example, this occurs */
/*                   when invalid input is detected. */

/*   RTOL, ATOL -- these quantities remain unchanged except when */
/*               IDID = -2.  In this case, the error tolerances have been */
/*               increased by the code to values which are estimated to */
/*               be appropriate for continuing the integration.  However, */
/*               the reported solution at T was obtained using the input */
/*               values of RTOL and ATOL. */

/*   RWORK, IWORK -- contain information which is usually of no interest */
/*               to the user but necessary for subsequent calls. */
/*               However, you may be interested in the performance data */
/*               listed below.  These quantities are accessed in RWORK */
/*               and IWORK but have internal mnemonic names, as follows.. */

/*               RWORK(3)--contains H, the step size h to be attempted */
/*                        on the next step. */

/*               RWORK(4)--contains TN, the current value of the */
/*                        independent variable, i.e. the farthest point */
/*                        integration has reached.  This will differ */
/*                        from T if interpolation has been performed */
/*                        (IDID = 3). */

/*               RWORK(7)--contains HOLD, the stepsize used on the last */
/*                        successful step.  If INFO(11) = INFO(14) = 1, */
/*                        this contains the value of H used in the */
/*                        initial condition calculation. */

/*               IWORK(7)--contains K, the order of the method to be */
/*                        attempted on the next step. */

/*               IWORK(8)--contains KOLD, the order of the method used */
/*                        on the last step. */

/*               IWORK(11)--contains NST, the number of steps (in T) */
/*                        taken so far. */

/*               IWORK(12)--contains NRE, the number of calls to RES */
/*                        so far. */

/*               IWORK(13)--contains NJE, the number of calls to JAC so */
/*                        far (Jacobian or preconditioner evaluations). */

/*               IWORK(14)--contains NETF, the total number of error test */
/*                        failures so far. */

/*               IWORK(15)--contains NCFN, the total number of nonlinear */
/*                        convergence failures so far (includes counts */
/*                        of singular iteration matrix or singular */
/*                        preconditioners). */

/*               IWORK(16)--contains NCFL, the number of convergence */
/*                        failures of the linear iteration so far. */

/*               IWORK(17)--contains LENIW, the length of IWORK actually */
/*                        required.  This is defined on normal returns */
/*                        and on an illegal input return for */
/*                        insufficient storage. */

/*               IWORK(18)--contains LENRW, the length of RWORK actually */
/*                        required.  This is defined on normal returns */
/*                        and on an illegal input return for */
/*                        insufficient storage. */

/*               IWORK(19)--contains NNI, the total number of nonlinear */
/*                        iterations so far (each of which calls a */
/*                        linear solver). */

/*               IWORK(20)--contains NLI, the total number of linear */
/*                        (Krylov) iterations so far. */

/*               IWORK(21)--contains NPS, the number of PSOL calls so */
/*                        far, for preconditioning solve operations or */
/*                        for solutions with the user-supplied method. */

/*               IWORK(36)--contains the total number of calls to the */
/*                        constraint function routine RT so far. */

/*               Note: The various counters in IWORK do not include */
/*               counts during a prior call made with INFO(11) > 0 and */
/*               INFO(14) = 1. */


/* ------INPUT - WHAT TO DO TO CONTINUE THE INTEGRATION  ----------------- */
/*              (CALLS AFTER THE FIRST) */

/*     This code is organized so that subsequent calls to continue the */
/*     integration involve little (if any) additional effort on your */
/*     part.  You must monitor the IDID parameter in order to determine */
/*     what to do next. */

/*     Recalling that the principal task of the code is to integrate */
/*     from T to TOUT (the interval mode), usually all you will need */
/*     to do is specify a new TOUT upon reaching the current TOUT. */

/*     Do not alter any quantity not specifically permitted below.  In */
/*     particular do not alter NEQ, T, Y(*), YPRIME(*), RWORK(*), */
/*     IWORK(*), or the differential equation in subroutine RES.  Any */
/*     such alteration constitutes a new problem and must be treated */
/*     as such, i.e. you must start afresh. */

/*     You cannot change from array to scalar error control or vice */
/*     versa (INFO(2)), but you can change the size of the entries of */
/*     RTOL or ATOL.  Increasing a tolerance makes the equation easier */
/*     to integrate.  Decreasing a tolerance will make the equation */
/*     harder to integrate and should generally be avoided. */

/*     You can switch from the intermediate-output mode to the */
/*     interval mode (INFO(3)) or vice versa at any time. */

/*     If it has been necessary to prevent the integration from going */
/*     past a point TSTOP (INFO(4), RWORK(1)), keep in mind that the */
/*     code will not integrate to any TOUT beyond the currently */
/*     specified TSTOP.  Once TSTOP has been reached, you must change */
/*     the value of TSTOP or set INFO(4) = 0.  You may change INFO(4) */
/*     or TSTOP at any time but you must supply the value of TSTOP in */
/*     RWORK(1) whenever you set INFO(4) = 1. */

/*     Do not change INFO(5), INFO(6), INFO(12-17) or their associated */
/*     IWORK/RWORK locations unless you are going to restart the code. */

/*                    *** FOLLOWING A COMPLETED TASK *** */

/*     If.. */
/*     IDID = 1, call the code again to continue the integration */
/*                  another step in the direction of TOUT. */

/*     IDID = 2 or 3, define a new TOUT and call the code again. */
/*                  TOUT must be different from T.  You cannot change */
/*                  the direction of integration without restarting. */

/*     IDID = 4, reset INFO(11) = 0 and call the code again to begin */
/*                  the integration.  (If you leave INFO(11) > 0 and */
/*                  INFO(14) = 1, you may generate an infinite loop.) */
/*                  In this situation, the next call to DDASKR is */
/*                  considered to be the first call for the problem, */
/*                  in that all initializations are done. */

/*     IDID = 5, call the code again to continue the integration in the */
/*                  direction of TOUT.  You may change the functions */
/*                  Ri defined by RT after a return with IDID = 5, but */
/*                  the number of constraint functions NRT must remain */
/*                  the same.  If you wish to change the functions in */
/*                  RES or in RT, then you must restart the code. */

/*                    *** FOLLOWING AN INTERRUPTED TASK *** */

/*     To show the code that you realize the task was interrupted and */
/*     that you want to continue, you must take appropriate action and */
/*     set INFO(1) = 1. */

/*     If.. */
/*     IDID = -1, the code has taken about 500 steps.  If you want to */
/*                  continue, set INFO(1) = 1 and call the code again. */
/*                  An additional 500 steps will be allowed. */


/*     IDID = -2, the error tolerances RTOL, ATOL have been increased */
/*                  to values the code estimates appropriate for */
/*                  continuing.  You may want to change them yourself. */
/*                  If you are sure you want to continue with relaxed */
/*                  error tolerances, set INFO(1) = 1 and call the code */
/*                  again. */

/*     IDID = -3, a solution component is zero and you set the */
/*                  corresponding component of ATOL to zero.  If you */
/*                  are sure you want to continue, you must first alter */
/*                  the error criterion to use positive values of ATOL */
/*                  for those components corresponding to zero solution */
/*                  components, then set INFO(1) = 1 and call the code */
/*                  again. */

/*     IDID = -4  --- cannot occur with this code. */

/*     IDID = -5, your JAC routine failed with the Krylov method.  Check */
/*                  for errors in JAC and restart the integration. */

/*     IDID = -6, repeated error test failures occurred on the last */
/*                  attempted step in DDASKR.  A singularity in the */
/*                  solution may be present.  If you are absolutely */
/*                  certain you want to continue, you should restart */
/*                  the integration.  (Provide initial values of Y and */
/*                  YPRIME which are consistent.) */

/*     IDID = -7, repeated convergence test failures occurred on the last */
/*                  attempted step in DDASKR.  An inaccurate or ill- */
/*                  conditioned Jacobian or preconditioner may be the */
/*                  problem.  If you are absolutely certain you want */
/*                  to continue, you should restart the integration. */


/*     IDID = -8, the matrix of partial derivatives is singular, with */
/*                  the use of direct methods.  Some of your equations */
/*                  may be redundant.  DDASKR cannot solve the problem */
/*                  as stated.  It is possible that the redundant */
/*                  equations could be removed, and then DDASKR could */
/*                  solve the problem.  It is also possible that a */
/*                  solution to your problem either does not exist */
/*                  or is not unique. */

/*     IDID = -9, DDASKR had multiple convergence test failures, preceded */
/*                  by multiple error test failures, on the last */
/*                  attempted step.  It is possible that your problem is */
/*                  ill-posed and cannot be solved using this code.  Or, */
/*                  there may be a discontinuity or a singularity in the */
/*                  solution.  If you are absolutely certain you want to */
/*                  continue, you should restart the integration. */

/*     IDID = -10, DDASKR had multiple convergence test failures */
/*                  because IRES was equal to -1.  If you are */
/*                  absolutely certain you want to continue, you */
/*                  should restart the integration. */

/*     IDID = -11, there was an unrecoverable error (IRES = -2) from RES */
/*                  inside the nonlinear system solver.  Determine the */
/*                  cause before trying again. */

/*     IDID = -12, DDASKR failed to compute the initial Y and YPRIME */
/*                  vectors.  This could happen because the initial */
/*                  approximation to Y or YPRIME was not very good, or */
/*                  because no consistent values of these vectors exist. */
/*                  The problem could also be caused by an inaccurate or */
/*                  singular iteration matrix, or a poor preconditioner. */

/*     IDID = -13, there was an unrecoverable error encountered inside */
/*                  your PSOL routine.  Determine the cause before */
/*                  trying again. */

/*     IDID = -14, the Krylov linear system solver failed to achieve */
/*                  convergence.  This may be due to ill-conditioning */
/*                  in the iteration matrix, or a singularity in the */
/*                  preconditioner (if one is being used). */
/*                  Another possibility is that there is a better */
/*                  choice of Krylov parameters (see INFO(13)). */
/*                  Possibly the failure is caused by redundant equations */
/*                  in the system, or by inconsistent equations. */
/*                  In that case, reformulate the system to make it */
/*                  consistent and non-redundant. */

/*     IDID = -15,..,-32 --- Cannot occur with this code. */

/*                       *** FOLLOWING A TERMINATED TASK *** */

/*     If IDID = -33, you cannot continue the solution of this problem. */
/*                  An attempt to do so will result in your run being */
/*                  terminated. */

/*  --------------------------------------------------------------------- */

/* ***REFERENCES */
/*  1.  L. R. Petzold, A Description of DASSL: A Differential/Algebraic */
/*      System Solver, in Scientific Computing, R. S. Stepleman et al. */
/*      (Eds.), North-Holland, Amsterdam, 1983, pp. 65-68. */
/*  2.  K. E. Brenan, S. L. Campbell, and L. R. Petzold, Numerical */
/*      Solution of Initial-Value Problems in Differential-Algebraic */
/*      Equations, Elsevier, New York, 1989. */
/*  3.  P. N. Brown and A. C. Hindmarsh, Reduced Storage Matrix Methods */
/*      in Stiff ODE Systems, J. Applied Mathematics and Computation, */
/*      31 (1989), pp. 40-91. */
/*  4.  P. N. Brown, A. C. Hindmarsh, and L. R. Petzold, Using Krylov */
/*      Methods in the Solution of Large-Scale Differential-Algebraic */
/*      Systems, SIAM J. Sci. Comp., 15 (1994), pp. 1467-1488. */
/*  5.  P. N. Brown, A. C. Hindmarsh, and L. R. Petzold, Consistent */
/*      Initial Condition Calculation for Differential-Algebraic */
/*      Systems, SIAM J. Sci. Comp. 19 (1998), pp. 1495-1512. */

/* ***ROUTINES CALLED */

/*   The following are all the subordinate routines used by DDASKR. */

/*   DRCHEK does preliminary checking for roots, and serves as an */
/*          interface between Subroutine DDASKR and Subroutine DROOTS. */
/*   DROOTS finds the leftmost root of a set of functions. */
/*   DDASIC computes consistent initial conditions. */
/*   DYYPNW updates Y and YPRIME in linesearch for initial condition */
/*          calculation. */
/*   DDSTP  carries out one step of the integration. */
/*   DCNSTR/DCNST0 check the current solution for constraint violations. */
/*   DDAWTS sets error weight quantities. */
/*   DINVWT tests and inverts the error weights. */
/*   DDATRP performs interpolation to get an output solution. */
/*   DDWNRM computes the weighted root-mean-square norm of a vector. */
/*   D1MACH provides the unit roundoff of the computer. */
/*   XERRWD/XSETF/XSETUN/IXSAV is a package to handle error messages. */
/*   DDASID nonlinear equation driver to initialize Y and YPRIME using */
/*          direct linear system solver methods.  Interfaces to Newton */
/*          solver (direct case). */
/*   DNSID  solves the nonlinear system for unknown initial values by */
/*          modified Newton iteration and direct linear system methods. */
/*   DLINSD carries out linesearch algorithm for initial condition */
/*          calculation (direct case). */
/*   DFNRMD calculates weighted norm of preconditioned residual in */
/*          initial condition calculation (direct case). */
/*   DNEDD  nonlinear equation driver for direct linear system solver */
/*          methods.  Interfaces to Newton solver (direct case). */
/*   DMATD  assembles the iteration matrix (direct case). */
/*   DNSD   solves the associated nonlinear system by modified */
/*          Newton iteration and direct linear system methods. */
/*   DSLVD  interfaces to linear system solver (direct case). */
/*   DDASIK nonlinear equation driver to initialize Y and YPRIME using */
/*          Krylov iterative linear system methods.  Interfaces to */
/*          Newton solver (Krylov case). */
/*   DNSIK  solves the nonlinear system for unknown initial values by */
/*          Newton iteration and Krylov iterative linear system methods. */
/*   DLINSK carries out linesearch algorithm for initial condition */
/*          calculation (Krylov case). */
/*   DFNRMK calculates weighted norm of preconditioned residual in */
/*          initial condition calculation (Krylov case). */
/*   DNEDK  nonlinear equation driver for iterative linear system solver */
/*          methods.  Interfaces to Newton solver (Krylov case). */
/*   DNSK   solves the associated nonlinear system by Inexact Newton */
/*          iteration and (linear) Krylov iteration. */
/*   DSLVK  interfaces to linear system solver (Krylov case). */
/*   DSPIGM solves a linear system by SPIGMR algorithm. */
/*   DATV   computes matrix-vector product in Krylov algorithm. */
/*   DORTH  performs orthogonalization of Krylov basis vectors. */
/*   DHEQR  performs QR factorization of Hessenberg matrix. */
/*   DHELS  finds least-squares solution of Hessenberg linear system. */
/*   DGEFA, DGESL, DGBFA, DGBSL are LINPACK routines for solving */
/*          linear systems (dense or band direct methods). */
/*   DAXPY, DCOPY, DDOT, DNRM2, DSCAL are Basic Linear Algebra (BLAS) */
/*          routines. */

/* The routines called directly by DDASKR are: */
/*   DCNST0, DDAWTS, DINVWT, D1MACH, DDWNRM, DDASIC, DDATRP, DDSTP, */
/*   DRCHEK, XERRWD */

/* ***END PROLOGUE DDASKR */



/*     Set pointers into IWORK. */


/*     Set pointers into RWORK. */




/* ***FIRST EXECUTABLE STATEMENT  DDASKR */


    /* Parameter adjustments */
    --y;
    --yprime;
    --info;
    --rtol;
    --atol;
    --rwork;
    --iwork;
    --rpar;
    --ipar;

    /* Function Body */
    if (info[1] != 0) {
	goto L100;
    }

/* ----------------------------------------------------------------------- */
/*     This block is executed for the initial call only. */
/*     It contains checking of inputs and initializations. */
/* ----------------------------------------------------------------------- */

/*     First check INFO array to make sure all elements of INFO */
/*     Are within the proper range.  (INFO(1) is checked later, because */
/*     it must be tested on every call.) ITEMP holds the location */
/*     within INFO which may be out of range. */

    for (i__ = 2; i__ <= 9; ++i__) {
	itemp = i__;
	if (info[i__] != 0 && info[i__] != 1) {
	    goto L701;
	}
/* L10: */
    }
    itemp = 10;
    if (info[10] < 0 || info[10] > 3) {
	goto L701;
    }
    itemp = 11;
    if (info[11] < 0 || info[11] > 2) {
	goto L701;
    }
    for (i__ = 12; i__ <= 17; ++i__) {
	itemp = i__;
	if (info[i__] != 0 && info[i__] != 1) {
	    goto L701;
	}
/* L15: */
    }
    itemp = 18;
    if (info[18] < 0 || info[18] > 2) {
	goto L701;
    }

/*     Check NEQ to see if it is positive. */

    if (*neq <= 0) {
	goto L702;
    }

/*     Check and compute maximum order. */

    mxord = 5;
    if (info[9] != 0) {
	mxord = iwork[3];
	if (mxord < 1 || mxord > 5) {
	    goto L703;
	}
    }
    iwork[3] = mxord;

/*     Set and/or check inputs for constraint checking (INFO(10) .NE. 0). */
/*     Set values for ICNFLG, NONNEG, and pointer LID. */

    icnflg = 0;
    nonneg = 0;
    lid = 41;
    if (info[10] == 0) {
	goto L20;
    }
    if (info[10] == 1) {
	icnflg = 1;
	nonneg = 0;
	lid = *neq + 41;
    } else if (info[10] == 2) {
	icnflg = 0;
	nonneg = 1;
    } else {
	icnflg = 1;
	nonneg = 1;
	lid = *neq + 41;
    }

L20:

/*     Set and/or check inputs for Krylov solver (INFO(12) .NE. 0). */
/*     If indicated, set default values for MAXL, KMP, NRMAX, and EPLI. */
/*     Otherwise, verify inputs required for iterative solver. */

    if (info[12] == 0) {
	goto L25;
    }

    iwork[23] = info[12];
    if (info[13] == 0) {
	iwork[24] = min(5,*neq);
	iwork[25] = iwork[24];
	iwork[26] = 5;
	rwork[10] = .05;
    } else {
	if (iwork[24] < 1 || iwork[24] > *neq) {
	    goto L720;
	}
	if (iwork[25] < 1 || iwork[25] > iwork[24]) {
	    goto L721;
	}
	if (iwork[26] < 0) {
	    goto L722;
	}
	if (rwork[10] <= 0. || rwork[10] >= 1.) {
	    goto L723;
	}
    }

L25:

/*     Set and/or check controls for the initial condition calculation */
/*     (INFO(11) .GT. 0).  If indicated, set default values. */
/*     Otherwise, verify inputs required for iterative solver. */

    if (info[11] == 0) {
	goto L30;
    }
    if (info[17] == 0) {
	iwork[32] = 5;
	if (info[12] > 0) {
	    iwork[32] = 15;
	}
	iwork[33] = 6;
	if (info[12] > 0) {
	    iwork[33] = 2;
	}
	iwork[34] = 5;
	iwork[35] = 0;
	rwork[15] = .01;
    } else {
	if (iwork[32] <= 0) {
	    goto L725;
	}
	if (iwork[33] <= 0) {
	    goto L725;
	}
	if (iwork[34] <= 0) {
	    goto L725;
	}
	lsoff = iwork[35];
	if (lsoff < 0 || lsoff > 1) {
	    goto L725;
	}
	if (rwork[15] <= 0.) {
	    goto L725;
	}
    }

L30:

/*     Below is the computation and checking of the work array lengths */
/*     LENIW and LENRW, using direct methods (INFO(12) = 0) or */
/*     the Krylov methods (INFO(12) = 1). */

    lenic = 0;
    if (info[10] == 1 || info[10] == 3) {
	lenic = *neq;
    }
    lenid = 0;
    if (info[11] == 1 || info[16] == 1) {
	lenid = *neq;
    }
    if (info[12] == 0) {

/*        Compute MTYPE, etc.  Check ML and MU. */

/* Computing MAX */
	i__1 = mxord + 1;
	ncphi = max(i__1,4);
	if (info[6] == 0) {
/* Computing 2nd power */
	    i__1 = *neq;
	    lenpd = i__1 * i__1;
	    lenrw = *nrt * 3 + 60 + (ncphi + 3) * *neq + lenpd;
	    if (info[5] == 0) {
		iwork[4] = 2;
	    } else {
		iwork[4] = 1;
	    }
	} else {
	    if (iwork[1] < 0 || iwork[1] >= *neq) {
		goto L717;
	    }
	    if (iwork[2] < 0 || iwork[2] >= *neq) {
		goto L718;
	    }
	    lenpd = ((iwork[1] << 1) + iwork[2] + 1) * *neq;
	    if (info[5] == 0) {
		iwork[4] = 5;
		mband = iwork[1] + iwork[2] + 1;
		msave = *neq / mband + 1;
		lenrw = *nrt * 3 + 60 + (ncphi + 3) * *neq + lenpd + (msave <<
			 1);
	    } else {
		iwork[4] = 4;
		lenrw = *nrt * 3 + 60 + (ncphi + 3) * *neq + lenpd;
	    }
	}

/*        Compute LENIW, LENWP, LENIWP. */

	leniw = lenic + 40 + lenid + *neq;
	lenwp = 0;
	leniwp = 0;

    } else if (info[12] == 1) {
	ncphi = mxord + 1;
	maxl = iwork[24];
	lenwp = iwork[27];
	leniwp = iwork[28];
/* Computing MIN */
	i__1 = 1, i__2 = maxl - iwork[25];
	lenpd = (maxl + 3 + min(i__1,i__2)) * *neq + (maxl + 3) * maxl + 1 + 
		lenwp;
	lenrw = *nrt * 3 + 60 + (mxord + 5) * *neq + lenpd;
	leniw = lenic + 40 + lenid + leniwp;

    }
    if (info[16] != 0) {
	lenrw += *neq;
    }

/*     Check lengths of RWORK and IWORK. */

    iwork[17] = leniw;
    iwork[18] = lenrw;
    iwork[22] = lenpd;
    iwork[29] = lenpd - lenwp + 1;
    if (*lrw < lenrw) {
	goto L704;
    }
    if (*liw < leniw) {
	goto L705;
    }

/*     Check ICNSTR for legality. */

    if (lenic > 0) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ici = iwork[i__ + 40];
	    if (ici < -2 || ici > 2) {
		goto L726;
	    }
/* L40: */
	}
    }

/*     Check Y for consistency with constraints. */

    if (lenic > 0) {
	dcnst0_(neq, &y[1], &iwork[41], &iret);
	if (iret != 0) {
	    goto L727;
	}
    }

/*     Check ID for legality and set INDEX = 0 or 1. */

    index = 1;
    if (lenid > 0) {
	index = 0;
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    idi = iwork[lid - 1 + i__];
	    if (idi != 1 && idi != -1) {
		goto L724;
	    }
	    if (idi == -1) {
		index = 1;
	    }
/* L50: */
	}
    }

/*     Check to see that TOUT is different from T, and NRT .ge. 0. */

    if (*tout == *t) {
	goto L719;
    }
    if (*nrt < 0) {
	goto L730;
    }

/*     Check HMAX. */

    if (info[7] != 0) {
	hmax = rwork[2];
	if (hmax <= 0.) {
	    goto L710;
	}
    }

/*     Initialize counters and other flags. */

    iwork[11] = 0;
    iwork[12] = 0;
    iwork[13] = 0;
    iwork[14] = 0;
    iwork[15] = 0;
    iwork[19] = 0;
    iwork[20] = 0;
    iwork[21] = 0;
    iwork[16] = 0;
    iwork[36] = 0;
    iwork[31] = info[18];
    *idid = 1;
    goto L200;

/* ----------------------------------------------------------------------- */
/*     This block is for continuation calls only. */
/*     Here we check INFO(1), and if the last step was interrupted, */
/*     we check whether appropriate action was taken. */
/* ----------------------------------------------------------------------- */

L100:
    if (info[1] == 1) {
	goto L110;
    }
    itemp = 1;
    if (info[1] != -1) {
	goto L701;
    }

/*     If we are here, the last step was interrupted by an error */
/*     condition from DDSTP, and appropriate action was not taken. */
/*     This is a fatal error. */

    s_copy(msg, "DASKR--  THE LAST STEP TERMINATED WITH A NEGATIVE", (ftnlen)
	    80, (ftnlen)49);
    xerrwd_(msg, &c__49, &c__201, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  VALUE (=I1) OF IDID AND NO APPROPRIATE", (ftnlen)80,
	     (ftnlen)47);
    xerrwd_(msg, &c__47, &c__202, &c__0, &c__1, idid, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  ACTION WAS TAKEN. RUN TERMINATED", (ftnlen)80, (
	    ftnlen)41);
    xerrwd_(msg, &c__41, &c__203, &c__1, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    return 0;
L110:

/* ----------------------------------------------------------------------- */
/*     This block is executed on all calls. */

/*     Counters are saved for later checks of performance. */
/*     Then the error tolerance parameters are checked, and the */
/*     work array pointers are set. */
/* ----------------------------------------------------------------------- */

L200:

/*     Save counters for use later. */

    iwork[10] = iwork[11];
    nli0 = iwork[20];
    nni0 = iwork[19];
    ncfn0 = iwork[15];
    ncfl0 = iwork[16];
    nwarn = 0;

/*     Check RTOL and ATOL. */

    nzflg = 0;
    rtoli = rtol[1];
    atoli = atol[1];
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (info[2] == 1) {
	    rtoli = rtol[i__];
	}
	if (info[2] == 1) {
	    atoli = atol[i__];
	}
	if (rtoli > 0. || atoli > 0.) {
	    nzflg = 1;
	}
	if (rtoli < 0.) {
	    goto L706;
	}
	if (atoli < 0.) {
	    goto L707;
	}
/* L210: */
    }
    if (nzflg == 0) {
	goto L708;
    }

/*     Set pointers to RWORK and IWORK segments. */
/*     For direct methods, SAVR is not used. */

    iwork[30] = lid + lenid;
    lsavr = 61;
    if (info[12] != 0) {
	lsavr = *neq + 61;
    }
    le = lsavr + *neq;
    lwt = le + *neq;
    lvt = lwt;
    if (info[16] != 0) {
	lvt = lwt + *neq;
    }
    lphi = lvt + *neq;
    lr0 = lphi + ncphi * *neq;
    lr1 = lr0 + *nrt;
    lrx = lr1 + *nrt;
    lwm = lrx + *nrt;
    if (info[1] == 1) {
	goto L400;
    }

/* ----------------------------------------------------------------------- */
/*     This block is executed on the initial call only. */
/*     Set the initial step size, the error weight vector, and PHI. */
/*     Compute unknown initial components of Y and YPRIME, if requested. */
/* ----------------------------------------------------------------------- */

/* L300: */
    tn = *t;
    *idid = 1;

/*     Set error weight array WT and altered weight array VT. */

    ddawts_(neq, &info[2], &rtol[1], &atol[1], &y[1], &rwork[lwt], &rpar[1], &
	    ipar[1]);
    dinvwt_(neq, &rwork[lwt], &ier);
    if (ier != 0) {
	goto L713;
    }
    if (info[16] != 0) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L305: */
/* Computing MAX */
	    i__2 = iwork[lid + i__ - 1];
	    rwork[lvt + i__ - 1] = max(i__2,0) * rwork[lwt + i__ - 1];
	}
    }

/*     Compute unit roundoff and HMIN. */

    uround = d1mach_(&c__4);
    rwork[9] = uround;
/* Computing MAX */
    d__1 = abs(*t), d__2 = abs(*tout);
    hmin = uround * 4. * max(d__1,d__2);

/*     Set/check STPTOL control for initial condition calculation. */

    if (info[11] != 0) {
	if (info[17] == 0) {
	    rwork[14] = pow_dd(&uround, &c_b113);
	} else {
	    if (rwork[14] <= 0.) {
		goto L725;
	    }
	}
    }

/*     Compute EPCON and square root of NEQ and its reciprocal, used */
/*     inside iterative solver. */

    rwork[13] = .33;
    floatn = (doublereal) (*neq);
    rwork[11] = sqrt(floatn);
    rwork[12] = 1. / rwork[11];

/*     Check initial interval to see that it is long enough. */

    tdist = (d__1 = *tout - *t, abs(d__1));
    if (tdist < hmin) {
	goto L714;
    }

/*     Check H0, if this was input. */

    if (info[8] == 0) {
	goto L310;
    }
    h0 = rwork[3];
    if ((*tout - *t) * h0 < 0.) {
	goto L711;
    }
    if (h0 == 0.) {
	goto L712;
    }
    goto L320;
L310:

/*     Compute initial stepsize, to be used by either */
/*     DDSTP or DDASIC, depending on INFO(11). */

    h0 = tdist * .001;
    ypnorm = ddwnrm_(neq, &yprime[1], &rwork[lvt], &rpar[1], &ipar[1]);
    if (ypnorm > .5 / h0) {
	h0 = .5 / ypnorm;
    }
    d__1 = *tout - *t;
    h0 = d_sign(&h0, &d__1);

/*     Adjust H0 if necessary to meet HMAX bound. */

L320:
    if (info[7] == 0) {
	goto L330;
    }
    rh = abs(h0) / rwork[2];
    if (rh > 1.) {
	h0 /= rh;
    }

/*     Check against TSTOP, if applicable. */

L330:
    if (info[4] == 0) {
	goto L340;
    }
    tstop = rwork[1];
    if ((tstop - *t) * h0 < 0.) {
	goto L715;
    }
    if ((*t + h0 - tstop) * h0 > 0.) {
	h0 = tstop - *t;
    }
    if ((tstop - *tout) * h0 < 0.) {
	goto L709;
    }

L340:
    if (info[11] == 0) {
	goto L370;
    }

/*     Compute unknown components of initial Y and YPRIME, depending */
/*     on INFO(11) and INFO(12).  INFO(12) represents the nonlinear */
/*     solver type (direct/Krylov).  Pass the name of the specific */
/*     nonlinear solver, depending on INFO(12).  The location of the work */
/*     arrays SAVR, YIC, YPIC, PWK also differ in the two cases. */
/*     For use in stopping tests, pass TSCALE = TDIST if INDEX = 0. */

    nwt = 1;
    epconi = rwork[15] * rwork[13];
    tscale = 0.;
    if (index == 0) {
	tscale = tdist;
    }
L350:
    if (info[12] == 0) {
	lyic = lphi + (*neq << 1);
	lypic = lyic + *neq;
	lpwk = lypic;
	ddasic_(&tn, &y[1], &yprime[1], neq, &info[11], &iwork[lid], (U_fp)
		res, (U_fp)jac, (U_fp)psol, &h0, &tscale, &rwork[lwt], &nwt, 
		idid, &rpar[1], &ipar[1], &rwork[lphi], &rwork[lsavr], &rwork[
		61], &rwork[le], &rwork[lyic], &rwork[lypic], &rwork[lpwk], &
		rwork[lwm], &iwork[1], &rwork[9], &rwork[10], &rwork[11], &
		rwork[12], &epconi, &rwork[14], &info[15], &icnflg, &iwork[41]
		, (U_fp)ddasid_);
    } else if (info[12] == 1) {
	lyic = lwm;
	lypic = lyic + *neq;
	lpwk = lypic + *neq;
	ddasic_(&tn, &y[1], &yprime[1], neq, &info[11], &iwork[lid], (U_fp)
		res, (U_fp)jac, (U_fp)psol, &h0, &tscale, &rwork[lwt], &nwt, 
		idid, &rpar[1], &ipar[1], &rwork[lphi], &rwork[lsavr], &rwork[
		61], &rwork[le], &rwork[lyic], &rwork[lypic], &rwork[lpwk], &
		rwork[lwm], &iwork[1], &rwork[9], &rwork[10], &rwork[11], &
		rwork[12], &epconi, &rwork[14], &info[15], &icnflg, &iwork[41]
		, (U_fp)ddasik_);
    }

    if (*idid < 0) {
	goto L600;
    }

/*     DDASIC was successful.  If this was the first call to DDASIC, */
/*     update the WT array (with the current Y) and call it again. */

    if (nwt == 2) {
	goto L355;
    }
    nwt = 2;
    ddawts_(neq, &info[2], &rtol[1], &atol[1], &y[1], &rwork[lwt], &rpar[1], &
	    ipar[1]);
    dinvwt_(neq, &rwork[lwt], &ier);
    if (ier != 0) {
	goto L713;
    }
    goto L350;

/*     If INFO(14) = 1, return now with IDID = 4. */

L355:
    if (info[14] == 1) {
	*idid = 4;
	h__ = h0;
	if (info[11] == 1) {
	    rwork[7] = h0;
	}
	goto L590;
    }

/*     Update the WT and VT arrays one more time, with the new Y. */

    ddawts_(neq, &info[2], &rtol[1], &atol[1], &y[1], &rwork[lwt], &rpar[1], &
	    ipar[1]);
    dinvwt_(neq, &rwork[lwt], &ier);
    if (ier != 0) {
	goto L713;
    }
    if (info[16] != 0) {
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L357: */
/* Computing MAX */
	    i__1 = iwork[lid + i__ - 1];
	    rwork[lvt + i__ - 1] = max(i__1,0) * rwork[lwt + i__ - 1];
	}
    }

/*     Reset the initial stepsize to be used by DDSTP. */
/*     Use H0, if this was input.  Otherwise, recompute H0, */
/*     and adjust it if necessary to meet HMAX bound. */

    if (info[8] != 0) {
	h0 = rwork[3];
	goto L360;
    }

    h0 = tdist * .001;
    ypnorm = ddwnrm_(neq, &yprime[1], &rwork[lvt], &rpar[1], &ipar[1]);
    if (ypnorm > .5 / h0) {
	h0 = .5 / ypnorm;
    }
    d__1 = *tout - *t;
    h0 = d_sign(&h0, &d__1);

L360:
    if (info[7] != 0) {
	rh = abs(h0) / rwork[2];
	if (rh > 1.) {
	    h0 /= rh;
	}
    }

/*     Check against TSTOP, if applicable. */

    if (info[4] != 0) {
	tstop = rwork[1];
	if ((*t + h0 - tstop) * h0 > 0.) {
	    h0 = tstop - *t;
	}
    }

/*     Load H and RWORK(LH) with H0. */

L370:
    h__ = h0;
    rwork[3] = h__;

/*     Load Y and H*YPRIME into PHI(*,1) and PHI(*,2). */

    itemp = lphi + *neq;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	rwork[lphi + i__ - 1] = y[i__];
/* L380: */
	rwork[itemp + i__ - 1] = h__ * yprime[i__];
    }

/*     Initialize T0 in RWORK; check for a zero of R near initial T. */

    rwork[51] = *t;
    iwork[37] = 0;
    rwork[39] = h__;
    rwork[40] = h__ * 2.;
    iwork[8] = 1;
    if (*nrt == 0) {
	goto L390;
    }
    drchek_(&c__1, (U_fp)rt, nrt, neq, t, tout, &y[1], &yprime[1], &rwork[
	    lphi], &rwork[39], &iwork[8], &rwork[lr0], &rwork[lr1], &rwork[
	    lrx], jroot, &irt, &rwork[9], &info[3], &rwork[1], &iwork[1], &
	    rpar[1], &ipar[1]);
    if (irt < 0) {
	goto L731;
    }

L390:
    goto L500;

/* ----------------------------------------------------------------------- */
/*     This block is for continuation calls only. */
/*     Its purpose is to check stop conditions before taking a step. */
/*     Adjust H if necessary to meet HMAX bound. */
/* ----------------------------------------------------------------------- */

L400:
    uround = rwork[9];
    done = FALSE_;
    tn = rwork[4];
    h__ = rwork[3];
    if (*nrt == 0) {
	goto L405;
    }

/*     Check for a zero of R near TN. */

    drchek_(&c__2, (U_fp)rt, nrt, neq, &tn, tout, &y[1], &yprime[1], &rwork[
	    lphi], &rwork[39], &iwork[8], &rwork[lr0], &rwork[lr1], &rwork[
	    lrx], jroot, &irt, &rwork[9], &info[3], &rwork[1], &iwork[1], &
	    rpar[1], &ipar[1]);
    if (irt < 0) {
	goto L731;
    }
    if (irt != 1) {
	goto L405;
    }
    iwork[37] = 1;
    *idid = 5;
    *t = rwork[51];
    done = TRUE_;
    goto L490;
L405:

    if (info[7] == 0) {
	goto L410;
    }
    rh = abs(h__) / rwork[2];
    if (rh > 1.) {
	h__ /= rh;
    }
L410:
    if (*t == *tout) {
	goto L719;
    }
    if ((*t - *tout) * h__ > 0.) {
	goto L711;
    }
    if (info[4] == 1) {
	goto L430;
    }
    if (info[3] == 1) {
	goto L420;
    }
    if ((tn - *tout) * h__ < 0.) {
	goto L490;
    }
    ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
	    rwork[39]);
    *t = *tout;
    *idid = 3;
    done = TRUE_;
    goto L490;
L420:
    if ((tn - *t) * h__ <= 0.) {
	goto L490;
    }
    if ((tn - *tout) * h__ >= 0.) {
	goto L425;
    }
    ddatrp_(&tn, &tn, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &rwork[
	    39]);
    *t = tn;
    *idid = 1;
    done = TRUE_;
    goto L490;
L425:
    ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
	    rwork[39]);
    *t = *tout;
    *idid = 3;
    done = TRUE_;
    goto L490;
L430:
    if (info[3] == 1) {
	goto L440;
    }
    tstop = rwork[1];
    if ((tn - tstop) * h__ > 0.) {
	goto L715;
    }
    if ((tstop - *tout) * h__ < 0.) {
	goto L709;
    }
    if ((tn - *tout) * h__ < 0.) {
	goto L450;
    }
    ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
	    rwork[39]);
    *t = *tout;
    *idid = 3;
    done = TRUE_;
    goto L490;
L440:
    tstop = rwork[1];
    if ((tn - tstop) * h__ > 0.) {
	goto L715;
    }
    if ((tstop - *tout) * h__ < 0.) {
	goto L709;
    }
    if ((tn - *t) * h__ <= 0.) {
	goto L450;
    }
    if ((tn - *tout) * h__ >= 0.) {
	goto L445;
    }
    ddatrp_(&tn, &tn, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &rwork[
	    39]);
    *t = tn;
    *idid = 1;
    done = TRUE_;
    goto L490;
L445:
    ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
	    rwork[39]);
    *t = *tout;
    *idid = 3;
    done = TRUE_;
    goto L490;
L450:

/*     Check whether we are within roundoff of TSTOP. */

    if ((d__1 = tn - tstop, abs(d__1)) > uround * 100. * (abs(tn) + abs(h__)))
	     {
	goto L460;
    }
    ddatrp_(&tn, &tstop, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
	    rwork[39]);
    *idid = 2;
    *t = tstop;
    done = TRUE_;
    goto L490;
L460:
    tnext = tn + h__;
    if ((tnext - tstop) * h__ <= 0.) {
	goto L490;
    }
    h__ = tstop - tn;
    rwork[3] = h__;

L490:
    if (done) {
	goto L590;
    }

/* ----------------------------------------------------------------------- */
/*     The next block contains the call to the one-step integrator DDSTP. */
/*     This is a looping point for the integration steps. */
/*     Check for too many steps. */
/*     Check for poor Newton/Krylov performance. */
/*     Update WT.  Check for too much accuracy requested. */
/*     Compute minimum stepsize. */
/* ----------------------------------------------------------------------- */

L500:

/*     Check for too many steps. */

    if (iwork[11] - iwork[10] < 500) {
	goto L505;
    }
    *idid = -1;
    goto L527;

/* Check for poor Newton/Krylov performance. */

L505:
    if (info[12] == 0) {
	goto L510;
    }
    nstd = iwork[11] - iwork[10];
    nnid = iwork[19] - nni0;
    if (nstd < 10 || nnid == 0) {
	goto L510;
    }
    avlin = (real) (iwork[20] - nli0) / (real) nnid;
    rcfn = (real) (iwork[15] - ncfn0) / (real) nstd;
    rcfl = (real) (iwork[16] - ncfl0) / (real) nnid;
    fmaxl = (doublereal) iwork[24];
    lavl = avlin > fmaxl;
    lcfn = rcfn > .9;
    lcfl = rcfl > .9;
    lwarn = lavl || lcfn || lcfl;
    if (! lwarn) {
	goto L510;
    }
    ++nwarn;
    if (nwarn > 10) {
	goto L510;
    }
    if (lavl) {
	s_copy(msg, "DASKR-- Warning. Poor iterative algorithm performance   "
		, (ftnlen)80, (ftnlen)56);
	xerrwd_(msg, &c__56, &c__501, &c__0, &c__0, &c__0, &c__0, &c__0, &
		c_b83, &c_b83, (ftnlen)80);
	s_copy(msg, "      at T = R1. Average no. of linear iterations = R2  "
		, (ftnlen)80, (ftnlen)56);
	xerrwd_(msg, &c__56, &c__501, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, 
		&avlin, (ftnlen)80);
    }
    if (lcfn) {
	s_copy(msg, "DASKR-- Warning. Poor iterative algorithm performance   "
		, (ftnlen)80, (ftnlen)56);
	xerrwd_(msg, &c__56, &c__502, &c__0, &c__0, &c__0, &c__0, &c__0, &
		c_b83, &c_b83, (ftnlen)80);
	s_copy(msg, "      at T = R1. Nonlinear convergence failure rate = R2"
		, (ftnlen)80, (ftnlen)56);
	xerrwd_(msg, &c__56, &c__502, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, 
		&rcfn, (ftnlen)80);
    }
    if (lcfl) {
	s_copy(msg, "DASKR-- Warning. Poor iterative algorithm performance   "
		, (ftnlen)80, (ftnlen)56);
	xerrwd_(msg, &c__56, &c__503, &c__0, &c__0, &c__0, &c__0, &c__0, &
		c_b83, &c_b83, (ftnlen)80);
	s_copy(msg, "      at T = R1. Linear convergence failure rate = R2   "
		, (ftnlen)80, (ftnlen)56);
	xerrwd_(msg, &c__56, &c__503, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, 
		&rcfl, (ftnlen)80);
    }

/*     Update WT and VT, if this is not the first call. */

L510:
    ddawts_(neq, &info[2], &rtol[1], &atol[1], &rwork[lphi], &rwork[lwt], &
	    rpar[1], &ipar[1]);
    dinvwt_(neq, &rwork[lwt], &ier);
    if (ier != 0) {
	*idid = -3;
	goto L527;
    }
    if (info[16] != 0) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L515: */
/* Computing MAX */
	    i__2 = iwork[lid + i__ - 1];
	    rwork[lvt + i__ - 1] = max(i__2,0) * rwork[lwt + i__ - 1];
	}
    }

/*     Test for too much accuracy requested. */

    r__ = ddwnrm_(neq, &rwork[lphi], &rwork[lwt], &rpar[1], &ipar[1]) * 100. *
	     uround;
    if (r__ <= 1.) {
	goto L525;
    }

/*     Multiply RTOL and ATOL by R and return. */

    if (info[2] == 1) {
	goto L523;
    }
    rtol[1] = r__ * rtol[1];
    atol[1] = r__ * atol[1];
    *idid = -2;
    goto L527;
L523:
    i__2 = *neq;
    for (i__ = 1; i__ <= i__2; ++i__) {
	rtol[i__] = r__ * rtol[i__];
/* L524: */
	atol[i__] = r__ * atol[i__];
    }
    *idid = -2;
    goto L527;
L525:

/*     Compute minimum stepsize. */

/* Computing MAX */
    d__1 = abs(tn), d__2 = abs(*tout);
    hmin = uround * 4. * max(d__1,d__2);

/*     Test H vs. HMAX */
    if (info[7] != 0) {
	rh = abs(h__) / rwork[2];
	if (rh > 1.) {
	    h__ /= rh;
	}
    }

/*     Call the one-step integrator. */
/*     Note that INFO(12) represents the nonlinear solver type. */
/*     Pass the required nonlinear solver, depending upon INFO(12). */

    if (info[12] == 0) {
	ddstp_(&tn, &y[1], &yprime[1], neq, (U_fp)res, (U_fp)jac, (U_fp)psol, 
		&h__, &rwork[lwt], &rwork[lvt], &info[1], idid, &rpar[1], &
		ipar[1], &rwork[lphi], &rwork[lsavr], &rwork[61], &rwork[le], 
		&rwork[lwm], &iwork[1], &rwork[21], &rwork[27], &rwork[33], &
		rwork[39], &rwork[45], &rwork[5], &rwork[6], &rwork[7], &
		rwork[8], &hmin, &rwork[9], &rwork[10], &rwork[11], &rwork[12]
		, &rwork[13], &iwork[6], &iwork[5], &info[15], &iwork[7], &
		iwork[8], &iwork[9], &nonneg, &info[12], (U_fp)dnedd_);
    } else if (info[12] == 1) {
	ddstp_(&tn, &y[1], &yprime[1], neq, (U_fp)res, (U_fp)jac, (U_fp)psol, 
		&h__, &rwork[lwt], &rwork[lvt], &info[1], idid, &rpar[1], &
		ipar[1], &rwork[lphi], &rwork[lsavr], &rwork[61], &rwork[le], 
		&rwork[lwm], &iwork[1], &rwork[21], &rwork[27], &rwork[33], &
		rwork[39], &rwork[45], &rwork[5], &rwork[6], &rwork[7], &
		rwork[8], &hmin, &rwork[9], &rwork[10], &rwork[11], &rwork[12]
		, &rwork[13], &iwork[6], &iwork[5], &info[15], &iwork[7], &
		iwork[8], &iwork[9], &nonneg, &info[12], (U_fp)dnedk_);
    }

L527:
    if (*idid < 0) {
	goto L600;
    }

/* ----------------------------------------------------------------------- */
/*     This block handles the case of a successful return from DDSTP */
/*     (IDID=1).  Test for stop conditions. */
/* ----------------------------------------------------------------------- */

    if (*nrt == 0) {
	goto L530;
    }

/*     Check for a zero of R near TN. */

    drchek_(&c__3, (U_fp)rt, nrt, neq, &tn, tout, &y[1], &yprime[1], &rwork[
	    lphi], &rwork[39], &iwork[8], &rwork[lr0], &rwork[lr1], &rwork[
	    lrx], jroot, &irt, &rwork[9], &info[3], &rwork[1], &iwork[1], &
	    rpar[1], &ipar[1]);
    if (irt != 1) {
	goto L530;
    }
    iwork[37] = 1;
    *idid = 5;
    *t = rwork[51];
    goto L580;

L530:
    if (info[4] == 0) {
/*        Stopping tests for the case of no TSTOP. ---------------------- */
	if ((tn - *tout) * h__ >= 0.) {
	    ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi]
		    , &rwork[39]);
	    *t = *tout;
	    *idid = 3;
	    goto L580;
	}
	if (info[3] == 0) {
	    goto L500;
	}
	*t = tn;
	*idid = 1;
	goto L580;
    }

/* L540: */
    if (info[3] != 0) {
	goto L550;
    }
/*     Stopping tests for the TSTOP case, interval-output mode. --------- */
    if ((d__1 = tn - tstop, abs(d__1)) <= uround * 100. * (abs(tn) + abs(h__))
	    ) {
	ddatrp_(&tn, &tstop, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], 
		&rwork[39]);
	*t = tstop;
	*idid = 2;
	goto L580;
    }
    if ((tn - *tout) * h__ >= 0.) {
	ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
		rwork[39]);
	*t = *tout;
	*idid = 3;
	goto L580;
    }
    tnext = tn + h__;
    if ((tnext - tstop) * h__ <= 0.) {
	goto L500;
    }
    h__ = tstop - tn;
    goto L500;

L550:
/*     Stopping tests for the TSTOP case, intermediate-output mode. ----- */
    if ((d__1 = tn - tstop, abs(d__1)) <= uround * 100. * (abs(tn) + abs(h__))
	    ) {
	ddatrp_(&tn, &tstop, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], 
		&rwork[39]);
	*t = tstop;
	*idid = 2;
	goto L580;
    }
    if ((tn - *tout) * h__ >= 0.) {
	ddatrp_(&tn, tout, &y[1], &yprime[1], neq, &iwork[8], &rwork[lphi], &
		rwork[39]);
	*t = *tout;
	*idid = 3;
	goto L580;
    }
    *t = tn;
    *idid = 1;

L580:

/* ----------------------------------------------------------------------- */
/*     All successful returns from DDASKR are made from this block. */
/* ----------------------------------------------------------------------- */

L590:
    rwork[4] = tn;
    rwork[52] = *t;
    rwork[3] = h__;
    return 0;

/* ----------------------------------------------------------------------- */
/*     This block handles all unsuccessful returns other than for */
/*     illegal input. */
/* ----------------------------------------------------------------------- */

L600:
    itemp = -(*idid);
    switch (itemp) {
	case 1:  goto L610;
	case 2:  goto L620;
	case 3:  goto L630;
	case 4:  goto L700;
	case 5:  goto L655;
	case 6:  goto L640;
	case 7:  goto L650;
	case 8:  goto L660;
	case 9:  goto L670;
	case 10:  goto L675;
	case 11:  goto L680;
	case 12:  goto L685;
	case 13:  goto L690;
	case 14:  goto L695;
    }

/*     The maximum number of steps was taken before */
/*     reaching tout. */

L610:
    s_copy(msg, "DASKR--  AT CURRENT T (=R1)  500 STEPS", (ftnlen)80, (ftnlen)
	    38);
    xerrwd_(msg, &c__38, &c__610, &c__0, &c__0, &c__0, &c__0, &c__1, &tn, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  TAKEN ON THIS CALL BEFORE REACHING TOUT", (ftnlen)
	    80, (ftnlen)48);
    xerrwd_(msg, &c__48, &c__611, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Too much accuracy for machine precision. */

L620:
    s_copy(msg, "DASKR--  AT T (=R1) TOO MUCH ACCURACY REQUESTED", (ftnlen)80,
	     (ftnlen)47);
    xerrwd_(msg, &c__47, &c__620, &c__0, &c__0, &c__0, &c__0, &c__1, &tn, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  FOR PRECISION OF MACHINE. RTOL AND ATOL", (ftnlen)
	    80, (ftnlen)48);
    xerrwd_(msg, &c__48, &c__621, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  WERE INCREASED BY A FACTOR R (=R1)", (ftnlen)80, (
	    ftnlen)43);
    xerrwd_(msg, &c__43, &c__622, &c__0, &c__0, &c__0, &c__0, &c__1, &r__, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     WT(I) .LE. 0.0D0 for some I (not at start of problem). */

L630:
    s_copy(msg, "DASKR--  AT T (=R1) SOME ELEMENT OF WT", (ftnlen)80, (ftnlen)
	    38);
    xerrwd_(msg, &c__38, &c__630, &c__0, &c__0, &c__0, &c__0, &c__1, &tn, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  HAS BECOME .LE. 0.0", (ftnlen)80, (ftnlen)28);
    xerrwd_(msg, &c__28, &c__631, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Error test failed repeatedly or with H=HMIN. */

L640:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__640, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  ERROR TEST FAILED REPEATEDLY OR WITH ABS(H)=HMIN", (
	    ftnlen)80, (ftnlen)57);
    xerrwd_(msg, &c__57, &c__641, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Nonlinear solver failed to converge repeatedly or with H=HMIN. */

L650:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__650, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  NONLINEAR SOLVER FAILED TO CONVERGE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__651, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  REPEATEDLY OR WITH ABS(H)=HMIN", (ftnlen)80, (
	    ftnlen)39);
    xerrwd_(msg, &c__40, &c__652, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     The preconditioner had repeated failures. */

L655:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__655, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  PRECONDITIONER HAD REPEATED FAILURES.", (ftnlen)80, 
	    (ftnlen)46);
    xerrwd_(msg, &c__46, &c__656, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     The iteration matrix is singular. */

L660:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__660, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  ITERATION MATRIX IS SINGULAR.", (ftnlen)80, (ftnlen)
	    38);
    xerrwd_(msg, &c__38, &c__661, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Nonlinear system failure preceded by error test failures. */

L670:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__670, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  NONLINEAR SOLVER COULD NOT CONVERGE.", (ftnlen)80, (
	    ftnlen)45);
    xerrwd_(msg, &c__45, &c__671, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  ALSO, THE ERROR TEST FAILED REPEATEDLY.", (ftnlen)
	    80, (ftnlen)48);
    xerrwd_(msg, &c__49, &c__672, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Nonlinear system failure because IRES = -1. */

L675:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__675, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  NONLINEAR SYSTEM SOLVER COULD NOT CONVERGE", (
	    ftnlen)80, (ftnlen)51);
    xerrwd_(msg, &c__51, &c__676, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  BECAUSE IRES WAS EQUAL TO MINUS ONE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__677, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Failure because IRES = -2. */

L680:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2)", (ftnlen)80, (
	    ftnlen)40);
    xerrwd_(msg, &c__40, &c__680, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  IRES WAS EQUAL TO MINUS TWO", (ftnlen)80, (ftnlen)
	    36);
    xerrwd_(msg, &c__36, &c__681, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Failed to compute initial YPRIME. */

L685:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__685, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "DASKR--  INITIAL (Y,YPRIME) COULD NOT BE COMPUTED", (ftnlen)
	    80, (ftnlen)49);
    xerrwd_(msg, &c__49, &c__686, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &h0,
	     (ftnlen)80);
    goto L700;

/*     Failure because IER was negative from PSOL. */

L690:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2)", (ftnlen)80, (
	    ftnlen)40);
    xerrwd_(msg, &c__40, &c__690, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  IER WAS NEGATIVE FROM PSOL", (ftnlen)80, (ftnlen)35)
	    ;
    xerrwd_(msg, &c__35, &c__691, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;

/*     Failure because the linear system solver could not converge. */

L695:
    s_copy(msg, "DASKR--  AT T (=R1) AND STEPSIZE H (=R2) THE", (ftnlen)80, (
	    ftnlen)44);
    xerrwd_(msg, &c__44, &c__695, &c__0, &c__0, &c__0, &c__0, &c__2, &tn, &
	    h__, (ftnlen)80);
    s_copy(msg, "DASKR--  LINEAR SYSTEM SOLVER COULD NOT CONVERGE.", (ftnlen)
	    80, (ftnlen)49);
    xerrwd_(msg, &c__50, &c__696, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L700;


L700:
    info[1] = -1;
    *t = tn;
    rwork[4] = tn;
    rwork[3] = h__;
    return 0;

/* ----------------------------------------------------------------------- */
/*     This block handles all error returns due to illegal input, */
/*     as detected before calling DDSTP. */
/*     First the error message routine is called.  If this happens */
/*     twice in succession, execution is terminated. */
/* ----------------------------------------------------------------------- */

L701:
    s_copy(msg, "DASKR--  ELEMENT (=I1) OF INFO VECTOR IS NOT VALID", (ftnlen)
	    80, (ftnlen)50);
    xerrwd_(msg, &c__50, &c__1, &c__0, &c__1, &itemp, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L702:
    s_copy(msg, "DASKR--  NEQ (=I1) .LE. 0", (ftnlen)80, (ftnlen)25);
    xerrwd_(msg, &c__25, &c__2, &c__0, &c__1, neq, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L703:
    s_copy(msg, "DASKR--  MAXORD (=I1) NOT IN RANGE", (ftnlen)80, (ftnlen)34);
    xerrwd_(msg, &c__34, &c__3, &c__0, &c__1, &mxord, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L704:
    s_copy(msg, "DASKR--  RWORK LENGTH NEEDED, LENRW (=I1), EXCEEDS LRW (=I2)"
	    , (ftnlen)80, (ftnlen)60);
    xerrwd_(msg, &c__60, &c__4, &c__0, &c__2, &lenrw, lrw, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L705:
    s_copy(msg, "DASKR--  IWORK LENGTH NEEDED, LENIW (=I1), EXCEEDS LIW (=I2)"
	    , (ftnlen)80, (ftnlen)60);
    xerrwd_(msg, &c__60, &c__5, &c__0, &c__2, &leniw, liw, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L706:
    s_copy(msg, "DASKR--  SOME ELEMENT OF RTOL IS .LT. 0", (ftnlen)80, (
	    ftnlen)39);
    xerrwd_(msg, &c__39, &c__6, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L707:
    s_copy(msg, "DASKR--  SOME ELEMENT OF ATOL IS .LT. 0", (ftnlen)80, (
	    ftnlen)39);
    xerrwd_(msg, &c__39, &c__7, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L708:
    s_copy(msg, "DASKR--  ALL ELEMENTS OF RTOL AND ATOL ARE ZERO", (ftnlen)80,
	     (ftnlen)47);
    xerrwd_(msg, &c__47, &c__8, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L709:
    s_copy(msg, "DASKR--  INFO(4) = 1 AND TSTOP (=R1) BEHIND TOUT (=R2)", (
	    ftnlen)80, (ftnlen)54);
    xerrwd_(msg, &c__54, &c__9, &c__0, &c__0, &c__0, &c__0, &c__2, &tstop, 
	    tout, (ftnlen)80);
    goto L750;
L710:
    s_copy(msg, "DASKR--  HMAX (=R1) .LT. 0.0", (ftnlen)80, (ftnlen)28);
    xerrwd_(msg, &c__28, &c__10, &c__0, &c__0, &c__0, &c__0, &c__1, &hmax, &
	    c_b83, (ftnlen)80);
    goto L750;
L711:
    s_copy(msg, "DASKR--  TOUT (=R1) BEHIND T (=R2)", (ftnlen)80, (ftnlen)34);
    xerrwd_(msg, &c__34, &c__11, &c__0, &c__0, &c__0, &c__0, &c__2, tout, t, (
	    ftnlen)80);
    goto L750;
L712:
    s_copy(msg, "DASKR--  INFO(8)=1 AND H0=0.0", (ftnlen)80, (ftnlen)29);
    xerrwd_(msg, &c__29, &c__12, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L713:
    s_copy(msg, "DASKR--  SOME ELEMENT OF WT IS .LE. 0.0", (ftnlen)80, (
	    ftnlen)39);
    xerrwd_(msg, &c__39, &c__13, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L714:
    s_copy(msg, "DASKR-- TOUT (=R1) TOO CLOSE TO T (=R2) TO START INTEGRATION"
	    , (ftnlen)80, (ftnlen)60);
    xerrwd_(msg, &c__60, &c__14, &c__0, &c__0, &c__0, &c__0, &c__2, tout, t, (
	    ftnlen)80);
    goto L750;
L715:
    s_copy(msg, "DASKR--  INFO(4)=1 AND TSTOP (=R1) BEHIND T (=R2)", (ftnlen)
	    80, (ftnlen)49);
    xerrwd_(msg, &c__49, &c__15, &c__0, &c__0, &c__0, &c__0, &c__2, &tstop, t,
	     (ftnlen)80);
    goto L750;
L717:
    s_copy(msg, "DASKR--  ML (=I1) ILLEGAL. EITHER .LT. 0 OR .GT. NEQ", (
	    ftnlen)80, (ftnlen)52);
    xerrwd_(msg, &c__52, &c__17, &c__0, &c__1, &iwork[1], &c__0, &c__0, &
	    c_b83, &c_b83, (ftnlen)80);
    goto L750;
L718:
    s_copy(msg, "DASKR--  MU (=I1) ILLEGAL. EITHER .LT. 0 OR .GT. NEQ", (
	    ftnlen)80, (ftnlen)52);
    xerrwd_(msg, &c__52, &c__18, &c__0, &c__1, &iwork[2], &c__0, &c__0, &
	    c_b83, &c_b83, (ftnlen)80);
    goto L750;
L719:
    s_copy(msg, "DASKR--  TOUT (=R1) IS EQUAL TO T (=R2)", (ftnlen)80, (
	    ftnlen)39);
    xerrwd_(msg, &c__39, &c__19, &c__0, &c__0, &c__0, &c__0, &c__2, tout, t, (
	    ftnlen)80);
    goto L750;
L720:
    s_copy(msg, "DASKR--  MAXL (=I1) ILLEGAL. EITHER .LT. 1 OR .GT. NEQ", (
	    ftnlen)80, (ftnlen)54);
    xerrwd_(msg, &c__54, &c__20, &c__0, &c__1, &iwork[24], &c__0, &c__0, &
	    c_b83, &c_b83, (ftnlen)80);
    goto L750;
L721:
    s_copy(msg, "DASKR--  KMP (=I1) ILLEGAL. EITHER .LT. 1 OR .GT. MAXL", (
	    ftnlen)80, (ftnlen)54);
    xerrwd_(msg, &c__54, &c__21, &c__0, &c__1, &iwork[25], &c__0, &c__0, &
	    c_b83, &c_b83, (ftnlen)80);
    goto L750;
L722:
    s_copy(msg, "DASKR--  NRMAX (=I1) ILLEGAL. .LT. 0", (ftnlen)80, (ftnlen)
	    36);
    xerrwd_(msg, &c__36, &c__22, &c__0, &c__1, &iwork[26], &c__0, &c__0, &
	    c_b83, &c_b83, (ftnlen)80);
    goto L750;
L723:
    s_copy(msg, "DASKR--  EPLI (=R1) ILLEGAL. EITHER .LE. 0.D0 OR .GE. 1.D0", 
	    (ftnlen)80, (ftnlen)58);
    xerrwd_(msg, &c__58, &c__23, &c__0, &c__0, &c__0, &c__0, &c__1, &rwork[10]
	    , &c_b83, (ftnlen)80);
    goto L750;
L724:
    s_copy(msg, "DASKR--  ILLEGAL IWORK VALUE FOR INFO(11) .NE. 0", (ftnlen)
	    80, (ftnlen)48);
    xerrwd_(msg, &c__48, &c__24, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L725:
    s_copy(msg, "DASKR--  ONE OF THE INPUTS FOR INFO(17) = 1 IS ILLEGAL", (
	    ftnlen)80, (ftnlen)54);
    xerrwd_(msg, &c__54, &c__25, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L726:
    s_copy(msg, "DASKR--  ILLEGAL IWORK VALUE FOR INFO(10) .NE. 0", (ftnlen)
	    80, (ftnlen)48);
    xerrwd_(msg, &c__48, &c__26, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L727:
    s_copy(msg, "DASKR--  Y(I) AND IWORK(40+I) (I=I1) INCONSISTENT", (ftnlen)
	    80, (ftnlen)49);
    xerrwd_(msg, &c__49, &c__27, &c__0, &c__1, &iret, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L730:
    s_copy(msg, "DASKR--  NRT (=I1) .LT. 0", (ftnlen)80, (ftnlen)25);
    xerrwd_(msg, &c__25, &c__30, &c__1, &c__1, nrt, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    goto L750;
L731:
    s_copy(msg, "DASKR--  R IS ILL-DEFINED.  ZERO VALUES WERE FOUND AT TWO", (
	    ftnlen)80, (ftnlen)57);
    xerrwd_(msg, &c__57, &c__31, &c__1, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    s_copy(msg, "         VERY CLOSE T VALUES, AT T = R1", (ftnlen)80, (
	    ftnlen)39);
    xerrwd_(msg, &c__39, &c__31, &c__1, &c__0, &c__0, &c__0, &c__1, &rwork[51]
	    , &c_b83, (ftnlen)80);

L750:
    if (info[1] == -1) {
	goto L760;
    }
    info[1] = -1;
    *idid = -33;
    return 0;
L760:
    s_copy(msg, "DASKR--  REPEATED OCCURRENCES OF ILLEGAL INPUT", (ftnlen)80, 
	    (ftnlen)46);
    xerrwd_(msg, &c__46, &c__701, &c__0, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
/* L770: */
    s_copy(msg, "DASKR--  RUN TERMINATED. APPARENT INFINITE LOOP", (ftnlen)80,
	     (ftnlen)47);
    xerrwd_(msg, &c__47, &c__702, &c__1, &c__0, &c__0, &c__0, &c__0, &c_b83, &
	    c_b83, (ftnlen)80);
    return 0;

/* ------END OF SUBROUTINE DDASKR----------------------------------------- */
} /* ddaskr_ */

/* Subroutine */ int drchek_(integer *job, S_fp rt, integer *nrt, integer *
	neq, doublereal *tn, doublereal *tout, doublereal *y, doublereal *yp, 
	doublereal *phi, doublereal *psi, integer *kold, doublereal *r0, 
	doublereal *r1, doublereal *rx, integer *jroot, integer *irt, 
	doublereal *uround, integer *info3, doublereal *rwork, integer *iwork,
	 doublereal *rpar, integer *ipar)
{
    /* Initialized data */

    static doublereal zero = 0.;

    /* System generated locals */
    integer phi_dim1, phi_offset, i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal h__;
    static integer i__;
    static doublereal x, t1, temp1, temp2;
    static integer jflag;
    static doublereal hminr;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static logical zroot;
    extern /* Subroutine */ int ddatrp_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *), droots_(integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);


/* ***BEGIN PROLOGUE  DRCHEK */
/* ***REFER TO DDASKR */
/* ***ROUTINES CALLED  DDATRP, DROOTS, DCOPY, RT */
/* ***REVISION HISTORY  (YYMMDD) */
/*   020815  DATE WRITTEN */
/*   021217  Added test for roots close when JOB = 2. */
/*   050510  Changed T increment after 110 so that TEMP1/H .ge. 0.1. */
/*   071003  Fixed bug in TEMP2 (HMINR) below 110. */
/*   110608  Fixed bug in setting of T1 at 300. */
/* ***END PROLOGUE  DRCHEK */

/* Pointers into IWORK: */
/* Pointers into RWORK: */
    /* Parameter adjustments */
    phi_dim1 = *neq;
    phi_offset = 1 + phi_dim1;
    phi -= phi_offset;
    --y;
    --yp;
    --psi;
    --r0;
    --r1;
    --rx;
    --jroot;
    --rwork;
    --iwork;

    /* Function Body */
/* ----------------------------------------------------------------------- */
/* This routine checks for the presence of a root of R(T,Y,Y') in the */
/* vicinity of the current T, in a manner depending on the */
/* input flag JOB.  It calls subroutine DROOTS to locate the root */
/* as precisely as possible. */

/* In addition to variables described previously, DRCHEK */
/* uses the following for communication.. */
/* JOB    = integer flag indicating type of call.. */
/*          JOB = 1 means the problem is being initialized, and DRCHEK */
/*                  is to look for a root at or very near the initial T. */
/*          JOB = 2 means a continuation call to the solver was just */
/*                  made, and DRCHEK is to check for a root in the */
/*                  relevant part of the step last taken. */
/*          JOB = 3 means a successful step was just taken, and DRCHEK */
/*                  is to look for a root in the interval of the step. */
/* R0     = array of length NRT, containing the value of R at T = T0. */
/*          R0 is input for JOB .ge. 2 and on output in all cases. */
/* R1,RX  = arrays of length NRT for work space. */
/* IRT    = completion flag.. */
/*          IRT = 0  means no root was found. */
/*          IRT = -1 means JOB = 1 and a zero was found both at T0 and */
/*                   and very close to T0. */
/*          IRT = -2 means JOB = 2 and some Ri was found to have a zero */
/*                   both at T0 and very close to T0. */
/*          IRT = 1  means a legitimate root was found (JOB = 2 or 3). */
/*                   On return, T0 is the root location, and Y is the */
/*                   corresponding solution vector. */
/* T0     = value of T at one endpoint of interval of interest.  Only */
/*          roots beyond T0 in the direction of integration are sought. */
/*          T0 is input if JOB .ge. 2, and output in all cases. */
/*          T0 is updated by DRCHEK, whether a root is found or not. */
/*          Stored in the global array RWORK. */
/* TLAST  = last value of T returned by the solver (input only). */
/*          Stored in the global array RWORK. */
/* TOUT   = final output time for the solver. */
/* IRFND  = input flag showing whether the last step taken had a root. */
/*          IRFND = 1 if it did, = 0 if not. */
/*          Stored in the global array IWORK. */
/* INFO3  = copy of INFO(3) (input only). */
/* ----------------------------------------------------------------------- */

    h__ = psi[1];
    *irt = 0;
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	jroot[i__] = 0;
    }
    hminr = (abs(*tn) + abs(h__)) * *uround * 100.;

    switch (*job) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
    }

/* Evaluate R at initial T (= RWORK(LT0)); check for zero values.-------- */
L100:
    ddatrp_(tn, &rwork[51], &y[1], &yp[1], neq, kold, &phi[phi_offset], &psi[
	    1]);
    (*rt)(neq, &rwork[51], &y[1], &yp[1], nrt, &r0[1], rpar, ipar);
    iwork[36] = 1;
    zroot = FALSE_;
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L110: */
	if ((d__1 = r0[i__], abs(d__1)) == zero) {
	    zroot = TRUE_;
	}
    }
    if (! zroot) {
	goto L190;
    }
/* R has a zero at T.  Look at R at T + (small increment). -------------- */
/* Computing MAX */
    d__1 = hminr / abs(h__);
    temp2 = max(d__1,.1);
    temp1 = temp2 * h__;
    rwork[51] += temp1;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L120: */
	y[i__] += temp2 * phi[i__ + (phi_dim1 << 1)];
    }
    (*rt)(neq, &rwork[51], &y[1], &yp[1], nrt, &r0[1], rpar, ipar);
    ++iwork[36];
    zroot = FALSE_;
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L130: */
	if ((d__1 = r0[i__], abs(d__1)) == zero) {
	    zroot = TRUE_;
	}
    }
    if (! zroot) {
	goto L190;
    }
/* R has a zero at T and also close to T.  Take error return. ----------- */
    *irt = -1;
    return 0;

L190:
    return 0;

L200:
    if (iwork[37] == 0) {
	goto L260;
    }
/* If a root was found on the previous step, evaluate R0 = R(T0). ------- */
    ddatrp_(tn, &rwork[51], &y[1], &yp[1], neq, kold, &phi[phi_offset], &psi[
	    1]);
    (*rt)(neq, &rwork[51], &y[1], &yp[1], nrt, &r0[1], rpar, ipar);
    ++iwork[36];
    zroot = FALSE_;
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = r0[i__], abs(d__1)) == zero) {
	    zroot = TRUE_;
	    jroot[i__] = 1;
	}
/* L210: */
    }
    if (! zroot) {
	goto L260;
    }
/* R has a zero at T0.  Look at R at T0+ = T0 + (small increment). ------ */
    temp1 = d_sign(&hminr, &h__);
    rwork[51] += temp1;
    if ((rwork[51] - *tn) * h__ < zero) {
	goto L230;
    }
    temp2 = temp1 / h__;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L220: */
	y[i__] += temp2 * phi[i__ + (phi_dim1 << 1)];
    }
    goto L240;
L230:
    ddatrp_(tn, &rwork[51], &y[1], &yp[1], neq, kold, &phi[phi_offset], &psi[
	    1]);
L240:
    (*rt)(neq, &rwork[51], &y[1], &yp[1], nrt, &r0[1], rpar, ipar);
    ++iwork[36];
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = r0[i__], abs(d__1)) > zero) {
	    goto L250;
	}
/* If Ri has a zero at both T0+ and T0, return an error flag. ----------- */
	if (jroot[i__] == 1) {
	    *irt = -2;
	    return 0;
	} else {
/* If Ri has a zero at T0+, but not at T0, return valid root. ----------- */
	    jroot[i__] = (integer) (-d_sign(&c_b3, &r0[i__]));
	    *irt = 1;
	}
L250:
	;
    }
    if (*irt == 1) {
	return 0;
    }
/* R0 has no zero components.  Proceed to check relevant interval. ------ */
L260:
    if (*tn == rwork[52]) {
	return 0;
    }

L300:
/* Set T1 to TN or TOUT, whichever comes first, and get R at T1. -------- */
    if ((*tout - *tn) * h__ >= zero) {
	t1 = *tn;
	goto L330;
    }
    t1 = *tout;
    if ((t1 - rwork[51]) * h__ <= zero) {
	goto L390;
    }
L330:
    ddatrp_(tn, &t1, &y[1], &yp[1], neq, kold, &phi[phi_offset], &psi[1]);
    (*rt)(neq, &t1, &y[1], &yp[1], nrt, &r1[1], rpar, ipar);
    ++iwork[36];
/* Call DROOTS to search for root in interval from T0 to T1. ------------ */
    jflag = 0;
L350:
    droots_(nrt, &hminr, &jflag, &rwork[51], &t1, &r0[1], &r1[1], &rx[1], &x, 
	    &jroot[1]);
    if (jflag > 1) {
	goto L360;
    }
    ddatrp_(tn, &x, &y[1], &yp[1], neq, kold, &phi[phi_offset], &psi[1]);
    (*rt)(neq, &x, &y[1], &yp[1], nrt, &rx[1], rpar, ipar);
    ++iwork[36];
    goto L350;
L360:
    rwork[51] = x;
    dcopy_(nrt, &rx[1], &c__1, &r0[1], &c__1);
    if (jflag == 4) {
	goto L390;
    }
/* Found a root.  Interpolate to X and return. -------------------------- */
    ddatrp_(tn, &x, &y[1], &yp[1], neq, kold, &phi[phi_offset], &psi[1]);
    *irt = 1;
    return 0;

L390:
    return 0;
/* ---------------------- END OF SUBROUTINE DRCHEK ----------------------- */
} /* drchek_ */

/* Subroutine */ int droots_(integer *nrt, doublereal *hmin, integer *jflag, 
	doublereal *x0, doublereal *x1, doublereal *r0, doublereal *r1, 
	doublereal *rx, doublereal *x, integer *jroot)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal tenth = .1;
    static doublereal half = .5;
    static doublereal five = 5.;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal t2, x2;
    static integer imax, last;
    static doublereal tmax, alpha;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static logical xroot, zroot, sgnchg;
    static integer imxold, nxlast;
    static doublereal fracsub, fracint;


/* ***BEGIN PROLOGUE  DROOTS */
/* ***REFER TO DRCHEK */
/* ***ROUTINES CALLED DCOPY */
/* ***REVISION HISTORY  (YYMMDD) */
/*   020815  DATE WRITTEN */
/*   021217  Added root direction information in JROOT. */
/*   040518  Changed adjustment to X2 at 180 to avoid infinite loop. */
/* ***END PROLOGUE  DROOTS */

/* ----------------------------------------------------------------------- */
/* This subroutine finds the leftmost root of a set of arbitrary */
/* functions Ri(x) (i = 1,...,NRT) in an interval (X0,X1).  Only roots */
/* of odd multiplicity (i.e. changes of sign of the Ri) are found. */
/* Here the sign of X1 - X0 is arbitrary, but is constant for a given */
/* problem, and -leftmost- means nearest to X0. */
/* The values of the vector-valued function R(x) = (Ri, i=1...NRT) */
/* are communicated through the call sequence of DROOTS. */
/* The method used is the Illinois algorithm. */

/* Reference: */
/* Kathie L. Hiebert and Lawrence F. Shampine, Implicitly Defined */
/* Output Points for Solutions of ODEs, Sandia Report SAND80-0180, */
/* February 1980. */

/* Description of parameters. */

/* NRT    = number of functions Ri, or the number of components of */
/*          the vector valued function R(x).  Input only. */

/* HMIN   = resolution parameter in X.  Input only.  When a root is */
/*          found, it is located only to within an error of HMIN in X. */
/*          Typically, HMIN should be set to something on the order of */
/*               100 * UROUND * MAX(ABS(X0),ABS(X1)), */
/*          where UROUND is the unit roundoff of the machine. */

/* JFLAG  = integer flag for input and output communication. */

/*          On input, set JFLAG = 0 on the first call for the problem, */
/*          and leave it unchanged until the problem is completed. */
/*          (The problem is completed when JFLAG .ge. 2 on return.) */

/*          On output, JFLAG has the following values and meanings: */
/*          JFLAG = 1 means DROOTS needs a value of R(x).  Set RX = R(X) */
/*                    and call DROOTS again. */
/*          JFLAG = 2 means a root has been found.  The root is */
/*                    at X, and RX contains R(X).  (Actually, X is the */
/*                    rightmost approximation to the root on an interval */
/*                    (X0,X1) of size HMIN or less.) */
/*          JFLAG = 3 means X = X1 is a root, with one or more of the Ri */
/*                    being zero at X1 and no sign changes in (X0,X1). */
/*                    RX contains R(X) on output. */
/*          JFLAG = 4 means no roots (of odd multiplicity) were */
/*                    found in (X0,X1) (no sign changes). */

/* X0,X1  = endpoints of the interval where roots are sought. */
/*          X1 and X0 are input when JFLAG = 0 (first call), and */
/*          must be left unchanged between calls until the problem is */
/*          completed.  X0 and X1 must be distinct, but X1 - X0 may be */
/*          of either sign.  However, the notion of -left- and -right- */
/*          will be used to mean nearer to X0 or X1, respectively. */
/*          When JFLAG .ge. 2 on return, X0 and X1 are output, and */
/*          are the endpoints of the relevant interval. */

/* R0,R1  = arrays of length NRT containing the vectors R(X0) and R(X1), */
/*          respectively.  When JFLAG = 0, R0 and R1 are input and */
/*          none of the R0(i) should be zero. */
/*          When JFLAG .ge. 2 on return, R0 and R1 are output. */

/* RX     = array of length NRT containing R(X).  RX is input */
/*          when JFLAG = 1, and output when JFLAG .ge. 2. */

/* X      = independent variable value.  Output only. */
/*          When JFLAG = 1 on output, X is the point at which R(x) */
/*          is to be evaluated and loaded into RX. */
/*          When JFLAG = 2 or 3, X is the root. */
/*          When JFLAG = 4, X is the right endpoint of the interval, X1. */

/* JROOT  = integer array of length NRT.  Output only. */
/*          When JFLAG = 2 or 3, JROOT indicates which components */
/*          of R(x) have a root at X, and the direction of the sign */
/*          change across the root in the direction of integration. */
/*          JROOT(i) =  1 if Ri has a root and changes from - to +. */
/*          JROOT(i) = -1 if Ri has a root and changes from + to -. */
/*          Otherwise JROOT(i) = 0. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --jroot;
    --rx;
    --r1;
    --r0;

    /* Function Body */

    if (*jflag == 1) {
	goto L200;
    }
/* JFLAG .ne. 1.  Check for change in sign of R or zero at X1. ---------- */
    imax = 0;
    tmax = zero;
    zroot = FALSE_;
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = r1[i__], abs(d__1)) > zero) {
	    goto L110;
	}
	zroot = TRUE_;
	goto L120;
/* At this point, R0(i) has been checked and cannot be zero. ------------ */
L110:
	if (d_sign(&c_b3, &r0[i__]) == d_sign(&c_b3, &r1[i__])) {
	    goto L120;
	}
	t2 = (d__1 = r1[i__] / (r1[i__] - r0[i__]), abs(d__1));
	if (t2 <= tmax) {
	    goto L120;
	}
	tmax = t2;
	imax = i__;
L120:
	;
    }
    if (imax > 0) {
	goto L130;
    }
    sgnchg = FALSE_;
    goto L140;
L130:
    sgnchg = TRUE_;
L140:
    if (! sgnchg) {
	goto L400;
    }
/* There is a sign change.  Find the first root in the interval. -------- */
    xroot = FALSE_;
    nxlast = 0;
    last = 1;

/* Repeat until the first root in the interval is found.  Loop point. --- */
L150:
    if (xroot) {
	goto L300;
    }
    if (nxlast == last) {
	goto L160;
    }
    alpha = 1.;
    goto L180;
L160:
    if (last == 0) {
	goto L170;
    }
    alpha *= .5;
    goto L180;
L170:
    alpha *= 2.;
L180:
    x2 = *x1 - (*x1 - *x0) * r1[imax] / (r1[imax] - alpha * r0[imax]);
    if ((d__1 = x2 - *x0, abs(d__1)) < half * *hmin) {
	fracint = (d__1 = *x1 - *x0, abs(d__1)) / *hmin;
	if (fracint > five) {
	    fracsub = tenth;
	} else {
	    fracsub = half / fracint;
	}
	x2 = *x0 + fracsub * (*x1 - *x0);
    }
    if ((d__1 = *x1 - x2, abs(d__1)) < half * *hmin) {
	fracint = (d__1 = *x1 - *x0, abs(d__1)) / *hmin;
	if (fracint > five) {
	    fracsub = tenth;
	} else {
	    fracsub = half / fracint;
	}
	x2 = *x1 - fracsub * (*x1 - *x0);
    }
    *jflag = 1;
    *x = x2;
/* Return to the calling routine to get a value of RX = R(X). ----------- */
    return 0;
/* Check to see in which interval R changes sign. ----------------------- */
L200:
    imxold = imax;
    imax = 0;
    tmax = zero;
    zroot = FALSE_;
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = rx[i__], abs(d__1)) > zero) {
	    goto L210;
	}
	zroot = TRUE_;
	goto L220;
/* Neither R0(i) nor RX(i) can be zero at this point. ------------------- */
L210:
	if (d_sign(&c_b3, &r0[i__]) == d_sign(&c_b3, &rx[i__])) {
	    goto L220;
	}
	t2 = (d__1 = rx[i__] / (rx[i__] - r0[i__]), abs(d__1));
	if (t2 <= tmax) {
	    goto L220;
	}
	tmax = t2;
	imax = i__;
L220:
	;
    }
    if (imax > 0) {
	goto L230;
    }
    sgnchg = FALSE_;
    imax = imxold;
    goto L240;
L230:
    sgnchg = TRUE_;
L240:
    nxlast = last;
    if (! sgnchg) {
	goto L250;
    }
/* Sign change between X0 and X2, so replace X1 with X2. ---------------- */
    *x1 = x2;
    dcopy_(nrt, &rx[1], &c__1, &r1[1], &c__1);
    last = 1;
    xroot = FALSE_;
    goto L270;
L250:
    if (! zroot) {
	goto L260;
    }
/* Zero value at X2 and no sign change in (X0,X2), so X2 is a root. ----- */
    *x1 = x2;
    dcopy_(nrt, &rx[1], &c__1, &r1[1], &c__1);
    xroot = TRUE_;
    goto L270;
/* No sign change between X0 and X2.  Replace X0 with X2. --------------- */
L260:
    dcopy_(nrt, &rx[1], &c__1, &r0[1], &c__1);
    *x0 = x2;
    last = 0;
    xroot = FALSE_;
L270:
    if ((d__1 = *x1 - *x0, abs(d__1)) <= *hmin) {
	xroot = TRUE_;
    }
    goto L150;

/* Return with X1 as the root.  Set JROOT.  Set X = X1 and RX = R1. ----- */
L300:
    *jflag = 2;
    *x = *x1;
    dcopy_(nrt, &r1[1], &c__1, &rx[1], &c__1);
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jroot[i__] = 0;
	if ((d__1 = r1[i__], abs(d__1)) == zero) {
	    jroot[i__] = (integer) (-d_sign(&c_b3, &r0[i__]));
	    goto L320;
	}
	if (d_sign(&c_b3, &r0[i__]) != d_sign(&c_b3, &r1[i__])) {
	    d__1 = r1[i__] - r0[i__];
	    jroot[i__] = (integer) d_sign(&c_b3, &d__1);
	}
L320:
	;
    }
    return 0;

/* No sign change in the interval.  Check for zero at right endpoint. --- */
L400:
    if (! zroot) {
	goto L420;
    }

/* Zero value at X1 and no sign change in (X0,X1).  Return JFLAG = 3. --- */
    *x = *x1;
    dcopy_(nrt, &r1[1], &c__1, &rx[1], &c__1);
    i__1 = *nrt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jroot[i__] = 0;
	if ((d__1 = r1[i__], abs(d__1)) == zero) {
	    jroot[i__] = (integer) (-d_sign(&c_b3, &r0[i__]));
	}
/* L410: */
    }
    *jflag = 3;
    return 0;

/* No sign changes in this interval.  Set X = X1, return JFLAG = 4. ----- */
L420:
    dcopy_(nrt, &r1[1], &c__1, &rx[1], &c__1);
    *x = *x1;
    *jflag = 4;
    return 0;
/* ----------------------- END OF SUBROUTINE DROOTS ---------------------- */
} /* droots_ */

/* Subroutine */ int ddasic_(doublereal *x, doublereal *y, doublereal *yprime,
	 integer *neq, integer *icopt, integer *id, U_fp res, U_fp jac, U_fp 
	psol, doublereal *h__, doublereal *tscale, doublereal *wt, integer *
	nic, integer *idid, doublereal *rpar, integer *ipar, doublereal *phi, 
	doublereal *savr, doublereal *delta, doublereal *e, doublereal *yic, 
	doublereal *ypic, doublereal *pwk, doublereal *wm, integer *iwm, 
	doublereal *uround, doublereal *epli, doublereal *sqrtn, doublereal *
	rsqrtn, doublereal *epconi, doublereal *stptol, integer *jflg, 
	integer *icnflg, integer *icnstr, S_fp nlsic)
{
    /* Initialized data */

    static doublereal rhcut = .1;
    static doublereal ratemx = .8;

    /* System generated locals */
    integer phi_dim1, phi_offset;

    /* Local variables */
    static doublereal cj;
    static integer nh, mxnh;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static integer jskip, iernls;


/* ***BEGIN PROLOGUE  DDASIC */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   940628   (YYMMDD) */
/* ***REVISION DATE  941206   (YYMMDD) */
/* ***REVISION DATE  950714   (YYMMDD) */
/* ***REVISION DATE  000628   TSCALE argument added. */

/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DDASIC is a driver routine to compute consistent initial values */
/*     for Y and YPRIME.  There are two different options: */
/*     Denoting the differential variables in Y by Y_d, and */
/*     the algebraic variables by Y_a, the problem solved is either: */
/*     1.  Given Y_d, calculate Y_a and Y_d', or */
/*     2.  Given Y', calculate Y. */
/*     In either case, initial values for the given components */
/*     are input, and initial guesses for the unknown components */
/*     must also be provided as input. */

/*     The external routine NLSIC solves the resulting nonlinear system. */

/*     The parameters represent */

/*     X  --        Independent variable. */
/*     Y  --        Solution vector at X. */
/*     YPRIME --    Derivative of solution vector. */
/*     NEQ --       Number of equations to be integrated. */
/*     ICOPT     -- Flag indicating initial condition option chosen. */
/*                    ICOPT = 1 for option 1 above. */
/*                    ICOPT = 2 for option 2. */
/*     ID        -- Array of dimension NEQ, which must be initialized */
/*                  if option 1 is chosen. */
/*                    ID(i) = +1 if Y_i is a differential variable, */
/*                    ID(i) = -1 if Y_i is an algebraic variable. */
/*     RES --       External user-supplied subroutine to evaluate the */
/*                  residual.  See RES description in DDASPK prologue. */
/*     JAC --       External user-supplied routine to update Jacobian */
/*                  or preconditioner information in the nonlinear solver */
/*                  (optional).  See JAC description in DDASPK prologue. */
/*     PSOL --      External user-supplied routine to solve */
/*                  a linear system using preconditioning. */
/*                  See PSOL in DDASPK prologue. */
/*     H --         Scaling factor in iteration matrix.  DDASIC may */
/*                  reduce H to achieve convergence. */
/*     TSCALE --    Scale factor in T, used for stopping tests if nonzero. */
/*     WT --        Vector of weights for error criterion. */
/*     NIC --       Input number of initial condition calculation call */
/*                  (= 1 or 2). */
/*     IDID --      Completion code.  See IDID in DDASPK prologue. */
/*     RPAR,IPAR -- Real and integer parameter arrays that */
/*                  are used for communication between the */
/*                  calling program and external user routines. */
/*                  They are not altered by DNSK */
/*     PHI --       Work space for DDASIC of length at least 2*NEQ. */
/*     SAVR --      Work vector for DDASIC of length NEQ. */
/*     DELTA --     Work vector for DDASIC of length NEQ. */
/*     E --         Work vector for DDASIC of length NEQ. */
/*     YIC,YPIC --  Work vectors for DDASIC, each of length NEQ. */
/*     PWK --       Work vector for DDASIC of length NEQ. */
/*     WM,IWM --    Real and integer arrays storing */
/*                  information required by the linear solver. */
/*     EPCONI --    Test constant for Newton iteration convergence. */
/*     ICNFLG --    Flag showing whether constraints on Y are to apply. */
/*     ICNSTR --    Integer array of length NEQ with constraint types. */

/*     The other parameters are for use internally by DDASIC. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DCOPY, NLSIC */

/* ***END PROLOGUE  DDASIC */




/* The following parameters are data-loaded here: */
/*     RHCUT  = factor by which H is reduced on retry of Newton solve. */
/*     RATEMX = maximum convergence rate for which Newton iteration */
/*              is considered converging. */

    /* Parameter adjustments */
    --y;
    --yprime;
    phi_dim1 = *neq;
    phi_offset = 1 + phi_dim1;
    phi -= phi_offset;
    --id;
    --wt;
    --rpar;
    --ipar;
    --savr;
    --delta;
    --e;
    --yic;
    --ypic;
    --pwk;
    --wm;
    --iwm;
    --icnstr;

    /* Function Body */


/* ----------------------------------------------------------------------- */
/*     BLOCK 1. */
/*     Initializations. */
/*     JSKIP is a flag set to 1 when NIC = 2 and NH = 1, to signal that */
/*     the initial call to the JAC routine is to be skipped then. */
/*     Save Y and YPRIME in PHI.  Initialize IDID, NH, and CJ. */
/* ----------------------------------------------------------------------- */

    mxnh = iwm[34];
    *idid = 1;
    nh = 1;
    jskip = 0;
    if (*nic == 2) {
	jskip = 1;
    }
    dcopy_(neq, &y[1], &c__1, &phi[phi_dim1 + 1], &c__1);
    dcopy_(neq, &yprime[1], &c__1, &phi[(phi_dim1 << 1) + 1], &c__1);

    if (*icopt == 2) {
	cj = 0.;
    } else {
	cj = 1. / *h__;
    }

/* ----------------------------------------------------------------------- */
/*     BLOCK 2 */
/*     Call the nonlinear system solver to obtain */
/*     consistent initial values for Y and YPRIME. */
/* ----------------------------------------------------------------------- */

L200:
    (*nlsic)(x, &y[1], &yprime[1], neq, icopt, &id[1], (U_fp)res, (U_fp)jac, (
	    U_fp)psol, h__, tscale, &wt[1], &jskip, &rpar[1], &ipar[1], &savr[
	    1], &delta[1], &e[1], &yic[1], &ypic[1], &pwk[1], &wm[1], &iwm[1],
	     &cj, uround, epli, sqrtn, rsqrtn, epconi, &ratemx, stptol, jflg, 
	    icnflg, &icnstr[1], &iernls);

    if (iernls == 0) {
	return 0;
    }

/* ----------------------------------------------------------------------- */
/*     BLOCK 3 */
/*     The nonlinear solver was unsuccessful.  Increment NCFN. */
/*     Return with IDID = -12 if either */
/*       IERNLS = -1: error is considered unrecoverable, */
/*       ICOPT = 2: we are doing initialization problem type 2, or */
/*       NH = MXNH: the maximum number of H values has been tried. */
/*     Otherwise (problem 1 with IERNLS .GE. 1), reduce H and try again. */
/*     If IERNLS > 1, restore Y and YPRIME to their original values. */
/* ----------------------------------------------------------------------- */

    ++iwm[15];
    jskip = 0;

    if (iernls == -1) {
	goto L350;
    }
    if (*icopt == 2) {
	goto L350;
    }
    if (nh == mxnh) {
	goto L350;
    }

    ++nh;
    *h__ *= rhcut;
    cj = 1. / *h__;

    if (iernls == 1) {
	goto L200;
    }

    dcopy_(neq, &phi[phi_dim1 + 1], &c__1, &y[1], &c__1);
    dcopy_(neq, &phi[(phi_dim1 << 1) + 1], &c__1, &yprime[1], &c__1);
    goto L200;

L350:
    *idid = -12;
    return 0;

/* ------END OF SUBROUTINE DDASIC----------------------------------------- */
} /* ddasic_ */

/* Subroutine */ int dyypnw_(integer *neq, doublereal *y, doublereal *yprime, 
	doublereal *cj, doublereal *rl, doublereal *p, integer *icopt, 
	integer *id, doublereal *ynew, doublereal *ypnew)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/* ***BEGIN PROLOGUE  DYYPNW */
/* ***REFER TO  DLINSK */
/* ***DATE WRITTEN   940830   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DYYPNW calculates the new (Y,YPRIME) pair needed in the */
/*     linesearch algorithm based on the current lambda value.  It is */
/*     called by DLINSK and DLINSD.  Based on the ICOPT and ID values, */
/*     the corresponding entry in Y or YPRIME is updated. */

/*     In addition to the parameters described in the calling programs, */
/*     the parameters represent */

/*     P      -- Array of length NEQ that contains the current */
/*               approximate Newton step. */
/*     RL     -- Scalar containing the current lambda value. */
/*     YNEW   -- Array of length NEQ containing the updated Y vector. */
/*     YPNEW  -- Array of length NEQ containing the updated YPRIME */
/*               vector. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED (NONE) */

/* ***END PROLOGUE  DYYPNW */



    /* Parameter adjustments */
    --ypnew;
    --ynew;
    --id;
    --p;
    --yprime;
    --y;

    /* Function Body */
    if (*icopt == 1) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (id[i__] < 0) {
		ynew[i__] = y[i__] - *rl * p[i__];
		ypnew[i__] = yprime[i__];
	    } else {
		ynew[i__] = y[i__];
		ypnew[i__] = yprime[i__] - *rl * *cj * p[i__];
	    }
/* L10: */
	}
    } else {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ynew[i__] = y[i__] - *rl * p[i__];
	    ypnew[i__] = yprime[i__];
/* L20: */
	}
    }
    return 0;
/* ----------------------- END OF SUBROUTINE DYYPNW ---------------------- */
} /* dyypnw_ */

/* Subroutine */ int ddstp_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, U_fp res, U_fp jac, U_fp psol, doublereal *h__, 
	doublereal *wt, doublereal *vt, integer *jstart, integer *idid, 
	doublereal *rpar, integer *ipar, doublereal *phi, doublereal *savr, 
	doublereal *delta, doublereal *e, doublereal *wm, integer *iwm, 
	doublereal *alpha, doublereal *beta, doublereal *gamma, doublereal *
	psi, doublereal *sigma, doublereal *cj, doublereal *cjold, doublereal 
	*hold, doublereal *s, doublereal *hmin, doublereal *uround, 
	doublereal *epli, doublereal *sqrtn, doublereal *rsqrtn, doublereal *
	epcon, integer *iphase, integer *jcalc, integer *jflg, integer *k, 
	integer *kold, integer *ns, integer *nonneg, integer *ntype, S_fp nls)
{
    /* System generated locals */
    integer phi_dim1, phi_offset, i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal r__;
    static integer j1;
    static doublereal ck;
    static integer km1, kp1, kp2, ncf, nef;
    static doublereal erk, err, est;
    static integer nsp1;
    static doublereal hnew, terk, xold;
    static integer knew;
    static doublereal erkm1, erkm2, erkp1, temp1, temp2;
    static integer kdiff;
    static doublereal enorm, alpha0, terkm1, terkm2, terkp1, alphas;
    extern /* Subroutine */ int ddatrp_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *);
    static doublereal cjlast;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer iernls;


/* ***BEGIN PROLOGUE  DDSTP */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  940909   (YYMMDD) (Reset PSI(1), PHI(*,2) at 690) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DDSTP solves a system of differential/algebraic equations of */
/*     the form G(X,Y,YPRIME) = 0, for one step (normally from X to X+H). */

/*     The methods used are modified divided difference, fixed leading */
/*     coefficient forms of backward differentiation formulas. */
/*     The code adjusts the stepsize and order to control the local error */
/*     per step. */


/*     The parameters represent */
/*     X  --        Independent variable. */
/*     Y  --        Solution vector at X. */
/*     YPRIME --    Derivative of solution vector */
/*                  after successful step. */
/*     NEQ --       Number of equations to be integrated. */
/*     RES --       External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     JAC --       External user-supplied routine to update */
/*                  Jacobian or preconditioner information in the */
/*                  nonlinear solver.  See JAC description in DDASPK */
/*                  prologue. */
/*     PSOL --      External user-supplied routine to solve */
/*                  a linear system using preconditioning. */
/*                  (This is optional).  See PSOL in DDASPK prologue. */
/*     H --         Appropriate step size for next step. */
/*                  Normally determined by the code. */
/*     WT --        Vector of weights for error criterion used in Newton test. */
/*     VT --        Masked vector of weights used in error test. */
/*     JSTART --    Integer variable set 0 for */
/*                  first step, 1 otherwise. */
/*     IDID --      Completion code returned from the nonlinear solver. */
/*                  See IDID description in DDASPK prologue. */
/*     RPAR,IPAR -- Real and integer parameter arrays that */
/*                  are used for communication between the */
/*                  calling program and external user routines. */
/*                  They are not altered by DNSK */
/*     PHI --       Array of divided differences used by */
/*                  DDSTP. The length is NEQ*(K+1), where */
/*                  K is the maximum order. */
/*     SAVR --      Work vector for DDSTP of length NEQ. */
/*     DELTA,E --   Work vectors for DDSTP of length NEQ. */
/*     WM,IWM --    Real and integer arrays storing */
/*                  information required by the linear solver. */

/*     The other parameters are information */
/*     which is needed internally by DDSTP to */
/*     continue from step to step. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   NLS, DDWNRM, DDATRP */

/* ***END PROLOGUE  DDSTP */





/* ----------------------------------------------------------------------- */
/*     BLOCK 1. */
/*     Initialize.  On the first call, set */
/*     the order to 1 and initialize */
/*     other variables. */
/* ----------------------------------------------------------------------- */

/*     Initializations for all calls */

    /* Parameter adjustments */
    --y;
    --yprime;
    phi_dim1 = *neq;
    phi_offset = 1 + phi_dim1;
    phi -= phi_offset;
    --wt;
    --vt;
    --rpar;
    --ipar;
    --savr;
    --delta;
    --e;
    --wm;
    --iwm;
    --alpha;
    --beta;
    --gamma;
    --psi;
    --sigma;

    /* Function Body */
    xold = *x;
    ncf = 0;
    nef = 0;
    if (*jstart != 0) {
	goto L120;
    }

/*     If this is the first step, perform */
/*     other initializations */

    *k = 1;
    *kold = 0;
    *hold = 0.;
    psi[1] = *h__;
    *cj = 1. / *h__;
    *iphase = 0;
    *ns = 0;
L120:





/* ----------------------------------------------------------------------- */
/*     BLOCK 2 */
/*     Compute coefficients of formulas for */
/*     this step. */
/* ----------------------------------------------------------------------- */
L200:
    kp1 = *k + 1;
    kp2 = *k + 2;
    km1 = *k - 1;
    if (*h__ != *hold || *k != *kold) {
	*ns = 0;
    }
/* Computing MIN */
    i__1 = *ns + 1, i__2 = *kold + 2;
    *ns = min(i__1,i__2);
    nsp1 = *ns + 1;
    if (kp1 < *ns) {
	goto L230;
    }

    beta[1] = 1.;
    alpha[1] = 1.;
    temp1 = *h__;
    gamma[1] = 0.;
    sigma[1] = 1.;
    i__1 = kp1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	temp2 = psi[i__ - 1];
	psi[i__ - 1] = temp1;
	beta[i__] = beta[i__ - 1] * psi[i__ - 1] / temp2;
	temp1 = temp2 + *h__;
	alpha[i__] = *h__ / temp1;
	sigma[i__] = (i__ - 1) * sigma[i__ - 1] * alpha[i__];
	gamma[i__] = gamma[i__ - 1] + alpha[i__ - 1] / *h__;
/* L210: */
    }
    psi[kp1] = temp1;
L230:

/*     Compute ALPHAS, ALPHA0 */

    alphas = 0.;
    alpha0 = 0.;
    i__1 = *k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	alphas -= 1. / i__;
	alpha0 -= alpha[i__];
/* L240: */
    }

/*     Compute leading coefficient CJ */

    cjlast = *cj;
    *cj = -alphas / *h__;

/*     Compute variable stepsize error coefficient CK */

    ck = (d__1 = alpha[kp1] + alphas - alpha0, abs(d__1));
/* Computing MAX */
    d__1 = ck, d__2 = alpha[kp1];
    ck = max(d__1,d__2);

/*     Change PHI to PHI STAR */

    if (kp1 < nsp1) {
	goto L280;
    }
    i__1 = kp1;
    for (j = nsp1; j <= i__1; ++j) {
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L260: */
	    phi[i__ + j * phi_dim1] = beta[j] * phi[i__ + j * phi_dim1];
	}
/* L270: */
    }
L280:

/*     Update time */

    *x += *h__;

/*     Initialize IDID to 1 */

    *idid = 1;





/* ----------------------------------------------------------------------- */
/*     BLOCK 3 */
/*     Call the nonlinear system solver to obtain the solution and */
/*     derivative. */
/* ----------------------------------------------------------------------- */

    (*nls)(x, &y[1], &yprime[1], neq, (U_fp)res, (U_fp)jac, (U_fp)psol, h__, &
	    wt[1], jstart, idid, &rpar[1], &ipar[1], &phi[phi_offset], &gamma[
	    1], &savr[1], &delta[1], &e[1], &wm[1], &iwm[1], cj, cjold, &
	    cjlast, s, uround, epli, sqrtn, rsqrtn, epcon, jcalc, jflg, &kp1, 
	    nonneg, ntype, &iernls);

    if (iernls != 0) {
	goto L600;
    }





/* ----------------------------------------------------------------------- */
/*     BLOCK 4 */
/*     Estimate the errors at orders K,K-1,K-2 */
/*     as if constant stepsize was used. Estimate */
/*     the local error at order K and test */
/*     whether the current step is successful. */
/* ----------------------------------------------------------------------- */

/*     Estimate errors at orders K,K-1,K-2 */

    enorm = ddwnrm_(neq, &e[1], &vt[1], &rpar[1], &ipar[1]);
    erk = sigma[*k + 1] * enorm;
    terk = (*k + 1) * erk;
    est = erk;
    knew = *k;
    if (*k == 1) {
	goto L430;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L405: */
	delta[i__] = phi[i__ + kp1 * phi_dim1] + e[i__];
    }
    erkm1 = sigma[*k] * ddwnrm_(neq, &delta[1], &vt[1], &rpar[1], &ipar[1]);
    terkm1 = *k * erkm1;
    if (*k > 2) {
	goto L410;
    }
    if (terkm1 <= terk * .5f) {
	goto L420;
    }
    goto L430;
L410:
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L415: */
	delta[i__] = phi[i__ + *k * phi_dim1] + delta[i__];
    }
    erkm2 = sigma[*k - 1] * ddwnrm_(neq, &delta[1], &vt[1], &rpar[1], &ipar[1]
	    );
    terkm2 = (*k - 1) * erkm2;
    if (max(terkm1,terkm2) > terk) {
	goto L430;
    }

/*     Lower the order */

L420:
    knew = *k - 1;
    est = erkm1;


/*     Calculate the local error for the current step */
/*     to see if the step was successful */

L430:
    err = ck * enorm;
    if (err > 1.) {
	goto L600;
    }





/* ----------------------------------------------------------------------- */
/*     BLOCK 5 */
/*     The step is successful. Determine */
/*     the best order and stepsize for */
/*     the next step. Update the differences */
/*     for the next step. */
/* ----------------------------------------------------------------------- */
    *idid = 1;
    ++iwm[11];
    kdiff = *k - *kold;
    *kold = *k;
    *hold = *h__;


/*     Estimate the error at order K+1 unless */
/*        already decided to lower order, or */
/*        already using maximum order, or */
/*        stepsize not constant, or */
/*        order raised in previous step */

    if (knew == km1 || *k == iwm[3]) {
	*iphase = 1;
    }
    if (*iphase == 0) {
	goto L545;
    }
    if (knew == km1) {
	goto L540;
    }
    if (*k == iwm[3]) {
	goto L550;
    }
    if (kp1 >= *ns || kdiff == 1) {
	goto L550;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L510: */
	delta[i__] = e[i__] - phi[i__ + kp2 * phi_dim1];
    }
    erkp1 = 1. / (*k + 2) * ddwnrm_(neq, &delta[1], &vt[1], &rpar[1], &ipar[1]
	    );
    terkp1 = (*k + 2) * erkp1;
    if (*k > 1) {
	goto L520;
    }
    if (terkp1 >= terk * .5) {
	goto L550;
    }
    goto L530;
L520:
    if (terkm1 <= min(terk,terkp1)) {
	goto L540;
    }
    if (terkp1 >= terk || *k == iwm[3]) {
	goto L550;
    }

/*     Raise order */

L530:
    *k = kp1;
    est = erkp1;
    goto L550;

/*     Lower order */

L540:
    *k = km1;
    est = erkm1;
    goto L550;

/*     If IPHASE = 0, increase order by one and multiply stepsize by */
/*     factor two */

L545:
    *k = kp1;
    hnew = *h__ * 2.;
    *h__ = hnew;
    goto L575;


/*     Determine the appropriate stepsize for */
/*     the next step. */

L550:
    hnew = *h__;
    temp2 = (doublereal) (*k + 1);
    d__1 = est * 2. + 1e-4;
    d__2 = -1. / temp2;
    r__ = pow_dd(&d__1, &d__2);
    if (r__ < 2.) {
	goto L555;
    }
    hnew = *h__ * 2.;
    goto L560;
L555:
    if (r__ > 1.) {
	goto L560;
    }
/* Computing MAX */
    d__1 = .5, d__2 = min(.9,r__);
    r__ = max(d__1,d__2);
    hnew = *h__ * r__;
L560:
    *h__ = hnew;


/*     Update differences for next step */

L575:
    if (*kold == iwm[3]) {
	goto L585;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L580: */
	phi[i__ + kp2 * phi_dim1] = e[i__];
    }
L585:
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L590: */
	phi[i__ + kp1 * phi_dim1] += e[i__];
    }
    i__1 = kp1;
    for (j1 = 2; j1 <= i__1; ++j1) {
	j = kp1 - j1 + 1;
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L595: */
	    phi[i__ + j * phi_dim1] += phi[i__ + (j + 1) * phi_dim1];
	}
    }
    *jstart = 1;
    return 0;





/* ----------------------------------------------------------------------- */
/*     BLOCK 6 */
/*     The step is unsuccessful. Restore X,PSI,PHI */
/*     Determine appropriate stepsize for */
/*     continuing the integration, or exit with */
/*     an error flag if there have been many */
/*     failures. */
/* ----------------------------------------------------------------------- */
L600:
    *iphase = 1;

/*     Restore X,PHI,PSI */

    *x = xold;
    if (kp1 < nsp1) {
	goto L630;
    }
    i__2 = kp1;
    for (j = nsp1; j <= i__2; ++j) {
	temp1 = 1. / beta[j];
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L610: */
	    phi[i__ + j * phi_dim1] = temp1 * phi[i__ + j * phi_dim1];
	}
/* L620: */
    }
L630:
    i__2 = kp1;
    for (i__ = 2; i__ <= i__2; ++i__) {
/* L640: */
	psi[i__ - 1] = psi[i__] - *h__;
    }


/*     Test whether failure is due to nonlinear solver */
/*     or error test */

    if (iernls == 0) {
	goto L660;
    }
    ++iwm[15];


/*     The nonlinear solver failed to converge. */
/*     Determine the cause of the failure and take appropriate action. */
/*     If IERNLS .LT. 0, then return.  Otherwise, reduce the stepsize */
/*     and try again, unless too many failures have occurred. */

    if (iernls < 0) {
	goto L675;
    }
    ++ncf;
    r__ = .25;
    *h__ *= r__;
    if (ncf < 10 && abs(*h__) >= *hmin) {
	goto L690;
    }
    if (*idid == 1) {
	*idid = -7;
    }
    if (nef >= 3) {
	*idid = -9;
    }
    goto L675;


/*     The nonlinear solver converged, and the cause */
/*     of the failure was the error estimate */
/*     exceeding the tolerance. */

L660:
    ++nef;
    ++iwm[14];
    if (nef > 1) {
	goto L665;
    }

/*     On first error test failure, keep current order or lower */
/*     order by one.  Compute new stepsize based on differences */
/*     of the solution. */

    *k = knew;
    temp2 = (doublereal) (*k + 1);
    d__1 = est * 2. + 1e-4;
    d__2 = -1. / temp2;
    r__ = pow_dd(&d__1, &d__2) * .9;
/* Computing MAX */
    d__1 = .25, d__2 = min(.9,r__);
    r__ = max(d__1,d__2);
    *h__ *= r__;
    if (abs(*h__) >= *hmin) {
	goto L690;
    }
    *idid = -6;
    goto L675;

/*     On second error test failure, use the current order or */
/*     decrease order by one.  Reduce the stepsize by a factor of */
/*     one quarter. */

L665:
    if (nef > 2) {
	goto L670;
    }
    *k = knew;
    r__ = .25;
    *h__ = r__ * *h__;
    if (abs(*h__) >= *hmin) {
	goto L690;
    }
    *idid = -6;
    goto L675;

/*     On third and subsequent error test failures, set the order to */
/*     one, and reduce the stepsize by a factor of one quarter. */

L670:
    *k = 1;
    r__ = .25;
    *h__ = r__ * *h__;
    if (abs(*h__) >= *hmin) {
	goto L690;
    }
    *idid = -6;
    goto L675;




/*     For all crashes, restore Y to its last value, */
/*     interpolate to find YPRIME at last X, and return. */

/*     Before returning, verify that the user has not set */
/*     IDID to a nonnegative value.  If the user has set IDID */
/*     to a nonnegative value, then reset IDID to be -7, indicating */
/*     a failure in the nonlinear system solver. */

L675:
    ddatrp_(x, x, &y[1], &yprime[1], neq, k, &phi[phi_offset], &psi[1]);
    *jstart = 1;
    if (*idid >= 0) {
	*idid = -7;
    }
    return 0;


/*     Go back and try this step again. */
/*     If this is the first step, reset PSI(1) and rescale PHI(*,2). */

L690:
    if (*kold == 0) {
	psi[1] = *h__;
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L695: */
	    phi[i__ + (phi_dim1 << 1)] = r__ * phi[i__ + (phi_dim1 << 1)];
	}
    }
    goto L200;

/* ------END OF SUBROUTINE DDSTP------------------------------------------ */
} /* ddstp_ */

/* Subroutine */ int dcnstr_(integer *neq, doublereal *y, doublereal *ynew, 
	integer *icnstr, doublereal *tau, doublereal *rlx, integer *iret, 
	integer *ivar)
{
    /* Initialized data */

    static doublereal fac = .6;
    static doublereal fac2 = .9;
    static doublereal zero = 0.;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal rdy, rdymx;


/* ***BEGIN PROLOGUE  DCNSTR */
/* ***DATE WRITTEN   950808   (YYMMDD) */
/* ***REVISION DATE  950814   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* This subroutine checks for constraint violations in the proposed */
/* new approximate solution YNEW. */
/* If a constraint violation occurs, then a new step length, TAU, */
/* is calculated, and this value is to be given to the linesearch routine */
/* to calculate a new approximate solution YNEW. */

/* On entry: */

/*   NEQ    -- size of the nonlinear system, and the length of arrays */
/*             Y, YNEW and ICNSTR. */

/*   Y      -- real array containing the current approximate y. */

/*   YNEW   -- real array containing the new approximate y. */

/*   ICNSTR -- INTEGER array of length NEQ containing flags indicating */
/*             which entries in YNEW are to be constrained. */
/*             if ICNSTR(I) =  2, then YNEW(I) must be .GT. 0, */
/*             if ICNSTR(I) =  1, then YNEW(I) must be .GE. 0, */
/*             if ICNSTR(I) = -1, then YNEW(I) must be .LE. 0, while */
/*             if ICNSTR(I) = -2, then YNEW(I) must be .LT. 0, while */
/*             if ICNSTR(I) =  0, then YNEW(I) is not constrained. */

/*   RLX    -- real scalar restricting update, if ICNSTR(I) = 2 or -2, */
/*             to ABS( (YNEW-Y)/Y ) < FAC2*RLX in component I. */

/*   TAU    -- the current size of the step length for the linesearch. */

/* On return */

/*   TAU    -- the adjusted size of the step length if a constraint */
/*             violation occurred (otherwise, it is unchanged).  it is */
/*             the step length to give to the linesearch routine. */

/*   IRET   -- output flag. */
/*             IRET=0 means that YNEW satisfied all constraints. */
/*             IRET=1 means that YNEW failed to satisfy all the */
/*                    constraints, and a new linesearch step */
/*                    must be computed. */

/*   IVAR   -- index of variable causing constraint to be violated. */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --icnstr;
    --ynew;
    --y;

    /* Function Body */
/* ----------------------------------------------------------------------- */
/* Check constraints for proposed new step YNEW.  If a constraint has */
/* been violated, then calculate a new step length, TAU, to be */
/* used in the linesearch routine. */
/* ----------------------------------------------------------------------- */
    *iret = 0;
    rdymx = zero;
    *ivar = 0;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {

	if (icnstr[i__] == 2) {
	    rdy = (d__1 = (ynew[i__] - y[i__]) / y[i__], abs(d__1));
	    if (rdy > rdymx) {
		rdymx = rdy;
		*ivar = i__;
	    }
	    if (ynew[i__] <= zero) {
		*tau = fac * *tau;
		*ivar = i__;
		*iret = 1;
		return 0;
	    }

	} else if (icnstr[i__] == 1) {
	    if (ynew[i__] < zero) {
		*tau = fac * *tau;
		*ivar = i__;
		*iret = 1;
		return 0;
	    }

	} else if (icnstr[i__] == -1) {
	    if (ynew[i__] > zero) {
		*tau = fac * *tau;
		*ivar = i__;
		*iret = 1;
		return 0;
	    }

	} else if (icnstr[i__] == -2) {
	    rdy = (d__1 = (ynew[i__] - y[i__]) / y[i__], abs(d__1));
	    if (rdy > rdymx) {
		rdymx = rdy;
		*ivar = i__;
	    }
	    if (ynew[i__] >= zero) {
		*tau = fac * *tau;
		*ivar = i__;
		*iret = 1;
		return 0;
	    }

	}
/* L100: */
    }
    if (rdymx >= *rlx) {
	*tau = fac2 * *tau * *rlx / rdymx;
	*iret = 1;
    }

    return 0;
/* ----------------------- END OF SUBROUTINE DCNSTR ---------------------- */
} /* dcnstr_ */

/* Subroutine */ int dcnst0_(integer *neq, doublereal *y, integer *icnstr, 
	integer *iret)
{
    /* Initialized data */

    static doublereal zero = 0.;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/* ***BEGIN PROLOGUE  DCNST0 */
/* ***DATE WRITTEN   950808   (YYMMDD) */
/* ***REVISION DATE  950808   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* This subroutine checks for constraint violations in the initial */
/* approximate solution u. */

/* On entry */

/*   NEQ    -- size of the nonlinear system, and the length of arrays */
/*             Y and ICNSTR. */

/*   Y      -- real array containing the initial approximate root. */

/*   ICNSTR -- INTEGER array of length NEQ containing flags indicating */
/*             which entries in Y are to be constrained. */
/*             if ICNSTR(I) =  2, then Y(I) must be .GT. 0, */
/*             if ICNSTR(I) =  1, then Y(I) must be .GE. 0, */
/*             if ICNSTR(I) = -1, then Y(I) must be .LE. 0, while */
/*             if ICNSTR(I) = -2, then Y(I) must be .LT. 0, while */
/*             if ICNSTR(I) =  0, then Y(I) is not constrained. */

/* On return */

/*   IRET   -- output flag. */
/*             IRET=0    means that u satisfied all constraints. */
/*             IRET.NE.0 means that Y(IRET) failed to satisfy its */
/*                       constraint. */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --icnstr;
    --y;

    /* Function Body */
/* ----------------------------------------------------------------------- */
/* Check constraints for initial Y.  If a constraint has been violated, */
/* set IRET = I to signal an error return to calling routine. */
/* ----------------------------------------------------------------------- */
    *iret = 0;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (icnstr[i__] == 2) {
	    if (y[i__] <= zero) {
		*iret = i__;
		return 0;
	    }
	} else if (icnstr[i__] == 1) {
	    if (y[i__] < zero) {
		*iret = i__;
		return 0;
	    }
	} else if (icnstr[i__] == -1) {
	    if (y[i__] > zero) {
		*iret = i__;
		return 0;
	    }
	} else if (icnstr[i__] == -2) {
	    if (y[i__] >= zero) {
		*iret = i__;
		return 0;
	    }
	}
/* L100: */
    }
    return 0;
/* ----------------------- END OF SUBROUTINE DCNST0 ---------------------- */
} /* dcnst0_ */

/* Subroutine */ int ddawts_(integer *neq, integer *iwt, doublereal *rtol, 
	doublereal *atol, doublereal *y, doublereal *wt, doublereal *rpar, 
	integer *ipar)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal atoli, rtoli;


/* ***BEGIN PROLOGUE  DDAWTS */
/* ***REFER TO  DDASPK */
/* ***ROUTINES CALLED  (NONE) */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***END PROLOGUE  DDAWTS */
/* ----------------------------------------------------------------------- */
/*     This subroutine sets the error weight vector, */
/*     WT, according to WT(I)=RTOL(I)*ABS(Y(I))+ATOL(I), */
/*     I = 1 to NEQ. */
/*     RTOL and ATOL are scalars if IWT = 0, */
/*     and vectors if IWT = 1. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --ipar;
    --rpar;
    --wt;
    --y;
    --atol;
    --rtol;

    /* Function Body */
    rtoli = rtol[1];
    atoli = atol[1];
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*iwt == 0) {
	    goto L10;
	}
	rtoli = rtol[i__];
	atoli = atol[i__];
L10:
	wt[i__] = rtoli * (d__1 = y[i__], abs(d__1)) + atoli;
/* L20: */
    }
    return 0;

/* ------END OF SUBROUTINE DDAWTS----------------------------------------- */
} /* ddawts_ */

/* Subroutine */ int dinvwt_(integer *neq, doublereal *wt, integer *ier)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/* ***BEGIN PROLOGUE  DINVWT */
/* ***REFER TO  DDASPK */
/* ***ROUTINES CALLED  (NONE) */
/* ***DATE WRITTEN   950125   (YYMMDD) */
/* ***END PROLOGUE  DINVWT */
/* ----------------------------------------------------------------------- */
/*     This subroutine checks the error weight vector WT, of length NEQ, */
/*     for components that are .le. 0, and if none are found, it */
/*     inverts the WT(I) in place.  This replaces division operations */
/*     with multiplications in all norm evaluations. */
/*     IER is returned as 0 if all WT(I) were found positive, */
/*     and the first I with WT(I) .le. 0.0 otherwise. */
/* ----------------------------------------------------------------------- */


    /* Parameter adjustments */
    --wt;

    /* Function Body */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (wt[i__] <= 0.) {
	    goto L30;
	}
/* L10: */
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	wt[i__] = 1. / wt[i__];
    }
    *ier = 0;
    return 0;

L30:
    *ier = i__;
    return 0;

/* ------END OF SUBROUTINE DINVWT----------------------------------------- */
} /* dinvwt_ */

/* Subroutine */ int ddatrp_(doublereal *x, doublereal *xout, doublereal *
	yout, doublereal *ypout, integer *neq, integer *kold, doublereal *phi,
	 doublereal *psi)
{
    /* System generated locals */
    integer phi_dim1, phi_offset, i__1, i__2;

    /* Local variables */
    static doublereal c__, d__;
    static integer i__, j;
    static doublereal temp1, gamma;
    static integer koldp1;


/* ***BEGIN PROLOGUE  DDATRP */
/* ***REFER TO  DDASPK */
/* ***ROUTINES CALLED  (NONE) */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***END PROLOGUE  DDATRP */

/* ----------------------------------------------------------------------- */
/*     The methods in subroutine DDSTP use polynomials */
/*     to approximate the solution.  DDATRP approximates the */
/*     solution and its derivative at time XOUT by evaluating */
/*     one of these polynomials, and its derivative, there. */
/*     Information defining this polynomial is passed from */
/*     DDSTP, so DDATRP cannot be used alone. */

/*     The parameters are */

/*     X     The current time in the integration. */
/*     XOUT  The time at which the solution is desired. */
/*     YOUT  The interpolated approximation to Y at XOUT. */
/*           (This is output.) */
/*     YPOUT The interpolated approximation to YPRIME at XOUT. */
/*           (This is output.) */
/*     NEQ   Number of equations. */
/*     KOLD  Order used on last successful step. */
/*     PHI   Array of scaled divided differences of Y. */
/*     PSI   Array of past stepsize history. */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --yout;
    --ypout;
    phi_dim1 = *neq;
    phi_offset = 1 + phi_dim1;
    phi -= phi_offset;
    --psi;

    /* Function Body */
    koldp1 = *kold + 1;
    temp1 = *xout - *x;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	yout[i__] = phi[i__ + phi_dim1];
/* L10: */
	ypout[i__] = 0.;
    }
    c__ = 1.;
    d__ = 0.;
    gamma = temp1 / psi[1];
    i__1 = koldp1;
    for (j = 2; j <= i__1; ++j) {
	d__ = d__ * gamma + c__ / psi[j - 1];
	c__ *= gamma;
	gamma = (temp1 + psi[j - 1]) / psi[j];
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    yout[i__] += c__ * phi[i__ + j * phi_dim1];
/* L20: */
	    ypout[i__] += d__ * phi[i__ + j * phi_dim1];
	}
/* L30: */
    }
    return 0;

/* ------END OF SUBROUTINE DDATRP----------------------------------------- */
} /* ddatrp_ */

doublereal ddwnrm_(integer *neq, doublereal *v, doublereal *rwt, doublereal *
	rpar, integer *ipar)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val, d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal sum, vmax;


/* ***BEGIN PROLOGUE  DDWNRM */
/* ***ROUTINES CALLED  (NONE) */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***END PROLOGUE  DDWNRM */
/* ----------------------------------------------------------------------- */
/*     This function routine computes the weighted */
/*     root-mean-square norm of the vector of length */
/*     NEQ contained in the array V, with reciprocal weights */
/*     contained in the array RWT of length NEQ. */
/*        DDWNRM=SQRT((1/NEQ)*SUM(V(I)*RWT(I))**2) */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --ipar;
    --rpar;
    --rwt;
    --v;

    /* Function Body */
    ret_val = 0.;
    vmax = 0.;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = v[i__] * rwt[i__], abs(d__1)) > vmax) {
	    vmax = (d__2 = v[i__] * rwt[i__], abs(d__2));
	}
/* L10: */
    }
    if (vmax <= 0.) {
	goto L30;
    }
    sum = 0.;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
/* Computing 2nd power */
	d__1 = v[i__] * rwt[i__] / vmax;
	sum += d__1 * d__1;
    }
    ret_val = vmax * sqrt(sum / *neq);
L30:
    return ret_val;

/* ------END OF FUNCTION DDWNRM------------------------------------------- */
} /* ddwnrm_ */

/* Subroutine */ int ddasid_(doublereal *x, doublereal *y, doublereal *yprime,
	 integer *neq, integer *icopt, integer *id, S_fp res, U_fp jacd, 
	doublereal *pdum, doublereal *h__, doublereal *tscale, doublereal *wt,
	 integer *jsdum, doublereal *rpar, integer *ipar, doublereal *dumsvr, 
	doublereal *delta, doublereal *r__, doublereal *yic, doublereal *ypic,
	 doublereal *dumpwk, doublereal *wm, integer *iwm, doublereal *cj, 
	doublereal *uround, doublereal *dume, doublereal *dums, doublereal *
	dumr, doublereal *epcon, doublereal *ratemx, doublereal *stptol, 
	integer *jfdum, integer *icnflg, integer *icnstr, integer *iernls)
{
    static integer nj, ierj, ires, mxnj;
    extern /* Subroutine */ int dmatd_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, integer *, S_fp, 
	    integer *, doublereal *, U_fp, doublereal *, integer *), dnsid_(
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, S_fp, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, integer *, doublereal *, integer *, integer *, 
	    integer *);
    static integer mxnit, iernew;


/* ***BEGIN PROLOGUE  DDASID */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   940701   (YYMMDD) */
/* ***REVISION DATE  950808   (YYMMDD) */
/* ***REVISION DATE  951110   Removed unreachable block 390. */
/* ***REVISION DATE  000628   TSCALE argument added. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */


/*     DDASID solves a nonlinear system of algebraic equations of the */
/*     form G(X,Y,YPRIME) = 0 for the unknown parts of Y and YPRIME in */
/*     the initial conditions. */

/*     The method used is a modified Newton scheme. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of unknowns. */
/*     ICOPT     -- Initial condition option chosen (1 or 2). */
/*     ID        -- Array of dimension NEQ, which must be initialized */
/*                  if ICOPT = 1.  See DDASIC. */
/*     RES       -- External user-supplied subroutine to evaluate the */
/*                  residual.  See RES description in DDASPK prologue. */
/*     JACD      -- External user-supplied routine to evaluate the */
/*                  Jacobian.  See JAC description for the case */
/*                  INFO(12) = 0 in the DDASPK prologue. */
/*     PDUM      -- Dummy argument. */
/*     H         -- Scaling factor for this initial condition calc. */
/*     TSCALE    -- Scale factor in T, used for stopping tests if nonzero. */
/*     WT        -- Vector of weights for error criterion. */
/*     JSDUM     -- Dummy argument. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     DUMSVR    -- Dummy argument. */
/*     DELTA     -- Work vector for NLS of length NEQ. */
/*     R         -- Work vector for NLS of length NEQ. */
/*     YIC,YPIC  -- Work vectors for NLS, each of length NEQ. */
/*     DUMPWK    -- Dummy argument. */
/*     WM,IWM    -- Real and integer arrays storing matrix information */
/*                  such as the matrix of partial derivatives, */
/*                  permutation vector, and various other information. */
/*     CJ        -- Matrix parameter = 1/H (ICOPT = 1) or 0 (ICOPT = 2). */
/*     UROUND    -- Unit roundoff. */
/*     DUME      -- Dummy argument. */
/*     DUMS      -- Dummy argument. */
/*     DUMR      -- Dummy argument. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     RATEMX    -- Maximum convergence rate for which Newton iteration */
/*                  is considered converging. */
/*     JFDUM     -- Dummy argument. */
/*     STPTOL    -- Tolerance used in calculating the minimum lambda */
/*                  value allowed. */
/*     ICNFLG    -- Integer scalar.  If nonzero, then constraint */
/*                  violations in the proposed new approximate solution */
/*                  will be checked for, and the maximum step length */
/*                  will be adjusted accordingly. */
/*     ICNSTR    -- Integer array of length NEQ containing flags for */
/*                  checking constraints. */
/*     IERNLS    -- Error flag for nonlinear solver. */
/*                   0   ==> nonlinear solver converged. */
/*                   1,2 ==> recoverable error inside nonlinear solver. */
/*                           1 => retry with current Y, YPRIME */
/*                           2 => retry with original Y, YPRIME */
/*                  -1   ==> unrecoverable error in nonlinear solver. */

/*     All variables with "DUM" in their names are dummy variables */
/*     which are not used in this routine. */

/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   RES, DMATD, DNSID */

/* ***END PROLOGUE  DDASID */





/*     Perform initializations. */

    /* Parameter adjustments */
    --icnstr;
    --iwm;
    --wm;
    --ypic;
    --yic;
    --r__;
    --delta;
    --ipar;
    --rpar;
    --wt;
    --id;
    --yprime;
    --y;

    /* Function Body */
    mxnit = iwm[32];
    mxnj = iwm[33];
    *iernls = 0;
    nj = 0;

/*     Call RES to initialize DELTA. */

    ires = 0;
    ++iwm[12];
    (*res)(x, &y[1], &yprime[1], cj, &delta[1], &ires, &rpar[1], &ipar[1]);
    if (ires < 0) {
	goto L370;
    }

/*     Looping point for updating the Jacobian. */

L300:

/*     Initialize all error flags to zero. */

    ierj = 0;
    ires = 0;
    iernew = 0;

/*     Reevaluate the iteration matrix, J = dG/dY + CJ*dG/dYPRIME, */
/*     where G(X,Y,YPRIME) = 0. */

    ++nj;
    ++iwm[13];
    dmatd_(neq, x, &y[1], &yprime[1], &delta[1], cj, h__, &ierj, &wt[1], &r__[
	    1], &wm[1], &iwm[1], (S_fp)res, &ires, uround, (U_fp)jacd, &rpar[
	    1], &ipar[1]);
    if (ires < 0 || ierj != 0) {
	goto L370;
    }

/*     Call the nonlinear Newton solver for up to MXNIT iterations. */

    dnsid_(x, &y[1], &yprime[1], neq, icopt, &id[1], (S_fp)res, &wt[1], &rpar[
	    1], &ipar[1], &delta[1], &r__[1], &yic[1], &ypic[1], &wm[1], &iwm[
	    1], cj, tscale, epcon, ratemx, &mxnit, stptol, icnflg, &icnstr[1],
	     &iernew);

    if (iernew == 1 && nj < mxnj) {

/*        MXNIT iterations were done, the convergence rate is < 1, */
/*        and the number of Jacobian evaluations is less than MXNJ. */
/*        Call RES, reevaluate the Jacobian, and try again. */

	++iwm[12];
	(*res)(x, &y[1], &yprime[1], cj, &delta[1], &ires, &rpar[1], &ipar[1])
		;
	if (ires < 0) {
	    goto L370;
	}
	goto L300;
    }

    if (iernew != 0) {
	goto L380;
    }
    return 0;


/*     Unsuccessful exits from nonlinear solver. */
/*     Compute IERNLS accordingly. */

L370:
    *iernls = 2;
    if (ires <= -2) {
	*iernls = -1;
    }
    return 0;

L380:
    *iernls = min(iernew,2);
    return 0;

/* ------END OF SUBROUTINE DDASID----------------------------------------- */
} /* ddasid_ */

/* Subroutine */ int dnsid_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, integer *icopt, integer *id, S_fp res, doublereal *wt, 
	doublereal *rpar, integer *ipar, doublereal *delta, doublereal *r__, 
	doublereal *yic, doublereal *ypic, doublereal *wm, integer *iwm, 
	doublereal *cj, doublereal *tscale, doublereal *epcon, doublereal *
	ratemx, integer *maxit, doublereal *stptol, integer *icnflg, integer *
	icnstr, integer *iernew)
{
    static integer m;
    static doublereal rlx, rate, fnrm;
    static integer iret, ires, lsoff;
    extern /* Subroutine */ int dslvd_(integer *, doublereal *, doublereal *, 
	    integer *), dcopy_(integer *, doublereal *, integer *, doublereal 
	    *, integer *), dlinsd_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, integer *, 
	    S_fp, integer *, doublereal *, integer *, doublereal *, integer *,
	     integer *, doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *);
    static doublereal oldfnm, delnrm;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);


/* ***BEGIN PROLOGUE  DNSID */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   940701   (YYMMDD) */
/* ***REVISION DATE  950713   (YYMMDD) */
/* ***REVISION DATE  000628   TSCALE argument added. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DNSID solves a nonlinear system of algebraic equations of the */
/*     form G(X,Y,YPRIME) = 0 for the unknown parts of Y and YPRIME */
/*     in the initial conditions. */

/*     The method used is a modified Newton scheme. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of unknowns. */
/*     ICOPT     -- Initial condition option chosen (1 or 2). */
/*     ID        -- Array of dimension NEQ, which must be initialized */
/*                  if ICOPT = 1.  See DDASIC. */
/*     RES       -- External user-supplied subroutine to evaluate the */
/*                  residual.  See RES description in DDASPK prologue. */
/*     WT        -- Vector of weights for error criterion. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     DELTA     -- Residual vector on entry, and work vector of */
/*                  length NEQ for DNSID. */
/*     WM,IWM    -- Real and integer arrays storing matrix information */
/*                  such as the matrix of partial derivatives, */
/*                  permutation vector, and various other information. */
/*     CJ        -- Matrix parameter = 1/H (ICOPT = 1) or 0 (ICOPT = 2). */
/*     TSCALE    -- Scale factor in T, used for stopping tests if nonzero. */
/*     R         -- Array of length NEQ used as workspace by the */
/*                  linesearch routine DLINSD. */
/*     YIC,YPIC  -- Work vectors for DLINSD, each of length NEQ. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     RATEMX    -- Maximum convergence rate for which Newton iteration */
/*                  is considered converging. */
/*     MAXIT     -- Maximum allowed number of Newton iterations. */
/*     STPTOL    -- Tolerance used in calculating the minimum lambda */
/*                  value allowed. */
/*     ICNFLG    -- Integer scalar.  If nonzero, then constraint */
/*                  violations in the proposed new approximate solution */
/*                  will be checked for, and the maximum step length */
/*                  will be adjusted accordingly. */
/*     ICNSTR    -- Integer array of length NEQ containing flags for */
/*                  checking constraints. */
/*     IERNEW    -- Error flag for Newton iteration. */
/*                   0  ==> Newton iteration converged. */
/*                   1  ==> failed to converge, but RATE .le. RATEMX. */
/*                   2  ==> failed to converge, RATE .gt. RATEMX. */
/*                   3  ==> other recoverable error (IRES = -1, or */
/*                          linesearch failed). */
/*                  -1  ==> unrecoverable error (IRES = -2). */

/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   DSLVD, DDWNRM, DLINSD, DCOPY */

/* ***END PROLOGUE  DNSID */





/*     Initializations.  M is the Newton iteration counter. */

    /* Parameter adjustments */
    --icnstr;
    --iwm;
    --wm;
    --ypic;
    --yic;
    --r__;
    --delta;
    --ipar;
    --rpar;
    --wt;
    --id;
    --yprime;
    --y;

    /* Function Body */
    lsoff = iwm[35];
    m = 0;
    rate = 1.;
    rlx = .4;

/*     Compute a new step vector DELTA by back-substitution. */

    dslvd_(neq, &delta[1], &wm[1], &iwm[1]);

/*     Get norm of DELTA.  Return now if norm(DELTA) .le. EPCON. */

    delnrm = ddwnrm_(neq, &delta[1], &wt[1], &rpar[1], &ipar[1]);
    fnrm = delnrm;
    if (*tscale > 0.) {
	fnrm = fnrm * *tscale * abs(*cj);
    }
    if (fnrm <= *epcon) {
	return 0;
    }

/*     Newton iteration loop. */

L300:
    ++iwm[19];

/*     Call linesearch routine for global strategy and set RATE */

    oldfnm = fnrm;

    dlinsd_(neq, &y[1], x, &yprime[1], cj, tscale, &delta[1], &delnrm, &wt[1],
	     &lsoff, stptol, &iret, (S_fp)res, &ires, &wm[1], &iwm[1], &fnrm, 
	    icopt, &id[1], &r__[1], &yic[1], &ypic[1], icnflg, &icnstr[1], &
	    rlx, &rpar[1], &ipar[1]);

    rate = fnrm / oldfnm;

/*     Check for error condition from linesearch. */
    if (iret != 0) {
	goto L390;
    }

/*     Test for convergence of the iteration, and return or loop. */

    if (fnrm <= *epcon) {
	return 0;
    }

/*     The iteration has not yet converged.  Update M. */
/*     Test whether the maximum number of iterations have been tried. */

    ++m;
    if (m >= *maxit) {
	goto L380;
    }

/*     Copy the residual to DELTA and its norm to DELNRM, and loop for */
/*     another iteration. */

    dcopy_(neq, &r__[1], &c__1, &delta[1], &c__1);
    delnrm = fnrm;
    goto L300;

/*     The maximum number of iterations was done.  Set IERNEW and return. */

L380:
    if (rate <= *ratemx) {
	*iernew = 1;
    } else {
	*iernew = 2;
    }
    return 0;

L390:
    if (ires <= -2) {
	*iernew = -1;
    } else {
	*iernew = 3;
    }
    return 0;


/* ------END OF SUBROUTINE DNSID------------------------------------------ */
} /* dnsid_ */

/* Subroutine */ int dlinsd_(integer *neq, doublereal *y, doublereal *t, 
	doublereal *yprime, doublereal *cj, doublereal *tscale, doublereal *p,
	 doublereal *pnrm, doublereal *wt, integer *lsoff, doublereal *stptol,
	 integer *iret, S_fp res, integer *ires, doublereal *wm, integer *iwm,
	 doublereal *fnrm, integer *icopt, integer *id, doublereal *r__, 
	doublereal *ynew, doublereal *ypnew, integer *icnflg, integer *icnstr,
	 doublereal *rlx, doublereal *rpar, integer *ipar)
{
    /* Initialized data */

    static doublereal alpha = 1e-4;
    static doublereal one = 1.;
    static doublereal two = 2.;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ void s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal rl;
    static char msg[80];
    static doublereal tau;
    static integer ivar;
    static doublereal slpi, f1nrm, ratio;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static doublereal rlmin, fnrmp;
    static integer kprin;
    static doublereal ratio1, f1nrmp;
    extern /* Subroutine */ int dfnrmd_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, S_fp, integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *), dcnstr_(integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *, integer *), xerrwd_(char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, doublereal 
	    *, doublereal *, ftnlen), dyypnw_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, doublereal *, doublereal *);


/* ***BEGIN PROLOGUE  DLINSD */
/* ***REFER TO  DNSID */
/* ***DATE WRITTEN   941025   (YYMMDD) */
/* ***REVISION DATE  941215   (YYMMDD) */
/* ***REVISION DATE  960129   Moved line RL = ONE to top block. */
/* ***REVISION DATE  000628   TSCALE argument added. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DLINSD uses a linesearch algorithm to calculate a new (Y,YPRIME) */
/*     pair (YNEW,YPNEW) such that */

/*     f(YNEW,YPNEW) .le. (1 - 2*ALPHA*RL)*f(Y,YPRIME) , */

/*     where 0 < RL <= 1.  Here, f(y,y') is defined as */

/*      f(y,y') = (1/2)*norm( (J-inverse)*G(t,y,y') )**2 , */

/*     where norm() is the weighted RMS vector norm, G is the DAE */
/*     system residual function, and J is the system iteration matrix */
/*     (Jacobian). */

/*     In addition to the parameters defined elsewhere, we have */

/*     TSCALE  --  Scale factor in T, used for stopping tests if nonzero. */
/*     P       -- Approximate Newton step used in backtracking. */
/*     PNRM    -- Weighted RMS norm of P. */
/*     LSOFF   -- Flag showing whether the linesearch algorithm is */
/*                to be invoked.  0 means do the linesearch, and */
/*                1 means turn off linesearch. */
/*     STPTOL  -- Tolerance used in calculating the minimum lambda */
/*                value allowed. */
/*     ICNFLG  -- Integer scalar.  If nonzero, then constraint violations */
/*                in the proposed new approximate solution will be */
/*                checked for, and the maximum step length will be */
/*                adjusted accordingly. */
/*     ICNSTR  -- Integer array of length NEQ containing flags for */
/*                checking constraints. */
/*     RLX     -- Real scalar restricting update size in DCNSTR. */
/*     YNEW    -- Array of length NEQ used to hold the new Y in */
/*                performing the linesearch. */
/*     YPNEW   -- Array of length NEQ used to hold the new YPRIME in */
/*                performing the linesearch. */
/*     Y       -- Array of length NEQ containing the new Y (i.e.,=YNEW). */
/*     YPRIME  -- Array of length NEQ containing the new YPRIME */
/*                (i.e.,=YPNEW). */
/*     FNRM    -- Real scalar containing SQRT(2*f(Y,YPRIME)) for the */
/*                current (Y,YPRIME) on input and output. */
/*     R       -- Work array of length NEQ, containing the scaled */
/*                residual (J-inverse)*G(t,y,y') on return. */
/*     IRET    -- Return flag. */
/*                IRET=0 means that a satisfactory (Y,YPRIME) was found. */
/*                IRET=1 means that the routine failed to find a new */
/*                       (Y,YPRIME) that was sufficiently distinct from */
/*                       the current (Y,YPRIME) pair. */
/*                IRET=2 means IRES .ne. 0 from RES. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   DFNRMD, DYYPNW, DCNSTR, DCOPY, XERRWD */

/* ***END PROLOGUE  DLINSD */



    /* Parameter adjustments */
    --ipar;
    --rpar;
    --icnstr;
    --ypnew;
    --ynew;
    --r__;
    --id;
    --iwm;
    --wm;
    --wt;
    --p;
    --yprime;
    --y;

    /* Function Body */

    kprin = iwm[31];

    f1nrm = *fnrm * *fnrm / two;
    ratio = one;
    if (kprin >= 2) {
	s_copy(msg, "------ IN ROUTINE DLINSD-- PNRM = (R1)", (ftnlen)80, (
		ftnlen)38);
	xerrwd_(msg, &c__38, &c__901, &c__0, &c__0, &c__0, &c__0, &c__1, pnrm,
		 &c_b83, (ftnlen)80);
    }
    tau = *pnrm;
    rl = one;
/* ----------------------------------------------------------------------- */
/* Check for violations of the constraints, if any are imposed. */
/* If any violations are found, the step vector P is rescaled, and the */
/* constraint check is repeated, until no violations are found. */
/* ----------------------------------------------------------------------- */
    if (*icnflg != 0) {
L10:
	dyypnw_(neq, &y[1], &yprime[1], cj, &rl, &p[1], icopt, &id[1], &ynew[
		1], &ypnew[1]);
	dcnstr_(neq, &y[1], &ynew[1], &icnstr[1], &tau, rlx, iret, &ivar);
	if (*iret == 1) {
	    ratio1 = tau / *pnrm;
	    ratio *= ratio1;
	    i__1 = *neq;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
		p[i__] *= ratio1;
	    }
	    *pnrm = tau;
	    if (kprin >= 2) {
		s_copy(msg, "------ CONSTRAINT VIOL., PNRM = (R1), INDEX = ("
			"I1)", (ftnlen)80, (ftnlen)50);
		xerrwd_(msg, &c__50, &c__902, &c__0, &c__1, &ivar, &c__0, &
			c__1, pnrm, &c_b83, (ftnlen)80);
	    }
	    if (*pnrm <= *stptol) {
		*iret = 1;
		return 0;
	    }
	    goto L10;
	}
    }

    slpi = -two * f1nrm * ratio;
    rlmin = *stptol / *pnrm;
    if (*lsoff == 0 && kprin >= 2) {
	s_copy(msg, "------ MIN. LAMBDA = (R1)", (ftnlen)80, (ftnlen)25);
	xerrwd_(msg, &c__25, &c__903, &c__0, &c__0, &c__0, &c__0, &c__1, &
		rlmin, &c_b83, (ftnlen)80);
    }
/* ----------------------------------------------------------------------- */
/* Begin iteration to find RL value satisfying alpha-condition. */
/* If RL becomes less than RLMIN, then terminate with IRET = 1. */
/* ----------------------------------------------------------------------- */
L100:
    dyypnw_(neq, &y[1], &yprime[1], cj, &rl, &p[1], icopt, &id[1], &ynew[1], &
	    ypnew[1]);
    dfnrmd_(neq, &ynew[1], t, &ypnew[1], &r__[1], cj, tscale, &wt[1], (S_fp)
	    res, ires, &fnrmp, &wm[1], &iwm[1], &rpar[1], &ipar[1]);
    ++iwm[12];
    if (*ires != 0) {
	*iret = 2;
	return 0;
    }
    if (*lsoff == 1) {
	goto L150;
    }

    f1nrmp = fnrmp * fnrmp / two;
    if (kprin >= 2) {
	s_copy(msg, "------ LAMBDA = (R1)", (ftnlen)80, (ftnlen)20);
	xerrwd_(msg, &c__20, &c__904, &c__0, &c__0, &c__0, &c__0, &c__1, &rl, 
		&c_b83, (ftnlen)80);
	s_copy(msg, "------ NORM(F1) = (R1),  NORM(F1NEW) = (R2)", (ftnlen)80,
		 (ftnlen)43);
	xerrwd_(msg, &c__43, &c__905, &c__0, &c__0, &c__0, &c__0, &c__2, &
		f1nrm, &f1nrmp, (ftnlen)80);
    }
    if (f1nrmp > f1nrm + alpha * slpi * rl) {
	goto L200;
    }
/* ----------------------------------------------------------------------- */
/* Alpha-condition is satisfied, or linesearch is turned off. */
/* Copy YNEW,YPNEW to Y,YPRIME and return. */
/* ----------------------------------------------------------------------- */
L150:
    *iret = 0;
    dcopy_(neq, &ynew[1], &c__1, &y[1], &c__1);
    dcopy_(neq, &ypnew[1], &c__1, &yprime[1], &c__1);
    *fnrm = fnrmp;
    if (kprin >= 1) {
	s_copy(msg, "------ LEAVING ROUTINE DLINSD, FNRM = (R1)", (ftnlen)80, 
		(ftnlen)42);
	xerrwd_(msg, &c__42, &c__906, &c__0, &c__0, &c__0, &c__0, &c__1, fnrm,
		 &c_b83, (ftnlen)80);
    }
    return 0;
/* ----------------------------------------------------------------------- */
/* Alpha-condition not satisfied.  Perform backtrack to compute new RL */
/* value.  If no satisfactory YNEW,YPNEW can be found sufficiently */
/* distinct from Y,YPRIME, then return IRET = 1. */
/* ----------------------------------------------------------------------- */
L200:
    if (rl < rlmin) {
	*iret = 1;
	return 0;
    }

    rl /= two;
    goto L100;

/* ----------------------- END OF SUBROUTINE DLINSD ---------------------- */
} /* dlinsd_ */

/* Subroutine */ int dfnrmd_(integer *neq, doublereal *y, doublereal *t, 
	doublereal *yprime, doublereal *r__, doublereal *cj, doublereal *
	tscale, doublereal *wt, S_fp res, integer *ires, doublereal *fnorm, 
	doublereal *wm, integer *iwm, doublereal *rpar, integer *ipar)
{
    extern /* Subroutine */ int dslvd_(integer *, doublereal *, doublereal *, 
	    integer *);
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);


/* ***BEGIN PROLOGUE  DFNRMD */
/* ***REFER TO  DLINSD */
/* ***DATE WRITTEN   941025   (YYMMDD) */
/* ***REVISION DATE  000628   TSCALE argument added. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DFNRMD calculates the scaled preconditioned norm of the nonlinear */
/*     function used in the nonlinear iteration for obtaining consistent */
/*     initial conditions.  Specifically, DFNRMD calculates the weighted */
/*     root-mean-square norm of the vector (J-inverse)*G(T,Y,YPRIME), */
/*     where J is the Jacobian matrix. */

/*     In addition to the parameters described in the calling program */
/*     DLINSD, the parameters represent */

/*     R      -- Array of length NEQ that contains */
/*               (J-inverse)*G(T,Y,YPRIME) on return. */
/*     TSCALE -- Scale factor in T, used for stopping tests if nonzero. */
/*     FNORM  -- Scalar containing the weighted norm of R on return. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   RES, DSLVD, DDWNRM */

/* ***END PROLOGUE  DFNRMD */


/* ----------------------------------------------------------------------- */
/*     Call RES routine. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ipar;
    --rpar;
    --iwm;
    --wm;
    --wt;
    --r__;
    --yprime;
    --y;

    /* Function Body */
    *ires = 0;
    (*res)(t, &y[1], &yprime[1], cj, &r__[1], ires, &rpar[1], &ipar[1]);
    if (*ires < 0) {
	return 0;
    }
/* ----------------------------------------------------------------------- */
/*     Apply inverse of Jacobian to vector R. */
/* ----------------------------------------------------------------------- */
    dslvd_(neq, &r__[1], &wm[1], &iwm[1]);
/* ----------------------------------------------------------------------- */
/*     Calculate norm of R. */
/* ----------------------------------------------------------------------- */
    *fnorm = ddwnrm_(neq, &r__[1], &wt[1], &rpar[1], &ipar[1]);
    if (*tscale > 0.) {
	*fnorm = *fnorm * *tscale * abs(*cj);
    }

    return 0;
/* ----------------------- END OF SUBROUTINE DFNRMD ---------------------- */
} /* dfnrmd_ */

/* Subroutine */ int dnedd_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, S_fp res, U_fp jacd, doublereal *pdum, doublereal *h__, 
	doublereal *wt, integer *jstart, integer *idid, doublereal *rpar, 
	integer *ipar, doublereal *phi, doublereal *gamma, doublereal *dumsvr,
	 doublereal *delta, doublereal *e, doublereal *wm, integer *iwm, 
	doublereal *cj, doublereal *cjold, doublereal *cjlast, doublereal *s, 
	doublereal *uround, doublereal *dume, doublereal *dums, doublereal *
	dumr, doublereal *epcon, integer *jcalc, integer *jfdum, integer *kp1,
	 integer *nonneg, integer *ntype, integer *iernls)
{
    /* Initialized data */

    static integer muldel = 1;
    static integer maxit = 4;
    static doublereal xrate = .25;

    /* System generated locals */
    integer phi_dim1, phi_offset, i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, ierj;
    extern /* Subroutine */ int dnsd_(doublereal *, doublereal *, doublereal *
	    , integer *, S_fp, doublereal *, doublereal *, doublereal *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     integer *, doublereal *, doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, integer 
	    *, integer *, integer *, integer *, integer *);
    static integer idum, ires;
    static doublereal temp1, temp2;
    extern /* Subroutine */ int dmatd_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, integer *, S_fp, 
	    integer *, doublereal *, U_fp, doublereal *, integer *);
    static doublereal pnorm, delnrm;
    static integer iernew;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal tolnew;
    static integer iertyp;


/* ***BEGIN PROLOGUE  DNEDD */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   891219   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DNEDD solves a nonlinear system of */
/*     algebraic equations of the form */
/*     G(X,Y,YPRIME) = 0 for the unknown Y. */

/*     The method used is a modified Newton scheme. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of unknowns. */
/*     RES       -- External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     JACD      -- External user-supplied routine to evaluate the */
/*                  Jacobian.  See JAC description for the case */
/*                  INFO(12) = 0 in the DDASPK prologue. */
/*     PDUM      -- Dummy argument. */
/*     H         -- Appropriate step size for next step. */
/*     WT        -- Vector of weights for error criterion. */
/*     JSTART    -- Indicates first call to this routine. */
/*                  If JSTART = 0, then this is the first call, */
/*                  otherwise it is not. */
/*     IDID      -- Completion flag, output by DNEDD. */
/*                  See IDID description in DDASPK prologue. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     PHI       -- Array of divided differences used by */
/*                  DNEDD.  The length is NEQ*(K+1),where */
/*                  K is the maximum order. */
/*     GAMMA     -- Array used to predict Y and YPRIME.  The length */
/*                  is MAXORD+1 where MAXORD is the maximum order. */
/*     DUMSVR    -- Dummy argument. */
/*     DELTA     -- Work vector for NLS of length NEQ. */
/*     E         -- Error accumulation vector for NLS of length NEQ. */
/*     WM,IWM    -- Real and integer arrays storing */
/*                  matrix information such as the matrix */
/*                  of partial derivatives, permutation */
/*                  vector, and various other information. */
/*     CJ        -- Parameter always proportional to 1/H. */
/*     CJOLD     -- Saves the value of CJ as of the last call to DMATD. */
/*                  Accounts for changes in CJ needed to */
/*                  decide whether to call DMATD. */
/*     CJLAST    -- Previous value of CJ. */
/*     S         -- A scalar determined by the approximate rate */
/*                  of convergence of the Newton iteration and used */
/*                  in the convergence test for the Newton iteration. */

/*                  If RATE is defined to be an estimate of the */
/*                  rate of convergence of the Newton iteration, */
/*                  then S = RATE/(1.D0-RATE). */

/*                  The closer RATE is to 0., the faster the Newton */
/*                  iteration is converging; the closer RATE is to 1., */
/*                  the slower the Newton iteration is converging. */

/*                  On the first Newton iteration with an up-dated */
/*                  preconditioner S = 100.D0, Thus the initial */
/*                  RATE of convergence is approximately 1. */

/*                  S is preserved from call to call so that the rate */
/*                  estimate from a previous step can be applied to */
/*                  the current step. */
/*     UROUND    -- Unit roundoff. */
/*     DUME      -- Dummy argument. */
/*     DUMS      -- Dummy argument. */
/*     DUMR      -- Dummy argument. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     JCALC     -- Flag used to determine when to update */
/*                  the Jacobian matrix.  In general: */

/*                  JCALC = -1 ==> Call the DMATD routine to update */
/*                                 the Jacobian matrix. */
/*                  JCALC =  0 ==> Jacobian matrix is up-to-date. */
/*                  JCALC =  1 ==> Jacobian matrix is out-dated, */
/*                                 but DMATD will not be called unless */
/*                                 JCALC is set to -1. */
/*     JFDUM     -- Dummy argument. */
/*     KP1       -- The current order(K) + 1;  updated across calls. */
/*     NONNEG    -- Flag to determine nonnegativity constraints. */
/*     NTYPE     -- Identification code for the NLS routine. */
/*                   0  ==> modified Newton; direct solver. */
/*     IERNLS    -- Error flag for nonlinear solver. */
/*                   0  ==> nonlinear solver converged. */
/*                   1  ==> recoverable error inside nonlinear solver. */
/*                  -1  ==> unrecoverable error inside nonlinear solver. */

/*     All variables with "DUM" in their names are dummy variables */
/*     which are not used in this routine. */

/*     Following is a list and description of local variables which */
/*     may not have an obvious usage.  They are listed in roughly the */
/*     order they occur in this subroutine. */

/*     The following group of variables are passed as arguments to */
/*     the Newton iteration solver.  They are explained in greater detail */
/*     in DNSD: */
/*        TOLNEW, MULDEL, MAXIT, IERNEW */

/*     IERTYP -- Flag which tells whether this subroutine is correct. */
/*               0 ==> correct subroutine. */
/*               1 ==> incorrect subroutine. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DDWNRM, RES, DMATD, DNSD */

/* ***END PROLOGUE  DNEDD */




    /* Parameter adjustments */
    --y;
    --yprime;
    phi_dim1 = *neq;
    phi_offset = 1 + phi_dim1;
    phi -= phi_offset;
    --wt;
    --rpar;
    --ipar;
    --gamma;
    --delta;
    --e;
    --wm;
    --iwm;

    /* Function Body */

/*     Verify that this is the correct subroutine. */

    iertyp = 0;
    if (*ntype != 0) {
	iertyp = 1;
	goto L380;
    }

/*     If this is the first step, perform initializations. */

    if (*jstart == 0) {
	*cjold = *cj;
	*jcalc = -1;
    }

/*     Perform all other initializations. */

    *iernls = 0;

/*     Decide whether new Jacobian is needed. */

    temp1 = (1. - xrate) / (xrate + 1.);
    temp2 = 1. / temp1;
    if (*cj / *cjold < temp1 || *cj / *cjold > temp2) {
	*jcalc = -1;
    }
    if (*cj != *cjlast) {
	*s = 100.;
    }

/* ----------------------------------------------------------------------- */
/*     Entry point for updating the Jacobian with current */
/*     stepsize. */
/* ----------------------------------------------------------------------- */
L300:

/*     Initialize all error flags to zero. */

    ierj = 0;
    ires = 0;
    iernew = 0;

/*     Predict the solution and derivative and compute the tolerance */
/*     for the Newton iteration. */

    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	y[i__] = phi[i__ + phi_dim1];
/* L310: */
	yprime[i__] = 0.;
    }
    i__1 = *kp1;
    for (j = 2; j <= i__1; ++j) {
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    y[i__] += phi[i__ + j * phi_dim1];
/* L320: */
	    yprime[i__] += gamma[j] * phi[i__ + j * phi_dim1];
	}
/* L330: */
    }
    pnorm = ddwnrm_(neq, &y[1], &wt[1], &rpar[1], &ipar[1]);
    tolnew = *uround * 100. * pnorm;

/*     Call RES to initialize DELTA. */

    ++iwm[12];
    (*res)(x, &y[1], &yprime[1], cj, &delta[1], &ires, &rpar[1], &ipar[1]);
    if (ires < 0) {
	goto L380;
    }

/*     If indicated, reevaluate the iteration matrix */
/*     J = dG/dY + CJ*dG/dYPRIME (where G(X,Y,YPRIME)=0). */
/*     Set JCALC to 0 as an indicator that this has been done. */

    if (*jcalc == -1) {
	++iwm[13];
	*jcalc = 0;
	dmatd_(neq, x, &y[1], &yprime[1], &delta[1], cj, h__, &ierj, &wt[1], &
		e[1], &wm[1], &iwm[1], (S_fp)res, &ires, uround, (U_fp)jacd, &
		rpar[1], &ipar[1]);
	*cjold = *cj;
	*s = 100.;
	if (ires < 0) {
	    goto L380;
	}
	if (ierj != 0) {
	    goto L380;
	}
    }

/*     Call the nonlinear Newton solver. */

    temp1 = 2. / (*cj / *cjold + 1.);
    dnsd_(x, &y[1], &yprime[1], neq, (S_fp)res, pdum, &wt[1], &rpar[1], &ipar[
	    1], dumsvr, &delta[1], &e[1], &wm[1], &iwm[1], cj, dums, dumr, 
	    dume, epcon, s, &temp1, &tolnew, &muldel, &maxit, &ires, &idum, &
	    iernew);

    if (iernew > 0 && *jcalc != 0) {

/*        The Newton iteration had a recoverable failure with an old */
/*        iteration matrix.  Retry the step with a new iteration matrix. */

	*jcalc = -1;
	goto L300;
    }

    if (iernew != 0) {
	goto L380;
    }

/*     The Newton iteration has converged.  If nonnegativity of */
/*     solution is required, set the solution nonnegative, if the */
/*     perturbation to do it is small enough.  If the change is too */
/*     large, then consider the corrector iteration to have failed. */

/* L375: */
    if (*nonneg == 0) {
	goto L390;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L377: */
/* Computing MIN */
	d__1 = y[i__];
	delta[i__] = min(d__1,0.);
    }
    delnrm = ddwnrm_(neq, &delta[1], &wt[1], &rpar[1], &ipar[1]);
    if (delnrm > *epcon) {
	goto L380;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L378: */
	e[i__] -= delta[i__];
    }
    goto L390;


/*     Exits from nonlinear solver. */
/*     No convergence with current iteration */
/*     matrix, or singular iteration matrix. */
/*     Compute IERNLS and IDID accordingly. */

L380:
    if (ires <= -2 || iertyp != 0) {
	*iernls = -1;
	if (ires <= -2) {
	    *idid = -11;
	}
	if (iertyp != 0) {
	    *idid = -15;
	}
    } else {
	*iernls = 1;
	if (ires < 0) {
	    *idid = -10;
	}
	if (ierj != 0) {
	    *idid = -8;
	}
    }

L390:
    *jcalc = 1;
    return 0;

/* ------END OF SUBROUTINE DNEDD------------------------------------------ */
} /* dnedd_ */

/* Subroutine */ int dnsd_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, S_fp res, doublereal *pdum, doublereal *wt, doublereal *
	rpar, integer *ipar, doublereal *dumsvr, doublereal *delta, 
	doublereal *e, doublereal *wm, integer *iwm, doublereal *cj, 
	doublereal *dums, doublereal *dumr, doublereal *dume, doublereal *
	epcon, doublereal *s, doublereal *confac, doublereal *tolnew, integer 
	*muldel, integer *maxit, integer *ires, integer *idum, integer *
	iernew)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, m;
    static doublereal rate;
    extern /* Subroutine */ int dslvd_(integer *, doublereal *, doublereal *, 
	    integer *);
    static doublereal delnrm;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal oldnrm;


/* ***BEGIN PROLOGUE  DNSD */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   891219   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  950126   (YYMMDD) */
/* ***REVISION DATE  000711   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DNSD solves a nonlinear system of */
/*     algebraic equations of the form */
/*     G(X,Y,YPRIME) = 0 for the unknown Y. */

/*     The method used is a modified Newton scheme. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of unknowns. */
/*     RES       -- External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     PDUM      -- Dummy argument. */
/*     WT        -- Vector of weights for error criterion. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     DUMSVR    -- Dummy argument. */
/*     DELTA     -- Work vector for DNSD of length NEQ. */
/*     E         -- Error accumulation vector for DNSD of length NEQ. */
/*     WM,IWM    -- Real and integer arrays storing */
/*                  matrix information such as the matrix */
/*                  of partial derivatives, permutation */
/*                  vector, and various other information. */
/*     CJ        -- Parameter always proportional to 1/H (step size). */
/*     DUMS      -- Dummy argument. */
/*     DUMR      -- Dummy argument. */
/*     DUME      -- Dummy argument. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     S         -- Used for error convergence tests. */
/*                  In the Newton iteration: S = RATE/(1 - RATE), */
/*                  where RATE is the estimated rate of convergence */
/*                  of the Newton iteration. */
/*                  The calling routine passes the initial value */
/*                  of S to the Newton iteration. */
/*     CONFAC    -- A residual scale factor to improve convergence. */
/*     TOLNEW    -- Tolerance on the norm of Newton correction in */
/*                  alternative Newton convergence test. */
/*     MULDEL    -- A flag indicating whether or not to multiply */
/*                  DELTA by CONFAC. */
/*                  0  ==> do not scale DELTA by CONFAC. */
/*                  1  ==> scale DELTA by CONFAC. */
/*     MAXIT     -- Maximum allowed number of Newton iterations. */
/*     IRES      -- Error flag returned from RES.  See RES description */
/*                  in DDASPK prologue.  If IRES = -1, then IERNEW */
/*                  will be set to 1. */
/*                  If IRES < -1, then IERNEW will be set to -1. */
/*     IDUM      -- Dummy argument. */
/*     IERNEW    -- Error flag for Newton iteration. */
/*                   0  ==> Newton iteration converged. */
/*                   1  ==> recoverable error inside Newton iteration. */
/*                  -1  ==> unrecoverable error inside Newton iteration. */

/*     All arguments with "DUM" in their names are dummy arguments */
/*     which are not used in this routine. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   DSLVD, DDWNRM, RES */

/* ***END PROLOGUE  DNSD */




/*     Initialize Newton counter M and accumulation vector E. */

    /* Parameter adjustments */
    --iwm;
    --wm;
    --e;
    --delta;
    --ipar;
    --rpar;
    --wt;
    --yprime;
    --y;

    /* Function Body */
    m = 0;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	e[i__] = 0.;
    }

/*     Corrector loop. */

L300:
    ++iwm[19];

/*     If necessary, multiply residual by convergence factor. */

    if (*muldel == 1) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L320: */
	    delta[i__] *= *confac;
	}
    }

/*     Compute a new iterate (back-substitution). */
/*     Store the correction in DELTA. */

    dslvd_(neq, &delta[1], &wm[1], &iwm[1]);

/*     Update Y, E, and YPRIME. */

    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	y[i__] -= delta[i__];
	e[i__] -= delta[i__];
/* L340: */
	yprime[i__] -= *cj * delta[i__];
    }

/*     Test for convergence of the iteration. */

    delnrm = ddwnrm_(neq, &delta[1], &wt[1], &rpar[1], &ipar[1]);
    if (m == 0) {
	oldnrm = delnrm;
	if (delnrm <= *tolnew) {
	    goto L370;
	}
    } else {
	d__1 = delnrm / oldnrm;
	d__2 = 1. / m;
	rate = pow_dd(&d__1, &d__2);
	if (rate > .9) {
	    goto L380;
	}
	*s = rate / (1. - rate);
    }
    if (*s * delnrm <= *epcon) {
	goto L370;
    }

/*     The corrector has not yet converged. */
/*     Update M and test whether the */
/*     maximum number of iterations have */
/*     been tried. */

    ++m;
    if (m >= *maxit) {
	goto L380;
    }

/*     Evaluate the residual, */
/*     and go back to do another iteration. */

    ++iwm[12];
    (*res)(x, &y[1], &yprime[1], cj, &delta[1], ires, &rpar[1], &ipar[1]);
    if (*ires < 0) {
	goto L380;
    }
    goto L300;

/*     The iteration has converged. */

L370:
    return 0;

/*     The iteration has not converged.  Set IERNEW appropriately. */

L380:
    if (*ires <= -2) {
	*iernew = -1;
    } else {
	*iernew = 1;
    }
    return 0;


/* ------END OF SUBROUTINE DNSD------------------------------------------- */
} /* dnsd_ */

/* Subroutine */ int dmatd_(integer *neq, doublereal *x, doublereal *y, 
	doublereal *yprime, doublereal *delta, doublereal *cj, doublereal *
	h__, integer *ier, doublereal *ewt, doublereal *e, doublereal *wm, 
	integer *iwm, S_fp res, integer *ires, doublereal *uround, S_fp jacd, 
	doublereal *rpar, integer *ipar)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l, n, i1, i2, ii, mba;
    static doublereal del;
    static integer meb1, nrow;
    static doublereal squr;
    extern /* Subroutine */ int dgbfa_(doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), dgefa_(doublereal *, 
	    integer *, integer *, integer *, integer *);
    static integer mband, lenpd, isave, msave;
    static doublereal ysave;
    static integer lipvt, mtype, meband;
    static doublereal delinv;
    static integer ipsave;
    static doublereal ypsave;


/* ***BEGIN PROLOGUE  DMATD */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  940701   (new LIPVT) */
/* ***REVISION DATE  060712   (Changed minimum D.Q. increment to 1/EWT(j)) */

/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     This routine computes the iteration matrix */
/*     J = dG/dY+CJ*dG/dYPRIME (where G(X,Y,YPRIME)=0). */
/*     Here J is computed by: */
/*       the user-supplied routine JACD if IWM(MTYPE) is 1 or 4, or */
/*       by numerical difference quotients if IWM(MTYPE) is 2 or 5. */

/*     The parameters have the following meanings. */
/*     X        = Independent variable. */
/*     Y        = Array containing predicted values. */
/*     YPRIME   = Array containing predicted derivatives. */
/*     DELTA    = Residual evaluated at (X,Y,YPRIME). */
/*                (Used only if IWM(MTYPE)=2 or 5). */
/*     CJ       = Scalar parameter defining iteration matrix. */
/*     H        = Current stepsize in integration. */
/*     IER      = Variable which is .NE. 0 if iteration matrix */
/*                is singular, and 0 otherwise. */
/*     EWT      = Vector of error weights for computing norms. */
/*     E        = Work space (temporary) of length NEQ. */
/*     WM       = Real work space for matrices.  On output */
/*                it contains the LU decomposition */
/*                of the iteration matrix. */
/*     IWM      = Integer work space containing */
/*                matrix information. */
/*     RES      = External user-supplied subroutine */
/*                to evaluate the residual.  See RES description */
/*                in DDASPK prologue. */
/*     IRES     = Flag which is equal to zero if no illegal values */
/*                in RES, and less than zero otherwise.  (If IRES */
/*                is less than zero, the matrix was not completed). */
/*                In this case (if IRES .LT. 0), then IER = 0. */
/*     UROUND   = The unit roundoff error of the machine being used. */
/*     JACD     = Name of the external user-supplied routine */
/*                to evaluate the iteration matrix.  (This routine */
/*                is only used if IWM(MTYPE) is 1 or 4) */
/*                See JAC description for the case INFO(12) = 0 */
/*                in DDASPK prologue. */
/*     RPAR,IPAR= Real and integer parameter arrays that */
/*                are used for communication between the */
/*                calling program and external user routines. */
/*                They are not altered by DMATD. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   JACD, RES, DGEFA, DGBFA */

/* ***END PROLOGUE  DMATD */




    /* Parameter adjustments */
    --ipar;
    --rpar;
    --iwm;
    --wm;
    --e;
    --ewt;
    --delta;
    --yprime;
    --y;

    /* Function Body */
    lipvt = iwm[30];
    *ier = 0;
    mtype = iwm[4];
    switch (mtype) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
    }


/*     Dense user-supplied matrix. */

L100:
    lenpd = iwm[22];
    i__1 = lenpd;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L110: */
	wm[i__] = 0.;
    }
    (*jacd)(x, &y[1], &yprime[1], &wm[1], cj, &rpar[1], &ipar[1]);
    goto L230;


/*     Dense finite-difference-generated matrix. */

L200:
    *ires = 0;
    nrow = 0;
    squr = sqrt(*uround);
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing MAX */
/* Computing MAX */
	d__5 = (d__1 = y[i__], abs(d__1)), d__6 = (d__2 = *h__ * yprime[i__], 
		abs(d__2));
	d__3 = squr * max(d__5,d__6), d__4 = 1. / ewt[i__];
	del = max(d__3,d__4);
	d__1 = *h__ * yprime[i__];
	del = d_sign(&del, &d__1);
	del = y[i__] + del - y[i__];
	ysave = y[i__];
	ypsave = yprime[i__];
	y[i__] += del;
	yprime[i__] += *cj * del;
	++iwm[12];
	(*res)(x, &y[1], &yprime[1], cj, &e[1], ires, &rpar[1], &ipar[1]);
	if (*ires < 0) {
	    return 0;
	}
	delinv = 1. / del;
	i__2 = *neq;
	for (l = 1; l <= i__2; ++l) {
/* L220: */
	    wm[nrow + l] = (e[l] - delta[l]) * delinv;
	}
	nrow += *neq;
	y[i__] = ysave;
	yprime[i__] = ypsave;
/* L210: */
    }


/*     Do dense-matrix LU decomposition on J. */

L230:
    dgefa_(&wm[1], neq, neq, &iwm[lipvt], ier);
    return 0;


/*     Dummy section for IWM(MTYPE)=3. */

L300:
    return 0;


/*     Banded user-supplied matrix. */

L400:
    lenpd = iwm[22];
    i__1 = lenpd;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L410: */
	wm[i__] = 0.;
    }
    (*jacd)(x, &y[1], &yprime[1], &wm[1], cj, &rpar[1], &ipar[1]);
    meband = (iwm[1] << 1) + iwm[2] + 1;
    goto L550;


/*     Banded finite-difference-generated matrix. */

L500:
    mband = iwm[1] + iwm[2] + 1;
    mba = min(mband,*neq);
    meband = mband + iwm[1];
    meb1 = meband - 1;
    msave = *neq / mband + 1;
    isave = iwm[22];
    ipsave = isave + msave;
    *ires = 0;
    squr = sqrt(*uround);
    i__1 = mba;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *neq;
	i__3 = mband;
	for (n = j; i__3 < 0 ? n >= i__2 : n <= i__2; n += i__3) {
	    k = (n - j) / mband + 1;
	    wm[isave + k] = y[n];
	    wm[ipsave + k] = yprime[n];
/* Computing MAX */
/* Computing MAX */
	    d__5 = (d__1 = y[n], abs(d__1)), d__6 = (d__2 = *h__ * yprime[n], 
		    abs(d__2));
	    d__3 = squr * max(d__5,d__6), d__4 = 1. / ewt[n];
	    del = max(d__3,d__4);
	    d__1 = *h__ * yprime[n];
	    del = d_sign(&del, &d__1);
	    del = y[n] + del - y[n];
	    y[n] += del;
/* L510: */
	    yprime[n] += *cj * del;
	}
	++iwm[12];
	(*res)(x, &y[1], &yprime[1], cj, &e[1], ires, &rpar[1], &ipar[1]);
	if (*ires < 0) {
	    return 0;
	}
	i__3 = *neq;
	i__2 = mband;
	for (n = j; i__2 < 0 ? n >= i__3 : n <= i__3; n += i__2) {
	    k = (n - j) / mband + 1;
	    y[n] = wm[isave + k];
	    yprime[n] = wm[ipsave + k];
/* Computing MAX */
/* Computing MAX */
	    d__5 = (d__1 = y[n], abs(d__1)), d__6 = (d__2 = *h__ * yprime[n], 
		    abs(d__2));
	    d__3 = squr * max(d__5,d__6), d__4 = 1. / ewt[n];
	    del = max(d__3,d__4);
	    d__1 = *h__ * yprime[n];
	    del = d_sign(&del, &d__1);
	    del = y[n] + del - y[n];
	    delinv = 1. / del;
/* Computing MAX */
	    i__4 = 1, i__5 = n - iwm[2];
	    i1 = max(i__4,i__5);
/* Computing MIN */
	    i__4 = *neq, i__5 = n + iwm[1];
	    i2 = min(i__4,i__5);
	    ii = n * meb1 - iwm[1];
	    i__4 = i2;
	    for (i__ = i1; i__ <= i__4; ++i__) {
/* L520: */
		wm[ii + i__] = (e[i__] - delta[i__]) * delinv;
	    }
/* L530: */
	}
/* L540: */
    }


/*     Do LU decomposition of banded J. */

L550:
    dgbfa_(&wm[1], &meband, neq, &iwm[1], &iwm[2], &iwm[lipvt], ier);
    return 0;

/* ------END OF SUBROUTINE DMATD------------------------------------------ */
} /* dmatd_ */

/* Subroutine */ int dslvd_(integer *neq, doublereal *delta, doublereal *wm, 
	integer *iwm)
{
    extern /* Subroutine */ int dgbsl_(doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *), dgesl_(
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    integer *);
    static integer lipvt, mtype, meband;


/* ***BEGIN PROLOGUE  DSLVD */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  940701   (YYMMDD) (new LIPVT) */

/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     This routine manages the solution of the linear */
/*     system arising in the Newton iteration. */
/*     Real matrix information and real temporary storage */
/*     is stored in the array WM. */
/*     Integer matrix information is stored in the array IWM. */
/*     For a dense matrix, the LINPACK routine DGESL is called. */
/*     For a banded matrix, the LINPACK routine DGBSL is called. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DGESL, DGBSL */

/* ***END PROLOGUE  DSLVD */




    /* Parameter adjustments */
    --iwm;
    --wm;
    --delta;

    /* Function Body */
    lipvt = iwm[30];
    mtype = iwm[4];
    switch (mtype) {
	case 1:  goto L100;
	case 2:  goto L100;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L400;
    }

/*     Dense matrix. */

L100:
    dgesl_(&wm[1], neq, neq, &iwm[lipvt], &delta[1], &c__0);
    return 0;

/*     Dummy section for MTYPE=3. */

L300:
    return 0;

/*     Banded matrix. */

L400:
    meband = (iwm[1] << 1) + iwm[2] + 1;
    dgbsl_(&wm[1], &meband, neq, &iwm[1], &iwm[2], &iwm[lipvt], &delta[1], &
	    c__0);
    return 0;

/* ------END OF SUBROUTINE DSLVD------------------------------------------ */
} /* dslvd_ */

/* Subroutine */ int ddasik_(doublereal *x, doublereal *y, doublereal *yprime,
	 integer *neq, integer *icopt, integer *id, S_fp res, S_fp jack, U_fp 
	psol, doublereal *h__, doublereal *tscale, doublereal *wt, integer *
	jskip, doublereal *rpar, integer *ipar, doublereal *savr, doublereal *
	delta, doublereal *r__, doublereal *yic, doublereal *ypic, doublereal 
	*pwk, doublereal *wm, integer *iwm, doublereal *cj, doublereal *
	uround, doublereal *epli, doublereal *sqrtn, doublereal *rsqrtn, 
	doublereal *epcon, doublereal *ratemx, doublereal *stptol, integer *
	jflg, integer *icnflg, integer *icnstr, integer *iernls)
{
    static integer nj, lwp, ires, liwp, mxnj;
    static doublereal eplin;
    extern /* Subroutine */ int dnsik_(doublereal *, doublereal *, doublereal 
	    *, integer *, integer *, integer *, S_fp, U_fp, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     integer *, integer *, integer *);
    static integer ierpj;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static integer mxnit, iernew;


/* ***BEGIN PROLOGUE  DDASIK */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   941026   (YYMMDD) */
/* ***REVISION DATE  950808   (YYMMDD) */
/* ***REVISION DATE  951110   Removed unreachable block 390. */
/* ***REVISION DATE  000628   TSCALE argument added. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */


/*     DDASIK solves a nonlinear system of algebraic equations of the */
/*     form G(X,Y,YPRIME) = 0 for the unknown parts of Y and YPRIME in */
/*     the initial conditions. */

/*     An initial value for Y and initial guess for YPRIME are input. */

/*     The method used is a Newton scheme with Krylov iteration and a */
/*     linesearch algorithm. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector at x. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of equations to be integrated. */
/*     ICOPT     -- Initial condition option chosen (1 or 2). */
/*     ID        -- Array of dimension NEQ, which must be initialized */
/*                  if ICOPT = 1.  See DDASIC. */
/*     RES       -- External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     JACK     --  External user-supplied routine to update */
/*                  the preconditioner.  (This is optional). */
/*                  See JAC description for the case */
/*                  INFO(12) = 1 in the DDASPK prologue. */
/*     PSOL      -- External user-supplied routine to solve */
/*                  a linear system using preconditioning. */
/*                  (This is optional).  See explanation inside DDASPK. */
/*     H         -- Scaling factor for this initial condition calc. */
/*     TSCALE    -- Scale factor in T, used for stopping tests if nonzero. */
/*     WT        -- Vector of weights for error criterion. */
/*     JSKIP     -- input flag to signal if initial JAC call is to be */
/*                  skipped.  1 => skip the call, 0 => do not skip call. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     SAVR      -- Work vector for DDASIK of length NEQ. */
/*     DELTA     -- Work vector for DDASIK of length NEQ. */
/*     R         -- Work vector for DDASIK of length NEQ. */
/*     YIC,YPIC  -- Work vectors for DDASIK, each of length NEQ. */
/*     PWK       -- Work vector for DDASIK of length NEQ. */
/*     WM,IWM    -- Real and integer arrays storing */
/*                  matrix information for linear system */
/*                  solvers, and various other information. */
/*     CJ        -- Matrix parameter = 1/H (ICOPT = 1) or 0 (ICOPT = 2). */
/*     UROUND    -- Unit roundoff.  Not used here. */
/*     EPLI      -- convergence test constant. */
/*                  See DDASPK prologue for more details. */
/*     SQRTN     -- Square root of NEQ. */
/*     RSQRTN    -- reciprical of square root of NEQ. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     RATEMX    -- Maximum convergence rate for which Newton iteration */
/*                  is considered converging. */
/*     JFLG      -- Flag showing whether a Jacobian routine is supplied. */
/*     ICNFLG    -- Integer scalar.  If nonzero, then constraint */
/*                  violations in the proposed new approximate solution */
/*                  will be checked for, and the maximum step length */
/*                  will be adjusted accordingly. */
/*     ICNSTR    -- Integer array of length NEQ containing flags for */
/*                  checking constraints. */
/*     IERNLS    -- Error flag for nonlinear solver. */
/*                   0   ==> nonlinear solver converged. */
/*                   1,2 ==> recoverable error inside nonlinear solver. */
/*                           1 => retry with current Y, YPRIME */
/*                           2 => retry with original Y, YPRIME */
/*                  -1   ==> unrecoverable error in nonlinear solver. */

/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   RES, JACK, DNSIK, DCOPY */

/* ***END PROLOGUE  DDASIK */





/*     Perform initializations. */

    /* Parameter adjustments */
    --icnstr;
    --iwm;
    --wm;
    --pwk;
    --ypic;
    --yic;
    --r__;
    --delta;
    --savr;
    --ipar;
    --rpar;
    --wt;
    --id;
    --yprime;
    --y;

    /* Function Body */
    lwp = iwm[29];
    liwp = iwm[30];
    mxnit = iwm[32];
    mxnj = iwm[33];
    *iernls = 0;
    nj = 0;
    eplin = *epli * *epcon;

/*     Call RES to initialize DELTA. */

    ires = 0;
    ++iwm[12];
    (*res)(x, &y[1], &yprime[1], cj, &delta[1], &ires, &rpar[1], &ipar[1]);
    if (ires < 0) {
	goto L370;
    }

/*     Looping point for updating the preconditioner. */

L300:

/*     Initialize all error flags to zero. */

    ierpj = 0;
    ires = 0;
    iernew = 0;

/*     If a Jacobian routine was supplied, call it. */

    if (*jflg == 1 && *jskip == 0) {
	++nj;
	++iwm[13];
	(*jack)((S_fp)res, &ires, neq, x, &y[1], &yprime[1], &wt[1], &delta[1]
		, &r__[1], h__, cj, &wm[lwp], &iwm[liwp], &ierpj, &rpar[1], &
		ipar[1]);
	if (ires < 0 || ierpj != 0) {
	    goto L370;
	}
    }
    *jskip = 0;

/*     Call the nonlinear Newton solver for up to MXNIT iterations. */

    dnsik_(x, &y[1], &yprime[1], neq, icopt, &id[1], (S_fp)res, (U_fp)psol, &
	    wt[1], &rpar[1], &ipar[1], &savr[1], &delta[1], &r__[1], &yic[1], 
	    &ypic[1], &pwk[1], &wm[1], &iwm[1], cj, tscale, sqrtn, rsqrtn, &
	    eplin, epcon, ratemx, &mxnit, stptol, icnflg, &icnstr[1], &iernew)
	    ;

    if (iernew == 1 && nj < mxnj && *jflg == 1) {

/*       Up to MXNIT iterations were done, the convergence rate is < 1, */
/*       a Jacobian routine is supplied, and the number of JACK calls */
/*       is less than MXNJ. */
/*       Copy the residual SAVR to DELTA, call JACK, and try again. */

	dcopy_(neq, &savr[1], &c__1, &delta[1], &c__1);
	goto L300;
    }

    if (iernew != 0) {
	goto L380;
    }
    return 0;


/*     Unsuccessful exits from nonlinear solver. */
/*     Set IERNLS accordingly. */

L370:
    *iernls = 2;
    if (ires <= -2) {
	*iernls = -1;
    }
    return 0;

L380:
    *iernls = min(iernew,2);
    return 0;

/* ----------------------- END OF SUBROUTINE DDASIK----------------------- */
} /* ddasik_ */

/* Subroutine */ int dnsik_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, integer *icopt, integer *id, S_fp res, U_fp psol, 
	doublereal *wt, doublereal *rpar, integer *ipar, doublereal *savr, 
	doublereal *delta, doublereal *r__, doublereal *yic, doublereal *ypic,
	 doublereal *pwk, doublereal *wm, integer *iwm, doublereal *cj, 
	doublereal *tscale, doublereal *sqrtn, doublereal *rsqrtn, doublereal 
	*eplin, doublereal *epcon, doublereal *ratemx, integer *maxit, 
	doublereal *stptol, integer *icnflg, integer *icnstr, integer *iernew)
{
    static integer m, ier, lwp;
    static doublereal rlx, rate;
    static integer ires;
    static doublereal fnrm, rhok;
    static integer iret, liwp;
    static doublereal fnrm0;
    static integer lsoff;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static integer iersl;
    extern /* Subroutine */ int dslvk_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, S_fp, integer *, U_fp, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal oldfnm;
    extern /* Subroutine */ int dfnrmk_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, S_fp, 
	    integer *, U_fp, integer *, integer *, doublereal *, doublereal *,
	     doublereal *, integer *, doublereal *, doublereal *, integer *);
    static doublereal delnrm;
    extern /* Subroutine */ int dlinsk_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *, S_fp, integer *,
	     U_fp, doublereal *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, doublereal *, doublereal *, integer *);
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);


/* ***BEGIN PROLOGUE  DNSIK */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   940701   (YYMMDD) */
/* ***REVISION DATE  950714   (YYMMDD) */
/* ***REVISION DATE  000628   TSCALE argument added. */
/* ***REVISION DATE  000628   Added criterion for IERNEW = 1 return. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DNSIK solves a nonlinear system of algebraic equations of the */
/*     form G(X,Y,YPRIME) = 0 for the unknown parts of Y and YPRIME in */
/*     the initial conditions. */

/*     The method used is a Newton scheme combined with a linesearch */
/*     algorithm, using Krylov iterative linear system methods. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of unknowns. */
/*     ICOPT     -- Initial condition option chosen (1 or 2). */
/*     ID        -- Array of dimension NEQ, which must be initialized */
/*                  if ICOPT = 1.  See DDASIC. */
/*     RES       -- External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     PSOL      -- External user-supplied routine to solve */
/*                  a linear system using preconditioning. */
/*                  See explanation inside DDASPK. */
/*     WT        -- Vector of weights for error criterion. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     SAVR      -- Work vector for DNSIK of length NEQ. */
/*     DELTA     -- Residual vector on entry, and work vector of */
/*                  length NEQ for DNSIK. */
/*     R         -- Work vector for DNSIK of length NEQ. */
/*     YIC,YPIC  -- Work vectors for DNSIK, each of length NEQ. */
/*     PWK       -- Work vector for DNSIK of length NEQ. */
/*     WM,IWM    -- Real and integer arrays storing */
/*                  matrix information such as the matrix */
/*                  of partial derivatives, permutation */
/*                  vector, and various other information. */
/*     CJ        -- Matrix parameter = 1/H (ICOPT = 1) or 0 (ICOPT = 2). */
/*     TSCALE    -- Scale factor in T, used for stopping tests if nonzero. */
/*     SQRTN     -- Square root of NEQ. */
/*     RSQRTN    -- reciprical of square root of NEQ. */
/*     EPLIN     -- Tolerance for linear system solver. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     RATEMX    -- Maximum convergence rate for which Newton iteration */
/*                  is considered converging. */
/*     MAXIT     -- Maximum allowed number of Newton iterations. */
/*     STPTOL    -- Tolerance used in calculating the minimum lambda */
/*                  value allowed. */
/*     ICNFLG    -- Integer scalar.  If nonzero, then constraint */
/*                  violations in the proposed new approximate solution */
/*                  will be checked for, and the maximum step length */
/*                  will be adjusted accordingly. */
/*     ICNSTR    -- Integer array of length NEQ containing flags for */
/*                  checking constraints. */
/*     IERNEW    -- Error flag for Newton iteration. */
/*                   0  ==> Newton iteration converged. */
/*                   1  ==> failed to converge, but RATE .lt. 1, or the */
/*                          residual norm was reduced by a factor of .1. */
/*                   2  ==> failed to converge, RATE .gt. RATEMX. */
/*                   3  ==> other recoverable error. */
/*                  -1  ==> unrecoverable error inside Newton iteration. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   DFNRMK, DSLVK, DDWNRM, DLINSK, DCOPY */

/* ***END PROLOGUE  DNSIK */





/*     Initializations.  M is the Newton iteration counter. */

    /* Parameter adjustments */
    --icnstr;
    --iwm;
    --wm;
    --pwk;
    --ypic;
    --yic;
    --r__;
    --delta;
    --savr;
    --ipar;
    --rpar;
    --wt;
    --id;
    --yprime;
    --y;

    /* Function Body */
    lsoff = iwm[35];
    m = 0;
    rate = 1.;
    lwp = iwm[29];
    liwp = iwm[30];
    rlx = .4;

/*     Save residual in SAVR. */

    dcopy_(neq, &delta[1], &c__1, &savr[1], &c__1);

/*     Compute norm of (P-inverse)*(residual). */

    dfnrmk_(neq, &y[1], x, &yprime[1], &savr[1], &r__[1], cj, tscale, &wt[1], 
	    sqrtn, rsqrtn, (S_fp)res, &ires, (U_fp)psol, &c__1, &ier, &fnrm, 
	    eplin, &wm[lwp], &iwm[liwp], &pwk[1], &rpar[1], &ipar[1]);
    ++iwm[21];
    if (ier != 0) {
	*iernew = 3;
	return 0;
    }

/*     Return now if residual norm is .le. EPCON. */

    if (fnrm <= *epcon) {
	return 0;
    }

/*     Newton iteration loop. */

    fnrm0 = fnrm;
L300:
    ++iwm[19];

/*     Compute a new step vector DELTA. */

    dslvk_(neq, &y[1], x, &yprime[1], &savr[1], &delta[1], &wt[1], &wm[1], &
	    iwm[1], (S_fp)res, &ires, (U_fp)psol, &iersl, cj, eplin, sqrtn, 
	    rsqrtn, &rhok, &rpar[1], &ipar[1]);
    if (ires != 0 || iersl != 0) {
	goto L390;
    }

/*     Get norm of DELTA.  Return now if DELTA is zero. */

    delnrm = ddwnrm_(neq, &delta[1], &wt[1], &rpar[1], &ipar[1]);
    if (delnrm == 0.) {
	return 0;
    }

/*     Call linesearch routine for global strategy and set RATE. */

    oldfnm = fnrm;

    dlinsk_(neq, &y[1], x, &yprime[1], &savr[1], cj, tscale, &delta[1], &
	    delnrm, &wt[1], sqrtn, rsqrtn, &lsoff, stptol, &iret, (S_fp)res, &
	    ires, (U_fp)psol, &wm[1], &iwm[1], &rhok, &fnrm, icopt, &id[1], &
	    wm[lwp], &iwm[liwp], &r__[1], eplin, &yic[1], &ypic[1], &pwk[1], 
	    icnflg, &icnstr[1], &rlx, &rpar[1], &ipar[1]);

    rate = fnrm / oldfnm;

/*     Check for error condition from linesearch. */
    if (iret != 0) {
	goto L390;
    }

/*     Test for convergence of the iteration, and return or loop. */

    if (fnrm <= *epcon) {
	return 0;
    }

/*     The iteration has not yet converged.  Update M. */
/*     Test whether the maximum number of iterations have been tried. */

    ++m;
    if (m >= *maxit) {
	goto L380;
    }

/*     Copy the residual SAVR to DELTA and loop for another iteration. */

    dcopy_(neq, &savr[1], &c__1, &delta[1], &c__1);
    goto L300;

/*     The maximum number of iterations was done.  Set IERNEW and return. */

L380:
    if (rate <= *ratemx || fnrm <= fnrm0 * .1) {
	*iernew = 1;
    } else {
	*iernew = 2;
    }
    return 0;

L390:
    if (ires <= -2 || iersl < 0) {
	*iernew = -1;
    } else {
	*iernew = 3;
	if (ires == 0 && iersl == 1 && m >= 2 && rate < 1.) {
	    *iernew = 1;
	}
    }
    return 0;


/* ----------------------- END OF SUBROUTINE DNSIK------------------------ */
} /* dnsik_ */

/* Subroutine */ int dlinsk_(integer *neq, doublereal *y, doublereal *t, 
	doublereal *yprime, doublereal *savr, doublereal *cj, doublereal *
	tscale, doublereal *p, doublereal *pnrm, doublereal *wt, doublereal *
	sqrtn, doublereal *rsqrtn, integer *lsoff, doublereal *stptol, 
	integer *iret, S_fp res, integer *ires, U_fp psol, doublereal *wm, 
	integer *iwm, doublereal *rhok, doublereal *fnrm, integer *icopt, 
	integer *id, doublereal *wp, integer *iwp, doublereal *r__, 
	doublereal *eplin, doublereal *ynew, doublereal *ypnew, doublereal *
	pwk, integer *icnflg, integer *icnstr, doublereal *rlx, doublereal *
	rpar, integer *ipar)
{
    /* Initialized data */

    static doublereal alpha = 1e-4;
    static doublereal one = 1.;
    static doublereal two = 2.;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ void s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal rl;
    static integer ier;
    static char msg[80];
    static doublereal tau;
    static integer ivar;
    static doublereal slpi, f1nrm, ratio;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);
    static doublereal rlmin, fnrmp;
    static integer kprin;
    static doublereal ratio1, f1nrmp;
    extern /* Subroutine */ int dfnrmk_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, S_fp, 
	    integer *, U_fp, integer *, integer *, doublereal *, doublereal *,
	     doublereal *, integer *, doublereal *, doublereal *, integer *), 
	    dcnstr_(integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, integer *), xerrwd_(char *,
	     integer *, integer *, integer *, integer *, integer *, integer *,
	     integer *, doublereal *, doublereal *, ftnlen), dyypnw_(integer *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *);


/* ***BEGIN PROLOGUE  DLINSK */
/* ***REFER TO  DNSIK */
/* ***DATE WRITTEN   940830   (YYMMDD) */
/* ***REVISION DATE  951006   (Arguments SQRTN, RSQRTN added.) */
/* ***REVISION DATE  960129   Moved line RL = ONE to top block. */
/* ***REVISION DATE  000628   TSCALE argument added. */
/* ***REVISION DATE  000628   RHOK*RHOK term removed in alpha test. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DLINSK uses a linesearch algorithm to calculate a new (Y,YPRIME) */
/*     pair (YNEW,YPNEW) such that */

/*     f(YNEW,YPNEW) .le. (1 - 2*ALPHA*RL)*f(Y,YPRIME) */

/*     where 0 < RL <= 1, and RHOK is the scaled preconditioned norm of */
/*     the final residual vector in the Krylov iteration. */
/*     Here, f(y,y') is defined as */

/*      f(y,y') = (1/2)*norm( (P-inverse)*G(t,y,y') )**2 , */

/*     where norm() is the weighted RMS vector norm, G is the DAE */
/*     system residual function, and P is the preconditioner used */
/*     in the Krylov iteration. */

/*     In addition to the parameters defined elsewhere, we have */

/*     SAVR    -- Work array of length NEQ, containing the residual */
/*                vector G(t,y,y') on return. */
/*     TSCALE  -- Scale factor in T, used for stopping tests if nonzero. */
/*     P       -- Approximate Newton step used in backtracking. */
/*     PNRM    -- Weighted RMS norm of P. */
/*     LSOFF   -- Flag showing whether the linesearch algorithm is */
/*                to be invoked.  0 means do the linesearch, */
/*                1 means turn off linesearch. */
/*     STPTOL  -- Tolerance used in calculating the minimum lambda */
/*                value allowed. */
/*     ICNFLG  -- Integer scalar.  If nonzero, then constraint violations */
/*                in the proposed new approximate solution will be */
/*                checked for, and the maximum step length will be */
/*                adjusted accordingly. */
/*     ICNSTR  -- Integer array of length NEQ containing flags for */
/*                checking constraints. */
/*     RHOK    -- Weighted norm of preconditioned Krylov residual. */
/*     RLX     -- Real scalar restricting update size in DCNSTR. */
/*     YNEW    -- Array of length NEQ used to hold the new Y in */
/*                performing the linesearch. */
/*     YPNEW   -- Array of length NEQ used to hold the new YPRIME in */
/*                performing the linesearch. */
/*     PWK     -- Work vector of length NEQ for use in PSOL. */
/*     Y       -- Array of length NEQ containing the new Y (i.e.,=YNEW). */
/*     YPRIME  -- Array of length NEQ containing the new YPRIME */
/*                (i.e.,=YPNEW). */
/*     FNRM    -- Real scalar containing SQRT(2*f(Y,YPRIME)) for the */
/*                current (Y,YPRIME) on input and output. */
/*     R       -- Work space length NEQ for residual vector. */
/*     IRET    -- Return flag. */
/*                IRET=0 means that a satisfactory (Y,YPRIME) was found. */
/*                IRET=1 means that the routine failed to find a new */
/*                       (Y,YPRIME) that was sufficiently distinct from */
/*                       the current (Y,YPRIME) pair. */
/*                IRET=2 means a failure in RES or PSOL. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   DFNRMK, DYYPNW, DCNSTR, DCOPY, XERRWD */

/* ***END PROLOGUE  DLINSK */



    /* Parameter adjustments */
    --ipar;
    --rpar;
    --icnstr;
    --pwk;
    --ypnew;
    --ynew;
    --r__;
    --iwp;
    --wp;
    --id;
    --iwm;
    --wm;
    --wt;
    --p;
    --savr;
    --yprime;
    --y;

    /* Function Body */

    kprin = iwm[31];
    f1nrm = *fnrm * *fnrm / two;
    ratio = one;

    if (kprin >= 2) {
	s_copy(msg, "------ IN ROUTINE DLINSK-- PNRM = (R1)", (ftnlen)80, (
		ftnlen)38);
	xerrwd_(msg, &c__38, &c__921, &c__0, &c__0, &c__0, &c__0, &c__1, pnrm,
		 &c_b83, (ftnlen)80);
    }
    tau = *pnrm;
    rl = one;
/* ----------------------------------------------------------------------- */
/* Check for violations of the constraints, if any are imposed. */
/* If any violations are found, the step vector P is rescaled, and the */
/* constraint check is repeated, until no violations are found. */
/* ----------------------------------------------------------------------- */
    if (*icnflg != 0) {
L10:
	dyypnw_(neq, &y[1], &yprime[1], cj, &rl, &p[1], icopt, &id[1], &ynew[
		1], &ypnew[1]);
	dcnstr_(neq, &y[1], &ynew[1], &icnstr[1], &tau, rlx, iret, &ivar);
	if (*iret == 1) {
	    ratio1 = tau / *pnrm;
	    ratio *= ratio1;
	    i__1 = *neq;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
		p[i__] *= ratio1;
	    }
	    *pnrm = tau;
	    if (kprin >= 2) {
		s_copy(msg, "------ CONSTRAINT VIOL., PNRM = (R1), INDEX = ("
			"I1)", (ftnlen)80, (ftnlen)50);
		xerrwd_(msg, &c__50, &c__922, &c__0, &c__1, &ivar, &c__0, &
			c__1, pnrm, &c_b83, (ftnlen)80);
	    }
	    if (*pnrm <= *stptol) {
		*iret = 1;
		return 0;
	    }
	    goto L10;
	}
    }

    slpi = -two * f1nrm * ratio;
    rlmin = *stptol / *pnrm;
    if (*lsoff == 0 && kprin >= 2) {
	s_copy(msg, "------ MIN. LAMBDA = (R1)", (ftnlen)80, (ftnlen)25);
	xerrwd_(msg, &c__25, &c__923, &c__0, &c__0, &c__0, &c__0, &c__1, &
		rlmin, &c_b83, (ftnlen)80);
    }
/* ----------------------------------------------------------------------- */
/* Begin iteration to find RL value satisfying alpha-condition. */
/* Update YNEW and YPNEW, then compute norm of new scaled residual and */
/* perform alpha condition test. */
/* ----------------------------------------------------------------------- */
L100:
    dyypnw_(neq, &y[1], &yprime[1], cj, &rl, &p[1], icopt, &id[1], &ynew[1], &
	    ypnew[1]);
    dfnrmk_(neq, &ynew[1], t, &ypnew[1], &savr[1], &r__[1], cj, tscale, &wt[1]
	    , sqrtn, rsqrtn, (S_fp)res, ires, (U_fp)psol, &c__0, &ier, &fnrmp,
	     eplin, &wp[1], &iwp[1], &pwk[1], &rpar[1], &ipar[1]);
    ++iwm[12];
    if (*ires >= 0) {
	++iwm[21];
    }
    if (*ires != 0 || ier != 0) {
	*iret = 2;
	return 0;
    }
    if (*lsoff == 1) {
	goto L150;
    }

    f1nrmp = fnrmp * fnrmp / two;
    if (kprin >= 2) {
	s_copy(msg, "------ LAMBDA = (R1)", (ftnlen)80, (ftnlen)20);
	xerrwd_(msg, &c__20, &c__924, &c__0, &c__0, &c__0, &c__0, &c__1, &rl, 
		&c_b83, (ftnlen)80);
	s_copy(msg, "------ NORM(F1) = (R1),  NORM(F1NEW) = (R2)", (ftnlen)80,
		 (ftnlen)43);
	xerrwd_(msg, &c__43, &c__925, &c__0, &c__0, &c__0, &c__0, &c__2, &
		f1nrm, &f1nrmp, (ftnlen)80);
    }
    if (f1nrmp > f1nrm + alpha * slpi * rl) {
	goto L200;
    }
/* ----------------------------------------------------------------------- */
/* Alpha-condition is satisfied, or linesearch is turned off. */
/* Copy YNEW,YPNEW to Y,YPRIME and return. */
/* ----------------------------------------------------------------------- */
L150:
    *iret = 0;
    dcopy_(neq, &ynew[1], &c__1, &y[1], &c__1);
    dcopy_(neq, &ypnew[1], &c__1, &yprime[1], &c__1);
    *fnrm = fnrmp;
    if (kprin >= 1) {
	s_copy(msg, "------ LEAVING ROUTINE DLINSK, FNRM = (R1)", (ftnlen)80, 
		(ftnlen)42);
	xerrwd_(msg, &c__42, &c__926, &c__0, &c__0, &c__0, &c__0, &c__1, fnrm,
		 &c_b83, (ftnlen)80);
    }
    return 0;
/* ----------------------------------------------------------------------- */
/* Alpha-condition not satisfied.  Perform backtrack to compute new RL */
/* value.  If RL is less than RLMIN, i.e. no satisfactory YNEW,YPNEW can */
/* be found sufficiently distinct from Y,YPRIME, then return IRET = 1. */
/* ----------------------------------------------------------------------- */
L200:
    if (rl < rlmin) {
	*iret = 1;
	return 0;
    }

    rl /= two;
    goto L100;

/* ----------------------- END OF SUBROUTINE DLINSK ---------------------- */
} /* dlinsk_ */

/* Subroutine */ int dfnrmk_(integer *neq, doublereal *y, doublereal *t, 
	doublereal *yprime, doublereal *savr, doublereal *r__, doublereal *cj,
	 doublereal *tscale, doublereal *wt, doublereal *sqrtn, doublereal *
	rsqrtn, S_fp res, integer *ires, S_fp psol, integer *irin, integer *
	ier, doublereal *fnorm, doublereal *eplin, doublereal *wp, integer *
	iwp, doublereal *pwk, doublereal *rpar, integer *ipar)
{
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), dcopy_(integer *, doublereal *, integer *, doublereal 
	    *, integer *);
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);


/* ***BEGIN PROLOGUE  DFNRMK */
/* ***REFER TO  DLINSK */
/* ***DATE WRITTEN   940830   (YYMMDD) */
/* ***REVISION DATE  951006   (SQRTN, RSQRTN, and scaling of WT added.) */
/* ***REVISION DATE  000628   TSCALE argument added. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DFNRMK calculates the scaled preconditioned norm of the nonlinear */
/*     function used in the nonlinear iteration for obtaining consistent */
/*     initial conditions.  Specifically, DFNRMK calculates the weighted */
/*     root-mean-square norm of the vector (P-inverse)*G(T,Y,YPRIME), */
/*     where P is the preconditioner matrix. */

/*     In addition to the parameters described in the calling program */
/*     DLINSK, the parameters represent */

/*     TSCALE -- Scale factor in T, used for stopping tests if nonzero. */
/*     IRIN   -- Flag showing whether the current residual vector is */
/*               input in SAVR.  1 means it is, 0 means it is not. */
/*     R      -- Array of length NEQ that contains */
/*               (P-inverse)*G(T,Y,YPRIME) on return. */
/*     FNORM  -- Scalar containing the weighted norm of R on return. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   RES, DCOPY, DSCAL, PSOL, DDWNRM */

/* ***END PROLOGUE  DFNRMK */


/* ----------------------------------------------------------------------- */
/*     Call RES routine if IRIN = 0. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ipar;
    --rpar;
    --pwk;
    --iwp;
    --wp;
    --wt;
    --r__;
    --savr;
    --yprime;
    --y;

    /* Function Body */
    if (*irin == 0) {
	*ires = 0;
	(*res)(t, &y[1], &yprime[1], cj, &savr[1], ires, &rpar[1], &ipar[1]);
	if (*ires < 0) {
	    return 0;
	}
    }
/* ----------------------------------------------------------------------- */
/*     Apply inverse of left preconditioner to vector R. */
/*     First scale WT array by 1/sqrt(N), and undo scaling afterward. */
/* ----------------------------------------------------------------------- */
    dcopy_(neq, &savr[1], &c__1, &r__[1], &c__1);
    dscal_(neq, rsqrtn, &wt[1], &c__1);
    *ier = 0;
    (*psol)(neq, t, &y[1], &yprime[1], &savr[1], &pwk[1], cj, &wt[1], &wp[1], 
	    &iwp[1], &r__[1], eplin, ier, &rpar[1], &ipar[1]);
    dscal_(neq, sqrtn, &wt[1], &c__1);
    if (*ier != 0) {
	return 0;
    }
/* ----------------------------------------------------------------------- */
/*     Calculate norm of R. */
/* ----------------------------------------------------------------------- */
    *fnorm = ddwnrm_(neq, &r__[1], &wt[1], &rpar[1], &ipar[1]);
    if (*tscale > 0.) {
	*fnorm = *fnorm * *tscale * abs(*cj);
    }

    return 0;
/* ----------------------- END OF SUBROUTINE DFNRMK ---------------------- */
} /* dfnrmk_ */

/* Subroutine */ int dnedk_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, S_fp res, S_fp jack, U_fp psol, doublereal *h__, 
	doublereal *wt, integer *jstart, integer *idid, doublereal *rpar, 
	integer *ipar, doublereal *phi, doublereal *gamma, doublereal *savr, 
	doublereal *delta, doublereal *e, doublereal *wm, integer *iwm, 
	doublereal *cj, doublereal *cjold, doublereal *cjlast, doublereal *s, 
	doublereal *uround, doublereal *epli, doublereal *sqrtn, doublereal *
	rsqrtn, doublereal *epcon, integer *jcalc, integer *jflg, integer *
	kp1, integer *nonneg, integer *ntype, integer *iernls)
{
    /* Initialized data */

    static integer muldel = 0;
    static integer maxit = 4;
    static doublereal xrate = .25;

    /* System generated locals */
    integer phi_dim1, phi_offset, i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, lwp;
    extern /* Subroutine */ int dnsk_(doublereal *, doublereal *, doublereal *
	    , integer *, S_fp, U_fp, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *);
    static integer ires, liwp;
    static doublereal temp1, temp2, eplin;
    static integer ierpj, iersl;
    static doublereal delnrm;
    static integer iernew;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal tolnew;
    static integer iertyp;


/* ***BEGIN PROLOGUE  DNEDK */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   891219   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  940701   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DNEDK solves a nonlinear system of */
/*     algebraic equations of the form */
/*     G(X,Y,YPRIME) = 0 for the unknown Y. */

/*     The method used is a matrix-free Newton scheme. */

/*     The parameters represent */
/*     X         -- Independent variable. */
/*     Y         -- Solution vector at x. */
/*     YPRIME    -- Derivative of solution vector */
/*                  after successful step. */
/*     NEQ       -- Number of equations to be integrated. */
/*     RES       -- External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     JACK     --  External user-supplied routine to update */
/*                  the preconditioner.  (This is optional). */
/*                  See JAC description for the case */
/*                  INFO(12) = 1 in the DDASPK prologue. */
/*     PSOL      -- External user-supplied routine to solve */
/*                  a linear system using preconditioning. */
/*                  (This is optional).  See explanation inside DDASPK. */
/*     H         -- Appropriate step size for this step. */
/*     WT        -- Vector of weights for error criterion. */
/*     JSTART    -- Indicates first call to this routine. */
/*                  If JSTART = 0, then this is the first call, */
/*                  otherwise it is not. */
/*     IDID      -- Completion flag, output by DNEDK. */
/*                  See IDID description in DDASPK prologue. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     PHI       -- Array of divided differences used by */
/*                  DNEDK.  The length is NEQ*(K+1), where */
/*                  K is the maximum order. */
/*     GAMMA     -- Array used to predict Y and YPRIME.  The length */
/*                  is K+1, where K is the maximum order. */
/*     SAVR      -- Work vector for DNEDK of length NEQ. */
/*     DELTA     -- Work vector for DNEDK of length NEQ. */
/*     E         -- Error accumulation vector for DNEDK of length NEQ. */
/*     WM,IWM    -- Real and integer arrays storing */
/*                  matrix information for linear system */
/*                  solvers, and various other information. */
/*     CJ        -- Parameter always proportional to 1/H. */
/*     CJOLD     -- Saves the value of CJ as of the last call to DITMD. */
/*                  Accounts for changes in CJ needed to */
/*                  decide whether to call DITMD. */
/*     CJLAST    -- Previous value of CJ. */
/*     S         -- A scalar determined by the approximate rate */
/*                  of convergence of the Newton iteration and used */
/*                  in the convergence test for the Newton iteration. */

/*                  If RATE is defined to be an estimate of the */
/*                  rate of convergence of the Newton iteration, */
/*                  then S = RATE/(1.D0-RATE). */

/*                  The closer RATE is to 0., the faster the Newton */
/*                  iteration is converging; the closer RATE is to 1., */
/*                  the slower the Newton iteration is converging. */

/*                  On the first Newton iteration with an up-dated */
/*                  preconditioner S = 100.D0, Thus the initial */
/*                  RATE of convergence is approximately 1. */

/*                  S is preserved from call to call so that the rate */
/*                  estimate from a previous step can be applied to */
/*                  the current step. */
/*     UROUND    -- Unit roundoff.  Not used here. */
/*     EPLI      -- convergence test constant. */
/*                  See DDASPK prologue for more details. */
/*     SQRTN     -- Square root of NEQ. */
/*     RSQRTN    -- reciprical of square root of NEQ. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     JCALC     -- Flag used to determine when to update */
/*                  the Jacobian matrix.  In general: */

/*                  JCALC = -1 ==> Call the DITMD routine to update */
/*                                 the Jacobian matrix. */
/*                  JCALC =  0 ==> Jacobian matrix is up-to-date. */
/*                  JCALC =  1 ==> Jacobian matrix is out-dated, */
/*                                 but DITMD will not be called unless */
/*                                 JCALC is set to -1. */
/*     JFLG      -- Flag showing whether a Jacobian routine is supplied. */
/*     KP1       -- The current order + 1;  updated across calls. */
/*     NONNEG    -- Flag to determine nonnegativity constraints. */
/*     NTYPE     -- Identification code for the DNEDK routine. */
/*                   1 ==> modified Newton; iterative linear solver. */
/*                   2 ==> modified Newton; user-supplied linear solver. */
/*     IERNLS    -- Error flag for nonlinear solver. */
/*                   0 ==> nonlinear solver converged. */
/*                   1 ==> recoverable error inside non-linear solver. */
/*                  -1 ==> unrecoverable error inside non-linear solver. */

/*     The following group of variables are passed as arguments to */
/*     the Newton iteration solver.  They are explained in greater detail */
/*     in DNSK: */
/*        TOLNEW, MULDEL, MAXIT, IERNEW */

/*     IERTYP -- Flag which tells whether this subroutine is correct. */
/*               0 ==> correct subroutine. */
/*               1 ==> incorrect subroutine. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   RES, JACK, DDWNRM, DNSK */

/* ***END PROLOGUE  DNEDK */




    /* Parameter adjustments */
    --y;
    --yprime;
    phi_dim1 = *neq;
    phi_offset = 1 + phi_dim1;
    phi -= phi_offset;
    --wt;
    --rpar;
    --ipar;
    --gamma;
    --savr;
    --delta;
    --e;
    --wm;
    --iwm;

    /* Function Body */

/*     Verify that this is the correct subroutine. */

    iertyp = 0;
    if (*ntype != 1) {
	iertyp = 1;
	goto L380;
    }

/*     If this is the first step, perform initializations. */

    if (*jstart == 0) {
	*cjold = *cj;
	*jcalc = -1;
	*s = 100.;
    }

/*     Perform all other initializations. */

    *iernls = 0;
    lwp = iwm[29];
    liwp = iwm[30];

/*     Decide whether to update the preconditioner. */

    if (*jflg != 0) {
	temp1 = (1. - xrate) / (xrate + 1.);
	temp2 = 1. / temp1;
	if (*cj / *cjold < temp1 || *cj / *cjold > temp2) {
	    *jcalc = -1;
	}
	if (*cj != *cjlast) {
	    *s = 100.;
	}
    } else {
	*jcalc = 0;
    }

/*     Looping point for updating preconditioner with current stepsize. */

L300:

/*     Initialize all error flags to zero. */

    ierpj = 0;
    ires = 0;
    iersl = 0;
    iernew = 0;

/*     Predict the solution and derivative and compute the tolerance */
/*     for the Newton iteration. */

    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	y[i__] = phi[i__ + phi_dim1];
/* L310: */
	yprime[i__] = 0.;
    }
    i__1 = *kp1;
    for (j = 2; j <= i__1; ++j) {
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    y[i__] += phi[i__ + j * phi_dim1];
/* L320: */
	    yprime[i__] += gamma[j] * phi[i__ + j * phi_dim1];
	}
/* L330: */
    }
    eplin = *epli * *epcon;
    tolnew = eplin;

/*     Call RES to initialize DELTA. */

    ++iwm[12];
    (*res)(x, &y[1], &yprime[1], cj, &delta[1], &ires, &rpar[1], &ipar[1]);
    if (ires < 0) {
	goto L380;
    }


/*     If indicated, update the preconditioner. */
/*     Set JCALC to 0 as an indicator that this has been done. */

    if (*jcalc == -1) {
	++iwm[13];
	*jcalc = 0;
	(*jack)((S_fp)res, &ires, neq, x, &y[1], &yprime[1], &wt[1], &delta[1]
		, &e[1], h__, cj, &wm[lwp], &iwm[liwp], &ierpj, &rpar[1], &
		ipar[1]);
	*cjold = *cj;
	*s = 100.;
	if (ires < 0) {
	    goto L380;
	}
	if (ierpj != 0) {
	    goto L380;
	}
    }

/*     Call the nonlinear Newton solver. */

    dnsk_(x, &y[1], &yprime[1], neq, (S_fp)res, (U_fp)psol, &wt[1], &rpar[1], 
	    &ipar[1], &savr[1], &delta[1], &e[1], &wm[1], &iwm[1], cj, sqrtn, 
	    rsqrtn, &eplin, epcon, s, &temp1, &tolnew, &muldel, &maxit, &ires,
	     &iersl, &iernew);

    if (iernew > 0 && *jcalc != 0) {

/*     The Newton iteration had a recoverable failure with an old */
/*     preconditioner.  Retry the step with a new preconditioner. */

	*jcalc = -1;
	goto L300;
    }

    if (iernew != 0) {
	goto L380;
    }

/*     The Newton iteration has converged.  If nonnegativity of */
/*     solution is required, set the solution nonnegative, if the */
/*     perturbation to do it is small enough.  If the change is too */
/*     large, then consider the corrector iteration to have failed. */

    if (*nonneg == 0) {
	goto L390;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L360: */
/* Computing MIN */
	d__1 = y[i__];
	delta[i__] = min(d__1,0.);
    }
    delnrm = ddwnrm_(neq, &delta[1], &wt[1], &rpar[1], &ipar[1]);
    if (delnrm > *epcon) {
	goto L380;
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L370: */
	e[i__] -= delta[i__];
    }
    goto L390;


/*     Exits from nonlinear solver. */
/*     No convergence with current preconditioner. */
/*     Compute IERNLS and IDID accordingly. */

L380:
    if (ires <= -2 || iersl < 0 || iertyp != 0) {
	*iernls = -1;
	if (ires <= -2) {
	    *idid = -11;
	}
	if (iersl < 0) {
	    *idid = -13;
	}
	if (iertyp != 0) {
	    *idid = -15;
	}
    } else {
	*iernls = 1;
	if (ires == -1) {
	    *idid = -10;
	}
	if (ierpj != 0) {
	    *idid = -5;
	}
	if (iersl > 0) {
	    *idid = -14;
	}
    }


L390:
    *jcalc = 1;
    return 0;

/* ------END OF SUBROUTINE DNEDK------------------------------------------ */
} /* dnedk_ */

/* Subroutine */ int dnsk_(doublereal *x, doublereal *y, doublereal *yprime, 
	integer *neq, S_fp res, U_fp psol, doublereal *wt, doublereal *rpar, 
	integer *ipar, doublereal *savr, doublereal *delta, doublereal *e, 
	doublereal *wm, integer *iwm, doublereal *cj, doublereal *sqrtn, 
	doublereal *rsqrtn, doublereal *eplin, doublereal *epcon, doublereal *
	s, doublereal *confac, doublereal *tolnew, integer *muldel, integer *
	maxit, integer *ires, integer *iersl, integer *iernew)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, m;
    static doublereal rate, rhok;
    extern /* Subroutine */ int dslvk_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, S_fp, integer *, U_fp, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal delnrm;
    extern doublereal ddwnrm_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal oldnrm;


/* ***BEGIN PROLOGUE  DNSK */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   891219   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  950126   (YYMMDD) */
/* ***REVISION DATE  000711   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     DNSK solves a nonlinear system of */
/*     algebraic equations of the form */
/*     G(X,Y,YPRIME) = 0 for the unknown Y. */

/*     The method used is a modified Newton scheme. */

/*     The parameters represent */

/*     X         -- Independent variable. */
/*     Y         -- Solution vector. */
/*     YPRIME    -- Derivative of solution vector. */
/*     NEQ       -- Number of unknowns. */
/*     RES       -- External user-supplied subroutine */
/*                  to evaluate the residual.  See RES description */
/*                  in DDASPK prologue. */
/*     PSOL      -- External user-supplied routine to solve */
/*                  a linear system using preconditioning. */
/*                  See explanation inside DDASPK. */
/*     WT        -- Vector of weights for error criterion. */
/*     RPAR,IPAR -- Real and integer arrays used for communication */
/*                  between the calling program and external user */
/*                  routines.  They are not altered within DASPK. */
/*     SAVR      -- Work vector for DNSK of length NEQ. */
/*     DELTA     -- Work vector for DNSK of length NEQ. */
/*     E         -- Error accumulation vector for DNSK of length NEQ. */
/*     WM,IWM    -- Real and integer arrays storing */
/*                  matrix information such as the matrix */
/*                  of partial derivatives, permutation */
/*                  vector, and various other information. */
/*     CJ        -- Parameter always proportional to 1/H (step size). */
/*     SQRTN     -- Square root of NEQ. */
/*     RSQRTN    -- reciprical of square root of NEQ. */
/*     EPLIN     -- Tolerance for linear system solver. */
/*     EPCON     -- Tolerance to test for convergence of the Newton */
/*                  iteration. */
/*     S         -- Used for error convergence tests. */
/*                  In the Newton iteration: S = RATE/(1.D0-RATE), */
/*                  where RATE is the estimated rate of convergence */
/*                  of the Newton iteration. */

/*                  The closer RATE is to 0., the faster the Newton */
/*                  iteration is converging; the closer RATE is to 1., */
/*                  the slower the Newton iteration is converging. */

/*                  The calling routine sends the initial value */
/*                  of S to the Newton iteration. */
/*     CONFAC    -- A residual scale factor to improve convergence. */
/*     TOLNEW    -- Tolerance on the norm of Newton correction in */
/*                  alternative Newton convergence test. */
/*     MULDEL    -- A flag indicating whether or not to multiply */
/*                  DELTA by CONFAC. */
/*                  0  ==> do not scale DELTA by CONFAC. */
/*                  1  ==> scale DELTA by CONFAC. */
/*     MAXIT     -- Maximum allowed number of Newton iterations. */
/*     IRES      -- Error flag returned from RES.  See RES description */
/*                  in DDASPK prologue.  If IRES = -1, then IERNEW */
/*                  will be set to 1. */
/*                  If IRES < -1, then IERNEW will be set to -1. */
/*     IERSL     -- Error flag for linear system solver. */
/*                  See IERSL description in subroutine DSLVK. */
/*                  If IERSL = 1, then IERNEW will be set to 1. */
/*                  If IERSL < 0, then IERNEW will be set to -1. */
/*     IERNEW    -- Error flag for Newton iteration. */
/*                   0  ==> Newton iteration converged. */
/*                   1  ==> recoverable error inside Newton iteration. */
/*                  -1  ==> unrecoverable error inside Newton iteration. */
/* ----------------------------------------------------------------------- */

/* ***ROUTINES CALLED */
/*   RES, DSLVK, DDWNRM */

/* ***END PROLOGUE  DNSK */




/*     Initialize Newton counter M and accumulation vector E. */

    /* Parameter adjustments */
    --iwm;
    --wm;
    --e;
    --delta;
    --savr;
    --ipar;
    --rpar;
    --wt;
    --yprime;
    --y;

    /* Function Body */
    m = 0;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	e[i__] = 0.;
    }

/*     Corrector loop. */

L300:
    ++iwm[19];

/*     If necessary, multiply residual by convergence factor. */

    if (*muldel == 1) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L320: */
	    delta[i__] *= *confac;
	}
    }

/*     Save residual in SAVR. */

    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L340: */
	savr[i__] = delta[i__];
    }

/*     Compute a new iterate.  Store the correction in DELTA. */

    dslvk_(neq, &y[1], x, &yprime[1], &savr[1], &delta[1], &wt[1], &wm[1], &
	    iwm[1], (S_fp)res, ires, (U_fp)psol, iersl, cj, eplin, sqrtn, 
	    rsqrtn, &rhok, &rpar[1], &ipar[1]);
    if (*ires != 0 || *iersl != 0) {
	goto L380;
    }

/*     Update Y, E, and YPRIME. */

    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	y[i__] -= delta[i__];
	e[i__] -= delta[i__];
/* L360: */
	yprime[i__] -= *cj * delta[i__];
    }

/*     Test for convergence of the iteration. */

    delnrm = ddwnrm_(neq, &delta[1], &wt[1], &rpar[1], &ipar[1]);
    if (m == 0) {
	oldnrm = delnrm;
	if (delnrm <= *tolnew) {
	    goto L370;
	}
    } else {
	d__1 = delnrm / oldnrm;
	d__2 = 1. / m;
	rate = pow_dd(&d__1, &d__2);
	if (rate > .9) {
	    goto L380;
	}
	*s = rate / (1. - rate);
    }
    if (*s * delnrm <= *epcon) {
	goto L370;
    }

/*     The corrector has not yet converged.  Update M and test whether */
/*     the maximum number of iterations have been tried. */

    ++m;
    if (m >= *maxit) {
	goto L380;
    }

/*     Evaluate the residual, and go back to do another iteration. */

    ++iwm[12];
    (*res)(x, &y[1], &yprime[1], cj, &delta[1], ires, &rpar[1], &ipar[1]);
    if (*ires < 0) {
	goto L380;
    }
    goto L300;

/*     The iteration has converged. */

L370:
    return 0;

/*     The iteration has not converged.  Set IERNEW appropriately. */

L380:
    if (*ires <= -2 || *iersl < 0) {
	*iernew = -1;
    } else {
	*iernew = 1;
    }
    return 0;


/* ------END OF SUBROUTINE DNSK------------------------------------------- */
} /* dnsk_ */

/* Subroutine */ int dslvk_(integer *neq, doublereal *y, doublereal *tn, 
	doublereal *yprime, doublereal *savr, doublereal *x, doublereal *ewt, 
	doublereal *wm, integer *iwm, S_fp res, integer *ires, U_fp psol, 
	integer *iersl, doublereal *cj, doublereal *eplin, doublereal *sqrtn, 
	doublereal *rsqrtn, doublereal *rhok, doublereal *rpar, integer *ipar)
{
    /* Initialized data */

    static integer irst = 1;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, lq, lr, lv, lz, ldl, nli, nre, kmp, lwk, nps, lwp, 
	    ncfl, lhes, lgmr, maxl, nres, npsl, liwp, iflag;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), dcopy_(integer *, doublereal *, integer *, doublereal 
	    *, integer *);
    static integer miter, nrmax, nrsts, maxlp1;
    extern /* Subroutine */ int dspigm_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , integer *, integer *, doublereal *, doublereal *, S_fp, integer 
	    *, integer *, U_fp, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *);


/* ***BEGIN PROLOGUE  DSLVK */
/* ***REFER TO  DDASPK */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  940928   Removed MNEWT and added RHOK in call list. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* DSLVK uses a restart algorithm and interfaces to DSPIGM for */
/* the solution of the linear system arising from a Newton iteration. */

/* In addition to variables described elsewhere, */
/* communication with DSLVK uses the following variables.. */
/* WM    = Real work space containing data for the algorithm */
/*         (Krylov basis vectors, Hessenberg matrix, etc.). */
/* IWM   = Integer work space containing data for the algorithm. */
/* X     = The right-hand side vector on input, and the solution vector */
/*         on output, of length NEQ. */
/* IRES  = Error flag from RES. */
/* IERSL = Output flag .. */
/*         IERSL =  0 means no trouble occurred (or user RES routine */
/*                    returned IRES < 0) */
/*         IERSL =  1 means the iterative method failed to converge */
/*                    (DSPIGM returned IFLAG > 0.) */
/*         IERSL = -1 means there was a nonrecoverable error in the */
/*                    iterative solver, and an error exit will occur. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DSCAL, DCOPY, DSPIGM */

/* ***END PROLOGUE  DSLVK */




/* ----------------------------------------------------------------------- */
/* IRST is set to 1, to indicate restarting is in effect. */
/* NRMAX is the maximum number of restarts. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ipar;
    --rpar;
    --iwm;
    --wm;
    --ewt;
    --x;
    --savr;
    --yprime;
    --y;

    /* Function Body */

    liwp = iwm[30];
    nli = iwm[20];
    nps = iwm[21];
    ncfl = iwm[16];
    nre = iwm[12];
    lwp = iwm[29];
    maxl = iwm[24];
    kmp = iwm[25];
    nrmax = iwm[26];
    miter = iwm[23];
    *iersl = 0;
    *ires = 0;
/* ----------------------------------------------------------------------- */
/* Use a restarting strategy to solve the linear system */
/* P*X = -F.  Parse the work vector, and perform initializations. */
/* Note that zero is the initial guess for X. */
/* ----------------------------------------------------------------------- */
    maxlp1 = maxl + 1;
    lv = 1;
    lr = lv + *neq * maxl;
    lhes = lr + *neq + 1;
    lq = lhes + maxl * maxlp1;
    lwk = lq + (maxl << 1);
/* Computing MIN */
    i__1 = 1, i__2 = maxl - kmp;
    ldl = lwk + min(i__1,i__2) * *neq;
    lz = ldl + *neq;
    dscal_(neq, rsqrtn, &ewt[1], &c__1);
    dcopy_(neq, &x[1], &c__1, &wm[lr], &c__1);
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L110: */
	x[i__] = 0.;
    }
/* ----------------------------------------------------------------------- */
/* Top of loop for the restart algorithm.  Initial pass approximates */
/* X and sets up a transformed system to perform subsequent restarts */
/* to update X.  NRSTS is initialized to -1, because restarting */
/* does not occur until after the first pass. */
/* Update NRSTS; conditionally copy DL to R; call the DSPIGM */
/* algorithm to solve A*Z = R;  updated counters;  update X with */
/* the residual solution. */
/* Note:  if convergence is not achieved after NRMAX restarts, */
/* then the linear solver is considered to have failed. */
/* ----------------------------------------------------------------------- */
    nrsts = -1;
L115:
    ++nrsts;
    if (nrsts > 0) {
	dcopy_(neq, &wm[ldl], &c__1, &wm[lr], &c__1);
    }
    dspigm_(neq, tn, &y[1], &yprime[1], &savr[1], &wm[lr], &ewt[1], &maxl, &
	    maxlp1, &kmp, eplin, cj, (S_fp)res, ires, &nres, (U_fp)psol, &
	    npsl, &wm[lz], &wm[lv], &wm[lhes], &wm[lq], &lgmr, &wm[lwp], &iwm[
	    liwp], &wm[lwk], &wm[ldl], rhok, &iflag, &irst, &nrsts, &rpar[1], 
	    &ipar[1]);
    nli += lgmr;
    nps += npsl;
    nre += nres;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L120: */
	x[i__] += wm[lz + i__ - 1];
    }
    if (iflag == 1 && nrsts < nrmax && *ires == 0) {
	goto L115;
    }
/* ----------------------------------------------------------------------- */
/* The restart scheme is finished.  Test IRES and IFLAG to see if */
/* convergence was not achieved, and set flags accordingly. */
/* ----------------------------------------------------------------------- */
    if (*ires < 0) {
	++ncfl;
    } else if (iflag != 0) {
	++ncfl;
	if (iflag > 0) {
	    *iersl = 1;
	}
	if (iflag < 0) {
	    *iersl = -1;
	}
    }
/* ----------------------------------------------------------------------- */
/* Update IWM with counters, rescale EWT, and return. */
/* ----------------------------------------------------------------------- */
    iwm[20] = nli;
    iwm[21] = nps;
    iwm[16] = ncfl;
    iwm[12] = nre;
    dscal_(neq, sqrtn, &ewt[1], &c__1);
    return 0;

/* ------END OF SUBROUTINE DSLVK------------------------------------------ */
} /* dslvk_ */

/* Subroutine */ int dspigm_(integer *neq, doublereal *tn, doublereal *y, 
	doublereal *yprime, doublereal *savr, doublereal *r__, doublereal *
	wght, integer *maxl, integer *maxlp1, integer *kmp, doublereal *eplin,
	 doublereal *cj, S_fp res, integer *ires, integer *nre, S_fp psol, 
	integer *npsl, doublereal *z__, doublereal *v, doublereal *hes, 
	doublereal *q, integer *lgmr, doublereal *wp, integer *iwp, 
	doublereal *wk, doublereal *dl, doublereal *rhok, integer *iflag, 
	integer *irst, integer *nrsts, doublereal *rpar, integer *ipar)
{
    /* System generated locals */
    integer v_dim1, v_offset, hes_dim1, hes_offset, i__1, i__2, i__3;
    doublereal d__1;

    /* Local variables */
    static doublereal c__;
    static integer i__, j, k;
    static doublereal s;
    static integer i2, ll, ip1, ier;
    static doublereal tem, rho;
    static integer llp1, info;
    extern /* Subroutine */ int datv_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, S_fp, integer *, S_fp, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, integer *);
    static doublereal prod, rnrm;
    extern doublereal dnrm2_(integer *, doublereal *, integer *);
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), dhels_(doublereal *, integer *, integer *, doublereal 
	    *, doublereal *), dheqr_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *);
    static doublereal dlnrm;
    extern /* Subroutine */ int dcopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *), dorth_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, 
	    doublereal *), daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);
    static integer maxlm1;
    static doublereal snormw;


/* ***BEGIN PROLOGUE  DSPIGM */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */
/* ***REVISION DATE  940927   Removed MNEWT and added RHOK in call list. */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* This routine solves the linear system A * Z = R using a scaled */
/* preconditioned version of the generalized minimum residual method. */
/* An initial guess of Z = 0 is assumed. */

/*      On entry */

/*          NEQ = Problem size, passed to PSOL. */

/*           TN = Current Value of T. */

/*            Y = Array Containing current dependent variable vector. */

/*       YPRIME = Array Containing current first derivative of Y. */

/*         SAVR = Array containing current value of G(T,Y,YPRIME). */

/*            R = The right hand side of the system A*Z = R. */
/*                R is also used as work space when computing */
/*                the final approximation and will therefore be */
/*                destroyed. */
/*                (R is the same as V(*,MAXL+1) in the call to DSPIGM.) */

/*         WGHT = The vector of length NEQ containing the nonzero */
/*                elements of the diagonal scaling matrix. */

/*         MAXL = The maximum allowable order of the matrix H. */

/*       MAXLP1 = MAXL + 1, used for dynamic dimensioning of HES. */

/*          KMP = The number of previous vectors the new vector, VNEW, */
/*                must be made orthogonal to.  (KMP .LE. MAXL.) */

/*        EPLIN = Tolerance on residuals R-A*Z in weighted rms norm. */

/*           CJ = Scalar proportional to current value of */
/*                1/(step size H). */

/*           WK = Real work array used by routine DATV and PSOL. */

/*           DL = Real work array used for calculation of the residual */
/*                norm RHO when the method is incomplete (KMP.LT.MAXL) */
/*                and/or when using restarting. */

/*           WP = Real work array used by preconditioner PSOL. */

/*          IWP = Integer work array used by preconditioner PSOL. */

/*         IRST = Method flag indicating if restarting is being */
/*                performed.  IRST .GT. 0 means restarting is active, */
/*                while IRST = 0 means restarting is not being used. */

/*        NRSTS = Counter for the number of restarts on the current */
/*                call to DSPIGM.  If NRSTS .GT. 0, then the residual */
/*                R is already scaled, and so scaling of R is not */
/*                necessary. */


/*      On Return */

/*         Z    = The final computed approximation to the solution */
/*                of the system A*Z = R. */

/*         LGMR = The number of iterations performed and */
/*                the current order of the upper Hessenberg */
/*                matrix HES. */

/*         NRE  = The number of calls to RES (i.e. DATV) */

/*         NPSL = The number of calls to PSOL. */

/*         V    = The neq by (LGMR+1) array containing the LGMR */
/*                orthogonal vectors V(*,1) to V(*,LGMR). */

/*         HES  = The upper triangular factor of the QR decomposition */
/*                of the (LGMR+1) by LGMR upper Hessenberg matrix whose */
/*                entries are the scaled inner-products of A*V(*,I) */
/*                and V(*,K). */

/*         Q    = Real array of length 2*MAXL containing the components */
/*                of the givens rotations used in the QR decomposition */
/*                of HES.  It is loaded in DHEQR and used in DHELS. */

/*         IRES = Error flag from RES. */

/*           DL = Scaled preconditioned residual, */
/*                (D-inverse)*(P-inverse)*(R-A*Z). Only loaded when */
/*                performing restarts of the Krylov iteration. */

/*         RHOK = Weighted norm of final preconditioned residual. */

/*        IFLAG = Integer error flag.. */
/*                0 Means convergence in LGMR iterations, LGMR.LE.MAXL. */
/*                1 Means the convergence test did not pass in MAXL */
/*                  iterations, but the new residual norm (RHO) is */
/*                  .LT. the old residual norm (RNRM), and so Z is */
/*                  computed. */
/*                2 Means the convergence test did not pass in MAXL */
/*                  iterations, new residual norm (RHO) .GE. old residual */
/*                  norm (RNRM), and the initial guess, Z = 0, is */
/*                  returned. */
/*                3 Means there was a recoverable error in PSOL */
/*                  caused by the preconditioner being out of date. */
/*               -1 Means there was an unrecoverable error in PSOL. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   PSOL, DNRM2, DSCAL, DATV, DORTH, DHEQR, DCOPY, DHELS, DAXPY */

/* ***END PROLOGUE  DSPIGM */


    /* Parameter adjustments */
    v_dim1 = *neq;
    v_offset = 1 + v_dim1;
    v -= v_offset;
    --y;
    --yprime;
    --savr;
    --r__;
    --wght;
    hes_dim1 = *maxlp1;
    hes_offset = 1 + hes_dim1;
    hes -= hes_offset;
    --z__;
    --q;
    --wp;
    --iwp;
    --wk;
    --dl;
    --rpar;
    --ipar;

    /* Function Body */
    ier = 0;
    *iflag = 0;
    *lgmr = 0;
    *npsl = 0;
    *nre = 0;
/* ----------------------------------------------------------------------- */
/* The initial guess for Z is 0.  The initial residual is therefore */
/* the vector R.  Initialize Z to 0. */
/* ----------------------------------------------------------------------- */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	z__[i__] = 0.;
    }
/* ----------------------------------------------------------------------- */
/* Apply inverse of left preconditioner to vector R if NRSTS .EQ. 0. */
/* Form V(*,1), the scaled preconditioned right hand side. */
/* ----------------------------------------------------------------------- */
    if (*nrsts == 0) {
	(*psol)(neq, tn, &y[1], &yprime[1], &savr[1], &wk[1], cj, &wght[1], &
		wp[1], &iwp[1], &r__[1], eplin, &ier, &rpar[1], &ipar[1]);
	*npsl = 1;
	if (ier != 0) {
	    goto L300;
	}
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	    v[i__ + v_dim1] = r__[i__] * wght[i__];
	}
    } else {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L35: */
	    v[i__ + v_dim1] = r__[i__];
	}
    }
/* ----------------------------------------------------------------------- */
/* Calculate norm of scaled vector V(*,1) and normalize it */
/* If, however, the norm of V(*,1) (i.e. the norm of the preconditioned */
/* residual) is .le. EPLIN, then return with Z=0. */
/* ----------------------------------------------------------------------- */
    rnrm = dnrm2_(neq, &v[v_offset], &c__1);
    if (rnrm <= *eplin) {
	*rhok = rnrm;
	return 0;
    }
    tem = 1. / rnrm;
    dscal_(neq, &tem, &v[v_dim1 + 1], &c__1);
/* ----------------------------------------------------------------------- */
/* Zero out the HES array. */
/* ----------------------------------------------------------------------- */
    i__1 = *maxl;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *maxlp1;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L60: */
	    hes[i__ + j * hes_dim1] = 0.;
	}
/* L65: */
    }
/* ----------------------------------------------------------------------- */
/* Main loop to compute the vectors V(*,2) to V(*,MAXL). */
/* The running product PROD is needed for the convergence test. */
/* ----------------------------------------------------------------------- */
    prod = 1.;
    i__1 = *maxl;
    for (ll = 1; ll <= i__1; ++ll) {
	*lgmr = ll;
/* ----------------------------------------------------------------------- */
/* Call routine DATV to compute VNEW = ABAR*V(LL), where ABAR is */
/* the matrix A with scaling and inverse preconditioner factors applied. */
/* Call routine DORTH to orthogonalize the new vector VNEW = V(*,LL+1). */
/* call routine DHEQR to update the factors of HES. */
/* ----------------------------------------------------------------------- */
	datv_(neq, &y[1], tn, &yprime[1], &savr[1], &v[ll * v_dim1 + 1], &
		wght[1], &z__[1], (S_fp)res, ires, (S_fp)psol, &v[(ll + 1) * 
		v_dim1 + 1], &wk[1], &wp[1], &iwp[1], cj, eplin, &ier, nre, 
		npsl, &rpar[1], &ipar[1]);
	if (*ires < 0) {
	    return 0;
	}
	if (ier != 0) {
	    goto L300;
	}
	dorth_(&v[(ll + 1) * v_dim1 + 1], &v[v_offset], &hes[hes_offset], neq,
		 &ll, maxlp1, kmp, &snormw);
	hes[ll + 1 + ll * hes_dim1] = snormw;
	dheqr_(&hes[hes_offset], maxlp1, &ll, &q[1], &info, &ll);
	if (info == ll) {
	    goto L120;
	}
/* ----------------------------------------------------------------------- */
/* Update RHO, the estimate of the norm of the residual R - A*ZL. */
/* If KMP .LT. MAXL, then the vectors V(*,1),...,V(*,LL+1) are not */
/* necessarily orthogonal for LL .GT. KMP.  The vector DL must then */
/* be computed, and its norm used in the calculation of RHO. */
/* ----------------------------------------------------------------------- */
	prod *= q[ll * 2];
	rho = (d__1 = prod * rnrm, abs(d__1));
	if (ll > *kmp && *kmp < *maxl) {
	    if (ll == *kmp + 1) {
		dcopy_(neq, &v[v_dim1 + 1], &c__1, &dl[1], &c__1);
		i__2 = *kmp;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    ip1 = i__ + 1;
		    i2 = i__ << 1;
		    s = q[i2];
		    c__ = q[i2 - 1];
		    i__3 = *neq;
		    for (k = 1; k <= i__3; ++k) {
/* L70: */
			dl[k] = s * dl[k] + c__ * v[k + ip1 * v_dim1];
		    }
/* L75: */
		}
	    }
	    s = q[ll * 2];
	    c__ = q[(ll << 1) - 1] / snormw;
	    llp1 = ll + 1;
	    i__2 = *neq;
	    for (k = 1; k <= i__2; ++k) {
/* L80: */
		dl[k] = s * dl[k] + c__ * v[k + llp1 * v_dim1];
	    }
	    dlnrm = dnrm2_(neq, &dl[1], &c__1);
	    rho *= dlnrm;
	}
/* ----------------------------------------------------------------------- */
/* Test for convergence.  If passed, compute approximation ZL. */
/* If failed and LL .LT. MAXL, then continue iterating. */
/* ----------------------------------------------------------------------- */
	if (rho <= *eplin) {
	    goto L200;
	}
	if (ll == *maxl) {
	    goto L100;
	}
/* ----------------------------------------------------------------------- */
/* Rescale so that the norm of V(1,LL+1) is one. */
/* ----------------------------------------------------------------------- */
	tem = 1. / snormw;
	dscal_(neq, &tem, &v[(ll + 1) * v_dim1 + 1], &c__1);
/* L90: */
    }
L100:
    if (rho < rnrm) {
	goto L150;
    }
L120:
    *iflag = 2;
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L130: */
	z__[i__] = 0.;
    }
    return 0;
L150:
    *iflag = 1;
/* ----------------------------------------------------------------------- */
/* The tolerance was not met, but the residual norm was reduced. */
/* If performing restarting (IRST .gt. 0) calculate the residual vector */
/* RL and store it in the DL array.  If the incomplete version is */
/* being used (KMP .lt. MAXL) then DL has already been calculated. */
/* ----------------------------------------------------------------------- */
    if (*irst > 0) {
	if (*kmp == *maxl) {

/*           Calculate DL from the V(I)'s. */

	    dcopy_(neq, &v[v_dim1 + 1], &c__1, &dl[1], &c__1);
	    maxlm1 = *maxl - 1;
	    i__1 = maxlm1;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		ip1 = i__ + 1;
		i2 = i__ << 1;
		s = q[i2];
		c__ = q[i2 - 1];
		i__2 = *neq;
		for (k = 1; k <= i__2; ++k) {
/* L170: */
		    dl[k] = s * dl[k] + c__ * v[k + ip1 * v_dim1];
		}
/* L175: */
	    }
	    s = q[*maxl * 2];
	    c__ = q[(*maxl << 1) - 1] / snormw;
	    i__1 = *neq;
	    for (k = 1; k <= i__1; ++k) {
/* L180: */
		dl[k] = s * dl[k] + c__ * v[k + *maxlp1 * v_dim1];
	    }
	}

/*        Scale DL by RNRM*PROD to obtain the residual RL. */

	tem = rnrm * prod;
	dscal_(neq, &tem, &dl[1], &c__1);
    }
/* ----------------------------------------------------------------------- */
/* Compute the approximation ZL to the solution. */
/* Since the vector Z was used as work space, and the initial guess */
/* of the Newton correction is zero, Z must be reset to zero. */
/* ----------------------------------------------------------------------- */
L200:
    ll = *lgmr;
    llp1 = ll + 1;
    i__1 = llp1;
    for (k = 1; k <= i__1; ++k) {
/* L210: */
	r__[k] = 0.;
    }
    r__[1] = rnrm;
    dhels_(&hes[hes_offset], maxlp1, &ll, &q[1], &r__[1]);
    i__1 = *neq;
    for (k = 1; k <= i__1; ++k) {
/* L220: */
	z__[k] = 0.;
    }
    i__1 = ll;
    for (i__ = 1; i__ <= i__1; ++i__) {
	daxpy_(neq, &r__[i__], &v[i__ * v_dim1 + 1], &c__1, &z__[1], &c__1);
/* L230: */
    }
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L240: */
	z__[i__] /= wght[i__];
    }
/* Load RHO into RHOK. */
    *rhok = rho;
    return 0;
/* ----------------------------------------------------------------------- */
/* This block handles error returns forced by routine PSOL. */
/* ----------------------------------------------------------------------- */
L300:
    if (ier < 0) {
	*iflag = -1;
    }
    if (ier > 0) {
	*iflag = 3;
    }

    return 0;

/* ------END OF SUBROUTINE DSPIGM----------------------------------------- */
} /* dspigm_ */

/* Subroutine */ int datv_(integer *neq, doublereal *y, doublereal *tn, 
	doublereal *yprime, doublereal *savr, doublereal *v, doublereal *wght,
	 doublereal *yptem, S_fp res, integer *ires, S_fp psol, doublereal *
	z__, doublereal *vtem, doublereal *wp, integer *iwp, doublereal *cj, 
	doublereal *eplin, integer *ier, integer *nre, integer *npsl, 
	doublereal *rpar, integer *ipar)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/* ***BEGIN PROLOGUE  DATV */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* This routine computes the product */

/*   Z = (D-inverse)*(P-inverse)*(dF/dY)*(D*V), */

/* where F(Y) = G(T, Y, CJ*(Y-A)), CJ is a scalar proportional to 1/H, */
/* and A involves the past history of Y.  The quantity CJ*(Y-A) is */
/* an approximation to the first derivative of Y and is stored */
/* in the array YPRIME.  Note that dF/dY = dG/dY + CJ*dG/dYPRIME. */

/* D is a diagonal scaling matrix, and P is the left preconditioning */
/* matrix.  V is assumed to have L2 norm equal to 1. */
/* The product is stored in Z and is computed by means of a */
/* difference quotient, a call to RES, and one call to PSOL. */

/*      On entry */

/*          NEQ = Problem size, passed to RES and PSOL. */

/*            Y = Array containing current dependent variable vector. */

/*       YPRIME = Array containing current first derivative of y. */

/*         SAVR = Array containing current value of G(T,Y,YPRIME). */

/*            V = Real array of length NEQ (can be the same array as Z). */

/*         WGHT = Array of length NEQ containing scale factors. */
/*                1/WGHT(I) are the diagonal elements of the matrix D. */

/*        YPTEM = Work array of length NEQ. */

/*         VTEM = Work array of length NEQ used to store the */
/*                unscaled version of V. */

/*         WP = Real work array used by preconditioner PSOL. */

/*         IWP = Integer work array used by preconditioner PSOL. */

/*           CJ = Scalar proportional to current value of */
/*                1/(step size H). */


/*      On return */

/*            Z = Array of length NEQ containing desired scaled */
/*                matrix-vector product. */

/*         IRES = Error flag from RES. */

/*          IER = Error flag from PSOL. */

/*         NRE  = The number of calls to RES. */

/*         NPSL = The number of calls to PSOL. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   RES, PSOL */

/* ***END PROLOGUE  DATV */


    /* Parameter adjustments */
    --ipar;
    --rpar;
    --iwp;
    --wp;
    --vtem;
    --z__;
    --yptem;
    --wght;
    --v;
    --savr;
    --yprime;
    --y;

    /* Function Body */
    *ires = 0;
/* ----------------------------------------------------------------------- */
/* Set VTEM = D * V. */
/* ----------------------------------------------------------------------- */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	vtem[i__] = v[i__] / wght[i__];
    }
    *ier = 0;
/* ----------------------------------------------------------------------- */
/* Store Y in Z and increment Z by VTEM. */
/* Store YPRIME in YPTEM and increment YPTEM by VTEM*CJ. */
/* ----------------------------------------------------------------------- */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	yptem[i__] = yprime[i__] + vtem[i__] * *cj;
/* L20: */
	z__[i__] = y[i__] + vtem[i__];
    }
/* ----------------------------------------------------------------------- */
/* Call RES with incremented Y, YPRIME arguments */
/* stored in Z, YPTEM.  VTEM is overwritten with new residual. */
/* ----------------------------------------------------------------------- */
    (*res)(tn, &z__[1], &yptem[1], cj, &vtem[1], ires, &rpar[1], &ipar[1]);
    ++(*nre);
    if (*ires < 0) {
	return 0;
    }
/* ----------------------------------------------------------------------- */
/* Set Z = (dF/dY) * VBAR using difference quotient. */
/* (VBAR is old value of VTEM before calling RES) */
/* ----------------------------------------------------------------------- */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L70: */
	z__[i__] = vtem[i__] - savr[i__];
    }
/* ----------------------------------------------------------------------- */
/* Apply inverse of left preconditioner to Z. */
/* ----------------------------------------------------------------------- */
    (*psol)(neq, tn, &y[1], &yprime[1], &savr[1], &yptem[1], cj, &wght[1], &
	    wp[1], &iwp[1], &z__[1], eplin, ier, &rpar[1], &ipar[1]);
    ++(*npsl);
    if (*ier != 0) {
	return 0;
    }
/* ----------------------------------------------------------------------- */
/* Apply D-inverse to Z and return. */
/* ----------------------------------------------------------------------- */
    i__1 = *neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L90: */
	z__[i__] *= wght[i__];
    }
    return 0;

/* ------END OF SUBROUTINE DATV------------------------------------------- */
} /* datv_ */

/* Subroutine */ int dorth_(doublereal *vnew, doublereal *v, doublereal *hes, 
	integer *n, integer *ll, integer *ldhes, integer *kmp, doublereal *
	snormw)
{
    /* System generated locals */
    integer v_dim1, v_offset, hes_dim1, hes_offset, i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, i0;
    static doublereal arg, tem;
    extern doublereal ddot_(integer *, doublereal *, integer *, doublereal *, 
	    integer *);
    static doublereal vnrm;
    extern doublereal dnrm2_(integer *, doublereal *, integer *);
    extern /* Subroutine */ int daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);
    static doublereal sumdsq;


/* ***BEGIN PROLOGUE  DORTH */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* This routine orthogonalizes the vector VNEW against the previous */
/* KMP vectors in the V array.  It uses a modified Gram-Schmidt */
/* orthogonalization procedure with conditional reorthogonalization. */

/*      On entry */

/*         VNEW = The vector of length N containing a scaled product */
/*                OF The Jacobian and the vector V(*,LL). */

/*         V    = The N x LL array containing the previous LL */
/*                orthogonal vectors V(*,1) to V(*,LL). */

/*         HES  = An LL x LL upper Hessenberg matrix containing, */
/*                in HES(I,K), K.LT.LL, scaled inner products of */
/*                A*V(*,K) and V(*,I). */

/*        LDHES = The leading dimension of the HES array. */

/*         N    = The order of the matrix A, and the length of VNEW. */

/*         LL   = The current order of the matrix HES. */

/*          KMP = The number of previous vectors the new vector VNEW */
/*                must be made orthogonal to (KMP .LE. MAXL). */


/*      On return */

/*         VNEW = The new vector orthogonal to V(*,I0), */
/*                where I0 = MAX(1, LL-KMP+1). */

/*         HES  = Upper Hessenberg matrix with column LL filled in with */
/*                scaled inner products of A*V(*,LL) and V(*,I). */

/*       SNORMW = L-2 norm of VNEW. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DDOT, DNRM2, DAXPY */

/* ***END PROLOGUE  DORTH */


/* ----------------------------------------------------------------------- */
/* Get norm of unaltered VNEW for later use. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --vnew;
    v_dim1 = *n;
    v_offset = 1 + v_dim1;
    v -= v_offset;
    hes_dim1 = *ldhes;
    hes_offset = 1 + hes_dim1;
    hes -= hes_offset;

    /* Function Body */
    vnrm = dnrm2_(n, &vnew[1], &c__1);
/* ----------------------------------------------------------------------- */
/* Do Modified Gram-Schmidt on VNEW = A*V(LL). */
/* Scaled inner products give new column of HES. */
/* Projections of earlier vectors are subtracted from VNEW. */
/* ----------------------------------------------------------------------- */
/* Computing MAX */
    i__1 = 1, i__2 = *ll - *kmp + 1;
    i0 = max(i__1,i__2);
    i__1 = *ll;
    for (i__ = i0; i__ <= i__1; ++i__) {
	hes[i__ + *ll * hes_dim1] = ddot_(n, &v[i__ * v_dim1 + 1], &c__1, &
		vnew[1], &c__1);
	tem = -hes[i__ + *ll * hes_dim1];
	daxpy_(n, &tem, &v[i__ * v_dim1 + 1], &c__1, &vnew[1], &c__1);
/* L10: */
    }
/* ----------------------------------------------------------------------- */
/* Compute SNORMW = norm of VNEW. */
/* If VNEW is small compared to its input value (in norm), then */
/* Reorthogonalize VNEW to V(*,1) through V(*,LL). */
/* Correct if relative correction exceeds 1000*(unit roundoff). */
/* Finally, correct SNORMW using the dot products involved. */
/* ----------------------------------------------------------------------- */
    *snormw = dnrm2_(n, &vnew[1], &c__1);
    if (vnrm + *snormw * .001 != vnrm) {
	return 0;
    }
    sumdsq = 0.;
    i__1 = *ll;
    for (i__ = i0; i__ <= i__1; ++i__) {
	tem = -ddot_(n, &v[i__ * v_dim1 + 1], &c__1, &vnew[1], &c__1);
	if (hes[i__ + *ll * hes_dim1] + tem * .001 == hes[i__ + *ll * 
		hes_dim1]) {
	    goto L30;
	}
	hes[i__ + *ll * hes_dim1] -= tem;
	daxpy_(n, &tem, &v[i__ * v_dim1 + 1], &c__1, &vnew[1], &c__1);
/* Computing 2nd power */
	d__1 = tem;
	sumdsq += d__1 * d__1;
L30:
	;
    }
    if (sumdsq == 0.) {
	return 0;
    }
/* Computing MAX */
/* Computing 2nd power */
    d__3 = *snormw;
    d__1 = 0., d__2 = d__3 * d__3 - sumdsq;
    arg = max(d__1,d__2);
    *snormw = sqrt(arg);
    return 0;

/* ------END OF SUBROUTINE DORTH------------------------------------------ */
} /* dorth_ */

/* Subroutine */ int dheqr_(doublereal *a, integer *lda, integer *n, 
	doublereal *q, integer *info, integer *ijob)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal c__;
    static integer i__, j, k;
    static doublereal s, t, t1, t2;
    static integer iq, km1, kp1, nm1;


/* ***BEGIN PROLOGUE  DHEQR */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */

/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/*     This routine performs a QR decomposition of an upper */
/*     Hessenberg matrix A.  There are two options available: */

/*          (1)  performing a fresh decomposition */
/*          (2)  updating the QR factors by adding a row and A */
/*               column to the matrix A. */

/*     DHEQR decomposes an upper Hessenberg matrix by using Givens */
/*     rotations. */

/*     On entry */

/*        A       DOUBLE PRECISION(LDA, N) */
/*                The matrix to be decomposed. */

/*        LDA     INTEGER */
/*                The leading dimension of the array A. */

/*        N       INTEGER */
/*                A is an (N+1) by N Hessenberg matrix. */

/*        IJOB    INTEGER */
/*                = 1     Means that a fresh decomposition of the */
/*                        matrix A is desired. */
/*                .GE. 2  Means that the current decomposition of A */
/*                        will be updated by the addition of a row */
/*                        and a column. */
/*     On return */

/*        A       The upper triangular matrix R. */
/*                The factorization can be written Q*A = R, where */
/*                Q is a product of Givens rotations and R is upper */
/*                triangular. */

/*        Q       DOUBLE PRECISION(2*N) */
/*                The factors C and S of each Givens rotation used */
/*                in decomposing A. */

/*        INFO    INTEGER */
/*                = 0  normal value. */
/*                = K  If  A(K,K) .EQ. 0.0.  This is not an error */
/*                     condition for this subroutine, but it does */
/*                     indicate that DHELS will divide by zero */
/*                     if called. */

/*     Modification of LINPACK. */
/*     Peter Brown, Lawrence Livermore Natl. Lab. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED (NONE) */

/* ***END PROLOGUE  DHEQR */


    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --q;

    /* Function Body */
    if (*ijob > 1) {
	goto L70;
    }
/* ----------------------------------------------------------------------- */
/* A new factorization is desired. */
/* ----------------------------------------------------------------------- */

/*     QR decomposition without pivoting. */

    *info = 0;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	km1 = k - 1;
	kp1 = k + 1;

/*           Compute Kth column of R. */
/*           First, multiply the Kth column of A by the previous */
/*           K-1 Givens rotations. */

	if (km1 < 1) {
	    goto L20;
	}
	i__2 = km1;
	for (j = 1; j <= i__2; ++j) {
	    i__ = (j - 1 << 1) + 1;
	    t1 = a[j + k * a_dim1];
	    t2 = a[j + 1 + k * a_dim1];
	    c__ = q[i__];
	    s = q[i__ + 1];
	    a[j + k * a_dim1] = c__ * t1 - s * t2;
	    a[j + 1 + k * a_dim1] = s * t1 + c__ * t2;
/* L10: */
	}

/*           Compute Givens components C and S. */

L20:
	iq = (km1 << 1) + 1;
	t1 = a[k + k * a_dim1];
	t2 = a[kp1 + k * a_dim1];
	if (t2 != 0.) {
	    goto L30;
	}
	c__ = 1.;
	s = 0.;
	goto L50;
L30:
	if (abs(t2) < abs(t1)) {
	    goto L40;
	}
	t = t1 / t2;
	s = -1. / sqrt(t * t + 1.);
	c__ = -s * t;
	goto L50;
L40:
	t = t2 / t1;
	c__ = 1. / sqrt(t * t + 1.);
	s = -c__ * t;
L50:
	q[iq] = c__;
	q[iq + 1] = s;
	a[k + k * a_dim1] = c__ * t1 - s * t2;
	if (a[k + k * a_dim1] == 0.) {
	    *info = k;
	}
/* L60: */
    }
    return 0;
/* ----------------------------------------------------------------------- */
/* The old factorization of A will be updated.  A row and a column */
/* has been added to the matrix A. */
/* N by N-1 is now the old size of the matrix. */
/* ----------------------------------------------------------------------- */
L70:
    nm1 = *n - 1;
/* ----------------------------------------------------------------------- */
/* Multiply the new column by the N previous Givens rotations. */
/* ----------------------------------------------------------------------- */
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
	i__ = (k - 1 << 1) + 1;
	t1 = a[k + *n * a_dim1];
	t2 = a[k + 1 + *n * a_dim1];
	c__ = q[i__];
	s = q[i__ + 1];
	a[k + *n * a_dim1] = c__ * t1 - s * t2;
	a[k + 1 + *n * a_dim1] = s * t1 + c__ * t2;
/* L100: */
    }
/* ----------------------------------------------------------------------- */
/* Complete update of decomposition by forming last Givens rotation, */
/* and multiplying it times the column vector (A(N,N),A(NP1,N)). */
/* ----------------------------------------------------------------------- */
    *info = 0;
    t1 = a[*n + *n * a_dim1];
    t2 = a[*n + 1 + *n * a_dim1];
    if (t2 != 0.) {
	goto L110;
    }
    c__ = 1.;
    s = 0.;
    goto L130;
L110:
    if (abs(t2) < abs(t1)) {
	goto L120;
    }
    t = t1 / t2;
    s = -1. / sqrt(t * t + 1.);
    c__ = -s * t;
    goto L130;
L120:
    t = t2 / t1;
    c__ = 1. / sqrt(t * t + 1.);
    s = -c__ * t;
L130:
    iq = (*n << 1) - 1;
    q[iq] = c__;
    q[iq + 1] = s;
    a[*n + *n * a_dim1] = c__ * t1 - s * t2;
    if (a[*n + *n * a_dim1] == 0.) {
	*info = *n;
    }
    return 0;

/* ------END OF SUBROUTINE DHEQR------------------------------------------ */
} /* dheqr_ */

/* Subroutine */ int dhels_(doublereal *a, integer *lda, integer *n, 
	doublereal *q, doublereal *b)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static doublereal c__;
    static integer k;
    static doublereal s, t, t1, t2;
    static integer kb, iq, kp1;
    extern /* Subroutine */ int daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);


/* ***BEGIN PROLOGUE  DHELS */
/* ***DATE WRITTEN   890101   (YYMMDD) */
/* ***REVISION DATE  900926   (YYMMDD) */


/* ----------------------------------------------------------------------- */
/* ***DESCRIPTION */

/* This is similar to the LINPACK routine DGESL except that */
/* A is an upper Hessenberg matrix. */

/*     DHELS solves the least squares problem */

/*           MIN (B-A*X,B-A*X) */

/*     using the factors computed by DHEQR. */

/*     On entry */

/*        A       DOUBLE PRECISION (LDA, N) */
/*                The output from DHEQR which contains the upper */
/*                triangular factor R in the QR decomposition of A. */

/*        LDA     INTEGER */
/*                The leading dimension of the array  A . */

/*        N       INTEGER */
/*                A is originally an (N+1) by N matrix. */

/*        Q       DOUBLE PRECISION(2*N) */
/*                The coefficients of the N givens rotations */
/*                used in the QR factorization of A. */

/*        B       DOUBLE PRECISION(N+1) */
/*                The right hand side vector. */


/*     On return */

/*        B       The solution vector X. */


/*     Modification of LINPACK. */
/*     Peter Brown, Lawrence Livermore Natl. Lab. */

/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DAXPY */

/* ***END PROLOGUE  DHELS */


/*        Minimize (B-A*X,B-A*X). */
/*        First form Q*B. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --q;
    --b;

    /* Function Body */
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	kp1 = k + 1;
	iq = (k - 1 << 1) + 1;
	c__ = q[iq];
	s = q[iq + 1];
	t1 = b[k];
	t2 = b[kp1];
	b[k] = c__ * t1 - s * t2;
	b[kp1] = s * t1 + c__ * t2;
/* L20: */
    }

/*        Now solve R*X = Q*B. */

    i__1 = *n;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n + 1 - kb;
	b[k] /= a[k + k * a_dim1];
	t = -b[k];
	i__2 = k - 1;
	daxpy_(&i__2, &t, &a[k * a_dim1 + 1], &c__1, &b[1], &c__1);
/* L40: */
    }
    return 0;

/* ------END OF SUBROUTINE DHELS------------------------------------------ */
} /* dhels_ */

/* ----------------------------------------------------------------------- */

/*             Preconditioner Routines for Sparse Problems */
/*                          13 December 2000 */

/* The following triple of subroutines -- DSPSETUP, DJACILU and */
/* DPSOLILU -- provides a general-purpose sparse incomplete LU (ILU) */
/* preconditioner matrix for use with the DDASPK solver, with the Krylov */
/* linear system method.  When using DDASPK to solve a problem */
/* G(t,y,y') = 0, whose iteration matrix (Jacobian) */
/*    J = dG/dy + c * dG/dy'  (c = scalar) */
/* is a general sparse matrix, these routines can be used to generate */
/* an approximation to J as the preconditioner and to solve the resulting */
/* sparse linear system, in conjunction with the Krylov method option */
/* (INFO(12) = 1) in DDASPK. */

/* The incomplete LU factorization is achieved via one of two routines */
/* from the SPARSKIT library available from Yousef Saad at the */
/* University of Minnesota.  The two routines are ILUT and ILUTP. */
/* See below for detailed descriptions of these routines. */

/* Descriptions of the above routines are as follows: */

/* DSPSETUP   - Setup routine for the preconditioner.  This routine */
/*              checks the user input for illegal values, and calculates */
/*              the minimum length needed for preconditioner workspace */
/*              arrays in DDASPK. */

/* DJACILU   -  This routine is a version of JAC for DDASPK. */
/*              It uses finite-differences to calculate the Jacobian */
/*              matrix J in sparse format, and then performs an */
/*              incomplete LU factorization using either ILUT or ILUTP. */
/*              DJACILU must be declared EXTERNAL in the user's main */
/*              program and passed through to DDASPK. */

/* DPSOLILU   - This routine is a version of PSOL for DDASPK. */
/*              It uses the incomplete factorization calculated in */
/*              DJACILU.  DPSOLILU must be declared EXTERNAL in the */
/*              user's main program and passed through to DDASPK. */


/* The routines ILUT and ILUTP are part of the SPARSKIT library, */
/* and are contained in the file 'dsparsk.f'.  ILUT performs an */
/* incomplete LU factorization of a sparse matrix using a dual */
/* thresholding technique based on a drop tolerance (TOLILUT below) */
/* and a level of fill-in parameter (LFILILUT).  LFILILUT controls */
/* the amount of fill-in allowed in the factorization (limited to a */
/* maximum of 2*LFILILUT*NEQ, but normally much less).  Increasing */
/* LFILILUT will generally make the ILU factorization more accurate. */
/* TOLILUT also controls the accuracy of the ILU factorization via */
/* a drop tolerance based on element size.  Descreasing TOLILUT */
/* will increase the amount of fill-in and make for a more accurate */
/* factorization.  ILUTP is a variant of ILUT that in addition performs */
/* pivoting based on a tolerance ratio PERMTOL. */

/* An important aspect of using incomplete factorization techniques */
/* is that of reordering the rows and columns in the Jacobian matrix */
/* J before performing the ILU.  In this package, this is accomplished */
/* via the parameter IREORDER, which when equal to 1 performs */
/* a reverse Cuthill-McKee (RCM) reordering before performing the */
/* ILU factorization.  Based on the limited amount of testing done so */
/* far, RCM seems the best overall choice.  It is possible to include */
/* a different reordering technique if desired. */

/* To use these routines in conjunction with DDASPK, the user's calling */
/* program should include the following, in addition to setting the other */
/* DDASPK input parameters. */

/* (a) Dimension the array IPAR to have length at least 30, and load the */
/*     following parameters into IPAR as */

/*      IPAR(1)  = ML        - The lower bandwidth used in calculating */
/*                             the approximate Jacobian matrix. */
/*      IPAR(2)  = MU        - The upper bandwidth used in calculating */
/*                             the approximate Jacobian matrix. */
/*      IPAR(3)  = LENPFAC   - The average number of nonzeros in a */
/*                             row of the Jacobian matrix.  The */
/*                             maximum of nonzeros allowed in the */
/*                             Jacobian matrix is NNZMX = LENPFAC*NEQ. */
/*                             LENPFAC must be .GE. 2. */
/*      IPAR(4)  = LENPLUFAC - The average amount of fill-in per row */
/*                             in the factored Jacobian matrix.  The */
/*                             maximum number of nonzeros allowed */
/*                             in the factored Jacobian matrix is */
/*                             LENPLUMX = NNZMX + LENPLUFAC*NEQ. */
/*                             LENPLUFAC must be .GE. 2. */
/*      IPAR(5)  = IPREMETH  - Preconditioner type flag. */
/*                             =1 means ILUT preconditioner used */
/*                             =2 means ILUTP preconditioner used */
/*      IPAR(6)  = LFILILUT  - Fill-in parameter for ILUT and ILUTP. */
/*                             The largest LFILILUT elements per row */
/*                             of the L and U factors are kept.  Each */
/*                             row of L and U will have a maximum of */
/*                             LFILILUT elements in addition to */
/*                             their original number of nonzero */
/*                             elements. */
/*      IPAR(7)  = IREORDER  - Reordering flag. */
/*                             =0 means that no reordering of the */
/*                                rows and columns of the Jacobian */
/*                                matrix is performed before the */
/*                                incomplete factorization is performed. */
/*                             =1 means that a reverse Cuthill-McKee */
/*                                (RCM) reordering is performed. */
/*      IPAR(8)  = ISRNORM   - Row norm flag. */
/*                             =1 means that row norms of the Jacobian */
/*                                matrix are computed and used as */
/*                                row scalings when solving the */
/*                                preconditioner linear system P*x=b. */
/*                             =0 means no row norm scaling is used. */
/*      IPAR(9)  = NORMTYPE  - Type of row norm scaling for ISRNORM */
/*                             =0 means max-norm is used. */
/*                             =1 means 1-norm is used. */
/*                             =2 means 2-norm is used. */
/*      IPAR(10) = JACOUT    - Output Jacobian flag. */
/*                             =1 means write the calculated Jacobian */
/*                                matrix along with the initial value of */
/*                                the residual G to a file pointed to by */
/*                                the logical unit number in IPAR(29). */
/*                                This is done after any reordering and */
/*                                scaling is performed.  The user must */
/*                                have attached the unit number to a */
/*                                file before calling DDASPK.  The */
/*                                integration is then halted by setting */
/*                                IRES = -2 (and a false message about */
/*                                failure to initialize is printed). */
/*                             =0 means no Jacobian matrix output. */
/*                             The matrix and initial residual G are */
/*                             written in Boeing-Harwell format. */
/*      IPAR(11) = JSCALCOL  - Flag for scaling columns of the */
/*                             Jacobian matrix by the inverses of the */
/*                             elements in the EWT array. */
/*                             =0 means no scaling. */
/*                             =1 means perform scaling. */

/*      IPAR(21:28)          - Used to hold pointer information. */
/*      IPAR(29)             - Logical unit number to write matrix output */
/*                             file on.  Only needed when JACOUT = 1. */
/*      IPAR(30)             - On return from DDASPK, this value */
/*                             holds the number of calls to the */
/*                             RES routine used in the preconditioner */
/*                             evaluations. */

/* (b) Dimension the array RPAR to have length at least 2, and load the */
/*     following parameters into RPAR as */

/*      RPAR(1)  = TOLILUT   - Drop tolerance for use by ILUT and ILUTP. */
/*                             TOLILUT must be .ge. 0.  Larger values */
/*                             of TOLILUT cause less fill-in.  Good */
/*                             values range from 0.001 to 0.01. */
/*      RPAR(2)  = PERMTOL   - Tolerance ratio used in determining column */
/*                             pivoting by ILUTP.  PERMTOL must be */
/*                             .ge. 0.  Good values are from 0.1 to */
/*                             0.01.  Two columns are permuted only if */
/*                             A(i,j)*PERMTOL .GT. A(i,i). */

/*     The two paramaters TOLILUT and LFILILUT gives the user a great */
/*     deal of flexibility: one can use TOLILUT=0 to get a strategy */
/*     based on keeping the largest elements in each row of L and U. */
/*     Taking TOLILUT .NE. 0 but LFILILUT=NEQ will give the usual */
/*     threshold strategy (however, fill-in is then unpredictable). */

/* (c) Include the names DJACILU and DPSOLILU in an EXTERNAL statement. */
/*     Set INFO(15) = 1 to indicate that a JAC routine exists. */
/*     Then in the call to DDASPK, pass the names DJACILU and DPSOLILU */
/*     as the arguments JAC and PSOL, respectively. */

/* (d) The DDASPK work arrays RWORK and IWORK must include segments WP */
/*     and IWP for use by DJACILU/DPSOLILU.  The lengths of these depend */
/*     on the problem size, half-bandwidths, and other parameters */
/*     as follows: */
/*       LWP =  length of RWORK segment WP = */
/*              2*LENPFAC*NEQ + LENPLUFAC*NEQ + ISRNORM*NEQ + NEQ */
/*       LIWP = length of IWORK segment IWP = */
/*              3*NEQ+1 + 3*LENPFAC*NEQ + 2*LENPLUFAC*NEQ */
/*                 + 2*IREORDER*NEQ + 2*(IPREMETH-1)*NEQ */
/*     Load these lengths in IWORK as */
/*       IWORK(27) = LWP */
/*       IWORK(28) = LIWP */
/*     and include these values in the declared size of RWORK and IWORK. */


/* The DJACILU and DPSOLILU routines generate and solve the sparse */
/* preconditioner matrix P within the preconditioned Krylov algorithm */
/* used by DDASPK when INFO(12) = 1.  P is generated and ILU-factored */
/* periodically during the integration, and the factors are used to */
/* solve systems Px = b as needed. */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int dspsetup_(integer *neq, integer *lwp, integer *liwp, 
	doublereal *rpar, integer *ipar, integer *ierr, integer *lwp_min__, 
	integer *liwp_min__)
{
    static integer jscalcol, ireorder, ipremeth, lfililut, lenplumx, normtype,
	     lrownrms, lenplufac, lbw, lju, ubw, ljac, ljlu, lplu, neqp1, 
	    liwk1, lrwk1, ljaci, ljacj, lmask, lperm, nnzmx, jacout, lqperm, 
	    lenpfac, llevels;
    static doublereal permtol;
    static integer isrnorm;
    static doublereal tolilut;

/* ... Version of 12-12-00 */
/* ... Calculate storage needed for ILU decomposition of the Jacobian */
/*     matrix for use as a preconditioner by the DDASPK solver. */
/*     Also, check for illegal input. */
/* ... Input arguments: */
/* total number of equations */
/* user real workspace */
/* user integer workspace */
/* current length of WP for DDASPK */
/* ... Output arguments: */
/* current length of IWP for DDASPK */
/* IERR between 1 and 11, means there's an */
/* illegal value for IPAR(IERR). */
/* IERR = 12 means IPAR(29) is illegal. */
/* IERR = 21 means RPAR(1) is illegal. */
/* IERR = 22 means RPAR(2) is illegal. */
/* IERR = 30 means more WP length is needed. */
/* IERR = 31 means more IWP length is needed. */
/* error flag (0 means success, else failure) */
/* minimum WP length needed. */
/* ... Local variables: */
/* minimum IWP length needed. */
/* =1 causes row normalization of JAC. */
/* 2-norm row scaling */
/* =0,1,2 for max-norm, 1-norm, or */
/* =1 causes row and column reordering of JAC. */
/*   be written to a file and then exit with */
/*   ierr = 1 to signal a stop to DDASPK. */
/* =1 causes the Jacobian matrix and SAVR to */
/*   to be scaled by EWT-inverse */
/* =1 causes the columns of the Jacobian matrix */
/* ... Load values from IPAR and RPAR.  Check for illegal values. */
    /* Parameter adjustments */
    --ipar;
    --rpar;

    /* Function Body */
    lbw = ipar[1];
/* LBW must be .gt. 0 */
    if (lbw <= 0) {
	*ierr = 1;
	return 0;
    }
    ubw = ipar[2];
/* UBW must be .gt. 0 */
    if (ubw <= 0) {
	*ierr = 2;
	return 0;
    }
    lenpfac = ipar[3];
/* LENPFAC must be .ge. 2 */
    if (lenpfac <= 1) {
	*ierr = 3;
	return 0;
    }
    lenplufac = ipar[4];
/* LENPLUFAC must be .ge. 2 */
    if (lenplufac <= 1) {
	*ierr = 4;
	return 0;
    }
    ipremeth = ipar[5];
/* IPREMETH must be .eq. 1 or 2 currently */
    if (ipremeth != 1 && ipremeth != 2) {
	*ierr = 5;
	return 0;
    }
    lfililut = ipar[6];
/* LFILILUT must be .ge. 0 */
    if (lfililut < 0) {
	*ierr = 6;
	return 0;
    }
    ireorder = ipar[7];
/* IREORDER must be 0 or 1 */
    if (ireorder < 0 || ireorder > 1) {
	*ierr = 7;
	return 0;
    }
    isrnorm = ipar[8];
/* ISRNORM must be 0 or 1 */
    if (isrnorm < 0 || isrnorm > 1) {
	*ierr = 8;
	return 0;
    }
    normtype = ipar[9];
/* NORMTYPE must be 0, 1, or 2 */
    if (normtype < 0 || normtype > 2) {
	*ierr = 9;
	return 0;
    }
    jacout = ipar[10];
/* JACOUT must be 0 or 1 */
    if (jacout < 0 || jacout > 1) {
	*ierr = 10;
	return 0;
    }
    jscalcol = ipar[11];
/* JSCALCOL must be 0 or 1 */
    if (jscalcol < 0 || jscalcol > 1) {
	*ierr = 11;
	return 0;
    }
    if (jacout == 1) {
/* IPAR(29) must be .gt. 0 */
	if (ipar[29] <= 0) {
	    *ierr = 12;
	    return 0;
	}
    }
    tolilut = rpar[1];
/* TOLILUT must be .ge. 0.0 */
    if (tolilut < 0.f) {
	*ierr = 21;
	return 0;
    }
    if (ipremeth == 2) {
	permtol = rpar[2];
/* PERMTOL must be .ge. 0.0 */
	if (permtol < 0.f) {
	    *ierr = 22;
	    return 0;
	}
    }
/* ... Calculate minimum work lengths for WP and IWP arrays. */
    neqp1 = *neq + 1;
    nnzmx = lenpfac * *neq;
    lenplumx = nnzmx + lenplufac * *neq;
/* ... Set up pointers into WP */
    ljac = 1;
    lrownrms = nnzmx + ljac;
    if (isrnorm == 1) {
	lplu = lrownrms + *neq;
    } else {
	lplu = lrownrms;
    }
    lrwk1 = lplu + lenplumx;
    *lwp_min__ = lrwk1 + *neq - 1;
    if (*lwp < *lwp_min__) {
	*ierr = 30;
/* more WP length needed. */
	return 0;
    }
/* ... Set up pointers into IWP */
    ljaci = 1;
    ljacj = ljaci + neqp1;
    lju = ljacj + nnzmx;
    ljlu = lju + max(lenplumx,neqp1);
    if (ireorder != 0) {
	lperm = ljlu + lenplumx;
	lqperm = lperm + *neq;
	liwk1 = lqperm + *neq;
	llevels = ljlu + nnzmx;
/* assumes that LENPLUFAC >= 2. */
	lmask = llevels + *neq;
    } else {
	lperm = 0;
	lqperm = 0;
	llevels = 0;
	lmask = 0;
	liwk1 = ljlu + lenplumx;
    }
    *liwp_min__ = liwk1 + (*neq << 1) - 1;
    if (ipremeth == 2) {
	*liwp_min__ += *neq << 1;
    }
    if (*liwp < *liwp_min__) {
	*ierr = 31;
/* more IWP length needed. */
	return 0;
    }
    *ierr = 0;
    return 0;
/* ------------  End of Subroutine DSPSETUP  ----------------------------- */
} /* dspsetup_ */

/* Subroutine */ int djacilu_(U_fp res, integer *ires, integer *neq, 
	doublereal *t, doublereal *y, doublereal *yprime, doublereal *rewt, 
	doublereal *savr, doublereal *wk, doublereal *h__, doublereal *cj, 
	doublereal *wp, integer *iwp, integer *ierr, doublereal *rpar, 
	integer *ipar)
{
    /* Initialized data */

    static char pmeth[8*4] = "ILUT    " "ILUTP   " "ILU0    " "MILU0   ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ void s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static integer jscalcol, ireorder, ipremeth, lfililut, lenplumx, normtype,
	     lrownrms, i__, lenplufac, nre, lbw;
    static char msg[80];
    static integer lju, ubw, ljac, ifmt, ljlu, lplu, neqp1, liwk1, lrwk1, 
	    ljaci, ljacj, lmask;
    extern /* Subroutine */ int djilu_(integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    integer *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, doublereal *, char *, integer *, integer *, ftnlen);
    static integer lperm;
    static char title[72];
    static integer iunit;
    extern /* Subroutine */ int prtmt_(integer *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, char *, char *, char *, char *
	    , integer *, integer *, integer *, ftnlen, ftnlen, ftnlen, ftnlen)
	    ;
    static doublereal sqrtn;
    static integer nnzmx;
    extern /* Subroutine */ int djcalc_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *, U_fp, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, integer *, integer *, integer 
	    *), amudia_(integer *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *), 
	    roscal_(integer *, integer *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    integer *);
    static integer jacout, liperm;
    extern /* Subroutine */ int dvperm_(integer *, doublereal *, integer *);
    static integer lqperm;
    extern /* Subroutine */ int xerrwd_(char *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, doublereal *, 
	    doublereal *, ftnlen);
    static integer lenpfac;
    extern /* Subroutine */ int djreord_(integer *, integer *, integer *, 
	    char *, doublereal *, integer *, integer *, doublereal *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, ftnlen);
    static char premeth[8];
    static integer llevels;
    static doublereal permtol;
    static integer isrnorm;
    static doublereal tolilut;

/* ... Version of 12-12-00 */
/* ... Calculate ILU decomposition of the Jacobian matrix */
/*     for use as a preconditioner by the DDASPK solver. */
/* ... Input arguments: */
/* total number of equations */
/* independent variable t */
/* most recent iterate of solution vector y */
/* most recent iterate of solution vector y' */
/* current residual evaluated at (T,Y,YPRIME) */
/* scale factors for Y and YPRIME */
/* function that evaluates residuals */
/* error flag for RES routine */
/* work space available to this subroutine */
/* current step size */
/* scalar proportional to 1/H */
/* user real workspace */
/* ... Output arguments: */
/* user integer workspace */
/* matrix elements of ILU */
/* array indices for elements of ILU */
/* Jacobian NRE is returned in IPAR(30) */
/* number of RES calls needed to evaluate */
/* ... Local variables: */
/* error flag (0 means success, else failure) */
/* =1 causes row normalization of Jac. */
/* 2-norm row scaling */
/* =0,1,2 for max-norm, 1-norm, or */
/* =1 causes row and column reordering of Jac. */
/*   be written to a file and then exit with */
/*   IRES = -2 to signal a stop to DDASPK. */
/* =1 causes the Jacobian matrix and SAVR to */
/* logical unit number to use when JACOUT .EQ. 1 */
/*   to be scaled by REWT-inverse */
/* =1 causes the columns of the Jacobian matrix */
    /* Parameter adjustments */
    --wk;
    --savr;
    --rewt;
    --yprime;
    --y;
    --wp;
    --iwp;
    --rpar;
    --ipar;

    /* Function Body */
/* ... Zero out NRE counter */
    nre = 0;
/* ... Load values from IPAR and RPAR. */
    lbw = ipar[1];
    ubw = ipar[2];
    lenpfac = ipar[3];
    lenplufac = ipar[4];
    ipremeth = ipar[5];
    lfililut = ipar[6];
    ireorder = ipar[7];
    isrnorm = ipar[8];
    normtype = ipar[9];
    jacout = ipar[10];
    jscalcol = ipar[11];
    tolilut = rpar[1];
    permtol = rpar[2];
    s_copy(premeth, pmeth + (ipremeth - 1 << 3), (ftnlen)8, (ftnlen)8);
/* ... Set pointers into the WP and IWP arrays. */
    neqp1 = *neq + 1;
    nnzmx = lenpfac * *neq;
    lenplumx = nnzmx + lenplufac * *neq;
/* ... Set up pointers into WP */
    ljac = 1;
    lrownrms = nnzmx + ljac;
    if (isrnorm == 1) {
	lplu = lrownrms + *neq;
    } else {
	lplu = lrownrms;
    }
    lrwk1 = lplu + lenplumx;
/* ... Set up pointers into IWP */
    ljaci = 1;
    ljacj = ljaci + neqp1;
    lju = ljacj + nnzmx;
    ljlu = lju + lenplumx;
/* ... Calculate Jacobian matrix. */
    *ierr = 0;
    djcalc_(neq, t, &y[1], &yprime[1], &savr[1], &lbw, &ubw, &wk[1], &rewt[1],
	     (U_fp)res, h__, cj, &nnzmx, &wp[ljac], &iwp[ljacj], &iwp[ljaci], 
	    &wp[lplu], &iwp[ljlu], &iwp[lju], &ipar[1], &rpar[1], ires, &nre, 
	    ierr);
    if (*ires < 0) {
	return 0;
    }
    if (*ierr != 0) {
	return 0;
    }
/* ... Save NRE value for user output. */
    ipar[30] += nre;
/* ... Modify pointers into IWP */
    ljlu = lju + neqp1;
    if (ireorder != 0) {
	lperm = ljlu + lenplumx;
	lqperm = lperm + *neq;
	liwk1 = lqperm + *neq;
	llevels = ljlu + nnzmx;
/* assumes that LENPLUFAC >= 2. */
	lmask = llevels + *neq;
    } else {
	lperm = 0;
	lqperm = 0;
	llevels = 0;
	lmask = 0;
	liwk1 = ljlu + lenplumx;
    }
    if (s_cmp(premeth, "ILUTP", (ftnlen)8, (ftnlen)5) == 0) {
	liperm = liwk1 + (*neq << 1);
    } else {
	liperm = liwk1;
    }
/* ... Multiply Jacobian columns by inverse of scaling vector REWT. */
/*     In PSOLILU, the WGHT array equals REWT/SQRT(NEQ), so we must */
/*     be consistent here. */
    if (jscalcol == 1) {
	sqrtn = sqrt((real) (*neq));
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    wk[i__] = sqrtn / rewt[i__];
/* L10: */
	}
	amudia_(neq, &c__0, &wp[ljac], &iwp[ljacj], &iwp[ljaci], &wk[1], &wp[
		ljac], &iwp[ljacj], &iwp[ljaci]);
    }
/* ... Normalize Jacobian rows, if desired. */
    if (isrnorm == 1) {
	roscal_(neq, &c__0, &normtype, &wp[ljac], &iwp[ljacj], &iwp[ljaci], &
		wp[lrownrms], &wp[ljac], &iwp[ljacj], &iwp[ljaci], ierr);
	if (*ierr != 0) {
	    return 0;
	}
    }
/* ... Reorder Jacobian rows and columns, if desired. */
    if (ireorder != 0) {
	djreord_(neq, &neqp1, &nnzmx, premeth, &wp[ljac], &iwp[ljacj], &iwp[
		ljaci], &wp[lplu], &iwp[ljlu], &iwp[lju], &iwp[lperm], &iwp[
		lqperm], &iwp[llevels], &iwp[lmask], &ireorder, (ftnlen)8);
    }
/* ... Write matrix JAC and scaled RES to file if JACOUT .eq. 1. */
    if (jacout == 1) {
	iunit = ipar[29];
	if (isrnorm == 1) {
	    i__1 = *neq;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		savr[i__] *= wp[lrownrms + i__ - 1];
/* L20: */
	    }
	}
	if (ireorder != 0) {
	    dvperm_(neq, &savr[1], &iwp[lperm]);
	}
	s_copy(title, " DDASPK Test Matrix ", (ftnlen)72, (ftnlen)20);
	ifmt = 15;
	prtmt_(neq, neq, &wp[ljac], &iwp[ljacj], &iwp[ljaci], &savr[1], "NN", 
		title, "SPARSKIT", "RUA", &ifmt, &c__3, &iunit, (ftnlen)2, (
		ftnlen)72, (ftnlen)8, (ftnlen)3);
	s_copy(msg, "DJACILU -- Jacobian Matrix written to file.", (ftnlen)80,
		 (ftnlen)43);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	*ierr = 1;
	*ires = -2;
	return 0;
    }
/* ... Compute ILU decomposition. */
    i__1 = *neq + 1;
    djilu_(neq, &i__1, &nnzmx, &wp[ljac], &iwp[ljacj], &iwp[ljaci], &iwp[lju],
	     &wp[lplu], &iwp[ljlu], &wp[lrwk1], &iwp[liwk1], &lenplumx, &
	    tolilut, &lfililut, &permtol, premeth, &iwp[liperm], ierr, (
	    ftnlen)8);
    if (*ierr == -2 || *ierr == -3) {
	*ires = -2;
/* Stop since more storage needed. */
    }
/* ... Save pointers for use in DPSOLILU into IPAR array. */
    ipar[21] = lplu;
    ipar[22] = lju;
    ipar[23] = ljlu;
    ipar[24] = lrownrms;
    ipar[25] = lperm;
    ipar[26] = lqperm;
    return 0;
/* ------------  End of Subroutine DJACILU  ------------------------------ */
} /* djacilu_ */

/* Subroutine */ int djcalc_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *yprime, doublereal *r0, integer *ml, integer *mu, 
	doublereal *r1, doublereal *rewt, S_fp res, doublereal *h__, 
	doublereal *cj, integer *nnzmx, doublereal *jac, integer *ja, integer 
	*ia, doublereal *rcoo, integer *jcoo, integer *icoo, integer *ipar, 
	doublereal *rpar, integer *ires, integer *nre, integer *ierr)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);
    /* Subroutine */ void s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, i1, i2, jj, mba;
    static doublereal del;
    static char msg[80];
    static integer nnz, meb1;
    static doublereal squr;
    static integer mband;
    extern doublereal d1mach_(integer *);
    static integer meband;
    static doublereal delinv;
    extern /* Subroutine */ int coocsr_(integer *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *, integer *), 
	    xerrwd_(char *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    ftnlen);
    static doublereal uround, jacelem;

/* ... Version of 10-6-95 */
/* ... Calculate Jacobian matrix (derivatives with respect to each */
/*     dependent variable of the right-hand side of each rate equation). */
/*     Lower and upper bandwidths are used to select for computation */
/*     only those Jacobian elements that may be nonzero. */
/*     Estimates of Jacobian elements are computed by finite differences. */
/*     The Jacobian is stored in compressed sparse row format. */
/* ... Input arguments: */
/* total number of equations */
/* independent variable t */
/* most recent iterate of solution vector y */
/* most recent iterate of solution vector y' */
/* current residual evaluated at (T,Y,YPRIME) */
/* array of scaling factors for Y and YPRIME */
/* function that evaluates residuals */
/* error flag for RES routine */
/* lower and upper bandwidths */
/* maximum number of nonzeros in Jacobian */
/* current step size */
/* scalar proportional to 1/H */
/* user real workspace */
/* ... Work-array argument: */
/* user integer workspace */
/* ... Output arguments: */
/* work space available to this subroutine */
/* nonzero Jacobian elements */
/* col indices of nonzero Jacobian elements */
/* pointers to beginning of each row in JAC,JA */
/* ... Workspace for temporary storage of Jacobian elements: */
/* nonzero Jacobian elements */
/* col indices of nonzero Jacobian elements */
/* ... Local variables: */
/* row indices of nonzero Jacobian elements */
/* ... Set band parameters. */
    /* Parameter adjustments */
    --ia;
    --rewt;
    --r1;
    --r0;
    --yprime;
    --y;
    --icoo;
    --jcoo;
    --rcoo;
    --ja;
    --jac;
    --ipar;
    --rpar;

    /* Function Body */
    nnz = 1;
    mband = *ml + *mu + 1;
    mba = min(mband,*neq);
    meband = mband + *ml;
    meb1 = meband - 1;
/* ... Set the machine unit roundoff UROUND and SQRT(UROUND), used to */
/* ... set increments in the difference quotient procedure. */
    uround = d1mach_(&c__4);
    squr = sqrt(uround);
/* ... Initial error flags. */
    *ierr = 0;
    *ires = 0;
/* ... Make MBA calls to RES to approximate the Jacobian. */
/* ... Here, R0(1),...,R0(neq) contains the base RES value, and */
/*     R1(1),...,R1(NEQ) contains the perturbed values of RES. */
    i__1 = mba;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *neq;
	i__3 = mband;
	for (jj = j; i__3 < 0 ? jj >= i__2 : jj <= i__2; jj += i__3) {
	    jac[jj] = y[jj];
	    jac[jj + *neq] = yprime[jj];
/* Computing MAX */
	    d__4 = (d__1 = y[jj], abs(d__1)), d__5 = (d__2 = *h__ * yprime[jj]
		    , abs(d__2)), d__4 = max(d__4,d__5), d__5 = (d__3 = 1.f / 
		    rewt[jj], abs(d__3));
	    del = squr * max(d__4,d__5);
	    d__1 = *h__ * yprime[jj];
	    del = d_sign(&del, &d__1);
	    del = y[jj] + del - y[jj];
	    y[jj] += del;
	    yprime[jj] += *cj * del;
/* L10: */
	}
	(*res)(t, &y[1], &yprime[1], cj, &r1[1], ires, &rpar[1], &ipar[1]);
	if (*ires < 0) {
	    return 0;
	}
	++(*nre);
	i__3 = *neq;
	i__2 = mband;
	for (jj = j; i__2 < 0 ? jj >= i__3 : jj <= i__3; jj += i__2) {
	    y[jj] = jac[jj];
	    yprime[jj] = jac[jj + *neq];
/* Computing MAX */
	    d__4 = (d__1 = y[jj], abs(d__1)), d__5 = (d__2 = *h__ * yprime[jj]
		    , abs(d__2)), d__4 = max(d__4,d__5), d__5 = (d__3 = 1.f / 
		    rewt[jj], abs(d__3));
	    del = squr * max(d__4,d__5);
	    d__1 = *h__ * yprime[jj];
	    del = d_sign(&del, &d__1);
	    del = y[jj] + del - y[jj];
	    delinv = 1.f / del;
/* Computing MAX */
	    i__4 = 1, i__5 = jj - *mu;
	    i1 = max(i__4,i__5);
/* Computing MIN */
	    i__4 = *neq, i__5 = jj + *ml;
	    i2 = min(i__4,i__5);
	    i__4 = i2;
	    for (i__ = i1; i__ <= i__4; ++i__) {
/* ... Calculate possibly nonzero Jacobian elements for this variable, */
/*     and store nonzero elements in coordinate format. */
		jacelem = (r1[i__] - r0[i__]) * delinv;
		if (jacelem != 0.f) {
		    if (nnz > *nnzmx) {
			s_copy(msg, "DJCALC -- More storage needed for Jacob"
				"ian.", (ftnlen)80, (ftnlen)43);
			xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &
				c__0, &c__0, (doublereal*)&c_b1235, (
				doublereal*)&c_b1235, (ftnlen)80);
			s_copy(msg, "DJCALC -- Increase LENPFAC.", (ftnlen)80,
				 (ftnlen)27);
			xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &
				c__0, &c__0, (doublereal*)&c_b1235, (
				doublereal*)&c_b1235, (ftnlen)80);
			s_copy(msg, "DJCALC -- Storage exceeded at (I,J) = ("
				"I1,I2)", (ftnlen)80, (ftnlen)45);
			xerrwd_(msg, &c__80, &c__0, &c__0, &c__2, &i__, &jj, &
				c__0, (doublereal*)&c_b1235, (doublereal*)&
				c_b1235, (ftnlen)80);
			*ierr = 1;
			*ires = -2;
			return 0;
		    }
		    rcoo[nnz] = jacelem;
		    jcoo[nnz] = jj;
		    icoo[nnz] = i__;
		    ++nnz;
		}
/* L20: */
	    }
/* L30: */
	}
/* L40: */
    }
    --nnz;

/* ... Convert Jacobian from coordinate to compressed sparse row format. */
    coocsr_(neq, &nnz, &rcoo[1], &icoo[1], &jcoo[1], &jac[1], &ja[1], &ia[1]);
    return 0;
/* ------------  End of Subroutine DJCALC  ------------------------------- */
} /* djcalc_ */

/* Subroutine */ int dpsolilu_(integer *neq, doublereal *t, doublereal *y, 
	doublereal *yprime, doublereal *r0, doublereal *wk, doublereal *cj, 
	doublereal *wght, doublereal *wp, integer *iwp, doublereal *bl, 
	doublereal *eplin, integer *ierr, doublereal *rpar, integer *ipar)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer jscalcol, ireorder, ipremeth, lrownrms, i__, lju, ljlu, 
	    lplu, lperm;
    extern /* Subroutine */ int lusol_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), dvperm_(integer *, 
	    doublereal *, integer *);
    static integer lqperm, isrnorm;

/* ... Version of 12-5-00 */
/* ... Solve the linear system P*x=c, using elements of P loaded into */
/*     arrays WP and IWP. */

/* ... Input arguments: */
/* total number of equations */
/* independent variable t */
/* most recent iterate of solution vector y */
/* most recent iterate of solution vector y' */
/* function value G(T,Y,YPRIME) */
/* scaling array for Y and YPRIME */
/* scalar proportional to 1/H */
/* not used */
/* matrix elements of ILU */
/* array indices for elements of ILU */
/* user workspace */
/* ... Work-array argument: */
/* user workspace */
/* ... In-out argument: */
/* work space available to this subroutine */
/* ... Output arguments: */
/* on input, c of P*x=c; on output, x */
/* ... Local variables: */
/* error flag (0 only possible value here) */
/* ... Load IPREMETH, IREORDER and ISRNORM values from IPAR. */
    /* Parameter adjustments */
    --bl;
    --wght;
    --wk;
    --r0;
    --yprime;
    --y;
    --wp;
    --iwp;
    --rpar;
    --ipar;

    /* Function Body */
    ipremeth = ipar[5];
    ireorder = ipar[7];
    isrnorm = ipar[8];
    jscalcol = ipar[11];
/* ... Load pointers into WP and iWP arrays. */
    lplu = ipar[21];
    lju = ipar[22];
    ljlu = ipar[23];
    lrownrms = ipar[24];
    lperm = ipar[25];
    lqperm = ipar[26];
/* ... Scale c by multiplying by row-normalization factors, if used. */
    if (isrnorm == 1) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    bl[i__] *= wp[lrownrms + i__ - 1];
/* L10: */
	}
    }
/* ... Solve P*x=c for a preconditioner stored as a sparse matrix in */
/*     compressed sparse row format. */
/*     If rows and columns of P were reordered (permuted), permute c, */
/*     then use inverse permutation on x. */
    if (ipremeth == 1 || ipremeth == 2) {
	if (ireorder == 1) {
	    dvperm_(neq, &bl[1], &iwp[lperm]);
	}
	lusol_(neq, &bl[1], &wk[1], &wp[lplu], &iwp[ljlu], &iwp[lju]);
	if (ireorder == 1) {
	    dvperm_(neq, &wk[1], &iwp[lqperm]);
	}
    }
/* ... Unscale x by dividing by column scaling vector WGHT. */
    if (jscalcol == 1) {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	    bl[i__] = wk[i__] / wght[i__];
	}
    } else {
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	    bl[i__] = wk[i__];
	}
    }
    *ierr = 0;
    return 0;
/* ------------  End of Subroutine DPSOLILU  ----------------------------- */
} /* dpsolilu_ */

/* Subroutine */ int djilu_(integer *neq, integer *neqp1, integer *nnzmx, 
	doublereal *jac, integer *ja, integer *ia, integer *ju, doublereal *
	plu, integer *jlu, doublereal *rwk1, integer *iwk1, integer *lenplumx,
	 doublereal *tolilut, integer *lfililut, doublereal *permtol, char *
	premeth, integer *iperm, integer *ierr, ftnlen premeth_len)
{
    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ void s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static char msg[80];
    extern /* Subroutine */ int ilut_(integer *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, integer *, integer *);
    static logical error;
    extern /* Subroutine */ int ilutp_(integer *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, integer *, integer *, doublereal *, 
	    integer *, integer *, integer *), xerrwd_(char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, ftnlen);

/* ... Version of 12-12-00 */
/* ... Compute ILU decomposition of Jacobian and return it in any one */
/*     of the storage formats. */
/* ... Input arguments: */
/* total number of equations */
/* NEQ + 1 */
/* maximum number of nonzeros in Jacobian */
/* nonzero Jacobian elements */
/* col indices of nonzero Jacobian elements */
/* pointers to beginning of each row in jac,ja */
/* ... Output arguments: */
/* matrix elements of ILU */
/* sizes and array indices for elements of ILU */
/* matrix PLU,JLU */
/* pointer to beginning of each row of U in */
/* ... Local variables: */
/* error flag */
    /* Parameter adjustments */
    --iperm;
    --iwk1;
    --rwk1;
    --ju;
    --ia;
    --ja;
    --jac;
    --jlu;
    --plu;

    /* Function Body */
    error = FALSE_;
    if (s_cmp(premeth, "ILUT", (ftnlen)8, (ftnlen)4) == 0) {
/* ... Use incomplete factorization routine ILUT from SparsKit. */
	ilut_(neq, &jac[1], &ja[1], &ia[1], lfililut, tolilut, &plu[1], &jlu[
		1], &ju[1], lenplumx, &rwk1[1], &iwk1[1], ierr);
	if (*ierr != 0) {
	    s_copy(msg, "DJILU -- Error return from ILUT: IERR = (I1)", (
		    ftnlen)80, (ftnlen)44);
	    xerrwd_(msg, &c__80, &c__0, &c__0, &c__1, ierr, &c__0, &c__0, (
		    doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	    error = TRUE_;
	}
    } else if (s_cmp(premeth, "ILUTP", (ftnlen)8, (ftnlen)5) == 0) {
/* ... Use incomplete factorization routine ILUTP from SparsKit. */
	ilutp_(neq, &jac[1], &ja[1], &ia[1], lfililut, tolilut, permtol, neq, 
		&plu[1], &jlu[1], &ju[1], lenplumx, &rwk1[1], &iwk1[1], &
		iperm[1], ierr);
	if (*ierr != 0) {
	    s_copy(msg, "DJILU -- Error return from ILUTP: IERR = (I1)", (
		    ftnlen)80, (ftnlen)45);
	    xerrwd_(msg, &c__80, &c__0, &c__0, &c__1, ierr, &c__0, &c__0, (
		    doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	    error = TRUE_;
	}
/* ... Put in other options here for incomplete factorizations. */
    }
    if (error) {
	s_copy(msg, "DJILU -- IERR .NE. 0 means one of the following has occ"
		"urred:", (ftnlen)80, (ftnlen)61);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    IERR >  0   --> Zero pivot encountered at step numb"
		"er IERR.", (ftnlen)80, (ftnlen)63);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    IERR = -1   --> Error. input matrix may be wrong.", (
		ftnlen)80, (ftnlen)53);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "                     (The elimination process has gener"
		"ated a", (ftnlen)80, (ftnlen)61);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "                     row in L or U with length > NEQ.)", 
		(ftnlen)80, (ftnlen)54);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    IERR = -2   --> Matrix L overflows.", (ftnlen)80, (
		ftnlen)39);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    IERR = -3   --> Matrix U overflows.", (ftnlen)80, (
		ftnlen)39);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    IERR = -4   --> Illegal value for LFILILUT.", (
		ftnlen)80, (ftnlen)47);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    IERR = -5   --> Zero row encountered.", (ftnlen)80, (
		ftnlen)41);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    ", (ftnlen)80, (ftnlen)4);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    For IERR = -2 or -3, increase the value of LENPLUFA"
		"C or", (ftnlen)80, (ftnlen)59);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    decrease the value of LFILILUT if LENPLUFAC cannot "
		"be", (ftnlen)80, (ftnlen)57);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
	s_copy(msg, "    increased.", (ftnlen)80, (ftnlen)14);
	xerrwd_(msg, &c__80, &c__0, &c__0, &c__0, &c__0, &c__0, &c__0, (
		doublereal*)&c_b1235, (doublereal*)&c_b1235, (ftnlen)80);
    }
    return 0;
/* ------------  End of Subroutine DJILU  -------------------------------- */
} /* djilu_ */

/* Subroutine */ int djreord_(integer *neq, integer *neqp1, integer *nnzmx, 
	char *premeth, doublereal *jac, integer *ja, integer *ia, doublereal *
	awk, integer *jwk, integer *iwk, integer *perm, integer *qperm, 
	integer *levels, integer *mask, integer *ireorder, ftnlen premeth_len)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int bfs_(integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *), atob_(integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *);
    static integer nlev;
    extern /* Subroutine */ int dperm_(integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, integer 
	    *, integer *);
    static integer nfirst;
    extern /* Subroutine */ int rversp_(integer *, integer *);
    static integer maskval;

/* ... Version of 10-6-95 */
/* ... If desired, reorder the Jacobian matrix. */
/* ... Input arguments: */
/* total number of equations */
/* NEQ + 1 */
/* maximum number of nonzeroes in Jacobian */
/* nonzero Jacobian elements */
/* column indices of nonzero Jacobian elements */
/* indices of 1st nonzero element in each row */
/* ... Work-array arguments: */
/* used in reordering the rows and columns of */
/* the Jacobian matrix. */
/* Integer array containing the permutation */
/* permutation in array perm. */
/* Integer array holding the inverse of the */
/* subroutine.   See subroutine BFS for */
/* more details. */
/* Work array used by the bfs reordering */
/* subroutine.  See BFS subroutine. */
/* Work array used by the BFS reordering */
/* of the Jacobian matrix is desired. */
/* = 1 means a reverse Cuthill-McKee */
/*     reordering of the rows and columns */
/*     of the Jacobian is done. */
/* = 0 means no reordering. */
/* ... Local variables: */
/* Flag used to determine if a reordering */
/* See subroutine BFS for more details. */
/* Number of levels in levels array. */
/* Scalar used with MASK. */
    /* Parameter adjustments */
    --mask;
    --levels;
    --qperm;
    --perm;
    --iwk;
    --ia;
    --jwk;
    --awk;
    --ja;
    --jac;

    /* Function Body */
    if (*ireorder == 1) {
/* ... Copy JAC, JA, and IA to AWK, JWK, and IWK. */
	atob_(neq, &jac[1], &ja[1], &ia[1], &awk[1], &jwk[1], &iwk[1]);
/* ... Perform a Cuthill-McKee reordering of the Jacobian. */
	nfirst = 1;
	perm[1] = 0;
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    mask[i__] = 1;
	}
	maskval = 1;
	qperm[1] = 1;
	bfs_(neq, &jwk[1], &iwk[1], &nfirst, &perm[1], &mask[1], &maskval, &
		qperm[1], &levels[1], &nlev);
/* ... Reverse the permutation to obtain the reverse Cuthill-McKee */
/*     reordering. */
	rversp_(neq, &qperm[1]);
/* ... Calculate the inverse of QPERM and put it in PERM. */
	i__1 = *neq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    perm[qperm[i__]] = i__;
	}
/* ... Permute rows and columns of Jacobian using PERM. */
	dperm_(neq, &awk[1], &jwk[1], &iwk[1], &jac[1], &ja[1], &ia[1], &perm[
		1], &perm[1], &c__1);
/* ... End of If block */
    }
    return 0;
/* ------------  End of Subroutine DJREORD  ------------------------------ */
} /* djreord_ */

/* Subroutine */ int dgefa_(doublereal *a, integer *lda, integer *n, integer *
	ipvt, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer j, k, l;
    static doublereal t;
    static integer kp1, nm1;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), daxpy_(integer *, doublereal *, doublereal *, integer 
	    *, doublereal *, integer *);
    extern integer idamax_(integer *, doublereal *, integer *);


/*     dgefa factors a double precision matrix by gaussian elimination. */

/*     dgefa is usually called by dgeco, but it can be called */
/*     directly with a saving in time if  rcond  is not needed. */
/*     (time for dgeco) = (1 + 9/n)*(time for dgefa) . */

/*     on entry */

/*        a       double precision(lda, n) */
/*                the matrix to be factored. */

/*        lda     integer */
/*                the leading dimension of the array  a . */

/*        n       integer */
/*                the order of the matrix  a . */

/*     on return */

/*        a       an upper triangular matrix and the multipliers */
/*                which were used to obtain it. */
/*                the factorization can be written  a = l*u  where */
/*                l  is a product of permutation and unit lower */
/*                triangular matrices and  u  is upper triangular. */

/*        ipvt    integer(n) */
/*                an integer vector of pivot indices. */

/*        info    integer */
/*                = 0  normal value. */
/*                = k  if  u(k,k) .eq. 0.0 .  this is not an error */
/*                     condition for this subroutine, but it does */
/*                     indicate that dgesl or dgedi will divide by zero */
/*                     if called.  use  rcond  in dgeco for a reliable */
/*                     indication of singularity. */

/*     linpack. this version dated 08/14/78 . */
/*     cleve moler, university of new mexico, argonne national lab. */

/*     subroutines and functions */

/*     blas daxpy,dscal,idamax */

/*     internal variables */



/*     gaussian elimination with partial pivoting */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ipvt;

    /* Function Body */
    *info = 0;
    nm1 = *n - 1;
    if (nm1 < 1) {
	goto L70;
    }
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
	kp1 = k + 1;

/*        find l = pivot index */

	i__2 = *n - k + 1;
	l = idamax_(&i__2, &a[k + k * a_dim1], &c__1) + k - 1;
	ipvt[k] = l;

/*        zero pivot implies this column already triangularized */

	if (a[l + k * a_dim1] == 0.) {
	    goto L40;
	}

/*           interchange if necessary */

	if (l == k) {
	    goto L10;
	}
	t = a[l + k * a_dim1];
	a[l + k * a_dim1] = a[k + k * a_dim1];
	a[k + k * a_dim1] = t;
L10:

/*           compute multipliers */

	t = -1. / a[k + k * a_dim1];
	i__2 = *n - k;
	dscal_(&i__2, &t, &a[k + 1 + k * a_dim1], &c__1);

/*           row elimination with column indexing */

	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    t = a[l + j * a_dim1];
	    if (l == k) {
		goto L20;
	    }
	    a[l + j * a_dim1] = a[k + j * a_dim1];
	    a[k + j * a_dim1] = t;
L20:
	    i__3 = *n - k;
	    daxpy_(&i__3, &t, &a[k + 1 + k * a_dim1], &c__1, &a[k + 1 + j * 
		    a_dim1], &c__1);
/* L30: */
	}
	goto L50;
L40:
	*info = k;
L50:
/* L60: */
	;
    }
L70:
    ipvt[*n] = *n;
    if (a[*n + *n * a_dim1] == 0.) {
	*info = *n;
    }
    return 0;
} /* dgefa_ */

/* Subroutine */ int dgesl_(doublereal *a, integer *lda, integer *n, integer *
	ipvt, doublereal *b, integer *job)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer k, l;
    static doublereal t;
    static integer kb, nm1;
    extern doublereal ddot_(integer *, doublereal *, integer *, doublereal *, 
	    integer *);
    extern /* Subroutine */ int daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);


/*     dgesl solves the double precision system */
/*     a * x = b  or  trans(a) * x = b */
/*     using the factors computed by dgeco or dgefa. */

/*     on entry */

/*        a       double precision(lda, n) */
/*                the output from dgeco or dgefa. */

/*        lda     integer */
/*                the leading dimension of the array  a . */

/*        n       integer */
/*                the order of the matrix  a . */

/*        ipvt    integer(n) */
/*                the pivot vector from dgeco or dgefa. */

/*        b       double precision(n) */
/*                the right hand side vector. */

/*        job     integer */
/*                = 0         to solve  a*x = b , */
/*                = nonzero   to solve  trans(a)*x = b  where */
/*                            trans(a)  is the transpose. */

/*     on return */

/*        b       the solution vector  x . */

/*     error condition */

/*        a division by zero will occur if the input factor contains a */
/*        zero on the diagonal.  technically this indicates singularity */
/*        but it is often caused by improper arguments or improper */
/*        setting of lda .  it will not occur if the subroutines are */
/*        called correctly and if dgeco has set rcond .gt. 0.0 */
/*        or dgefa has set info .eq. 0 . */

/*     to compute  inverse(a) * c  where  c  is a matrix */
/*     with  p  columns */
/*           call dgeco(a,lda,n,ipvt,rcond,z) */
/*           if (rcond is too small) go to ... */
/*           do 10 j = 1, p */
/*              call dgesl(a,lda,n,ipvt,c(1,j),0) */
/*        10 continue */

/*     linpack. this version dated 08/14/78 . */
/*     cleve moler, university of new mexico, argonne national lab. */

/*     subroutines and functions */

/*     blas daxpy,ddot */

/*     internal variables */


    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ipvt;
    --b;

    /* Function Body */
    nm1 = *n - 1;
    if (*job != 0) {
	goto L50;
    }

/*        job = 0 , solve  a * x = b */
/*        first solve  l*y = b */

    if (nm1 < 1) {
	goto L30;
    }
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
	l = ipvt[k];
	t = b[l];
	if (l == k) {
	    goto L10;
	}
	b[l] = b[k];
	b[k] = t;
L10:
	i__2 = *n - k;
	daxpy_(&i__2, &t, &a[k + 1 + k * a_dim1], &c__1, &b[k + 1], &c__1);
/* L20: */
    }
L30:

/*        now solve  u*x = y */

    i__1 = *n;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n + 1 - kb;
	b[k] /= a[k + k * a_dim1];
	t = -b[k];
	i__2 = k - 1;
	daxpy_(&i__2, &t, &a[k * a_dim1 + 1], &c__1, &b[1], &c__1);
/* L40: */
    }
    goto L100;
L50:

/*        job = nonzero, solve  trans(a) * x = b */
/*        first solve  trans(u)*y = b */

    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	i__2 = k - 1;
	t = ddot_(&i__2, &a[k * a_dim1 + 1], &c__1, &b[1], &c__1);
	b[k] = (b[k] - t) / a[k + k * a_dim1];
/* L60: */
    }

/*        now solve trans(l)*x = y */

    if (nm1 < 1) {
	goto L90;
    }
    i__1 = nm1;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n - kb;
	i__2 = *n - k;
	b[k] += ddot_(&i__2, &a[k + 1 + k * a_dim1], &c__1, &b[k + 1], &c__1);
	l = ipvt[k];
	if (l == k) {
	    goto L70;
	}
	t = b[l];
	b[l] = b[k];
	b[k] = t;
L70:
/* L80: */
	;
    }
L90:
L100:
    return 0;
} /* dgesl_ */

/* Subroutine */ int dgbfa_(doublereal *abd, integer *lda, integer *n, 
	integer *ml, integer *mu, integer *ipvt, integer *info)
{
    /* System generated locals */
    integer abd_dim1, abd_offset, i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal t;
    static integer i0, j0, j1, lm, mm, ju, jz, kp1, nm1;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), daxpy_(integer *, doublereal *, doublereal *, integer 
	    *, doublereal *, integer *);
    extern integer idamax_(integer *, doublereal *, integer *);


/*     dgbfa factors a double precision band matrix by elimination. */

/*     dgbfa is usually called by dgbco, but it can be called */
/*     directly with a saving in time if  rcond  is not needed. */

/*     on entry */

/*        abd     double precision(lda, n) */
/*                contains the matrix in band storage.  the columns */
/*                of the matrix are stored in the columns of  abd  and */
/*                the diagonals of the matrix are stored in rows */
/*                ml+1 through 2*ml+mu+1 of  abd . */
/*                see the comments below for details. */

/*        lda     integer */
/*                the leading dimension of the array  abd . */
/*                lda must be .ge. 2*ml + mu + 1 . */

/*        n       integer */
/*                the order of the original matrix. */

/*        ml      integer */
/*                number of diagonals below the main diagonal. */
/*                0 .le. ml .lt. n . */

/*        mu      integer */
/*                number of diagonals above the main diagonal. */
/*                0 .le. mu .lt. n . */
/*                more efficient if  ml .le. mu . */
/*     on return */

/*        abd     an upper triangular matrix in band storage and */
/*                the multipliers which were used to obtain it. */
/*                the factorization can be written  a = l*u  where */
/*                l  is a product of permutation and unit lower */
/*                triangular matrices and  u  is upper triangular. */

/*        ipvt    integer(n) */
/*                an integer vector of pivot indices. */

/*        info    integer */
/*                = 0  normal value. */
/*                = k  if  u(k,k) .eq. 0.0 .  this is not an error */
/*                     condition for this subroutine, but it does */
/*                     indicate that dgbsl will divide by zero if */
/*                     called.  use  rcond  in dgbco for a reliable */
/*                     indication of singularity. */

/*     band storage */

/*           if  a  is a band matrix, the following program segment */
/*           will set up the input. */

/*                   ml = (band width below the diagonal) */
/*                   mu = (band width above the diagonal) */
/*                   m = ml + mu + 1 */
/*                   do 20 j = 1, n */
/*                      i1 = max0(1, j-mu) */
/*                      i2 = min0(n, j+ml) */
/*                      do 10 i = i1, i2 */
/*                         k = i - j + m */
/*                         abd(k,j) = a(i,j) */
/*                10    continue */
/*                20 continue */

/*           this uses rows  ml+1  through  2*ml+mu+1  of  abd . */
/*           in addition, the first  ml  rows in  abd  are used for */
/*           elements generated during the triangularization. */
/*           the total number of rows needed in  abd  is  2*ml+mu+1 . */
/*           the  ml+mu by ml+mu  upper left triangle and the */
/*           ml by ml  lower right triangle are not referenced. */

/*     linpack. this version dated 08/14/78 . */
/*     cleve moler, university of new mexico, argonne national lab. */

/*     subroutines and functions */

/*     blas daxpy,dscal,idamax */
/*     fortran max0,min0 */

/*     internal variables */



    /* Parameter adjustments */
    abd_dim1 = *lda;
    abd_offset = 1 + abd_dim1;
    abd -= abd_offset;
    --ipvt;

    /* Function Body */
    m = *ml + *mu + 1;
    *info = 0;

/*     zero initial fill-in columns */

    j0 = *mu + 2;
    j1 = min(*n,m) - 1;
    if (j1 < j0) {
	goto L30;
    }
    i__1 = j1;
    for (jz = j0; jz <= i__1; ++jz) {
	i0 = m + 1 - jz;
	i__2 = *ml;
	for (i__ = i0; i__ <= i__2; ++i__) {
	    abd[i__ + jz * abd_dim1] = 0.;
/* L10: */
	}
/* L20: */
    }
L30:
    jz = j1;
    ju = 0;

/*     gaussian elimination with partial pivoting */

    nm1 = *n - 1;
    if (nm1 < 1) {
	goto L130;
    }
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
	kp1 = k + 1;

/*        zero next fill-in column */

	++jz;
	if (jz > *n) {
	    goto L50;
	}
	if (*ml < 1) {
	    goto L50;
	}
	i__2 = *ml;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    abd[i__ + jz * abd_dim1] = 0.;
/* L40: */
	}
L50:

/*        find l = pivot index */

/* Computing MIN */
	i__2 = *ml, i__3 = *n - k;
	lm = min(i__2,i__3);
	i__2 = lm + 1;
	l = idamax_(&i__2, &abd[m + k * abd_dim1], &c__1) + m - 1;
	ipvt[k] = l + k - m;

/*        zero pivot implies this column already triangularized */

	if (abd[l + k * abd_dim1] == 0.) {
	    goto L100;
	}

/*           interchange if necessary */

	if (l == m) {
	    goto L60;
	}
	t = abd[l + k * abd_dim1];
	abd[l + k * abd_dim1] = abd[m + k * abd_dim1];
	abd[m + k * abd_dim1] = t;
L60:

/*           compute multipliers */

	t = -1. / abd[m + k * abd_dim1];
	dscal_(&lm, &t, &abd[m + 1 + k * abd_dim1], &c__1);

/*           row elimination with column indexing */

/* Computing MIN */
/* Computing MAX */
	i__3 = ju, i__4 = *mu + ipvt[k];
	i__2 = max(i__3,i__4);
	ju = min(i__2,*n);
	mm = m;
	if (ju < kp1) {
	    goto L90;
	}
	i__2 = ju;
	for (j = kp1; j <= i__2; ++j) {
	    --l;
	    --mm;
	    t = abd[l + j * abd_dim1];
	    if (l == mm) {
		goto L70;
	    }
	    abd[l + j * abd_dim1] = abd[mm + j * abd_dim1];
	    abd[mm + j * abd_dim1] = t;
L70:
	    daxpy_(&lm, &t, &abd[m + 1 + k * abd_dim1], &c__1, &abd[mm + 1 + 
		    j * abd_dim1], &c__1);
/* L80: */
	}
L90:
	goto L110;
L100:
	*info = k;
L110:
/* L120: */
	;
    }
L130:
    ipvt[*n] = *n;
    if (abd[m + *n * abd_dim1] == 0.) {
	*info = *n;
    }
    return 0;
} /* dgbfa_ */

/* Subroutine */ int dgbsl_(doublereal *abd, integer *lda, integer *n, 
	integer *ml, integer *mu, integer *ipvt, doublereal *b, integer *job)
{
    /* System generated locals */
    integer abd_dim1, abd_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer k, l, m;
    static doublereal t;
    static integer kb, la, lb, lm, nm1;
    extern doublereal ddot_(integer *, doublereal *, integer *, doublereal *, 
	    integer *);
    extern /* Subroutine */ int daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);


/*     dgbsl solves the double precision band system */
/*     a * x = b  or  trans(a) * x = b */
/*     using the factors computed by dgbco or dgbfa. */

/*     on entry */

/*        abd     double precision(lda, n) */
/*                the output from dgbco or dgbfa. */

/*        lda     integer */
/*                the leading dimension of the array  abd . */

/*        n       integer */
/*                the order of the original matrix. */

/*        ml      integer */
/*                number of diagonals below the main diagonal. */

/*        mu      integer */
/*                number of diagonals above the main diagonal. */

/*        ipvt    integer(n) */
/*                the pivot vector from dgbco or dgbfa. */

/*        b       double precision(n) */
/*                the right hand side vector. */

/*        job     integer */
/*                = 0         to solve  a*x = b , */
/*                = nonzero   to solve  trans(a)*x = b , where */
/*                            trans(a)  is the transpose. */

/*     on return */

/*        b       the solution vector  x . */

/*     error condition */

/*        a division by zero will occur if the input factor contains a */
/*        zero on the diagonal.  technically this indicates singularity */
/*        but it is often caused by improper arguments or improper */
/*        setting of lda .  it will not occur if the subroutines are */
/*        called correctly and if dgbco has set rcond .gt. 0.0 */
/*        or dgbfa has set info .eq. 0 . */

/*     to compute  inverse(a) * c  where  c  is a matrix */
/*     with  p  columns */
/*           call dgbco(abd,lda,n,ml,mu,ipvt,rcond,z) */
/*           if (rcond is too small) go to ... */
/*           do 10 j = 1, p */
/*              call dgbsl(abd,lda,n,ml,mu,ipvt,c(1,j),0) */
/*        10 continue */

/*     linpack. this version dated 08/14/78 . */
/*     cleve moler, university of new mexico, argonne national lab. */

/*     subroutines and functions */

/*     blas daxpy,ddot */
/*     fortran min0 */

/*     internal variables */


    /* Parameter adjustments */
    abd_dim1 = *lda;
    abd_offset = 1 + abd_dim1;
    abd -= abd_offset;
    --ipvt;
    --b;

    /* Function Body */
    m = *mu + *ml + 1;
    nm1 = *n - 1;
    if (*job != 0) {
	goto L50;
    }

/*        job = 0 , solve  a * x = b */
/*        first solve l*y = b */

    if (*ml == 0) {
	goto L30;
    }
    if (nm1 < 1) {
	goto L30;
    }
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
/* Computing MIN */
	i__2 = *ml, i__3 = *n - k;
	lm = min(i__2,i__3);
	l = ipvt[k];
	t = b[l];
	if (l == k) {
	    goto L10;
	}
	b[l] = b[k];
	b[k] = t;
L10:
	daxpy_(&lm, &t, &abd[m + 1 + k * abd_dim1], &c__1, &b[k + 1], &c__1);
/* L20: */
    }
L30:

/*        now solve  u*x = y */

    i__1 = *n;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n + 1 - kb;
	b[k] /= abd[m + k * abd_dim1];
	lm = min(k,m) - 1;
	la = m - lm;
	lb = k - lm;
	t = -b[k];
	daxpy_(&lm, &t, &abd[la + k * abd_dim1], &c__1, &b[lb], &c__1);
/* L40: */
    }
    goto L100;
L50:

/*        job = nonzero, solve  trans(a) * x = b */
/*        first solve  trans(u)*y = b */

    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	lm = min(k,m) - 1;
	la = m - lm;
	lb = k - lm;
	t = ddot_(&lm, &abd[la + k * abd_dim1], &c__1, &b[lb], &c__1);
	b[k] = (b[k] - t) / abd[m + k * abd_dim1];
/* L60: */
    }

/*        now solve trans(l)*x = y */

    if (*ml == 0) {
	goto L90;
    }
    if (nm1 < 1) {
	goto L90;
    }
    i__1 = nm1;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n - kb;
/* Computing MIN */
	i__2 = *ml, i__3 = *n - k;
	lm = min(i__2,i__3);
	b[k] += ddot_(&lm, &abd[m + 1 + k * abd_dim1], &c__1, &b[k + 1], &
		c__1);
	l = ipvt[k];
	if (l == k) {
	    goto L70;
	}
	t = b[l];
	b[l] = b[k];
	b[k] = t;
L70:
/* L80: */
	;
    }
L90:
L100:
    return 0;
} /* dgbsl_ */

/* Subroutine */ int daxpy_(integer *n, doublereal *da, doublereal *dx, 
	integer *incx, doublereal *dy, integer *incy)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, m, ix, iy, mp1;


/*     constant times a vector plus a vector. */
/*     uses unrolled loop for increments equal to one. */
/*     jack dongarra, linpack, 3/11/78. */


    /* Parameter adjustments */
    --dy;
    --dx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if (*da == 0.) {
	return 0;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*        code for unequal increments or equal increments */
/*          not equal to 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dy[iy] += *da * dx[ix];
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return 0;

/*        code for both increments equal to 1 */


/*        clean-up loop */

L20:
    m = *n % 4;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dy[i__] += *da * dx[i__];
/* L30: */
    }
    if (*n < 4) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i__ = mp1; i__ <= i__1; i__ += 4) {
	dy[i__] += *da * dx[i__];
	dy[i__ + 1] += *da * dx[i__ + 1];
	dy[i__ + 2] += *da * dx[i__ + 2];
	dy[i__ + 3] += *da * dx[i__ + 3];
/* L50: */
    }
    return 0;
} /* daxpy_ */

/* Subroutine */ int dcopy_(integer *n, doublereal *sx, integer *incx, 
	doublereal *sy, integer *incy)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, m, ix, iy, mp1;


/*     copies a vector, x, to a vector, y. */
/*     uses unrolled loops for increments equal to 1. */
/*     jack dongarra, linpack, 3/11/78. */


    /* Parameter adjustments */
    --sy;
    --sx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*        code for unequal increments or equal increments */
/*          not equal to 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sy[iy] = sx[ix];
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return 0;

/*        code for both increments equal to 1 */


/*        clean-up loop */

L20:
    m = *n % 7;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sy[i__] = sx[i__];
/* L30: */
    }
    if (*n < 7) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i__ = mp1; i__ <= i__1; i__ += 7) {
	sy[i__] = sx[i__];
	sy[i__ + 1] = sx[i__ + 1];
	sy[i__ + 2] = sx[i__ + 2];
	sy[i__ + 3] = sx[i__ + 3];
	sy[i__ + 4] = sx[i__ + 4];
	sy[i__ + 5] = sx[i__ + 5];
	sy[i__ + 6] = sx[i__ + 6];
/* L50: */
    }
    return 0;
} /* dcopy_ */

/* Subroutine */ int dscal_(integer *n, doublereal *da, doublereal *dx, 
	integer *incx)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, m, mp1, nincx;


/*     scales a vector by a constant. */
/*     uses unrolled loop for increment equal to one. */
/*     jack dongarra, linpack, 3/11/78. */


    /* Parameter adjustments */
    --dx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if (*incx == 1) {
	goto L20;
    }

/*        code for increment not equal to 1 */

    nincx = *n * *incx;
    i__1 = nincx;
    i__2 = *incx;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	dx[i__] = *da * dx[i__];
/* L10: */
    }
    return 0;

/*        code for increment equal to 1 */


/*        clean-up loop */

L20:
    m = *n % 5;
    if (m == 0) {
	goto L40;
    }
    i__2 = m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	dx[i__] = *da * dx[i__];
/* L30: */
    }
    if (*n < 5) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__2 = *n;
    for (i__ = mp1; i__ <= i__2; i__ += 5) {
	dx[i__] = *da * dx[i__];
	dx[i__ + 1] = *da * dx[i__ + 1];
	dx[i__ + 2] = *da * dx[i__ + 2];
	dx[i__ + 3] = *da * dx[i__ + 3];
	dx[i__ + 4] = *da * dx[i__ + 4];
/* L50: */
    }
    return 0;
} /* dscal_ */

doublereal ddot_(integer *n, doublereal *dx, integer *incx, doublereal *dy, 
	integer *incy)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, m, ix, iy, mp1;
    static doublereal dtemp;


/*     forms the dot product of two vectors. */
/*     uses unrolled loop for increments equal to one. */
/*     jack dongarra, linpack, 3/11/78. */


    /* Parameter adjustments */
    --dy;
    --dx;

    /* Function Body */
    ret_val = 0.;
    dtemp = 0.;
    if (*n <= 0) {
	return ret_val;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*        code for unequal increments or equal increments */
/*          not equal to 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dtemp += dx[ix] * dy[iy];
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    ret_val = dtemp;
    return ret_val;

/*        code for both increments equal to 1 */


/*        clean-up loop */

L20:
    m = *n % 5;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dtemp += dx[i__] * dy[i__];
/* L30: */
    }
    if (*n < 5) {
	goto L60;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i__ = mp1; i__ <= i__1; i__ += 5) {
	dtemp = dtemp + dx[i__] * dy[i__] + dx[i__ + 1] * dy[i__ + 1] + dx[
		i__ + 2] * dy[i__ + 2] + dx[i__ + 3] * dy[i__ + 3] + dx[i__ + 
		4] * dy[i__ + 4];
/* L50: */
    }
L60:
    ret_val = dtemp;
    return ret_val;
} /* ddot_ */

doublereal dnrm2_(integer *n, doublereal *dx, integer *incx)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal cutlo = 8.232e-11;
    static doublereal cuthi = 1.304e19;

    /* Format strings */
    static char fmt_30[] = "";
    static char fmt_50[] = "";
    static char fmt_70[] = "";
    static char fmt_110[] = "";

    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val, d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, nn;
    static doublereal sum, xmax;
    static integer next;
    static doublereal hitest;

    /* Assigned format variables */
    static char *next_fmt;

    /* Parameter adjustments */
    --dx;

    /* Function Body */

/*     euclidean norm of the n-vector stored in dx() with storage */
/*     increment incx . */
/*     if    n .le. 0 return with result = 0. */
/*     if n .ge. 1 then incx must be .ge. 1 */

/*           c.l.lawson, 1978 jan 08 */

/*     four phase method     using two built-in constants that are */
/*     hopefully applicable to all machines. */
/*         cutlo = maximum of  dsqrt(u/eps)  over all known machines. */
/*         cuthi = minimum of  dsqrt(v)      over all known machines. */
/*     where */
/*         eps = smallest no. such that eps + 1. .gt. 1. */
/*         u   = smallest positive no.   (underflow limit) */
/*         v   = largest  no.            (overflow  limit) */

/*     brief outline of algorithm.. */

/*     phase 1    scans zero components. */
/*     move to phase 2 when a component is nonzero and .le. cutlo */
/*     move to phase 3 when a component is .gt. cutlo */
/*     move to phase 4 when a component is .ge. cuthi/m */
/*     where m = n for x() real and m = 2*n for complex. */

/*     values for cutlo and cuthi.. */
/*     from the environmental parameters listed in the imsl converter */
/*     document the limiting values are as follows.. */
/*     cutlo, s.p.   u/eps = 2**(-102) for  honeywell.  close seconds are */
/*                   univac and dec at 2**(-103) */
/*                   thus cutlo = 2**(-51) = 4.44089e-16 */
/*     cuthi, s.p.   v = 2**127 for univac, honeywell, and dec. */
/*                   thus cuthi = 2**(63.5) = 1.30438e19 */
/*     cutlo, d.p.   u/eps = 2**(-67) for honeywell and dec. */
/*                   thus cutlo = 2**(-33.5) = 8.23181d-11 */
/*     cuthi, d.p.   same as s.p.  cuthi = 1.30438d19 */
/*     data cutlo, cuthi / 8.232d-11,  1.304d19 / */
/*     data cutlo, cuthi / 4.441e-16,  1.304e19 / */

    if (*n > 0) {
	goto L10;
    }
    ret_val = zero;
    goto L300;

L10:
    next = 0;
    next_fmt = fmt_30;
    sum = zero;
    nn = *n * *incx;
/*                                                 begin main loop */
    i__ = 1;
L20:
    switch (next) {
	case 0: goto L30;
	case 1: goto L50;
	case 2: goto L70;
	case 3: goto L110;
    }
L30:
    if ((d__1 = dx[i__], abs(d__1)) > cutlo) {
	goto L85;
    }
    next = 1;
    next_fmt = fmt_50;
    xmax = zero;

/*                        phase 1.  sum is zero */

L50:
    if (dx[i__] == zero) {
	goto L200;
    }
    if ((d__1 = dx[i__], abs(d__1)) > cutlo) {
	goto L85;
    }

/*                                prepare for phase 2. */
    next = 2;
    next_fmt = fmt_70;
    goto L105;

/*                                prepare for phase 4. */

L100:
    i__ = j;
    next = 3;
    next_fmt = fmt_110;
    sum = sum / dx[i__] / dx[i__];
L105:
    xmax = (d__1 = dx[i__], abs(d__1));
    goto L115;

/*                   phase 2.  sum is small. */
/*                             scale to avoid destructive underflow. */

L70:
    if ((d__1 = dx[i__], abs(d__1)) > cutlo) {
	goto L75;
    }

/*                     common code for phases 2 and 4. */
/*                     in phase 4 sum is large.  scale to avoid overflow. */

L110:
    if ((d__1 = dx[i__], abs(d__1)) <= xmax) {
	goto L115;
    }
/* Computing 2nd power */
    d__1 = xmax / dx[i__];
    sum = one + sum * (d__1 * d__1);
    xmax = (d__1 = dx[i__], abs(d__1));
    goto L200;

L115:
/* Computing 2nd power */
    d__1 = dx[i__] / xmax;
    sum += d__1 * d__1;
    goto L200;


/*                  prepare for phase 3. */

L75:
    sum = sum * xmax * xmax;


/*     for real or d.p. set hitest = cuthi/n */
/*     for complex      set hitest = cuthi/(2*n) */

L85:
    hitest = cuthi / (real) (*n);

/*                   phase 3.  sum is mid-range.  no scaling. */

    i__1 = nn;
    i__2 = *incx;
    for (j = i__; i__2 < 0 ? j >= i__1 : j <= i__1; j += i__2) {
	if ((d__1 = dx[j], abs(d__1)) >= hitest) {
	    goto L100;
	}
/* L95: */
/* Computing 2nd power */
	d__1 = dx[j];
	sum += d__1 * d__1;
    }
    ret_val = sqrt(sum);
    goto L300;

L200:
    i__ += *incx;
    if (i__ <= nn) {
	goto L20;
    }

/*              end of main loop. */

/*              compute square root and adjust for scaling. */

    ret_val = xmax * sqrt(sum);
L300:
    return ret_val;
} /* dnrm2_ */

integer idamax_(integer *n, doublereal *dx, integer *incx)
{
    /* System generated locals */
    integer ret_val, i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__, ix;
    static doublereal dmax__;


/*     finds the index of element having max. absolute value. */
/*     jack dongarra, linpack, 3/11/78. */


    /* Parameter adjustments */
    --dx;

    /* Function Body */
    ret_val = 0;
    if (*n < 1) {
	return ret_val;
    }
    ret_val = 1;
    if (*n == 1) {
	return ret_val;
    }
    if (*incx == 1) {
	goto L20;
    }

/*        code for increment not equal to 1 */

    ix = 1;
    dmax__ = abs(dx[1]);
    ix += *incx;
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if ((d__1 = dx[ix], abs(d__1)) <= dmax__) {
	    goto L5;
	}
	ret_val = i__;
	dmax__ = (d__1 = dx[ix], abs(d__1));
L5:
	ix += *incx;
/* L10: */
    }
    return ret_val;

/*        code for increment equal to 1 */

L20:
    dmax__ = abs(dx[1]);
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if ((d__1 = dx[i__], abs(d__1)) <= dmax__) {
	    goto L30;
	}
	ret_val = i__;
	dmax__ = (d__1 = dx[i__], abs(d__1));
L30:
	;
    }
    return ret_val;
} /* idamax_ */

/* ----------------------------------------------------------------------- */

/*    Preconditioner Tools for Reaction-Transport Problems */
/*    Part I: Block-Diagonal Reaction-Based Factor without Grouping */
/*                        14 September 1995 */

/* The following three subroutines -- DMSET2, DRBDJA, DRBDPS -- */
/* are provided to assist in the generation and solution of */
/* preconditioner matrices for problems arising from reaction-transport */
/* systems, as solved with DASPK.  More specifically, they are intended */
/* as tools for preconditioners that include a contribution from the */
/* reaction terms of the system.  These are intended as auxiliary */
/* routines for the user-supplied routines JAC and PSOL called by */
/* DASPK when the Krylov method is selected. */

/* These routines are intended for a DAE system obtained from a system */
/* of reaction-transport PDEs, in which some of the PDE variables obey */
/* evolution equations, and the rest obey algebraic (time-independent) */
/* equations.  See Ref. 2, Section 4.  It is assumed that the */
/* right-hand sides of all the equations have the form of a sum of a */
/* reaction term R and a transport term S, that the transport term */
/* is discretized by finite differences, and that in the spatial */
/* discretization the PDE variables at each spatial point are kept */
/* together.  Thus the DAE system function, in terms of a dependent */
/* variable vector u, has the form */
/*     G(t,u,u') = I_d u' - R(t,u) - S(t,u) ,  where */
/*     I_d = identity matrix with zeros in the positions corresponding */
/*           to the algebraic components, ones in those for the */
/*           evolution (differential) components. */
/*     R(t,u) = the reaction terms (spatial coupling absent), and */
/*     S(t,u) = the spatial transport terms. */

/* As shown in [2], two possible preconditioners for such a system are: */
/* (a) P_R = c I_d - dR/du, based on the reaction term R alone, and */
/* (b) P_SR = (I - (1/c) dS/du) (c I_d - dR/du), the product of two */
/*     factors (in either order), one being P_R and the other being */
/*     based on the spatial term S alone. */
/* Here c is the scalar CJ that is input to the JAC and PSOL routines */
/* provided by the user (1/c is proportional to the step size H). */

/* The routines given here can be used to provide the reaction-based */
/* factor P_R.  More precisely, they provide an approximation A_R to */
/* P_R.  The matrix P_R is block-diagonal, with each block corresponding */
/* to one spatial point.  In A_R, we compute each block by difference */
/* quotient approximations, by way of calls to a user-supplied routine, */
/* subroutine RBLOCK, that evaluates the reaction terms at a single */
/* spatial point.  A_R has one such block for each spatial point in */
/* the mesh.  (For a more economical approximation, see Part II, */
/* on block-grouping in A_R.) */

/* The routines given here are specialized to the case of a 2-D problem */
/* on a rectangular mesh in the x-y plane.  However, they can be easily */
/* modified for a different problem geometry.  It is also assumed */
/* that the PDE variables are ordered so that the differential */
/* variables appear first, followed by the algebraic variables. */

/* To make use of these routines in a DASPK solution, the user must */
/* provide: */
/* (a) a calling program that sets the DASPK input parameters, and calls */
/*     DMSET2 to set mesh data and mesh-related DASPK inputs; */
/* (b) a JAC routine, as prescribed by the DASPK instructions, which */
/*     calls DRBDJA, and does any other Jacobian-related preprocessing */
/*     needed for preconditioning; and */
/* (c) a PSOL routine, as prescribed by the DASPK instructions, which */
/*     calls DRBDPS for the solution of systems A_R x = b, and does */
/*     any other linear system solving required by the preconditioner. */
/* Detailed descriptions and instructions are given below. */

/* In addition, the use of these routines requires: */
/*  * the LINPACK routines DGEFA and DGESL for dense linear sytems, and */
/*  * the machine constant routine D1MACH for the machine unit roundoff. */

/* (a) The calling program. */
/* The calling program sets the DASPK inputs and makes calls to DASPK. */
/* Here the DASPK inputs include */
/*   INFO(12) = 1 [to signal the Krylov method] */
/*   INFO(15) = 1 [to signal the presence of a JAC routine] */

/* Also, the use of the DRBDJA/DRBDPS routines in conjunction with */
/* DASPK requires that certain mesh-related data be set.  This can be */
/* done with the call */
/*     CALL DMSET2 (MX, MY, NS, NSD, LID, IWORK) */
/* The input arguments to DMSET2 are: */
/*   MX and MY = the mesh dimensions. */
/*   NS  = number of PDE variables. */
/*   NSD = number of differential PDE variables. */
/*   LID = offset in IWORK for array showing the differential and */
/*         algebraic components on input to DASPK, required if either */
/*         INFO(11) = 1 or INFO(16) = 1.  Set LID = 0 otherwise. */
/*         If this array is required, set LID = 40 or 40 + NEQ, */
/*         depending on the value of the constraint option INFO(10). */
/* DMSET2 loads mesh data in a COMMON block /DRPRE1/ used by the */
/* DRBDJA/DRBDPS routines. */

/* DMSET2 also loads the preconditioner work lengths into */
/* IWORK(27) and IWORK(28), and if LID > 0 it sets the ID array */
/* in IWORK showing the differential and algebraic components. */

/* (b) The JAC routine. */
/* The user-supplied JAC routine called by DASPK with the Krylov */
/* method specified, is to generate and preprocess Jacobian-related */
/* data as needed for later solution of the preconditioner system */
/* P x = b.  Assuming that P is to be an approximation of either P_R */
/* or P_SR, the JAC routine should call DRBDJA for the approximation */
/* A_R to P_R.  Subroutine DRBDJA generates A_R using difference */
/* quotients.  It then performs an LU decomposition of each block, */
/* using the LINPACK routine DGEFA. */

/* In terms of the arguments passed to JAC by DASPK, the call to */
/* DRBDJA should have the form */
/*     CALL DRBDJA (T, U, R0, RBLOCK, WK, REWT, CJ, WP, IWP, IER) */
/* where we use U instead of Y for the dependent variable array. */
/* The argument R0 is an array assumed to contain the current value */
/* of the R vector, at the current values (T,U).  This can be done, for */
/* example, by taking R0 to be RPAR, and loading RPAR with the */
/* vector R in the last call to the RES routine; in that case, the */
/* calling program must declare RPAR to have length at least NEQ. */
/* Alternatively, insert a call to RBLOCK (see below) within the */
/* loop over mesh points in DRBDJA. */

/* To use DRBDJA, the user must provide the following subroutine, */
/* which DRBDJA calls to obtain individual blocks of R: */
/*      SUBROUTINE RBLOCK (T, JX, JY, UXY, RXY) */
/* The input arguments to RBLOCK are: */
/*   T     = current time. */
/*   JX,JY = spatial indices in x- and y-directions. */
/*   UXY   = block of NS dependent variables at spatial point (JX,JY). */
/* RBLOCK is to load block (JX,JY) of R(t,u) into the array RXY. */

/* (c) The PSOL routine. */
/* The user-supplied PSOL routine must solve the linear system P x = b, */
/* where P is the preconditioner matrix.  For this, the PSOL routine */
/* should call DRBDPS for the solution of A_R.  Subroutine DRBDPS */
/* solves a linear system A_R x = b, using the LINPACK backsolve */
/* routine DGESL.  In terms of the arguments passed to PSOL by DASPK, */
/* the call to DRBDPS should have the form */
/*     CALL DRBDPS (B, WP, IWP) */
/* DRBDPS overwrites the B array (containing b) with the solution x. */

/* ----------------------------------------------------------------------- */

/* References */
/* [1] Peter N. Brown and Alan C. Hindmarsh, */
/*     Reduced Storage Matrix Methods in Stiff ODE Systems, */
/*     J. Appl. Math. & Comp., 31 (1989), pp. 40-91. */
/* [2] Peter N. Brown, Alan C. Hindmarsh, and Linda R. Petzold, */
/*     Using Krylov Methods in the Solution of Large-Scale Differential- */
/*     Algebraic Systems, SIAM J. Sci. Comput., 15 (1994), pp. 1467-1488. */
/* [3] Peter N. Brown, Alan C. Hindmarsh, and Linda R. Petzold, */
/*     Consistent Initial Condition Calculation for Differential- */
/*     Algebraic Systems, LLNL Report UCRL-JC-122175, August 1995; */
/*     submitted to SIAM J. Sci. Comp. */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int dmset2_(integer *mx, integer *my, integer *ns, integer *
	nsd, integer *lid, integer *iwork)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, i0, jx, jy;
    extern doublereal d1mach_(integer *);
    static doublereal uround;

/* ***BEGIN PROLOGUE  DMSET2 */
/* ***DATE WRITTEN   950830   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine sets mesh parameters needed to use the routines */
/* DRBDJA and DRBDPS, assuming a 2-D rectangular problem. */
/* Given the mesh parameters, it loads the COMMON block /DRPRE1/, */
/* and the lengths LENWP and LENIWP in IWORK. */
/* Then if LID > 0, it also sets the ID array in IWORK, indicating */
/* which components are differential and which are algebraic. */

/* The variables in the COMMON block are defined as follows: */
/*   SRUR   = SQRT(unit roundoff), used in difference quotients. */
/*            UROUND = D1MACH(4) generates the unit roundoff. */
/*   MP     = NS = number of PDE variables, the size of each block in */
/*            the block-diagonal preconditioner matrix P_R. */
/*   MPD    = NSD = number of differential PDE variables.  In the DAE */
/*            system, the first MPD variables at each spatial point have */
/*            time  derivatives, and the remaining (MP - MPD) do not. */
/*   MPSQ   = MP*MP. */
/*   MESHX  = MX = x mesh size. */
/*   MESHY  = MY = y mesh size (the mesh is MESHX by MESHY). */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   D1MACH */

/* ***END PROLOGUE  DMSET2 */


/* Load the COMMON block. */
    /* Parameter adjustments */
    --iwork;

    /* Function Body */
    uround = d1mach_(&c__4);
    drpre1_1.srur = sqrt(uround);
    drpre1_1.mp = *ns;
    drpre1_1.mpd = *nsd;
    drpre1_1.mpsq = *ns * *ns;
    drpre1_1.meshx = *mx;
    drpre1_1.meshy = *my;
    drpre1_1.mxmp = drpre1_1.meshx * drpre1_1.mp;

/* Here set the sizes of the preconditioning storage space segments */
/* in RWORK and IWORK. */
    iwork[27] = drpre1_1.mpsq * drpre1_1.meshx * drpre1_1.meshy;
    iwork[28] = drpre1_1.mp * drpre1_1.meshx * drpre1_1.meshy;

/* If LID .GT. 0, set the ID array in IWORK. */
    if (*lid == 0) {
	return 0;
    }
    i0 = *lid;
    i__1 = *my;
    for (jy = 1; jy <= i__1; ++jy) {
	i__2 = *mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    i__3 = drpre1_1.mpd;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L10: */
		iwork[i0 + i__] = 1;
	    }
	    i__3 = drpre1_1.mp;
	    for (i__ = drpre1_1.mpd + 1; i__ <= i__3; ++i__) {
/* L20: */
		iwork[i0 + i__] = -1;
	    }
	    i0 += drpre1_1.mp;
/* L30: */
	}
/* L40: */
    }

    return 0;
/* ------------  End of Subroutine DMSET2  ------------------------------- */
} /* dmset2_ */

/* Subroutine */ int drbdja_(doublereal *t, doublereal *u, doublereal *r0, 
	S_fp rblock, doublereal *r1, doublereal *rewt, doublereal *cj, 
	doublereal *bd, integer *ipbd, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, j, j0, js;
    static doublereal uj;
    static integer jx, jy;
    static doublereal fac;
    static integer ibd;
    static doublereal del;
    static integer iip;
    static doublereal dfac;
    extern /* Subroutine */ int dgefa_(doublereal *, integer *, integer *, 
	    integer *, integer *);
    static integer idiag;

/* ***BEGIN PROLOGUE  DRBDJA */
/* ***DATE WRITTEN   950914   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine generates and preprocesses a block-diagonal */
/* preconditioner matrix, based on the part of the Jacobian corresponding */
/* to the reaction terms R of the problem. */
/* It generates a matrix of the form CJ * I_d - dR/du. */
/* It calls DGEFA to do LU decomposition of each diagonal block. */
/* The computation of the diagonal blocks uses the mesh information in */
/* the COMMON block /DRPRE1/.  One block per spatial point is computed. */
/* The Jacobian elements are generated by difference quotients. */
/* This routine calls a user routine of the form */
/*      SUBROUTINE RBLOCK (T, JX, JY, UXY, RXY) */
/* which is to set RXY to block (JX,JY) of R, as a function of the */
/* current time T and block UXY of current dependent variable vector U. */
/* The array R0 is assumed to contain the current value of R at (T,U). */
/* ----------------------------------------------------------------------- */
/* On input: */
/*   T      = current value of independent variable. */
/*   U      = current dependent variable array. */
/*   R0  = array of current values of the vector R at (T,U) */
/*   RBLOCK = name of external routine that computes a single block of R. */
/*   R1     = array of length NEQ for work space. */
/*   REWT   = reciprocal error weights. */
/*   CJ     = scalar used in forming the system Jacobian. */

/* On output: */
/*   BD     = array containing the LU factors of the diagonal blocks. */
/*   IPBD   = integer array of pivots for the LU factorizations. */
/*   IER    = integer error flag.  If no error occurred, IER = 0. */
/*            If a zero pivot was found at stage k in one of the LU */
/*            factorizations, this routine returns IER = k > 0. */
/* Here BD is the RWORK segment WP, and IPBD is the IWORK segment IWP. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   RBLOCK, DGEFA */

/* ***END PROLOGUE  DRBDJA */



/* Make MP calls to RBLOCK to approximate each diagonal block of dR/du. */
    /* Parameter adjustments */
    --ipbd;
    --bd;
    --rewt;
    --r1;
    --r0;
    --u;

    /* Function Body */
    dfac = .01;
    ibd = 0;
    j0 = 0;
    i__1 = drpre1_1.meshy;
    for (jy = 1; jy <= i__1; ++jy) {
	i__2 = drpre1_1.meshx;
	for (jx = 1; jx <= i__2; ++jx) {
/* If R0 has not been set previously as an array of length NEQ, it can */
/* be set here, as an array of length MP, with the call */
/*         CALL RBLOCK (T, JX, JY, U(J0+1), R0) */
/* In this case, change R0(J0+I) below to R0(I). */
	    i__3 = drpre1_1.mp;
	    for (js = 1; js <= i__3; ++js) {
		j = j0 + js;
		uj = u[j];
/* Computing MAX */
		d__1 = drpre1_1.srur * abs(uj), d__2 = dfac / rewt[j];
		del = max(d__1,d__2);
		u[j] += del;
		fac = -1. / del;
		(*rblock)(t, &jx, &jy, &u[j0 + 1], &r1[1]);
		i__4 = drpre1_1.mp;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L10: */
		    bd[ibd + i__] = (r1[i__] - r0[j0 + i__]) * fac;
		}
		u[j] = uj;
		ibd += drpre1_1.mp;
/* L20: */
	    }
	    j0 += drpre1_1.mp;
/* L30: */
	}
/* L40: */
    }

/* Add matrix CJ * I_d, and do LU decomposition on blocks. -------------- */
    ibd = 1;
    iip = 1;
    i__1 = drpre1_1.meshx * drpre1_1.meshy;
    for (j = 1; j <= i__1; ++j) {
	idiag = ibd;
	i__2 = drpre1_1.mp;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (i__ <= drpre1_1.mpd) {
		bd[idiag] += *cj;
	    }
/* L70: */
	    idiag += drpre1_1.mp + 1;
	}
	dgefa_(&bd[ibd], &drpre1_1.mp, &drpre1_1.mp, &ipbd[iip], ier);
	if (*ier != 0) {
	    goto L90;
	}
	ibd += drpre1_1.mpsq;
	iip += drpre1_1.mp;
/* L80: */
    }
L90:
    return 0;
/* ------------  End of Subroutine DRBDJA  ------------------------------- */
} /* drbdja_ */

/* Subroutine */ int drbdps_(doublereal *b, doublereal *bd, integer *ipbd)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ib, jx, jy, ibd, ier;
    extern /* Subroutine */ int dgesl_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *);

/* ***BEGIN PROLOGUE  DRBDPS */
/* ***DATE WRITTEN   950914   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine solves a linear system A_R x = b, using the LU factors */
/* of the diagonal blocks computed in DRBDJA, and mesh parameters */
/* in the COMMON block /DRPRE1/. */
/* Here BD is the RWORK segment WP, and IPBD is the IWORK segment IWP. */
/* The right-hand side vector b, contained in B on entry, is overwritten */
/* with the solution vector x on return. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DGESL */

/* ***END PROLOGUE  DRBDPS */



    /* Parameter adjustments */
    --ipbd;
    --bd;
    --b;

    /* Function Body */
    ier = 0;
    ib = 1;
    ibd = 1;
    i__1 = drpre1_1.meshy;
    for (jy = 1; jy <= i__1; ++jy) {
	i__2 = drpre1_1.meshx;
	for (jx = 1; jx <= i__2; ++jx) {
	    dgesl_(&bd[ibd], &drpre1_1.mp, &drpre1_1.mp, &ipbd[ib], &b[ib], &
		    c__0);
	    ib += drpre1_1.mp;
	    ibd += drpre1_1.mpsq;
/* L10: */
	}
/* L20: */
    }

    return 0;
/* ------------  End of Subroutine DRBDPS  ------------------------------- */
} /* drbdps_ */

/* ----------------------------------------------------------------------- */

/*    Preconditioner Tools for Reaction-Transport Problems */
/*    Part II: Block-Grouping in Block-Diagonal Reaction-Based Factor */
/*                        14 September 1995 */

/* The following four subroutines -- DGSET2, GSET1, DRBGJA, DRBGPS -- */
/* are provided to assist in the generation and solution of */
/* preconditioner matrices for problems arising from reaction-transport */
/* systems, as solved with DASPK.  More specifically, they are intended */
/* as tools for preconditioners that include a contribution from the */
/* reaction terms of the system.  These are intended as auxiliary */
/* routines for the user-supplied routines JAC and PSOL called by */
/* DASPK when the Krylov method is selected. */

/* These routines are intended for a DAE system obtained from a system */
/* of reaction-transport PDEs, in which some of the PDE variables obey */
/* evolution equations, and the rest obey algebraic (time-independent) */
/* equations.  See Ref. 2, Section 4.  It is assumed that the */
/* right-hand sides of all the equations have the form of a sum of a */
/* reaction term R and a transport term S, that the transport term */
/* is discretized by finite differences, and that in the spatial */
/* discretization the PDE variables at each spatial point are kept */
/* together.  Thus the DAE system function, in terms of a dependent */
/* variable vector u, has the form */
/*     G(t,u,u') = I_d u' - R(t,u) - S(t,u) ,  where */
/*     I_d = identity matrix with zeros in the positions corresponding */
/*           to the algebraic components, ones in those for the */
/*           evolution (differential) components. */
/*     R(t,u) = the reaction terms (spatial coupling absent), and */
/*     S(t,u) = the spatial transport terms. */

/* As shown in [2], two possible preconditioners for such a system are: */
/* (a) P_R = c I_d - dR/du, based on the reaction term R alone, and */
/* (b) P_SR = (I - (1/c) dS/du) (c I_d - dR/du), the product of two */
/*     factors (in either order), one being P_R and the other being */
/*     based on the spatial term S alone. */
/* Here c is the scalar CJ that is input to the JAC and PSOL routines */
/* provided by the user (1/c is proportional to the step size H). */

/* The routines given here can be used to provide the reaction-based */
/* factor P_R.  More precisely, they provide an approximation A_R to */
/* P_R.  The matrix P_R is block-diagonal, with each block corresponding */
/* to one spatial point.  In A_R, we compute each block by difference */
/* quotient approximations, by way of calls to a user-supplied routine, */
/* subroutine RBLOCK, that evaluates the reaction terms at a single */
/* spatial point.  In addition, rather than evaluate a block at every */
/* spatial point in the mesh, we use a block-grouping scheme, described */
/* in Ref. 1.  In this scheme, the mesh points are grouped, as in domain */
/* decomposition, and only one block of dR/du is computed for each group; */
/* then in solving A_R x = b, the inverse of the representative block is */
/* applied to all the blocks of unknowns in the group.  Block-grouping */
/* greatly reduces the storage required for the preconditioner. */

/* The routines given here are specialized to the case of a 2-D problem */
/* on a rectangular mesh in the x-y plane, and for a block-grouping */
/* arrangement that is rectangular (i.e. the Cartesian product of two */
/* 1-D groupings).  However, they can be easily modified for a different */
/* problem geometry or a different grouping arrangement.  It is also */
/* assumed that the PDE variables are ordered so that the differential */
/* variables appear first, followed by the algebraic variables. */

/* To make use of these routines in a DASPK solution, the user must */
/* provide: */
/* (a) a calling program that sets the DASPK input parameters, and calls */
/*     DGSET2 to set the mesh and block-grouping data needed later; */
/* (b) a JAC routine, as prescribed by the DASPK instructions, which */
/*     calls DRBGJA, and does any other Jacobian-related preprocessing */
/*     needed for preconditioning; and */
/* (c) a PSOL routine, as prescribed by the DASPK instructions, which */
/*     calls DRBGPS for the solution of systems A_R x = b, and does */
/*     any other linear system solving required by the preconditioner. */
/* Detailed descriptions and instructions are given below. */

/* In addition, the use of these routines requires: */
/*  * the LINPACK routines DGEFA and DGESL for dense linear sytems, and */
/*  * the machine constant routine D1MACH for the machine unit roundoff. */

/* (a) The calling program. */
/* The calling program sets the DASPK inputs and makes calls to DASPK. */
/* Here the DASPK inputs include */
/*   INFO(12) = 1 [to signal the Krylov method] */
/*   INFO(15) = 1 [to signal the presence of a JAC routine] */
/* Also, the use of the DRBGJA/DRBGPS routines in conjunctin with */
/* DASPK requires that certain mesh-related and block-grouping data */
/* be set.  This can be done with the call */
/*     CALL DGSET2 (MX, MY, NS, NSD, NXG, NYG, LID, IWORK) */
/* The input arguments to DGSET2 are: */
/*   MX and MY = the mesh dimensions. */
/*   NS  = number of PDE variables. */
/*   NSD = number of differential PDE variables. */
/*   NXG = number of groups in the x direction. */
/*   NYG = number of groups in the y direction. */
/*   LID = offset in IWORK for array showing the differential and */
/*         algebraic components on input to DASPK, required if either */
/*         INFO(11) = 1 or INFO(16) = 1.  Set LID = 0 otherwise. */
/*         If this array is required, set LID = 40 or 40 + NEQ, */
/*         depending on the value of the constraint option INFO(10). */

/* DGSET2 loads mesh parameters and group data in two COMMON */
/* blocks, /DRPRE1/ and /RPRE2/, used by these routines. */
/* Note: the declaration of /RPRE2/ in DGSET2, DRBGJA, and DRBGPS */
/* uses a parameter MAXM that must be .GE. MAX (MX, MY); */
/* this must be altered for larger mesh sizes. */

/* DGSET2 also loads the preconditioner work lengths into */
/* IWORK(27) and IWORK(28), and if LID > 0 it sets the ID array */
/* in IWORK showing the differential and algebraic components. */

/* DGSET2 generates a rectangular grouping arrangement, with */
/* partitioning in each mesh direction being uniform (or as nearly */
/* uniform as possible), by calling the routine GSET1 twice. */
/* If a different grouping arrangement is desired, the user must */
/* alter or replace DGSET2 accordingly. */

/* (b) The JAC routine. */
/* The user-supplied JAC routine called by DASPK with the Krylov */
/* method specified, is to generate and preprocess Jacobian-related */
/* data as needed for later solution of the preconditioner system */
/* P x = b.  Assuming that P is to be an approximation of either P_R */
/* or P_SR, the JAC routine should call DRBGJA for the approximation */
/* A_R to P_R.  Subroutine DRBGJA generates A_R using difference */
/* quotients and the block-grouping information.  It then performs an */
/* LU decomposition of each block, using the LINPACK routine DGEFA. */

/* In terms of the arguments passed to JAC by DASPK, the call to */
/* DRBGJA should have the form */
/*     CALL DRBGJA (T, U, R0, RBLOCK, WK, REWT, CJ, WP, IWP, IER) */
/* where we use U instead of Y for the dependent variable array. */
/* The argument R0 is an array assumed to contain the current value */
/* of the R vector, at the current values (T,U).  This can be done, for */
/* example, by taking R0 to be RPAR, and loading RPAR with the */
/* vector R in the last call to the RES routine; in that case, the */
/* calling program must declare RPAR to have length at least NEQ. */
/* Alternatively, insert a call to RBLOCK (see below) within the */
/* loop over mesh points in DRBGJA. */

/* To use DRBGJA, the user must provide the following subroutine, */
/* which DRBGJA calls to obtain individual blocks of R: */
/*      SUBROUTINE RBLOCK (T, JX, JY, UXY, RXY) */
/* The input arguments to RBLOCK are: */
/*   T     = current time. */
/*   JX,JY = spatial indices in x- and y-directions. */
/*   UXY   = block of NS dependent variables at spatial point (JX,JY). */
/* RBLOCK is to load block (JX,JY) of R(t,u) into the array RXY. */

/* (c) The PSOL routine. */
/* The user-supplied PSOL routine must solve the linear system P x = b, */
/* where P is the preconditioner matrix.  For this, the PSOL routine */
/* should call DRBGPS for the solution of A_R.  Subroutine DRBGPS */
/* solves a linear system A_R x = b, using the LINPACK backsolve */
/* routine DGESL.  In terms of the arguments passed to PSOL by DASPK, */
/* the call to DRBGPS should have the form */
/*     CALL DRBGPS (B, WP, IWP) */
/* DRBGPS overwrites the B array (containing b) with the solution x. */

/* ----------------------------------------------------------------------- */

/* References */
/* [1] Peter N. Brown and Alan C. Hindmarsh, */
/*     Reduced Storage Matrix Methods in Stiff ODE Systems, */
/*     J. Appl. Math. & Comp., 31 (1989), pp. 40-91. */
/* [2] Peter N. Brown, Alan C. Hindmarsh, and Linda R. Petzold, */
/*     Using Krylov Methods in the Solution of Large-Scale Differential- */
/*     Algebraic Systems, SIAM J. Sci. Comput., 15 (1994), pp. 1467-1488. */
/* [3] Peter N. Brown, Alan C. Hindmarsh, and Linda R. Petzold, */
/*     Consistent Initial Condition Calculation for Differential- */
/*     Algebraic Systems, LLNL Report UCRL-JC-122175, August 1995; */
/*     submitted to SIAM J. Sci. Comp. */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int dgset2_(integer *mx, integer *my, integer *ns, integer *
	nsd, integer *nxg, integer *nyg, integer *lid, integer *iwork)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, i0, jx, jy;
    extern /* Subroutine */ int gset1_(integer *, integer *, integer *, 
	    integer *, integer *);
    extern doublereal d1mach_(integer *);
    static doublereal uround;

/* ***BEGIN PROLOGUE  DGSET2 */
/* ***DATE WRITTEN   950828   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine sets mesh and block-grouping data needed to use the */
/* DRBGJA and DRBGPS routines, assuming a 2-D rectangular problem with */
/* uniform rectangular block-grouping.  Given the mesh and group */
/* parameters, it loads the COMMON blocks /DRPRE1/ and /RPRE2/, and the */
/* lengths LENWP and LENIWP in IWORK.  Then if LID > 0, it also sets the */
/* ID array in IWORK, indicating which components are differential and */
/* which are algebraic. */

/* The variables in the COMMON blocks are defined as follows: */
/*   SRUR   = SQRT(unit roundoff), used in difference quotients. */
/*            UROUND = D1MACH(4) generates the unit roundoff. */
/*   MP     = NS = number of PDE variables, the size of each block in */
/*            the block-diagonal preconditioner matrix P_R. */
/*   MPD    = NSD = number of differential PDE variables.  In the DAE */
/*            system, the first MPD variables at each spatial point have */
/*            time  derivatives, and the remaining (MP - MPD) do not. */
/*   MPSQ   = MP*MP. */
/*   MESHX  = MX = x mesh size. */
/*   MESHY  = MY = y mesh size (the mesh is MESHX by MESHY). */
/*   NGX    = NXG = no. groups in x direction in block-grouping scheme. */
/*   NGY    = NYG = no. groups in y direction in block-grouping scheme. */
/*   NGRP   = total number of groups = NGX*NGY. */
/*   MXMP   = MESHX*MP. */
/*   JGX    = length NGX+1 array of group boundaries in x direction. */
/*            Group igx has x indices jx = JGX(igx),...,JGX(igx+1)-1. */
/*   JIGX   = length MESHX array of x group indices vs x node index. */
/*            x node index jx is in x group JIGX(jx). */
/*   JXR    = length NGX array of x indices representing the x groups. */
/*            The index for x group igx is jx = JXR(igx). */
/*   JGY, JIGY, JYR = analogous arrays for grouping in y direction. */
/* The COMMON block /RPRE2/ declared below has arrays whose minimum */
/* lengths depend on MX, MY, NXG, and NYG.  For simplicity, the */
/* declaration uses a single parameter MAXM, assumed to be .GE. all */
/* four of these numbers.  If this declaration is altered here, it must */
/* be altered consistently in subroutines DRBGJA and DRBGPS. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   D1MACH, GSET1 */

/* ***END PROLOGUE  DGSET2 */


/* Load all the scalars in COMMON blocks. */
    /* Parameter adjustments */
    --iwork;

    /* Function Body */
    uround = d1mach_(&c__4);
    drpre1_1.srur = sqrt(uround);
    drpre1_1.mp = *ns;
    drpre1_1.mpd = *nsd;
    drpre1_1.mpsq = *ns * *ns;
    drpre1_1.meshx = *mx;
    drpre1_1.meshy = *my;
    drpre1_1.mxmp = drpre1_1.meshx * drpre1_1.mp;
    rpre2_1.ngx = *nxg;
    rpre2_1.ngy = *nyg;
    rpre2_1.ngrp = rpre2_1.ngx * rpre2_1.ngy;

/* Call GSET1 for each mesh direction to load grouping arrays. */
    gset1_(&drpre1_1.meshx, &rpre2_1.ngx, rpre2_1.jgx, rpre2_1.jigx, 
	    rpre2_1.jxr);
    gset1_(&drpre1_1.meshy, &rpre2_1.ngy, rpre2_1.jgy, rpre2_1.jigy, 
	    rpre2_1.jyr);

/* Here set the sizes of the preconditioning storage space segments */
/* in RWORK and IWORK. */
    iwork[27] = drpre1_1.mpsq * rpre2_1.ngrp;
    iwork[28] = drpre1_1.mp * rpre2_1.ngrp;

/* If LID .GT. 0, set the ID array in IWORK. */
    if (*lid == 0) {
	return 0;
    }
    i0 = *lid;
    i__1 = *my;
    for (jy = 1; jy <= i__1; ++jy) {
	i__2 = *mx;
	for (jx = 1; jx <= i__2; ++jx) {
	    i__3 = drpre1_1.mpd;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L10: */
		iwork[i0 + i__] = 1;
	    }
	    i__3 = drpre1_1.mp;
	    for (i__ = drpre1_1.mpd + 1; i__ <= i__3; ++i__) {
/* L20: */
		iwork[i0 + i__] = -1;
	    }
	    i0 += drpre1_1.mp;
/* L30: */
	}
/* L40: */
    }

    return 0;
/* ------------  End of Subroutine DGSET2  ------------------------------- */
} /* dgset2_ */

/* Subroutine */ int gset1_(integer *m, integer *ng, integer *jg, integer *
	jig, integer *jr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, ig, len1, ngm1, mper;

/* ***BEGIN PROLOGUE  GSET1 */
/* ***DATE WRITTEN   950828   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine sets arrays JG, JIG, and JR describing a uniform */
/* (or nearly uniform) partition of (1,2,...,M) into NG groups. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   NONE */

/* ***END PROLOGUE  GSET1 */


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
	jr[ig] = (integer) (((real) ig - .5) * (real) mper + .5);
    }
    jr[*ng] = (integer) ((real) (ngm1 * mper + 1 + *m) * .5);

    return 0;
/* ------------  End of Subroutine GSET1  -------------------------------- */
} /* gset1_ */

/* Subroutine */ int drbgja_(doublereal *t, doublereal *u, doublereal *r0, 
	S_fp rblock, doublereal *r1, doublereal *rewt, doublereal *cj, 
	doublereal *bd, integer *ipbd, integer *ier)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, j, j0, j00, ig, js;
    static doublereal uj;
    static integer jx, jy;
    static doublereal fac;
    static integer ibd;
    static doublereal del;
    static integer iip, igx, igy;
    static doublereal dfac;
    extern /* Subroutine */ int dgefa_(doublereal *, integer *, integer *, 
	    integer *, integer *);
    static integer idiag;

/* ***BEGIN PROLOGUE  DRBGJA */
/* ***DATE WRITTEN   950914   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine generates and preprocesses a block-diagonal */
/* preconditioner matrix, based on the part of the Jacobian corresponding */
/* to the reaction terms R of the problem, using block-grouping. */
/* It generates a matrix of the form CJ * I_d - dR/du. */
/* It calls DGEFA to do LU decomposition of each diagonal block. */
/* The computation of the diagonal blocks uses the mesh and grouping */
/* information in the COMMON blocks /DRPRE1/ and /RPRE2/.  One block */
/* per group is computed.  The Jacobian elements are generated by */
/* difference quotients. */
/* This routine calls a user-supplied routine of the form */
/*      SUBROUTINE RBLOCK (T, JX, JY, UXY, RXY) */
/* which is to set RXY to block (JX,JY) of R, as a function of the */
/* current time T and block UXY of current dependent variable vector U. */
/* The array R0 is assumed to contain the current value of R at (T,U). */
/* ----------------------------------------------------------------------- */
/* On input: */
/*   T      = current value of independent variable. */
/*   U      = current dependent variable array. */
/*   R0  = array of current values of the vector R at (T,U) */
/*   RBLOCK = name of external routine that computes a single block of R. */
/*   R1     = array of length NEQ for work space. */
/*   REWT   = reciprocal error weights. */
/*   CJ     = scalar used in forming the system Jacobian. */

/* On output: */
/*   BD     = array containing the LU factors of the diagonal blocks. */
/*   IPBD   = integer array of pivots for the LU factorizations. */
/*   IER    = integer error flag.  If no error occurred, IER = 0. */
/*            If a zero pivot was found at stage k in one of the LU */
/*            factorizations, this routine returns IER = k > 0. */
/* Here BD is the RWORK segment WP, and IPBD is the IWORK segment IWP. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   RBLOCK, DGEFA */

/* ***END PROLOGUE  DRBGJA */


/* The declaration of /RPRE2/ below must agree with that in DGSET2. */

/* Make MP calls to RBLOCK to approximate each diagonal block of dR/du. */
    /* Parameter adjustments */
    --ipbd;
    --bd;
    --rewt;
    --r1;
    --r0;
    --u;

    /* Function Body */
    dfac = .01;
    ibd = 0;
    i__1 = rpre2_1.ngy;
    for (igy = 1; igy <= i__1; ++igy) {
	jy = rpre2_1.jyr[igy - 1];
	j00 = (jy - 1) * drpre1_1.mxmp;
	i__2 = rpre2_1.ngx;
	for (igx = 1; igx <= i__2; ++igx) {
	    jx = rpre2_1.jxr[igx - 1];
	    j0 = j00 + (jx - 1) * drpre1_1.mp;
/* If R0 has not been set previously as an array of length NEQ, it can */
/* be set here, as an array of length MP, with the call */
/*         CALL RBLOCK (T, JX, JY, U(J0+1), R0) */
/* In this case, change R0(J0+I) below to R0(I). */
	    i__3 = drpre1_1.mp;
	    for (js = 1; js <= i__3; ++js) {
		j = j0 + js;
		uj = u[j];
/* Computing MAX */
		d__1 = drpre1_1.srur * abs(uj), d__2 = dfac / rewt[j];
		del = max(d__1,d__2);
		u[j] += del;
		fac = -1. / del;
		(*rblock)(t, &jx, &jy, &u[j0 + 1], &r1[1]);
		i__4 = drpre1_1.mp;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L10: */
		    bd[ibd + i__] = (r1[i__] - r0[j0 + i__]) * fac;
		}
		u[j] = uj;
		ibd += drpre1_1.mp;
/* L20: */
	    }
/* L30: */
	}
/* L40: */
    }

/* Add matrix CJ * I_d, and do LU decomposition on blocks. -------------- */
    ibd = 1;
    iip = 1;
    i__1 = rpre2_1.ngrp;
    for (ig = 1; ig <= i__1; ++ig) {
	idiag = ibd;
	i__2 = drpre1_1.mp;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (i__ <= drpre1_1.mpd) {
		bd[idiag] += *cj;
	    }
/* L70: */
	    idiag += drpre1_1.mp + 1;
	}
	dgefa_(&bd[ibd], &drpre1_1.mp, &drpre1_1.mp, &ipbd[iip], ier);
	if (*ier != 0) {
	    goto L90;
	}
	ibd += drpre1_1.mpsq;
	iip += drpre1_1.mp;
/* L80: */
    }
L90:
    return 0;
/* ------------  End of Subroutine DRBGJA  ------------------------------- */
} /* drbgja_ */

/* Subroutine */ int drbgps_(doublereal *b, doublereal *bd, integer *ipbd)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ib, jx, jy, ig0, ibd, ier, iip, igx, igy, igm1;
    extern /* Subroutine */ int dgesl_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, integer *);

/* ***BEGIN PROLOGUE  DRBGPS */
/* ***DATE WRITTEN   950914   (YYMMDD) */

/* ***AUTHORS  A. C. Hindmarsh */
/*            Lawrence Livermore National Laboratory */
/*            L-316, P.O. Box 808 */
/*            Livermore, CA 94551 */

/* ***DESCRIPTION */

/* ----------------------------------------------------------------------- */
/* This routine solves a linear system A_R x = b, using the LU factors */
/* of the diagonal blocks computed in DRBGJA, and the mesh and */
/* block-grouping data in the COMMON blocks /DRPRE1/ and /RPRE2/. */
/* Here BD is the RWORK segment WP, and IPBD is the IWORK segment IWP. */
/* The right-hand side vector b, contained in B on entry, is overwritten */
/* with the solution vector x on return. */
/* ----------------------------------------------------------------------- */
/* ***ROUTINES CALLED */
/*   DGESL */

/* ***END PROLOGUE  DRBGPS */


/* The declaration of /RPRE2/ below must agree with that in DGSET2. */

    /* Parameter adjustments */
    --ipbd;
    --bd;
    --b;

    /* Function Body */
    ier = 0;
    ib = 1;
    i__1 = drpre1_1.meshy;
    for (jy = 1; jy <= i__1; ++jy) {
	igy = rpre2_1.jigy[jy - 1];
	ig0 = (igy - 1) * rpre2_1.ngx;
	i__2 = drpre1_1.meshx;
	for (jx = 1; jx <= i__2; ++jx) {
	    igx = rpre2_1.jigx[jx - 1];
	    igm1 = igx - 1 + ig0;
	    ibd = igm1 * drpre1_1.mpsq + 1;
	    iip = igm1 * drpre1_1.mp + 1;
	    dgesl_(&bd[ibd], &drpre1_1.mp, &drpre1_1.mp, &ipbd[iip], &b[ib], &
		    c__0);
	    ib += drpre1_1.mp;
/* L10: */
	}
/* L20: */
    }

    return 0;
/* ------------  End of Subroutine DRBGPS  ------------------------------- */
} /* drbgps_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*        BASIC LINEAR ALGEBRA FOR SPARSE MATRICES. BLASSM MODULE       c */
/* ----------------------------------------------------------------------c */
/* aplb   :   computes     C = A+B                                      c */
/* aplb1  :   computes     C = A+B  [Sorted version: A, B, C sorted]    c */
/* aplsb  :   computes     C = A + s B                                  c */
/* diamua :   Computes     C = Diag * A                                 c */
/* amudia :   Computes     C = A* Diag                                  c */
/* aplsca :   Computes     A:= A + s I    (s = scalar)                  c */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int aplb_(integer *nrow, integer *ncol, integer *job, 
	doublereal *a, integer *ja, integer *ia, doublereal *b, integer *jb, 
	integer *ib, doublereal *c__, integer *jc, integer *ic, integer *
	nzmax, integer *iw, integer *ierr)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, k, ka, kb, ii, len, jcol, jpos;
    static logical values;

/* ----------------------------------------------------------------------- */
/* performs the matrix sum  C = A+B. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A and B */
/* ncol  = integer. The column dimension of A and B. */
/* job   = integer. Job indicator. When job = 0, only the structure */
/*                  (i.e. the arrays jc, ic) is computed and the */
/*                  real values are ignored. */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format. */

/* b, */
/* jb, */
/* ib	=  Matrix B in compressed sparse row format. */

/* nzmax	= integer. The  length of the arrays c and jc. */
/*         amub will stop if the result matrix C  has a number */
/*         of elements that exceeds exceeds nzmax. See ierr. */

/* on return: */
/* ---------- */
/* c, */
/* jc, */
/* ic	= resulting matrix C in compressed sparse row sparse format. */

/* ierr	= integer. serving as error message. */
/*         ierr = 0 means normal return, */
/*         ierr .gt. 0 means that amub stopped while computing the */
/*         i-th row  of C with i=ierr, because the number */
/*         of elements in C exceeds nzmax. */

/* work arrays: */
/* ------------ */
/* iw	= integer work array of length equal to the number of */
/*         columns in A. */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ic;
    --ib;
    --ia;
    --iw;
    --a;
    --ja;
    --b;
    --jb;
    --c__;
    --jc;

    /* Function Body */
    values = *job != 0;
    *ierr = 0;
    len = 0;
    ic[1] = 1;
    i__1 = *ncol;
    for (j = 1; j <= i__1; ++j) {
	iw[j] = 0;
/* L1: */
    }

    i__1 = *nrow;
    for (ii = 1; ii <= i__1; ++ii) {
/*     row i */
	i__2 = ia[ii + 1] - 1;
	for (ka = ia[ii]; ka <= i__2; ++ka) {
	    ++len;
	    jcol = ja[ka];
	    if (len > *nzmax) {
		goto L999;
	    }
	    jc[len] = jcol;
	    if (values) {
		c__[len] = a[ka];
	    }
	    iw[jcol] = len;
/* L200: */
	}

	i__2 = ib[ii + 1] - 1;
	for (kb = ib[ii]; kb <= i__2; ++kb) {
	    jcol = jb[kb];
	    jpos = iw[jcol];
	    if (jpos == 0) {
		++len;
		if (len > *nzmax) {
		    goto L999;
		}
		jc[len] = jcol;
		if (values) {
		    c__[len] = b[kb];
		}
		iw[jcol] = len;
	    } else {
		if (values) {
		    c__[jpos] += b[kb];
		}
	    }
/* L300: */
	}
	i__2 = len;
	for (k = ic[ii]; k <= i__2; ++k) {
	    iw[jc[k]] = 0;
/* L301: */
	}
	ic[ii + 1] = len + 1;
/* L500: */
    }
    return 0;
L999:
    *ierr = ii;
    return 0;
/* ------------end of aplb ----------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* aplb_ */

/* Subroutine */ int aplb1_(integer *nrow, integer *ncol, integer *job, 
	doublereal *a, integer *ja, integer *ia, doublereal *b, integer *jb, 
	integer *ib, doublereal *c__, integer *jc, integer *ic, integer *
	nzmax, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j1, j2, kc, ka, kb, kamax, kbmax;
    static logical values;

/* ----------------------------------------------------------------------- */
/* performs the matrix sum  C = A+B for matrices in sorted CSR format. */
/* the difference with aplb  is that the resulting matrix is such that */
/* the elements of each row are sorted with increasing column indices in */
/* each row, provided the original matrices are sorted in the same way. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A and B */
/* ncol  = integer. The column dimension of A and B. */
/* job   = integer. Job indicator. When job = 0, only the structure */
/*                  (i.e. the arrays jc, ic) is computed and the */
/*                  real values are ignored. */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format with entries sorted */

/* b, */
/* jb, */
/* ib	=  Matrix B in compressed sparse row format with entries sorted */
/*        ascendly in each row */

/* nzmax	= integer. The  length of the arrays c and jc. */
/*         amub will stop if the result matrix C  has a number */
/*         of elements that exceeds exceeds nzmax. See ierr. */

/* on return: */
/* ---------- */
/* c, */
/* jc, */
/* ic	= resulting matrix C in compressed sparse row sparse format */
/*         with entries sorted ascendly in each row. */

/* ierr	= integer. serving as error message. */
/*         ierr = 0 means normal return, */
/*         ierr .gt. 0 means that amub stopped while computing the */
/*         i-th row  of C with i=ierr, because the number */
/*         of elements in C exceeds nzmax. */

/* Notes: */
/* ------- */
/*     this will not work if any of the two input matrices is not sorted */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ic;
    --ib;
    --ia;
    --a;
    --ja;
    --b;
    --jb;
    --c__;
    --jc;

    /* Function Body */
    values = *job != 0;
    *ierr = 0;
    kc = 1;
    ic[1] = kc;

    i__1 = *nrow;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ka = ia[i__];
	kb = ib[i__];
	kamax = ia[i__ + 1] - 1;
	kbmax = ib[i__ + 1] - 1;
L5:
	if (ka <= kamax) {
	    j1 = ja[ka];
	} else {
	    j1 = *ncol + 1;
	}
	if (kb <= kbmax) {
	    j2 = jb[kb];
	} else {
	    j2 = *ncol + 1;
	}

/*     three cases */

	if (j1 == j2) {
	    if (values) {
		c__[kc] = a[ka] + b[kb];
	    }
	    jc[kc] = j1;
	    ++ka;
	    ++kb;
	    ++kc;
	} else if (j1 < j2) {
	    jc[kc] = j1;
	    if (values) {
		c__[kc] = a[ka];
	    }
	    ++ka;
	    ++kc;
	} else if (j1 > j2) {
	    jc[kc] = j2;
	    if (values) {
		c__[kc] = b[kb];
	    }
	    ++kb;
	    ++kc;
	}
	if (kc > *nzmax) {
	    goto L999;
	}
	if (ka <= kamax || kb <= kbmax) {
	    goto L5;
	}
	ic[i__ + 1] = kc;
/* L6: */
    }
    return 0;
L999:
    *ierr = i__;
    return 0;
/* ------------end-of-aplb1----------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* aplb1_ */

/* Subroutine */ int aplsb_(integer *nrow, integer *ncol, doublereal *a, 
	integer *ja, integer *ia, doublereal *s, doublereal *b, integer *jb, 
	integer *ib, doublereal *c__, integer *jc, integer *ic, integer *
	nzmax, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j1, j2, kc, ka, kb, kamax, kbmax;

/* ----------------------------------------------------------------------- */
/* performs the operation C = A+s B for matrices in sorted CSR format. */
/* the difference with aplsb is that the resulting matrix is such that */
/* the elements of each row are sorted with increasing column indices in */
/* each row, provided the original matrices are sorted in the same way. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A and B */
/* ncol  = integer. The column dimension of A and B. */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format with entries sorted */

/* s	= real. scalar factor for B. */

/* b, */
/* jb, */
/* ib	=  Matrix B in compressed sparse row format with entries sorted */
/*        ascendly in each row */

/* nzmax	= integer. The  length of the arrays c and jc. */
/*         amub will stop if the result matrix C  has a number */
/*         of elements that exceeds exceeds nzmax. See ierr. */

/* on return: */
/* ---------- */
/* c, */
/* jc, */
/* ic	= resulting matrix C in compressed sparse row sparse format */
/*         with entries sorted ascendly in each row. */

/* ierr	= integer. serving as error message. */
/*         ierr = 0 means normal return, */
/*         ierr .gt. 0 means that amub stopped while computing the */
/*         i-th row  of C with i=ierr, because the number */
/*         of elements in C exceeds nzmax. */

/* Notes: */
/* ------- */
/*     this will not work if any of the two input matrices is not sorted */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ic;
    --ib;
    --ia;
    --a;
    --ja;
    --b;
    --jb;
    --c__;
    --jc;

    /* Function Body */
    *ierr = 0;
    kc = 1;
    ic[1] = kc;

/*     the following loop does a merge of two sparse rows + adds  them. */

    i__1 = *nrow;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ka = ia[i__];
	kb = ib[i__];
	kamax = ia[i__ + 1] - 1;
	kbmax = ib[i__ + 1] - 1;
L5:

/*     this is a while  -- do loop -- */

	if (ka <= kamax || kb <= kbmax) {

	    if (ka <= kamax) {
		j1 = ja[ka];
	    } else {
/*     take j1 large enough  that always j2 .lt. j1 */
		j1 = *ncol + 1;
	    }
	    if (kb <= kbmax) {
		j2 = jb[kb];
	    } else {
/*     similarly take j2 large enough  that always j1 .lt. j2 */
		j2 = *ncol + 1;
	    }

/*     three cases */

	    if (j1 == j2) {
		c__[kc] = a[ka] + *s * b[kb];
		jc[kc] = j1;
		++ka;
		++kb;
		++kc;
	    } else if (j1 < j2) {
		jc[kc] = j1;
		c__[kc] = a[ka];
		++ka;
		++kc;
	    } else if (j1 > j2) {
		jc[kc] = j2;
		c__[kc] = *s * b[kb];
		++kb;
		++kc;
	    }
	    if (kc > *nzmax) {
		goto L999;
	    }
	    goto L5;

/*     end while loop */

	}
	ic[i__ + 1] = kc;
/* L6: */
    }
    return 0;
L999:
    *ierr = i__;
    return 0;
/* ------------end-of-aplsb --------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* aplsb_ */

/* Subroutine */ int diamua_(integer *nrow, integer *job, doublereal *a, 
	integer *ja, integer *ia, doublereal *diag, doublereal *b, integer *
	jb, integer *ib)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer k, k1, k2, ii;
    static doublereal scal;

/* ----------------------------------------------------------------------- */
/* performs the matrix by matrix product B = Diag * A  (in place) */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A */

/* job   = integer. job indicator. Job=0 means get array b only */
/*         job = 1 means get b, and the integer arrays ib, jb. */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format. */

/* diag = diagonal matrix stored as a vector dig(1:n) */

/* on return: */
/* ---------- */

/* b, */
/* jb, */
/* ib	= resulting matrix B in compressed sparse row sparse format. */

/* Notes: */
/* ------- */
/* 1)        The column dimension of A is not needed. */
/* 2)        algorithm in place (B can take the place of A). */
/*           in this case use job=0. */
/* ----------------------------------------------------------------- */
    /* Parameter adjustments */
    --ib;
    --diag;
    --ia;
    --a;
    --ja;
    --b;
    --jb;

    /* Function Body */
    i__1 = *nrow;
    for (ii = 1; ii <= i__1; ++ii) {

/*     normalize each row */

	k1 = ia[ii];
	k2 = ia[ii + 1] - 1;
	scal = diag[ii];
	i__2 = k2;
	for (k = k1; k <= i__2; ++k) {
	    b[k] = a[k] * scal;
/* L2: */
	}
/* L1: */
    }

    if (*job == 0) {
	return 0;
    }

    i__1 = *nrow + 1;
    for (ii = 1; ii <= i__1; ++ii) {
	ib[ii] = ia[ii];
/* L3: */
    }
    i__1 = ia[*nrow + 1] - 1;
    for (k = ia[1]; k <= i__1; ++k) {
	jb[k] = ja[k];
/* L31: */
    }
    return 0;
/* ----------end-of-diamua------------------------------------------------ */
/* ----------------------------------------------------------------------- */
} /* diamua_ */

/* Subroutine */ int amudia_(integer *nrow, integer *job, doublereal *a, 
	integer *ja, integer *ia, doublereal *diag, doublereal *b, integer *
	jb, integer *ib)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer k, k1, k2, ii;

/* ----------------------------------------------------------------------- */
/* performs the matrix by matrix product B = A * Diag  (in place) */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A */

/* job   = integer. job indicator. Job=0 means get array b only */
/*         job = 1 means get b, and the integer arrays ib, jb. */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format. */

/* diag = diagonal matrix stored as a vector dig(1:n) */

/* on return: */
/* ---------- */

/* b, */
/* jb, */
/* ib	= resulting matrix B in compressed sparse row sparse format. */

/* Notes: */
/* ------- */
/* 1)        The column dimension of A is not needed. */
/* 2)        algorithm in place (B can take the place of A). */
/* ----------------------------------------------------------------- */
    /* Parameter adjustments */
    --ib;
    --diag;
    --ia;
    --a;
    --ja;
    --b;
    --jb;

    /* Function Body */
    i__1 = *nrow;
    for (ii = 1; ii <= i__1; ++ii) {

/*     scale each element */

	k1 = ia[ii];
	k2 = ia[ii + 1] - 1;
	i__2 = k2;
	for (k = k1; k <= i__2; ++k) {
	    b[k] = a[k] * diag[ja[k]];
/* L2: */
	}
/* L1: */
    }

    if (*job == 0) {
	return 0;
    }

    i__1 = *nrow + 1;
    for (ii = 1; ii <= i__1; ++ii) {
	ib[ii] = ia[ii];
/* L3: */
    }
    i__1 = ia[*nrow + 1] - 1;
    for (k = ia[1]; k <= i__1; ++k) {
	jb[k] = ja[k];
/* L31: */
    }
    return 0;
/* ----------------------------------------------------------------------- */
/* -----------end-of-amudiag---------------------------------------------- */
} /* amudia_ */

/* Subroutine */ int aplsca_(integer *nrow, doublereal *a, integer *ja, 
	integer *ia, doublereal *scal, integer *iw)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, k1, k2, ii, ko;
    static logical test;
    extern /* Subroutine */ int diapos_(integer *, integer *, integer *, 
	    integer *);
    static integer icount;

/* ----------------------------------------------------------------------- */
/* Adds a scalar to the diagonal entries of a sparse matrix A :=A + s I */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A */

/* a, */
/* ja, */
/* ia    = Matrix A in compressed sparse row format. */

/* scal  = real. scalar to add to the diagonal entries. */

/* on return: */
/* ---------- */

/* a, */
/* ja, */
/* ia	= matrix A with diagonal elements shifted (or created). */

/* iw    = integer work array of length n. On return iw will */
/*         contain  the positions of the diagonal entries in the */
/*         output matrix. (i.e., a(iw(k)), ja(iw(k)), k=1,...n, */
/*         are the values/column indices of the diagonal elements */
/*         of the output matrix. ). */

/* Notes: */
/* ------- */
/*     The column dimension of A is not needed. */
/*     important: the matrix a may be expanded slightly to allow for */
/*     additions of nonzero elements to previously nonexisting diagonals. */
/*     The is no checking as to whether there is enough space appended */
/*     to the arrays a and ja. if not sure allow for n additional */
/*     elemnts. */
/*     coded by Y. Saad. Latest version July, 19, 1990 */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --ia;
    --a;
    --ja;
    --iw;

    /* Function Body */
    diapos_(nrow, &ja[1], &ia[1], &iw[1]);
    icount = 0;
    i__1 = *nrow;
    for (j = 1; j <= i__1; ++j) {
	if (iw[j] == 0) {
	    ++icount;
	} else {
	    a[iw[j]] += *scal;
	}
/* L1: */
    }

/*     if no diagonal elements to insert in data structure return. */

    if (icount == 0) {
	return 0;
    }

/* shift the nonzero elements if needed, to allow for created */
/* diagonal elements. */

    ko = ia[*nrow + 1] + icount;

/*     copy rows backward */

    for (ii = *nrow; ii >= 1; --ii) {

/*     go through  row ii */

	k1 = ia[ii];
	k2 = ia[ii + 1] - 1;
	ia[ii + 1] = ko;
	test = iw[ii] == 0;
	i__1 = k1;
	for (k = k2; k >= i__1; --k) {
	    j = ja[k];
	    if (test && j < ii) {
		test = FALSE_;
		--ko;
		a[ko] = *scal;
		ja[ko] = ii;
		iw[ii] = ko;
	    }
	    --ko;
	    a[ko] = a[k];
	    ja[ko] = j;
/* L4: */
	}
/*     diagonal element has not been added yet. */
	if (test) {
	    --ko;
	    a[ko] = *scal;
	    ja[ko] = ii;
	    iw[ii] = ko;
	}
/* L5: */
    }
    ia[1] = ko;
    return 0;
/* ----------------------------------------------------------------------- */
/* ----------end-of-aplsca------------------------------------------------ */
} /* aplsca_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*          BASIC MATRIX-VECTOR OPERATIONS - MATVEC MODULE              c */
/* ----------------------------------------------------------------------c */
/* amux  : A times a vector. Compressed Sparse Row (CSR) format.        c */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int amux_(integer *n, doublereal *x, doublereal *y, 
	doublereal *a, integer *ja, integer *ia)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k;
    static doublereal t;

/* ----------------------------------------------------------------------- */
/*         A times a vector */
/* ----------------------------------------------------------------------- */
/* multiplies a matrix by a vector using the dot product form */
/* Matrix A is stored in compressed sparse row storage. */

/* on entry: */
/* ---------- */
/* n     = row dimension of A */
/* x     = real array of length equal to the column dimension of */
/*         the A matrix. */
/* a, ja, */
/*    ia = input matrix in compressed sparse row format. */

/* on return: */
/* ----------- */
/* y     = real array of length n, containing the product y=Ax */

/* ----------------------------------------------------------------------- */
/* local variables */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ia;
    --ja;
    --a;
    --y;
    --x;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*     compute the inner product of row i with vector x */

	t = 0.;
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    t += a[k] * x[ja[k]];
/* L99: */
	}

/*     store result in y(i) */

	y[i__] = t;
/* L100: */
    }

    return 0;
/* ---------end-of-amux--------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* amux_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*                        INPUT-OUTPUT MODULE                           c */
/* ----------------------------------------------------------------------c */
/*  prtmt  : prints matrices in the Boeing/Harwell format.              c */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int prtmt_(integer *nrow, integer *ncol, doublereal *a, 
	integer *ja, integer *ia, doublereal *rhs, char *guesol, char *title, 
	char *key, char *type__, integer *ifmt, integer *job, integer *iounit,
	 ftnlen guesol_len, ftnlen title_len, ftnlen key_len, ftnlen type_len)
{
    /* Format strings */
    static char fmt_101[] = "(\002(\002,i2,\002I\002,i2,\002)\002)";
    static char fmt_100[] = "(\002(\002,i2,\002I\002,i1,\002)\002)";
    static char fmt_102[] = "(\002(\002,i2,\002F\002,i1,\002.\002,i1,\002"
	    ")\002)";
    static char fmt_103[] = "(\002(\002,i2,\002F\002,i2,\002.\002,i1,\002"
	    ")\002)";
    static char fmt_104[] = "(\002(\002,i2,\002F\002,i2,\002.\002,i2,\002"
	    ")\002)";
    static char fmt_105[] = "(\002(\002,i1,\002D\002,i1,\002.\002,i1,\002"
	    ")\002)";
    static char fmt_106[] = "(\002(\002,i1,\002D\002,i2,\002.\002,i1,\002"
	    ")\002)";
    static char fmt_107[] = "(\002(\002,i1,\002D\002,i2,\002.\002,i2,\002"
	    ")\002)";
    static char fmt_108[] = "(\002(\002,i2,\002D\002,i1,\002.\002,i1,\002"
	    ")\002)";
    static char fmt_109[] = "(\002(\002,i2,\002D\002,i2,\002.\002,i1,\002"
	    ")\002)";
    static char fmt_110[] = "(\002(\002,i2,\002D\002,i2,\002.\002,i2,\002"
	    ")\002)";
    static char fmt_10[] = "(a72,a8/5i14/a3,11x,4i14/2a16,2a20)";
    static char fmt_11[] = "(a3,11x,i14,i14)";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1;
    icilist ici__1;

    /* Builtin functions */
    double r_lg10(real *);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ void s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, ix, len, nnz, iend, nrhs, next, ihead, indcrd, valcrd;
    static char indfmt[16];
    static integer rhscrd;
    static char valfmt[20];
    static integer nperli, totcrd, ptrcrd;
    static char ptrfmt[16], rhstyp[3];
    static integer nrwindx;

    /* Fortran I/O blocks */
    static icilist io___698 = { 0, indfmt, 0, fmt_100, 16, 1 };
    static cilist io___707 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___709 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___710 = { 0, 0, 0, ptrfmt, 0 };
    static cilist io___711 = { 0, 0, 0, indfmt, 0 };
    static cilist io___712 = { 0, 0, 0, valfmt, 0 };
    static cilist io___715 = { 0, 0, 0, valfmt, 0 };
    static cilist io___716 = { 0, 0, 0, valfmt, 0 };
    static cilist io___717 = { 0, 0, 0, valfmt, 0 };


    /* Assigned format variables */
    static char *ix_fmt;

/* ----------------------------------------------------------------------- */
/* writes a matrix in Harwell-Boeing format into a file. */
/* assumes that the matrix is stored in COMPRESSED SPARSE COLUMN FORMAT. */
/* some limited functionality for right hand sides. */
/* Author: Youcef Saad - Date: Sept., 1989 - updated Oct. 31, 1989 to */
/* cope with new format. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow   = number of rows in matrix */
/* ncol	 = number of columns in matrix */
/* a	 = real*8 array containing the values of the matrix stored */
/*          columnwise */
/* ja 	 = integer array of the same length as a containing the column */
/*          indices of the corresponding matrix elements of array a. */
/* ia     = integer array of containing the pointers to the beginning of */
/* 	   the row in arrays a and ja. */
/* rhs    = real array  containing the right-hand-side (s) and optionally */
/*          the associated initial guesses and/or exact solutions */
/*          in this order. See also guesol for details. the vector rhs will */
/*          be used only if job .gt. 2 (see below). Only full storage for */
/*          the right hand sides is supported. */

/* guesol = a 2-character string indicating whether an initial guess */
/*          (1-st character) and / or the exact solution (2-nd) */
/*          character) is provided with the right hand side. */
/* 	   if the first character of guesol is 'G' it means that an */
/*          an intial guess is provided for each right-hand sides. */
/*          These are assumed to be appended to the right hand-sides in */
/*          the array rhs. */
/* 	   if the second character of guesol is 'X' it means that an */
/*          exact solution is provided for each right-hand side. */
/*          These are assumed to be appended to the right hand-sides */
/*          and the initial guesses (if any) in the array rhs. */

/* title  = character*72 = title of matrix test ( character a*72 ). */
/* key    = character*8  = key of matrix */
/* type   = charatcer*3  = type of matrix. */

/* ifmt	 = integer specifying the format chosen for the real values */
/* 	   to be output (i.e., for a, and for rhs-guess-sol if */
/*          applicable). The meaning of ifmt is as follows. */
/* 	  * if (ifmt .lt. 100) then the D descriptor is used, */
/*           format Dd.m, in which the length (m) of the mantissa is */
/*           precisely the integer ifmt (and d = ifmt+6) */
/* 	  * if (ifmt .gt. 100) then prtmt will use the */
/*           F- descriptor (format Fd.m) in which the length of the */
/*           mantissa (m) is the integer mod(ifmt,100) and the length */
/*           of the integer part is k=ifmt/100 (and d = k+m+2) */
/* 	    Thus  ifmt= 4   means  D10.4  +.xxxxD+ee    while */
/* 	          ifmt=104  means  F7.4   +x.xxxx */
/* 	          ifmt=205  means  F9.5   +xx.xxxxx */
/* 	    Note: formats for ja, and ia are internally computed. */

/* job	 = integer to indicate whether matrix values and */
/* 	   a right-hand-side is available to be written */
/*          job = 1   write srtucture only, i.e., the arrays ja and ia. */
/*          job = 2   write matrix including values, i.e., a, ja, ia */
/*          job = 3   write matrix and one right hand side: a,ja,ia,rhs. */
/* 	   job = nrhs+2 write matrix and nrhs successive right hand sides */
/* 	   Note that there cannot be any right-hand-side if the matrix */
/* 	   has no values. Also the initial guess and exact solutions when */
/*          provided are for each right hand side. For example if nrhs=2 */
/*          and guesol='GX' there are 6 vectors to write. */


/* iounit = logical unit number where to write the matrix into. */

/* on return: */
/* ---------- */
/* the matrix a, ja, ia will be written in output unit iounit */
/* in the Harwell-Boeing format. None of the inputs is modofied. */

/* Notes: 1) This code attempts to pack as many elements as possible per */
/*        80-character line. */
/*        2) this code attempts to avoid as much as possible to put */
/*        blanks in the formats that are written in the 4-line header */
/* 	 (This is done for purely esthetical reasons since blanks */
/*        are ignored in format descriptors.) */
/*        3) sparse formats for right hand sides and guesses are not */
/*        supported. */
/* ----------------------------------------------------------------------- */
/* -------------- */
/*     compute pointer format */
/* -------------- */
    /* Parameter adjustments */
    --rhs;
    --ia;
    --ja;
    --a;

    /* Function Body */
    nnz = ia[*ncol + 1] - 1;
    r__1 = (real) (nnz + 1) + .1f;
    len = (integer) r_lg10(&r__1) + 1;
    nperli = 80 / len;
    ptrcrd = *ncol / nperli + 1;
    if (len > 9) {
	ix = 0;
	ix_fmt = fmt_101;
    } else {
	ix = 1;
	ix_fmt = fmt_100;
    }
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 16;
    ici__1.iciunit = ptrfmt;
    ici__1.icifmt = ix_fmt;
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&nperli, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&len, (ftnlen)sizeof(integer));
    e_wsfi();
L100:
L101:
/* ---------------------------- */
/* compute ROW index format */
/* ---------------------------- */
    r__1 = (real) (*nrow) + .1f;
    len = (integer) r_lg10(&r__1) + 1;
/* Computing MIN */
    i__1 = 80 / len;
    nperli = min(i__1,nnz);
    indcrd = (nnz - 1) / nperli + 1;
    s_wsfi(&io___698);
    do_fio(&c__1, (char *)&nperli, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&len, (ftnlen)sizeof(integer));
    e_wsfi();
/* --------------- */
/* compute values and rhs format (using the same for both) */
/* --------------- */
    valcrd = 0;
    rhscrd = 0;
/* quit this part if no values provided. */
    if (*job <= 1) {
	goto L20;
    }

    if (*ifmt >= 100) {
	ihead = *ifmt / 100;
	*ifmt -= ihead * 100;
	len = ihead + *ifmt + 2;
	nperli = 80 / len;

	if (len <= 9) {
	    ix = 2;
	    ix_fmt = fmt_102;
	} else if (*ifmt <= 9) {
	    ix = 3;
	    ix_fmt = fmt_103;
	} else {
	    ix = 4;
	    ix_fmt = fmt_104;
	}

	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 20;
	ici__1.iciunit = valfmt;
	ici__1.icifmt = ix_fmt;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&nperli, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&len, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*ifmt), (ftnlen)sizeof(integer));
	e_wsfi();
L102:
L103:
L104:

	;
    } else {
	len = *ifmt + 6;
	nperli = 80 / len;
/*     try to minimize the blanks in the format strings. */
	if (nperli <= 9) {
	    if (len <= 9) {
		ix = 5;
		ix_fmt = fmt_105;
	    } else if (*ifmt <= 9) {
		ix = 6;
		ix_fmt = fmt_106;
	    } else {
		ix = 7;
		ix_fmt = fmt_107;
	    }
	} else {
	    if (len <= 9) {
		ix = 8;
		ix_fmt = fmt_108;
	    } else if (*ifmt <= 9) {
		ix = 9;
		ix_fmt = fmt_109;
	    } else {
		ix = 10;
		ix_fmt = fmt_110;
	    }
	}
/* ----------- */
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 20;
	ici__1.iciunit = valfmt;
	ici__1.icifmt = ix_fmt;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&nperli, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&len, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*ifmt), (ftnlen)sizeof(integer));
	e_wsfi();
L105:
L106:
L107:
L108:
L109:
L110:

	;
    }
    valcrd = (nnz - 1) / nperli + 1;
    nrhs = *job - 2;
    if (nrhs >= 1) {
	i__ = (nrhs * *nrow - 1) / nperli + 1;
	rhscrd = i__;
	if (*(unsigned char *)guesol == 'G' || *(unsigned char *)guesol == 
		'g') {
	    rhscrd += i__;
	}
	if (*(unsigned char *)&guesol[1] == 'X' || *(unsigned char *)&guesol[
		1] == 'x') {
	    rhscrd += i__;
	}
/* Writing concatenation */
	i__2[0] = 1, a__1[0] = "F";
	i__2[1] = 2, a__1[1] = guesol;
	s_cat(rhstyp, a__1, i__2, &c__2, (ftnlen)3);
    }
L20:

    totcrd = ptrcrd + indcrd + valcrd + rhscrd;
/*     write 4-line or five line header */
    io___707.ciunit = *iounit;
    s_wsfe(&io___707);
    do_fio(&c__1, title, (ftnlen)72);
    do_fio(&c__1, key, (ftnlen)8);
    do_fio(&c__1, (char *)&totcrd, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ptrcrd, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&indcrd, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&valcrd, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&rhscrd, (ftnlen)sizeof(integer));
    do_fio(&c__1, type__, (ftnlen)3);
    do_fio(&c__1, (char *)&(*nrow), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ncol), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nnz, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nrhs, (ftnlen)sizeof(integer));
    do_fio(&c__1, ptrfmt, (ftnlen)16);
    do_fio(&c__1, indfmt, (ftnlen)16);
    do_fio(&c__1, valfmt, (ftnlen)20);
    do_fio(&c__1, valfmt, (ftnlen)20);
    e_wsfe();
/* ----------------------------------------------------------------------- */
    nrwindx = 0;
    if (nrhs >= 1) {
	io___709.ciunit = *iounit;
	s_wsfe(&io___709);
	do_fio(&c__1, rhstyp, (ftnlen)3);
	do_fio(&c__1, (char *)&nrhs, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nrwindx, (ftnlen)sizeof(integer));
	e_wsfe();
    }

    io___710.ciunit = *iounit;
    s_wsfe(&io___710);
    i__1 = *ncol + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ia[i__], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    io___711.ciunit = *iounit;
    s_wsfe(&io___711);
    i__1 = nnz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&ja[i__], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    if (*job <= 1) {
	return 0;
    }
    io___712.ciunit = *iounit;
    s_wsfe(&io___712);
    i__1 = nnz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (*job <= 2) {
	return 0;
    }
    len = *nrow * nrhs;
    next = 1;
    iend = len;
    io___715.ciunit = *iounit;
    s_wsfe(&io___715);
    i__1 = iend;
    for (i__ = next; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&rhs[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

/*     write initial guesses if available */

    if (*(unsigned char *)guesol == 'G' || *(unsigned char *)guesol == 'g') {
	next += len;
	iend += len;
	io___716.ciunit = *iounit;
	s_wsfe(&io___716);
	i__1 = iend;
	for (i__ = next; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&rhs[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }

/*     write exact solutions if available */

    if (*(unsigned char *)&guesol[1] == 'X' || *(unsigned char *)&guesol[1] ==
	     'x') {
	next += len;
	iend += len;
	io___717.ciunit = *iounit;
	s_wsfe(&io___717);
	i__1 = iend;
	for (i__ = next; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&rhs[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }

    return 0;
/* ----------end of prtmt ------------------------------------------------ */
/* ----------------------------------------------------------------------- */
} /* prtmt_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*                    FORMAT CONVERSION MODULE                          c */
/* ----------------------------------------------------------------------c */
/* csrdns  : converts a row-stored sparse matrix into the dense format. c */
/* coocsr  : converts coordinate to  to csr format                      c */
/* coicsr  : in-place conversion of coordinate to csr format            c */
/* csrcoo  : converts compressed sparse row to coordinate.              c */
/* csrcsc  : converts compressed sparse row format to compressed sparse c */
/*           column format (transposition)                              c */
/* csrcsc2 : rectangular version of csrcsc                              c */
/* csrdia  : converts a compressed sparse row format into a diagonal    c */
/*           format.                                                    c */
/* csrbnd  : converts a compressed sparse row format into a banded      c */
/*           format (linpack style).                                    c */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int csrdns_(integer *nrow, integer *ncol, doublereal *a, 
	integer *ja, integer *ia, doublereal *dns, integer *ndns, integer *
	ierr)
{
    /* System generated locals */
    integer dns_dim1, dns_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, k;

/* ----------------------------------------------------------------------- */
/* Compressed Sparse Row    to    Dense */
/* ----------------------------------------------------------------------- */

/* converts a row-stored sparse matrix into a densely stored one */

/* On entry: */
/* ---------- */

/* nrow	= row-dimension of a */
/* ncol	= column dimension of a */
/* a, */
/* ja, */
/* ia    = input matrix in compressed sparse row format. */
/*         (a=value array, ja=column array, ia=pointer array) */
/* dns   = array where to store dense matrix */
/* ndns	= first dimension of array dns */

/* on return: */
/* ----------- */
/* dns   = the sparse matrix a, ja, ia has been stored in dns(ndns,*) */

/* ierr  = integer error indicator. */
/*         ierr .eq. 0  means normal return */
/*         ierr .eq. i  means that the code has stopped when processing */
/*         row number i, because it found a column number .gt. ncol. */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --a;
    --ja;
    --ia;
    dns_dim1 = *ndns;
    dns_offset = 1 + dns_dim1;
    dns -= dns_offset;

    /* Function Body */
    *ierr = 0;
    i__1 = *nrow;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *ncol;
	for (j = 1; j <= i__2; ++j) {
	    dns[i__ + j * dns_dim1] = 0.;
/* L2: */
	}
/* L1: */
    }

    i__1 = *nrow;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k];
	    if (j > *ncol) {
		*ierr = i__;
		return 0;
	    }
	    dns[i__ + j * dns_dim1] = a[k];
/* L3: */
	}
/* L4: */
    }
    return 0;
/* ---- end of csrdns ---------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* csrdns_ */

/* Subroutine */ int coocsr_(integer *nrow, integer *nnz, doublereal *a, 
	integer *ir, integer *jc, doublereal *ao, integer *jao, integer *iao)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k;
    static doublereal x;
    static integer k0, iad;

/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
/*  Coordinate     to   Compressed Sparse Row */
/* ----------------------------------------------------------------------- */
/* converts a matrix that is stored in coordinate format */
/*  a, ir, jc into a row general sparse ao, jao, iao format. */

/* on entry: */
/* --------- */
/* nrow	= dimension of the matrix */
/* nnz	= number of nonzero elements in matrix */
/* a, */
/* ir, */
/* jc    = matrix in coordinate format. a(k), ir(k), jc(k) store the nnz */
/*         nonzero elements of the matrix with a(k) = actual real value of */
/* 	  the elements, ir(k) = its row number and jc(k) = its column */
/* 	  number. The order of the elements is arbitrary. */

/* on return: */
/* ----------- */
/* ir 	is destroyed */

/* ao, jao, iao = matrix in general sparse matrix format with ao */
/* 	continung the real values, jao containing the column indices, */
/* 	and iao being the pointer to the beginning of the row, */
/* 	in arrays ao, jao. */

/* Notes: */
/* ------ This routine is NOT in place.  See coicsr */

/* ------------------------------------------------------------------------ */
    /* Parameter adjustments */
    --iao;
    --jao;
    --ao;
    --jc;
    --ir;
    --a;

    /* Function Body */
    i__1 = *nrow + 1;
    for (k = 1; k <= i__1; ++k) {
	iao[k] = 0;
/* L1: */
    }
/* determine row-lengths. */
    i__1 = *nnz;
    for (k = 1; k <= i__1; ++k) {
	++iao[ir[k]];
/* L2: */
    }
/* starting position of each row.. */
    k = 1;
    i__1 = *nrow + 1;
    for (j = 1; j <= i__1; ++j) {
	k0 = iao[j];
	iao[j] = k;
	k += k0;
/* L3: */
    }
/* go through the structure  once more. Fill in output matrix. */
    i__1 = *nnz;
    for (k = 1; k <= i__1; ++k) {
	i__ = ir[k];
	j = jc[k];
	x = a[k];
	iad = iao[i__];
	ao[iad] = x;
	jao[iad] = j;
	iao[i__] = iad + 1;
/* L4: */
    }
/* shift back iao */
    for (j = *nrow; j >= 1; --j) {
	iao[j + 1] = iao[j];
/* L5: */
    }
    iao[1] = 1;
    return 0;
/* ------------- end of coocsr ------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* coocsr_ */

/* Subroutine */ int coicsr_(integer *n, integer *nnz, integer *job, 
	doublereal *a, integer *ja, integer *ia, integer *iwk)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k;
    static doublereal t;
    static integer init, ipos, inext, jnext;
    static doublereal tnext;
    static logical values;

/* ------------------------------------------------------------------------ */
/* IN-PLACE coo-csr conversion routine. */
/* ------------------------------------------------------------------------ */
/* this subroutine converts a matrix stored in coordinate format into */
/* the csr format. The conversion is done in place in that the arrays */
/* a,ja,ia of the result are overwritten onto the original arrays. */
/* ------------------------------------------------------------------------ */
/* on entry: */
/* --------- */
/* n	= integer. row dimension of A. */
/* nnz	= integer. number of nonzero elements in A. */
/* job   = integer. Job indicator. when job=1, the real values in a are */
/*         filled. Otherwise a is not touched and the structure of the */
/*         array only (i.e. ja, ia)  is obtained. */
/* a	= real array of size nnz (number of nonzero elements in A) */
/*         containing the nonzero elements */
/* ja	= integer array of length nnz containing the column positions */
/* 	  of the corresponding elements in a. */
/* ia	= integer array of length nnz containing the row positions */
/* 	  of the corresponding elements in a. */
/* iwk	= integer work array of length n+1 */
/* on return: */
/* ---------- */
/* a */
/* ja */
/* ia	= contains the compressed sparse row data structure for the */
/*         resulting matrix. */
/* Note: */
/* ------- */
/*         the entries of the output matrix are not sorted (the column */
/*         indices in each are not in increasing order) use coocsr */
/*         if you want them sorted. */
/* ----------------------------------------------------------------------c */
/*  Coded by Y. Saad, Sep. 26 1989                                      c */
/* ----------------------------------------------------------------------c */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --iwk;
    --ia;
    --ja;
    --a;

    /* Function Body */
    values = *job == 1;
/* find pointer array for resulting matrix. */
    i__1 = *n + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iwk[i__] = 0;
/* L35: */
    }
    i__1 = *nnz;
    for (k = 1; k <= i__1; ++k) {
	i__ = ia[k];
	++iwk[i__ + 1];
/* L4: */
    }
/* ------------------------------------------------------------------------ */
    iwk[1] = 1;
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	iwk[i__] = iwk[i__ - 1] + iwk[i__];
/* L44: */
    }

/*     loop for a cycle in chasing process. */

    init = 1;
    k = 0;
L5:
    if (values) {
	t = a[init];
    }
    i__ = ia[init];
    j = ja[init];
    ia[init] = -1;
/* ------------------------------------------------------------------------ */
L6:
    ++k;
/*     current row number is i.  determine  where to go. */
    ipos = iwk[i__];
/*     save the chased element. */
    if (values) {
	tnext = a[ipos];
    }
    inext = ia[ipos];
    jnext = ja[ipos];
/*     then occupy its location. */
    if (values) {
	a[ipos] = t;
    }
    ja[ipos] = j;
/*     update pointer information for next element to come in row i. */
    iwk[i__] = ipos + 1;
/*     determine  next element to be chased, */
    if (ia[ipos] < 0) {
	goto L65;
    }
    t = tnext;
    i__ = inext;
    j = jnext;
    ia[ipos] = -1;
    if (k < *nnz) {
	goto L6;
    }
    goto L70;
L65:
    ++init;
    if (init > *nnz) {
	goto L70;
    }
    if (ia[init] < 0) {
	goto L65;
    }
/*     restart chasing -- */
    goto L5;
L70:
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia[i__ + 1] = iwk[i__];
/* L80: */
    }
    ia[1] = 1;
    return 0;
/* ----------------- end of coicsr ---------------------------------------- */
/* ------------------------------------------------------------------------ */
} /* coicsr_ */

/* Subroutine */ int csrcoo_(integer *nrow, integer *job, integer *nzmax, 
	doublereal *a, integer *ja, integer *ia, integer *nnz, doublereal *ao,
	 integer *ir, integer *jc, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, k1, k2;

/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------- */
/*  Compressed Sparse Row      to      Coordinate */
/* ----------------------------------------------------------------------- */
/* converts a matrix that is stored in coordinate format */
/*  a, ir, jc into a row general sparse ao, jao, iao format. */

/* on entry: */
/* --------- */
/* nrow	= dimension of the matrix. */
/* job   = integer serving as a job indicator. */
/*         if job = 1 fill in only the array ir, ignore jc, and ao. */
/*         if job = 2 fill in ir, and jc but not ao */
/*         if job = 3 fill in everything. */
/*         The reason why these options are provided is that on return */
/*         ao and jc are the same as a, ja. So when job = 3, a and ja are */
/*         simply copied into ao, jc.  When job=2, only jc and ir are */
/*         returned. With job=1 only the array ir is returned. Moreover, */
/*         the algorithm is in place: */
/* 	     call csrcoo (nrow,1,nzmax,a,ja,ia,nnz,a,ia,ja,ierr) */
/*         will write the output matrix in coordinate format on a, ja,ia. */

/* a, */
/* ja, */
/* ia    = matrix in compressed sparse row format. */
/* nzmax = length of space available in ao, ir, jc. */
/*         the code will stop immediatly if the number of */
/*         nonzero elements found in input matrix exceeds nzmax. */

/* on return: */
/* ----------- */
/* ao, ir, jc = matrix in coordinate format. */

/* nnz        = number of nonzero elements in matrix. */
/* ierr       = integer error indicator. */
/*         ierr .eq. 0 means normal retur */
/*         ierr .eq. 1 means that the the code stopped */
/*         because there was no space in ao, ir, jc */
/*         (according to the value of  nzmax). */

/* NOTES: 1)This routine is PARTIALLY in place: csrcoo can be called with */
/*         ao being the same array as as a, and jc the same array as ja. */
/*         but ir CANNOT be the same as ia. */
/*         2) note the order in the output arrays, */
/* ------------------------------------------------------------------------ */
    /* Parameter adjustments */
    --ia;
    --a;
    --ja;
    --ao;
    --ir;
    --jc;

    /* Function Body */
    *ierr = 0;
    *nnz = ia[*nrow + 1] - 1;
    if (*nnz > *nzmax) {
	*ierr = 1;
	return 0;
    }
/* ------------------------------------------------------------------------ */
    switch (*job) {
	case 1:  goto L3;
	case 2:  goto L2;
	case 3:  goto L1;
    }
L1:
    i__1 = *nnz;
    for (k = 1; k <= i__1; ++k) {
	ao[k] = a[k];
/* L10: */
    }
L2:
    i__1 = *nnz;
    for (k = 1; k <= i__1; ++k) {
	jc[k] = ja[k];
/* L11: */
    }

/*     copy backward to allow for in-place processing. */

L3:
    for (i__ = *nrow; i__ >= 1; --i__) {
	k1 = ia[i__ + 1] - 1;
	k2 = ia[i__];
	i__1 = k2;
	for (k = k1; k >= i__1; --k) {
	    ir[k] = i__;
/* L12: */
	}
/* L13: */
    }
    return 0;
/* ------------- end-of-csrcoo ------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* csrcoo_ */

/* Subroutine */ int csrcsc_(integer *n, integer *job, integer *ipos, 
	doublereal *a, integer *ja, integer *ia, doublereal *ao, integer *jao,
	 integer *iao)
{
    extern /* Subroutine */ int csrcsc2_(integer *, integer *, integer *, 
	    integer *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, integer *);

/* ----------------------------------------------------------------------- */
/* Compressed Sparse Row     to      Compressed Sparse Column */

/* (transposition operation)   Not in place. */
/* ----------------------------------------------------------------------- */
/* -- not in place -- */
/* this subroutine transposes a matrix stored in a, ja, ia format. */
/* --------------- */
/* on entry: */
/* ---------- */
/* n	= dimension of A. */
/* job	= integer to indicate whether to fill the values (job.eq.1) of the */
/*         matrix ao or only the pattern., i.e.,ia, and ja (job .ne.1) */

/* ipos  = starting position in ao, jao of the transposed matrix. */
/*         the iao array takes this into account (thus iao(1) is set to ipos.) */
/*         Note: this may be useful if one needs to append the data structure */
/*         of the transpose to that of A. In this case use for example */
/*                call csrcsc (n,1,ia(n+1),a,ja,ia,a,ja,ia(n+2)) */
/* 	  for any other normal usage, enter ipos=1. */
/* a	= real array of length nnz (nnz=number of nonzero elements in input */
/*         matrix) containing the nonzero elements. */
/* ja	= integer array of length nnz containing the column positions */
/* 	  of the corresponding elements in a. */
/* ia	= integer of size n+1. ia(k) contains the position in a, ja of */
/* 	  the beginning of the k-th row. */

/* on return: */
/* ---------- */
/* output arguments: */
/* ao	= real array of size nzz containing the "a" part of the transpose */
/* jao	= integer array of size nnz containing the column indices. */
/* iao	= integer array of size n+1 containing the "ia" index array of */
/* 	  the transpose. */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --iao;
    --ia;
    --a;
    --ja;
    --ao;
    --jao;

    /* Function Body */
    csrcsc2_(n, n, job, ipos, &a[1], &ja[1], &ia[1], &ao[1], &jao[1], &iao[1])
	    ;
    return 0;
} /* csrcsc_ */

/* Subroutine */ int csrcsc2_(integer *n, integer *n2, integer *job, integer *
	ipos, doublereal *a, integer *ja, integer *ia, doublereal *ao, 
	integer *jao, integer *iao)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k, next;

/* ----------------------------------------------------------------------- */
/* Compressed Sparse Row     to      Compressed Sparse Column */

/* (transposition operation)   Not in place. */
/* ----------------------------------------------------------------------- */
/* Rectangular version.  n is number of rows of CSR matrix, */
/*                       n2 (input) is number of columns of CSC matrix. */
/* ----------------------------------------------------------------------- */
/* -- not in place -- */
/* this subroutine transposes a matrix stored in a, ja, ia format. */
/* --------------- */
/* on entry: */
/* ---------- */
/* n	= number of rows of CSR matrix. */
/* n2    = number of columns of CSC matrix. */
/* job	= integer to indicate whether to fill the values (job.eq.1) of the */
/*         matrix ao or only the pattern., i.e.,ia, and ja (job .ne.1) */

/* ipos  = starting position in ao, jao of the transposed matrix. */
/*         the iao array takes this into account (thus iao(1) is set to ipos.) */
/*         Note: this may be useful if one needs to append the data structure */
/*         of the transpose to that of A. In this case use for example */
/*                call csrcsc2 (n,n,1,ia(n+1),a,ja,ia,a,ja,ia(n+2)) */
/* 	  for any other normal usage, enter ipos=1. */
/* a	= real array of length nnz (nnz=number of nonzero elements in input */
/*         matrix) containing the nonzero elements. */
/* ja	= integer array of length nnz containing the column positions */
/* 	  of the corresponding elements in a. */
/* ia	= integer of size n+1. ia(k) contains the position in a, ja of */
/* 	  the beginning of the k-th row. */

/* on return: */
/* ---------- */
/* output arguments: */
/* ao	= real array of size nzz containing the "a" part of the transpose */
/* jao	= integer array of size nnz containing the column indices. */
/* iao	= integer array of size n+1 containing the "ia" index array of */
/* 	  the transpose. */

/* ----------------------------------------------------------------------- */
/* ----------------- compute lengths of rows of transp(A) ---------------- */
    /* Parameter adjustments */
    --ia;
    --iao;
    --a;
    --ja;
    --ao;
    --jao;

    /* Function Body */
    i__1 = *n2 + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iao[i__] = 0;
/* L1: */
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k] + 1;
	    ++iao[j];
/* L2: */
	}
/* L3: */
    }
/* ---------- compute pointers from lengths ------------------------------ */
    iao[1] = *ipos;
    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iao[i__ + 1] = iao[i__] + iao[i__ + 1];
/* L4: */
    }
/* --------------- now do the actual copying ----------------------------- */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k];
	    next = iao[j];
	    if (*job == 1) {
		ao[next] = a[k];
	    }
	    jao[next] = i__;
	    iao[j] = next + 1;
/* L62: */
	}
/* L6: */
    }
/* -------------------------- reshift iao and leave ---------------------- */
    for (i__ = *n2; i__ >= 1; --i__) {
	iao[i__ + 1] = iao[i__];
/* L7: */
    }
    iao[1] = *ipos;
/* --------------- end of csrcsc2 ---------------------------------------- */
/* ----------------------------------------------------------------------- */
    return 0;
} /* csrcsc2_ */

/* Subroutine */ int csrdia_(integer *n, integer *idiag, integer *job, 
	doublereal *a, integer *ja, integer *ia, integer *ndiag, doublereal *
	diag, integer *ioff, doublereal *ao, integer *jao, integer *iao, 
	integer *ind)
{
    /* System generated locals */
    integer diag_dim1, diag_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, n2, ii, ko, job1, job2, idum, jmax;
    extern /* Subroutine */ int infdia_(integer *, integer *, integer *, 
	    integer *, integer *);

/* ----------------------------------------------------------------------- */
/* Compressed sparse row     to    diagonal format */
/* ----------------------------------------------------------------------- */
/* this subroutine extracts  idiag diagonals  from the  input matrix a, */
/* a, ia, and puts the rest of  the matrix  in the  output matrix ao, */
/* jao, iao.  The diagonals to be extracted depend  on the  value of job */
/* (see below for details.)  In  the first  case, the  diagonals to be */
/* extracted are simply identified by  their offsets  provided in ioff */
/* by the caller.  In the second case, the  code internally determines */
/* the idiag most significant diagonals, i.e., those  diagonals of the */
/* matrix which  have  the  largest  number  of  nonzero elements, and */
/* extracts them. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* n	= dimension of the matrix a. */
/* idiag = integer equal to the number of diagonals to be extracted. */
/*         Note: on return idiag may be modified. */
/* a, ja, */
/*    ia = matrix stored in a, ja, ia, format */
/* job	= integer. serves as a job indicator.  Job is better thought */
/*         of as a two-digit number job=xy. If the first (x) digit */
/*         is one on entry then the diagonals to be extracted are */
/*         internally determined. In this case csrdia exctracts the */
/*         idiag most important diagonals, i.e. those having the largest */
/*         number on nonzero elements. If the first digit is zero */
/*         then csrdia assumes that ioff(*) contains the offsets */
/*         of the diagonals to be extracted. there is no verification */
/*         that ioff(*) contains valid entries. */
/*         The second (y) digit of job determines whether or not */
/*         the remainder of the matrix is to be written on ao,jao,iao. */
/*         If it is zero  then ao, jao, iao is not filled, i.e., */
/*         the diagonals are found  and put in array diag and the rest is */
/*         is discarded. if it is one, ao, jao, iao contains matrix */
/*         of the remaining elements. */
/*         Thus: */
/*         job= 0 means do not select diagonals internally (pick those */
/*                defined by ioff) and do not fill ao,jao,iao */
/*         job= 1 means do not select diagonals internally */
/*                      and fill ao,jao,iao */
/*         job=10 means  select diagonals internally */
/*                      and do not fill ao,jao,iao */
/*         job=11 means select diagonals internally */
/*                      and fill ao,jao,iao */

/* ndiag = integer equal to the first dimension of array diag. */

/* on return: */
/* ----------- */

/* idiag = number of diagonals found. This may be smaller than its value */
/*         on entry. */
/* diag  = real array of size (ndiag x idiag) containing the diagonals */
/*         of A on return */

/* ioff  = integer array of length idiag, containing the offsets of the */
/*   	  diagonals to be extracted. */
/* ao, jao */
/*  iao  = remainder of the matrix in a, ja, ia format. */
/* work arrays: */
/* ------------ */
/* ind   = integer array of length 2*n-1 used as integer work space. */
/*         needed only when job.ge.10 i.e., in case the diagonals are to */
/*         be selected internally. */

/* Notes: */
/* ------- */
/*    1) The algorithm is in place: ao, jao, iao can be overwritten on */
/*       a, ja, ia if desired */
/*    2) When the code is required to select the diagonals (job .ge. 10) */
/*       the selection of the diagonals is done from left to right */
/*       as a result if several diagonals have the same weight (number */
/*       of nonzero elemnts) the leftmost one is selected first. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --a;
    --ja;
    --ia;
    diag_dim1 = *ndiag;
    diag_offset = 1 + diag_dim1;
    diag -= diag_offset;
    --ioff;
    --ao;
    --jao;
    --iao;
    --ind;

    /* Function Body */
    job1 = *job / 10;
    job2 = *job - job1 * 10;
    if (job1 == 0) {
	goto L50;
    }
    n2 = *n + *n - 1;
    infdia_(n, &ja[1], &ia[1], &ind[1], &idum);
/* ----------- determine diagonals to  accept.---------------------------- */
/* ----------------------------------------------------------------------- */
    ii = 0;
L4:
    ++ii;
    jmax = 0;
    i__1 = n2;
    for (k = 1; k <= i__1; ++k) {
	j = ind[k];
	if (j <= jmax) {
	    goto L41;
	}
	i__ = k;
	jmax = j;
L41:
	;
    }
    if (jmax <= 0) {
	--ii;
	goto L42;
    }
    ioff[ii] = i__ - *n;
    ind[i__] = -jmax;
    if (ii < *idiag) {
	goto L4;
    }
L42:
    *idiag = ii;
/* ---------------- initialize diago to zero ----------------------------- */
L50:
    i__1 = *idiag;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    diag[i__ + j * diag_dim1] = 0.;
/* L54: */
	}
/* L55: */
    }
/* ----------------------------------------------------------------------- */
    ko = 1;
/* ----------------------------------------------------------------------- */
/* extract diagonals and accumulate remaining matrix. */
/* ----------------------------------------------------------------------- */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k];
	    i__3 = *idiag;
	    for (l = 1; l <= i__3; ++l) {
		if (j - i__ != ioff[l]) {
		    goto L52;
		}
		diag[i__ + l * diag_dim1] = a[k];
		goto L51;
L52:
		;
	    }
/* --------------- append element not in any diagonal to ao,jao,iao ----- */
	    if (job2 == 0) {
		goto L51;
	    }
	    ao[ko] = a[k];
	    jao[ko] = j;
	    ++ko;
L51:
	    ;
	}
	if (job2 != 0) {
	    ind[i__ + 1] = ko;
	}
/* L6: */
    }
    if (job2 == 0) {
	return 0;
    }
/*     finish with iao */
    iao[1] = 1;
    i__1 = *n + 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	iao[i__] = ind[i__];
/* L7: */
    }
    return 0;
/* ----------- end of csrdia --------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* csrdia_ */

/* Subroutine */ int csrbnd_(integer *n, doublereal *a, integer *ja, integer *
	ia, integer *job, doublereal *abd, integer *nabd, integer *lowd, 
	integer *ml, integer *mu, integer *ierr)
{
    /* System generated locals */
    integer abd_dim1, abd_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, k, m, ii, mdiag;
    extern /* Subroutine */ int getbwd_(integer *, doublereal *, integer *, 
	    integer *, integer *, integer *);

/* ----------------------------------------------------------------------- */
/*   Compressed Sparse Row  to  Banded (Linpack ) format. */
/* ----------------------------------------------------------------------- */
/* this subroutine converts a general sparse matrix stored in */
/* compressed sparse row format into the banded format. for the */
/* banded format,the Linpack conventions are assumed (see below). */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* n	= integer,the actual row dimension of the matrix. */

/* a, */
/* ja, */
/* ia    = input matrix stored in compressed sparse row format. */

/* job	= integer. if job=1 then the values of the lower bandwith ml */
/*         and the upper bandwidth mu are determined internally. */
/*         otherwise it is assumed that the values of ml and mu */
/*         are the correct bandwidths on input. See ml and mu below. */

/* nabd  = integer. first dimension of array abd. */

/* lowd  = integer. this should be set to the row number in abd where */
/*         the lowest diagonal (leftmost) of A is located. */
/*         lowd should be  ( 1  .le.  lowd  .le. nabd). */
/*         if it is not known in advance what lowd should be */
/*         enter lowd = 0 and the default value lowd = ml+mu+1 */
/*         will be chosen. Alternative: call routine getbwd from unary */
/*         first to detrermione ml and mu then define lowd accordingly. */
/*         (Note: the banded solvers in linpack use lowd=2*ml+mu+1. ) */

/* ml	= integer. equal to the bandwidth of the strict lower part of A */
/* mu	= integer. equal to the bandwidth of the strict upper part of A */
/*         thus the total bandwidth of A is ml+mu+1. */
/*         if ml+mu+1 is found to be larger than lowd then an error */
/*         flag is raised (unless lowd = 0). see ierr. */

/* note:   ml and mu are assumed to have	 the correct bandwidth values */
/*         as defined above if job is set to zero on entry. */

/* on return: */
/* ----------- */

/* abd   = real array of dimension abd(nabd,n). */
/*         on return contains the values of the matrix stored in */
/*         banded form. The j-th column of abd contains the elements */
/*         of the j-th column of  the original matrix comprised in the */
/*         band ( i in (j-ml,j+mu) ) with the lowest diagonal at */
/*         the bottom row (row lowd). See details below for this format. */

/* ml	= integer. equal to the bandwidth of the strict lower part of A */
/* mu	= integer. equal to the bandwidth of the strict upper part of A */
/*         if job=1 on entry then these two values are internally computed. */

/* lowd  = integer. row number in abd where the lowest diagonal */
/*         (leftmost) of A is located on return. In case lowd = 0 */
/*         on return, then it is defined to ml+mu+1 on return and the */
/*         lowd will contain this value on return. ` */

/* ierr  = integer. used for error messages. On return: */
/*         ierr .eq. 0  :means normal return */
/*         ierr .eq. -1 : means invalid value for lowd. (either .lt. 0 */
/*         or larger than nabd). */
/*         ierr .eq. -2 : means that lowd is not large enough and as */
/*         result the matrix cannot be stored in array abd. */
/*         lowd should be at least ml+mu+1, where ml and mu are as */
/*         provided on output. */

/* ----------------------------------------------------------------------* */
/* Additional details on banded format.  (this closely follows the      * */
/* format used in linpack. may be useful for converting a matrix into   * */
/* this storage format in order to use the linpack  banded solvers).    * */
/* ----------------------------------------------------------------------* */
/*             ---  band storage format  for matrix abd ---             * */
/* uses ml+mu+1 rows of abd(nabd,*) to store the diagonals of           * */
/* a in rows of abd starting from the lowest (sub)-diagonal  which  is  * */
/* stored in row number lowd of abd. the minimum number of rows needed  * */
/* in abd is ml+mu+1, i.e., the minimum value for lowd is ml+mu+1. the  * */
/* j-th  column  of  abd contains the elements of the j-th column of a, * */
/* from bottom to top: the element a(j+ml,j) is stored in  position     * */
/* abd(lowd,j), then a(j+ml-1,j) in position abd(lowd-1,j) and so on.   * */
/* Generally, the element a(j+k,j) of original matrix a is stored in    * */
/* position abd(lowd+k-ml,j), for k=ml,ml-1,..,0,-1, -mu.               * */
/* The first dimension nabd of abd must be .ge. lowd                    * */
/*                                                                      * */
/*     example [from linpack ]:   if the original matrix is             * */
/*                                                                      * */
/*              11 12 13  0  0  0                                       * */
/*              21 22 23 24  0  0                                       * */
/*               0 32 33 34 35  0     original banded matrix            * */
/*               0  0 43 44 45 46                                       * */
/*               0  0  0 54 55 56                                       * */
/*               0  0  0  0 65 66                                       * */
/*                                                                      * */
/* then  n = 6, ml = 1, mu = 2. lowd should be .ge. 4 (=ml+mu+1)  and   * */
/* if lowd = 5 for example, abd  should be:                             * */
/*                                                                      * */
/* untouched --> x  x  x  x  x  x                                       * */
/*               *  * 13 24 35 46                                       * */
/*               * 12 23 34 45 56    resulting abd matrix in banded     * */
/*              11 22 33 44 55 66    format                             * */
/*  row lowd--> 21 32 43 54 65  *                                       * */
/*                                                                      * */
/* * = not used                                                         * */


/* ----------------------------------------------------------------------* */
/* first determine ml and mu. */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --ia;
    --a;
    --ja;
    abd_dim1 = *nabd;
    abd_offset = 1 + abd_dim1;
    abd -= abd_offset;

    /* Function Body */
    *ierr = 0;
/* ----------- */
    if (*job == 1) {
	getbwd_(n, &a[1], &ja[1], &ia[1], ml, mu);
    }
    m = *ml + *mu + 1;
    if (*lowd == 0) {
	*lowd = m;
    }
    if (m > *lowd) {
	*ierr = -2;
    }
    if (*lowd > *nabd || *lowd < 0) {
	*ierr = -1;
    }
    if (*ierr < 0) {
	return 0;
    }
/* ------------ */
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = *lowd - i__ + 1;
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    abd[ii + j * abd_dim1] = 0.;
/* L10: */
	}
/* L15: */
    }
/* --------------------------------------------------------------------- */
    mdiag = *lowd - *ml;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k];
	    abd[i__ - j + mdiag + j * abd_dim1] = a[k];
/* L20: */
	}
/* L30: */
    }
    return 0;
/* ------------- end of csrbnd ------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* csrbnd_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*                     UNARY SUBROUTINES MODULE                         c */
/* ----------------------------------------------------------------------c */
/* rperm  : permutes the rows of a matrix (B = P A)                     c */
/* cperm  : permutes the columns of a matrix (B = A Q)                  c */
/* dperm  : permutes both the rows and columns of a matrix (B = P A Q ) c */
/* dvperm : permutes a real vector (in-place)                           c */
/* ivperm : permutes an integer vector (in-place)                       c */
/* diapos : returns the positions of the diagonal elements in A.        c */
/* getbwd : returns the bandwidth information on a matrix.              c */
/* infdia : obtains information on the diagonals of A.                  c */
/* rnrms  : computes the norms of the rows of A                         c */
/* roscal : scales the rows of a matrix by their norms.                 c */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int rperm_(integer *nrow, doublereal *a, integer *ja, 
	integer *ia, doublereal *ao, integer *jao, integer *iao, integer *
	perm, integer *job)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k, ii, ko;
    static logical values;

/* ----------------------------------------------------------------------- */
/* this subroutine permutes the rows of a matrix in CSR format. */
/* rperm  computes B = P A  where P is a permutation matrix. */
/* the permutation P is defined through the array perm: for each j, */
/* perm(j) represents the destination row number of row number j. */
/* Youcef Saad -- recoded Jan 28, 1991. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* n 	= dimension of the matrix */
/* a, ja, ia = input matrix in csr format */
/* perm 	= integer array of length nrow containing the permutation arrays */
/* 	  for the rows: perm(i) is the destination of row i in the */
/*         permuted matrix. */
/*         ---> a(i,j) in the original matrix becomes a(perm(i),j) */
/*         in the output  matrix. */

/* job	= integer indicating the work to be done: */
/* 		job = 1	permute a, ja, ia into ao, jao, iao */
/*                       (including the copying of real values ao and */
/*                       the array iao). */
/* 		job .ne. 1 :  ignore real values. */
/*                     (in which case arrays a and ao are not needed nor */
/*                      used). */

/* ------------ */
/* on return: */
/* ------------ */
/* ao, jao, iao = input matrix in a, ja, ia format */
/* note : */
/*        if (job.ne.1)  then the arrays a and ao are not used. */
/* ----------------------------------------------------------------------c */
/*           Y. Saad, May  2, 1990                                      c */
/* ----------------------------------------------------------------------c */
    /* Parameter adjustments */
    --perm;
    --iao;
    --ia;
    --a;
    --ja;
    --ao;
    --jao;

    /* Function Body */
    values = *job == 1;

/*     determine pointers for output matix. */

    i__1 = *nrow;
    for (j = 1; j <= i__1; ++j) {
	i__ = perm[j];
	iao[i__ + 1] = ia[j + 1] - ia[j];
/* L50: */
    }

/* get pointers from lengths */

    iao[1] = 1;
    i__1 = *nrow;
    for (j = 1; j <= i__1; ++j) {
	iao[j + 1] += iao[j];
/* L51: */
    }

/* copying */

    i__1 = *nrow;
    for (ii = 1; ii <= i__1; ++ii) {

/* old row = ii  -- new row = iperm(ii) -- ko = new pointer */

	ko = iao[perm[ii]];
	i__2 = ia[ii + 1] - 1;
	for (k = ia[ii]; k <= i__2; ++k) {
	    jao[ko] = ja[k];
	    if (values) {
		ao[ko] = a[k];
	    }
	    ++ko;
/* L60: */
	}
/* L100: */
    }

    return 0;
/* ---------end-of-rperm ------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* rperm_ */

/* Subroutine */ int cperm_(integer *nrow, doublereal *a, integer *ja, 
	integer *ia, doublereal *ao, integer *jao, integer *iao, integer *
	perm, integer *job)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, k, nnz;

/* ----------------------------------------------------------------------- */
/* this subroutine permutes the columns of a matrix a, ja, ia. */
/* the result is written in the output matrix  ao, jao, iao. */
/* cperm computes B = A P, where  P is a permutation matrix */
/* that maps column j into column perm(j), i.e., on return */
/*      a(i,j) becomes a(i,perm(j)) in new matrix */
/* Y. Saad, May 2, 1990 / modified Jan. 28, 1991. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* nrow 	= row dimension of the matrix */

/* a, ja, ia = input matrix in csr format. */

/* perm	= integer array of length ncol (number of columns of A */
/*         containing the permutation array  the columns: */
/*         a(i,j) in the original matrix becomes a(i,perm(j)) */
/*         in the output matrix. */

/* job	= integer indicating the work to be done: */
/* 		job = 1	permute a, ja, ia into ao, jao, iao */
/*                       (including the copying of real values ao and */
/*                       the array iao). */
/* 		job .ne. 1 :  ignore real values ao and ignore iao. */

/* ------------ */
/* on return: */
/* ------------ */
/* ao, jao, iao = input matrix in a, ja, ia format (array ao not needed) */

/* Notes: */
/* ------- */
/* 1. if job=1 then ao, iao are not used. */
/* 2. This routine is in place: ja, jao can be the same. */
/* 3. If the matrix is initially sorted (by increasing column number) */
/*    then ao,jao,iao  may not be on return. */

/* ----------------------------------------------------------------------c */
/* local parameters: */

    /* Parameter adjustments */
    --iao;
    --ia;
    --a;
    --ja;
    --ao;
    --jao;
    --perm;

    /* Function Body */
    nnz = ia[*nrow + 1] - 1;
    i__1 = nnz;
    for (k = 1; k <= i__1; ++k) {
	jao[k] = perm[ja[k]];
/* L100: */
    }

/*     done with ja array. return if no need to touch values. */

    if (*job != 1) {
	return 0;
    }

/* else get new pointers -- and copy values too. */

    i__1 = *nrow + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iao[i__] = ia[i__];
/* L1: */
    }

    i__1 = nnz;
    for (k = 1; k <= i__1; ++k) {
	ao[k] = a[k];
/* L2: */
    }

    return 0;
/* ---------end-of-cperm-------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* cperm_ */

/* Subroutine */ int dperm_(integer *nrow, doublereal *a, integer *ja, 
	integer *ia, doublereal *ao, integer *jao, integer *iao, integer *
	perm, integer *qperm, integer *job)
{
    extern /* Subroutine */ int cperm_(integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, integer 
	    *), rperm_(integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, integer *);
    static integer locjob;

/* ----------------------------------------------------------------------- */
/* This routine permutes the rows and columns of a matrix stored in CSR */
/* format. i.e., it computes P A Q, where P, Q are permutation matrices. */
/* P maps row i into row perm(i) and Q maps column j into column qperm(j): */
/*      a(i,j)    becomes   a(perm(i),qperm(j)) in new matrix */
/* In the particular case where Q is the transpose of P (symmetric */
/* permutation of A) then qperm is not needed. */
/* note that qperm should be of length ncol (number of columns) but this */
/* is not checked. */
/* ----------------------------------------------------------------------- */
/* Y. Saad, Sep. 21 1989 / recoded Jan. 28 1991. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* n 	= dimension of the matrix */
/* a, ja, */
/*    ia = input matrix in a, ja, ia format */
/* perm 	= integer array of length n containing the permutation arrays */
/* 	  for the rows: perm(i) is the destination of row i in the */
/*         permuted matrix -- also the destination of column i in case */
/*         permutation is symmetric (job .le. 2) */

/* qperm	= same thing for the columns. This should be provided only */
/*         if job=3 or job=4, i.e., only in the case of a nonsymmetric */
/* 	  permutation of rows and columns. Otherwise qperm is a dummy */

/* job	= integer indicating the work to be done: */
/* * job = 1,2 permutation is symmetric  Ao :== P * A * transp(P) */
/* 		job = 1	permute a, ja, ia into ao, jao, iao */
/* 		job = 2 permute matrix ignoring real values. */
/* * job = 3,4 permutation is non-symmetric  Ao :== P * A * Q */
/* 		job = 3	permute a, ja, ia into ao, jao, iao */
/* 		job = 4 permute matrix ignoring real values. */

/* on return: */
/* ----------- */
/* ao, jao, iao = input matrix in a, ja, ia format */

/* in case job .eq. 2 or job .eq. 4, a and ao are never referred to */
/* and can be dummy arguments. */
/* Notes: */
/* ------- */
/*  1) algorithm is in place */
/*  2) column indices may not be sorted on return even  though they may be */
/*     on entry. */
/* ----------------------------------------------------------------------c */
/* local variables */

/*     locjob indicates whether or not real values must be copied. */

    /* Parameter adjustments */
    --perm;
    --iao;
    --ia;
    --a;
    --ja;
    --ao;
    --jao;
    --qperm;

    /* Function Body */
    locjob = *job % 2;

/* permute rows first */

    rperm_(nrow, &a[1], &ja[1], &ia[1], &ao[1], &jao[1], &iao[1], &perm[1], &
	    locjob);

/* then permute columns */

    locjob = 0;

    if (*job <= 2) {
	cperm_(nrow, &ao[1], &jao[1], &iao[1], &ao[1], &jao[1], &iao[1], &
		perm[1], &locjob);
    } else {
	cperm_(nrow, &ao[1], &jao[1], &iao[1], &ao[1], &jao[1], &iao[1], &
		qperm[1], &locjob);
    }

    return 0;
/* -------end-of-dperm---------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* dperm_ */

/* Subroutine */ int dvperm_(integer *n, doublereal *x, integer *perm)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, ii;
    static doublereal tmp, tmp1;
    static integer init, next;

/* ----------------------------------------------------------------------- */
/* this subroutine performs an in-place permutation of a real vector x */
/* according to the permutation array perm(*), i.e., on return, */
/* the vector x satisfies, */

/* 	x(perm(j)) :== x(j), j=1,2,.., n */

/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* n 	= length of vector x. */
/* perm 	= integer array of length n containing the permutation  array. */
/* x	= input vector */

/* on return: */
/* ---------- */
/* x	= vector x permuted according to x(perm(*)) :=  x(*) */

/* ----------------------------------------------------------------------c */
/*           Y. Saad, Sep. 21 1989                                      c */
/* ----------------------------------------------------------------------c */
/* local variables */

    /* Parameter adjustments */
    --perm;
    --x;

    /* Function Body */
    init = 1;
    tmp = x[init];
    ii = perm[init];
    perm[init] = -perm[init];
    k = 0;

/* loop */

L6:
    ++k;

/* save the chased element -- */

    tmp1 = x[ii];
    x[ii] = tmp;
    next = perm[ii];
    if (next < 0) {
	goto L65;
    }

/* test for end */

    if (k > *n) {
	goto L101;
    }
    tmp = tmp1;
    perm[ii] = -perm[ii];
    ii = next;

/* end loop */

    goto L6;

/* reinitilaize cycle -- */

L65:
    ++init;
    if (init > *n) {
	goto L101;
    }
    if (perm[init] < 0) {
	goto L65;
    }
    tmp = x[init];
    ii = perm[init];
    perm[init] = -perm[init];
    goto L6;

L101:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	perm[j] = -perm[j];
/* L200: */
    }

    return 0;
/* -------------------end-of-dvperm--------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* dvperm_ */

/* Subroutine */ int ivperm_(integer *n, integer *ix, integer *perm)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, ii, tmp, tmp1, init, next;

/* ----------------------------------------------------------------------- */
/* this subroutine performs an in-place permutation of an integer vector */
/* ix according to the permutation array perm(*), i.e., on return, */
/* the vector x satisfies, */

/* 	ix(perm(j)) :== ix(j), j=1,2,.., n */

/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* n 	= length of vector x. */
/* perm 	= integer array of length n containing the permutation  array. */
/* ix	= input vector */

/* on return: */
/* ---------- */
/* ix	= vector x permuted according to ix(perm(*)) :=  ix(*) */

/* ----------------------------------------------------------------------c */
/*           Y. Saad, Sep. 21 1989                                      c */
/* ----------------------------------------------------------------------c */
/* local variables */

    /* Parameter adjustments */
    --perm;
    --ix;

    /* Function Body */
    init = 1;
    tmp = ix[init];
    ii = perm[init];
    perm[init] = -perm[init];
    k = 0;

/* loop */

L6:
    ++k;

/* save the chased element -- */

    tmp1 = ix[ii];
    ix[ii] = tmp;
    next = perm[ii];
    if (next < 0) {
	goto L65;
    }

/* test for end */

    if (k > *n) {
	goto L101;
    }
    tmp = tmp1;
    perm[ii] = -perm[ii];
    ii = next;

/* end loop */

    goto L6;

/* reinitilaize cycle -- */

L65:
    ++init;
    if (init > *n) {
	goto L101;
    }
    if (perm[init] < 0) {
	goto L65;
    }
    tmp = ix[init];
    ii = perm[init];
    perm[init] = -perm[init];
    goto L6;

L101:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	perm[j] = -perm[j];
/* L200: */
    }

    return 0;
/* -------------------end-of-ivperm--------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* ivperm_ */

/* Subroutine */ int diapos_(integer *n, integer *ja, integer *ia, integer *
	idiag)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k;

/* ----------------------------------------------------------------------- */
/* this subroutine returns the positions of the diagonal elements of a */
/* sparse matrix a, ja, ia, in the array idiag. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */

/* n	= integer. row dimension of the matrix a. */
/* a,ja, */
/*    ia = matrix stored compressed sparse row format. a array skipped. */

/* on return: */
/* ----------- */
/* idiag  = integer array of length n. The i-th entry of idiag */
/*          points to the diagonal element a(i,i) in the arrays */
/*          a, ja. (i.e., a(idiag(i)) = element A(i,i) of matrix A) */
/*          if no diagonal element is found the entry is set to 0. */
/* ----------------------------------------------------------------------c */
/*           Y. Saad, March, 1990 */
/* ----------------------------------------------------------------------c */
    /* Parameter adjustments */
    --idiag;
    --ia;
    --ja;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	idiag[i__] = 0;
/* L1: */
    }

/*     sweep through data structure. */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    if (ja[k] == i__) {
		idiag[i__] = k;
	    }
/* L51: */
	}
/* L6: */
    }
/* ----------- -end-of-diapos--------------------------------------------- */
/* ----------------------------------------------------------------------- */
    return 0;
} /* diapos_ */

/* Subroutine */ int getbwd_(integer *n, doublereal *a, integer *ja, integer *
	ia, integer *ml, integer *mu)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer i__, k, ldist;

/* ----------------------------------------------------------------------- */
/* gets the bandwidth of lower part and upper part of A. */
/* does not assume that A is sorted. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* n	= integer = the row dimension of the matrix */
/* a, ja, */
/*    ia = matrix in compressed sparse row format. */

/* on return: */
/* ----------- */
/* ml	= integer. The bandwidth of the strict lower part of A */
/* mu	= integer. The bandwidth of the strict upper part of A */

/* Notes: */
/* ===== ml and mu are allowed to be negative or return. This may be */
/*       useful since it will tell us whether a band is confined */
/*       in the strict  upper/lower triangular part. */
/*       indeed the definitions of ml and mu are */

/*       ml = max ( (i-j)  s.t. a(i,j) .ne. 0  ) */
/*       mu = max ( (j-i)  s.t. a(i,j) .ne. 0  ) */
/* ----------------------------------------------------------------------c */
/* Y. Saad, Sep. 21 1989                                                c */
/* ----------------------------------------------------------------------c */
    /* Parameter adjustments */
    --ia;
    --a;
    --ja;

    /* Function Body */
    *ml = -(*n);
    *mu = -(*n);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    ldist = i__ - ja[k];
	    *ml = max(*ml,ldist);
/* Computing MAX */
	    i__3 = *mu, i__4 = -ldist;
	    *mu = max(i__3,i__4);
/* L31: */
	}
/* L3: */
    }
    return 0;
/* ---------------end-of-getbwd ------------------------------------------ */
/* ----------------------------------------------------------------------- */
} /* getbwd_ */

/* Subroutine */ int infdia_(integer *n, integer *ja, integer *ia, integer *
	ind, integer *idiag)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k, n2;

/* ----------------------------------------------------------------------- */
/*     obtains information on the diagonals of A. */
/* ----------------------------------------------------------------------- */
/* this subroutine finds the lengths of each of the 2*n-1 diagonals of A */
/* it also outputs the number of nonzero diagonals found. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* ---------- */
/* n	= dimension of the matrix a. */

/* a,    ..... not needed here. */
/* ja, */
/* ia    = matrix stored in csr format */

/* on return: */
/* ----------- */

/* idiag = integer. number of nonzero diagonals found. */

/* ind   = integer array of length at least 2*n-1. The k-th entry in */
/*         ind contains the number of nonzero elements in the diagonal */
/*         number k, the numbering beeing from the lowermost diagonal */
/*         (bottom-left). In other words ind(k) = length of diagonal */
/*         whose offset wrt the main diagonal is = - n + k. */
/* ----------------------------------------------------------------------c */
/*           Y. Saad, Sep. 21 1989                                      c */
/* ----------------------------------------------------------------------c */
    /* Parameter adjustments */
    --ind;
    --ia;
    --ja;

    /* Function Body */
    n2 = *n + *n - 1;
    i__1 = n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ind[i__] = 0;
/* L1: */
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k];
	    ++ind[*n + j - i__];
/* L2: */
	}
/* L3: */
    }
/*     count the nonzero ones. */
    *idiag = 0;
    i__1 = n2;
    for (k = 1; k <= i__1; ++k) {
	if (ind[k] != 0) {
	    ++(*idiag);
	}
/* L41: */
    }
    return 0;
/* done */
/* ------end-of-infdia --------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* infdia_ */

/* Subroutine */ int rnrms_(integer *nrow, integer *nrm, doublereal *a, 
	integer *ja, integer *ia, doublereal *diag)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer k, k1, k2, ii;
    static doublereal scal;

/* ----------------------------------------------------------------------- */
/* gets the norms of each row of A. (choice of three norms) */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A */

/* nrm   = integer. norm indicator. nrm = 1, means 1-norm, nrm =2 */
/*                  means the 2-nrm, nrm = 0 means max norm */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format. */

/* on return: */
/* ---------- */

/* diag = real vector of length nrow containing the norms */

/* ----------------------------------------------------------------- */
    /* Parameter adjustments */
    --diag;
    --ia;
    --a;
    --ja;

    /* Function Body */
    i__1 = *nrow;
    for (ii = 1; ii <= i__1; ++ii) {

/*     compute the norm if each element. */

	scal = 0.;
	k1 = ia[ii];
	k2 = ia[ii + 1] - 1;
	if (*nrm == 0) {
	    i__2 = k2;
	    for (k = k1; k <= i__2; ++k) {
/* Computing MAX */
		d__2 = scal, d__3 = (d__1 = a[k], abs(d__1));
		scal = max(d__2,d__3);
/* L2: */
	    }
	} else if (*nrm == 1) {
	    i__2 = k2;
	    for (k = k1; k <= i__2; ++k) {
		scal += (d__1 = a[k], abs(d__1));
/* L3: */
	    }
	} else {
	    i__2 = k2;
	    for (k = k1; k <= i__2; ++k) {
/* Computing 2nd power */
		d__1 = a[k];
		scal += d__1 * d__1;
/* L4: */
	    }
	}
	if (*nrm == 2) {
	    scal = sqrt(scal);
	}
	diag[ii] = scal;
/* L1: */
    }
    return 0;
/* ----------------------------------------------------------------------- */
/* -------------end-of-rnrms---------------------------------------------- */
} /* rnrms_ */

/* Subroutine */ int roscal_(integer *nrow, integer *job, integer *nrm, 
	doublereal *a, integer *ja, integer *ia, doublereal *diag, doublereal 
	*b, integer *jb, integer *ib, integer *ierr)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j;
    extern /* Subroutine */ int rnrms_(integer *, integer *, doublereal *, 
	    integer *, integer *, doublereal *), diamua_(integer *, integer *,
	     doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *);

/* ----------------------------------------------------------------------- */
/* scales the rows of A such that their norms are one on return */
/* 3 choices of norms: 1-norm, 2-norm, max-norm. */
/* ----------------------------------------------------------------------- */
/* on entry: */
/* --------- */
/* nrow	= integer. The row dimension of A */

/* job   = integer. job indicator. Job=0 means get array b only */
/*         job = 1 means get b, and the integer arrays ib, jb. */

/* nrm   = integer. norm indicator. nrm = 1, means 1-norm, nrm =2 */
/*                  means the 2-nrm, nrm = 0 means max norm */

/* a, */
/* ja, */
/* ia   = Matrix A in compressed sparse row format. */

/* on return: */
/* ---------- */

/* diag = diagonal matrix stored as a vector containing the matrix */
/*        by which the rows have been scaled, i.e., on return */
/*        we have B = Diag*A. */

/* b, */
/* jb, */
/* ib	= resulting matrix B in compressed sparse row sparse format. */

/* ierr  = error message. ierr=0     : Normal return */
/*                        ierr=i > 0 : Row number i is a zero row. */
/* Notes: */
/* ------- */
/* 1)        The column dimension of A is not needed. */
/* 2)        algorithm in place (B can take the place of A). */
/* ----------------------------------------------------------------- */
    /* Parameter adjustments */
    --ib;
    --diag;
    --ia;
    --a;
    --ja;
    --b;
    --jb;

    /* Function Body */
    rnrms_(nrow, nrm, &a[1], &ja[1], &ia[1], &diag[1]);
    *ierr = 0;
    i__1 = *nrow;
    for (j = 1; j <= i__1; ++j) {
	if (diag[j] == 0.) {
	    *ierr = j;
	    return 0;
	} else {
	    diag[j] = 1. / diag[j];
	}
/* L1: */
    }
    diamua_(nrow, job, &a[1], &ja[1], &ia[1], &diag[1], &b[1], &jb[1], &ib[1])
	    ;
    return 0;
/* -------end-of-roscal--------------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* roscal_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*                   ITERATIVE SOLVERS MODULE                           c */
/* ----------------------------------------------------------------------c */
/* ILUT    : Incomplete LU factorization with dual truncation strategy  c */
/* ILUTP   : ILUT with column  pivoting                                 c */
/* LUSOL   : forward followed by backward triangular solve (Precond.)   c */
/* QSPLIT  : quick split routine used by ilut to sort out the k largest c */
/*           elements in absolute value                                 c */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int ilut_(integer *n, doublereal *a, integer *ja, integer *
	ia, integer *lfil, doublereal *droptol, doublereal *alu, integer *jlu,
	 integer *ju, integer *iwk, doublereal *w, integer *jw, integer *ierr)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k;
    static doublereal s, t;
    static integer j1, j2, ii, jj, ju0, len;
    static doublereal fact;
    static integer lenl, lenu, jpos, jrow;
    static doublereal tnorm;
    extern /* Subroutine */ int qsplit_(doublereal *, integer *, integer *, 
	    integer *);

/* ----------------------------------------------------------------------- */
/* ----------------------------------------------------------------------* */
/*                      *** ILUT preconditioner ***                     * */
/*      incomplete LU factorization with dual truncation mechanism      * */
/* ----------------------------------------------------------------------* */
/*     Author: Yousef Saad *May, 5, 1990, Latest revision, August 1996  * */
/* ----------------------------------------------------------------------* */
/* PARAMETERS */
/* ----------- */

/* on entry: */
/* ========== */
/* n       = integer. The row dimension of the matrix A. The matrix */

/* a,ja,ia = matrix stored in Compressed Sparse Row format. */

/* lfil    = integer. The fill-in parameter. Each row of L and each row */
/*           of U will have a maximum of lfil elements (excluding the */
/*           diagonal element). lfil must be .ge. 0. */
/*           ** WARNING: THE MEANING OF LFIL HAS CHANGED WITH RESPECT TO */
/*           EARLIER VERSIONS. */

/* droptol = real*8. Sets the threshold for dropping small terms in the */
/*           factorization. See below for details on dropping strategy. */


/* iwk     = integer. The lengths of arrays alu and jlu. If the arrays */
/*           are not big enough to store the ILU factorizations, ilut */
/*           will stop with an error message. */

/* On return: */
/* =========== */

/* alu,jlu = matrix stored in Modified Sparse Row (MSR) format containing */
/*           the L and U factors together. The diagonal (stored in */
/*           alu(1:n) ) is inverted. Each i-th row of the alu,jlu matrix */
/*           contains the i-th row of L (excluding the diagonal entry=1) */
/*           followed by the i-th row of U. */

/* ju      = integer array of length n containing the pointers to */
/*           the beginning of each row of U in the matrix alu,jlu. */

/* ierr    = integer. Error message with the following meaning. */
/*           ierr  = 0    --> successful return. */
/*           ierr .gt. 0  --> zero pivot encountered at step number ierr. */
/*           ierr  = -1   --> Error. input matrix may be wrong. */
/*                            (The elimination process has generated a */
/*                            row in L or U whose length is .gt.  n.) */
/*           ierr  = -2   --> The matrix L overflows the array al. */
/*           ierr  = -3   --> The matrix U overflows the array alu. */
/*           ierr  = -4   --> Illegal value for lfil. */
/*           ierr  = -5   --> zero row encountered. */

/* work arrays: */
/* ============= */
/* jw      = integer work array of length 2*n. */
/* w       = real work array of length n */

/* ---------------------------------------------------------------------- */
/* w, ju (1:n) store the working array [1:ii-1 = L-part, ii:n = u] */
/* jw(n+1:2n)  stores nonzero indicators */

/* Notes: */
/* ------ */
/* The diagonal elements of the input matrix must be  nonzero (at least */
/* 'structurally'). */

/* ----------------------------------------------------------------------* */
/* ---- Dual drop strategy works as follows.                             * */
/*                                                                      * */
/*     1) Theresholding in L and U as set by droptol. Any element whose * */
/*        magnitude is less than some tolerance (relative to the abs    * */
/*        value of diagonal element in u) is dropped.                   * */
/*                                                                      * */
/*     2) Keeping only the largest lfil elements in the i-th row of L   * */
/*        and the largest lfil elements in the i-th row of U (excluding * */
/*        diagonal elements).                                           * */
/*                                                                      * */
/* Flexibility: one  can use  droptol=0  to get  a strategy  based on   * */
/* keeping  the largest  elements in  each row  of L  and U.   Taking   * */
/* droptol .ne.  0 but lfil=n will give  the usual threshold strategy   * */
/* (however, fill-in is then mpredictible).                             * */
/* ----------------------------------------------------------------------* */
/*     locals */
    /* Parameter adjustments */
    --jw;
    --w;
    --ju;
    --ia;
    --a;
    --ja;
    --alu;
    --jlu;

    /* Function Body */
    if (*lfil < 0) {
	goto L998;
    }
/* ----------------------------------------------------------------------- */
/*     initialize ju0 (points to next element to be added to alu,jlu) */
/*     and pointer array. */
/* ----------------------------------------------------------------------- */
    ju0 = *n + 2;
    jlu[1] = ju0;

/*     initialize nonzero indicator array. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	jw[*n + j] = 0;
/* L1: */
    }
/* ----------------------------------------------------------------------- */
/*     beginning of main loop. */
/* ----------------------------------------------------------------------- */
    i__1 = *n;
    for (ii = 1; ii <= i__1; ++ii) {
	j1 = ia[ii];
	j2 = ia[ii + 1] - 1;
	tnorm = 0.;
	i__2 = j2;
	for (k = j1; k <= i__2; ++k) {
	    tnorm += (d__1 = a[k], abs(d__1));
/* L501: */
	}
	if (tnorm == 0.) {
	    goto L999;
	}
	tnorm /= (real) (j2 - j1 + 1);

/*     unpack L-part and U-part of row of A in arrays w */

	lenu = 1;
	lenl = 0;
	jw[ii] = ii;
	w[ii] = 0.f;
	jw[*n + ii] = ii;

	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    k = ja[j];
	    t = a[j];
	    if (k < ii) {
		++lenl;
		jw[lenl] = k;
		w[lenl] = t;
		jw[*n + k] = lenl;
	    } else if (k == ii) {
		w[ii] = t;
	    } else {
		++lenu;
		jpos = ii + lenu - 1;
		jw[jpos] = k;
		w[jpos] = t;
		jw[*n + k] = jpos;
	    }
/* L170: */
	}
	jj = 0;
	len = 0;

/*     eliminate previous rows */

L150:
	++jj;
	if (jj > lenl) {
	    goto L160;
	}
/* ----------------------------------------------------------------------- */
/*     in order to do the elimination in the correct order we must select */
/*     the smallest column index among jw(k), k=jj+1, ..., lenl. */
/* ----------------------------------------------------------------------- */
	jrow = jw[jj];
	k = jj;

/*     determine smallest column index */

	i__2 = lenl;
	for (j = jj + 1; j <= i__2; ++j) {
	    if (jw[j] < jrow) {
		jrow = jw[j];
		k = j;
	    }
/* L151: */
	}

	if (k != jj) {
/*     exchange in jw */
	    j = jw[jj];
	    jw[jj] = jw[k];
	    jw[k] = j;
/*     exchange in jr */
	    jw[*n + jrow] = jj;
	    jw[*n + j] = k;
/*     exchange in w */
	    s = w[jj];
	    w[jj] = w[k];
	    w[k] = s;
	}

/*     zero out element in row by setting jw(n+jrow) to zero. */

	jw[*n + jrow] = 0;

/*     get the multiplier for row to be eliminated (jrow). */

	fact = w[jj] * alu[jrow];
	if (abs(fact) <= *droptol) {
	    goto L150;
	}

/*     combine current row and row jrow */

	i__2 = jlu[jrow + 1] - 1;
	for (k = ju[jrow]; k <= i__2; ++k) {
	    s = fact * alu[k];
	    j = jlu[k];
	    jpos = jw[*n + j];
	    if (j >= ii) {

/*     dealing with upper part. */

		if (jpos == 0) {

/*     this is a fill-in element */

		    ++lenu;
		    if (lenu > *n) {
			goto L995;
		    }
		    i__ = ii + lenu - 1;
		    jw[i__] = j;
		    jw[*n + j] = i__;
		    w[i__] = -s;
		} else {

/*     this is not a fill-in element */

		    w[jpos] -= s;
		}
	    } else {

/*     dealing  with lower part. */

		if (jpos == 0) {

/*     this is a fill-in element */

		    ++lenl;
		    if (lenl > *n) {
			goto L995;
		    }
		    jw[lenl] = j;
		    jw[*n + j] = lenl;
		    w[lenl] = -s;
		} else {

/*     this is not a fill-in element */

		    w[jpos] -= s;
		}
	    }
/* L203: */
	}

/*     store this pivot element -- (from left to right -- no danger of */
/*     overlap with the working elements in L (pivots). */

	++len;
	w[len] = fact;
	jw[len] = jrow;
	goto L150;
L160:

/*     reset double-pointer to zero (U-part) */

	i__2 = lenu;
	for (k = 1; k <= i__2; ++k) {
	    jw[*n + jw[ii + k - 1]] = 0;
/* L308: */
	}

/*     update L-matrix */

	lenl = len;
	len = min(lenl,*lfil);

/*     sort by quick-split */

	qsplit_(&w[1], &jw[1], &lenl, &len);

/*     store L-part */

	i__2 = len;
	for (k = 1; k <= i__2; ++k) {
	    if (ju0 > *iwk) {
		goto L996;
	    }
	    alu[ju0] = w[k];
	    jlu[ju0] = jw[k];
	    ++ju0;
/* L204: */
	}

/*     save pointer to beginning of row ii of U */

	ju[ii] = ju0;

/*     update U-matrix -- first apply dropping strategy */

	len = 0;
	i__2 = lenu - 1;
	for (k = 1; k <= i__2; ++k) {
	    if ((d__1 = w[ii + k], abs(d__1)) > *droptol * tnorm) {
		++len;
		w[ii + len] = w[ii + k];
		jw[ii + len] = jw[ii + k];
	    }
	}
	lenu = len + 1;
	len = min(lenu,*lfil);

	if (lenu > 1) {
	    i__2 = lenu - 1;
	    qsplit_(&w[ii + 1], &jw[ii + 1], &i__2, &len);
	}

/*     copy */

	t = (d__1 = w[ii], abs(d__1));
	if (len + ju0 > *iwk) {
	    goto L997;
	}
	i__2 = ii + len - 1;
	for (k = ii + 1; k <= i__2; ++k) {
	    jlu[ju0] = jw[k];
	    alu[ju0] = w[k];
	    t += (d__1 = w[k], abs(d__1));
	    ++ju0;
/* L302: */
	}

/*     store inverse of diagonal element of u */

	if (w[ii] == 0.) {
	    w[ii] = (*droptol + 1e-4f) * tnorm;
	}

	alu[ii] = 1. / w[ii];

/*     update pointer to beginning of next row of U. */

	jlu[ii + 1] = ju0;
/* ----------------------------------------------------------------------- */
/*     end main loop */
/* ----------------------------------------------------------------------- */
/* L500: */
    }
    *ierr = 0;
    return 0;

/*     incomprehensible error. Matrix must be wrong. */

L995:
    *ierr = -1;
    return 0;

/*     insufficient storage in L. */

L996:
    *ierr = -2;
    return 0;

/*     insufficient storage in U. */

L997:
    *ierr = -3;
    return 0;

/*     illegal lfil entered. */

L998:
    *ierr = -4;
    return 0;

/*     zero row encountered */

L999:
    *ierr = -5;
    return 0;
/* ----------------end-of-ilut-------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* ilut_ */

/* Subroutine */ int ilutp_(integer *n, doublereal *a, integer *ja, integer *
	ia, integer *lfil, doublereal *droptol, doublereal *permtol, integer *
	mbloc, doublereal *alu, integer *jlu, integer *ju, integer *iwk, 
	doublereal *w, integer *jw, integer *iperm, integer *ierr)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k;
    static doublereal s, t;
    static integer j1, j2, ii, jj, ju0, len;
    static doublereal tmp, fact;
    static integer lenl, imax, lenu, icut, jpos;
    static doublereal xmax;
    static integer jrow;
    static doublereal xmax0, tnorm;
    extern /* Subroutine */ int qsplit_(doublereal *, integer *, integer *, 
	    integer *);

/* ----------------------------------------------------------------------- */
/*     implicit none */
/* ----------------------------------------------------------------------* */
/*       *** ILUTP preconditioner -- ILUT with pivoting  ***            * */
/*      incomplete LU factorization with dual truncation mechanism      * */
/* ----------------------------------------------------------------------* */
/* author Yousef Saad *Sep 8, 1993 -- Latest revision, August 1996.     * */
/* ----------------------------------------------------------------------* */
/* on entry: */
/* ========== */
/* n       = integer. The dimension of the matrix A. */

/* a,ja,ia = matrix stored in Compressed Sparse Row format. */
/*           ON RETURN THE COLUMNS OF A ARE PERMUTED. SEE BELOW FOR */
/*           DETAILS. */

/* lfil    = integer. The fill-in parameter. Each row of L and each row */
/*           of U will have a maximum of lfil elements (excluding the */
/*           diagonal element). lfil must be .ge. 0. */
/*           ** WARNING: THE MEANING OF LFIL HAS CHANGED WITH RESPECT TO */
/*           EARLIER VERSIONS. */

/* droptol = real*8. Sets the threshold for dropping small terms in the */
/*           factorization. See below for details on dropping strategy. */

/* lfil    = integer. The fill-in parameter. Each row of L and */
/*           each row of U will have a maximum of lfil elements. */
/*           WARNING: THE MEANING OF LFIL HAS CHANGED WITH RESPECT TO */
/*           EARLIER VERSIONS. */
/*           lfil must be .ge. 0. */

/* permtol = tolerance ratio used to  determne whether or not to permute */
/*           two columns.  At step i columns i and j are permuted when */

/*                     abs(a(i,j))*permtol .gt. abs(a(i,i)) */

/*           [0 --> never permute; good values 0.1 to 0.01] */

/* mbloc   = if desired, permuting can be done only within the diagonal */
/*           blocks of size mbloc. Useful for PDE problems with several */
/*           degrees of freedom.. If feature not wanted take mbloc=n. */


/* iwk     = integer. The lengths of arrays alu and jlu. If the arrays */
/*           are not big enough to store the ILU factorizations, ilut */
/*           will stop with an error message. */

/* On return: */
/* =========== */

/* alu,jlu = matrix stored in Modified Sparse Row (MSR) format containing */
/*           the L and U factors together. The diagonal (stored in */
/*           alu(1:n) ) is inverted. Each i-th row of the alu,jlu matrix */
/*           contains the i-th row of L (excluding the diagonal entry=1) */
/*           followed by the i-th row of U. */

/* ju      = integer array of length n containing the pointers to */
/*           the beginning of each row of U in the matrix alu,jlu. */

/* iperm   = contains the permutation arrays. */
/*           iperm(1:n) = old numbers of unknowns */
/*           iperm(n+1:2*n) = reverse permutation = new unknowns. */

/* ierr    = integer. Error message with the following meaning. */
/*           ierr  = 0    --> successful return. */
/*           ierr .gt. 0  --> zero pivot encountered at step number ierr. */
/*           ierr  = -1   --> Error. input matrix may be wrong. */
/*                            (The elimination process has generated a */
/*                            row in L or U whose length is .gt.  n.) */
/*           ierr  = -2   --> The matrix L overflows the array al. */
/*           ierr  = -3   --> The matrix U overflows the array alu. */
/*           ierr  = -4   --> Illegal value for lfil. */
/*           ierr  = -5   --> zero row encountered. */

/* work arrays: */
/* ============= */
/* jw      = integer work array of length 2*n. */
/* w       = real work array of length n */

/* IMPORTANR NOTE: */
/* -------------- */
/* TO AVOID PERMUTING THE SOLUTION VECTORS ARRAYS FOR EACH LU-SOLVE, */
/* THE MATRIX A IS PERMUTED ON RETURN. [all column indices are */
/* changed]. SIMILARLY FOR THE U MATRIX. */
/* To permute the matrix back to its original state use the loop: */

/*      do k=ia(1), ia(n+1)-1 */
/*         ja(k) = iperm(ja(k)) */
/*      enddo */

/* ----------------------------------------------------------------------- */
/*     local variables */


    /* Parameter adjustments */
    --iperm;
    --jw;
    --w;
    --ju;
    --ia;
    --a;
    --ja;
    --alu;
    --jlu;

    /* Function Body */
    if (*lfil < 0) {
	goto L998;
    }
/* ----------------------------------------------------------------------- */
/*     initialize ju0 (points to next element to be added to alu,jlu) */
/*     and pointer array. */
/* ----------------------------------------------------------------------- */
    ju0 = *n + 2;
    jlu[1] = ju0;

/*  integer double pointer array. */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	jw[*n + j] = 0;
	iperm[j] = j;
	iperm[*n + j] = j;
/* L1: */
    }
/* ----------------------------------------------------------------------- */
/*     beginning of main loop. */
/* ----------------------------------------------------------------------- */
    i__1 = *n;
    for (ii = 1; ii <= i__1; ++ii) {
	j1 = ia[ii];
	j2 = ia[ii + 1] - 1;
	tnorm = 0.;
	i__2 = j2;
	for (k = j1; k <= i__2; ++k) {
	    tnorm += (d__1 = a[k], abs(d__1));
/* L501: */
	}
	if (tnorm == 0.) {
	    goto L999;
	}
	tnorm /= j2 - j1 + 1;

/*     unpack L-part and U-part of row of A in arrays  w  -- */

	lenu = 1;
	lenl = 0;
	jw[ii] = ii;
	w[ii] = 0.f;
	jw[*n + ii] = ii;

	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    k = iperm[*n + ja[j]];
	    t = a[j];
	    if (k < ii) {
		++lenl;
		jw[lenl] = k;
		w[lenl] = t;
		jw[*n + k] = lenl;
	    } else if (k == ii) {
		w[ii] = t;
	    } else {
		++lenu;
		jpos = ii + lenu - 1;
		jw[jpos] = k;
		w[jpos] = t;
		jw[*n + k] = jpos;
	    }
/* L170: */
	}
	jj = 0;
	len = 0;

/*     eliminate previous rows */

L150:
	++jj;
	if (jj > lenl) {
	    goto L160;
	}
/* ----------------------------------------------------------------------- */
/*     in order to do the elimination in the correct order we must select */
/*     the smallest column index among jw(k), k=jj+1, ..., lenl. */
/* ----------------------------------------------------------------------- */
	jrow = jw[jj];
	k = jj;

/*     determine smallest column index */

	i__2 = lenl;
	for (j = jj + 1; j <= i__2; ++j) {
	    if (jw[j] < jrow) {
		jrow = jw[j];
		k = j;
	    }
/* L151: */
	}

	if (k != jj) {
/*     exchange in jw */
	    j = jw[jj];
	    jw[jj] = jw[k];
	    jw[k] = j;
/*     exchange in jr */
	    jw[*n + jrow] = jj;
	    jw[*n + j] = k;
/*     exchange in w */
	    s = w[jj];
	    w[jj] = w[k];
	    w[k] = s;
	}

/*     zero out element in row by resetting jw(n+jrow) to zero. */

	jw[*n + jrow] = 0;

/*     get the multiplier for row to be eliminated: jrow */

	fact = w[jj] * alu[jrow];

/*     drop term if small */

	if (abs(fact) <= *droptol) {
	    goto L150;
	}

/*     combine current row and row jrow */

	i__2 = jlu[jrow + 1] - 1;
	for (k = ju[jrow]; k <= i__2; ++k) {
	    s = fact * alu[k];
/*     new column number */
	    j = iperm[*n + jlu[k]];
	    jpos = jw[*n + j];
	    if (j >= ii) {

/*     dealing with upper part. */

		if (jpos == 0) {

/*     this is a fill-in element */

		    ++lenu;
		    i__ = ii + lenu - 1;
		    if (lenu > *n) {
			goto L995;
		    }
		    jw[i__] = j;
		    jw[*n + j] = i__;
		    w[i__] = -s;
		} else {
/*     no fill-in element -- */
		    w[jpos] -= s;
		}
	    } else {

/*     dealing with lower part. */

		if (jpos == 0) {

/*     this is a fill-in element */

		    ++lenl;
		    if (lenl > *n) {
			goto L995;
		    }
		    jw[lenl] = j;
		    jw[*n + j] = lenl;
		    w[lenl] = -s;
		} else {

/*     this is not a fill-in element */

		    w[jpos] -= s;
		}
	    }
/* L203: */
	}

/*     store this pivot element -- (from left to right -- no danger of */
/*     overlap with the working elements in L (pivots). */

	++len;
	w[len] = fact;
	jw[len] = jrow;
	goto L150;
L160:

/*     reset double-pointer to zero (U-part) */

	i__2 = lenu;
	for (k = 1; k <= i__2; ++k) {
	    jw[*n + jw[ii + k - 1]] = 0;
/* L308: */
	}

/*     update L-matrix */

	lenl = len;
	len = min(lenl,*lfil);

/*     sort by quick-split */

	qsplit_(&w[1], &jw[1], &lenl, &len);

/*     store L-part -- in original coordinates .. */

	i__2 = len;
	for (k = 1; k <= i__2; ++k) {
	    if (ju0 > *iwk) {
		goto L996;
	    }
	    alu[ju0] = w[k];
	    jlu[ju0] = iperm[jw[k]];
	    ++ju0;
/* L204: */
	}

/*     save pointer to beginning of row ii of U */

	ju[ii] = ju0;

/*     update U-matrix -- first apply dropping strategy */

	len = 0;
	i__2 = lenu - 1;
	for (k = 1; k <= i__2; ++k) {
	    if ((d__1 = w[ii + k], abs(d__1)) > *droptol * tnorm) {
		++len;
		w[ii + len] = w[ii + k];
		jw[ii + len] = jw[ii + k];
	    }
	}
	lenu = len + 1;
	len = min(lenu,*lfil);
	if (lenu > 1) {
	    i__2 = lenu - 1;
	    qsplit_(&w[ii + 1], &jw[ii + 1], &i__2, &len);
	}

/*     determine next pivot -- */

	imax = ii;
	xmax = (d__1 = w[imax], abs(d__1));
	xmax0 = xmax;
	icut = ii - 1 + *mbloc - (ii - 1) % *mbloc;
	i__2 = ii + len - 1;
	for (k = ii + 1; k <= i__2; ++k) {
	    t = (d__1 = w[k], abs(d__1));
	    if (t > xmax && t * *permtol > xmax0 && jw[k] <= icut) {
		imax = k;
		xmax = t;
	    }
	}

/*     exchange w's */

	tmp = w[ii];
	w[ii] = w[imax];
	w[imax] = tmp;

/*     update iperm and reverse iperm */

	j = jw[imax];
	i__ = iperm[ii];
	iperm[ii] = iperm[j];
	iperm[j] = i__;

/*     reverse iperm */

	iperm[*n + iperm[ii]] = ii;
	iperm[*n + iperm[j]] = j;
/* ----------------------------------------------------------------------- */

	if (len + ju0 > *iwk) {
	    goto L997;
	}

/*     copy U-part in original coordinates */

	i__2 = ii + len - 1;
	for (k = ii + 1; k <= i__2; ++k) {
	    jlu[ju0] = iperm[jw[k]];
	    alu[ju0] = w[k];
	    ++ju0;
/* L302: */
	}

/*     store inverse of diagonal element of u */

	if (w[ii] == 0.) {
	    w[ii] = (*droptol + 1e-4) * tnorm;
	}
	alu[ii] = 1. / w[ii];

/*     update pointer to beginning of next row of U. */

	jlu[ii + 1] = ju0;
/* ----------------------------------------------------------------------- */
/*     end main loop */
/* ----------------------------------------------------------------------- */
/* L500: */
    }

/*     permute all column indices of LU ... */

    i__1 = jlu[*n + 1] - 1;
    for (k = jlu[1]; k <= i__1; ++k) {
	jlu[k] = iperm[*n + jlu[k]];
    }

/*     ...and of A */

    i__1 = ia[*n + 1] - 1;
    for (k = ia[1]; k <= i__1; ++k) {
	ja[k] = iperm[*n + ja[k]];
    }

    *ierr = 0;
    return 0;

/*     incomprehensible error. Matrix must be wrong. */

L995:
    *ierr = -1;
    return 0;

/*     insufficient storage in L. */

L996:
    *ierr = -2;
    return 0;

/*     insufficient storage in U. */

L997:
    *ierr = -3;
    return 0;

/*     illegal lfil entered. */

L998:
    *ierr = -4;
    return 0;

/*     zero row encountered */

L999:
    *ierr = -5;
    return 0;
/* ----------------end-of-ilutp------------------------------------------- */
/* ----------------------------------------------------------------------- */
} /* ilutp_ */

/* Subroutine */ int qsplit_(doublereal *a, integer *ind, integer *n, integer 
	*ncut)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer j, mid;
    static doublereal tmp;
    static integer last, itmp, first;
    static doublereal abskey;

/* ----------------------------------------------------------------------- */
/*     does a quick-sort split of a real array. */
/*     on input a(1:n). is a real array */
/*     on output a(1:n) is permuted such that its elements satisfy: */

/*     abs(a(i)) .ge. abs(a(ncut)) for i .lt. ncut and */
/*     abs(a(i)) .le. abs(a(ncut)) for i .gt. ncut */

/*     ind(1:n) is an integer array which permuted in the same way as a(*). */
/* ----------------------------------------------------------------------- */
/* ----- */
    /* Parameter adjustments */
    --ind;
    --a;

    /* Function Body */
    first = 1;
    last = *n;
    if (*ncut < first || *ncut > last) {
	return 0;
    }

/*     outer loop -- while mid .ne. ncut do */

L1:
    mid = first;
    abskey = (d__1 = a[mid], abs(d__1));
    i__1 = last;
    for (j = first + 1; j <= i__1; ++j) {
	if ((d__1 = a[j], abs(d__1)) > abskey) {
	    ++mid;
/*     interchange */
	    tmp = a[mid];
	    itmp = ind[mid];
	    a[mid] = a[j];
	    ind[mid] = ind[j];
	    a[j] = tmp;
	    ind[j] = itmp;
	}
/* L2: */
    }

/*     interchange */

    tmp = a[mid];
    a[mid] = a[first];
    a[first] = tmp;

    itmp = ind[mid];
    ind[mid] = ind[first];
    ind[first] = itmp;

/*     test for while loop */

    if (mid == *ncut) {
	return 0;
    }
    if (mid > *ncut) {
	last = mid - 1;
    } else {
	first = mid + 1;
    }
    goto L1;
/* ----------------end-of-qsplit------------------------------------------ */
/* ----------------------------------------------------------------------- */
} /* qsplit_ */

/* Subroutine */ int lusol_(integer *n, doublereal *y, doublereal *x, 
	doublereal *alu, integer *jlu, integer *ju)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k;

/* ----------------------------------------------------------------------- */

/* This routine solves the system (LU) x = y, */
/* given an LU decomposition of a matrix stored in (alu, jlu, ju) */
/* modified sparse row format */

/* ----------------------------------------------------------------------- */
/* on entry: */
/* n   = dimension of system */
/* y   = the right-hand-side vector */
/* alu, jlu, ju */
/*     = the LU matrix as provided from the ILU routines. */

/* on return */
/* x   = solution of LU x = y. */
/* ----------------------------------------------------------------------- */

/* Note: routine is in place: call lusol (n, x, x, alu, jlu, ju) */
/*       will solve the system with rhs x and overwrite the result on x . */

/* ----------------------------------------------------------------------- */
/* local variables */


/* forward solve */

    /* Parameter adjustments */
    --x;
    --y;
    --alu;
    --jlu;
    --ju;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__] = y[i__];
	i__2 = ju[i__] - 1;
	for (k = jlu[i__]; k <= i__2; ++k) {
	    x[i__] -= alu[k] * x[jlu[k]];
/* L41: */
	}
/* L40: */
    }

/*     backward solve. */

    for (i__ = *n; i__ >= 1; --i__) {
	i__1 = jlu[i__ + 1] - 1;
	for (k = ju[i__]; k <= i__1; ++k) {
	    x[i__] -= alu[k] * x[jlu[k]];
/* L91: */
	}
	x[i__] = alu[i__] * x[i__];
/* L90: */
    }

    return 0;
/* ----------------end of lusol ------------------------------------------ */
/* ----------------------------------------------------------------------- */
} /* lusol_ */

/* ----------------------------------------------------------------------c */
/*                          S P A R S K I T                             c */
/* ----------------------------------------------------------------------c */
/*               REORDERING ROUTINES -- LEVEL SET BASED ROUTINES        c */
/* ----------------------------------------------------------------------c */
/* dblstr   : doubled stripe partitioner */
/* BFS      : Breadth-First search traversal algorithm */
/* add_lvst : routine to add a level -- used by BFS */
/* stripes  : finds the level set structure */
/* perphn   : finds a pseudo-peripheral node and performs a BFS from it. */
/* rversp   : routine to reverse a given permutation (e.g., for RCMK) */
/* maskdeg  : integer function to compute the `masked' of a node */
/* ----------------------------------------------------------------------- */
/* Subroutine */ int dblstr_(integer *n, integer *ja, integer *ia, integer *
	ip1, integer *ip2, integer *nfirst, integer *riord, integer *ndom, 
	integer *map, integer *mapptr, integer *mask, integer *levels, 
	integer *iwk)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, k;
    extern /* Subroutine */ int bfs_(integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *);
    static integer ndp1, idom, jdom, kdom, init, nlev;
    extern /* Subroutine */ int perphn_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);
    static integer numnod, maskval, nextdom;
    extern /* Subroutine */ int stripes_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);

/* ----------------------------------------------------------------------- */
/*     this routine does a two-way partitioning of a graph using */
/*     level sets recursively. First a coarse set is found by a */
/*     simple cuthill-mc Kee type algorithm. Them each of the large */
/*     domains is further partitioned into subsets using the same */
/*     technique. The ip1 and ip2 parameters indicate the desired number */
/*     number of partitions 'in each direction'. So the total number of */
/*     partitions on return ought to be equal (or close) to ip1*ip2 */
/* ----------------------parameters---------------------------------------- */
/* on entry: */
/* --------- */
/* n      = row dimension of matrix == number of vertices in graph */
/* ja, ia = pattern of matrix in CSR format (the ja,ia arrays of csr data */
/*          structure) */
/* ip1    = integer indicating the number of large partitions ('number of */
/*          paritions in first direction') */
/* ip2    = integer indicating the number of smaller partitions, per */
/*          large partition, ('number of partitions in second direction') */
/* nfirst = number of nodes in the first level that is input in riord */
/* riord  = (also an ouput argument). on entry riord contains the labels */
/*          of the nfirst nodes that constitute the first level. */
/* on return: */
/* ----------- */
/* ndom   = total number of partitions found */
/* map    = list of nodes listed partition by partition from partition 1 */
/*          to paritition ndom. */
/* mapptr = pointer array for map. All nodes from position */
/*          k1=mapptr(idom),to position k2=mapptr(idom+1)-1 in map belong */
/*          to partition idom. */
/* work arrays: */
/* ------------- */
/* mask   = array of length n, used to hold the partition number of each */
/*          node for the first (large) partitioning. */
/*          mask is also used as a marker of  visited nodes. */
/* levels = integer array of length .le. n used to hold the pointer */
/*          arrays for the various level structures obtained from BFS. */

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --iwk;
    --levels;
    --mask;
    --mapptr;
    --map;
    --riord;
    --ia;
    --ja;

    /* Function Body */
    maskval = 1;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	mask[j] = maskval;
    }
    iwk[1] = 0;
    bfs_(n, &ja[1], &ia[1], nfirst, &iwk[1], &mask[1], &maskval, &riord[1], &
	    levels[1], &nlev);

/*     init = riord(1) */
/*     call perphn (ja,ia,mask,maskval,init,nlev,riord,levels) */
    stripes_(&nlev, &riord[1], &levels[1], ip1, &map[1], &mapptr[1], ndom);
/* ----------------------------------------------------------------------- */
    if (*ip2 == 1) {
	return 0;
    }
    ndp1 = *ndom + 1;

/*     pack info into array iwk */

    i__1 = *ndom + 1;
    for (j = 1; j <= i__1; ++j) {
	iwk[j] = ndp1 + mapptr[j];
    }
    i__1 = mapptr[*ndom + 1] - 1;
    for (j = 1; j <= i__1; ++j) {
	iwk[ndp1 + j] = map[j];
    }
    i__1 = *ndom;
    for (idom = 1; idom <= i__1; ++idom) {
	j = iwk[idom];
	numnod = iwk[idom + 1] - iwk[idom];
	init = iwk[j];
	i__2 = iwk[idom + 1] - 1;
	for (k = j; k <= i__2; ++k) {
	}
    }
    i__1 = *ndom;
    for (idom = 1; idom <= i__1; ++idom) {
	i__2 = mapptr[idom + 1] - 1;
	for (k = mapptr[idom]; k <= i__2; ++k) {
	    mask[map[k]] = idom;
	}
    }
    nextdom = 1;

/*     jdom = counter for total number of (small) subdomains */

    jdom = 1;
    mapptr[jdom] = 1;
/* ----------------------------------------------------------------------- */
    i__1 = *ndom;
    for (idom = 1; idom <= i__1; ++idom) {
	maskval = idom;
	*nfirst = 1;
	numnod = iwk[idom + 1] - iwk[idom];
	j = iwk[idom];
	init = iwk[j];
	nextdom = mapptr[jdom];
/*  note:    old version uses iperm array */
	perphn_(&numnod, &ja[1], &ia[1], &init, &mask[1], &maskval, &nlev, &
		riord[1], &levels[1]);

	stripes_(&nlev, &riord[1], &levels[1], ip2, &map[nextdom], &mapptr[
		jdom], &kdom);

	mapptr[jdom] = nextdom;
	i__2 = jdom + kdom - 1;
	for (j = jdom; j <= i__2; ++j) {
	    mapptr[j + 1] = nextdom + mapptr[j + 1] - 1;
	}
	jdom += kdom;
    }

    *ndom = jdom - 1;
    return 0;
} /* dblstr_ */

/* Subroutine */ int bfs_(integer *n, integer *ja, integer *ia, integer *
	nfirst, integer *iperm, integer *mask, integer *maskval, integer *
	riord, integer *levels, integer *nlev)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int add_lvst__(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    static integer j, ii, nod, iend, istart;
    static logical permut;

/* ----------------------------------------------------------------------- */
/* finds the level-structure (breadth-first-search or CMK) ordering for a */
/* given sparse matrix. Uses add_lvst. Allows an set of nodes to be */
/* the initial level (instead of just one node). */
/* -------------------------parameters------------------------------------ */
/* on entry: */
/* --------- */
/*     n      = number of nodes in the graph */
/*     ja, ia = pattern of matrix in CSR format (the ja,ia arrays of csr data */
/*     structure) */
/*     nfirst = number of nodes in the first level that is input in riord */
/*     iperm  = integer array indicating in which order to  traverse the graph */
/*     in order to generate all connected components. */
/*     if iperm(1) .eq. 0 on entry then BFS will traverse the nodes */
/*     in the  order 1,2,...,n. */

/*     riord  = (also an ouput argument). On entry riord contains the labels */
/*     of the nfirst nodes that constitute the first level. */

/*     mask   = array used to indicate whether or not a node should be */
/*     condidered in the graph. see maskval. */
/*     mask is also used as a marker of  visited nodes. */

/*     maskval= consider node i only when:  mask(i) .eq. maskval */
/*     maskval must be .gt. 0. */
/*     thus, to consider all nodes, take mask(1:n) = 1. */
/*     maskval=1 (for example) */

/*     on return */
/*     --------- */
/*     mask   = on return mask is restored to its initial state. */
/*     riord  = `reverse permutation array'. Contains the labels of the nodes */
/*     constituting all the levels found, from the first level to */
/*     the last. */
/*     levels = pointer array for the level structure. If lev is a level */
/*     number, and k1=levels(lev),k2=levels(lev+1)-1, then */
/*     all the nodes of level number lev are: */
/*     riord(k1),riord(k1+1),...,riord(k2) */
/*     nlev   = number of levels found */
/* ----------------------------------------------------------------------- */

    /* Parameter adjustments */
    --mask;
    --iperm;
    --ja;
    --ia;
    --riord;
    --levels;

    /* Function Body */
    permut = iperm[1] != 0;

/*     start pointer structure to levels */

    *nlev = 0;

/*     previous end */

    istart = 0;
    ii = 0;

/*     current end */

    iend = *nfirst;

/*     intialize masks to zero -- except nodes of first level -- */

    i__1 = *nfirst;
    for (j = 1; j <= i__1; ++j) {
	mask[riord[j]] = 0;
/* L12: */
    }
/* ----------------------------------------------------------------------- */
/* L13: */

L1:
    ++(*nlev);
    levels[*nlev] = istart + 1;
    add_lvst__(&istart, &iend, nlev, &riord[1], &ja[1], &ia[1], &mask[1], 
	    maskval);
    if (istart < iend) {
	goto L1;
    }
L2:
    ++ii;
    if (ii <= *n) {
	nod = ii;
	if (permut) {
	    nod = iperm[nod];
	}
	if (mask[nod] == *maskval) {

/*     start a new level */

	    istart = iend;
	    ++iend;
	    riord[iend] = nod;
	    mask[nod] = 0;
	    goto L1;
	} else {
	    goto L2;
	}
    }
/* ----------------------------------------------------------------------- */
/* L3: */
    levels[*nlev + 1] = iend + 1;
    i__1 = iend;
    for (j = 1; j <= i__1; ++j) {
	mask[riord[j]] = *maskval;
    }
/* ----------------------------------------------------------------------- */
    return 0;
} /* bfs_ */

/* Subroutine */ int add_lvst__(integer *istart, integer *iend, integer *nlev,
	 integer *riord, integer *ja, integer *ia, integer *mask, integer *
	maskval)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k, ir, nod;

/* ------------------------------------------------------------- */
/*     adds one level set to the previous sets.. */
/*     span all nodes of previous mask */
/* ------------------------------------------------------------- */
    /* Parameter adjustments */
    --mask;
    --ia;
    --ja;
    --riord;

    /* Function Body */
    nod = *iend;
    i__1 = *iend;
    for (ir = *istart + 1; ir <= i__1; ++ir) {
	i__ = riord[ir];
	i__2 = ia[i__ + 1] - 1;
	for (k = ia[i__]; k <= i__2; ++k) {
	    j = ja[k];
	    if (mask[j] == *maskval) {
		++nod;
		mask[j] = 0;
		riord[nod] = j;
	    }
/* L24: */
	}
/* L25: */
    }
    *istart = *iend;
    *iend = nod;
    return 0;
} /* add_lvst__ */

/* Subroutine */ int stripes_(integer *nlev, integer *riord, integer *levels, 
	integer *ip, integer *map, integer *mapptr, integer *ndom)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer k, ib, ktr, ilev, nsiz, psiz;

/* ----------------------------------------------------------------------- */
/*    this is a post processor to BFS. stripes uses the output of BFS to */
/*    find a decomposition of the adjacency graph by stripes. It fills */
/*    the stripes level by level until a number of nodes .gt. ip is */
/*    is reached. */
/* ---------------------------parameters----------------------------------- */
/* on entry: */
/* -------- */
/* nlev   = number of levels as found by BFS */
/* riord  = reverse permutation array produced by BFS -- */
/* levels = pointer array for the level structure as computed by BFS. If */
/*          lev is a level number, and k1=levels(lev),k2=levels(lev+1)-1, */
/*          then all the nodes of level number lev are: */
/*                      riord(k1),riord(k1+1),...,riord(k2) */
/*  ip    = number of desired partitions (subdomains) of about equal size. */

/* on return */
/* --------- */
/* ndom     = number of subgraphs (subdomains) found */
/* map      = node per processor list. The nodes are listed contiguously */
/*            from proc 1 to nproc = mpx*mpy. */
/* mapptr   = pointer array for array map. list for proc. i starts at */
/*            mapptr(i) and ends at mapptr(i+1)-1 in array map. */
/* ----------------------------------------------------------------------- */
/* local variables. */

    /* Parameter adjustments */
    --levels;
    --riord;
    --map;
    --mapptr;

    /* Function Body */
    *ndom = 1;
    ib = 1;
/* to add: if (ip .le. 1) then ... */
    nsiz = levels[*nlev + 1] - levels[1];
/* Computing MAX */
    i__1 = 1, i__2 = *ip - *ndom + 1;
    psiz = (nsiz - ib) / max(i__1,i__2) + 1;
    mapptr[*ndom] = ib;
    ktr = 0;
    i__1 = *nlev;
    for (ilev = 1; ilev <= i__1; ++ilev) {

/*     add all nodes of this level to domain */

	i__2 = levels[ilev + 1] - 1;
	for (k = levels[ilev]; k <= i__2; ++k) {
	    map[ib] = riord[k];
	    ++ib;
	    ++ktr;
	    if (ktr >= psiz || k >= nsiz) {
		++(*ndom);
		mapptr[*ndom] = ib;
/* Computing MAX */
		i__3 = 1, i__4 = *ip - *ndom + 1;
		psiz = (nsiz - ib) / max(i__3,i__4) + 1;
		ktr = 0;
	    }

/* L3: */
	}
/* L10: */
    }
    --(*ndom);
    return 0;
} /* stripes_ */

integer maskdeg_(integer *ja, integer *ia, integer *nod, integer *mask, 
	integer *maskval)
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer k, deg;

/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --mask;
    --ia;
    --ja;

    /* Function Body */
    deg = 0;
    i__1 = ia[*nod + 1] - 1;
    for (k = ia[*nod]; k <= i__1; ++k) {
	if (mask[ja[k]] == *maskval) {
	    ++deg;
	}
    }
    ret_val = deg;
    return ret_val;
} /* maskdeg_ */

/* Subroutine */ int perphn_(integer *n, integer *ja, integer *ia, integer *
	init, integer *mask, integer *maskval, integer *nlev, integer *riord, 
	integer *levels)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, deg;
    extern /* Subroutine */ int bfs_(integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *);
    static integer nod, iperm[1], nlevp, mindeg, nfirst;
    extern integer maskdeg_(integer *, integer *, integer *, integer *, 
	    integer *);

/* ----------------------------------------------------------------------- */
/*     finds a peripheral node and does a BFS search from it. */
/* ----------------------------------------------------------------------- */
/*     see routine  dblstr for description of parameters */
/* input: */
/* ------- */
/* ja, ia  = list pointer array for the adjacency graph */
/* mask    = array used for masking nodes -- see maskval */
/* maskval = value to be checked against for determing whether or */
/*           not a node is masked. If mask(k) .ne. maskval then */
/*           node k is not considered. */
/* init    = init node in the pseudo-peripheral node algorithm. */

/* output: */
/* ------- */
/* init    = actual pseudo-peripherial node found. */
/* nlev    = number of levels in the final BFS traversal. */
/* riord   = */
/* levels  = */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --levels;
    --riord;
    --mask;
    --ia;
    --ja;

    /* Function Body */
    nlevp = 0;
L1:
    riord[1] = *init;
    nfirst = 1;
    iperm[0] = 0;

    bfs_(n, &ja[1], &ia[1], &nfirst, iperm, &mask[1], maskval, &riord[1], &
	    levels[1], nlev);
    if (*nlev > nlevp) {
	mindeg = *n + 1;
	i__1 = levels[*nlev + 1] - 1;
	for (j = levels[*nlev]; j <= i__1; ++j) {
	    nod = riord[j];
	    deg = maskdeg_(&ja[1], &ia[1], &nod, &mask[1], maskval);
	    if (deg < mindeg) {
		*init = nod;
		mindeg = deg;
	    }
	}
	nlevp = *nlev;
	goto L1;
    }
    return 0;
} /* perphn_ */

/* Subroutine */ int rversp_(integer *n, integer *riord)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k;

/* ----------------------------------------------------------------------- */
/*     this routine does an in-place reversing of the permutation array */
/*     riord -- */
/* ----------------------------------------------------------------------- */
    /* Parameter adjustments */
    --riord;

    /* Function Body */
    i__1 = *n / 2;
    for (j = 1; j <= i__1; ++j) {
	k = riord[j];
	riord[j] = riord[*n - j + 1];
	riord[*n - j + 1] = k;
/* L26: */
    }
    return 0;
} /* rversp_ */

/* ----------------------------------------------------------------------c */
/*     Non-SPARSKIT utility routine */
/* ----------------------------------------------------------------------c */
/* Subroutine */ int atob_(integer *n, doublereal *a, integer *ja, integer *
	ia, doublereal *b, integer *jb, integer *ib)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

/* ... Copy matrix a,ja,ia to b,jb,ib.  Both matrices are in */
/*     compressed sparse row format. */
/* ... Input arguments: */
/* ... Output arguments: */
/* ... Local variable: */
    /* Parameter adjustments */
    --ib;
    --ia;
    --a;
    --ja;
    --b;
    --jb;

    /* Function Body */
    i__1 = ia[*n + 1] - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	b[i__] = a[i__];
	jb[i__] = ja[i__];
    }
    i__1 = *n + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ib[i__] = ia[i__];
    }
    return 0;
/*  end of atob */
} /* atob_ */

