#include "main.h"

/**
 * _eputs - prints an input string to stderr.
 * @str: the string to be printed.
 *
 * Return: nothing.
 */
void _eputs(char *str)
{
	if (!str)
		return;

	while (*str)
	{
		_eputchar(*str++);
	}
}

/**
 * _eputchar - writes the character c to stderr with buffering.
 * @c: the character to print.
 *
 * Return: 1 on success, -1 on error.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)

	{
		if (write(2, buf, i) == -1)
			return (-1);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}

/**
 * _putfd - writes the character c to a given file descriptor with buffering.
 * @c: the character to print.
 * @fd: the file descriptor to write to.
 *
 * Return: 1 on success, -1 on error.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		if (write(fd, buf, i) == -1)
			return (-1);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buf[i++] = c;

	return (1);
}

/**
 * _putsfd - prints an input string to a given file descriptor.
 * @str: the string to be printed.
 * @fd: the file descriptor to write to.
 *
 * Return: number of characters printed.
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (!str)
		return (0);

	while (*str)
	{
		if (_putfd(*str++, fd) == -1)
			return (-1);
		count++;
	}
	return (count);
}
