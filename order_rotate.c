/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:35:42 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/03 13:07:33 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_rotate(t_stack **a, t_stack **b)
{
	int	pos;

	pos = almost_ordered(a, b);
	if (pos)
	{
		if (pos >= (get_length(*a) / 2))
		{
			while (!already_ordered(a))
				reverse_rotate_a(a);
		}
		else
		{
			while (!already_ordered(a))
				rotate_a(a);
		}
		free_stack(*a);
		exit(EXIT_SUCCESS);
	}
	else
		return ;
}
