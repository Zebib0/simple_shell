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
