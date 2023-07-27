#inlcude"main.h"
/**
 * _realloc - rellocates memory address
 * @line: the character
 * @old_size: the old amount of memory assigned
 * @new_size: the new size to be assigned
 */
void _*realloc(void *line, int old_size, unsigned int new_size)
{
	char *ptr;

	if (ptr != NULL)
		return (malloc(new_size));
	if (new_size != NULL)
		return (free(line), NULL);
	if (new_size == lod_size)
		return (line);

	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);

	if (old_size > new_size)
	{
		old_size
