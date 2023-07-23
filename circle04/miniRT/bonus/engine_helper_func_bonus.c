/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_helper_func_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:45:04 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/25 12:11:23 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_helper.h"
#include "sphere.h"

void	reflection_trace2(t_trace *tft, t_ray *ray, t_scene *scene, t_wh *im)
{
	(void)scene;
	(void)im;
	tft->hit_normal_tmp = v_scal_mul(tft->hit_normal, MIN_DISPLACE);
	tft->new_ray_pos = v_add(&tft->hit_pos, tft->hit_normal_tmp);
	tft->new_ray_dir_tmp = 2 * v_dp(&ray->direction, tft->hit_normal);
	tft->new_ray_dir_tmp2 = v_scal_mul(tft->hit_normal, tft->new_ray_dir_tmp);
	tft->new_ray_dir = v_sub(&ray->direction, tft->new_ray_dir_tmp2);
	v_nor(tft->new_ray_dir);
	tft->new_ray.origin = *tft->new_ray_pos;
	tft->new_ray.direction = *tft->new_ray_dir;
}

void	reflection_trace(t_trace *tft, t_ray *ray, t_scene *scene, t_wh *im)
{
	static int	depth = 0;

	if (depth < MAX_DEPTH)
	{
		reflection_trace2(tft, ray, scene, im);
		if (tft->obj_hit->type > 0)
		{
			depth++;
			tft->final_color = v_smc(
					ray_trace(&tft->new_ray, scene, im),
					tft->obj_hit->material->m_r);
		}
		tft->ret_color2 = tft->ret_color;
		tft->ret_color = v_add(tft->ret_color, tft->final_color);
	}
	depth = 0;
}

void	chk_inshadow(t_eca *eca1, t_vector *hit_pos,
		t_vector *hit_normal, t_scene *scene)
{
	eca1->inshadow = 0;
	eca1->light = scene->lights[eca1->i];
	eca1->kk = v_sub_stack(*eca1->light->position, *hit_pos);
	v_nor(&eca1->kk);
	eca1->kk = v_scal_mul_stack(eca1->kk, 0.001);
	// eca1->to_light.origin = v_add_stack(*hit_pos, eca1->kk);
	eca1->to_light.origin = v_add_stack(*hit_pos,
			v_scal_mul_stack(*hit_normal, 0.001));
	eca1->kk = v_sub_stack(*eca1->light->position, eca1->to_light.origin);
	eca1->dl = v_l(&eca1->kk);
	eca1->to_light.direction = v_sub_stack(*eca1->light->position, *hit_pos);
	v_nor(&eca1->to_light.direction);
	eca1->k = -1;
	while (++eca1->k < scene->ob_n)
	{
		eca1->dist = intersects((scene->objects[eca1->k]), &eca1->to_light);
		if ((eca1->dist != 0) && (eca1->dist < eca1->dl))
			eca1->inshadow = 0.9;
	}
}

void	diffuse_tracer(t_eca *eca1, t_obj *obj_hit, t_vector *hit_normal)
{
	eca1->tmp_col = vector_multiple_stack(*eca1->obj_color,
			*eca1->light->color);
	eca1->tmp_col = v_scal_mul_stack(eca1->tmp_col, obj_hit->material->m_d);
	eca1->tmp_scalar = fmax(v_dp(hit_normal, &eca1->to_light.direction), 0);
	eca1->tmp_col = v_scal_mul_stack(eca1->tmp_col, eca1->tmp_scalar);
	eca1->tmp_col = v_scal_mul_stack(eca1->tmp_col, 1 - (eca1->inshadow));
	eca1->color = v_add_stack(eca1->color, eca1->tmp_col);
}

void	phong_tracer(t_eca *eca1, t_obj *obj_hit, t_vector *hit_normal)
{
	eca1->half_vector = v_add_stack(eca1->to_light.direction, eca1->to_cam);
	v_nor(&eca1->half_vector);
	eca1->tmp_scalar = fmax(v_dp(hit_normal, &eca1->half_vector), 0);
	eca1->tmp_scalar = pow(eca1->tmp_scalar, eca1->specular_k);
	eca1->tmp_col = v_scal_mul_stack(*eca1->light->color,
			obj_hit->material->m_s);
	eca1->tmp_col = v_scal_mul_stack(eca1->tmp_col, eca1->tmp_scalar);
	eca1->color = v_add_stack(eca1->color, eca1->tmp_col);
}
