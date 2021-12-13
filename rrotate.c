/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:16 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 18:28:27 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_reverse_rotate(t_stack *s)
{
	int	i;
	int	t;

	i = -1;
	t = s->array[0];
	while (++i < s->top)
		s->array[i] = s->array[i + 1];
	s->array[s->top] = t;
}

void	op_reverse_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	ft_putstr("rra\n");
	op_reverse_rotate(a);
	print(a);
}

void	op_reverse_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_putstr("rrb\n");
	op_reverse_rotate(b);
	print(a);
}

void	op_reverse_rotate_r(t_stack *a, t_stack *b)
{
	ft_putstr("rrr\n");
	op_reverse_rotate(a);
	op_reverse_rotate(b);
	print(a);
}
