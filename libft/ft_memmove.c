#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*str1;
	char		*str2;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	str1 = (char *) src;
	str2 = (char *) dest;
	i = 0;
	if (str2 > str1)
		while (n-- > 0)
			str2[n] = str1[n];
	else
	{
		while (i < n)
		{
			str2[i] = str1[i];
			i++;
		}
	}
	return (dest);
}
