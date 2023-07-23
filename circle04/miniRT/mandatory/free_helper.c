/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:19:55 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/19 17:22:29 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_helper.h"
#include "engine_helper.h"

void	freemain(t_scene scene, t_wh im)
{
	t_free1	f1;
	int		i;

	f1.objects_num = im.ob_n;
	f1.lights_num = scene.l_n;
	f1.objects = scene.objects;
	f1.lights = scene.lights;
	i = -1;
	freemain2(im, f1);
	while (++i < f1.lights_num)
	{
		free(f1.lights[i]->color);
		free(f1.lights[i]->position);
	}
}

void	freemain2(t_wh im, t_free1 f1)
{
	int	i;

	i = -1;
	while (++i < f1.objects_num)
	{
		if (f1.objects[i]->type == Sphere)
		{
			free(f1.objects[i]->s->center);
			free(f1.objects[i]->material->m_c1);
			free(f1.objects[i]->material->m_c2);
		}
		else if (f1.objects[i]->type == 1)
		{
			free(f1.objects[i]->p->nv);
			free(f1.objects[i]->p->point);
			free(f1.objects[i]->material->m_c1);
			free(f1.objects[i]->material->m_c2);
		}
	}
	i = -1;
	while (++i < im.width * im.height)
		free(im.pixels[i]);
	free(im.pixels);
}

void	free_intersects_p(t_vector *po_tmp, t_vector *po_tmp2, t_vector *tmp)
{
	free(po_tmp);
	free(po_tmp2);
	free(tmp);
}

void	free_trace(t_trace tft)
{
	if (tft.obj_hit->type == Sphere)
		free(tft.hit_normal);
	if (tft.obj_hit->type == Cylinder)
		free(tft.hit_normal);
	if (tft.obj_hit->type == Cone)
		free(tft.hit_normal);
	free(tft.tmp);
	free(tft.tmp_color);
	free(tft.hit_normal_tmp);
	free(tft.new_ray_pos);
	free(tft.new_ray_dir_tmp2);
	free(tft.new_ray_dir);
	free(tft.final_color);
	free(tft.ret_color2);
}
