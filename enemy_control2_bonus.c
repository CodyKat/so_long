/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:44:29 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/01 21:46:35 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	enemy_swap_and_process(char *a, char *b)
{
	char	tmp;

	if (*b == 'P')
		exit(0);
	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

void	enemy_move1(int enemy_num, int way, t_game *game)
{
	int	cur_x;
	int	cur_y;

	cur_x = game->enemy[enemy_num]->cur_x;
	cur_y = game->enemy[enemy_num]->cur_y;
	if (way == KEY_A)
	{
		enemy_swap_and_process(\
				&game->map[cur_y][cur_x], \
				&game->map[cur_y][cur_x - 1]);
		game->enemy[enemy_num]->cur_x--;
	}
	else if (way == KEY_S)
	{
		enemy_swap_and_process(\
				&game->map[cur_y][cur_x], \
				&game->map[cur_y + 1][cur_x]);
		game->enemy[enemy_num]->cur_y++;
	}
}

void	enemy_move2(int enemy_num, int way, t_game *game)
{
	int	cur_x;
	int	cur_y;

	cur_x = game->enemy[enemy_num]->cur_x;
	cur_y = game->enemy[enemy_num]->cur_y;
	if (way == KEY_D)
	{
		enemy_swap_and_process(\
				&game->map[cur_y][cur_x], \
				&game->map[cur_y][cur_x + 1]);
		game->enemy[enemy_num]->cur_x++;
	}
	else if (way == KEY_W)
	{
		enemy_swap_and_process(\
				&game->map[cur_y][cur_x], \
				&game->map[cur_y - 1][cur_x]);
		game->enemy[enemy_num]->cur_y--;
	}
}

int	enemy_check_can_go(int enemy_num, int way, t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->enemy[enemy_num]->cur_x;
	next_y = game->enemy[enemy_num]->cur_y;
	if (way == KEY_A)
		next_x--;
	else if (way == KEY_S)
		next_y++;
	else if (way == KEY_D)
		next_x++;
	else
		next_y--;
	if (game->map[next_y][next_x] == '1' || game->map[next_y][next_x] == 'E')
		return (-1);
	else if (game->map[next_y][next_x] == 'C')
		return (1);
	else if (game->map[next_y][next_x] == 'O')
		return (-1);
	else
		return (0);
}
