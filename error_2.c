/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 06:55:32 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/16 17:22:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_count_data(t_game *game, char block, int higth, int width)
{
	static int	enemy_count = 0;

	if (block == 'C')
		game->coin_cnt++;
	else if (block == 'P')
	{
		game->cur_x = width;
		game->cur_y = higth;
		game->sp_cnt++;
	}
	else if (block == 'E')
		game->exit_cnt++;
	else if (block == 'O')
	{
		game->enemy[enemy_count]->cur_x = width;
		game->enemy[enemy_count]->cur_y = higth;
		enemy_count++;
	}
}

int	has_same_width(int width)
{
	static int	prev_width = -1;

	if (prev_width == -1)
		prev_width = width;
	else if (prev_width != width)
		return (0);
	return (1);
}
