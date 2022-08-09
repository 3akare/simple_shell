/*
 * File: helper.c
 * Auth: Michael Rowland
 * David Bakare
 */

#include "main.h"

/**
 * _putchar - prints out a single character
 * @c: the character to be printed out
 *
 * Return: success (1)
 */

int _putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * is_delim - determines if @c is a delimiter
 * @delim: a string of delimiters
 * @c: a character
 * Return: succes(0)
 */

unsigned int is_delim(char c, string delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
		{
			return (1);
		}
		delim++;
	}
	return (0);
}

/**
 * bin_check - checks if the first char in @args is '/'
 * if it isn't, it concatenates args[0] to "/usr/bin/"
 *
 * @args: An array of strings (commmands)
 * @envp: An Array of strings (environment)
 */

void bin_check(char **args, char **envp)
{
	char cmd[100];
	char binary[] = "/usr/bin/";

	if (args[0][0] != '/')
	{
		strcpy(cmd, binary);
		strcat(cmd, args[0]);
		if (execve(cmd, args, envp) == -1)
		{
			perror("Error!");
			exit(EXIT_FAILURE);
		}
	}
	if (execve(args[0], args, envp) == -1) /*Execute args[0] if success*/
	{
		perror("Error!"); /*To the stderr if args[0] not found*/
		exit(EXIT_FAILURE); /* Exits child process cleanly */
	}
}
