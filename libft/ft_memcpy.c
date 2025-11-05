#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)src;
	str2 = dest;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dest);
}
