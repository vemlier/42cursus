/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:50:39 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 05:17:35 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stdio.h>
# include <stdlib.h>
# include "vector.h"
# include "image.h"
# include "color.h"

typedef struct s_text
{
	FILE	*pfile2;
	char	first[3];
	int		ppm_width;
	int		ppm_height;
	int		ppm_rgb_num;
	int		ppm_i;
	int		ppm_j;
	int		r_ppm;
	int		g_ppm;
	int		b_ppm;
	char	**tmp_pixels;
	t_color	*tmp_color_ppm;
	char	*pline;
	char	*p;
	t_color	**ppm_pixels;
}			t_text;

int		texture_init(t_text *t1);
int		texture_tokens(t_text *t1);
void	texture_while1(t_text *t1);
void	texture_while2(t_text *t1);
void	texture_while3(t_text *t1);
void	texture_free(t_text *t1);
t_color	**texture(void);

#endif
