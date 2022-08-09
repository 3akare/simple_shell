# Shelly - Simple Shell

**Shelly** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

# Invocation

To invoke **shelly**, complie all `.c` files in the repository and run the resulting executable:
```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o shelly
alias shelly="./shelly"
shelly
```
or 

```
.\run.sh
```

# Usage

`ls`- list directories content

```
/home/bakare/simple_shell$ ls
AUTHORS a.out  helper.c  main.h  strtok.c ...
```
`pwd` - print name of current/working directory
```
/home/bakare/simple_shell$ pwd
/home/bakare/simple_shell
```
`cat` - concatenate files and print on the standard output
```
/home/bakare/simple_shell$ cat AUTHORS
#This file contains all individuals that contributed content to this re...
```
# Builtin functions

`cd` - change current/working directory
```
/home/bakare/simple_shell$ pwd
/home/bakare/simple_shell
/home/bakare/simple_shell$ cd ..
/home/bakare$ pwd
/home/bakare
/home/bakare$
```
`Exit` - cause normal process termination
```
/home/bakare/simple_shell$ exit
```
# Authors #
* David Bakare
* Michael Rowland

# Acknowledgemnts #
This project was written as part of the curriculum for ALX-SE program
