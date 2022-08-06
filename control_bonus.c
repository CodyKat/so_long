/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:44:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 14:39:12 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	swap_and_process(char *a, char *b, t_game *game)
{
	char	tmp;
	char	*string;

	if ((*b == 'E') && (game->coin_cnt != 0))
		return (0);
	else if (((*b == 'E') && (game->coin_cnt == 0)) || *b == 'O')
		exit(0);
	tmp = *a;
	*a = *b;
	*b = tmp;
	if (*a == 'C')
	{
		*a = '0';
		game->coin_cnt--;
	}
	string = ft_itoa(game->move_count);
	if (string == 0)
		ft_error();
	mlx_string_put(game->mlx, game->win, 15, 15, 0xff66ff33, string);
	free(string);
	return (1);
}

void	move1(int way, t_game *game)
{
	int	cur_x;
	int	cur_y;

	cur_x = game->cur_x;
	cur_y = game->cur_y;
	if (way == KEY_A)
	{
		if (!swap_and_process(&game->map[cur_y][cur_x], \
				&game->map[cur_y][cur_x - 1], game))
			return ;
		game->cur_x--;
	}
	else if (way == KEY_S)
	{
		if (!swap_and_process(&game->map[cur_y][cur_x], \
				&game->map[cur_y + 1][cur_x], game))
			return ;
		game->cur_y++;
	}
	game->move_count++;
}

void	move2(int way, t_game *game)
{
	int	cur_x;
	int	cur_y;

	cur_x = game->cur_x;
	cur_y = game->cur_y;
	if (way == KEY_D)
	{
		if (!swap_and_process(&game->map[cur_y][cur_x], \
				&game->map[cur_y][cur_x + 1], game))
			return ;
		game->cur_x++;
	}
	else if (way == KEY_W)
	{
		if (!swap_and_process(&game->map[cur_y][cur_x], \
				&game->map[cur_y - 1][cur_x], game))
			return ;
		game->cur_y--;
	}
	game->move_count++;
}

int	check_can_go(int way, t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->cur_x;
	next_y = game->cur_y;
	if (way == KEY_A)
		next_x--;
	else if (way == KEY_S)
		next_y++;
	else if (way == KEY_D)
		next_x++;
	else
		next_y--;
	if (game->map[next_y][next_x] == '1')
		return (-1);
	else if (game->map[next_y][next_x] == 'C')
		return (1);
	else if (game->map[next_y][next_x] == 'E')
		return (2);
	else if (game->map[next_y][next_x] == 'O')
		return (3);
	else
		return (0);
}

void	check_and_go(int way, t_game *game)
{
	int	state;

	state = check_can_go(way, game);
	if (state != -1)
	{
		if (way == KEY_A)
			move1(KEY_A, game);
		else if (way == KEY_S)
			move1(KEY_S, game);
		else if (way == KEY_D)
			move2(KEY_D, game);
		else if (way == KEY_W)
			move2(KEY_W, game);
	}
}
