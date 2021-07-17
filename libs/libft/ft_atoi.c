#include "libft.h"

static int	count(int numb, int minus, long long result)
{
	if ((numb > 19 || result > 9223372036854775807) && minus == 1)
		return (-1);
	if ((numb > 19 || result > 9223372036854775807) && minus == -1)
		return (0);
	return ((int)result * minus);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	result;
	int				minus;
	int				numb;

	i = 0;
	result = 0;
	minus = 1;
	numb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		 minus = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
		numb++;
	}
	return (count(numb, minus, result));
}
