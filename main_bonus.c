/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:45:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 16:19:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_A)
		check_and_go(KEY_A, game);
	else if (key == KEY_S)
		check_and_go(KEY_S, game);
	else if (key == KEY_D)
		check_and_go(KEY_D, game);
	else if (key == KEY_W)
		check_and_go(KEY_W, game);
	return (0);
}

void	init_game(t_game *game)
{
	game->sp_cnt = 0;
	game->coin_cnt = 0;
	game->exit_cnt = 0;
	game->move_count = 0;
	game->mlx = mlx_init();
	load_image(game);
	game->win_width = game->width * game->size_w;
	game->win_heigth = game->heigth * game->size_h;
	game->enemy_cnt = 0;
	game->win = mlx_new_window(game->mlx, game->win_width, \
			game->win_heigth, "game");
	game->cur_enemy = game->enemy_cut[0];
	srand(time(NULL));
}

int	close_game(void)
{
	exit(0);
}

void	updata_enemy_cordin(t_game *game)
{
	int	cur_height;
	int	cur_width;
	int	enemy_count;

	enemy_count = 0;
	cur_height = 1;
	while (cur_height < game->heigth - 1)
	{
		cur_width = 1;
		while (cur_width < game->width - 1)
		{
			if (game->map[cur_height][cur_width] == 'O')
			{
				game->enemy[enemy_count]->cur_x = cur_width;
				game->enemy[enemy_count]->cur_y = cur_height;
				enemy_count++;
			}
			cur_width++;
		}
		cur_height++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_error();
	get_map(&game, argv);
	init_game(&game);
	check_valid_map(&game);
	create_enemy(&game);
	reflect_enemy(&game);
	updata_enemy_cordin(&game);
	mlx_key_hook(game.win, get_key, &game);
	mlx_hook(game.win, KEY_EXIT, 0, close_game, 0);
	mlx_loop_hook(game.mlx, control_enemy, &game);
	mlx_loop(game.mlx);
}
