#include "shell.h"

/**
 * exit_error_non_interactive - error handler for interactive mode
 *
 * @str: a string
 * @str2: a string
 */
void exit_error_non_interactive(char *str, char *str2)
{
	fprintf(stderr, "%s: 1: %s: not found\n", str, str2);
	exit(127);
}
