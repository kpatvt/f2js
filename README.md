# f2js
Useful Fortran routines converted to JS/Webassembly using emscripten. 
Currently ODEPACK, MINPACK and DASKR have been ported.
The original FORTRAN code was converted to C using f2c and the f2c library is bundled with code.

This code was built on WSL with the latest emscripten compiler.

Setup emscripten and make sure emcc is available to your path.

Each directory is self-contained and compiles with its own copy of f2c.
When used in WASM code, the unused object files/code will be stripped away.

There are demos in each folder that correspond to the original demos provided with the FORTRAN code.

For example to run the demos in odepack:

    cd odepack
    make -j4
    node demo1.js

You should see the following output:

    Demonstration program for DLSODE package


    Problem 1:  Van der Pol oscillator:
    xdotdot - 3*(1 - x**2)*xdot + x = 0,    x(0) = 2, xdot(0) = 0
    neq = 2
    itol =  1   rtol =    .0E+00   atol =    .1E-05





    Solution with mf = 10

    t               x               xdot       nq      h


    .13928E+01      .16801E+01     -.291E+00    3      .123E+00
    .36076E+01     -.77986E-04     -.317E+01    5      .217E-01
    .58224E+01     -.16801E+01      .291E+00    3      .475E-01
    .80372E+01      .11669E-03      .317E+01    5      .234E-01


    Final statistics for this run:
    rwork size =  52   iwork size =  20
    number of steps =  297
    number of f-s   =  352
    (excluding J-s) =  352
    number of J-s   =    0
    error overrun =   .12E+03

    (... output removed for brevity)
    ----------------------------------------------------------------------


    Problem 2: ydot = A * y , where  A is a banded lower triangular matrix
        derived from 2-D advection PDE
    neq = 25   ml = 5   mu = 0
    itol =  1   rtol =    .0E+00   atol =    .1E-05





    Solution with mf = 10

    t             max.err.     nq      h


    .10000E-01      .556E-06    2      .766E-02
    .10000E+00      .655E-05    3      .249E-01
    .10000E+01      .274E-05    4      .520E-01
    .10000E+02      .114E-05    3      .117E+00
    .10000E+03      .221E-05    2      .262E+00


    Final statistics for this run:
    rwork size = 420   iwork size =  20
    number of steps =  524
    number of f-s   =  552
    (excluding J-s) =  552
    number of J-s   =    0
    error overrun =   .65E+01


    (... output removed for brevity)


    Solution with mf = 25

    t             max.err.     nq      h


    .10000E-01      .104E-05    2      .608E-02
    .10000E+00      .463E-06    3      .146E-01
    .10000E+01      .247E-05    5      .666E-01
    .10000E+02      .828E-06    5      .391E+00
    .10000E+03      .384E-09    1      .108E+03


    Final statistics for this run:
    rwork size = 522   iwork size =  45
    number of steps =  118
    number of f-s   =  244
    (excluding J-s) =  136
    number of J-s   =   18
    error overrun =   .25E+01




    Number of errors encountered =  0    
    
    
Have fun!
