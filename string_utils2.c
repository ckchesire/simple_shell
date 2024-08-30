#include "main.h"

/**
 * _strcpy - function copies a string
 * @dest: the destination buffer
 * @src: the source str buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - function duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret_str;

	if (str == NULL)
		return (NULL);

	while (*str++)
		len++;

	ret_str = malloc(sizeof(char) * (len + 1));

	if (!ret_str)
		return (NULL);
	for (len++; len--;)
		ret_str[len] = *--str;
	return (ret_str);
}

/**
 * _puts - function prints an input string to std output
 * @str: the string to be printed
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - function writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, it returns -1, and error no. is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
