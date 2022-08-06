/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:44:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 15:41:46 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_count_data(t_game *game, char block, int heigth, int width)
{
	if (block == 'C')
		game->coin_cnt++;
	else if (block == 'P')
	{
		game->cur_x = width;
		game->cur_y = heigth;
		game->sp_cnt++;
	}
	else if (block == 'E')
		game->exit_cnt++;
	else if ((block != '1') && (block != '0'))
		ft_error();
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
