/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:48:15 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:20:44 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	int				len;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_args
{
	struct s_stack		*stack_a;
	struct s_stack		*stack_b;
	struct s_stack		*op;
	struct s_pivot_set	*pivot_set;
	int					len;
}	t_args;

typedef struct s_pivot_set
{
	int				pivot1;
	int				pivot2;
}	t_pivot_set;

typedef struct s_cnt_a
{
	int	cnt_ra;
	int	cnt_pb;
	int	cnt_rb;
	int	cnt_i;
}	t_cnt_a;

typedef struct s_cnt_b
{
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_ra;
	int	cnt_i;
}	t_cnt_b;

enum e_Operation {
	Sa = 0,
	Sb = 1,
	Ss = 2,
	Pa = 3,
	Pb = 4,
	Ra = 5,
	Rb = 6,
	Rr = 7,
	Rra = 8,
	Rrb = 9,
	Rrr = 10
};

void	parser(char *str, int i, int flag, t_stack *stack);
void	print_error(char *msg);

t_node	*get_new_node(int num);
t_stack	*get_new_stack(void);
int		is_empty(t_stack *stack);
int		is_exist(int num, t_stack *stack);
int		stack_len(t_stack *stack);
int		return_min(int a, int b);

void	print_stack(t_stack *stack);
void	print_stack_duel(t_stack *stack_a, t_stack *stack_b);
void	print_stack_duel_contents(t_stack *stack_a, t_stack *stack_b, int cnt);
void	print_op(t_stack *op);
void	print_op_2(int op);
void	opt_op(t_stack *op);

void	push_top(t_stack *stack, t_node *new_node);
void	push_bottom(t_stack *stack, t_node *new_node);

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack, int direction);

void	sa(t_args *args);
void	sb(t_args *args);
void	ss(t_args *args);
void	pa(t_args *args);
void	pb(t_args *args);
void	ra(t_args *args);
void	rb(t_args *args);
void	rr(t_args *args);
void	rra(t_args *args);
void	rrb(t_args *args);
void	rrr(t_args *args);

void	mini_sort_2(t_args *args, char name);
void	sort_3_a_1(t_args *args);
void	sort_3_a_2(t_args *args);
void	pb_sa_pa(t_args *args);
void	sort_3_b_1(t_args *args);
void	sort_3_b_2(t_args *args);
void	pa_sb_pb(t_args *args);
void	sorting_3(t_args *args);
void	sorting_5(t_args *args);
void	sorting_5_2(t_args *args);

int		*stack_to_arr(t_stack *stack, int len);
void	quick_sort(int arr[], int start, int end);
void	swap_arr(int arr[], int i, int j);
void	select_pivot(t_stack *stack, t_pivot_set *pivot, int len);
void	cnt_a_init(t_cnt_a *cnt);
void	cnt_b_init(t_cnt_b *cnt);

void	a_to_b(t_args *args, int len);
void	a_to_b_2(t_args *args, t_cnt_a *cnt);
void	a_to_b_3(t_args *args, t_cnt_a *cnt);
void	b_to_a(t_args *args, int len);
void	b_to_a_2(t_args *args, t_cnt_b *cnt);
void	b_to_a_3(t_args *args, t_cnt_b *cnt);
int		b_to_a_4(t_args *args, int len);

#endif