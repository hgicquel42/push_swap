/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:37:12 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 17:12:46 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = 0;
// 	while (i < a->top + 1)
// 		printf("%d ", a->array[i++]);
// 	printf("\n");
// 	i = 0;
// 	while (i < b->top + 1)
// 		printf("%d ", b->array[i++]);
// 	printf("\n");
// }

void	print(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
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

bool	parse(char *s, t_stack *a)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		j = ft_satoi(s + i, &r);
		if (!j)
			return (0);
		if (!try_push(a, r))
			return (0);
		i += j;
	}
	return (1);
}

bool	run(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	bool	e;

	e = 0;
	i = 1;
	while (i < argc)
		e += !parse(argv[i++], a);
	if (e)
		return (0);
	reverse(a);
	if (!reindex(a))
		return (0);
	if (is_sorted(a))
		return (1);
	print(a, b);
	sortn(a, b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack			a;
	t_stack			b;
	bool			r;

	if (argc == 1)
		return (1);
	if (!init(&a, 1024))
		return (ft_puterr("Error\n"));
	if (!init(&b, 1024))
		return (ft_puterr("Error\n") + ft_free(&a));
	r = run(argc, argv, &a, &b);
	if (!r)
		return (ft_puterr("Error\n"));
	ft_free(&a);
	ft_free(&b);
	return (0);
}
