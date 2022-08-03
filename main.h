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
#include <errno.h>


#define BUF_SIZE 0
#define TOK_BUF_SIZE 4
#define DELIM " \t\n\r\a"

typedef char *string;

/*
 * helper functions
 */

int _putchar(int c);

/*
 * shell functions - basic shell functions
 */

void start_shell(void);
char *get_sh_input(void);
char **get_sh_tokens(char *line);
int execute_sh(char **args);

#endif
