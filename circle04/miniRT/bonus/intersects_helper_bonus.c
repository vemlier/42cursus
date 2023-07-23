/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:29 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:18:36 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersects_helper.h"

void	is_init(t_is *is, t_sphere *sphere, t_ray *ray)
{
	is->sphere_to_ray = v_sub_stack(ray->origin, *sphere->center);
	is->b = 2 * v_dp(&ray->direction, &is->sphere_to_ray);
	is->c = v_dp(&is->sphere_to_ray,
			&is->sphere_to_ray) - (sphere->radius) * (sphere->radius);
	is->discriminant = is->b * is->b - 4 * is->c;
}

void	ip_init(t_ip *ip, t_plane *plane, t_ray *ray)
{
	ip->t = 0;
	ip->dist = 0;
	ip->discriminant = v_dp(&ray->direction, plane->nv);
	ip->bunmo = v_dp(&ray->direction, plane->nv);
	ip->po_tmp = v_sub_stack(*plane->point, ray->origin);
	ip->bunza = v_dp(&ip->po_tmp, plane->nv);
	if (ip->discriminant == 0)
		ip->bunmo = 0.01 * sqrt(ip->discriminant * ip->discriminant);
	ip->t = (ip->bunza / ip->bunmo);
}
