/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:25:10 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 17:49:17 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int arr[], int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			++i;
		while (j > start && arr[j] >= arr[pivot])
			--j;
		if (i >= j)
			break ;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	swap_arr(arr, pivot, j);
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void	swap_arr(int arr[], int i, int j)
{
	int	temp;

	temp = arr[j];
	arr[j] = arr[i];
	arr[i] = temp;
}

int	return_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
