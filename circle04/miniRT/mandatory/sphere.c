/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:56:10 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/19 17:31:26 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "intersects_helper.h"
#include "free_helper.h"

double	intersects(t_obj *obj, t_ray *ray)
{
	double	ret;

	if (obj->type == 1)
	{
		ret = intersects_sphere(obj->s, ray);
		return (ret);
	}
	else if (obj->type == 2)
	{
		ret = intersects_plane(obj->p, ray);
		return (ret);
	}
	else if (obj->type == Cylinder)
	{
		ret = intersects_cylinder(obj->c, ray);
		return (ret);
	}
	else if (obj->type == Cone)
	{
		ret = intersects_cone(obj->cone, ray);
		return (ret);
	}
	return (0);
}

double	intersects_sphere(t_sphere *sphere, t_ray *ray)
{
	t_is	is1;

	is_init(&is1, sphere, ray);
	if (is1.discriminant >= 0)
	{
		is1.dist = (-is1.b - sqrt(is1.discriminant)) / 2;
		if (is1.dist > 0)
		{
			return (is1.dist);
		}
	}
	return (0);
}

double	intersects_plane(t_plane *plane, t_ray *ray)
{
	t_ip	ip1;

	ip_init(&ip1, plane, ray);
	if (ip1.t <= 0)
		return (0);
	ip1.po_tmp2 = v_scal_mul_stack(ray->direction, ip1.t);
	ip1.tmp = v_add_stack(ray->origin, ip1.po_tmp2);
	ip1.dist = (((ray->origin.x - ip1.tmp.x)
				* (ray->origin.x - ip1.tmp.x))
			+ ((ray->origin.y - ip1.tmp.y) * (ray->origin.y - ip1.tmp.y))
			+ ((ray->origin.z - ip1.tmp.z) * (ray->origin.z - ip1.tmp.z)));
	ip1.dist = sqrt(ip1.dist);
	if (ip1.dist > 0)
		return (ip1.dist);
	return (0);
}

t_vector	*normal(t_sphere *sphere, t_vector *surface_point)
{
	t_vector	*ret;

	ret = v_sub(surface_point, sphere->center);
	v_nor(ret);
	return (ret);
}

t_vector	*normal_plane(t_plane *plane, t_vector *surface_point)
{
	(void)surface_point;
	return (plane->nv);
}
