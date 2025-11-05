#include "libft.h"
#include <stdint.h>

int	print_ptr(void *arg)
{
	uintptr_t	ptr;
	char		*conv;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (arg == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr = (uintptr_t)arg;
	write(1, "0x", 2);
	conv = convert_hex(ptr);
	i = ft_strlen(conv) - 1;
	while (i >= 0)
	{
		ft_putchar_fd(conv[i], 1);
		ret++;
		i--;
	}
	free(conv);
	return (ret + 2);
}
