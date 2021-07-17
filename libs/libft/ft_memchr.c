#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*k;

	k = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (k[i] == (unsigned char)c)
			return (k + i);
		i++;
	}
	return (NULL);
}
