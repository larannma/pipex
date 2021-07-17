#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		n;
	size_t	needle_l;

	n = *haystack;
	n = 0;
	needle_l = ft_strlen(needle);
	if (needle_l == 0)
		return ((char *)haystack);
	while (n < (int)(len - needle_l + 1))
	{
		if (ft_strncmp(haystack, needle, needle_l) == 0)
			return ((char *)haystack);
		haystack++;
		n++;
	}
	return (0);
}
