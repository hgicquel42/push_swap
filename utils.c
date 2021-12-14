/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:04:50 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 15:30:33 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

int	ft_atoi(char *s)
{
	int	x;
	int	n;

	x = 0;
	n = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			n = -1;
	while (*s >= '0' && *s <= '9')
		x = (x * 10) + n * (*s++ - '0');
	return (x);
}

int	ft_bytes(int n)
{
	int	b;

	b = 0;
	while ((n >> b) != 0)
		b++;
	return (b);
}

void	op_loop(t_stack *a, t_stack *b, void (f(t_stack*, t_stack*)), int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(a, b);
		i++;
	}
}
