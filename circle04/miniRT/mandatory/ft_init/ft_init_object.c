/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:33:35 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 04:33:36 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scene.h"
#include "../ft_atod/ft_atod.h"
#include "../../libft/libft.h"
#include "../sphere.h"
#include "ft_init.h"

t_vector	*ft_c_v(char *str);
int			ft_in_range(t_vector *v, double a, double b);

int	ft_init_obj_help2(char **arr, t_scene *scene, int type, int *i)
{
	*i = 0;
	(void)type;
	(void)arr;
	scene->objects[scene->ob_n - 1]->material
		= ft_calloc(sizeof(t_material), 1);
	if (scene->objects[scene->ob_n - 1]->material == 0)
		return (1);
	return (0);
}

int	ft_init_obj_if1(char **arr, t_scene *scene, int type)
{
	if (type == 1)
	{
		scene->objects[scene->ob_n - 1]->s = ft_calloc(sizeof(t_obj), 1);
		if (scene->objects[scene->ob_n - 1]->s == 0)
			return (1);
	}
	else if (type == 2)
	{
		scene->objects[scene->ob_n - 1]->p = ft_calloc(sizeof(t_plane), 1);
		if (scene->objects[scene->ob_n - 1]->p == 0)
			return (1);
	}
	return (0);
}

int	ft_init_obj_if2(char **arr, t_scene *scene, int type)
{
	if (type == 3)
	{
		scene->objects[scene->ob_n - 1]->c = ft_calloc(sizeof(t_cylinder), 1);
		if (scene->objects[scene->ob_n - 1]->c == 0)
			return (1);
	}
	else if (type == 4)
	{
		scene->objects[scene->ob_n - 1]->cone = ft_calloc(sizeof(t_cone), 1);
		if (scene->objects[scene->ob_n - 1]->cone == 0)
			return (1);
	}
	return (0);
}

int	ft_init_obj_help(char **arr, t_scene *scene, int type)
{
	int	index;

	(void)arr;
	if (ft_init_obj_help2(arr, scene, type, &index))
		return (1);
	if (ft_init_obj_if1(arr, scene, type))
		return (1);
	if (ft_init_obj_if2(arr, scene, type))
		return (1);
	return (0);
}

int	ft_init_obj(char **arr, t_scene *scene, int type)
{
	t_obj	**tmp;
	int		i;

	i = 0;
	tmp = scene->objects;
	scene->objects = (t_obj **)malloc(sizeof(t_obj *)
			* ((scene->ob_n) + 20));
	if (scene->objects == 0)
		return (1);
	while (i < scene->ob_n)
	{
		scene->objects[i] = tmp[i];
		++i;
	}
	if (i >= 1)
		free(tmp);
	scene->objects[scene->ob_n] = ft_calloc(sizeof(t_obj), 1);
	if (scene->objects[scene->ob_n] == 0)
		return (1);
	scene->objects[scene->ob_n]->type = type;
	scene->ob_n += 1;
	return (ft_init_obj_help(arr, scene, type));
}
