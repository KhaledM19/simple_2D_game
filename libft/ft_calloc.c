#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*str;
	int			bytes;

	bytes = nmemb * size;
	if (size != 0 && bytes / size != nmemb)
		return (NULL);
	str = malloc(bytes);
	if (!str)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (str);
	ft_bzero(str, bytes);
	return (str);
}
