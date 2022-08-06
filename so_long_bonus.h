/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:45:48 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 15:19:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define SO_LONG_H
# define FALSE 0
# define TRUE 1
# define TOTAL_FRAME 6
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_EXIT 17

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
	int		heigth;
	int		width;
	int		win_width;
	int		win_heigth;
	int		cur_x;
	int		cur_y;
	int		move_count;
	int		size_w;
	int		size_h;
	int		sp_cnt;
	int		coin_cnt;
	int		exit_cnt;
	int		enemy_cnt;
	t_enemy	**enemy;
}	t_game;

void	enemy_move1(int enemy_num, int way, t_game *game);
void	enemy_move2(int enemy_num, int way, t_game *game);
void	update_count_data(t_game *game, char block, int heigth, int width);
void	ft_error(void);
void	load_image(t_game *game);
void	render_map(t_game *game);
void	check_and_go(int way, t_game *game);
void	get_map(t_game *game, char **argv);
void	check_valid_map(t_game *game);
void	create_enemy(t_game *game);
void	reflect_enemy(t_game *game);

int		check_file_name(char *file);
int		enemy_check_can_go(int enemy_num, int way, t_game *game);
int		ft_strncmp(char *s1, char *s2, int n);
int		has_same_width(int width);
int		count_enemy(t_game *game);
int		control_enemy(t_game *game);

char	*ft_itoa(int c);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
#endif
