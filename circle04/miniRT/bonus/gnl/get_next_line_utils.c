/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:05:08 by bechoi            #+#    #+#             */
/*   Updated: 2022/01/13 11:32:07 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

size_t	ft_gnl_strlcpy(char *dst, char *src, size_t size);
size_t	ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *str, char a);

char	*ft_gnl_strchr(char *str, char a)
{
	while (str && *str)
		if (*str++ == a)
			return (--str);
	return (NULL);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	l1;
	size_t	l2;

	l1 = ft_gnl_strlen(s1);
	l2 = ft_gnl_strlen(s2);
	p = (char *) malloc((l1 + l2 + 1) * sizeof(char));
	if (p)
	{
		if (s1)
			ft_gnl_strlcpy(p, s1, l1 + 1);
		ft_gnl_strlcpy(p + l1, s2, l2 + 1);
	}
	free(s1);
	return (p);
}

size_t	ft_gnl_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s && *s++)
		l++;
	return (l);
}

size_t	ft_gnl_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_gnl_strlen(src);
	while ((i < l) && (i + 1 < size))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (size != 0)
		*(dst + i) = 0;
	return (l);
}
