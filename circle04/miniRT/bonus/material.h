/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:03:48 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:06:04 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "vector.h"
# include "image.h"
# include "color.h"
# include "ray.h"
# include "sphere.h"

typedef struct s_texture
{
	double	theta;
	double	phi;
	double	raw_u;
	double	u;
	double	v;
	int		u2;
	int		v2;
}			t_texture;

t_color	*mat_helper(t_material mat, t_vector *position, int x, int y);
t_color	*chqbig(t_obj *obj_hit, t_vector *position,
			t_color **ppm_pixels, t_color *ret);
t_color	*chqts(t_obj *obj_hit, t_vector *position,
			t_color **ppm_pixels, t_color *ret);
t_color	*imgtext(t_obj *obj_hit, t_vector *position,
			t_color **ppm_pixels, t_color *ret);
t_color	*imgtextplane(t_obj *obj_hit, t_vector *position,
			t_color **ppm_pixels, t_color *ret);
t_color	*material_color_at(t_obj *obj_hit,
			t_vector *position, t_color **ppm_pixels);
#endif
