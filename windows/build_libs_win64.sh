#!/bin/sh
export PATH=/c/Qt/Tools/mingw730_64/bin/:$PATH
cd ../external/libraw
mingw32-make -f Makefile.mingw clean
mkdir lib/
mingw32-make -f Makefile.mingw library
cd ../../windows

