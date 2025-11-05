#include "libft.h"

static int	count_digits(long n)
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

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	count;

	count = count_digits(n);
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
	return (count);
}
