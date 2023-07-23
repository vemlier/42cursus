/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:22:19 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:25:24 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"

void	camera_chker(t_camera *c1)
{
	t_vector	min_axis;

	if ((c1->fov >= 180) || (c1->fov <= 0))
		ft_exit(-1, "Error\nFov error\n");
	v_nor(c1->normal_vector);
	v_nor(c1->axis);
	min_axis = v_scal_mul_stack(*c1->axis, -1);
	if ((c1->normal_vector->x == c1->axis->x)
		&& (c1->normal_vector->y == c1->axis->y)
		&& (c1->normal_vector->z == c1->axis->z))
	{
		c1->axis->x = 0;
		c1->axis->y = 0;
		c1->axis->z = 1;
	}
	else if ((c1->normal_vector->x == min_axis.x)
		&& (c1->normal_vector->y == min_axis.y)
		&& (c1->normal_vector->z == min_axis.z))
	{
		c1->axis->x = 0;
		c1->axis->y = 0;
		c1->axis->z = 1;
	}
}
