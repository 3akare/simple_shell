/*
 * File: strtok.c
 * Auth: Michael Rowland
 * David Bakare
 */

#include "main.h"

/**
 * _strtok - breaks a string into a sequence of zero or more non-empty tokens.
 * @str: string to be broken
 * @delim: specifies a set of bytes that delimit the tokens in @str
 *
 * Return: a string
 */

string _strtok(string str, string delim)
{
	static string backup_string;
	string ret;

	if (!str)
		str = backup_string;   /* checks if str is NULL */
	if (!str)
		return (NULL);

	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		break;
	}
	ret = str;

	while (1)
	{
		if (*str == '\0')
		{
			backup_string = str;
			return (ret);
		}
		if (is_delim(*str, delim))
		{
			*str = '\0';
			backup_string = str + 1;
			return (ret);
		}
		str++;
	}
}
