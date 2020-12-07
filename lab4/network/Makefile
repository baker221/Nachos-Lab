# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the network assignment
#    Defines set up assuming this assignment is done last 
#    If not, use the "bare bones"  defines below. 
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM -DVM -DFILESYS_NEEDED -DFILESYS -DNETWORK
INCPATH = -I../network -I../bin -I../filesys -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H) $(FILESYS_H) $(NETWORK_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C) $(FILESYS_C) $(NETWORK_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O) $(FILESYS_O) $(NETWORK_O)

# bare bones version
# DEFINES =-DTHREADS -DNETWORK
# INCPATH = -I../network -I../threads -I../machine
# HFILES = $(THREAD_H) $(NETWORK_H)
# CFILES = $(THREAD_C) $(NETWORK_C)
# C_OFILES = $(THREAD_O) $(NETWORK_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/system.h \
 ../machine/interrupt.h ../threads/copyright.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/scheduler.h ../threads/list.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
list.o: ../threads/list.cc ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
scheduler.o: ../threads/scheduler.cc ../threads/scheduler.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/utility.h \
 ../machine/translate.h ../machine/machine.h ../machine/disk.h \
 ../machine/translate.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/system.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
synch.o: ../threads/synch.cc ../threads/synch.h ../threads/copyright.h \
 ../threads/list.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/utility.h \
 ../machine/translate.h ../machine/machine.h ../machine/disk.h \
 ../machine/translate.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/system.h ../machine/interrupt.h ../threads/list.h \
 ../threads/scheduler.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h
synchlist.o: ../threads/synchlist.cc ../threads/synchlist.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/utility.h ../machine/translate.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h
system.o: ../threads/system.cc ../threads/system.h ../threads/copyright.h \
 ../machine/interrupt.h ../threads/copyright.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/scheduler.h ../threads/list.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
thread.o: ../threads/thread.cc ../threads/thread.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/switch.h \
 ../threads/synch.h ../threads/list.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../threads/scheduler.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h
utility.o: ../threads/utility.cc ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
 ../machine/elevatortest.h ../threads/copyright.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/scheduler.h ../threads/list.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
interrupt.o: ../machine/interrupt.cc ../machine/interrupt.h \
 ../threads/copyright.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../machine/interrupt.h \
 ../threads/scheduler.h ../threads/list.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/utility.h ../machine/translate.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
 /usr/include/signal.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h \
 /usr/include/i386-linux-gnu/bits/signum.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/siginfo.h \
 /usr/include/i386-linux-gnu/bits/sigaction.h \
 /usr/include/i386-linux-gnu/bits/sigcontext.h \
 /usr/include/i386-linux-gnu/asm/sigcontext.h /usr/include/linux/types.h \
 /usr/include/i386-linux-gnu/asm/types.h /usr/include/asm-generic/types.h \
 /usr/include/asm-generic/int-ll64.h \
 /usr/include/i386-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/i386-linux-gnu/asm/posix_types.h \
 /usr/include/i386-linux-gnu/asm/posix_types_32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/sigstack.h \
 /usr/include/i386-linux-gnu/sys/ucontext.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/sigthread.h /usr/include/stdio.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/i386-linux-gnu/sys/file.h \
 /usr/include/fcntl.h /usr/include/i386-linux-gnu/bits/fcntl.h \
 /usr/include/i386-linux-gnu/sys/types.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/uio.h \
 /usr/include/i386-linux-gnu/bits/stat.h \
 /usr/include/i386-linux-gnu/sys/mman.h \
 /usr/include/i386-linux-gnu/bits/mman.h \
 /usr/include/i386-linux-gnu/sys/socket.h \
 /usr/include/i386-linux-gnu/sys/uio.h \
 /usr/include/i386-linux-gnu/bits/socket.h \
 /usr/include/i386-linux-gnu/bits/sockaddr.h \
 /usr/include/i386-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h \
 /usr/include/i386-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/i386-linux-gnu/sys/time.h \
 /usr/include/i386-linux-gnu/sys/un.h /usr/include/errno.h \
 /usr/include/i386-linux-gnu/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/i386-linux-gnu/asm/errno.h /usr/include/asm-generic/errno.h \
 /usr/include/asm-generic/errno-base.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/system.h ../machine/interrupt.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/utility.h \
 ../machine/translate.h ../machine/machine.h ../machine/disk.h \
 ../machine/translate.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
