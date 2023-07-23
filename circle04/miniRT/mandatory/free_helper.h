/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:18:56 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/06 16:19:45 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_HELPER_H
# define FREE_HELPER_H

# include <stdio.h>
# include <stdlib.h>
# include "vector.h"
# include "image.h"
# include "color.h"
# include "ray.h"
# include "scene.h"
# include "engine.h"
# include "light.h"
# include "material.h"
# include "engine_helper.h"

typedef struct s_free1
{
	int			i;
	int			objects_num;
	int			lights_num;
	t_vector	*camera;
	t_obj		**objects;
	t_light		**lights;
}				t_free1;

void	freemain(t_scene scene, t_wh im);
void	freemain2(t_wh im, t_free1 f1);
void	free_intersects_p(t_vector *po_tmp, t_vector *po_tmp2, t_vector *tmp);
void	free_trace(t_trace tft);
#endif
