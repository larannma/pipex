#include "libft.h"

static	size_t	lenword(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != c && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static	size_t	amountword(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			word++;
		while (*s != c && *s)
			s++;
	}
	return (word);
}

static	void	osvobojdenie(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free (res);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	j;
	size_t	len;

	j = 0;
	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (amountword(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			len = lenword(s, c);
			res[j] = ft_substr(s, 0, len);
			if (res[j++] == 0)
				osvobojdenie(res);
			s = s + len;
		}
	}
	res[j] = NULL;
	return (res);
}
