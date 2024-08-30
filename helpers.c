#include "main.h"

/**
* interactive - function checks if shell is in an interactive mode
* @info: pointer to the info struct.
*
* Return: 1 if interactive mode, 0 otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - function checks if a character is a delimeter
* @c: the character to check
* @delim: the delimeter str
* Return: 1 if true, 0 if false
*/
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
			return (1);
	}
	return (0);
}

/**
* _isalpha - function checks if character is alphabetic
* @c: The character to verify
* Return: 1 if c is alphabetic, 0 otherwise.
*/
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
* _atoi - function converts a string to an integer.
* @s: string to be converted
* Return: the converted number, or 0 in no number in str
*/
int _atoi(char *s)
{
	int i = 0, sign = 1, flag = 0;
	unsigned int result = 0;

	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
		i++;
	}
	return (sign == -1 ? -((int)result) : (int)result);
}
