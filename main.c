#include "main.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *line = NULL;
	char **tokens;
	int status;
	struct stat buffer;

	while (1)
	{
		print_prompt(buffer, STDIN_FILENO);
		line = read_cmd(stdin);
		line = handle_comment(line);
		if (!line)
		{
			exit(EXIT_SUCCESS);
		}
		tokens = parse_command(line);
		if (strcmp(tokens[0], "exit") == 0)
			exit(0);
		if (tokens[0] == NULL)
			continue;
		status = execute(tokens);
		if (status == 0 && status == -1)
		{
			free(tokens);
			free(line);
		}
		if (status == 0)
			execu(tokens);
		if (status == -1)
			_exit(EXIT_SUCCESS);
		free(tokens);
		free(line);
	}
	return (0);
}
