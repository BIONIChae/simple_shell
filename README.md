C - Simple Shell

Description
In this project we will be going over simple shell,
and the processes involved in curating, running it
,and interacting with the user.
The program must have the exact same output and error output as sh (/bin/sh).
The program name must be equivalent to your argv[0].

List of allowed system calls and functions:
access; chdir; close; closedir; execve; exit; _exit;
fflush; fork; free; getcwd; getline; getpid; isatty;
kill; malloc; open; opendir; perror; read; readdir;
signal; stat; lstat; fstat; strtok; wait; waitpid;
wait3; wait4; write.

Compilation
'''
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
'''
Testing
Interactive mode:
'''
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
'''
NON-Interactive mode:
'''
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls2
$
$ cat testls2
/bin/ls
/bin/ls
$
$ cat testls2 | ./hsh
hsh main.c shell.c testls2
hsh main.c shell.c testls2
$
'''
