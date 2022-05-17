/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 01:33:17 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/17 06:35:37 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <mlx.h>

void	render_map(t_game *game);
char	*ft_itoa(int c);
void	ft_error(void);

int	swap(char *a, char *b, t_game *game)
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
	string = ft_itoa(game->comm_count);
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
		if (!swap(&game->map[cur_y][cur_x], &game->map[cur_y][cur_x - 1], game))
			return ;
		game->cur_x--;
	}
	else if (way == KEY_S)
	{
		if (!swap(&game->map[cur_y][cur_x], &game->map[cur_y + 1][cur_x], game))
			return ;
		game->cur_y++;
	}
	game->comm_count++;
}

void	move2(int way, t_game *game)
{
	int	cur_x;
	int	cur_y;

	cur_x = game->cur_x;
	cur_y = game->cur_y;
	if (way == KEY_D)
	{
		if (!swap(&game->map[cur_y][cur_x], &game->map[cur_y][cur_x + 1], game))
			return ;
		game->cur_x++;
	}
	else if (way == KEY_W)
	{
		if (!swap(&game->map[cur_y][cur_x], &game->map[cur_y - 1][cur_x], game))
			return ;
		game->cur_y--;
	}
	game->comm_count++;
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
