/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:02:21 by chukim            #+#    #+#             */
/*   Updated: 2022/12/23 15:16:01 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	a_to_b(t_args *args, int len)
{
	t_cnt_a		*cnt;
	t_pivot_set	*pivot;

	if (len <= 3)
	{
		sort_3_a_1(args);
		return ;
	}
	cnt = (t_cnt_a *)malloc(sizeof(t_cnt_a));
	cnt_a_init(cnt);
	pivot = (t_pivot_set *)malloc(sizeof(t_pivot_set));
	select_pivot(args->stack_a, pivot, len);
	args->len = len;
	args->pivot_set = pivot;
	a_to_b_2(args, cnt);
	a_to_b_3(args, cnt);
	free(cnt);
	free(pivot);
}

void	a_to_b_2(t_args *args, t_cnt_a *cnt)
{
	t_node	*current;

	current = args->stack_a->top;
	while (args->len-- > 0)
	{
		if (current->val >= args->pivot_set->pivot1)
		{
			ra(args);
			cnt->cnt_ra++;
		}
		else
		{
			pb(args);
			cnt->cnt_pb++;
			if (current->val >= args->pivot_set->pivot2)
			{
				rb(args);
				cnt->cnt_rb++;
			}
		}
		current = args->stack_a->top;
	}
}

void	a_to_b_3(t_args *args, t_cnt_a *cnt)
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
	a_to_b(args, cnt->cnt_ra);
	b_to_a(args, cnt->cnt_rb);
	b_to_a(args, cnt->cnt_pb - cnt->cnt_rb);
}
