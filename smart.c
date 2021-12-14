/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:33 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 11:51:10 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b)
		to_move = find_min(a);
	smart_rotate_a(a, b, to_move);
	op_push_a(a, b);
}

int	closest_above(t_stack *s, int n)
{
	int	k;
	int	i;

	k = find_max(s);
	if (s->top < 0 || n > k)
		return (n);
	i = 0;
	while (i <= s->top)
	{
		if (s->array[i] > n && s->array[i] < k)
			k = s->array[i];
		i++;
	}
	return (k);
}

int	closest_below(t_stack *s, int n)
{
	int	k;
	int	i;

	k = find_min(s);
	if (s->top < 0 || n < k)
		return (n);
	i = 0;
	while (i <= s->top)
	{
		if (s->array[i] < n && s->array[i] > k)
			k = s->array[i];
		i++;
	}
	return (k);
}

void	smart_rotate_a(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = a->top;
	while (i >= 0 && a->array[i] != n)
		i--;
	if (i < 0)
		return ;
	else if (i < a->top / 2)
		op_loop(a, b, op_reverse_rotate_a, i + 1);
	else
		op_loop(a, b, op_rotate_a, a->top - i);
}

void	smart_rotate_b(t_stack *a, t_stack *b, int n)
{
	int	i;

	i = b->top;
	while (b->array[i] != n && i >= 0)
		i--;
	if (i < 0)
		return ;
	else if (i < b->top / 2)
		op_loop(a, b, op_reverse_rotate_b, i + 1);
	else
		op_loop(a, b, op_rotate_b, b->top - i);
}
