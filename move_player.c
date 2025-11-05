#include "so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width
		|| new_y < 0 || new_y >= game->map.height)
		return (0);
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->player.collected++;
		game->map.grid[y][x] = '0';
		ft_printf("Collectible picked up! (%d/%d)\n",
			game->player.collected, game->map.collectibles);
	}
	
}

void	check_win_condition(t_game *game)
{
	if (game->player.x == game->exit_x
		&& game->player.y == game->exit_y
		&& game->player.collected == game->map.collectibles)
	{
		ft_printf("Congratulations! You won in %d moves!\n",
			game->player.moves);
		cleanup_and_exit(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	ft_printf("Moves: %d\n", game->player.moves);
	handle_collectible(game, new_x, new_y);
	check_win_condition(game);
	render_game(game);
}
