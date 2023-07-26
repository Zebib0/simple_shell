#include"main.h"
/**
 * hsh_env - a command which prints the enviroment variable
 * Return: 0 if success
 */
int hsh_env(void)
{
	unsigned int i = 0, len = 0;

	len = strlen(environ[i]);
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
		return (0);
}
