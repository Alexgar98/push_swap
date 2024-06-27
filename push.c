/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:28:13 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/15 11:52:40 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*second_src;

	if (!*src)
		return ;
	second_src = NULL;
	if ((*src)-> next)
	{
		second_src = (*src)-> next;
		second_src -> previous = NULL;
	}
	if (*dst)
	{
		(*dst)-> previous = *src;
		(*src)-> next = *dst;
	}
	else
		(*src)-> next = NULL;
	*dst = *src;
	*src = second_src;
}

void	push_a(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	push_b(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}
