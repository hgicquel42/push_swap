/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:27:41 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 15:28:11 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push(t_stack *src, t_stack *dst)
{
	if (src->top != -1)
		push(dst, shift(src));
}

void	op_push_a(t_stack *a, t_stack *b)
{
	ft_putstr("pa\n");
	op_push(a, b);
}

void	op_push_b(t_stack *a, t_stack *b)
{
	ft_putstr("pb\n");
	op_push(b, a);
}
