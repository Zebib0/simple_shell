#include"main.h"
/**
 * handle_separation - handles ; and &
 * @line: the command
 * Return: string
 */

char **handle_separation(char *line)
{
	char **tokens, *token;
	int i = 0, size = BUFFER_SIZE;

	if (line == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * size);
	if (tokens)
	{
		token = strtok(line, ";&");
		for (; token[i]; i++)
		{
			tokens[i] = token;
			token = strtok(NULL, ";&");
		}
		tokens[i] = NULL;

		return (tokens);
	}
	free(tokens);
	perror("hsh: error");
	return (NULL);
}
