/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_helper_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:44:35 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:44:55 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_helper.h"

void	init_eca(t_eca *eca1, t_obj *obj_hit,
	t_vector *hit_pos, t_scene *scene)
{
	eca1->obj_color = material_color_at(obj_hit, hit_pos, scene->ppm_pixels);
	eca1->to_cam = v_sub_stack(*scene->camera->position, *hit_pos);
	eca1->ffffff = (t_vector){1, 1, 1};
	eca1->light = NULL;
	eca1->tmp_scalar = 0;
	eca1->specular_k = 50;
	eca1->ambient = scene->ambient_ratio;
	eca1->i = 0;
	eca1->color = v_scal_mul_stack(*scene->ambient, eca1->ambient);
	eca1->dl = 0;
	eca1->k = -1;
}

void	init_fn(t_fn *fn1, t_wh *im)
{
	fn1->dist = 0;
	fn1->dist_min = 0;
	fn1->objects_num = im->ob_n;
	fn1->i = 0;
	fn1->obj = NULL;
	fn1->obj_hit = NULL;
	fn1->tmp_addr = NULL;
}

void	render_init(t_render *t1)
{
	double		tmp_scalar;
	t_vector	tmp_vector;

	tmp_scalar = v_dp(t1->camera->axis, t1->camera->normal_vector);
	tmp_vector = v_scal_mul_stack(*t1->camera->normal_vector, tmp_scalar);
	t1->viewport_y = v_sub(t1->camera->axis, &tmp_vector);
	t1->viewport_x = v_cp(t1->camera->normal_vector, t1->viewport_y);
	v_nor(t1->viewport_x);
	tmp_vector = v_scal_mul_stack(*t1->viewport_x, (t1->nv_vx_tan));
	t1->x0 = v_sub_stack(*t1->camera->normal_vector, tmp_vector);
	t1->x1 = v_add_stack(*t1->camera->normal_vector, tmp_vector);
	tmp_vector = v_sub_stack(t1->x1, t1->x0);
	t1->xstep = v_scal_mul_stack(tmp_vector, (1 / (double)t1->width));
	t1->y0 = v_scal_mul_stack(*t1->viewport_y, (1 / t1->aspect_ratio));
	t1->y1 = v_scal_mul_stack(*t1->viewport_y, (-1 / t1->aspect_ratio));
	tmp_vector = v_sub_stack(t1->y1, t1->y0);
	t1->ystep = v_scal_mul_stack(tmp_vector, (1 / (double)t1->height));
	t1->color = NULL;
	t1->i = -1;
	t1->j = -1;
}

void	render_camera_init(t_render *t1, t_scene *scene)
{
	t1->camera = scene->camera;
	t1->width = scene->width;
	t1->height = scene->height;
	t1->aspect_ratio = (double)t1->width / t1->height;
	t1->camera->fov = t1->camera->fov * 3.1415926 / 180 / 2;
	t1->nv_vx_tan = tan(t1->camera->fov);
	v_nor(t1->camera->axis);
	v_nor(t1->camera->normal_vector);
}

void	trace_init(t_trace *tft, t_ray *ray, t_scene *scene, t_wh *im)
{
	tft->color = (t_vector){0, 0, 0};
	tft->tmp = find_nearest(ray, scene, im);
	tft->obj_hit = tft->tmp->obj;
	tft->hit_normal = NULL;
	tft->hit_normal_tmp = NULL;
	tft->tmp_color = NULL;
	tft->ret_color = NULL;
	tft->ret_color2 = NULL;
	tft->final_color = NULL;
	tft->new_ray_pos = NULL;
	tft->new_ray_dir = NULL;
	tft->new_ray_dir_tmp = 0;
	tft->new_ray_dir_tmp2 = NULL;
	tft->dist_hit = tft->tmp->dist_min;
}
