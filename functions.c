#include"main.c"
/**
 * _strlen - length of a string
 * @str: the string value
 * Return: the number of charachters or length
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
/**
 * _strcpy - copies string to its destination
 * @dest: destination string
 * @src: source string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = strlen(src);

	for (i = 0; i < j; i++)
		dest[i] = src[i];
	return (dest);
}
