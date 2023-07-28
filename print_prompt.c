#include "main.h"
/**
 * print_prompt - prints the prompt
 * @fd: file
 * @buffer: stat buffer
 * Return: nothing
 */
void print_prompt(struct stat buffer, int fd)
{
	fstat(fd, &buffer);

	if (S_ISCHR(buffer.st_mode))
		write(STDOUT_FILENO, "$ ", 2);
}
