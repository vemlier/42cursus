/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:52:00 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 18:14:06 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vector.h"
# include "image.h"
# include "color.h"
# include "ray.h"
# include "stdbool.h"
//# include "material.h"

typedef struct s_material
{
	t_color	*m_c1;
	t_color	*m_c2;
	double	m_d;
	double	m_s;
	double	m_r;
}				t_material;

enum {
	OneColor = 1,
	ChqBig= 2,
	ChqTextureSphere = 3,
	ImgTexture = 4,
	ImgTexturePlane = 5,
};

enum {
	Sphere = 1,
	Plane = 2,
	Cylinder = 3,
	Cone = 4,
};

typedef struct s_sphere
{
	t_vector	*center;
	double		radius;
}	t_sphere;

typedef struct s_plane
{
	t_vector	*point;
	t_vector	*nv;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	*bottom;
	t_vector	*top;
	t_vector	*direction;
	double		diameter;
	double		height;
	int			circle;
}	t_cylinder;

typedef struct s_cyhelp
{
	t_vector	v;
	t_vector	h;
	t_vector	h_ori;
	t_vector	w;
	t_vector	l_int;
	double		r;
	double		a;
	double		b;
	double		c;
	double		d;
	double		t;
	double		d_sqr;
	double		l_int_tmp;
}	t_cyhelp;

typedef struct s_cycirh
{
	double			radius;
	double			denom;
	t_vector		center;
	t_vector		hit_pos;
	double			distance;
	double			root;
}	t_cycirh;

typedef struct s_cone
{
	t_vector	*center;
	t_vector	*tip;
	t_vector	*direction;
	double		radius;
	double		height;
	int			circle;
}	t_cone;

typedef struct s_obj
{
	int			type;
	int			mat_type;
	t_sphere	*s;
	t_cylinder	*c;
	t_cone		*cone;
	t_plane		*p;
	t_material	*material;
}	t_obj;

double		intersects(t_obj *obj, t_ray *ray);
double		intersects_sphere(t_sphere *sphere, t_ray *ray);
double		intersects_plane(t_plane *plane, t_ray *ray);
t_vector	*normal(t_sphere *sphere, t_vector *surface_point);
t_vector	*normal_plane(t_plane *plane, t_vector *surface_point);
double		intersects_cylinder(t_cylinder *cylinder, t_ray *ray);
t_vector	*normal_cylinder(t_cylinder *cylinder, t_vector *pos, t_ray *ray);
double		intersects_cone(t_cone *cone, t_ray *ray);
t_vector	*normal_cone(t_cone *cone, t_vector *pos, t_ray *ray);
t_vector	side_normal(t_cylinder *cylinder, t_vector pos);
bool		cylinder_height(t_cylinder *cylinder, double t, t_ray *ray);
#endif
