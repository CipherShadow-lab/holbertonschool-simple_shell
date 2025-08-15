include "shell.h"

/**
 * _strcmp - function mimics strcmp to compare two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: positive if s1 is greater, negative if s2 is greater or 0 if equal
 */

int _strcmp(const char *s1, const char *s2)
{
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (s1[i] - s2[i]);
}
