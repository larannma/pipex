#include "libft.h"

static	char	*functcia(char *m, int j, int len_int, int k)
{
	if (m == NULL)
		return (NULL);
	if (j == 1)
		m[0] = '-';
	while (k >= 10)
	{
		m[len_int--] = k % 10 + 48;
		k = k / 10;
		j++;
	}
	j++;
	m[len_int--] = k % 10 + 48;
	m[j] = '\0';
	return (m);
}

char	*ft_itoa(int n)
{
	int		len_int;
	char	*m;
	int		k;
	int		j;

	len_int = 0;
	j = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		j = 1;
		n *= -1;
		len_int++;
	}
	k = n;
	while (n >= 10)
	{
		n = n / 10;
		len_int++;
	}
	m = (char *)malloc (sizeof(char) * (len_int + 2));
	if (m == 0)
		return (0);
	return (functcia(m, j, len_int, k));
}
