#include "main.h"
/**
 * handle_path - a function which gets the path variable
 * @line: the command entered
 * Return: the path
 */
char *handle_path(char *line)
{
	struct stat buffer;
	char *env_var, *env_cpy;
	char *token, *path;
	int len, path_len;

	env_var = _getenv("PATH", environ);
	len = strlen(line);
	if (env_var)
	{
		env_cpy = strdup(env_var);
		token = strtok(env_cpy, ":");
		while (token != NULL)
		{
			path_len = strlen(token);
			path = malloc(len + path_len + 2);
			strcpy(path, token);
			strcat(path, "/");
			strcat(path, line);
			strcat(path, "\0");
			if (stat(path, &buffer) == 0)
			{
				free(env_cpy);
				return (path);
			}
			else
			{
				free(path);
				token = strtok(NULL, ":");
			}
		}
		free(env_cpy);
		free(path);
		if (stat(line, &buffer) == 0)
		{
			return (line);
		}
		return (NULL);
	}
	return (NULL);
}
/**
 * _getenv - a function which displays env't
 * variable using environ
 * @envt: The type of env't variable to display
 * @environ: array which contains the env't variable
 * Return: returns the char which cantains env't variable
 * else it returns NULL
 */
char *_getenv(const char *envt, char **environ)
{
	char *env = NULL;
	int i = 0, cmp = 0;

	for (; environ[i]; i++)
	{
		cmp = cmp_string(environ[i], envt);
		if (cmp)
		{
			env = environ[i];
			break;
		}
	}
	return (env + cmp);
}
/**
 * cmp_string - compares the env't variable wanted and
 * env't variable name
 * @env: the name of the enviromental variable
 * @envt: the enviromental variable needed
 * Return: 0 is returned if not equal and
 * differnt from 0 if equal
 */
int cmp_string(const char *env, const char *envt)
{
	int i = 0;

	for (; env[i] != '='; i++)
	{
		if (env[i] != envt[i])
		{
			return (0);
		}
	}

	return (i + 1);
}
