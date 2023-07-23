/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:50:12 by chukim            #+#    #+#             */
/*   Updated: 2022/06/22 07:09:23 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	image;
	int		wid;
	int		hei;

	image.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &wid, &hei);
	image.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
	image.chara = mlx_xpm_file_to_image(mlx, "./images/chara.xpm", &wid, &hei);
	image.chest = mlx_xpm_file_to_image(mlx, "./images/chest.xpm", &wid, &hei);
	image.door = mlx_xpm_file_to_image(mlx, "./images/door.xpm", &wid, &hei);
	image.door2 = mlx_xpm_file_to_image(mlx, "./images/door2.xpm", &wid, &hei);
	return (image);
}

void	put_img(t_game *g, int w, int h)
{
	if (g->str_line[h * g->width + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chest, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.chara, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.door2, w * 64, h * 64);
	}
	else if (g->str_line[h * g->width + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.door, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 64, h * 64);
	}
}

void	setting_img(t_game *game)
{
	int		height;
	int		width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			put_img(game, width, height);
			width++;
		}
		height++;
	}
}
