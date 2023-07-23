/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:27:40 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 20:08:54 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	plane_normal_chker(t_plane *plane1, t_camera *camera2)
{
	t_vector	tmp_plane_vector;
	t_vector	*old_nv;

	tmp_plane_vector = (t_vector){
		plane1->point->x - camera2->position->x, plane1->point->y
		- camera2->position->y,
		plane1->point->z - camera2->position->z};
	old_nv = plane1->nv;
	if (v_dp(&tmp_plane_vector, plane1->nv) > 0)
	{
		plane1->nv = v_scal_mul(plane1->nv, -1);
		free(old_nv);
	}
	v_nor(plane1->nv);
}

void	color_chk(t_scene *scene2)
{
	int			i;
	t_vector	tmp_color;

	i = 0;
	if (ft_in_range(scene2->ambient, 0, 1))
		ft_exit(-1, "Error\nAmbient Color range error\n");
	while (i < scene2->ob_n)
	{
		if (ft_in_range(scene2->objects[i]->material->m_c1, 0, 1)
			|| ft_in_range(scene2->objects[i]->material->m_c2, 0, 1))
			ft_exit(-1, "Error\nMaterial range error\n");
		i++;
	}
	i = 0;
	while (i < scene2->l_n)
	{
		tmp_color = v_scal_mul_stack(*scene2->lights[i]->color,
				1 / scene2->lights[i]->ratio);
		if (ft_in_range(&tmp_color, 0, 1))
			ft_exit(-1, "Error\nLight Color range error\n");
		i++;
	}
}

void	light_chk(t_scene *scene2)
{
	int	i;

	i = 0;
	while (i < scene2->l_n)
	{
		if ((scene2->lights[i]->ratio > 1)
			|| scene2->lights[i]->ratio < 0)
			ft_exit(-1, "Error\nlight ratio error\n");
		i++;
	}
	if ((scene2->ambient_ratio > 1) || (scene2->ambient_ratio < 0))
		ft_exit(-1, "Error\nambient ratio error\n");
}

void	srd_chk(t_scene *scene2)
{
	int	i;

	i = 0;
	while (i < scene2->ob_n)
	{
		if ((scene2->objects[i]->material->m_d > 1)
			|| (scene2->objects[i]->material->m_d < 0)
			|| (scene2->objects[i]->material->m_r > 1)
			|| (scene2->objects[i]->material->m_r < 0)
			|| (scene2->objects[i]->material->m_s > 1)
			|| (scene2->objects[i]->material->m_s < 0))
			ft_exit(-1, "Error\nsrd ratio error\n");
		i++;
	}
}
