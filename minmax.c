/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:42:24 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 16:43:39 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rmax(int *p, size_t l)
{
	int	m;

	if (l == 1)
		return (p[0]);
	m = rmax(p, l - 1);
	if (p[l - 1] > m)
		m = p[l - 1];
	return (m);
}

int	max(t_stack *s)
{
	return (rmax(s->array, s->top + 1));
}

int	rmin(int *p, size_t l)
{
	int	m;

	if (l == 1)
		return (p[0]);
	m = rmin(p, l - 1);
	if (p[l - 1] < m)
		m = p[l - 1];
	return (m);
}

int	min(t_stack *s)
{
	return (rmin(s->array, s->top + 1));
}
