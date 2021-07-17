#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = n;
	if (k == 0)
		return (0);
	while (s1[i] != '\0' && i < k - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
