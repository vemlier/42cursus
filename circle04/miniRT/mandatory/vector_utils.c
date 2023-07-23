/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:44:06 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 14:45:12 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	v_l(t_vector *vector)
{
	double	result;

	result = sqrt(vector->x * vector->x + vector->y
			* vector->y + vector->z * vector->z);
	return (result);
}

void	v_nor(t_vector *vector)
{
	double	length;

	length = v_l(vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
}

double	v_dp(t_vector *a, t_vector *b)
{
	double	result;

	result = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
	return (result);
}

t_vector	*v_smc(t_vector *a, double b)
{
	t_vector	*vector;

	vector = v_n(a->x * b, a->y * b, a->z * b);
	free(a);
	return (vector);
}

double	v_distance(t_vector v1, t_vector v2)
{
	return (sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2)
			+ pow(v1.z - v2.z, 2)));
}
