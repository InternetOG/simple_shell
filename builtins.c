#include "shell.h"
/**
 * env - Print environment into output
 * Return: 0
 */
int env(void)
{
/*	extern char **environ;*/
	int line;

	for (line = 0; environ[line] != NULL; line++)
		printf("%s\n", environ[line]);
	return (0);
}
/**
 * exitshell - Leave shell
 * Return: void
 */
int exitshell(void)
{
	exit(EXIT_SUCCESS);
}
/**
 * _help - Gives user info about a command
 * @args: argument being sent in
 * Return: 0
 */
int _help(char *args)
{
	free(args);
	write(STDOUT_FILENO, "Google it dude.\n", 16);
	return (0);
}
