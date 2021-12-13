/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:39:15 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 13:57:57 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_pa(t_stack *a, t_stack *b)
{
	ft_putstr("pa\n");
	if (a->top)
		a->array[++a->top] = b->array[--b->top];
}

void	run_pb(t_stack *a, t_stack *b)
{
	ft_putstr("pa\n");
	if (b->top)
		b->array[++b->top] = a->array[--a->top];
}

void	run_sa(t_stack *a, t_stack *b)
{
	(void)b;
	ft_putstr("sa\n");
	if (a->top)
		swap(a, a->top - 2, a->top - 1);
}

void	run_sb(t_stack *a, t_stack *b)
{
	(void)a;
	ft_putstr("sb\n");
	if (b->top)
		swap(b, b->top - 2, b->top - 1);
}

void	run_ss(t_stack *a, t_stack *b)
{
	ft_putstr("ss\n");
	if (a->top)
		swap(a, a->top - 2, a->top - 1);
	if (b->top)
		swap(b, b->top - 2, b->top - 1);
}
