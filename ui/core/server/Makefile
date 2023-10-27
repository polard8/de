
# GRAMLAND.BIN
# GWS - Gramland Window Server.
# 2020 - Created by Fred Nora.

linkTarget = GRAMLAND.BIN

# See: https://linux.die.net/man/1/ld
# -s --strip-all:   Omit all symbol information from the output file.
# -x --discard-all: Delete all local symbols.
# -static: Do not link against shared libraries. 
# -M --print-map:   Print a link map to the standard output.
# LDFLAGS := -m elf_x86_64 -static
# LDFLAGS := -m elf_x86_64 -s -x -static  

#linkFlags  = -m elf_x86_64 \
#-s -x -static -T ../../link.ld

linkFlags  = -m elf_x86_64 \
-s -x -static -T link.ld


VERSION = 0
PATCHLEVEL = 1
SUBLEVEL = 0
EXTRAVERSION = 
#NAME = GWS

# Make variables (CC, etc...)
AS	= as
LD	= ld
CC	= gcc
AR	= ar
MAKE	= make
NASM	= nasm
OBJCOPY	= objcopy
OBJDUMP	= objdump
LEX	= flex
YACC	= bison
PERL	= perl
PYTHON	= python
PYTHON2	= python2
PYTHON3	= python3
RUBY	= ruby


# usermode cross compiler flags.
CFLAGS = -Wall
#CFLAGS += -O3
CFLAGS += -Wundef
CFLAGS += -Wmissing-prototypes
CFLAGS += -Wno-uninitialized
CFLAGS += -Wno-format-security
CFLAGS += -Wno-trigraphs
CFLAGS += -Werror=strict-prototypes
CFLAGS += -Werror=implicit-function-declaration
CFLAGS += -Werror=return-type
CFLAGS += -std=gnu89
CFLAGS += -m64
CFLAGS += -s
CFLAGS += -static
CFLAGS += -fcommon
CFLAGS += -fgnu89-inline
CFLAGS += -finline-functions
CFLAGS += -fshort-wchar
CFLAGS += -ffreestanding
CFLAGS += -fleading-underscore
CFLAGS += -fstrict-overflow
CFLAGS += -nostdlib
CFLAGS += -nodefaultlibs
CFLAGS += -nostdinc
CFLAGS += -fno-builtin
CFLAGS += -fno-stack-protector
CFLAGS += -fno-strict-aliasing
CFLAGS += -fno-PIE
CFLAGS += -fno-pie
CFLAGS += -fno-omit-frame-pointer
CFLAGS += -fno-optimize-sibling-calls    


LIBC        = ../libs/rtl/include/
LIBCOBJ     = ../libs/rtl/obj

LIBDISP     = ../libs/libdisp/include/
LIBDISPOBJ  = ../libs/libdisp/obj

LIBGR       = ../libs/libgr/include/
LIBGROBJ    = ../libs/libgr/obj

CINCLUDES  = -I $(LIBC)  
CINCLUDES += -I $(LIBDISP)
CINCLUDES += -I $(LIBGR)
CINCLUDES += -I .    

# Objects
myObjects = crt0.o main.o rtl.o \
ctype.o stdio.o stdlib.o string.o conio.o socket.o signal.o unistd.o \
termios.o ioctl.o fcntl.o    

myObjects += libdisp.o
myObjects += libgr.o

myObjects += ar_root.o
myObjects += ar_rtl.o
myObjects += ar_os.o
myObjects += ar_comp.o
myObjects += ar_ui.o    

.PHONY: all all-c gws-link finalize clean

all: main.o all-c gws-link finalize clean
	@echo "Ok?"
main.o:
	$(CC) -c main.c      $(CFLAGS) $(CINCLUDES) -o main.o
all-c:

	$(CC) -c callback.c  $(CFLAGS) $(CINCLUDES) -o callback.o
	$(CC) -c client.c    $(CFLAGS) $(CINCLUDES) -o client.o
	$(CC) -c demos.c     $(CFLAGS) $(CINCLUDES) -o demos.o
	$(CC) -c globals.c   $(CFLAGS) $(CINCLUDES) -o globals.o
	$(CC) -c gws.c       $(CFLAGS) $(CINCLUDES) -o gws.o
	$(CC) -c sprite.c    $(CFLAGS) $(CINCLUDES) -o sprite.o
	$(CC) -c shutdown.c  $(CFLAGS) $(CINCLUDES) -o shutdown.o
#	$(CC) -c zres/grinput.c   $(CFLAGS) $(CINCLUDES) -o grinput.o
	$(LD) -r -o ar_root.o \
callback.o client.o demos.o \
globals.o gws.o sprite.o shutdown.o    

	make -C rtl/
	make -C comp/
	make -C os/
	make -C ui/

#
# == imported objects =============================
#

# rtl/
	cp $(LIBCOBJ)/crt0.o .
	cp $(LIBCOBJ)/rtl.o .

	cp $(LIBCOBJ)/ctype.o .
	cp $(LIBCOBJ)/stdio.o .
	cp $(LIBCOBJ)/stdlib.o .
	cp $(LIBCOBJ)/string.o .
	cp $(LIBCOBJ)/conio.o .
	cp $(LIBCOBJ)/unistd.o .
	cp $(LIBCOBJ)/socket.o .
	cp $(LIBCOBJ)/signal.o .
	cp $(LIBCOBJ)/termios.o .
	cp $(LIBCOBJ)/ioctl.o .
	cp $(LIBCOBJ)/fcntl.o .

	cp $(LIBDISPOBJ)/libdisp.o .
	cp $(LIBGROBJ)/libgr.o .

gws-link:
	$(LD) $(linkFlags) -o $(linkTarget) $(myObjects)
finalize:
#	cp $(linkTarget) ../bin/
	cp $(linkTarget) bin/
clean:
	-rm *.o
	-rm comp/*.o
	-rm os/*.o
	-rm rtl/*.o
	-rm ui/*.o
	-rm $(linkTarget)

