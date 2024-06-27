/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:32:41 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/10 11:34:11 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_length(t_stack *stack)
{
	int		i;

	i = 0;
	if (stack)
	{
		while (stack)
		{
			i++;
			stack = stack -> next;
		}
	}
	return (i);
}

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack -> next == NULL)
		return (stack);
	else
		return (get_last(stack -> next));
}

t_stack	*get_first(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack -> previous == NULL)
		return (stack);
	else
		return (get_first(stack -> previous));
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*next_node;
	t_stack	*min;

	if (!stack -> next)
		return (stack);
	min = stack;
	next_node = stack -> next;
	while (next_node)
	{
		if (next_node -> cont < min -> cont)
			min = next_node;
		next_node = next_node -> next;
	}
	return (min);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*next_node;
	t_stack	*max;

	if (!stack -> next)
		return (stack);
	max = stack;
	next_node = stack -> next;
	while (next_node)
	{
		if (next_node -> cont > max -> cont)
			max = next_node;
		next_node = next_node -> next;
	}
	return (max);
}
