/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:04:45 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/13 11:58:57 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*highest_lower(t_stack *elem, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*lower;

	if (elem -> cont < get_min(*stack)-> cont)
		return (get_max(*stack));
	else
	{
		aux = *stack;
		lower = aux;
		while (aux)
		{
			if (lower -> cont > elem -> cont
				&& aux -> cont < lower -> cont)
				lower = aux;
			if (lower -> cont < aux -> cont
				&& aux -> cont < elem -> cont)
				lower = aux;
			aux = aux -> next;
		}
	}
	return (lower);
}

t_stack	*lowest_higher(t_stack *elem, t_stack **stack)
{
	t_stack	*aux;
	t_stack	*higher;

	if (elem -> cont > get_max(*stack)-> cont)
		return (get_min(*stack));
	else
	{
		aux = *stack;
		higher = aux;
		while (aux)
		{
			if (higher -> cont < elem -> cont
				&& aux -> cont > higher -> cont)
				higher = aux;
			if (higher -> cont > aux -> cont
				&& aux -> cont > elem -> cont)
				higher = aux;
			aux = aux -> next;
		}
	}
	return (higher);
}
