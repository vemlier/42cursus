/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:33:55 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/18 03:33:58 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../ft_exit/ft_exit.h"

static double	ft_atod_helper(char *str)
{
	double	ret;
	int		index;

	index = 0;
	ret = 0;
	while (*str != 0 && *str != '.')
	{
		if ('0' <= *str && *str <= '9')
			ret = ret * 10 + *str - '0';
		else
			ft_exit(1, "Error\nWrong Format\n");
		++str;
	}
	if (*str == '.')
		++str;
	while (str[index] != 0)
	{
		if ('0' <= str[index] && str[index] <= '9')
			ret += pow(10, -(index + 1)) * 1 * (str[index] - '0');
		else
			ft_exit(1, "Error\nWrong Format\n");
		++index;
	}
	return (ret);
}

double	ft_atod(char *str)
{
	bool	neg;

	neg = false;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = true;
		++str;
	}
	if (neg)
		return (ft_atod_helper(str) * -1);
	return (ft_atod_helper(str));
}
