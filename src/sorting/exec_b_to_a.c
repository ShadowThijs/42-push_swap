/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:58:34 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/12/29 19:38:45 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>
#include <stdbool.h>

static bool	calc_cheap_rot(t_stack *a)
{
	t_node	*cur;
	t_node	*next;
	int		index;

	index = 0;
	cur = a->head_node;
	next = cur->next_node;
	while (next != NULL && cur->number > next->number)
	{
		cur = next;
		next = cur->next_node;
		index++;
	}
	if (index > (a->size / 2))
		return (true);
	return (false);
}

static void	final_rot_b(t_stack *b)
{
	bool	rot;

	if (!b->head_node)
		return ;
	rot = calc_cheap_rot(b);
	while (b->head_node->number < b->last_node->number)
	{
		if (rot)
			rrb(b);
		else
			rb(b);
	}
	if (rot)
		rrb(b);
	else
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
