#include "shell.h"

/**
 * _strdup - creates a duplicate copy of a string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, otherwise NULL
 */

char *_strdup(const char *str)
{
	char *dup;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(len + 1);

	if (dup == NULL)
		return (NULL);

	_strcpy(dup, str);

	return (dup);
}
