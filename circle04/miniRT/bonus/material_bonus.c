/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:27:14 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 15:51:36 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "material_utils.h"
#include "material.h"
#include <math.h>
#define _USE_MATH_DEFINES

t_color	*chqbig(t_obj *obj_hit, t_vector *position,
	t_color **ppm_pixels, t_color *ret)
{
	(void)ppm_pixels;
	(void)ret;
	if (position->x > 0)
	{
		if (position->z > 0)
			return (mat_helper(*obj_hit->material, position, 0, 0));
		else
			return (mat_helper(*obj_hit->material, position, 0, 1));
	}
	else
	{
		if (position->z > 0)
			return (mat_helper(*obj_hit->material, position, 1, 0));
		else
			return (mat_helper(*obj_hit->material, position, 0, 0));
	}
}

t_color	*chqts(t_obj *obj_hit, t_vector *position,
	t_color **ppm_pixels, t_color *ret)
{
	t_texture	tt;

	(void)ppm_pixels;
	(void)ret;
	tt.theta = atan2((position->x - obj_hit->s->center->x),
			(position->z - obj_hit->s->center->z));
	tt.phi = acos((position->y - obj_hit->s->center->y) / obj_hit->s->radius);
	tt.raw_u = tt.theta / (2 * M_PI);
	tt.u = (1 - (tt.raw_u + 0.5));
	tt.v = (1 - (tt.phi / M_PI));
	tt.u2 = floor(tt.u * 24);
	tt.v2 = floor(tt.v * 15);
	if ((tt.u2 + tt.v2) % 2 == 0)
		return (obj_hit->material->m_c1);
	else
		return (obj_hit->material->m_c2);
}

t_color	*imgtext(t_obj *obj_hit, t_vector *position,
	t_color **ppm_pixels, t_color *ret)
{
	t_texture	tt;
	t_color		*ppm_rgb;

	(void)ret;
	tt.theta = atan2((position->x - obj_hit->s->center->x),
			(position->z - obj_hit->s->center->z));
	tt.phi = acos((position->y - obj_hit->s->center->y)
			/ obj_hit->s->radius);
	tt.raw_u = tt.theta / (2 * M_PI);
	tt.u = (1 - (tt.raw_u + 0.5));
	tt.v = (1 - (tt.phi / M_PI));
	if (tt.u > 0.15)
		tt.u -= 0.15;
	else
		tt.u += 0.85;
	if (tt.v > 0.15)
		tt.v -= 0.15;
	else
		tt.v += 0.85;
	tt.u2 = floor(tt.u * 2048);
	tt.v2 = floor(tt.v * 1024);
	ppm_rgb = ppm_pixels[tt.v2 * 2048 + tt.u2];
	return (ppm_rgb);
}

t_color	*imgtextplane(t_obj *obj_hit, t_vector *position,
	t_color **ppm_pixels, t_color *ret)
{
	int		u2;
	int		v2;
	t_color	*ppm_rgb;

	ppm_rgb = NULL;
	(void)obj_hit;
	(void)ret;
	u2 = (int)floor(position->x) % 2048;
	v2 = (int)floor(position->y) % 1024;
	if (u2 < 0)
		u2 = u2 + 2048;
	if (v2 < 0)
		v2 = v2 + 1024;
	ppm_rgb = ppm_pixels[v2 * 2048 + u2];
	return (ppm_rgb);
}

t_color	*material_color_at(t_obj *obj_hit,
	t_vector *position, t_color **ppm_pixels)
{
	t_color	*ret;

	ret = NULL;
	if (obj_hit->mat_type == OneColor)
		return (obj_hit->material->m_c1);
	else if (obj_hit->mat_type == ChqBig)
		return (chqbig(obj_hit, position, ppm_pixels, ret));
	else if (obj_hit->mat_type == ChqTextureSphere)
		return (chqts(obj_hit, position, ppm_pixels, ret));
	else if (obj_hit->mat_type == ImgTexture)
		return (imgtext(obj_hit, position, ppm_pixels, ret));
	else if (obj_hit->mat_type == ImgTexturePlane)
		return (imgtextplane(obj_hit, position, ppm_pixels, ret));
	else
		return (NULL);
}
