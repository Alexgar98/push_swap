/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:58:16 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/14 12:15:25 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *elem, t_stack **stack)
{
	int		position;
	t_stack	*aux;

	position = 0;
	aux = *stack;
	while (elem -> cont != aux -> cont)
	{
		aux = aux -> next;
		position++;
	}
	return (position);
}

int	get_highest_lower(t_stack *elem, t_stack **stack)
{
	int		pos_lower;
	t_stack	*lower;

	lower = highest_lower(elem, stack);
	pos_lower = get_position(lower, stack);
	return (pos_lower);
}

int	get_cost(t_stack *elem, t_stack **a, t_stack **b)
{
	int		pos;
	int		cost_top_elem;
	int		pos_high_lower;
	int		cost_high_lower;

	pos = get_position(elem, a);
	pos_high_lower = get_highest_lower(elem, b);
	if (pos < get_length(*a) / 2)
		cost_top_elem = pos;
	else
		cost_top_elem = get_length(*a) - pos;
	if (pos_high_lower < (get_length(*b) / 2))
		cost_high_lower = pos_high_lower;
	else
		cost_high_lower = get_length(*b) - pos_high_lower;
	if ((pos < (get_length(*a) / 2) && pos_high_lower < (get_length(*b) / 2))
		|| (pos > get_length(*a) / 2 && pos_high_lower > (get_length(*b) / 2)))
	{
		if (cost_top_elem > cost_high_lower)
			return (cost_top_elem);
		else
			return (cost_high_lower);
	}
	else
		return (cost_top_elem + cost_high_lower);
}

t_stack	*get_lower_cost(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		lower;
	t_stack	*lowest_cost;

	aux = (*a)-> next;
	lower = get_cost(*a, a, b);
	lowest_cost = *a;
	while (aux)
	{
		if (get_cost(aux, a, b) < lower)
		{
			lower = get_cost(aux, a, b);
			lowest_cost = aux;
		}
		aux = aux -> next;
	}
	return (lowest_cost);
}
