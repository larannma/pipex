#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;

	l = ft_strlen(s);
	if (s == NULL)
		return (0);
	while (l != 0 && s[l] != (char)c)
		l--;
	if (s[l] == (char)c)
		return ((char *)&s[l]);
	return (0);
}
