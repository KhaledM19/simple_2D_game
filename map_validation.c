#include "so_long.h"

void	check_char(char *line, char **map, int row)
{
	char	*valid;
	int		i;
	int		j;
	int		found;

	i = 0;
	valid = "10CEP";
	while (line[i])
	{
		found = 0;
		j = 0;
		while (valid[j])
		{
			if ((line[i] == valid[j]) || (line[i] == '\n'))
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			error_exit_free_map(map, row, "Invalid character in map");
		i++;
	}
}

void	count_elements(char *line, t_game *game, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			game->map.collectibles++;
		else if (line[i] == 'E')
		{
			game->exit_x = i;
			game->exit_y = y;
		}
		else if (line[i] == 'P')
		{
			game->player.x = i;
			game->player.y = y;
		}
		i++;
	}
}

int	all_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_walls(char **map, int height, int width)
{
	int	i;

	if (!all_walls(map[0]) || !all_walls(map[height - 1]))
		error_exit_free_map(map, height, "Map is not surrounded by 1");
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			error_exit_free_map(map, height, "Map is not surrounded by 1");
		i++;
	}
}

int	validate_elements(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	i;
	int	j;

	i = 0;
	player_count = 0;
	exit_count = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == 'P')
				player_count++;
			else if (game->map.grid[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || game->map.collectibles < 1)
		return (0);
	return (1);
}
