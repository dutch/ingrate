AC_INIT([ingrate],
[m4_esyscmd([build-aux/git-version-gen .tarball-version])],
[https://github.com/dutch/ingrate/issues],
[],
[https://github.com/dutch/ingrate])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects])
INGRATE_INIT
AC_PROG_CC
PKG_CHECK_MODULES([SDL], [sdl2])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
