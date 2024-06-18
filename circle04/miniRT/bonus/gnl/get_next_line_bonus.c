/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bechoi <bechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:05:22 by bechoi            #+#    #+#             */
/*   Updated: 2022/02/04 10:18:54 by bechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

size_t	ft_gnl_strlcpy(char *dst, char *src, size_t size);
size_t	ft_gnl_strlen(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *str, char a);

void	ft_shift(char *st, char *point)
{
	size_t	l;

	point += 1;
	l = ft_gnl_strlen(point);
	ft_gnl_strlcpy(st, point, l + 1);
}

bool	ft_to_point(char *str, char *point, char **r)
{
	char	*p;

	p = (char *) malloc((point - str + 2) * sizeof(char));
	if (p)
	{
		ft_gnl_strlcpy(p, str, point - str + 2);
		*r = ft_gnl_strjoin(*r, p);
		free(p);
		ft_shift(str, point);
		if (*r)
			return (true);
	}
	return (false);
}

bool	ft_read(int fd, char **r)
{
	static char	str[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		e;

	tmp = ft_gnl_strchr(str, '\n');
	if (tmp)
		return (ft_to_point(str, tmp, r));
	if (*str)
	{
		*r = ft_gnl_strjoin(*r, str);
		*str = 0;
		if (*r == NULL)
			return (false);
	}
	e = read(fd, str, BUFFER_SIZE);
	if (e < 0)
		return (false);
	else if (e == 0)
		return (true);
	else
		*(str + e) = 0;
	return (ft_read(fd, r));
}

char	*get_next_line(int fd)
{
	char		*r;

	r = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_read(fd, &r))
		return (r);
	free(r);
	return (NULL);
}
