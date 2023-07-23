/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 05:19:52 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 05:23:57 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS

void	texture_while1(t_text *t1)
{
	t1->p = strtok(t1->tmp_pixels[t1->ppm_j], " ");
	t1->r_ppm = atoi(t1->p);
}

void	texture_while2(t_text *t1)
{
	if (t1->ppm_i % 3 == 0)
	{
		t1->p = strtok(NULL, " ");
		t1->r_ppm = atoi(t1->p);
	}
	else if (t1->ppm_i % 3 == 1)
	{
		t1->p = strtok(NULL, " ");
		t1->g_ppm = atoi(t1->p);
	}
	else if (t1->ppm_i % 3 == 2)
	{
		t1->p = strtok(NULL, " ");
		t1->b_ppm = atoi(t1->p);
	}
}

void	texture_while3(t_text *t1)
{
	t1->tmp_color_ppm = v_n(t1->r_ppm / 255.0,
			t1->g_ppm / 255.0, t1->b_ppm / 255.0);
	t1->ppm_pixels[t1->ppm_j * 2048 + (int)(t1->ppm_i / 3)] = t1->tmp_color_ppm;
}

t_color	**texture(void)
{
	t_text	t1;

	if (!texture_init(&t1) || !texture_tokens(&t1))
		return (NULL);
	while (t1.ppm_j < 1024)
	{
		while (t1.ppm_i < 3 * 2048)
		{
			if (t1.ppm_i == 0)
				texture_while1(&t1);
			else
				texture_while2(&t1);
			if (t1.ppm_i % 3 == 2)
				texture_while3(&t1);
			++t1.ppm_i;
		}
		t1.ppm_i = 0;
		++t1.ppm_j;
	}
	texture_free(&t1);
	return (t1.ppm_pixels);
}
