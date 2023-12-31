/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:57:18 by chukim            #+#    #+#             */
/*   Updated: 2022/08/04 23:45:43 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c);	
static char		*ft_makestr(const char *s1, char c, size_t *flag);
static char		*ft_strndup(const char *s, size_t len);
static char		**ft_error(char **s);

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*tmp;
	size_t	flag;
	int		i;
	size_t	strindex;

	i = -1;
	strindex = 0;
	str = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[++i])
	{
		flag = 0;
		if (i == 0 && s[0] != c)
			tmp = ft_makestr(&s[i], c, &flag);
		else if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
			tmp = ft_makestr(&s[i + 1], c, &flag);
		if (flag == 1 && tmp == NULL)
			return (ft_error(str));
		else if (flag == 1)
			str[strindex++] = tmp;
	}
	str[strindex] = 0;
	return (str);
}

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[0] != c)
			|| (s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*ft_makestr(const char *s1, char c, size_t *flag)
{
	char	*tmp;
	size_t	i;

	*flag = 1;
	tmp = NULL;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
		{
			tmp = ft_strndup(s1, i);
			if (tmp == NULL)
				return (NULL);
			return (tmp);
		}
		else if (i == (ft_strlen(s1) - 1))
		{
			tmp = ft_strndup(s1, i + 1);
			if (tmp == NULL)
				return (NULL);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_strndup(const char *s, size_t len)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	if (len == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_error(char **s)
{
	size_t	i;

	i = 0;
	while (!s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
