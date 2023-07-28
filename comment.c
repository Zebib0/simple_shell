#include"main.h"
/**
 * handle_comment - handles comment
 * @input: input string or command
 * Return: a comment handled input
 */
char *handle_comment(char *input)
{
	int i = 0, n = 0;

	for (; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}
			if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
				n = i;
		}
	}
	if (n != 0)
	{
		input = realloc(input, n + 1);
		input[n] = '\0';
	}
	return (input);
}
