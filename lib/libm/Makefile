DEFAULT_HOST!=$(TOOLSDIR)/default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=$(TOOLSDIR)/target-triplet-to-arch.sh $(HOST)

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

SRCDIR=src
DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib

CFLAGS:=$(CFLAGS) -ffreestanding -Wall -Wextra
CPPFLAGS:=$(CPPFLAGS) -D__IS_LIBM -Iinclude

ARCHDIR=arch/$(HOSTARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)

FREEOBJS=\
	$(ARCH_FREEOBJS) \

HOSTEDOBJS=\
	$(ARCH_HOSTEDOBJS) \

OBJS=\
	$(FREEOBJS) \
	$(HOSTEDOBJS) \

BINARIES=libm.a

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libm.o .c .S

all: $(BINARIES)

libm.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu89 $(CFLAGS) $(CPPFLAGS)

.S.o:
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)

.c.libm.o:
	$(CC) -MD -c $< -o $@ -std=gnu89

# clean:
#	rm -f $(BINARIES) *.a
#	rm -f $(OBJS) 

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)

-include $(OBJS:.o=.d)
# -include $(LIBK_OBJS:.o=.d)

