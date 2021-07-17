#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*m;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
	{
		m = malloc(sizeof(char) * 1);
		if (m == NULL)
			return (NULL);
		m[0] = '\0';
		return (m);
	}
	while (ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	m = ft_substr(s1, i, len - i);
	if (m == NULL)
		return (NULL);
	return (m);
}
