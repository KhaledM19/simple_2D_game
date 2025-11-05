#include "so_long.h"

char	**copy_map(char **original, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = malloc(ft_strlen(original[i]) + 1);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		ft_strlcpy(copy[i], original[i], ft_strlen(original[i]) + 1);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	free_map_copy(char **map, int height)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

int	validate_helper_loop(t_game *game, int i, char **map_copy)
{
	int	j;

	j = 0;
	while (j < game->map.width)
	{
		if ((game->map.grid[i][j] == 'C' || game->map.grid[i][j] == 'E')
			&& map_copy[i][j] != 'X')
		{
			free_map_copy(map_copy, game->map.height);
			return (0);
		}
		j++;
	}
	return (1);
}

int	validate_path(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = copy_map(game->map.grid, game->map.height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player.x, game->player.y, game);
	i = 0;
	while (i < game->map.height)
	{
		if (!validate_helper_loop(game, i, map_copy))
			return (0);
		i++;
	}
	free_map_copy(map_copy, game->map.height);
	return (1);
}
