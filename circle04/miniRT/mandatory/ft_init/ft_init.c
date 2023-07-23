/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:36:55 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 19:39:05 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../scene.h"
#include "../gnl/get_next_line.h"
#include "../../libft/libft.h"
#include "../ft_exit/ft_exit.h"
#include "ft_init.h"
#define AMBIENT "A"
#define CAMERA "C"
#define LIGHT "L"
#define LIGHT2 "l"
#define SPHERE "sp"
#define PLANE "pl"
#define CYLINDER "cy"
#define CONE "co"

int	ft_init_light(char **arr, t_scene *scene);
int	ft_init_camera(char **arr, t_scene *scene);
int	ft_init_ambient(char **arr, t_scene *scene);
int	ft_init_sphere(char **arr, t_scene *scene);
int	ft_init_plane(char **arr, t_scene *scene);
int	ft_init_cylinder(char **arr, t_scene *scene);
int	ft_init_cone(char **arr, t_scene *scene);

int	ft_init_classify2(char **arr, t_scene *scene)
{
	if (ft_strncmp(arr[0], SPHERE, ft_strlen(arr[0])) == 0)
		return (ft_init_sphere(&arr[1], scene));
	else if (ft_strncmp(arr[0], PLANE, ft_strlen(arr[0])) == 0)
		return (ft_init_plane(&arr[1], scene));
	else if (ft_strncmp(arr[0], CYLINDER, ft_strlen(arr[0])) == 0)
		return (ft_init_cylinder(&arr[1], scene));
	return (1);
}

int	ft_init_classify(char **arr, t_scene *scene)
{
	static int	count[3] = {0, 0, 0};

	if (count[0] == 0 && ft_strncmp(arr[0], AMBIENT, ft_strlen(arr[0])) == 0)
	{
		++count[0];
		return (ft_init_ambient(&arr[1], scene));
	}
	else if (count[1] == 0 && ft_strncmp(arr[0], CAMERA,
			ft_strlen(arr[0])) == 0)
	{
		++count[1];
		scene->camera = ft_calloc(sizeof(t_camera), 1);
		if (scene->camera == 0)
			return (1);
		return (ft_init_camera(&arr[1], scene));
	}
	else if (ft_strncmp(arr[0], LIGHT, ft_strlen(arr[0])) == 0)
	{
		return (ft_init_light(&arr[1], scene));
	}
	return (ft_init_classify2(arr, scene));
}

int	ft_init(char *str, t_scene *scene)
{
	char	**arr;
	int		index;

	index = 0;
	arr = ft_split(str, ' ');
	if (!arr)
		return (1);
	if (arr[0] != 0)
	{
		if (ft_init_classify(arr, scene))
			ft_exit(1, "Error\nWrong Format\n");
	}
	else
		return (1);
	while (arr[index] != 0)
	{
		free(arr[index]);
		++index;
	}
	free(arr);
	return (0);
}
