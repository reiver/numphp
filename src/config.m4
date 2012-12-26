PHP_ARG_ENABLE(num, whether to enable NumPHP support,
[ --enable-num   Enable NumPHP support])

num_sources="num.c num_add.c "

if test "$PHP_NUM" = "yes"; then
  AC_DEFINE(HAVE_NUM, 1, [Whether you have NumPHP])
  PHP_NEW_EXTENSION(num, $num_sources, $ext_shared)
fi
