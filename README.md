## perrno - print the errno mnemonic from your program
#### _perrno_ is a system to create a header file that you can include in your C/C++/Obj-C project that allows you to print out the errno mnemonic \[rather than the strerr/perror message\].  Are you sick of using the poorly thought out perror or strerr C library functions?  Of course you are!  Do they often give you inpenetrable, and therefore useless, verbiage that is usually impossible to incorporate into a coherent error message for your users?  Not to mention hard to use.  Then this little system is for you!

The system works like this: run the shell script **generate-perrno_h.sh**, and it will produce the header file _perrno.h_ which you can include into one of your source files.  There are two functions available for your use:<br>
```const char *perrno(int errno)```<br>
and<br>
```const char *strerrno(int errno)```


*perrno* is called with the errno as the argument, and returns a pointer to a NULL terminated const static string of the errno mnemonic.  For example, if the errno is 4, the returned pointer would point to the string "EINTR".

RETURN VALUE

If no mnemonic can be found for this errno, for instance it's an invalid errno like 0 or 5600, then the function returns NULL.


*strerrno* is the same as *perrno* except that the pointer returned points to the error message that is possibly the same as returned by _perror_ C library function, except that it can't get messed by in a multi-threaded program and such.

Both of these functions are MT Safe.  The pointers returned can be passed as arguments to other functions, or saved for later use, without fear.  They are pointers to const char arrays, so hopefully users of this code are smart enough not to change the strings themselves.
