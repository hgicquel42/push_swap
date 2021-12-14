/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:04:50 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 16:49:21 by hgicquel         ###   ########.fr       */
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

int	ft_puterr(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
	return (1);
}

int	ft_free(t_stack *s)
{
	if (s->array)
		free(s->array);
	return (0);
}

int	ft_satoi(char *s, int *r)
{
	long	x;
	int		i;
	int		n;

	x = 0;
	n = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			n = -1;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		x = (x * 10) + n * (s[i++] - '0');
		if (n == 1 && x > 2147483647)
			return (0);
		if (n == -1 && x < -2147483648)
			return (0);
	}
	*r = (int) x;
	return (i);
}

int	ft_bytes(int n)
{
	int	b;

	b = 0;
	while ((n >> b) != 0)
		b++;
	return (b);
}
