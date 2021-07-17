#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*m;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	m = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (m == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		m[i] = s1[0];
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		m[i] = s2[0];
		i++;
		s2++;
	}
	m[i] = '\0';
	return (m);
}
