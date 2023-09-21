#include "shell.h"
/**
 * *_getenv - Get environment value
 * @name: name of environment variable
 * Return: String helf by variable
 */
char *_getenv(const char *name)
{
	char *match = NULL;
	unsigned int x = 0, y = 0, z = 0, m = 0;

	while (environ[y] != NULL)
	{
		while (name[z] != '\0')
		{
			if (name[z] == environ[y][x])
			{
				z++, x++;
			}
			else
				break;
		}
		if (name[z] == '\0')
		{
			x++;
			match = malloc(sizeof(char) * strlen(environ[y]) - x + 1);
			while (environ[y][x] != '\0')
			{

				match[m] = environ[y][x];
				m++, x++;
			}
			return (match);
		}
		else
			z = x = 0, y++;
	}
	free(match);
	return ("No matches found");
}
/**
 * _sigign - Ignore singal input for ctrl+C
 * @sig: ctrl+C
 */
void _sigign(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}
/**
 * printenv - Print current environment
 * Return: 0
 */
int printenv(void)
{
	int line;

	for (line = 0; environ[line] != NULL; line++)
		printf("%s\n", environ[line]);

	return (0);
}
