#include "so_long.h"

void	init_window_and_images(t_game *game)
{
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE,
			"so_long");
	if (!game->win)
	{
		ft_printf("Error\nFailed to create window\n");
		cleanup_and_exit(game);
	}
	load_images(game);
	render_game(game);
}

int	check_input(char *filename)
{
	if (!find_substr(filename, ".ber"))
	{
		ft_printf("Error\nWrong map format\n");
		exit(1);
	}
	return (0);
}

int	check_map(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	read_map(fd, game);
	close(fd);
	game->player.moves = 0;
	game->player.collected = 0;
	if (!validate_elements(game))
	{
		ft_printf("Error\nInvalid map elements: repetition or missing\n");
		cleanup(game);
	}
	if (!validate_path(game))
	{
		ft_printf("Error\nMap has unreachable collectibles or exit\n");
		cleanup(game);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nEnter map\n");
		exit(1);
	}
	game.map.collectibles = 0;
	check_input(argv[1]);
	check_map(argv[1], &game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_printf("Error\nFailed to initialize MLX\n");
		exit(1);
	}
	init_window_and_images(&game);
	setup_events(&game);
	mlx_loop(game.mlx);
	return (0);
}
