/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:10:06 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/17 06:54:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	update_count_data(t_game *game, char block, int higth, int width);
int		ft_strncmp(char *s1, char *s2, int n);
int		has_same_width(int width);
int		count_enemy(t_game *game);

int	is_arrounded_wall(t_game *game)
{
	int	width;
	int	higth;

	higth = 0;
	while (higth < game->higth)
	{
		width = 0;
		while (width < game->width)
		{
			if (higth == 0 || higth == game->higth - 1)
				if (game->map[higth][width] != '1')
					return (0);
			width++;
		}
		if (game->map[higth][0] != '1' || \
				game->map[higth][game->width - 1] != '1')
			return (0);
		higth++;
	}
	return (1);
}

int	check_valid_map(t_game *game)
{
	int	width;
	int	higth;

	higth = 0;
	while (game->map[higth] != 0)
	{
		width = 0;
		while (game->map[higth][width] != '\n')
		{
			update_count_data(game, game->map[higth][width], higth, width);
			width++;
		}
		if (!has_same_width(width))
			return (1);
		game->width = width;
		higth++;
	}
	game->higth = higth;
	if (game->sp_cnt != 1 || game->exit_cnt < 1 || !is_arrounded_wall(game))
		return (1);
	return (0);
}

int	check_file_name(char *file)
{
	while (*file != '\0')
		file++;
	file -= 4;
	if (ft_strncmp(file, ".ber", 4))
		return (0);
	return (1);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	check_error(t_game *game, int argc, char **argv)
{
	game->sp_cnt = 0;
	game->coin_cnt = 0;
	game->exit_cnt = 0;
	if (argc != 2)
		ft_error();
	else if (check_file_name(argv[1]))
		ft_error();
	else if (check_valid_map(game))
		ft_error();
	else if ((game->sp_cnt != 1) || (game->exit_cnt < 1))
		ft_error();
}
