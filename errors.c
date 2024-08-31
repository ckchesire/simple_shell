#include "main.h"
/**
* _eputs - function prints an input string
* @str: the str to be printed out
* Return: nothing
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
* _eputchar - function writes the character c to stderr
* @c: The character to print out
*
* Return: On success '1'
* On error, '-1' is returned, and errno is set to appropriate
*/
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _putfd - functon writes the character c to given fd
* @c: The character to print out
* @fd: The file descriptor to write out to
*
* Return: On success '1'.
* On error, '-1' is returned, and errno is set appropriate.
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _putsfd - function prints out an input string
* @str: string to be printed out
* @fd: filedescriptor to write out to
*
* Return: the total number of chars put
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
