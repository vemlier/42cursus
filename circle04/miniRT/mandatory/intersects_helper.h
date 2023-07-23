/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects_helper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:16:05 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:17:26 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTS_HELPER_H
# define INTERSECTS_HELPER_H

# include <stdio.h>
# include <stdlib.h>
# include "vector.h"
# include "image.h"
# include "color.h"
# include "sphere.h"
# include "ray.h"
# include "scene.h"
# include "engine.h"
# include "light.h"
# include "material.h"

typedef struct s_is
{
	t_vector	sphere_to_ray;
	double		b;
	double		c;
	double		discriminant;
	double		dist;
}				t_is;

typedef struct s_ip
{
	double		t;
	double		dist;
	double		discriminant;
	double		bunmo;
	t_vector	po_tmp;
	t_vector	po_tmp2;
	t_vector	tmp;
	double		bunza;
}				t_ip;

void	is_init(t_is *is1, t_sphere *sphere, t_ray *ray);
void	ip_init(t_ip *ip1, t_plane *plane, t_ray *ray);
#endif
