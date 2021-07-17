#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	if (!s && !d)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
		{
			i++;
			return (dst + i);
		}
		i++;
	}
	return (NULL);
}
