/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:49:02 by chukim            #+#    #+#             */
/*   Updated: 2022/06/20 15:08:05 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup_new(char *s)
{
	char	*mem;
	int		size;
	int		i;

	mem = NULL;
	size = ft_strlen(s);
	i = 0;
	mem = malloc(size + 1);
	if (!(mem))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		mem[i] = s[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int	ft_strlcpy_new(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
		return (src_len);
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	char	*mem;
	size_t	s1_len;
	size_t	s2_len;

	mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_new(s2));
	else if (s2 == NULL)
		return (ft_strdup_new(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	mem = malloc(s1_len + s2_len);
	if (!(mem))
		return (NULL);
	ft_strlcpy_new(mem, s1, s1_len + 1);
	ft_strlcpy_new(mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (mem);
}
