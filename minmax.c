/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:42:24 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 15:29:13 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *s)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (++i < s->top + 1)
		if (s->array[i] < s->array[m])
			m = i;
	return (m);
}

int	find_max(t_stack *s)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (++i < s->top + 1)
		if (s->array[i] > s->array[m])
			m = i;
	return (m);
}
