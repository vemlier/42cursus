/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:23:18 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 15:24:28 by ysungwon         ###   ########.fr       */
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

#endif
