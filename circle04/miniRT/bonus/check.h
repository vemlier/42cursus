/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:27:34 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/20 03:30:00 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "vector.h"
# include "camera.h"
# include "sphere.h"
# include "scene.h"
# include "ft_init/ft_init.h"
# include "ft_exit/ft_exit.h"

void	plane_normal_chker(t_plane *plane1, t_camera *camera2);
void	color_chk(t_scene *scene2);
void	srd_light_chk(t_scene *scene2);
void	mat_type_chk(t_scene *scene2);
#endif
