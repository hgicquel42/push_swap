/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:32:52 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 11:02:22 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy(int *p, int l)
{
	int	i;
	int	*r;

	r = malloc(l * sizeof(int *));
	if (!r)
		return (0);
	i = -1;
	while (++i < l)
		r[i] = p[i];
	return (r);
}

void	reindex2(t_stack *s, int *p, int *q)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->top + 1)
	{
		j = 0;
		while (p[j] != s->array[i])
			j++;
		q[i++] = j;
	}
}

bool	reindex(t_stack *s)
{
	int	*p;
	int	*q;

	p = copy(s->array, s->top + 1);
	if (!p)
		return (0);
	q = copy(s->array, s->top + 1);
	if (!q)
	{
		free(p);
		return (0);
	}
	insertion_sort(p, s->top + 1);
	reindex2(s, p, q);
	free(s->array);
	s->array = q;
	free(p);
	return (1);
}
