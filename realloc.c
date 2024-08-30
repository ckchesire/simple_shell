#include "main.h"
/**
 * _memset - function fills memory area  with a constant byte
 * @s: pointer to the memory area
 * @b: byte to fill *s with
 * @n: amount of bytes to be filled
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - function frees a array of strings
 * @pp: array of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (pp == NULL)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - function reallocates a block of memory
 * @ptr: pointer to previous allocated block
 * @old_size: size in bytes of previous block
 * @new_size: size in bytes of new block
 * Return: pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == NULL)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
