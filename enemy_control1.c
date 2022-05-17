/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:13:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/16 11:36:36 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	render_map(t_game *game);
int		enemy_check_can_go(int enemy_num, int way, t_game *game);
void	enemy_move1(int enemy_num, int way, t_game *game);
void	enemy_move2(int enemy_num, int way, t_game *game);

void	enemy_check_and_go(int enemy_num, int way, t_game *game)
{
	int	state;

	if (way == 4)
		return ;
	state = enemy_check_can_go(enemy_num, way, game);
	if (state != -1)
	{
		if (way == KEY_A)
			enemy_move1(enemy_num, KEY_A, game);
		else if (way == KEY_S)
			enemy_move1(enemy_num, KEY_S, game);
		else if (way == KEY_D)
			enemy_move2(enemy_num, KEY_D, game);
		else if (way == KEY_W)
			enemy_move2(enemy_num, KEY_W, game);
	}
}

int	control_enemy(t_game *game)
{
	static int	frame = 0;
	static int	move_inverse_speed = 0;
	int			speed_reduce;
	int			enemy_count;
	int			enemy_way;

	speed_reduce = 3;
	game->cur_enemy = game->enemy_cut[frame / speed_reduce];
	frame = (frame + 1) % (TOTAL_FRAME * speed_reduce);
	if (frame == TOTAL_FRAME * speed_reduce - 1)
		move_inverse_speed++;
	if (move_inverse_speed == 4)
	{
		move_inverse_speed = 0;
		enemy_count = -1;
		while (++enemy_count < game->enemy_cnt)
		{
			enemy_way = rand() % 5;
			if (enemy_way == 3)
				enemy_way += 10;
			enemy_check_and_go(enemy_count, enemy_way, game);
		}
	}
	render_map(game);
	return (0);
}
