/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:28:52 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 15:29:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *s)
{
	if (s->top != -1)
		swap(s, s->top, s->top - 1);
}

void	op_swap_a(t_stack *a)
{
	ft_putstr("sa\n");
	op_swap(a);
}

void	op_swap_b(t_stack *b)
{
	ft_putstr("sb\n");
	op_swap(b);
}

void	op_swap_s(t_stack *a, t_stack *b)
{
	ft_putstr("ss\n");
	op_swap(a);
	op_swap(b);
}
