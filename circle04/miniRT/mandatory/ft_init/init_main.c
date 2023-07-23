/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 03:41:26 by ysungwon          #+#    #+#             */
/*   Updated: 2022/12/21 19:38:25 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include "../gnl/get_next_line.h"
#include "../../libft/libft.h"
#include "../ft_exit/ft_exit.h"
#include "../test/test.h"
#include "../image.h"
#include "../vector.h"
#include "../scene.h"
#include <unistd.h>

void	print_vector(t_vector *v);

void	init_mh(t_main_help *mh)
{
	mh->i = 0;
	mh->str = "test.rt";
	mh->fd = open(mh->str, O_RDONLY);
}

void	acl_init(t_scene *s)
{
	t_acl_check	*acl;

	acl = (t_acl_check *)malloc(sizeof(t_acl_check));
	acl->acount = 0;
	acl->ccount = 0;
	acl->lcount = 0;
	acl->lflag = 0;
	s->acl = acl;
}

int	init_main(t_scene *s, t_wh *im)
{
	t_main_help	mh;

	init_mh(&mh);
	acl_init(s);
	while (++mh.i)
	{
		mh.tmp = get_next_line(mh.fd);
		if (mh.tmp == 0 || *mh.tmp == 0)
			break ;
		if (*mh.tmp == '\n')
		{
			free(mh.tmp);
			continue ;
		}
		if (ft_strlen(mh.tmp) >= 1)
			mh.tmp[ft_strlen(mh.tmp) - 1] = 0;
		if (ft_init(mh.tmp, s))
		{
			ft_exit(1, "Error\nWrong Format\n");
		}
		free(mh.tmp);
	}
	im->ob_n = s->ob_n;
	return (0);
}
