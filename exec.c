#include "main.h"
/**
 * exec_cmd - allow process to execute another program
 * @argv : array of strings command arguments inputted
 * Return: nothing
 */
void exec_cmd(char **argv)
{
	char *cmd = NULL, *cmd_path = NULL;

	if (argv)
	{
		cmd = argv[0];

		cmd_path = locate_path(cmd);

		if (execve(cmd_path, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
