## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = -I$(srcdir)/include $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

SUBDIRS = $(EXTRA_SUBDIRS) .

AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

lib_a_SOURCES = \
	chmod.c close.c crt1.c doserror.c exit.c fds.c fork.c fstat.c \
	getpid.c gettod.c isatty.c kill.c lseek.c main.c open.c read.c \
	sbrk.c write.c
EXTRA_lib_a_SOURCES = dummy.S
lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

all-local: crt0.o

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/human68k; \
	for i in $(srcdir)/include/human68k/*.h; do \
	  $(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/human68k/`basename $$i`; \
	done;

ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
