#include "shell.h"

/**
 * _strtok - breaks a string into a sequence of zero or more non-empty tokens.
 * @str: string to be broken
 * @delim: specifies a set of bytes that delimit the tokens in @str
 *
 * Return: a string
 */

char *_strtok(char *str, char *delim)
{
	static char *backup_string;
	char *ret;

	if (!str)
		str = backup_string;
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
			return (NULL);
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

/**
 * is_delim - checks if @c is a delimeter
 *
 * @c: a character
 * @delim: a MACRO containing delimeters
 * Return: 1 if @c is a delimeter, else 0
 */

unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * get_sh_tokens - returns an array of strings with the help of _strtok
 * @line: a string
 *
 * Return: an array of strings
 */

char **get_sh_tokens(char *line)
{
	int bufsize = TOK_BUF_SIZE, index = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
	return (NULL);
	token = _strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[index] = token;
		index++;
		if (index >= bufsize)
		{
			bufsize += TOK_BUF_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
				return (NULL);
		}
		token = _strtok(NULL, DELIM);
	}
	tokens[index] = NULL;
	return (tokens);
}
