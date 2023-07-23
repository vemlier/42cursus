/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:04:06 by chukim            #+#    #+#             */
/*   Updated: 2022/08/04 23:45:30 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	count;

	count = 0;
	while (count < num)
	{
		((unsigned char *)ptr)[count] = (unsigned char)value;
		count++;
	}
	return (ptr);
}
