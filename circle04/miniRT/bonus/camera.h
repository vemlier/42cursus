/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:30 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:22:13 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"
# include "image.h"
# include "ft_exit/ft_exit.h"

typedef struct s_camera
{
	t_vector	*position;
	t_vector	*normal_vector;
	t_vector	*axis;
	double		fov;
}				t_camera;

void	camera_chker(t_camera *c1);
#endif
