#ifndef SO_LONG_H
# include <stdlib.h>
# include <time.h>
# define SO_LONG_H
# define FALSE 0
# define TRUE 1
# define TOTAL_FRAME 6
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_enemy
{
	int	cur_x;
	int	cur_y;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*path;
	void	*coin;
	void	*player;
	void	*exit;
	void	*enemy_cut[TOTAL_FRAME];
	void	*cur_enemy;
	char	**map;
	int		higth;
	int		width;
	int		win_width;
	int		win_higth;
	int		cur_x;
	int		cur_y;
	int		comm_count;
	int		size_w;
	int		size_h;
	int		sp_cnt;
	int		coin_cnt;
	int		exit_cnt;
	int		enemy_cnt;
	t_enemy	**enemy;
}	t_game;

#endif
