/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:02:23 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 16:25:22 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_stack *s)
{
	int	i;
	int	tmp;

	i = s->top + 1;
	tmp = s->array[s->top];
	while (--i)
		s->array[i] = s->array[i - 1];
	s->array[0] = tmp;
}

void	op_rotate_a(t_stack *a, t_stack *b)
{
	(void)b;
	ft_putstr("ra\n");
	op_rotate(a);
}

void	op_rotate_b(t_stack *a, t_stack *b)
{
	(void)a;
	ft_putstr("rb\n");
	op_rotate(b);
}

void	op_rotate_r(t_stack *a, t_stack *b)
{
	ft_putstr("rr\n");
	op_rotate(a);
	op_rotate(b);
}
