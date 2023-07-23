/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:06:10 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:06:40 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector.h"
# include "image.h"
# include "color.h"

typedef struct s_light
{
	t_vector	*position;
	t_vector	*color;
	double		ratio;
}				t_light;
#endif
