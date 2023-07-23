/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:06:45 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 15:29:37 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdio.h>
# include <stdlib.h>
# include "vector.h"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}				t_mlx;

typedef struct s_wh
{
	int		width;
	int		height;
	t_color	**pixels;
	int		ob_n;
}				t_wh;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_di
{
	int	count_w;
	int	count_h;
	int	tmp_x;
	int	tmp_y;
	int	tmp_z;
}				t_di;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		image;
}				t_vars;

void	draw_image(t_wh *wh);
void	set_pixel(t_wh *wh, int x, int y, t_color *col);
void	init_pixels(t_wh *wh);
void	open_mlx(t_wh *wh);
#endif
