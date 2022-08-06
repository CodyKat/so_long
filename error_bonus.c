/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:44:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 16:09:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_arrounded_wall(t_game *game)
{
	int	width;
	int	heigth;

	heigth = 0;
	while (heigth < game->heigth)
	{
		width = 0;
		while (width < game->width)
		{
			if (heigth == 0 || heigth == game->heigth - 1)
				if (game->map[heigth][width] != '1')
					return (0);
			width++;
		}
		if (game->map[heigth][0] != '1' || \
				game->map[heigth][game->width - 1] != '1')
			return (0);
		heigth++;
	}
	return (1);
}

void	check_valid_map(t_game *game)
{
	int	width;
	int	heigth;

	heigth = 0;
	while (game->map[heigth] != 0)
	{
		width = 0;
		while (game->map[heigth][width] != 0)
		{
			update_count_data(game, game->map[heigth][width], heigth, width);
			width++;
		}
		if (!has_same_width(width))
			ft_error();
		heigth++;
	}
	if (game->sp_cnt != 1 || game->exit_cnt < 1 || !is_arrounded_wall(game))
		ft_error();
}

int	check_file_name(char *file)
{
	int	file_len;

	file_len = ft_strlen(file);
	if (file_len <= 4)
		ft_error();
	while (*file != '\0')
		file++;
	file -= 4;
	if (ft_strncmp(file, ".ber", 4) == 0)
		return (1);
	else if ((file_len >= 5) && (*(file - 1) == '/'))
		return (1);
	return (0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
