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
	char *lineptr = malloc(100 * sizeof(char));
	char new_lineptr[100];
	char **arguments;

	while (getline(&lineptr, &size, stdin) != -1)
	{
		if (strcmp(lineptr, "exit\n") == 0)
		{
			free(lineptr);
			exit(0);
		}
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
	return (0);
}


/**
 * main - The main function of the shell
 *
 * @ac: count of CMD line arguments vectors
 * @argv: an array of CMD line argument vectors
 * Return: Always Succesful
 */

int main(int __attribute__((unused)) ac, char *argv[])
{
	if (!isatty(STDIN_FILENO))
		non_interactive_mode(argv);
	else
		shell_execute(argv);
	return (0);
}
