/*
 * File:shell.c
 * Auth: Michael Rowland
 * David Bakare
 */

#include "main.h"

/**
 * start_shell - function entry point
 * Desc: Runs a loop in the shell until exit condition is met
 *
 * Return: void
 */

void start_shell(void)
{
	string input;
	char **args;
	int status;

	do {
		printf("($) ");
		input = get_sh_input(); /* Get input form the stdin */
		args = get_sh_tokens(input); /* splits the 'input' into args*/
		status = execute_sh(args); /* execute sh using args */

		free(input); /* Clear input at address for next iteration */
		free(args); /* Clear args list for next iteration */
	} while (status);
}


/**
 * get_sh_input - function entry point
 * Desc: Reads the input from the stdin and stores in a buffer
 *
 * Return: a character pointer
 */
string get_sh_input(void)
{
	string buffer;
	size_t buf_size = BUF_SIZE;
	int i;

	i = getline(&buffer, &buf_size, stdin);
	if (i == -1)
	{
		perror("Error!, getline failed");
	}
	if (buffer == NULL)
	{
		perror("Error!, Bad Arguments");
	}
	return (buffer);
}


/**
 * get_sh_tokens - function entry point
 * @line: str to be separated into tokens
 * Desc: separates line into tokens using a delimiter
 *
 * Return: an array of char pointers
 */
char **get_sh_tokens(string line)
{
	int bufsize = TOK_BUF_SIZE, index = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	string token;

	if (tokens == NULL)
	{
		perror("Error: allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);/*Create tokens from the str 'line'*/
	while (token != NULL)
	{
		tokens[index] = token;
		index++;

		if (index >= bufsize)
		{
			bufsize += TOK_BUF_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				perror("Error: reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}

/**
 * execute_sh - function entry point
 * @args: an array of char pointers
 * Desc: Uses args as commands and executes them
 *
 * Return: an int to signal end of shell
 */
int execute_sh(char **args)
{
	pid_t child_pid;
	int status;

	if (args[0] == NULL)
	{
		perror("Error: no command entered :(");
		return (1); /* Upon execution if no args are passed */
	}

	child_pid = fork(); /* Create a child process from parent */
	if (child_pid == 0) /* if fork is successful */
	{
		if (execvp(args[0], args) == -1) /*Execute args[0] if success*/
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
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
