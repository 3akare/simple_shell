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


#define BUF_SIZE 100
#define TOK_BUF_SIZE 4
#define BUF_PWD 100
#define DELIM " \t\n\r\a"

typedef char *string; /* redefining char pointer type as "string", :)*/

/* helper functions */

int _putchar(int c);
unsigned int is_delim(char c, char *delim);
char *_strtok(char *str, char *delim);
void bin_check(char **args, char **envp);

/* shell functions - main shell functions */

void start_shell(char *cmd);
char *get_sh_input(void);
char **get_sh_tokens(char *line);
int execute_sh(char **args, char *cmd);
int init_sh(char **args, char *cmd);

/* builtin functions */

int shell_cd(char **args);
int shell_exit(char **args);

#endif
