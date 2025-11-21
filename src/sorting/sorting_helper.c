/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:50:39 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 01:50:40 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>
#include <stdbool.h>

int	get_index_node(t_node *node, t_stack *stack)
{
	int		index;
	t_node	*temp_node;

	index = 0;
	if (!stack->head_node)
		return (-1);
	temp_node = stack->head_node;
	while (temp_node != node)
	{
		temp_node = temp_node->next_node;
		index++;
	}
	return (index);
}

int	rot_costs(int index, int stack_size)
{
	int	rot;
	int	rrot;

	rot = index;
	rrot = stack_size - index;
	if (rot <= rrot)
		return (rot);
	else
		return (rrot);
}

bool	should_rot(int index, int stack_size)
{
	return (index <= stack_size - index);
}

t_search_result	find_smallest_in_stack(t_stack *stack)
{
	t_search_result	result;
	t_node			*current;
	int				idx;

	result.value = LONG_MAX;
	result.index = 0;
	idx = 0;
	current = stack->head_node;
	while (current != NULL)
	{
		if (current->number < result.value)
		{
			result.value = current->number;
			result.index = idx;
		}
		current = current->next_node;
		idx++;
	}
	return (result);
}

t_search_result	find_closest_bigger_in_a(long value, t_stack *a)
{
	t_search_result	result;
	t_node			*current;
	int				idx;

	result.value = LONG_MAX;
	result.index = -1;
	idx = 0;
	current = a->head_node;
	while (current != NULL)
	{
		if (current->number > value && current->number < result.value)
		{
			result.value = current->number;
			result.index = idx;
		}
		current = current->next_node;
		idx++;
	}
	return (result);
}
