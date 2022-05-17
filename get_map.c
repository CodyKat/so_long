/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:38:04 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/16 17:00:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "so_long.h"

char	*get_next_line(int fd);
void	load_image(t_game *game);
void	ft_error(void);
size_t	ft_strlen(const char *s);

int	get_line_count(char **argv)
{
	int		output;
	int		fd;
	char	*line;

	output = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		output++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (output);
}

void	get_map(t_game *game, char **argv)
{
	int	fd;
	int	line_count;
	int	index;

	index = 0;
	line_count = get_line_count(argv);
	game->map = (char **)malloc(sizeof(char *) * (line_count + 1));
	fd = open(argv[1], O_RDONLY);
	while (index < line_count)
	{
		game->map[index] = get_next_line(fd);
		if (game->map[index] == 0)
			ft_error();
		index++;
	}
	close(fd);
	game->width = ft_strlen(game->map[index - 1]) - 1;
	game->higth = line_count;
	game->map[index] = 0;
}
