#include <stdio.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "image.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 119)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}

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

void	open_mlx(t_wh *wh)
{
	t_vars vars;
	t_data image;

	image = vars.image;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, wh->width, wh->height, "miniRT"); 
  	image.img = mlx_new_image(vars.mlx, wh->width, wh->height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	for (int i = 0 ; i < wh->width; i++)
	{
		for (int j = 0 ; j < wh->height; j++)
			my_mlx_pixel_put(&image, i, j, color_to_int(wh->pixels[(j * wh->width) + i]));
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
}
