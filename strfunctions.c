#include "shell.h"
/**
 * _strlen - Print the length of the string
 * @s: Prints length of the string "Holberton"
 * Return: l
 */
int _strlen(char *s)
{
	int l = 0;

	while (s[l] != '\0')
		l++;

	return (l);
}

/**
 * *_strdup - Returns a pointer to a new string
 * @str: Starting char in string
 * Return: s.
 */
char *_strdup(char *str)
{
	char *s;
	int i;

	if (str == NULL)
		return (NULL);

	s = malloc((_strlen(str) + 1) * sizeof(char));

	if (s != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
			s[i] = str[i];
		s[i] = '\0';
	}
	return (s);
}
/**
 * *str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 * Return: str.
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	int i;
	int n = 0;
	int len1, len2;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = _strlen(s1);
	if (s2 == NULL)
		len2 = 0;
	else
		len2 = _strlen(s2);

	str = malloc((len1 + len2 + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		str[i] = s1[i];
	str[i] = '/';
	i++;
	for (n = 0; n < len2; n++, i++)
		str[i] = s2[n];
	str[i] = '\0';
	free(s1);
	return (str);
}

/**
 * _strcmp - Compares strings s1 & s2
 * @s1: First string to be compared
 * @s2: Second string being compared with the first
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int r = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (r == 0)
			r = s1[i] - s2[i];
		else
			break;
	}
	return (r);
}
