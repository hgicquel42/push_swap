/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:04:50 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 13:42:14 by hgicquel         ###   ########.fr       */
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