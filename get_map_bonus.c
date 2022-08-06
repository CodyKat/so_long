/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:45:12 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/07 16:16:28 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#define HARD_TO_CREATE 20

void	remove_newline(char *map_line)
{
	if (map_line == 0)
		return ;
	while ((*map_line != 0) && (*map_line != '\n'))
		map_line++;
	if (*map_line == '\n')
		*map_line = 0;
}

int	get_line_count(char **argv, int	*line_count)
{
	int		output;
	int		fd;
	char	*line;

	output = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	line = get_next_line(fd);
	while (line)
	{
		output++;
		free(line);
		line = get_next_line(fd);
		if (line != 0 && *line == '\n')
			output--;
	}
	close(fd);
	*line_count = output;
	return (output);
}

void	get_map(t_game *game, char **argv)
{
	int	fd;
	int	line_count;
	int	index;

	if (check_file_name(argv[1]))
		ft_error();
	index = 0;
	if (get_line_count(argv, &line_count) < 3)
		ft_error();
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (game->map == 0)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	while (index < line_count)
	{
		game->map[index] = get_next_line(fd);
		remove_newline(game->map[index]);
		if (game->map[index] == 0)
			ft_error();
		index++;
	}
	close(fd);
	game->width = ft_strlen(game->map[0]);
	game->heigth = line_count;
	game->map[index] = 0;
}

void	create_enemy(t_game *game)
{
	int		cur_height;
	int		cur_width;
	int		flag_create;
	int		enemy_count;

	enemy_count = 0;
	cur_height = 0;
	while (cur_height++ < game->heigth - 2)
	{
		cur_width = 0;
		while (cur_width++ < game->width - 2)
		{
			if (game->map[cur_height][cur_width] == '0')
			{
				flag_create = rand();
				if (flag_create % HARD_TO_CREATE == 0)
				{
					game->map[cur_height][cur_width] = 'O';
					enemy_count++;
				}
			}
		}
	}
	game->enemy_cnt = enemy_count;
}

void	reflect_enemy(t_game *game)
{
	int	enemy_count;

	enemy_count = 0;
	game->enemy = (t_enemy **)malloc(sizeof(t_enemy *) * game->enemy_cnt);
	while (enemy_count < game->enemy_cnt)
	{
		game->enemy[enemy_count] = (t_enemy *)malloc(sizeof(t_enemy));
		enemy_count++;
	}
}
