/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:49:29 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 05:02:19 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef t_vector	t_point;
typedef t_vector	t_color;

t_vector	*v_n(double x, double y, double z);
t_vector	*v_sub(t_vector *a, t_vector *b);
t_vector	*v_add(t_vector *a, t_vector *b);
t_vector	*v_scal_mul(t_vector *a, double b);
t_vector	*v_smc(t_vector *a, double b);
t_vector	*v_zm(t_vector *a, double b);
t_vector	*v_cp(t_vector *a, t_vector *b);

double		v_l(t_vector *vector);
void		v_nor(t_vector *vector);
double		v_dp(t_vector *a, t_vector *b);

t_vector	v_add_stack(t_vector a, t_vector b);
t_vector	v_sub_stack(t_vector a, t_vector b);
t_vector	v_scal_mul_stack(t_vector a, double b);
t_vector	v_zm_stack(t_vector a, double b);
t_vector	vector_multiple_stack(t_vector a, t_vector b);
t_vector	v_cp_stack(t_vector a, t_vector b);

double		v_l_s(t_vector vector);
t_vector	v_nor_s(t_vector vector);
double		v_dp_s(t_vector a, t_vector b);
t_vector	v_smc_s(t_vector a, double b);
double		v_l2_s(t_vector vector);
double		v_distance(t_vector v1, t_vector v2);
#endif
