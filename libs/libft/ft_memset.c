#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*k;

	k = (unsigned char *)b;
	while (len > 0)
	{
		k[len - 1] = (unsigned char)c;
		len--;
	}
	return (b);
}
