#include "main.h"
/**
 * _strlen - returns the string length
 * @s: string whose length is to be checked
 *
 * Return: integer value of string length
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);

	while (*s++)
		len++;

	return (len);
}

/**
 * _strcmp - evaluate two strings for lexicographic comparison
 * @s1: first string
 * @s2: second string
 *
 * Return: -ve if s1 < s2, +ve if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - perform search to see if needle starts with haystack
 * @haystack: string to be searched
 * @needle: the substring to locate
 *
 * Return: address of next character in haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
			return (NULL);
	}
	return ((char *)haystack);
}

/**
 * _strcat - performs concatenation for two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
	char *str_concat = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (str_concat);
}

