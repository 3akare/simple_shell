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
