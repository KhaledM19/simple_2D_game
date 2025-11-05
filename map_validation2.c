#include "so_long.h"

static char	**allocate_map(char **map, int *capacity, int used)
{
	char	**temp;
	int		j;

	*capacity *= 2;
	temp = malloc(sizeof(char *) * (*capacity));
	if (!temp)
		error_exit_free_map(map, used, "");
	j = 0;
	while (j < used)
	{
		temp[j] = map[j];
		j++;
	}
	free(map);
	return (temp);
}

char	*process_line(char *line)
{
	char	*trimmed;

	if (!line)
		return (NULL);
	trimmed = ft_strtrim(line, "\n");
	free(line);
	if (!trimmed)
		error_exit();
	return (trimmed);
}

static void	finalize_map(char **map, int rows, int cols, t_game *game)
{
	if (rows == 0)
		error_exit_free_map(map, 0, "no map");
	map[rows] = NULL;
	game->map.height = rows;
	game->map.width = cols;
	check_walls(map, rows, cols);
}

void	finish_read(t_game *game, int i, int width)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_strlen(game->map.grid[j]) != (size_t)(width))
			error_exit_free_map(game->map.grid, i, "Map is not a rectangle");
		check_char(game->map.grid[j], game->map.grid, i);
		count_elements(game->map.grid[j], game, j);
		j++;
	}
	finalize_map(game->map.grid, i, width, game);
}

char	**read_map(int fd, t_game *game)
{
	char	*line;
	int		capacity;
	int		i;
	int		width;

	width = 0;
	i = 0;
	capacity = 100;
	game->map.grid = malloc(sizeof(char *) * capacity);
	if (!game->map.grid)
		error_exit();
	line = get_next_line(fd);
	while (line)
	{
		if (i >= capacity - 1)
			game->map.grid = allocate_map(game->map.grid, &capacity, i);
		game->map.grid[i] = process_line(line);
		if (i == 0)
			width = ft_strlen(game->map.grid[i]);
		i++;
		line = get_next_line(fd);
	}
	finish_read(game, i, width);
	return (game->map.grid);
}
