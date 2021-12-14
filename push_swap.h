/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:37:22 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 15:57:43 by hgicquel         ###   ########.fr       */
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
	int	*array;
	int	top;
	int	size;
}	t_stack;

int		ft_satoi(char *s, int *r);

int		ft_putstr(char *s);

int		ft_bytes(int n);

bool	is_sorted(t_stack *s);

void	insertion_sort(int *p, int n);

bool	init(t_stack *s, int l);

void	push(t_stack *s, int x);

int		shift(t_stack *s);

void	swap(t_stack *s, unsigned int i, unsigned int j);

void	reverse(t_stack *s);

void	print(t_stack *a, t_stack *b);

void	sortn(t_stack *a, t_stack *b);

void	op_push_a(t_stack *a, t_stack *b);

void	op_push_b(t_stack *a, t_stack *b);

void	op_swap_a(t_stack *a, t_stack *b);

void	op_swap_b(t_stack *a, t_stack *b);

void	op_swap_s(t_stack *a, t_stack *b);

void	op_rotate_a(t_stack *a, t_stack *b);

void	op_rotate_b(t_stack *a, t_stack *b);

void	op_rotate_r(t_stack *a, t_stack *b);

void	op_reverse_rotate_a(t_stack *a, t_stack *b);

void	op_reverse_rotate_b(t_stack *a, t_stack *b);

void	op_reverse_rotate_r(t_stack *a, t_stack *b);

void	op_loop(t_stack *a, t_stack *b, void (f(t_stack*, t_stack*)), int n);

void	push_min_to_b(t_stack *a, t_stack *b);

void	smart_rotate_a(t_stack *a, t_stack *b, int n);

int		find_max(t_stack *s);

int		find_min(t_stack *s);

bool	reindex(t_stack *s);

#endif