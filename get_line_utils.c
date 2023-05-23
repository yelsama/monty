#include "main.h"

/**
 * ft_strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	char	*str;
	int		count;

	str = (char *)s;
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * ft_strchr - Locates the first occurrence of a character in a string.
 * @s: The input string.
 * @c: The character to locate.
 *
 * Return: Pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	match;
	int		i;

	str = (char *)s;
	match = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == match)
			return (&str[i]);
		i++;
	}
	return (0);
}

/**
 * ft_strjoin - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: Pointer to the concatenated string,
 *         or NULL if memory allocation fails.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(s1);
	result = malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!result)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < len)
		result[i] = s1[i];
	len = 0;
	while (s2[len] != '\0')
		result[i++] = s2[len++];
	result[i] = s2[len];
	free(s1);
	return (result);
}

/**
 * ft_strcpy - Check the code
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: The pointer to the destination string.
 */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * ft_calloc - Allocates memory for an array and initializes it to zero.
 * @count: The number of elements to allocate.
 * @size: The size of each element.
 *
 * Return: Pointer to the allocated memory,
 *         or NULL if memory allocation fails.
 */
void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned long	i;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < count)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
