/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:14:39 by tlogtenb          #+#    #+#             */
/*   Updated: 2026/01/06 16:01:21 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <limits.h>

static bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] != '-' && str[i] != '+')
			|| (str[i] > '9' && str[i] != '-' && str[i] != '+'))
			return (false);
		i++;
	}
	return (true);
}

static bool	parse_checks(char *value, t_stack *stack)
{
	t_node	*node;

	if (!is_valid_number(value))
		return (false);
	if (ft_atol(value) > 2147483647 || ft_atol(value) < -2147483648)
		return (false);
	if (!stack->head_node)
		return (true);
	node = stack->head_node;
	while (node->next_node)
	{
		if (node->number == ft_atol(value))
			return (false);
		node = node->next_node;
	}
	if (node->number == ft_atol(value))
		return (false);
	return (true);
}

static bool	parse_string(char **argv, t_stack *stack_a, int counter)
{
	char	**temp;
	int		split_counter;
	t_node	*node;

	temp = ft_split(argv[counter], ' ');
	split_counter = 0;
	while (temp[split_counter])
	{
		if (!parse_checks(temp[split_counter], stack_a))
			return (false);
		node = new_node(ft_atol(temp[split_counter]));
		stack_add_back(stack_a, node);
		split_counter++;
	}
	return (true);
}

bool	parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		counter;
	t_node	*node;

	counter = 1;
	while (counter < argc)
	{
		if (!ft_strchr(argv[counter], ' '))
		{
			if (!parse_checks(argv[counter], stack_a))
				return (false);
			node = new_node(ft_atol(argv[counter]));
			stack_add_back(stack_a, node);
		}
		else
			if (!parse_string(argv, stack_a, counter))
				return (false);
		counter++;
	}
	return (true);
}
