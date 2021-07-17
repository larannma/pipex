#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*m;

	i = 0;
	if (!s)
		return (0);
	m = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (m == NULL)
		return (NULL);
	while (s[i])
	{
		m[i] = f(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
