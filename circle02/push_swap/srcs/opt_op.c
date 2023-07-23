/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:28:46 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 17:49:22 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	opt_op(t_stack *op)
{
	int		len;
	t_node	*current;

	len = op->len;
	len--;
	current = op->bottom;
	while (len-- > 0)
	{
		if ((current->val == 5 && current->right->val == 6)
			|| (current->val == 6 && current->right->val == 5))
		{
			current->val = 7;
			current->right->val = -1;
		}
		if ((current->val == 8 && current->right->val == 9)
			|| (current->val == 9 && current->right->val == 8))
		{
			current->val = 10;
			current->right->val = -1;
		}
		current = current->right;
	}
}
