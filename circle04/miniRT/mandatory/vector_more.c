/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:37:00 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 14:41:39 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*v_n(double x, double y, double z);

t_vector	*v_cp(t_vector *a, t_vector *b)
{
	t_vector	*vector;

	vector = v_n(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z, a->x * b->y - a->y * b->x);
	return (vector);
}

t_vector	v_cp_stack(t_vector a, t_vector b)
{
	return ((t_vector){a.y * b.z - a.z * b.y, a.z * b.x
		- a.x * b.z, a.x * b.y - a.y * b.x});
}
