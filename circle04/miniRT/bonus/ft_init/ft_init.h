/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:23:30 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/20 01:29:19 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include "../scene.h"
# include "../ft_exit/ft_exit.h"
//# include "../check.h"

typedef struct s_main_help
{
	char const	*str;
	int			fd;
	int			i;
	char		*tmp;
}				t_main_help;

int			ft_init(char *str, t_scene *scene);
int			ft_init_cylinder(char **arr, t_scene *scene);
int			ft_init_obj(char **arr, t_scene *scene, int type);
int			ft_init_plane(char **arr, t_scene *scene);
int			ft_init_sphere(char **arr, t_scene *scene);
int			ft_init_cone(char **arr, t_scene *scene);
//utils
t_vector	*ft_c_v(char *str);
int			ft_in_range(t_vector *v, double a, double b);
//init.c
int			ft_init_classify2(char **arr, t_scene *scene);
int			ft_init_classify(char **arr, t_scene *scene);
int			ft_init(char *str, t_scene *scene);
//struct.c
int			ft_init_ambient(char **arr, t_scene *scene);
int			ft_init_camera(char **arr, t_scene *scene);
int			ft_init_light(char **arr, t_scene *scene);

int			ft_init_sphere(char **arr, t_scene *scene);
int			ft_init_plane(char **arr, t_scene *scene);
int			ft_init_cylinder(char **arr, t_scene *scene);

int			ft_init_obj(char **arr, t_scene *scene, int type);
int			ft_init_obj_help(char **arr, t_scene *scene, int index);

int			init_main(t_scene *s, t_wh *im);

// void	plane_normal_chker(t_plane *plane1, t_camera *camera2);
// void	color_chk(t_scene *scene2);
#endif
