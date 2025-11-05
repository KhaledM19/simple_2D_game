#include "libft.h"
#include <stdint.h>

static int	count_digits(long int n)
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

char	*convert_hex(uintptr_t decn)
{
	long		tmp;
	char		*hexdigits;
	int			i;

	i = 0;
	hexdigits = malloc(sizeof(char) * (count_digits(decn) + 1));
	if (decn == 0)
	{
		hexdigits[0] = '0';
		i++;
	}
	while (decn > 0)
	{
		tmp = decn % 16;
		if (tmp < 10)
			hexdigits[i] = tmp + '0';
		else
			hexdigits[i] = tmp + 'a' - 10;
		i++;
		decn = decn / 16;
	}
	hexdigits[i] = '\0';
	return (hexdigits);
}
