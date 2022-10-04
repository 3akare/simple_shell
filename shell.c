#include "shell.h"
/**
 * shell_execute - executes commands gotten from the stdin
 *
 * @argv: an array of strings
 * Return: Always Successful
 */

int shell_execute(char **argv)
{
	size_t size = 10;
	char *lineptr = malloc(50 * sizeof(char));
	char **arguments;
	int success = 0, status;
	pid_t child_pid;

	while (1)
	{
		printf("$ ");
		getline(&lineptr, &size, stdin);
		arguments = get_sh_tokens(lineptr);
		if (arguments == NULL)
			exit_error_non_interactive(argv[0], lineptr);
		child_pid = fork();
		if (child_pid == 0)
		{
			success = execvp(arguments[0], arguments);
			if (success == -1)
				exit_error_non_interactive(argv[0], lineptr);
		}
		else
			wait(&status);
	}
	free(lineptr);
	free(arguments);
	return (0);
}
