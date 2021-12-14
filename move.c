/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:17:14 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 11:52:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(t_stack *s, int n)
{
	int	i;

	i = s->top;
	while (i >= 0 && s->array[i] != n)
		i--;
	return (i);
}

int	find_minmax_from_top(t_stack *s, int min, int max)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->array[i] >= min && s->array[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}

int	find_minmax_from_bottom(t_stack *s, int min, int max)
{
	int	i;

	i = s->top;
	while (i >= 0)
	{	
		if (s->array[i] >= min && s->array[i] <= max)
			return (i);
		i--;
	}
	return (-1);
}

void	move(t_stack *a, t_stack *b, int min, int max)
{
	int	top;
	int btm;

	top = find_minmax_from_top(a, min, max);
	btm = find_minmax_from_bottom(a, min, max);
	if (top < a->top - btm)
		smart_rotate_a(a, b, a->array[top]);
	else
		smart_rotate_a(a, b, a->array[btm]);
}

void	move_minmax(t_stack *a, t_stack *b)
{
	int	min;
	int max;

	min = find(b, find_min(b));
	max = find(b, find_max(b));
	if (min < b->top - max)
		smart_rotate_b(a, b, b->array[min]);
	else
		smart_rotate_b(a, b, b->array[max]);
}
