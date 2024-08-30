#include "main.h"

/**
 * hsh - main shell loop
 * @info: struct containing command information and return status
 * @av: argument vector from main()
 *
 * Return: 0 on success, 1 on error, or an error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t input_status = 0;
	int builtin_status = 0;

	while (input_status != -1 && builtin_status != -2)
	{
		clear_info(info);

		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		input_status = get_input(info);

		if (input_status != -1)
		{
			set_info(info, av);
			builtin_status = find_builtin(info);

			if (builtin_status == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}

	write_history(info);
	free_info(info, 1);

	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_status == -2)
	{
		exit(info->err_num == -1 ? info->status : info->err_num);
	}
	return (builtin_status);
}

/**
 * find_builtin - finds and executes a built-in command
 * @info: Struct containing command information and return status
 *
 * Return: -1 if the built-in is not found,
 *          0 if the built-in is executed successfully,
 *          1 if the built-in is found but not successful,
 *          2 if the built-in signals to exit
 */
int find_builtin(info_t *info)
{
	int i;
	int builtin_status = -1;

	builtin_table builtins[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].type; i++)
	{
		if (_strcmp(info->argv[0], builtins[i].type) == 0)
		{
			info->line_count++;
			builtin_status = builtins[i].func(info);
			break;
		}
	}
	return (builtin_status);
}

/**
 * find_cmd - finds and executes a command in the system PATH
 * @info: struct containing command information and return status
 * Return: nothing
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int command_found = 0;

	info->path = info->argv[0];

	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}

	for (int i = 0; info->arg[i]; i++)
	{
		if (!is_delim(info->arg[i], " \t\n"))
			command_found++;
	}

	if (command_found == 0)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=") || info->argv[0][0] == '/')
				&& is_cmd(info, info->argv[0]))
		{
			fork_cmd(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "Command not found\n");
		}
	}
}

/**
 * fork_cmd - forks a child process to execute a command
 * @info: struct containing command information and return status
 * Return: nothing
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: forking process");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));

		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);

			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
