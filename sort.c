/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:11:42 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 16:36:50 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *a, t_stack *b)
{
	int	*p;

	p = a->array;
	if (p[0] > p[1] && p[1] < p[2] && p[2] < p[0])
		op_swap_a(a, b);
	if (p[0] > p[1] && p[1] < p[2] && p[2] > p[0])
		op_rotate_a(a, b);
	if (p[0] < p[1] && p[1] > p[2] && p[2] > p[0])
		op_reverse_rotate_a(a, b);
	if (p[0] < p[1] && p[1] > p[2] && p[2] < p[0])
	{
		op_swap_a(a, b);
		op_rotate_a(a, b);
	}
	if (p[0] < p[1] && p[1] < p[2] && p[2] > p[0])
	{
		op_swap_a(a, b);
		op_reverse_rotate_a(a, b);
	}
}

void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b)
		to_move = min(a);
	smart_rotate_a(a, b, to_move);
	op_push_a(a, b);
}

void	sort_ab(t_stack *a, t_stack *b)
{
	op_loop(a, b, op_push_b, a->top - 2);
	sort_a(a, b);
	while (b->top >= 0)
		put_top_in_position(a, b);
	smart_rotate_a(a, b, 0);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		op_swap_a(a, b);
	if (a->top == 2)
		sort_a(a, b);
	if (a->top > 2)
		sort_ab(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->top < 5)
		sort_small(a, b);
}
