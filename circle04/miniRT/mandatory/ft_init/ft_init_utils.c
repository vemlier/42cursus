/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:43:49 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 03:43:51 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../vector.h"
#include "../ft_atod/ft_atod.h"
#include "../ft_exit/ft_exit.h"
#include "ft_init.h"

t_vector	*ft_c_v(char *str)
{
	char		**arr;
	int			i;
	t_vector	*ret;

	arr = ft_split(str, ',');
	if (arr == 0)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		++i;
	if (i != 3)
	{	
		ft_exit(1, "Error\nWrong Format\n");
	}
	i = 0;
	ret = v_n(ft_atod(arr[0]), ft_atod(arr[1]), ft_atod(arr[2]));
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr);
	return (ret);
}

int	ft_in_range(t_vector *v, double a, double b)
{
	if (a > v->x || b < v->x)
		return (1);
	if (a > v->y || b < v->y)
		return (1);
	if (a > v->z || b < v->z)
		return (1);
	return (0);
}
