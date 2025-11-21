/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:58:34 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 02:58:35 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>

static void	final_rot_b(t_stack *b)
{
	long	second;
	long	first;
	t_node	*node;

	if (!b->head_node)
		return ;
	node = b->head_node;
	first = node->number;
	second = node->next_node->number;
	while (first > second)
	{
		rb(b);
		node = b->head_node;
		second = node->next_node->number;
		first = node->number;
	}
	rb(b);
}

static int	get_target_pos(long b_val, t_stack *a)
{
	t_search_result	closest;
	t_search_result	smallest;

	closest = find_closest_bigger_in_a(b_val, a);
	if (closest.index == -1)
	{
		smallest = find_smallest_in_stack(a);
		return (smallest.index);
	}
	return (closest.index);
}

static void	rotate_to_pos(t_stack *a, int target_pos)
{
	int	rotations;

	rotations = rot_costs(target_pos, a->size);
	if (should_rot(target_pos, a->size))
	{
		while (rotations-- > 0)
			ra(a);
	}
	else
	{
		while (rotations-- > 0)
			rra(a);
	}
}

void	move_to_a(t_stack *a, t_stack *b)
{
	long			b_val;
	int				target_pos;
	t_search_result	smallest;

	final_rot_b(b);
	while (b->size != 0)
	{
		b_val = b->head_node->number;
		target_pos = get_target_pos(b_val, a);
		rotate_to_pos(a, target_pos);
		pa(a, b);
	}
	smallest = find_smallest_in_stack(a);
	rotate_to_pos(a, smallest.index);
}
