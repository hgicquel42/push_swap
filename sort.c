/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:11:42 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 14:42:26 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *s)
{
	int	i;

	i = -1;
	while (++i < s->top)
		if (s->array[i + 1] > s->array[i])
			return (0);
	return (1);
}

void sort1(t_stack *a, t_stack *b)
{
	int	*p;

	p = a->array;
	if (p[0] > p[1])
		if (p[1] < p[2])
			if (p[2] < p[0])
				run_sa(a, b);
			else
				run_ra(a, b);
		else
			return ;
	else
		if (p[1] < p[2])
			if (p[2] > p[0])
			{
				run_sa(a, b);
				run_rra(a, b);
			}
			else
				return ;
		else
			if (p[2] < p[0])
			{
				run_sa(a, b);
				run_ra(a, b);
			}

		
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		run_sa(a, b);
		// if (a->top == 2)

}

void	sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->top <= 5)
		sort_small(a, b);
}
