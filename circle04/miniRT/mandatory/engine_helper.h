/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:36:37 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:41:30 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HELPER_H
# define ENGINE_HELPER_H

# include <stdio.h>
# include <stdlib.h>
# include "vector.h"
# include "image.h"
# include "color.h"
# include "sphere.h"
# include "ray.h"
# include "scene.h"
# include "engine.h"
# include "light.h"
# include "material.h"
# define MAX_DEPTH 5
# define MIN_DISPLACE 0.0001

typedef struct s_trace
{
	t_color		color;
	t_find_ret	*tmp;
	t_obj		*obj_hit;
	t_vector	hit_pos;
	t_vector	*hit_normal;
	t_vector	*hit_normal_tmp;
	t_vector	scalar_tmp;
	t_color		*tmp_color;
	t_color		*ret_color;
	t_color		*ret_color2;
	t_color		*final_color;
	t_vector	*new_ray_pos;
	t_vector	*new_ray_dir;
	double		new_ray_dir_tmp;
	t_vector	*new_ray_dir_tmp2;
	t_ray		new_ray;
	double		dist_hit;
}				t_trace;

typedef struct s_render
{
	int			width;
	int			height;
	int			i;
	int			j;
	double		aspect_ratio;
	double		nv_vx_tan;
	t_vector	x0;
	t_vector	x1;
	t_vector	xstep;
	t_vector	y0;
	t_vector	y1;
	t_vector	ystep;
	t_camera	*camera;
	t_vector	*viewport_y;
	t_vector	*viewport_x;
	t_vector	x;
	t_vector	y;
	t_ray		ray;
	t_vector	point;
	t_color		*color;
}				t_render;

typedef struct s_fn
{
	double		dist;
	double		dist_min;
	int			objects_num;
	int			i;
	t_obj		*obj;
	t_obj		*obj_hit;
	t_find_ret	*tmp_addr;
}				t_fn;

typedef struct s_eca
{
	t_material	*material;
	t_color		*obj_color;
	t_vector	to_cam;
	t_color		color;
	t_color		ffffff;
	t_color		tmp_col;
	t_color		*ret_color;
	t_vector	half_vector;
	t_light		*light;
	t_ray		to_light;
	t_vector	kk;
	double		ambient;
	double		dist;
	double		inshadow;
	double		dl;
	double		tmp_scalar;
	double		specular_k;
	int			i;
	int			k;
}				t_eca;

void	init_eca(t_eca *eca1, t_obj *obj_hit,
			t_vector *hit_pos, t_scene *scene);
void	init_fn(t_fn *fn1, t_wh *im);
void	render_init(t_render *t1);
void	render_camera_init(t_render *t1, t_scene *scene);
void	trace_init(t_trace *tft, t_ray *ray, t_scene *scene, t_wh *im);
void	reflection_trace(t_trace *tft, t_ray *ray, t_scene *scene, t_wh *im);
void	reflection_trace2(t_trace *tft, t_ray *ray, t_scene *scene, t_wh *im);
void	chk_inshadow(t_eca *eca1, t_vector *hit_pos, t_scene *scene);
void	diffuse_tracer(t_eca *eca1, t_obj *obj_hit, t_vector *hit_normal);
void	phong_tracer(t_eca *eca1, t_obj *obj_hit, t_vector *hit_normal);
#endif
