#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE
#define TOK_DELIM ": '\n''\t'"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

typedef struct command
{
	char *arg;
	int (*func)(void);

} cmnd_t;

int main(void);
int _strlen(char *);
int env(void);
int exitshell(void);
int *printdir(void);
int _setenv(const char *name, const char *value, int overwrite);
int builtin(char *s);
int printenv(void);
int _strcmp(char *s1, char *s2);
int _help(char *args);
char *_getenv(const char *name);
char *findpath(char *name);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *getinput(void);
char **tokenizer(char *buffer);
void _sigign(int sig);
extern char **environ;

#endif
