/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:38:36 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 10:42:52 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->top)
		if (s->array[i + 1] > s->array[i])
			return (0);
	return (1);
}

void	insertion_sort(int *p, int n)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	while (i < n)
	{
		x = p[i];
		j = i - 1;
		while (j >= 0 && p[j] > x)
		{
			p[j + 1] = p[j];
			j = j - 1;
		}
		p[j + 1] = x;
		i++;
	}
}
