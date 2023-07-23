/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:28:26 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:15:43 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"
#include "../ft_printf/includes/ft_printf.h"

void	select_pivot(t_stack *stack, t_pivot_set *pivot, int len)
{
	int	*arr;

	if (len < 2)
	{
		ft_printf("stack is smaller than 2\n");
		return ;
	}
	arr = stack_to_arr(stack, len);
	quick_sort(arr, 0, len - 1);
	pivot->pivot1 = arr[(len / 3) * 2];
	pivot->pivot2 = arr[len / 3];
	free(arr);
}

void	mini_sort_2(t_args *args, char name)
{
	t_node	*current;

	if (name == 'a')
	{
		current = args->stack_a->top;
		if (current->left != NULL && current->val > current->left->val)
			sa(args);
	}
	else if (name == 'b')
	{
		current = args->stack_b->top;
		if (current->left != NULL && current->val < current->left->val)
			sb(args);
	}
	else
		print_error("sort error\n");
}

void	sort_3_a_1(t_args *args)
{
	t_node	*current;

	if (args->stack_a->len < 3)
	{
		mini_sort_2(args, 'a');
		return ;
	}
	current = args->stack_a->top;
	if (current->val > current->left->val
		&& current->val < current->left->left->val)
	{
		sa(args);
	}
	else if (current->left->val > current->left->left->val
		&& current->left->val < current->val)
	{
		sa(args);
		pb(args);
		sa(args);
		pa(args);
		sa(args);
	}
	else
		sort_3_a_2(args);
}

void	sort_3_a_2(t_args *args)
{
	t_node	*current;

	current = args->stack_a->top;
	if (current->left->left->val > current->left->val
		&& current->left->left->val < current->val)
	{
		sa(args);
		pb_sa_pa(args);
	}
	else if (current->left->left->val < current->left->val
		&& current->left->left->val > current->val)
	{
		pb_sa_pa(args);
	}
	else if (current->val < current->left->val
		&& current->val > current->left->left->val)
	{
		pb_sa_pa(args);
		sa(args);
	}
}

void	pb_sa_pa(t_args *args)
{
	pb(args);
	sa(args);
	pa(args);
}
