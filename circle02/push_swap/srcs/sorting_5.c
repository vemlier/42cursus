/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:20:54 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:16:35 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"

void	sorting_5(t_args *args)
{
	int		len;
	int		*arr;
	t_node	*current;

	if (args->stack_a->len == 3)
	{
		sorting_3(args);
		return ;
	}
	len = args->stack_a->len;
	arr = stack_to_arr(args->stack_a, len);
	quick_sort(arr, 0, len - 1);
	current = args->stack_a->top;
	while (len-- > 0)
	{
		if (current->val == arr[0] || current->val == arr[4])
			pb(args);
		else
			ra(args);
		current = args->stack_a->top;
	}
	free(arr);
	sorting_5_2(args);
}

void	sorting_5_2(t_args *args)
{
	sorting_3(args);
	pa(args);
	if (args->stack_a->top->val > args->stack_b->top->val)
	{
		ra(args);
		pa(args);
	}
	else
	{
		pa(args);
		ra(args);
	}
}

void	sorting_3(t_args *args)
{
	t_node	*current;

	current = args->stack_a->top;
	if (current->val > current->left->val
		&& current->val < args->stack_a->bottom->val)
		sa(args);
	else if (current->left->val < current->val
		&& current->left->val > args->stack_a->bottom->val)
	{
		sa(args);
		rra(args);
	}
	else if (args->stack_a->bottom->val < current->val
		&& args->stack_a->bottom->val > current->left->val)
		ra(args);
	else if (args->stack_a->bottom->val > current->val
		&& args->stack_a->bottom->val < current->left->val)
	{
		sa(args);
		ra(args);
	}
	else if (current->val < current->left->val
		&& current->val > args->stack_a->bottom->val)
		rra(args);
}
