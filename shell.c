/*
 * File:shell.c
 * Auth: Michael Rowland
 * David Bakare
 */

#include "shell.h"

/**
 * start_shell - function entry point
 * Desc: Runs a loop in the shell until exit condition is met
 * @cmd: name of program
 *
 * Return: void
 */

void start_shell(char *cmd)
{
	string input;
	char  buffer_pwd[BUF_PWD];
	char **args;
	int status;

	do {
		if (isatty(fileno(stdin)))
		{
			/* prints the current working directory */
			printf("%s", getcwd(buffer_pwd, BUF_PWD));
			printf("$ ");
		}
		input = get_sh_input(); /* Get input form the stdin */
		args = get_sh_tokens(input); /* splits the 'input' into args*/
		status = execute_sh(args, cmd); /* execute sh using args */
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
	char ch;
	string buffer;
	int buf_size = BUF_SIZE, index = 0;

	buffer = malloc(sizeof(string) * buf_size);
	if (buffer == NULL)
	{
		perror("Error: allocation error");
		exit(EXIT_FAILURE);
	}
	while (ch != '\n')
	{
		ch = getc(stdin);
		buffer[index] = ch;
		index++;
		if (index >= buf_size)
		{
			buf_size += BUF_SIZE;
			buffer = realloc(buffer, sizeof(string) * buf_size);
			if (buffer == NULL)
			{
				perror("Error: reallocation error");
				exit(EXIT_FAILURE);
			}
		}
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
	token = _strtok(line, DELIM); /*Create tokens from the str 'line'*/
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
		token = _strtok(NULL, DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}

/**
 * execute_sh - executes arguments
 * @args: an array of char pointers
 * @cmd: name of program
 *
 * Return: a function
 */

int execute_sh(char **args, char *cmd)
{
	int i, len_builtin_func;
	char *builtin_str[] = {
		"cd",
		"exit"
	};
	int (*builtin_func[])(char **) = {
		&shell_cd,
		&shell_exit
	};

	len_builtin_func = sizeof(builtin_str) / sizeof(string);

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < len_builtin_func; i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (builtin_func[i](args));
		}
	}

	return (init_sh(args, cmd));
}

/**
 * init_sh - function entry point
 * @args: an array of char pointers
 * @cmd: name of program
 * Desc: Uses args as commands and executes them
 *
 * Return: an int to signal end of shell
 */
int init_sh(char **args, char *cmd)
{
	pid_t child_pid;
	int status;

	child_pid = fork(); /* Create a child process from parent */
	if (child_pid == 0) /* if fork is successful */
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
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
	if (!isatty(fileno(stdin)))
	{
		return (0);
	}

	return (1);
}
