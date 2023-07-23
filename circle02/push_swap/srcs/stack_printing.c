/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:09:44 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:13:16 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"
#include "../ft_printf/includes/ft_printf.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	if (current == NULL)
	{
		ft_printf("stack is NULL\n");
	}
	else
	{
		ft_printf("-----stack-----\n");
		while (current != NULL)
		{
			ft_printf("%d\n", current->val);
			current = current->left;
		}
		ft_printf("-----stack-----\n");
		ft_printf("stack len is [%d]\n", stack->len);
	}
}

void	print_stack_duel(t_stack *stack_a, t_stack *stack_b)
{
	int		cnt;

	if (stack_a->len >= stack_b->len)
		cnt = stack_a->len;
	else
		cnt = stack_b->len;
	ft_printf("-----stack_a-----||-----stack_b-----\n");
	print_stack_duel_contents(stack_a, stack_b, cnt);
	ft_printf("-----stack_a-----||-----stack_b-----\n");
	ft_printf("stack_a len [%d] || stack_b len [%d]\n",
		stack_a->len, stack_b->len);
}

void	print_stack_duel_contents(t_stack *stack_a, t_stack *stack_b, int cnt)
{
	t_node	*current1;
	t_node	*current2;

	current1 = stack_a->top;
	current2 = stack_b->top;
	while (cnt-- > 0)
	{
		if (current1 != NULL)
		{
			ft_printf("-----[ %d  ]-----|", current1->val);
			current1 = current1->left;
		}
		else
			ft_printf("-----[NULL!]-----|");
		if (current2 != NULL)
		{
			ft_printf("|-----[ %d  ]-----\n", current2->val);
			current2 = current2->left;
		}
		else
			ft_printf("|-----[NULL!]-----\n");
	}
}

int	stack_len(t_stack *stack)
{
	int		cnt;
	t_node	*current;

	current = stack->top;
	cnt = 0;
	while (current != NULL)
	{
		cnt++;
		current = current->left;
	}
	return (cnt);
}

void	rrr(t_args *args)
{
	t_node	*operation;

	operation = get_new_node(Rrr);
	rotate(args->stack_a, -1);
	rotate(args->stack_b, -1);
	push_top(args->op, operation);
}
