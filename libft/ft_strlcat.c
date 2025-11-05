#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	len_dst;
	size_t	ret;
	size_t	len_src;
	size_t	i;

	s = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(s);
	ret = 0;
	i = 0;
	if (size > len_dst)
		ret = len_src + len_dst;
	else
		ret = len_src + size;
	while (s[i] && (len_dst + 1) < size)
	{
		dst[len_dst] = s[i];
		len_dst++;
		i++;
	}
	if (ret == len_src + len_dst)
		dst[len_dst] = '\0';
	return (ret);
}
