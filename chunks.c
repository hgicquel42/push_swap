/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:10:12 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 11:50:15 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_minmax(a, b);
		put_top_in_position(a, b);
	}
}

void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move(a, b, min, max);
		op_push_b(a, b);
		size--;
	}
}

void	sort_chunks(t_stack *a, t_stack *b)
{
	int	chunks;
	int	step;
	int	lmax;
	int	lmin;

	chunks = (a->top + 1) / 50;
	step = (a->top + 1) / chunks;
	lmax = find_max(a);
	while (chunks >= 1)
	{
		if (chunks > 1)
			lmin = lmax - step + 1;
		else
			lmin = find_min(a);
		move_chunk(a, b, lmin, lmax);
		sort_chunk(a, b);
		lmax = lmin - 1;
		chunks--;
	}
	smart_rotate_a(a, b, find_min(a));
}
