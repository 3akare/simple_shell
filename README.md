# Shelly - Simple Shell

**Shelly** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

# Usage

To invoke **shelly**, complie all `.c` files in the repository and run the resulting executable:

```
gcc *.c -o shelly
./shelly
```
or

```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o shelly
alias shelly="./shelly"
shelly
```
