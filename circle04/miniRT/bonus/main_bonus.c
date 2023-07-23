/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 05:35:52 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/25 21:03:30 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "image.h"
#include "color.h"
#include "sphere.h"
#include "ray.h"
#include "scene.h"
#include "engine.h"
#include "light.h"
#include "material.h"
#include "camera.h"
#include "texture.h"
#include "check.h"
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "ft_atod/ft_atod.h"
#include "ft_exit/ft_exit.h"
#include "ft_init/ft_init.h"
#include "gnl/get_next_line.h"
#include "test/test.h"
#include <fcntl.h>
#include <sys/fcntl.h>
#include "libft/libft.h"

void	check_leak(void)
{
	system("leaks --list -- miniRT");
}

void	main_init(t_scene *scene2, t_wh *im2, t_color **ppm_pixels2)
{
	int	chki;

	chki = -1;
	init_pixels(im2);
	ppm_pixels2 = texture();
	if ((ppm_pixels2 == NULL))
		ft_exit(-1, "return NULL!\n");
	scene2->ppm_pixels = ppm_pixels2;
	init_main(scene2, im2);
	while (++chki < scene2->ob_n)
	{
		if (scene2->objects[chki]->type == Plane)
		{
			plane_normal_chker(scene2->objects[chki]->p,
				scene2->camera);
		}
	}
	color_chk(scene2);
	srd_light_chk(scene2);
	mat_type_chk(scene2);
}

void	main_free_helper2(t_scene *scene2, int i)
{
	if (scene2->objects[i]->type == Cylinder)
	{
		free(scene2->objects[i]->material->m_c1);
		free(scene2->objects[i]->material->m_c2);
		free(scene2->objects[i]->material);
		free(scene2->objects[i]->c->bottom);
		free(scene2->objects[i]->c->direction);
		free(scene2->objects[i]->c->top);
		free(scene2->objects[i]->c);
	}
	else if (scene2->objects[i]->type == Cone)
	{
		free(scene2->objects[i]->material->m_c1);
		free(scene2->objects[i]->material->m_c2);
		free(scene2->objects[i]->material);
		free(scene2->objects[i]->cone->center);
		free(scene2->objects[i]->cone->direction);
		free(scene2->objects[i]->cone->tip);
		free(scene2->objects[i]->cone);
	}	
}

void	main_free_helper1(t_scene *scene2, int i)
{
	if (scene2->objects[i]->type == Plane)
	{
		free(scene2->objects[i]->material->m_c1);
		free(scene2->objects[i]->material->m_c2);
		free(scene2->objects[i]->material);
		free(scene2->objects[i]->p->nv);
		free(scene2->objects[i]->p->point);
		free(scene2->objects[i]->p);
	}
	else if (scene2->objects[i]->type == Sphere)
	{
		free(scene2->objects[i]->material->m_c1);
		free(scene2->objects[i]->material->m_c2);
		free(scene2->objects[i]->material);
		free(scene2->objects[i]->s->center);
		free(scene2->objects[i]->s);
	}
}

void	main_free_helper3(t_scene *scene2, t_wh *im2,
	t_color **ppm_pixels2, int i)
{
	i = 0;
	free(scene2->camera->position);
	free(scene2->camera->axis);
	free(scene2->camera->normal_vector);
	free(scene2->camera);
	free(scene2->ambient);
	free(scene2->objects);
	free(scene2->lights);
	while (i < im2->width * im2->height)
	{
		free(im2->pixels[i]);
		i++;
	}
	free(im2->pixels);
	i = 0;
	while (i < 1024 * 2048)
	{
		free(ppm_pixels2[i]);
		i++;
	}
	free(ppm_pixels2);
	free(scene2->acl);
	free(scene2);
	free(im2);
}

void	main_free(t_scene *scene2, t_wh *im2, t_color **ppm_pixels2)
{
	int	i;

	i = 0;
	while (i < scene2->ob_n)
	{
		if ((scene2->objects[i]->type == Plane)
			|| (scene2->objects[i]->type == Sphere))
			main_free_helper1(scene2, i);
		else if ((scene2->objects[i]->type == Cylinder)
			|| (scene2->objects[i]->type == Cone))
			main_free_helper2(scene2, i);
		free(scene2->objects[i]);
		i++;
	}
	i = 0;
	while (i < scene2->l_n)
	{
		free(scene2->lights[i]->color);
		free(scene2->lights[i]->position);
		free(scene2->lights[i]);
		i++;
	}
	main_free_helper3(scene2, im2, ppm_pixels2, i);
}

int main(void)
{
	t_scene		*scene2;
	t_wh		*im2;
	t_color		**ppm_pixels2;
	double		start2;
	double		end2;

	start2 = (double)clock() / CLOCKS_PER_SEC;
	scene2 = (t_scene *)malloc(sizeof(t_scene));
	im2 = (t_wh *)malloc(sizeof(t_wh));
	im2->width = 320 * 4;
	im2->height = 200 * 4;
	scene2->width = im2->width;
	scene2->height = im2->height;
	scene2->ob_n = 0;
	scene2->l_n = 0;
	start2 = 0;
	end2 = 0;
	main_init(scene2, im2, ppm_pixels2);
	print_scene(scene2);
	scene2->camera->position->y -= 1;
	render(scene2, im2);
	// main_init(scene2, im2, ppm_pixels2);
	//render(scene2, im2);
	draw_image(im2);
	open_mlx(im2);
	end2 = (((double)clock()) / CLOCKS_PER_SEC);
	printf("it takes time :%lf\n", (end2 - start2));
	main_free(scene2, im2, ppm_pixels2);
	atexit(check_leak);
	return (0);
}
