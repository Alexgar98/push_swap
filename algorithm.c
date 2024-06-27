/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:07:41 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/14 12:04:18 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_preparation(t_stack **a, t_stack **b,
					t_stack *to_push, t_stack *high_lower)
{
	int	length_push;
	int	length_lower;

	length_push = get_length(to_push) > (get_length(*a) / 2);
	length_lower = get_length(high_lower) > (get_length(*b) / 2);
	while ((*a)-> cont != to_push -> cont)
	{
		if (length_push)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	while ((*b)-> cont != high_lower -> cont)
	{
		if (length_lower)
			rotate_b(b);
		else
			reverse_rotate_b(b);
	}
}

void	prepare_push_b(t_stack **a, t_stack **b,
					t_stack *to_push, t_stack *high_lower)
{
	int	length_lower;
	int	length_push;

	length_lower = get_length(high_lower) < (get_length(*b) / 2);
	length_push = get_length(to_push) < (get_length(*a) / 2);
	while ((*a)-> cont != to_push -> cont
		&& (*b)-> cont != high_lower -> cont)
	{
		if (length_lower && length_push)
			reverse_rotate_r(a, b);
		else if (!length_lower && !length_push)
			rotate_r(a, b);
		else if (length_lower && !length_push)
		{
			rotate_a(a);
			reverse_rotate_b(b);
		}
		else
		{
			reverse_rotate_a(a);
			rotate_b(b);
		}
	}
	finish_preparation(a, b, to_push, high_lower);
	push_b(a, b);
}

void	empty_b(t_stack **a, t_stack **b)
{
	t_stack	*low_higher;
	int		greater;

	while (*b)
	{
		low_higher = lowest_higher(*b, a);
		greater = get_length(low_higher) > (get_length(*a) / 2);
		while ((*a)-> cont != low_higher -> cont)
		{
			if (greater)
				rotate_a(a);
			else
				reverse_rotate_a(a);
		}
		push_a(a, b);
	}
}

void	swap_rotate(t_stack **a)
{
	swap_a(a);
	rotate_a(a);
}
