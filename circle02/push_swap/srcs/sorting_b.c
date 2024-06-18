/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:55:46 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 02:30:23 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_b_1(t_args *args)
{
	t_node	*current;

	if (args->stack_b->len < 3)
	{
		mini_sort_2(args, 'b');
		return ;
	}
	current = args->stack_b->top;
	if (current->val > current->left->val
		&& current->val < current->left->left->val)
	{
		pa_sb_pb(args);
		sb(args);
	}
	else if (current->left->val < current->left->left->val
		&& current->left->val > current->val)
	{
		sb(args);
		pa_sb_pb(args);
		sb(args);
	}
	else
		sort_3_b_2(args);
}

void	sort_3_b_2(t_args *args)
{
	t_node	*current;

	current = args->stack_b->top;
	if (current->left->left->val > current->left->val
		&& current->left->left->val < current->val)
	{
		pa_sb_pb(args);
	}
	else if (current->left->left->val < current->left->val
		&& current->left->left->val > current->val)
	{
		sb(args);
		pa_sb_pb(args);
	}
	else if (current->val < current->left->val
		&& current->val > current->left->left->val)
	{
		sb(args);
	}
}

void	pa_sb_pb(t_args *args)
{
	pa(args);
	sb(args);
	pb(args);
}
