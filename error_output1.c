#include "main.h"

/**
* _erratoi - function converts a string to an integer
* @s: str to be converted
* Return: 0 if no numbers in str, converted number if successful, otherwise
* -1 on error
*/
int _erratoi(char *s)
{
	int sign = 1;
	long result = 0;

	if (!s || *s == '\0')
		return (-1);

	if (*s == '+' || *s == '-')
		sign = (*s++ == '+') ? 1 : -1;

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);

		result = result * 10 + (*s - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (-1);
		s++;
	}
	return ((int)(result * sign));
}

/**
* print_error - function prints an error message
* @info: the parameter & return info struct
* @estr: str containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
* print_d - function prints a decimal integer number to base 10
* @input: the input
* @fd: the file descriptor to write to
*
* Return: number of charas printed
*/
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}

/**
* convert_number - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
	static const char lower_digits[] = "0123456789abcdef";
	static const char upper_digits[] = "0123456789ABCDEF";
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = (flags & CONVERT_LOWERCASE) ? lower_digits : upper_digits;
	ptr = &buffer[49];
	*ptr = '\0';
	do {*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
* remove_comments - function that replaces first instance of '#' with '\0'
* @buf: address of the string to be modified
*
* Return: Always 0;
*/
void remove_comments(char *buf)
{
	int i;

	if (buf == NULL)
		return;
	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
