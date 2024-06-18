/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:23:09 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:14:03 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	*stack_to_arr(t_stack *stack, int len)
{
	int		cnt;
	int		*result;
	t_node	*current;

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		print_error("malloc error\n");
	current = stack->top;
	cnt = 0;
	while (len-- > 0)
	{
		result[cnt] = current->val;
		current = current->left;
		cnt++;
	}
	return (result);
}

void	cnt_a_init(t_cnt_a *cnt)
{
	cnt->cnt_ra = 0;
	cnt->cnt_pb = 0;
	cnt->cnt_rb = 0;
	cnt->cnt_i = 0;
}

void	cnt_b_init(t_cnt_b *cnt)
{
	cnt->cnt_rb = 0;
	cnt->cnt_pa = 0;
	cnt->cnt_ra = 0;
	cnt->cnt_i = 0;
}
