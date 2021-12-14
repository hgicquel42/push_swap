/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:37:22 by hgicquel          #+#    #+#             */
/*   Updated: 2021/12/14 11:51:26 by hgicquel         ###   ########.fr       */
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

bool	is_sorted(t_stack *s);

void	insertion_sort(int *p, int n);

bool	init(t_stack *s, unsigned int l);

void	push(t_stack *s, int x);

int		shift(t_stack *s);

void	swap(t_stack *s, unsigned int i, unsigned int j);

void	reverse(t_stack *s);

void	print(t_stack *s);

void	sort(t_stack *a, t_stack *b);

void	sort_chunks(t_stack *a, t_stack *b);

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

void	put_top_in_position(t_stack *a, t_stack *b);

int		closest_above(t_stack *s, int n);

int		closest_below(t_stack *s, int n);

void	smart_rotate_a(t_stack *a, t_stack *b, int n);

void	smart_rotate_b(t_stack *a, t_stack *b, int n);

int		find_max(t_stack *s);

int		find_min(t_stack *s);

bool	reindex(t_stack *s);

void	move(t_stack *a, t_stack *b, int min, int max);

void	move_minmax(t_stack *a, t_stack *b);

#endif