/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:27:00 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 04:27:02 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scene.h"
#include "../ft_atod/ft_atod.h"
#include "ft_init.h"

t_vector	*ft_c_v(char *str);
int			ft_in_range(t_vector *v, double a, double b);
int			ft_init_obj(char **arr, t_scene *scene, int type);

int	ft_init_plane_if_1(char **arr, t_scene *scene, int index, t_vector *ttmp)
{
	if (index == 0)
		scene->objects[scene->ob_n - 1]->p->point = ft_c_v(arr[index]);
	else if (index == 1)
	{
		scene->objects[scene->ob_n - 1]->p->nv = ft_c_v(arr[index]);
		v_nor(scene->objects[scene->ob_n - 1]->p->nv);
	}
	else if (index == 2)
	{	
		ttmp = ft_c_v(arr[index]);
		scene->objects[scene->ob_n - 1]->material->m_c1
			= v_scal_mul(ttmp, 1.0 / 255);
		scene->objects[scene->ob_n - 1]->material->m_c2
			= v_scal_mul(ttmp, 1.0 / 255);
		free(ttmp);
	}
	else if (index == 3)
		scene->objects[scene->ob_n - 1]->material->m_d = ft_atod(arr[index]);
	return (0);
}

int	ft_init_plane_if_2(char **arr, t_scene *scene, int index, t_vector *ttmp)
{
	if (index == 4)
		scene->objects[scene->ob_n - 1]->material->m_s = ft_atod(arr[index]);
	else if (index == 5)
		scene->objects[scene->ob_n - 1]->material->m_r = ft_atod(arr[index]);
	scene->objects[scene->ob_n - 1]->mat_type = 1;
	return (0);
}

int	ft_init_plane_help(char **arr, t_scene *scene, int index)
{
	t_vector	*ttmp;

	if (index < 4)
		ft_init_plane_if_1(arr, scene, index, ttmp);
	else if (index < 6)
		ft_init_plane_if_2(arr, scene, index, ttmp);
	else
		return (1);
	return (0);
}

int	ft_init_plane(char **arr, t_scene *scene)
{
	int	index;

	if (ft_init_obj(arr, scene, Plane))
		return (1);
	index = 0;
	while (arr[index] != 0)
	{	
		if (ft_init_plane_help(arr, scene, index))
			return (1);
		++index;
	}
	if (5 > index || index > 6)
		return (1);
	return (0);
}
