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

/**
 * _strcpy - copies string from src to dest
 * @dest: pointer to string dest
 * @src: pointer to string src
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

/**
 * _strchr - locates the first occurence of a character in a string
 * @str: the string to search
 * @c: the character to find
 *
 * Return: pointer to first occurence of character in string, otherwise NULL
 */

char *_strchr(const char *str, int c)
{
    while (*str != '\0')
	{
        if (*str == (char)c)
            return ((char *)str);
        str++;
	}

	if (c == '\0')
		return ((char *)str);

	return (NULL);
}

/**
 * _strcat - concetenates two strings
 * @src: source string to append
 * @dest: destination string
 *
 * Return: pointer to resulting string
 */

char *_strcat(char *dest, const char *src)
{
    int d = 0;
    int s = 0;

	while (dest[d] != '\0')
        d++;

	while (src[s] != '\0')
	{
        dest[d] = src[s];
		d++;
		s++;
	}

    dest[d] = '\0'; /* null-terminate the result */

	return (dest);
}

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
    dup = malloc(len + 1);  // +1 for null terminator

    if (dup == NULL)
        return (NULL);

    _strcpy(dup, str);
	
    return (dup);
}
