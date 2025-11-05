#include "libft.h"

static int	isset(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	k = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1)
		j = 0;
	while (isset(s1[i], set))
		i++;
	while (j >= i && isset(s1[j], set))
		j--;
	str = malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	while (i <= j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
