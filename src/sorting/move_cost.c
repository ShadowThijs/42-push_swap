/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:22:53 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 02:22:54 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"

t_move_cost	calc_move_cost(t_node *node, t_stack *a, t_stack *b)
{
	t_move_cost	cost;
	int			node_index;
	int			target_index;

	node_index = get_index_node(node, a);
	cost.cost_a = rot_costs(node_index, a->size);
	cost.rot_a = should_rot(node_index, a->size);
	target_index = find_target_b(node->number, b);
	cost.cost_b = rot_costs(target_index, b->size);
	cost.rot_b = should_rot(target_index, b->size);
	if (cost.rot_a == cost.rot_b)
	{
		if (cost.cost_a > cost.cost_b)
			cost.total_cost = cost.cost_a;
		else
			cost.total_cost = cost.cost_b;
	}
	else
		cost.total_cost = cost.cost_a + cost.cost_b;
	return (cost);
}
