/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:30 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/15 11:26:18 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	throw_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	throw_empty_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	throw_split_error(char **split)
{
	free_split(split);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
