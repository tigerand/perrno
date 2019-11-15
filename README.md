## perrno - print the errno mnemonic from your program
#### _perrno_ is a system to create a header file that you can include in your C/C++/Obj-C project that allows you to print out the errno mnemonic [rather than the strerr/perror message].  Are you sick of the perror messages?  Of course you are!  Do they often give you inpenetrable, and therefore useless, verbiage that is usually impossible to incorporate into a coherent error message for your users?  Then this little system is for you!

The system works like this: run the shell script **generate-perrno_h.sh**, and it will produce the header file _perrno.h_ which you can include into one of your source files.  There are two functions available for your use:<br>
```const char *perrno(int errno)```<br>
and<br>
```const char *strerrno(int errno)```

