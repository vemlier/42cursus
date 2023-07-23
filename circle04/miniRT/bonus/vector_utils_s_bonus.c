/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 05:03:48 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 05:03:49 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	v_l_s(t_vector vector)
{
	double	result;

	result = sqrt(vector.x * vector.x + vector.y
			* vector.y + vector.z * vector.z);
	return (result);
}

double	v_l2_s(t_vector vector)
{
	double	result;

	result = (vector.x * vector.x + vector.y
			* vector.y + vector.z * vector.z);
	return (result);
}

t_vector	v_nor_s(t_vector vector)
{
	double	length;

	length = v_l_s(vector);
	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return (vector);
}

double	v_dp_s(t_vector a, t_vector b)
{
	double	result;

	result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (result);
}

t_vector	v_smc_s(t_vector a, double b)
{
	t_vector	vector;

	vector = (t_vector){
		a.x = a.x * b,
		a.y = a.y * b,
		a.z = a.z * b,
	};
	return (vector);
}
