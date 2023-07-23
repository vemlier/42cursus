/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:23:18 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/25 14:30:30 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "vector.h"
# include "image.h"
# include "color.h"
# include "ray.h"
# include "sphere.h"
# include "light.h"
# include "camera.h"
//# include "ft_init/ft_init.h"

typedef struct s_acl_check
{
	int	acount;
	int	ccount;
	int	lcount;
	int	lflag;
}				t_acl_check;

typedef struct s_scene
{
	t_acl_check	*acl;
	t_camera	*camera;
	t_obj		**objects;
	t_light		**lights;
	t_vector	*ambient;
	t_color		**ppm_pixels;
	float		ambient_ratio;
	int			width;
	int			height;
	int			l_n;
	int			ob_n;
}				t_scene;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_wh		*wh;
	t_data		*image;
	t_scene		*scene;
}				t_vars;

void	open_mlx(t_wh *wh, t_scene *scene);
#endif
