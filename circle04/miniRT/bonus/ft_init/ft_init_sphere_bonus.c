/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:26:50 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 04:26:51 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scene.h"
#include "../ft_atod/ft_atod.h"
#include "ft_init.h"

t_vector	*ft_c_v(char *str);
int			ft_in_range(t_vector *v, double a, double b);
int			ft_init_obj(char **arr, t_scene *scene, int type);

int	ft_init_sphere_if_1(char **arr, t_scene *scene, int index, t_vector *ttmp)
{
	if (index == 0)
		scene->objects[scene->ob_n - 1]->s->center = ft_c_v(arr[index]);
	else if (index == 1)
		scene->objects[scene->ob_n - 1]->s->radius = ft_atod(arr[index]);
	else if (index == 2)
	{
		ttmp = ft_c_v(arr[index]);
		scene->objects[scene->ob_n - 1]->material->m_c1
			= v_scal_mul(ttmp, 1.0 / 255);
		free(ttmp);
	}
	else if (index == 3)
		scene->objects[scene->ob_n - 1]->material->m_d = ft_atod(arr[index]);
	return (0);
}

int	ft_init_sphere_if_2(char **arr, t_scene *scene, int index, t_vector *ttmp)
{
	if (index == 4)
		scene->objects[scene->ob_n - 1]->material->m_s = ft_atod(arr[index]);
	else if (index == 5)
		scene->objects[scene->ob_n - 1]->material->m_r = ft_atod(arr[index]);
	else if (index == 6)
	{
		ttmp = ft_c_v(arr[index]);
		scene->objects[scene->ob_n - 1]->material->m_c2
			= v_scal_mul(ttmp, 1.0 / 255);
		free(ttmp);
	}
	else if (index == 7)
		scene->objects[scene->ob_n - 1]->mat_type
			= ft_atod(arr[index]);
	return (0);
}

int	ft_init_sphere_help(char **arr, t_scene *scene, int index)
{
	t_vector	*ttmp;

	if (index < 4)
	{
		ft_init_sphere_if_1(arr, scene, index, ttmp);
	}
	else if (index < 8)
	{
		ft_init_sphere_if_2(arr, scene, index, ttmp);
	}
	else
		return (1);
	return (0);
}

int	ft_init_sphere(char **arr, t_scene *scene)
{
	int	index;

	if (ft_init_obj(arr, scene, 1))
		return (1);
	index = 0;
	while (arr[index] != 0)
	{
		if (ft_init_sphere_help(arr, scene, index))
			return (1);
		++index;
	}
	if (7 > index || index > 8)
		return (1);
	return (0);
}
