#include "shell.h"
/**
 * _print_string - Prints a string to the standard output
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	char *message = "Hello, world!";

	_print_string(message);

	return (0);
}

