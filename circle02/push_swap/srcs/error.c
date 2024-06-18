/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_h.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:10:05 by chukim            #+#    #+#             */
/*   Updated: 2022/05/04 13:10:05 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "../ft_printf/libft/includes/libft.h"

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}
