#include "libft.h"
#include <stdarg.h>

static int	check_case(char *frmt, va_list args)
{
	int	i;

	i = 0;
	if (*frmt == 'c')
		i = ft_putchar_fd(va_arg(args, int), 1);
	else if (*frmt == 's')
		i = ft_putstr_fd(va_arg(args, char *), 1);
	else if (*frmt == 'p')
		i = print_ptr(va_arg(args, void *));
	else if (*frmt == 'd' || *frmt == 'i')
		i = ft_putnbr_fd(va_arg(args, int), 1);
	else if (*frmt == 'u')
		i = print_unsigned(va_arg(args, unsigned int));
	else if (*frmt == 'x' || *frmt == 'X')
		i = print_hex(va_arg(args, unsigned int), *frmt);
	else if (*frmt == '%')
		i = ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*frmt;
	int		count;

	frmt = (char *)format;
	count = 0;
	va_start(args, format);
	while (*frmt)
	{
		if (*frmt == '%')
		{
			count += check_case((char *)frmt + 1, args);
			frmt++;
		}
		else
		{
			count += ft_putchar_fd(*frmt, 1);
		}
		frmt++;
	}
	va_end(args);
	return (count);
}
