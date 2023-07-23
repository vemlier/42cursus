/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:24:37 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 15:24:55 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "image.h"
# include "color.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;
#endif
