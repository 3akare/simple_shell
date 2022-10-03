# hsh - Simple Shell
A simple UNIX command interpreter that reads commands from standard input and executes them.

## Compliation
Use, 

```
gcc @flags *.c -o hsh 
```

to compile all `.c` files in the repository and,

```
./hsh
```

to run the resulting executable.

**hsh** can be invoked non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
If **hsh** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **hsh** displays the prompt `$ ` when it is ready to read a command.

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
# Authors
- [David Bakare](https://github.com/3akare)
- [Michael Rowland](https://github.com/mykie88)

# Acknowledgements
This project was written as part of the curriculum for Holberton School.