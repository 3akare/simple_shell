#include "main.h"

/**
 * run_sh_loop - function entry point
 * Desc: Runs a loop in the shell until exit condition is met
 *
 * Return: void
 */
void run_sh_loop(void)
{
	char *input;
	char **args;
	int status;

	do {
		printf("> ");
		input = get_sh_input(); /* Get input form the stdin */
		args = get_sh_tokens(input); /* split the 'input' into args */
		status = execute_sh(args); /* execute sh using args */

		free(input); /* Clear str at address for next iteration */
		free(args); /* Clear args list for next iteration */
	} while (status);
}


/**
 * get_sh_input - function entry point
 * Desc: Reads the input from the stdin and stores in a buffer
 *
 * Return: a buffer containing the input
 */
char *get_sh_input(void)
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		perror("Error: allocation error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar(); /* Reads just a single character from the stdin */

		if (c == EOF || c == '\n') /*If we reach the end of the input*/
		{
			buffer[position] = '\0'; /*add a null byte at endof buf*/
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;

		if (position >= bufsize)
		{
			bufsize += 1024;
			buffer = realloc(buffer, bufsize); /* Realloc buffer*/
			if (!buffer)
			{
				perror("Error: reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}


/**
 * get_sh_tokens - function entry point
 * @line: str to separate into tokens
 * Desc: separate line into tokens using a delimiter
 *
 * Return: a pointer to an array containing the tokens
 */
char **get_sh_tokens(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Error: allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");/*Create tokens from the str 'line'*/
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Error: reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute_sh - function entry point
 * @args: an array of pointers to tokens
 * Desc: Launches the shell and uses the tokens as commands
 *
 * Return: an int to signal end of shell
 */
int execute_sh(char **args)
{
	pid_t child_pid, wpid;
	int status;

	if (args[0] == NULL)
	{
		perror("Error: no command entered :(");
		return (1); /* Upon execution if no args are passed */
	}

	child_pid = fork(); /* Create a child process from parent */
	if (child_pid == 0) /* if fork is successful */
	{
		if (execve(args[0], args, NULL) == -1) /*Execute args[0] if success*/
			perror("Error: "); /*To the stderr if args[0] not found*/
		exit(EXIT_FAILURE); /* Exits child process cleanly */
	}
	else if (child_pid < 0) /* Enter conditional block if fork failed */
	{
		perror("Error: "); /*Print to the stderr but don't return yet*/
	}
	else
	{ /* Execute parent process after a successful fork */
		do {  /* Wait for the child*/
			wpid = waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
