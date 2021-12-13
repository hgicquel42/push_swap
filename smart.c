/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:33 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 16:32:02 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find the next number greater than n in the
** stack. Returns 'n' if there's no such number;
*/

int	closest_above(t_stack *s, int n)
{
	int	k;
	int	i;

	if (s->top < 0 || n > max(s))
		return (n);
	i = 0;
	k = max(s);
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

	if (s->top < 0 || n < min(s))
		return (n);
	i = 0;
	k = min(s);
	while (i <= s->top)
	{
		if (s->array[i] < n && s->array[i] > k)
			k = s->array[i];
		i++;
	}
	return (k);
}

/*
** Put the number 'n' at the top of the stack,
** in the least amount of moves possible (RRA
** or RA). Do nothing if 'n' isn't on stack;
*/

void	smart_rotate_a(t_stack *a, t_stack *b, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		op_loop(a, b, op_reverse_rotate_a, find + 1);
	else
		op_loop(a, b, op_rotate_a, a->top - find);
}

void	smart_rotate_b(t_stack *a, t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (b->array[find] != n && find >= 0)
		find--;
	if (find < 0)
		return ;
	else if (find < b->top / 2)
		op_loop(a, b, op_reverse_rotate_b, find + 1);
	else
		op_loop(a, b, op_rotate_b, b->top - find);
}
