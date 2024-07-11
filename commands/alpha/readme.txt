
 The folders:

  libs/     - The low level routines.
  toolkits/ - The wrappers.

  Some systems take so serious the consistence of the libc and 
the posix standard for this lib. I don't care!
  I don't care about the libc standard, so this way
the libc will stay in the low level and I will implement 
toolkits to call the low level functionalities in the libs/ folder.
 But remember, the libc also has the operating system specific routines
 in some cases, just like the system calls.