#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define TILE_SIZE 107

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		collected;
}	t_player;

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		width;
	int		height;
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_images	img;
	int			exit_x;
	int			exit_y;
}	t_game;

void	error_exit(void);
void	error_exit_free(char *str, char *error_msg);
void	error_exit_free_map(char **map, int rows, char *error_msg);
int		find_substr(const char *s, char *c);
int		validate_path(t_game *game);
void	check_walls(char **map, int height, int width);
void	count_elements(char *line, t_game *game, int y);
void	check_char(char *line, char **map, int row);
char	**read_map(int fd, t_game *game);
int		cleanup_and_exit(t_game *game);
int		cleanup(t_game *game);
void	setup_events(t_game *game);
void	load_images(t_game *game);
void	draw_map(t_game *game);
void	render_game(t_game *game);
int		validate_elements(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		handle_keypress(int keycode, t_game *game);
void	setup_events(t_game *game);

#endif