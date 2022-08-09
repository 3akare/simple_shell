#include "main.h"

/**
 * shell_cd - change directories function
 * @args: an array of char pointers
 *
 * Return: Always Successful
 */

int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stdout, "Usage: cd [ filename ]\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error!: unable to change directory");
		}
	}
	return (1);
}

/**
 * shell_exit - exit function
 * @args: an array of char pointers
 *
 * Return: Success (0)
 */

int shell_exit(char __attribute__((unused)) **args)
{
	return (0);
}
