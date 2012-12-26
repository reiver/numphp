#!/bin/sh

rm -fR BUILD/
mkdir BUILD
cp src/config.m4        BUILD/
cp src/config.w32       BUILD/
cp src/num.h            BUILD/
cp src/num.c            BUILD/
cp src/num_types.h      BUILD/
cp src/num_add.c        BUILD/
cp src/num_dimension.c  BUILD/
cp src/num_mathml.c     BUILD/
cp src/num_types.c      BUILD/
cd BUILD
phpize
./configure --enable-num
make
echo '';
echo '';
echo '';
echo '=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=';
echo '';
echo 'The extension should be at: BUILD/modules/num.so';
echo '';
echo '=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=';
echo '';
