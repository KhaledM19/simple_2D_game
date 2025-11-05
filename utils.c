#include "so_long.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_exit_free(char *str, char *error_msg)
{
	write(2, "Error\n", 6);
	ft_printf("%s", error_msg);
	if (str)
		free(str);
	exit(1);
}

void	error_exit_free_map(char **map, int rows, char *error_msg)
{
	int	i;

	i = 0;
	while (i < rows && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	write(2, "Error\n", 6);
	ft_printf("%s", error_msg);
	exit(1);
}

int	find_substr(const char *s, char *c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(c);
	while (s[i])
	{
		j = 0;
		while (j < len && s[i + j] && s[i + j] == c[j])
			j++;
		if (j == len)
			return (1);
		i++;
	}
	return (0);
}
