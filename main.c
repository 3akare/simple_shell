#include "shell.h"

/**
 * non_interactive_mode - enables the shell to work in non-interactive mode
 *
 * @argv: an array of strings
 * Return: Always Successful
 */

int non_interactive_mode(char **argv)
{
	size_t size = 10;
	pid_t child_pid;
	int status, success = 0;
	char *lineptr = malloc(50 * sizeof(char));
	char new_lineptr[100];
	char **arguments;

	while (getline(&lineptr, &size, stdin) != -1)
	{
		strcpy(new_lineptr, lineptr);
		arguments = get_sh_tokens(new_lineptr);
		if (arguments == NULL)
			exit_error_non_interactive(argv[0], new_lineptr);
		child_pid = fork();
		if (child_pid == 0)
		{
			success = execvp(arguments[0], arguments);
			if (success == -1)
				exit_error_non_interactive(argv[0], new_lineptr);
		}
		else
			wait(&status);
	}
	free(lineptr);
	exit(0);
}


/**
 * main - The main function of the shell
 *
 * @ac: count of CMD line arguments vectors
 * @argv: an array of CMD line argument vectors
 * Return: Always Succesful
 */

int main(int __attribute__((unused)) ac, char __attribute__((unused))*argv[])
{
	if (isatty(STDIN_FILENO) == 1)
		shell_execute(argv);
	else if (isatty(STDIN_FILENO == 0))
		non_interactive_mode(argv);
	else
		dprintf(STDERR_FILENO, "failed");
	return (0);
}
