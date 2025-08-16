#include "shell.h"

/**
 * _strcmp - function mimics strcmp to compare two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: positive if s1 is greater, negative if s2 is greater or 0 if equal
 */

int _strcmp(const char *s1, const char *s2)
{
    int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * _strlen - function returns the length of a string
 * @s: pointer to string
 *
 * Return: length of string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

