/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 05:10:54 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 05:12:57 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS

int	texture_init(t_text *t1)
{
	t1->pfile2 = NULL;
	t1->ppm_i = 0;
	t1->ppm_j = 0;
	t1->tmp_pixels = NULL;
	t1->tmp_pixels = (char **)malloc(sizeof(char *) * 1024);
	if (!t1->tmp_pixels)
		return (0);
	t1->tmp_color_ppm = NULL;
	t1->pline = NULL;
	t1->ppm_pixels = (t_color **)malloc(sizeof(t_color *) * 2048 * 1024);
	if (!t1->ppm_pixels)
		return (0);
	t1->pfile2 = fopen("earth.ppm", "rt");
	if (t1->pfile2 == NULL)
		return (0);
	else
	{
		fscanf(t1->pfile2, "%s\n", t1->first);
		fscanf(t1->pfile2, "%d %d\n", &t1->ppm_width, &t1->ppm_height);
		fscanf(t1->pfile2, "%d\n", &t1->ppm_rgb_num);
	}
	return (1);
}

int	texture_tokens(t_text *t1)
{
	while (t1->ppm_j < 1024)
	{
		t1->pline = (char *)malloc(sizeof(char) * 2048 * 20);
		if (t1->pline == NULL)
			return (0);
		else
		{
			fgets(t1->pline, 2048 * 20, t1->pfile2);
			t1->tmp_pixels[t1->ppm_j] = t1->pline;
			t1->ppm_j++;
		}
	}
	t1->ppm_j = 0;
	return (1);
}

void	texture_free(t_text *t1)
{
	int	jj;

	jj = 0;
	while (jj < 1024)
	{
		free(t1->tmp_pixels[jj]);
		jj++;
	}
	free(t1->tmp_pixels);
}
