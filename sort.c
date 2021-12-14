/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:11:42 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 15:46:35 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *a, t_stack *b)
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

void	sort4(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort3(a, b);
	op_push_a(a, b);
}

void	sort5(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort3(a, b);
	op_push_a(a, b);
	op_push_a(a, b);
}

void	sortr(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	n;
	int	x;

	n = ft_bytes(a->top);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < (int) a->size)
		{
			x = a->array[a->top];
			if (((x >> i) & 1) == 1)
				op_rotate_a(a, b);
			else
				op_push_b(a, b);
			j++;
		}
		while (b->top + 1)
			op_push_a(a, b);
		i++;
	}
}

void	sortn(t_stack *a, t_stack *b)
{
	if (a->top + 1 == 2)
		op_swap_a(a, b);
	if (a->top + 1 == 3)
		sort3(a, b);
	if (a->top + 1 == 4)
		sort4(a, b);
	if (a->top + 1 == 5)
		sort5(a, b);
	else
		sortr(a, b);
}
