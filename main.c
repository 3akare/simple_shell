/*
 * File: main.c
 * Auth: Michael Rowland
 * David Bakare
 */

#include "shell.h"

/**
 * main - Runs a simple UNIX command interpreter
 * @argc: The number of command line arguments supplied to the program
 * @argv: An array of pointers containing command line arguments
 *
 * Return: success (0), fail (1)
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	start_shell(argv[0]); /*run shell loop until exit condition is met*/
	exit(EXIT_SUCCESS);
}
