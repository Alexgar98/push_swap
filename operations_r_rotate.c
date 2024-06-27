/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:30:44 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/15 11:52:20 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (get_length(*stack) > 1)
	{
		last = get_last(*stack);
		second_last = last -> previous;
		second_last -> next = NULL;
		last -> previous = NULL;
		last -> next = *stack;
		(*stack)-> previous = last;
		*stack = last;
	}
}

void	reverse_rotate_a(t_stack **a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	reverse_rotate_b(t_stack **b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	reverse_rotate_r(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
