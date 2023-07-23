/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:55:43 by chukim            #+#    #+#             */
/*   Updated: 2022/08/04 23:46:14 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*res;
	unsigned char	target;

	res = NULL;
	i = 0;
	target = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == target)
			res = ((char *)(&s[i]));
		i++;
	}
	if (target == 0)
		res = (char *)(&s[ft_strlen(s)]);
	return (res);
}
