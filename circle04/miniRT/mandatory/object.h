/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:57:02 by chukim            #+#    #+#             */
/*   Updated: 2022/12/21 17:52:05 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

typedef struct s_var
{
	double		t;
	double		m;
	double		a;
	double		b;
	double		c;
	double		d;
	double		d_sqr;
	double		tmp;
	t_vector	l;
	t_vector	v;
	t_vector	h;
	t_vector	h_pivot;
	t_vector	w;
}	t_var;

void	calculate_cone_det(t_var *var, t_cone *cone, t_ray *ray);
double	calculate_cone_intersect(t_var *var, t_cone *cone, t_ray *ray);
double	calculate_cone_ret(t_var *var, t_cone *cone, t_ray *ray);
double	cone_circle(t_cone *cone, t_ray *ray);
double	calculate_ret(t_cone *cone, t_ray *ray, double tmp);

#endif