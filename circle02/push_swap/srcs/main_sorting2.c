/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:48:57 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:16:14 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/push_swap.h"

void	b_to_a(t_args *args, int len)
{
	t_cnt_b		*cnt;
	t_pivot_set	*pivot;

	if (b_to_a_4(args, len) == 1)
		return ;
	cnt = (t_cnt_b *)malloc(sizeof(t_cnt_b));
	cnt_b_init(cnt);
	pivot = (t_pivot_set *)malloc(sizeof(t_pivot_set));
	select_pivot(args->stack_b, pivot, len);
	args->len = len;
	args->pivot_set = pivot;
	b_to_a_2(args, cnt);
	a_to_b(args, cnt->cnt_pa - cnt->cnt_ra);
	b_to_a_3(args, cnt);
	a_to_b(args, cnt->cnt_ra);
	b_to_a(args, cnt->cnt_rb);
	free(cnt);
	free(pivot);
}

void	b_to_a_2(t_args *args, t_cnt_b *cnt)
{
	t_node	*current;

	current = args->stack_b->top;
	while (args->len-- > 0)
	{
		if (current->val < args->pivot_set->pivot2)
		{
			rb(args);
			cnt->cnt_rb++;
		}
		else
		{
			pa(args);
			cnt->cnt_pa++;
			if (current->val < args->pivot_set->pivot1)
			{
				ra(args);
				cnt->cnt_ra++;
			}
		}
		current = args->stack_b->top;
	}
}

void	b_to_a_3(t_args *args, t_cnt_b *cnt)
{
	int	len;

	if (cnt->cnt_ra >= cnt->cnt_rb)
	{
		len = return_min(cnt->cnt_ra, cnt->cnt_rb);
		cnt->cnt_i = cnt->cnt_ra - len;
		while (len-- > 0)
			rrr(args);
		while (cnt->cnt_i-- > 0)
			rra(args);
	}
	else
	{
		len = return_min(cnt->cnt_ra, cnt->cnt_rb);
		cnt->cnt_i = cnt->cnt_rb - len;
		while (len-- > 0)
			rrr(args);
		while (cnt->cnt_i-- > 0)
			rrb(args);
	}
}

int	b_to_a_4(t_args *args, int len)
{
	if (len == 3)
	{
		sort_3_b_1(args);
		pa(args);
		pa(args);
		pa(args);
		return (1);
	}
	else if (len == 2)
	{
		sort_3_b_1(args);
		pa(args);
		pa(args);
		return (1);
	}
	else if (len == 1)
	{
		pa(args);
		return (1);
	}
	else if (len < 1)
		return (1);
	return (0);
}
