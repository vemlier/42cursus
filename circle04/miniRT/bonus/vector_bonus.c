/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:58:31 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 19:59:41 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*v_n(double x, double y, double z)
{
	t_vector	*vector;

	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

t_vector	*v_sub(t_vector *a, t_vector *b)
{
	t_vector	*vector;

	vector = v_n(a->x - b->x, a->y - b->y, a->z - b->z);
	return (vector);
}

t_vector	*v_add(t_vector *a, t_vector *b)
{
	t_vector	*vector;

	vector = v_n(a->x + b->x, a->y + b->y, a->z + b->z);
	return (vector);
}

t_vector	*v_scal_mul(t_vector *a, double b)
{
	t_vector	*vector;

	vector = v_n(a->x * b, a->y * b, a->z * b);
	return (vector);
}

t_vector	*v_zm(t_vector *a, double b)
{
	t_vector	*vector;

	vector = v_n(pow(a->x, b), pow(a->y, b), pow(a->z, b));
	return (vector);
}
