#ifndef _SHELL_H_
#define _SHELL_H_

#define DELIM " \n\a\t\r"
#define TOK_BUF_SIZE 4

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

unsigned int is_delim(char c, char *delim);
char **get_sh_tokens(char *line);
int non_interactive_mode(char **argv);
char *_strtok(char *str, char *delim);
int shell_execute(char **argv);
void exit_command(char *str);

/*  error handlers */

void exit_error_non_interactive(char *str, char *str2);

#endif
