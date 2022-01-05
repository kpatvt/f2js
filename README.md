# f2js
Useful Fortran routines converted to JS/Webassembly using emscripten. 
Currently ODEPACK, MINPACK and DASKR have been ported.
The original FORTRAN code was converted to C using f2c and the f2c library is bundled with code.

This code was built on WSL with the latest emscripten compiler.
Should work on any *nix type system where Make and emscripten are available.

Setup emscripten and make sure emcc is available to your path.

Each directory is self-contained and compiles with its own copy of f2c.
When used in WASM code, the unused object files/code will be stripped away.

There are demos in each folder that correspond to the original demos provided with the FORTRAN code.

