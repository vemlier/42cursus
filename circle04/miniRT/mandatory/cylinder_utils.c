/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:17:23 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 16:26:57 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "sphere.h"
#include "vector.h"

double	cylinder_circle(t_cylinder *cylinder, t_ray *ray, bool f);

t_vector	side_normal(t_cylinder *cylinder, t_vector pos)
{
	double		t;
	t_vector	pt;

	t = v_dp_s(v_sub_stack(pos, *cylinder->bottom),
			*cylinder->direction);
	pt = v_add_stack(*cylinder->bottom,
			v_scal_mul_stack(*cylinder->direction, t));
	return (v_sub_stack(pos, pt));
}

bool	cylinder_height(t_cylinder *cylinder, double t, t_ray *ray)
{
	t_vector const	hit_pos = v_add_stack(ray->origin,
			v_scal_mul_stack(ray->direction, t));
	t_vector const	bot_to_pos = v_sub_stack(hit_pos,
			*cylinder->bottom);
	double const	hit_height = v_dp_s(bot_to_pos,
			*cylinder->direction);

	if (0 < hit_height && (hit_height) <= cylinder->height)
		return (true);
	return (false);
}

void	intersects_cylinder_help(t_cylinder *cylinder, t_ray *ray,
	double *ret, double *tmp)
{
	cylinder->circle = 0;
	if (0 < *tmp && *tmp < *ret)
	{
		*ret = *tmp;
		cylinder->circle = 1;
	}
	*tmp = cylinder_circle(cylinder, ray, true);
	if (0 < *tmp && *tmp < *ret)
	{
		*ret = *tmp;
		cylinder->circle = 2;
	}
	*tmp = cylinder_circle(cylinder, ray, false);
	if (0 < *tmp && *tmp < *ret)
	{
		*ret = *tmp;
		cylinder->circle = 3;
	}
}
