/*
 * File: main.c
 * Auth: Michael Rowland
 *	 David Bakare
 */

#include "main.h"

/**
 * main - Runs a simple UNIX command interpreter
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: success (0), fail (1)
 */
int main(int argc, char **argv)
{
	run_sh_loop(); /*run shell loop until exit condition is meet*/

	exit(EXIT_SUCCESS);
}
