/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:37:12 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/10 18:19:25 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	x;
	int	n;

	x = 0;
	n = 1;
	if (*s == '-' || *s == '+')
		if(*s++ == '-')
			n = -1;
	while (*s >= '0' && *s <= '9')
		x = (x * 10) + n * (*s++ - '0');
	return (x);
}

/**
 * 	Push x to the top
 **/
void	push(t_stack *s, int x)
{
	s->array[s->top++] = x;
}

void	swap(t_stack *s, int i, int j)
{
	uint	t;

	t = s->array[i];
	s->array[i] = s->array[j];
	s->array[j] = t;
}

void	reverse(t_stack *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = s->top - 1;
	while (i < j)
		swap(s, i++, j--);
}

/**
 * Init the stack
 **/
bool	init(t_stack *s, uint l)
{
	s->size = l;
	s->top = 0;
	s->array = malloc(l * sizeof(int *));
	if (!s->array)
		return (0);
	return (1);
}

int	ft_error(t_stack *s)
{
	if (s->array)
		free(s->array);
	return (1);
}

/**
 *	Check if x already exists before pushing 
 **/
bool	try_push(t_stack *s, int x)
{
	int	i;

	i = 0;
	while (i < s->top)
		if (s->array[i++] == x)
			return (0);
	push(s, x);
	return (1);
}

void	print(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
		printf("%d\n", s->array[i++]);
}

int	main(int argc, char **argv)
{
	t_stack	s;
	int		i;
	bool	e;

	if (argc == 1)
		return (1);
	if(!init(&s, argc - 1))
		return (1);
	e = 0;
	i = 1;
	while (i < argc)
		e += !try_push(&s, ft_atoi(argv[i++]));
	if (e)
		return (ft_error(&s));
	reverse(&s);
	print(&s);
	free(s.array);
	return (0);
}
