/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:30:02 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 01:49:09 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Ra);
	rotate(args->stack_a, 1);
	push_top(args->op, operation);
}

void	rb(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Rb);
	rotate(args->stack_b, 1);
	push_top(args->op, operation);
}

void	rr(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Rr);
	rotate(args->stack_a, 1);
	rotate(args->stack_b, 1);
	push_top(args->op, operation);
}

void	rra(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Rra);
	rotate(args->stack_a, -1);
	push_top(args->op, operation);
}

void	rrb(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Rrb);
	rotate(args->stack_b, -1);
	push_top(args->op, operation);
}
