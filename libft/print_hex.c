#include "libft.h"
#include <stdint.h>

int	print_lower(char *conv, int i)
{
	int	ret;

	ret = 0;
	while (i >= 0)
	{
		ft_putchar_fd(conv[i], 1);
		ret++;
		i--;
	}
	return (ret);
}

int	print_upper(char *conv, int i)
{
	int	ret;

	ret = 0;
	while (i >= 0)
	{
		ft_putchar_fd(ft_toupper(conv[i]), 1);
		ret++;
		i--;
	}
	return (ret);
}

int	print_hex(unsigned int arg, int h)
{
	int		i;
	int		ret;
	char	*conv;

	ret = 0;
	conv = convert_hex(arg);
	i = ft_strlen(conv) - 1;
	if (h == 'x')
		ret = print_lower(conv, i);
	else if (h == 'X')
		ret = print_upper(conv, i);
	free(conv);
	return (ret);
}
