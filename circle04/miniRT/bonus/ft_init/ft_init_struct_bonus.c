/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:11:24 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/22 17:46:21 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scene.h"
#include "../../libft/libft.h"
#include "../ft_atod/ft_atod.h"
#include <stdlib.h>
#include "ft_init.h"

t_vector	*ft_c_v(char *str);
int			ft_in_range(t_vector *v, double a, double b);

int	ft_init_light_help(char **arr, t_scene *scene)
{
	t_light	**tmp;
	int		i;

	(void)arr;
	i = 0;
	tmp = scene->lights;
	scene->lights = ft_calloc(sizeof(t_light *), (scene->l_n) + 2);
	if (scene->lights == 0)
		return (1);
	while (i < scene->l_n)
	{
		scene->lights[i] = tmp[i];
		++i;
	}
	if (i >= 1)
		free(tmp);
	scene->lights[scene->l_n] = ft_calloc(sizeof(t_light), 1);
	if (scene->lights[scene->l_n] == 0)
		return (1);
	scene->l_n += 1;
	return (0);
}

int	ft_init_light_help2(char **arr, t_scene *scene)
{
	int	index;

	index = 0;
	if (ft_init_light_help(arr, scene))
		return (1);
	while (arr[index] != 0)
		index++;
	if (index != 3)
		return (1);
	return (0);
}

int	ft_init_light(char **arr, t_scene *scene)
{
	int			index;
	t_vector	*ttmp;

	index = -1;
	ft_init_light_help2(arr, scene);
	while (arr[++index] != 0)
	{
		if (index == 0)
			scene->lights[scene->l_n - 1]->position
				= ft_c_v(arr[index]);
		else if (index == 1)
			scene->lights[scene->l_n - 1]->ratio
				= ft_atod(arr[index]);
		else if (index == 2)
		{
			ttmp = ft_c_v(arr[index]);
			scene->lights[scene->l_n - 1]->color
				= v_scal_mul(ttmp, 1.0 / 255
					* scene->lights[scene->l_n - 1]->ratio);
			free(ttmp);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_init_camera(char **arr, t_scene *scene)
{
	int	index;

	if (scene->acl->ccount == 0)
		scene->acl->ccount = 1;
	else
		ft_exit(-1, "Error\nMore than one camera\n");
	index = 0;
	while (arr[index] != 0)
	{
		if (index == 0)
			scene->camera->position = ft_c_v(arr[index]);
		else if (index == 1)
			scene->camera->normal_vector = ft_c_v(arr[index]);
		else if (index == 2)
			scene->camera->fov = ft_atod(arr[index]);
		else
			return (1);
		++index;
	}
	scene->camera->axis = v_n(0, -1, 0);
	camera_chker(scene->camera);
	if (index != 3)
		return (1);
	return (0);
}

int	ft_init_ambient(char **arr, t_scene *scene)
{
	int			index;
	t_vector	*ttmp;

	if (scene->acl->acount == 0)
		scene->acl->acount = 1;
	else
		ft_exit(-1, "Error\nMore than one ambient\n");
	index = 0;
	while (arr[index] != 0)
	{
		if (index == 0)
			scene->ambient_ratio = ft_atod(arr[index]);
		else if (index == 1)
		{
			ttmp = ft_c_v(arr[index]);
			scene->ambient = v_scal_mul(ttmp, 1.0 / 255);
			free(ttmp);
		}
		else
			return (1);
		++index;
	}
	if (index != 2)
		return (1);
	return (0);
}
