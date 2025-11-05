#include "libft.h"
#include <limits.h>

static int	count_digit(long n)
{
	long	count;

	count = 0;
	if (n == 0)
		count++;
	else if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	edge_case(int n)
{
	if (n == 0)
		return ('0');
	if (n < 0)
	{
		n = -n;
		return ('-');
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = count_digit(n);
	ret = malloc(sizeof(char) * (count_digit(n) + 1));
	ret[i] = '\0';
	if (!ret)
		return (NULL);
	i--;
	ret[0] = edge_case(n);
	if (n < 0)
		n = -n;
	if (n == -2147483648)
	{
		n = 214748364;
		ret[i--] = '8';
	}
	while (n > 0)
	{
		ret[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (ret);
}
