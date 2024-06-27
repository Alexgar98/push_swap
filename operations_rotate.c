/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:20:22 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/15 11:52:23 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second;

	if (get_length(*stack) > 1)
	{
		last = get_last(*stack);
		second = (*stack)-> next;
		second -> previous = NULL;
		(*stack)-> next = NULL;
		last -> next = *stack;
		(*stack)-> previous = last;
		*stack = second;
	}
}

void	rotate_a(t_stack **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rotate_b(t_stack **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rotate_r(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
