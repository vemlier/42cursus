/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:47:08 by chukim            #+#    #+#             */
/*   Updated: 2022/06/20 15:08:50 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_error("File open fail.\n");
	line = get_next_line(fd);
	game->height = 0;
	game->walk_cnt = 0;
	game->width = ft_strlen(line) - 1;
	game->str_line = ft_strdup_new(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin_new(game->str_line, line);
		}
	}
	close(fd);
}

void	map_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str_line))
	{
		if (i < game->width)
		{
			if (game->str_line[i] != '1')
				print_error("Map must be surrounded by walls\n");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->str_line[i] != '1')
				print_error("Map must be surrounded by walls\n");
		}
		else if (i > (int)ft_strlen(game->str_line) - game->width)
		{
			if (game->str_line[i] != '1')
				print_error("Map must be surrounded by walls\n");
		}
		i++;
	}
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->all_col = 0;
	game->col_cnt = 0;
	while (i++ < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (num_e == 0)
		print_error("Not enough exits\n");
	if (game->all_col == 0)
		print_error("Not enough collectibles\n");
	if (num_p != 1)
		print_error("Must have one starting position\n");
}

void	map_check(t_game *game)
{
	if (game->height * game->width != (int)ft_strlen(game->str_line))
		print_error("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
}
