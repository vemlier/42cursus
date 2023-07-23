/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:41:58 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 14:43:51 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	v_add_stack(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	v_sub_stack(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	v_scal_mul_stack(t_vector a, double b)
{
	return ((t_vector){a.x * b, a.y * b, a.z * b});
}

t_vector	v_zm_stack(t_vector a, double b)
{
	return ((t_vector){pow(a.x, b), pow(a.y, b), pow(a.z, b)});
}

t_vector	vector_multiple_stack(t_vector a, t_vector b)
{
	return ((t_vector){a.x * b.x, a.y * b.y, a.z * b.z});
}
