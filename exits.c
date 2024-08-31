#include "main.h"

/**
**_strncpy - function that copies a string
*@dest: the destination string buffer to be copied to
*@src: the source string
*@n: the no. of characters to be copied
*Return: returns concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
**_strncat - function concatenates two strings
*@dest: this is the first string
*@src: this is the second string
*@n: the no. of bytes to be maximally used
*Return: returns concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
**_strchr - function locates a character in a string
*@s: the string to parse
*@c: the char to look for
*Return: pointer to the memory area for s
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
