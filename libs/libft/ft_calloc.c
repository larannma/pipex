#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (char *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero((char *)p, count * size);
	return (p);
}
