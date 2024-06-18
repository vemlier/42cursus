/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:26 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 01:49:52 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Sa);
	swap(args->stack_a);
	push_top(args->op, operation);
}

void	sb(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Sb);
	swap(args->stack_b);
	push_top(args->op, operation);
}

void	ss(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Ss);
	swap(args->stack_a);
	swap(args->stack_b);
	push_top(args->op, operation);
}

void	pa(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Pa);
	push(args->stack_b, args->stack_a);
	push_top(args->op, operation);
}

void	pb(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Pb);
	push(args->stack_a, args->stack_b);
	push_top(args->op, operation);
}
