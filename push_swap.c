/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:46:57 by alexigar          #+#    #+#             */
/*   Updated: 2024/05/16 19:28:34 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '-')
			i++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			i++;
	}
	return (1);
}

int	check_all_unequal(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if ((i != j) && (array[i] == array[j]))
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_stack	*split_string(char *arg)
{
	t_stack	*stack;
	char	**split;
	int		i;

	stack = NULL;
	split = ft_split(arg, ' ');
	if (!split)
		throw_empty_error();
	i = 0;
	while (split[i])
	{
		if (!is_all_num(split[i]))
			throw_split_error(split);
		i++;
	}
	stack = create_from_split(i, split);
	free_split(split);
	if (!stack)
		throw_empty_error();
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0' || !argv[1][0])
		exit(EXIT_FAILURE);
	if (argc == 2)
		a = split_string(argv[1]);
	else
		a = create_from_argc(argc, argv);
	order_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	exit(EXIT_SUCCESS);
}
