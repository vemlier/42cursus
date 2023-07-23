/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:49:49 by chukim            #+#    #+#             */
/*   Updated: 2022/12/21 17:51:48 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "sphere.h"
#include "vector.h"
#include "object.h"

void	calculate_cone_det(t_var *var, t_cone *cone, t_ray *ray)
{
	var->m = pow(cone->radius, 2) / pow(cone->height, 2);
	var->v = ray->direction;
	var->h = v_sub_stack(*cone->center, *cone->tip);
	var->h_pivot = v_nor_s(var->h);
	var->w = v_sub_stack(ray->origin, *cone->tip);
	var->a = v_dp_s(var->v, var->v) - (var->m * pow(v_dp_s(var->v,
					var->h_pivot), 2)) - pow(v_dp_s(var->v, var->h_pivot), 2);
	var->b = 2 * ((v_dp_s(var->v, var->w)) - (var->m * v_dp_s(var->v,
					var->h_pivot) * v_dp_s(var->w, var->h_pivot))
			- (v_dp_s(var->v, var->h_pivot) * v_dp_s(var->w, var->h_pivot)));
	var->c = v_dp_s(var->w, var->w) - (var->m * pow(v_dp_s(var->w,
					var->h_pivot), 2)) - pow(v_dp_s(var->w, var->h_pivot), 2);
	var->d = pow(var->b, 2) - (4 * var->a * var->c);
	var->d_sqr = sqrt(var->d);
}

double	calculate_cone_intersect(t_var *var, t_cone *cone, t_ray *ray)
{
	var->t = (-var->b - var->d_sqr) / (2 * var->a);
	var->l = v_add_stack(ray->origin, v_scal_mul_stack(var->v, var->t));
	var->tmp = v_dp_s(v_sub_stack(var->l, *cone->tip), var->h_pivot);
	if ((var->t > 0) && (var->tmp >= 0) && (var->tmp <= cone->height))
		return (var->t);
	var->t = (-var->b + var->d_sqr) / (2 * var->a);
	var->l = v_add_stack(ray->origin, v_scal_mul_stack(var->v, var->t));
	var->tmp = v_dp_s(v_sub_stack(var->l, *cone->tip), var->h_pivot);
	if ((var->t > 0) && (var->tmp >= 0) && (var->tmp <= cone->height))
		return (var->t);
	return (0);
}

double	calculate_cone_ret(t_var *var, t_cone *cone, t_ray *ray)
{
	double	ret;

	ret = 0;
	if (var->d < 0)
		ret = 0;
	else if (var->d > 0)
		ret = calculate_cone_intersect(var, cone, ray);
	else if (var->d == 0)
		ret = (-1 * var->b / (2 * var->a));
	return (ret);
}

double	cone_circle(t_cone *cone, t_ray *ray)
{
	double			denom;
	double			distance;
	double			root;
	t_vector		hit_pos;

	denom = v_dp_s(ray->direction, *cone->direction);
	if (denom == 0)
		return (0);
	root = v_dp_s(v_sub_stack(*cone->center, ray->origin),
			*cone->direction) / denom;
	hit_pos = v_add_stack(ray->origin, v_scal_mul_stack(ray->direction, root));
	distance = v_l_s(v_sub_stack(hit_pos, *cone->center));
	if (distance <= cone->radius)
		return (root);
	return (0);
}

double	calculate_ret(t_cone *cone, t_ray *ray, double tmp)
{
	double	ret;

	ret = 111111111.0;
	if (0 < tmp && tmp < ret)
	{
		ret = tmp;
		cone->circle = 1;
	}
	tmp = cone_circle(cone, ray);
	if (0 < tmp && tmp < ret)
	{
		ret = tmp;
		cone->circle = 2;
	}
	return (ret);
}
