/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_making.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:51:46 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 14:57:40 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"

t_node	*get_new_node(int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->val = num;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

t_stack	*get_new_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->len = 0;
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (1);
	return (0);
}

void	push_top(t_stack *stack, t_node *new_node)
{
	if (is_empty(stack))
	{
		stack->top = new_node;
		stack->bottom = new_node;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	else
	{
		stack->top->right = new_node;
		new_node->left = stack->top;
		new_node->right = NULL;
		stack->top = new_node;
	}
	stack->len++;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	if (is_empty(stack))
	{
		stack->top = new_node;
		stack->bottom = new_node;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	else
	{
		stack->bottom->left = new_node;
		new_node->right = stack->bottom;
		new_node->left = NULL;
		stack->bottom = new_node;
	}
	stack->len++;
}
