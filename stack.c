/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:05:32 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 13:57:16 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	init(t_stack *s, unsigned int l)
{
	s->size = l;
	s->top = -1;
	s->array = malloc(l * sizeof(int *));
	if (!s->array)
		return (0);
	return (1);
}

void	push(t_stack *s, int x)
{
	s->array[++s->top] = x;
}

void	swap(t_stack *s, unsigned int i, unsigned int j)
{
	int	t;

	t = s->array[i];
	s->array[i] = s->array[j];
	s->array[j] = t;
}

void	reverse(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	j = s->top;
	while (i < j)
		swap(s, i++, j--);
}

void	print(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top + 1)
		printf("%d\n", s->array[i++]);
}
