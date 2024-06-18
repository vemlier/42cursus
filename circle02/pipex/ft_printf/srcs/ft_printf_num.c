/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:08:44 by chukim            #+#    #+#             */
/*   Updated: 2022/12/02 03:30:47 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(t_info *info, va_list ap)
{
	int			ret;
	long long	num;

	info->num_base = 10;
	num = va_arg(ap, int);
	if (num < 0)
	{
		info->num_sign = -1;
		num = -num;
		(info->width)--;
	}
	ret = print_num(info, num);
	return (ret);
}

int	ft_print_u(t_info *info, va_list ap)
{
	int			ret;
	long long	num;

	info->num_base = 10;
	num = va_arg(ap, unsigned int);
	ret = print_num(info, num);
	return (ret);
}

int	ft_print_xx(t_info *info, va_list ap, char type)
{
	int			ret;
	long long	num;

	if (type == 'x')
		info->locass = SMALL;
	info->num_base = 16;
	num = va_arg(ap, unsigned int);
	ret = print_num(info, num);
	return (ret);
}

int	ft_print_p(t_info *info, va_list ap)
{
	int					ret;
	unsigned long long	num;

	info->address = ENABLE;
	info->locass = SMALL;
	info->width -= 2;
	info->num_base = 16;
	num = (unsigned long long)va_arg(ap, void *);
	if (num == 0)
		ret = write(1, "(nil)", 5);
	else
		ret = print_num(info, num);
	return (ret);
}
