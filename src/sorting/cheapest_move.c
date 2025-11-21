/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:30:42 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 02:30:43 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>

t_node	*find_cheapest_node(t_stack *a, t_stack *b)
{
	t_node		*current;
	t_node		*cheapest;
	t_move_cost	current_cost;
	int			best_cost;

	current = a->head_node;
	cheapest = current;
	best_cost = INT_MAX;
	while (current != NULL)
	{
		current_cost = calc_move_cost(current, a, b);
		if (current_cost.total_cost < best_cost)
		{
			best_cost = current_cost.total_cost;
			cheapest = current;
		}
		current = current->next_node;
	}
	return (cheapest);
}
