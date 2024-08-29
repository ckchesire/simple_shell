#include "main.h"
/*
 * main - entry point for shell program
 *
 * Return: '0' on success
 */
int main(void)
{
	char *input = NULL, *input_copy = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	ssize_t n_chars;
	int argc = 0;
	int i = 0;
	char **argv = NULL;
	pid_t pid;

	while (1)
	{
		printf(":) ");
		n_chars = getline(&input, &n, stdin);
		if (n_chars == -1)
		{
			perror("Error:");
			return (-1);
		}
		if (n_chars == 1)
		{
			continue;
		}
		input_copy =  malloc(sizeof(char) * (n_chars + 1));
		if (input_copy == NULL)
		{
			perror("Error:");
			return (-1);
		}
		strcpy(input_copy, input);
		token = strtok(input, delim);
		for (argc = 0; token != NULL; argc++)
		{
			token = strtok(NULL, delim);
		}
		argv = malloc(sizeof(char *) * (argc + 1));
		if (argv == NULL)
		{
			perror("Error:");
			return (-1);
		}
		token = strtok(input_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
			if (argv[i] == NULL)
			{
				perror("Error:");
				while (i > 0)
					free(argv[--i]);
				free(argv);
				free(input_copy);
				return (-1);
			}
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			exec_cmd(argv);
		}
		else
		{
			wait(NULL);
		}
		for (i = 0; i < argc; i++)
			free(argv[i]);
		free(argv);
		free(input_copy);
	}
	free(input);
	return (0);
}
