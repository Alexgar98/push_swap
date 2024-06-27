/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:28:37 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/16 19:37:53 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack	*create_from_argc(int argc, char **argv)
{
	int		i;
	int		*stack;

	stack = malloc(sizeof(int) * (argc - 1));
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_all_num(argv[i]) || ft_atol(argv[i]) < INT_MIN
			|| ft_atol(argv[i]) > INT_MAX)
		{
			free(stack);
			throw_empty_error();
		}
		stack[i - 1] = (int)(ft_atol(argv[i]));
		i++;
	}
	if (!stack || !check_all_unequal(stack, argc - 1))
	{
		free(stack);
		throw_empty_error();
	}
	return (new_stack(stack, argc));
}

t_stack	*create_from_split(int len, char **split)
{
	int	i;
	int	*stack;

	stack = malloc(sizeof(int) * (len));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (ft_atol(split[i]) < INT_MIN || ft_atol(split[i]) > INT_MAX)
		{
			free(stack);
			return (NULL);
		}
		stack[i] = (int)(ft_atol(split[i]));
		i++;
	}
	if (!stack || !check_all_unequal(stack, i))
	{
		free(stack);
		throw_empty_error();
	}
	return (new_stack(stack, i + 1));
}

t_stack	*empty_node(int *nbrs)
{
	free(nbrs);
	return (NULL);
}

t_stack	*new_stack(int *nbrs, int argc)
{
	t_stack		*new;
	t_stack		*next;
	static int	index = 0;
	int			content;

	content = nbrs[index];
	if (index++ < argc - 1)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			throw_empty_error();
		new -> next = new_stack(nbrs, argc);
		new -> cont = content;
		new -> previous = NULL;
		if (new -> next)
		{
			next = new -> next;
			next -> previous = new;
		}
	}
	else
		return (empty_node(nbrs));
	return (new);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack -> next)
			free_stack(stack -> next);
		free(stack);
	}
}
