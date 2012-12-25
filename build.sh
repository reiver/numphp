#!/bin/sh

rm -fR BUILD/
mkdir BUILD
cp src/config.m4  BUILD/
cp src/config.w32 BUILD/
cp src/numphp.h   BUILD/
cp src/numphp.c   BUILD/
cd BUILD
phpize
./configure --enable-numphp
make
echo '';
echo '';
echo '';
echo '=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=';
echo '';
echo 'The extension should be at: BUILD/modules/numphp.so';
echo '';
echo '=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=';
echo '';
