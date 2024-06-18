/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:10:11 by chukim            #+#    #+#             */
/*   Updated: 2022/05/04 13:10:11 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_args	args;

	i = 0;
	args.stack_a = get_new_stack();
	args.stack_b = get_new_stack();
	args.op = get_new_stack();
	while (++i < argc)
		parser(argv[i], -1, 0, args.stack_a);
	if (args.stack_a->len == 5 || args.stack_a->len == 3)
		sorting_5(&args);
	else if (args.stack_a->len == 0)
		return (0);
	else
		a_to_b(&args, args.stack_a->len);
	opt_op(args.op);
	print_op(args.op);
	return (0);
}

void	print_op(t_stack *op)
{
	t_node	*current;

	current = op->bottom;
	while (op->len-- > 0)
	{
		print_op_2(current->val);
		current = current->right;
	}
}

void	print_op_2(int op)
{
	if (op == Sa)
		write(1, "sa\n", 3);
	else if (op == Sb)
		write(1, "sb\n", 3);
	else if (op == Ss)
		write(1, "ss\n", 3);
	else if (op == Pa)
		write(1, "pa\n", 3);
	else if (op == Pb)
		write(1, "pb\n", 3);
	else if (op == Ra)
		write(1, "ra\n", 3);
	else if (op == Rb)
		write(1, "rb\n", 3);
	else if (op == Rr)
		write(1, "rr\n", 3);
	else if (op == Rra)
		write(1, "rra\n", 4);
	else if (op == Rrb)
		write(1, "rrb\n", 4);
	else if (op == Rrr)
		write(1, "rrr\n", 4);
}
