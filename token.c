#include"main.h"
/**
 * parse_command - a function for tokinizing the command
 * @line: the command entered
 * Return: toknized input
 */
char **parse_command(char *line)
{
	int bufsize = BUFFER_SIZE, i = 0;
	char **tokens;
	char **rel_tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	rel_tokens = NULL;
	token = NULL;
	if (!line)
	{
		return (NULL);
	}
	if (!tokens)
	{
		perror("hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			rel_tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!rel_tokens)
			{
				perror("hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
			tokens = rel_tokens;
		}
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
