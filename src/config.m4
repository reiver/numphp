PHP_ARG_ENABLE(numphp, whether to enable NumPHP support, [ --enable-numphp   Enable NumPHP support])
if test "$PHP_NUMPHP" = "yes"; then
  AC_DEFINE(HAVE_NUMPHP, 1, [Whether you have NumPHP])
  PHP_NEW_EXTENSION(numphp, numphp.c, $ext_shared)
fi
