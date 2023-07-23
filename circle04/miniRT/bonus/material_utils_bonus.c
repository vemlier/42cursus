/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:37:24 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:03:36 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include <math.h>
#define _USE_MATH_DEFINES

t_color	*mat_helper(t_material mat,
	t_vector *position, int x, int y)
{
	t_color			*ret;
	unsigned int	tmp;
	unsigned int	tmp2;

	ret = NULL;
	tmp = (((unsigned int)position->z % 2) + y);
	tmp2 = (((unsigned int)position->x % 2) + x);
	if (((tmp + tmp2) % 2) == 0)
		ret = mat.m_c1;
	else
		ret = mat.m_c2;
	return (ret);
}
