/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:37:22 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/13 13:57:00 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int				*array;
	int				top;
	unsigned int	size;
}	t_stack;

int		ft_atoi(char *s);

int		ft_putstr(char *s);

bool	init(t_stack *s, unsigned int l);

void	push(t_stack *s, int x);

void	swap(t_stack *s, unsigned int i, unsigned int j);

void	reverse(t_stack *s);

void	print(t_stack *s);

void	run_pa(t_stack *a, t_stack *b);

void	run_pb(t_stack *a, t_stack *b);

void	run_sa(t_stack *a, t_stack *b);

void	run_sb(t_stack *a, t_stack *b);

void	run_ss(t_stack *a, t_stack *b);

#endif