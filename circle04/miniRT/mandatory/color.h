/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:25:31 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:25:50 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "vector.h"
# include "image.h"

int			cal_color(const char *hex, int a, int b);
t_vector	*color(double x, double y, double z);
t_color		*from_hex(const char *hex);
#endif
