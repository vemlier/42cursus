/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:08:41 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:15:37 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"
#include "color.h"

int	to_byte(double c)
{
	return ((int)round(fmax(fmin(c * 255, 255), 0)));
}

void	draw_image(t_wh *wh)
{
	t_di	di1;
	FILE	*ptr_file;

	ptr_file = fopen("./newchq.ppm", "wb");
	fprintf(ptr_file, "P3 %d %d\n255\n", wh->width, wh->height);
	di1.count_h = -1;
	while (++(di1.count_h) < wh->height)
	{
		di1.count_w = -1;
		while (++di1.count_w < wh->width)
		{
			di1.tmp_x = to_byte((wh->pixels[di1.count_h
						* wh->width + di1.count_w])->x);
			di1.tmp_y = to_byte((wh->pixels[di1.count_h
						* wh->width + di1.count_w])->y);
			di1.tmp_z = to_byte((wh->pixels[di1.count_h
						* wh->width + di1.count_w])->z);
			fprintf(ptr_file, "%d %d %d ", di1.tmp_x, di1.tmp_y, di1.tmp_z);
		}
		fprintf(ptr_file, "\n");
	}
	printf("draw4\n");
	fclose(ptr_file);
}

void	set_pixel(t_wh *wh, int x, int y, t_color *col)
{
	(wh->pixels)[y * wh->width + x] = col;
}

void	init_pixels(t_wh	*wh)
{
	t_color	**tmp_pixels;

	tmp_pixels = (t_color **)malloc(sizeof(t_color *) * wh->width * wh->height);
	if (!tmp_pixels)
		exit(0);
	wh->pixels = tmp_pixels;
}
