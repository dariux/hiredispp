#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.66])
AC_INIT([Hiredispp], [0.1], [])
AM_INIT_AUTOMAKE([foreign subdir-objects dist-bzip2 dist-lzma])
AM_SILENT_RULES([yes])
LT_PREREQ([2.2])
LT_INIT
AC_CONFIG_SRCDIR([hiredispp.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

case ${program_prefix} in
    NONE) program_prefix=hiredispp- ;;
esac

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_LANG(C++)

AC_ARG_ENABLE([coverage], [AS_HELP_STRING([--enable-coverage],
              [enable code coverage statistics @<:@default: no@:>@])],
              [enable_coverage=${enableval}], [enable_coverage=no])

COVERAGE_CXXFLAGS=
COVERAGE_LDADD=
if test x"${enable_coverage}" = xyes; then
    AC_CHECK_PROG(LCOV, lcov, lcov)
    if test x"${LCOV}" = xlcov; then
        COVERAGE_CXXFLAGS="-fprofile-arcs -ftest-coverage"
        COVERAGE_LDADD="-lgcov"
    else
        AC_MSG_WARN([Could not find lcov for test coverage])
        enable_coverage=no
    fi
fi
AC_SUBST([COVERAGE_CXXFLAGS], [${COVERAGE_CXXFLAGS}])
AC_SUBST([COVERAGE_LDADD], [${COVERAGE_LDADD}])

# Checks for header files.
AC_CHECK_HEADERS([string vector map stdexcept])
AC_CHECK_HEADER([hiredis/hiredis.h],,[AC_MSG_ERROR([
-------------------------------------------------
Hiredispp relies upon the hiredis library.
Please install hiredis to continue.
-------------------------------------------------])])
AC_CHECK_HEADERS([boost/lexical_cast.hpp boost/cstdint.hpp boost/optional.hpp],,[AC_MSG_ERROR([
-------------------------------------------------
Hiredispp relies upon the boost library.
Please install boost to continue.
-------------------------------------------------])])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MMAP
AC_CHECK_FUNCS([alarm clock_gettime ftruncate memmove mkdir munmap rmdir socket])

AM_CONDITIONAL([ENABLE_COVERAGE], [test x"${enable_coverage}" = xyes])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
