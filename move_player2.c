#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Game closed by user\n");
		cleanup_and_exit(game);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

void	setup_events(t_game *game)
{
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 1L << 17, cleanup_and_exit, game);
}
