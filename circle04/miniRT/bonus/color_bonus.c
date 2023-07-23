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
#include "image.h"
#include "color.h"

int	cal_color(const char *hex, int a, int b)
{
	int	c1;
	int	c2;
	int	ret;

	c1 = 0;
	c2 = 0;
	if ((hex[a] >= '0') && (hex[a] <= '9'))
		c1 = (int)hex[a] - 48;
	else if ((hex[a] >= 'A') && (hex[a] <= 'F'))
		c1 = (int)hex[a] - 55;
	if ((hex[b] >= '0') && (hex[b] <= '9'))
		c2 = (int)hex[b] - 48;
	else if ((hex[b] >= 'A') && (hex[b] <= 'F'))
		c2 = (int)hex[b] - 55;
	ret = (c1 * 16) + c2;
	return (ret);
}

t_color	*from_hex(const char *hex)
{
	double		r;
	double		g;
	double		b;
	t_vector	*ret_color;

	r = (cal_color(hex, 1, 2)) / 255.0f;
	g = (cal_color(hex, 3, 4)) / 255.0f;
	b = (cal_color(hex, 5, 6)) / 255.0f;
	ret_color = v_n(r, g, b);
	return (ret_color);
}

t_vector	*color(double x, double y, double z)
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
