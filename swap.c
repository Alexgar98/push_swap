/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:20:53 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/15 11:52:49 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (get_length(*stack) > 1)
	{
		first = *stack;
		second = first -> next;
		third = second -> next;
		first -> previous = second;
		first -> next = second -> next;
		second -> previous = NULL;
		second -> next = first;
		third -> previous = first;
		*stack = second;
	}
}

void	swap_a(t_stack **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	swap_b(t_stack **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	swap_s(t_stack **a, t_stack **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
