/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:27:29 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/22 19:05:34 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"
#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "scene.h"
#include "engine.h"
#include "engine_helper.h"
#include "free_helper.h"

t_find_ret	*find_nearest(t_ray *ray, t_scene *scene, t_wh *im)
{
	t_fn	fn1;

	init_fn(&fn1, im);
	fn1.tmp_addr = (t_find_ret *)malloc(sizeof(t_find_ret));
	if (!fn1.tmp_addr)
		return (NULL);
	while (fn1.i < fn1.objects_num)
	{
		fn1.dist = intersects((scene->objects[fn1.i]), ray);
		fn1.obj = (scene->objects[fn1.i]);
		if ((fn1.dist != 0) && ((fn1.obj_hit == NULL)
				|| fn1.dist < fn1.dist_min))
		{
			fn1.dist_min = fn1.dist;
			fn1.obj_hit = fn1.obj;
		}
		fn1.i++;
	}
	fn1.tmp_addr->dist_min = fn1.dist_min;
	fn1.tmp_addr->obj = fn1.obj_hit;
	return (fn1.tmp_addr);
}

t_color	*engine_color_at(t_obj *obj_hit,
	t_vector *hit_pos, t_vector *hit_normal, t_scene *scene)
{
	t_eca	eca1;

	init_eca(&eca1, obj_hit, hit_pos, scene);
	while (eca1.i < scene->l_n)
	{
		chk_inshadow(&eca1, hit_pos, hit_normal, scene);
		diffuse_tracer(&eca1, obj_hit, hit_normal);
		phong_tracer(&eca1, obj_hit, hit_normal);
		eca1.i++;
	}
	eca1.ret_color = v_n(eca1.color.x, eca1.color.y, eca1.color.z);
	return (eca1.ret_color);
}

t_color	*ray_trace(t_ray *ray, t_scene *scene, t_wh *im)
{
	t_trace	tft;

	trace_init(&tft, ray, scene, im);
	if (tft.obj_hit == NULL)
	{	
		free(tft.tmp);
		tft.ret_color = v_n(tft.color.x, tft.color.y, tft.color.z);
		return (tft.ret_color);
	}
	tft.scalar_tmp = v_scal_mul_stack(ray->direction, tft.dist_hit);
	tft.hit_pos = v_add_stack(ray->origin, tft.scalar_tmp);
	if (tft.obj_hit->type == Sphere)
		tft.hit_normal = normal(tft.obj_hit->s, &tft.hit_pos);
	else if (tft.obj_hit->type == Plane)
		tft.hit_normal = normal_plane(tft.obj_hit->p, &tft.hit_pos);
	else if (tft.obj_hit->type == Cylinder)
		tft.hit_normal = normal_cylinder(tft.obj_hit->c, &tft.hit_pos, ray);
	else if (tft.obj_hit->type == Cone)
		tft.hit_normal = normal_cone(tft.obj_hit->cone, &tft.hit_pos, ray);
	tft.tmp_color = engine_color_at(tft.obj_hit,
			&tft.hit_pos, tft.hit_normal, scene);
	tft.ret_color = v_add(&tft.color, tft.tmp_color);
	reflection_trace(&tft, ray, scene, im);
	free_trace(tft);
	return (tft.ret_color);
}

void	render(t_scene *scene, t_wh *im)
{
	t_render	t1;
	t_vector	tmp_vector;

	render_camera_init(&t1, scene);
	render_init(&t1);
	while (++(t1.j) < t1.height)
	{
		tmp_vector = v_scal_mul_stack(t1.ystep, t1.j);
		t1.y = v_add_stack(t1.y0, tmp_vector);
		while (++(t1.i) < t1.width)
		{
			tmp_vector = v_scal_mul_stack(t1.xstep, t1.i);
			t1.x = v_add_stack(t1.x0, tmp_vector);
			t1.point = v_add_stack(t1.x, t1.y);
			t1.ray.origin = *t1.camera->position;
			t1.ray.direction = v_add_stack(t1.point, *t1.camera->normal_vector);
			v_nor(&t1.ray.direction);
			t1.color = ray_trace(&t1.ray, scene, im);
			set_pixel(im, t1.i, t1.j, t1.color);
		}
		t1.i = -1;
	}
	free(t1.viewport_y);
	free(t1.viewport_x);
}
