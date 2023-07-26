#include"main.h"
/**
 * execute - builtin execution
 * @tokens: tokinized command
 * Return: the respectve function for the command name
 */
int execute(char **tokens)
{
	int st = 0;
	unsigned int len = 0, no = 0, i = 0;

	list list[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);
	len = strlen(tokens[0]);
	while ((list[no].command) != NULL)
		no++;
	for (; i < no; i++)
	{
		if (strncmp(tokens[0], list[i].command, len) == 0)
		{
			st = (list[i].fun)();
			return (st);
		}
	}
	return (0);
}
