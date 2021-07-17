#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*k;

	k = ft_calloc(1, ft_strlen(s1) + 1);
	if (k != NULL)
		ft_memmove(k, s1, ft_strlen(s1) + 1);
	return (k);
}
