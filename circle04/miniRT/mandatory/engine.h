/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:26:15 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/25 15:22:26 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "vector.h"
# include "image.h"
# include "color.h"
# include "ray.h"
# include "sphere.h"
# include "scene.h"

typedef struct s_find_ret
{
	double	dist_min;
	t_obj	*obj;
}				t_find_ret;

t_find_ret	*find_nearest(t_ray *ray, t_scene *scene, t_wh *im);
t_color		*engine_color_at(t_obj *obj_hit, t_vector *hit_pos,
				t_vector *hit_normal, t_scene *scene);
t_color		*ray_trace(t_ray *ray, t_scene *scene, t_wh *im);
void		render(t_scene *scene, t_wh *im);
#endif
