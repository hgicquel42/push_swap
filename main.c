/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:37:12 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 18:38:45 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->top + 1)
		printf("%d ", s->array[i++]);
	printf("\n");
}

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

void	ft_free(t_stack *s)
{
	if (s->array)
		free(s->array);
}

int	ft_error1(t_stack *s)
{
	ft_free(s);
	return (1);
}

int	ft_error2(t_stack *a, t_stack *b)
{
	ft_free(a);
	ft_free(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	int				i;
	bool			e;

	if (argc == 1)
		return (1);
	if (!init(&a, argc - 1 * 2))
		return (1);
	if (!init(&b, argc - 1 * 2))
		return (ft_error1(&a));
	e = 0;
	i = 1;
	while (i < argc)
		e += !try_push(&a, ft_atoi(argv[i++]));
	if (e)
		return (ft_error2(&a, &b));
	reverse(&a);
	index(&a);
	sort(&a, &b);
	print(&a);
	return (0);
}
