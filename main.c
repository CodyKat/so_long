/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:30 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/16 11:34:51 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	get_map(t_game *game, char **argv);
void	load_image(t_game *game);
void	check_error(t_game *game, int argc, char **argv);
void	render_map(t_game *game);
void	check_and_go(int way, t_game *game);
int		control_enemy(t_game *game);

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

int	count_enemy(t_game *game)
{
	int	count;
	int	width;
	int	higth;

	higth = 1;
	count = 0;
	while (higth < game->higth - 1)
	{
		width = 1;
		while (width < game->width - 1)
		{
			if (game->map[higth][width] == 'O')
				count++;
			width++;
		}
		higth++;
	}
	return (count);
}

void	init_game(t_game *game)
{
	int	enemy_count;

	enemy_count = 0;
	game->comm_count = 1;
	game->mlx = mlx_init();
	load_image(game);
	game->win_width = game->width * game->size_w;
	game->win_higth = game->higth * game->size_h;
	game->enemy_cnt = 0;
	game->win = mlx_new_window(game->mlx, game->win_width, \
			game->win_higth, "game");
	game->cur_enemy = game->enemy_cut[0];
	game->enemy_cnt = count_enemy(game);
	game->enemy = (t_enemy **)malloc(sizeof(t_enemy *) * game->enemy_cnt);
	while (enemy_count < game->enemy_cnt)
	{
		game->enemy[enemy_count] = (t_enemy *)malloc(sizeof(t_enemy));
		enemy_count++;
	}
	srand(time(NULL));
}

int	main(int argc, char *argv[])
{
	t_game	game;

	get_map(&game, argv);
	init_game(&game);
	check_error(&game, argc, argv);
	mlx_key_hook(game.win, get_key, &game);
	mlx_loop_hook(game.mlx, control_enemy, &game);
	mlx_loop(game.mlx);
}
