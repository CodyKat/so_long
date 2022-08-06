/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:45:37 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 14:39:13 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_image(t_game *game)
{
	void	*mlx;
	int		w;
	int		h;

	mlx = game->mlx;
	game->enemy_cut[0] = mlx_xpm_file_to_image(mlx, "./img/slime0.xpm", &w, &h);
	game->enemy_cut[1] = mlx_xpm_file_to_image(mlx, "./img/slime1.xpm", &w, &h);
	game->enemy_cut[2] = mlx_xpm_file_to_image(mlx, "./img/slime2.xpm", &w, &h);
	game->enemy_cut[3] = mlx_xpm_file_to_image(mlx, "./img/slime3.xpm", &w, &h);
	game->enemy_cut[4] = mlx_xpm_file_to_image(mlx, "./img/slime4.xpm", &w, &h);
	game->enemy_cut[5] = mlx_xpm_file_to_image(mlx, "./img/slime5.xpm", &w, &h);
	game->path = mlx_xpm_file_to_image(mlx, "./img/path.xpm", &w, &h);
	game->wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	game->coin = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &w, &h);
	game->size_w = w;
	game->size_h = h;
}

void	put_img(t_game *game, int pos_x, int pos_y)
{
	int		cordin_x;
	int		cordin_y;
	void	*mlx;
	void	*win;

	cordin_x = pos_x * game->size_w;
	cordin_y = pos_y * game->size_h;
	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, game->path, cordin_x, cordin_y);
	if (game->map[pos_y][pos_x] == 'P')
		mlx_put_image_to_window(mlx, win, game->player, cordin_x, cordin_y);
	else if (game->map[pos_y][pos_x] == 'C')
		mlx_put_image_to_window(mlx, win, game->coin, cordin_x, cordin_y);
	else if (game->map[pos_y][pos_x] == 'E')
		mlx_put_image_to_window(mlx, win, game->exit, cordin_x, cordin_y);
	else if (game->map[pos_y][pos_x] == '1')
		mlx_put_image_to_window(mlx, win, game->wall, cordin_x, cordin_y);
	else if (game->map[pos_y][pos_x] == 'O')
		mlx_put_image_to_window(mlx, win, game->cur_enemy, cordin_x, cordin_y);
	else if (game->map[pos_y][pos_x] == '0')
		mlx_put_image_to_window(mlx, win, game->path, cordin_x, cordin_y);
	else
		ft_error();
}

void	render_map(t_game *game)
{
	int		pos_x;
	int		pos_y;
	char	*string;

	string = ft_itoa(game->move_count);
	pos_y = 0;
	while (pos_y < game->heigth)
	{
		pos_x = 0;
		while (pos_x < game->width)
		{
			put_img(game, pos_x, pos_y);
			pos_x++;
		}
		pos_y++;
	}
	mlx_string_put(game->mlx, game->win, 15, 15, 0x0066ff33, string);
	free(string);
}
