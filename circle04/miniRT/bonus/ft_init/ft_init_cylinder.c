/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:37:19 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 04:37:22 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scene.h"
#include "../ft_atod/ft_atod.h"
#include "ft_init.h"
//#include "ft_init_object.c"

t_vector	*ft_c_v(char *str);
int			ft_in_range(t_vector *v, double a, double b);
int			ft_init_obj(char **arr, t_scene *scene, int type);

void	ft_init_cylinder_help2(char **arr, t_scene *scene, int index)
{
	t_vector	*cy_tmp;

	scene->objects[scene->ob_n - 1]->c->height = ft_atod(arr[index]);
	cy_tmp = v_scal_mul(scene->objects[scene->ob_n - 1]->c->direction,
			scene->objects[scene->ob_n - 1]->c->height);
	scene->objects[scene->ob_n - 1]->c->top
		= v_add(scene->objects[scene->ob_n - 1]->c->bottom, cy_tmp);
	free(cy_tmp);
}

int	ft_init_cylinder_if_1(char **arr, t_scene *scene, int index, t_vector *ttmp)
{
	if (index == 0)
		scene->objects[scene->ob_n - 1]->c->bottom = ft_c_v(arr[index]);
	else if (index == 1)
	{
		scene->objects[scene->ob_n - 1]->c->direction = ft_c_v(arr[index]);
		v_nor(scene->objects[scene->ob_n - 1]->c->direction);
	}
	else if (index == 2)
		scene->objects[scene->ob_n - 1]->c->diameter = ft_atod(arr[index]);
	else if (index == 3)
		ft_init_cylinder_help2(arr, scene, index);
	else if (index == 4)
	{
		ttmp = ft_c_v(arr[index]);
		scene->objects[scene->ob_n - 1]->material->m_c1
			= v_scal_mul(ttmp, 1.0 / 255);
		free(ttmp);
	}
	return (0);
}

int	ft_init_cylinder_if_2(char **arr, t_scene *scene, int index, t_vector *ttmp)
{
	if (index == 5)
		scene->objects[scene->ob_n - 1]->material->m_d = ft_atod(arr[index]);
	else if (index == 6)
		scene->objects[scene->ob_n - 1]->material->m_s = ft_atod(arr[index]);
	else if (index == 7)
		scene->objects[scene->ob_n - 1]->material->m_r = ft_atod(arr[index]);
	else if (index == 8)
	{
		ttmp = ft_c_v(arr[index]);
		scene->objects[scene->ob_n - 1]->material->m_c2
			= v_scal_mul(ttmp, 1.0 / 255);
		free(ttmp);
	}
	else if (index == 9)
		scene->objects[scene->ob_n - 1]->mat_type = ft_atod(arr[index]);
	return (0);
}

int	ft_init_cylinder_help(char **arr, t_scene *scene, int index)
{
	t_vector	*ttmp;

	scene->objects[scene->ob_n - 1]->c->circle = false;
	if (index < 5)
	{
		ft_init_cylinder_if_1(arr, scene, index, ttmp);
	}
	else if (index < 10)
	{
		ft_init_cylinder_if_2(arr, scene, index, ttmp);
	}
	else
		return (1);
	return (0);
}

int	ft_init_cylinder(char **arr, t_scene *scene)
{
	int	index;

	if (ft_init_obj(arr, scene, Cylinder))
		return (1);
	index = 0;
	while (arr[index] != 0)
	{
		if (ft_init_cylinder_help(arr, scene, index))
			return (1);
		++index;
	}
	if (9 > index || index > 10)
		return (1);
	return (0);
}