stats.o: ../machine/stats.cc ../machine/stats.h ../threads/copyright.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
timer.o: ../machine/timer.cc ../machine/timer.h ../threads/copyright.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
elevatortest.o: ../machine/elevatortest.cc ../machine/elevatortest.h \
 ../threads/copyright.h ../machine/elevator.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/utility.h ../threads/synch.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/thread.h
elevator.o: ../machine/elevator.cc ../machine/elevator.h \
 ../threads/copyright.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/utility.h ../threads/system.h \
 ../machine/interrupt.h ../threads/scheduler.h ../threads/list.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../machine/translate.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
addrspace.o: ../userprog/addrspace.cc ../userprog/addrspace.h \
 ../threads/copyright.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../bin/noff.h \
 ../threads/system.h ../machine/interrupt.h ../threads/list.h \
 ../threads/utility.h ../threads/scheduler.h ../threads/list.h \
 ../threads/thread.h ../userprog/addrspace.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
bitmap.o: ../userprog/bitmap.cc ../userprog/bitmap.h \
 ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
exception.o: ../userprog/exception.cc ../threads/copyright.h \
 ../machine/machine.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/syscall.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
 ../threads/scheduler.h ../threads/list.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../machine/translate.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h ../userprog/addrspace.h
progtest.o: ../userprog/progtest.cc ../userprog/addrspace.h \
 ../threads/copyright.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/console.h \
 ../threads/synch.h ../threads/list.h ../threads/utility.h \
 ../threads/thread.h ../userprog/addrspace.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/scheduler.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
console.o: ../machine/console.cc ../machine/console.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
machine.o: ../machine/machine.cc ../machine/machine.h \
 ../threads/copyright.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
 ../machine/machine.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/mipssim.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
 ../threads/scheduler.h ../threads/list.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../machine/translate.h ../machine/machine.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
translate.o: ../machine/translate.cc ../userprog/addrspace.h \
 ../threads/copyright.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../machine/machine.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
directory.o: ../filesys/directory.cc ../filesys/directory.h \
 ../threads/copyright.h ../filesys/openfile.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/filehdr.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/disk.h
filehdr.o: ../filesys/filehdr.cc ../threads/copyright.h \
 ../filesys/filehdr.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/disk.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
 ../threads/scheduler.h ../threads/list.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../machine/translate.h ../machine/machine.h ../machine/disk.h \
 ../machine/translate.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../threads/synch.h ../network/post.h \
 ../machine/network.h ../threads/synchlist.h ../threads/synch.h
filesys.o: ../filesys/filesys.cc ../threads/copyright.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/directory.h ../filesys/openfile.h \
 ../machine/disk.h ../filesys/filehdr.h ../filesys/filesys.h
fstest.o: ../filesys/fstest.cc ../threads/copyright.h ../machine/disk.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/filesys.h ../filesys/openfile.h \
 ../machine/stats.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../machine/translate.h ../machine/machine.h \
 ../machine/disk.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/timer.h ../filesys/synchdisk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h ../threads/thread.h
openfile.o: ../filesys/openfile.cc ../filesys/openfile.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/filehdr.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/disk.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../threads/utility.h \
 ../threads/scheduler.h ../threads/list.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
synchdisk.o: ../filesys/synchdisk.cc ../filesys/synchdisk.h \
 ../threads/copyright.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/list.h \
 ../threads/utility.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h
disk.o: ../machine/disk.cc ../machine/disk.h ../threads/copyright.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/scheduler.h \
 ../threads/list.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/translate.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h ../machine/network.h ../threads/synchlist.h \
 ../threads/synch.h
nettest.o: ../network/nettest.cc ../threads/copyright.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/network.h ../threads/utility.h \
 ../network/post.h ../threads/synchlist.h ../threads/list.h \
 ../threads/synch.h ../threads/thread.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../threads/system.h \
 ../threads/scheduler.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../network/post.h
post.o: ../network/post.cc ../network/post.h ../threads/copyright.h \
 ../machine/network.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synchlist.h ../threads/list.h \
 ../threads/utility.h ../threads/synch.h ../threads/thread.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../machine/translate.h ../machine/machine.h ../machine/disk.h \
 ../machine/translate.h ../userprog/bitmap.h ../filesys/openfile.h
network.o: ../machine/network.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../machine/interrupt.h \
 ../threads/list.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h ../threads/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/scheduler.h ../threads/list.h \
 ../threads/thread.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/utility.h ../machine/translate.h \
 ../machine/machine.h ../machine/disk.h ../machine/translate.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h ../network/post.h ../machine/network.h \
 ../threads/synchlist.h ../threads/synch.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
