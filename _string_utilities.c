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


/**
 * _getenv - finds value of an environment variable
 * @name: name of environment variable
 *
 * Return: pointer to string with the value of env var
 */

char *_getenv(const char *name)
{
	int i;
	char *env_var;
	size_t name_len;

	if (name == NULL)
	{
		return (NULL);
	}

	name_len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		if (_strncmp(env_var, name, name_len) == 0 &&
		    env_var[name_len] == '=')
		{
			return (&env_var[name_len + 1]);
		}
	}
	return (NULL);
}

/**
 * _strncmp - compares two string lengths
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: length
 *
 * Return: 0 on success, otherwise 1 on failure
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}

	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
}

/**
 * free_args - function frees each string and then array
 * @args: arguments or strings to free
 *
 * Return: void
 */

void free_args(char **args)
{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);

	free(args);
}

