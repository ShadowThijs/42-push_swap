/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:22:10 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 02:22:11 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>

static t_search	find_biggest(t_stack *b)
{
	t_search	result;
	t_node		*current;
	int			index;

	result.value = INT_MIN;
	result.index = 0;
	index = 0;
	current = b->head_node;
	while (current != NULL)
	{
		if (current->number > result.value)
		{
			result.value = current->number;
			result.index = index;
		}
		current = current->next_node;
		index++;
	}
	return (result);
}

static t_search	find_closest_smallest(int value, t_stack *b)
{
	t_search	result;
	t_node		*current;
	int			index;

	result.value = INT_MIN;
	result.index = -1;
	index = 0;
	current = b->head_node;
	while (current != NULL)
	{
		if (current->number < value && current->number > result.value)
		{
			result.value = current->number;
			result.index = index;
		}
		current = current->next_node;
		index++;
	}
	return (result);
}

int	find_target_b(int value, t_stack *b)
{
	t_search	closest;
	t_search	biggest;

	if (!b->head_node)
		return (0);
	closest = find_closest_smallest(value, b);
	if (closest.index == -1)
	{
		biggest = find_biggest(b);
		return (biggest.index);
	}
	return (closest.index);
}
