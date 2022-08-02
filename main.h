#ifndef MAIN_H
#define MAIN_H

/*
 * File: main.h
 * Auth: Michael Rowland
 * David Bakare
 */


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/*
 * helper functions
 */

int _putchar(int c);
void run_sh_loop(void);
char *get_sh_input(void);
char **get_sh_tokens(char *line);
int execute_sh(char **args);

#endif
