#include "main.h"

/**
 * execu - function to begin the process
 * @tokens: parsed input
 * Return: Nothing
 */
void execu(char **tokens)
{
	pid_t pid;
	char *cmd_in = NULL;
	char *cpy_cmd = NULL;
	int val = 0, status;
	char **envp = environ;

	pid = fork();
	if (pid == -1)
		perror("hsh: Error");
	if (pid == 0)
	{
		if (tokens)
		{
			cmd_in = tokens[0];
			cpy_cmd = handle_path(cmd_in);
			val = execve(cpy_cmd, tokens, envp);
			if (val == -1)
				perror("hsh");
		}
	}
	else
	{
		wait(&status);
	}
}
/*
int add_process(char *path, char **token)
{
pid_t pid;
int pstatus, exe_status;
char **envp = environ;

pid = fork();
if (pid == -1)
{
	perror("hsh: Error while forking");
	exit(EXIT_FAILURE);
}
if (pid == 0)
{
	exe_status = execve(path, tokens, envp);
	if (exe_status == -1)
		return (-1);
}
else
	wait(&pstatus);

	return (0);
	}*/
