/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:45:53 by chukim            #+#    #+#             */
/*   Updated: 2022/12/21 18:01:57 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "sphere.h"
#include "vector.h"
#include "object.h"

double	intersects_cone(t_cone *cone, t_ray *ray)
{
	t_var	*var;
	double	ret;
	double	tmp;

	cone->circle = 0;
	var = (t_var *)malloc(sizeof(t_var));
	if (var == NULL)
		return (0);
	calculate_cone_det(var, cone, ray);
	tmp = calculate_cone_ret(var, cone, ray);
	free(var);
	ret = calculate_ret(cone, ray, tmp);
	if (cone->circle)
		return (ret);
	return (0);
}

t_vector	*calculate_cone_normal(t_vector *ret, t_ray *ray)
{
	double	tmp;

	tmp = v_dp_s(*ret, ray->direction);
	if (tmp > 0)
		return (v_smc(ret, -1));
	return (ret);
}

t_vector	*normal_cone(t_cone *cone, t_vector *pos, t_ray *ray)
{
	double		co;
	t_vector	*ret;
	t_vector	cp;
	t_vector	unit_vector;

	ret = (t_vector *)malloc(sizeof(t_vector));
	if (ret == NULL)
		return (0);
	if (cone->circle == 1)
	{
		cp = v_sub_stack(*pos, *cone->tip);
		unit_vector = v_nor_s(v_sub_stack(*cone->center, *cone->tip));
		co = pow(v_l_s(cp), 2) / v_dp_s(cp, unit_vector);
		*ret = v_nor_s(v_sub_stack(cp, v_scal_mul_stack(unit_vector, co)));
	}
	else if (cone->circle == 2)
		*ret = v_nor_s(v_scal_mul_stack(*cone->direction, -1));
	ret = calculate_cone_normal(ret, ray);
	if (cone->circle)
		return (ret);
	free(ret);
	return (0);
}
