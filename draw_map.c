#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm",
			&width, &height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "./images/floor.xpm",
			&width, &height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "./images/new_eng.xpm",
			&width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm",
			&width, &height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"./images/collectible.xpm",
			&width, &height);
	game->img.width = width;
	game->img.height = height;
	if (!game->img.wall || !game->img.floor || !game->img.player
		|| !game->img.exit || !game->img.collectible)
	{
		ft_printf("Error\nFailed to load images\n");
		cleanup_and_exit(game);
	}
}

static void	draw_map_helper(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.floor, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map.grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img.exit, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map_helper(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.player, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);
}

void	render_game(t_game *game)
{
	draw_map(game);
}
