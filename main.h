#ifndef MAIN_H
#define MAIN_H
#include<signal.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define DELIM " \t\n\r"
#define BUFFER_SIZE 1024
#define BUF_size 60
/**
 * struct list - linked list for the builtins
 * and their functions
 * @command: the buitins
 * @fun: the function pointer
 */
typedef struct list
{
	char *command;
	int (*fun)(void);
} list;
extern char **environ;
int execute(char **tokens);
char *handle_path(char *line);
void execu(char **tokens);
char *read_cmd(FILE *fp);
void print_prompt(void);
char *_getenv(const char *envt, char **environ);
char **parse_command(char *line);
char *read_input(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int cmp_string(const char *env, const char *envt);
int hsh_env(void);
int hsh_exit(void);
#endif
