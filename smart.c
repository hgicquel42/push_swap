/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:29:33 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 16:32:31 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b)
{
	smart_rotate_a(a, b, find_min(a));
	op_push_b(a, b);
}

void	op_loop(t_stack *a, t_stack *b, void (f(t_stack*, t_stack*)), int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(a, b);
		i++;
	}
}

void	smart_rotate_a(t_stack *a, t_stack *b, int i)
{
	if (i > a->top / 2)
		op_loop(a, b, op_rotate_a, a->top - i);
	else
		op_loop(a, b, op_reverse_rotate_a, i + 1);
}
