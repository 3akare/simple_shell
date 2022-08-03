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
