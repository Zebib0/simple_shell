#include "main.h"
/**
 * read_cmd - this is a function which reads command
 * from standard input.
 * @fp: standard input
 * Return: the char that is read from keyboard
 */
char *read_cmd(FILE *fp)
{
	char *line = NULL;
	ssize_t byte_read;
	size_t length = 0;

	byte_read = getline(&line, &length, fp);
	if (byte_read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}
