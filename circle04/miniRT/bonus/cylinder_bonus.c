/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:17:10 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 18:29:32 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "sphere.h"
#include "vector.h"

void	intersects_cylinder_help(t_cylinder *cylinder, t_ray *ray,
			double *ret, double *tmp);

int	side_help(t_cylinder *cylinder, t_ray *ray, t_cyhelp *ch)
{
	ch->v = ray->direction;
	v_nor(&ch->v);
	ch->h = v_sub_stack(*cylinder->top, *cylinder->bottom);
	ch->h_ori = v_sub_stack(*cylinder->top, *cylinder->bottom);
	v_nor(&ch->h);
	ch->w = v_sub_stack(ray->origin, *cylinder->bottom);
	ch->r = (cylinder->diameter / 2);
	ch->a = (v_dp_s(ch->v, ch->v) - (v_dp_s(ch->v, ch->h)
				* v_dp_s(ch->v, ch->h)));
	ch->b = 2 * (v_dp_s(ch->v, ch->w) - (v_dp_s(ch->v, ch->h)
				* v_dp_s(ch->w, ch->h)));
	ch->c = v_dp_s(ch->w, ch->w) - v_dp_s(ch->w, ch->h)
		* v_dp_s(ch->w, ch->h) - ch->r * ch->r;
	ch->d = ch->b * ch->b - 4 * ch->a * ch->c;
	if (ch->d >= 0)
		ch->d_sqr = sqrt(ch->d);
	return (0);
}

double	hit_cylinder_side(t_cylinder *cylinder, t_ray *ray)
{
	t_cyhelp	ch;

	side_help(cylinder, ray, &ch);
	if (ch.d < 0)
		return (0);
	ch.d_sqr = sqrt(ch.d);
	if (ch.d > 0)
	{
		ch.t = (-ch.b - ch.d_sqr) / (ch.a * 2);
		ch.l_int = v_add_stack(ray->origin, v_scal_mul_stack(ch.v, ch.t));
		ch.l_int_tmp = v_dp_s(v_sub_stack(ch.l_int, *cylinder->bottom), ch.h);
		if ((ch.l_int_tmp > 0) && (ch.l_int_tmp < cylinder->height))
			return (ch.t);
		ch.t = (-ch.b + ch.d_sqr) / (ch.a * 2);
		ch.l_int = v_add_stack(ray->origin, v_scal_mul_stack(ch.v, ch.t));
		ch.l_int_tmp = v_dp_s(v_sub_stack(ch.l_int, *cylinder->bottom), ch.h);
		if ((ch.l_int_tmp > 0) && (ch.l_int_tmp < cylinder->height))
			return (ch.t);
	}
	if (ch.d == 0)
		return (-1 * ch.b / (2 * ch.a));
	return (0);
}

double	cylinder_circle(t_cylinder *cylinder, t_ray *ray, bool f)
{
	t_cycirh	cyh;

	cyh.radius = cylinder->diameter / 2;
	cyh.denom = v_dp_s(ray->direction, *cylinder->direction);
	if (f)
		cyh.center = *cylinder->bottom;
	else
		cyh.center = *cylinder->top;
	if (cyh.denom == 0)
		return (0);
	cyh.root = v_dp_s(v_sub_stack(cyh.center, ray->origin),
			*cylinder->direction) / cyh.denom;
	cyh.hit_pos = v_add_stack(ray->origin,
			v_scal_mul_stack(ray->direction, cyh.root));
	cyh.distance = v_l_s(v_sub_stack(cyh.hit_pos, cyh.center));
	if (cyh.distance <= cyh.radius)
		return (cyh.root);
	return (0);
}

double	intersects_cylinder(t_cylinder *cylinder, t_ray *ray)
{
	double	ret;
	double	tmp;

	ret = 111111111;
	tmp = hit_cylinder_side(cylinder, ray);
	intersects_cylinder_help(cylinder, ray, &ret, &tmp);
	if (cylinder->circle)
		return (ret);
	return (0);
}

t_vector	*normal_cylinder(t_cylinder *cylinder, t_vector *pos, t_ray *ray)
{
	t_vector	*ret;
	t_vector	*tmp_vector;
	double		tmp;

	ret = malloc(sizeof(t_vector));
	if (ret == NULL)
		return (0);
	if (cylinder->circle == 1)
		*ret = v_nor_s(side_normal(cylinder, *pos));
	else if (cylinder->circle == 2)
		*ret = v_nor_s(v_scal_mul_stack(*cylinder->direction, -1));
	else if (cylinder->circle == 3)
		*ret = v_nor_s(*cylinder->direction);
	if (cylinder->circle)
	{
		tmp = v_dp_s(*ret, ray->direction);
		if (tmp > 0.0)
		{
			tmp_vector = v_scal_mul(ret, -1.0);
			return (tmp_vector);
		}
		return (ret);
	}
	free(ret);
	return (0);
}
