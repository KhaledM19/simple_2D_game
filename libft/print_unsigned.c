#include "libft.h"

static int	count_digits(unsigned int n)
{
	long	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	print_unsigned(unsigned int n)
{
	unsigned int	nb;
	long			count;

	count = count_digits(n);
	nb = n;
	if (nb >= 10)
		print_unsigned(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
	return (count);
}
