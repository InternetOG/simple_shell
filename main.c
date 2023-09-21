#include "shell.h"
/**
 * main - Receive input and implement arguments
 * Return: 0 or 1
 */
int main(void)
{
	char *argv[5], *token, *buffer;
	pid_t child;
	int status, x = 0;

	signal(SIGINT, _sigign);
	while (1)
	{
		argv[0] = NULL, buffer = NULL, token = NULL, x = 0;
		buffer = getinput();
		token = strtok(buffer, TOK_DELIM);
		do {
			argv[x] = _strdup(token);
			x++;
			token = strtok(NULL, TOK_DELIM);
		} while (token != NULL);
		argv[x] = NULL;
		if (argv != NULL && argv[0] != NULL)
		{
			builtin(argv[0]);
			argv[0] = findpath(argv[0]);
			child = fork();
			if (child < 0)
				perror("Error");
			if (child == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			wait(&status);
		}
		free(buffer);
		free(token);
	}
	free(buffer);
	return (0);
}
