#!/bin/bash
gcc -Wall -pedantic -Wextra -Werror -std=gnu89 -g *.c -o shelly
sleep 1
alias shelly="./shelly*"
./shelly
