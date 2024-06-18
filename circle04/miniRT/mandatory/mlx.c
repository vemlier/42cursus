/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:09:21 by chukim            #+#    #+#             */
/*   Updated: 2022/12/25 21:11:24 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "scene.h"
#include "engine.h"
#include "minilibx/mlx.h"

int	color_to_int(t_color *pixel)
{
	int	ret;
	int	x;
	int	y;
	int	z;

	ret = 0;
	x = (int)(pixel->x * 255.0);
	if (x > 255)
		x = 255;
	y = (int)(pixel->y * 255.0);
	if (y > 255)
		y = 255;
	z = (int)(pixel->z * 255.0);
	if (z > 255)
		z = 255;
	ret = (x << 16);
	ret += (y << 8);
	ret += z;
	return (ret);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->wh->width)
	{
		j = 0;
		while (j < vars->wh->height)
		{
			my_mlx_pixel_put(vars->image, i, j,
				color_to_int(vars->wh->pixels[(j * vars->wh->width) + i]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image->img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 119)
	{
		// vars->scene->camera->position->y -= 0.5;
		// render(vars->scene, vars->wh);
		// put_pixel(vars);
	}
	else if (keycode == 115)
	{
		// vars->scene->camera->position->y += 0.5;
		// render(vars->scene, vars->wh);
		// put_pixel(vars);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}

void	open_mlx(t_wh *wh, t_scene *scene)
{
	t_vars	vars;
	t_data	image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, wh->width, wh->height, "miniRT");
	vars.wh = wh;
	vars.image = &image;
	vars.scene = scene;
	image.img = mlx_new_image(vars.mlx, wh->width, wh->height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	vars.scene->camera->position->y -= 1;
	put_pixel(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
}
