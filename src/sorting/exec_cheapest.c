/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:35:56 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 02:35:57 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>

static void	exec_rr(t_move_cost cost, t_stack *a, t_stack *b)
{
	while (cost.cost_a > 0 && cost.cost_b > 0)
	{
		rr(a, b);
		cost.cost_a--;
		cost.cost_b--;
	}
	while (cost.cost_a > 0)
	{
		ra(a);
		cost.cost_a--;
	}
	while (cost.cost_b > 0)
	{
		rb(b);
		cost.cost_b--;
	}
}

static void	exec_rrr(t_move_cost cost, t_stack *a, t_stack *b)
{
	while (cost.cost_a > 0 && cost.cost_b > 0)
	{
		rrr(a, b);
		cost.cost_a--;
		cost.cost_b--;
	}
	while (cost.cost_a > 0)
	{
		rra(a);
		cost.cost_a--;
	}
	while (cost.cost_b > 0)
	{
		rrb(b);
		cost.cost_b--;
	}
}

static void	exec_rot_a(t_move_cost cost, t_stack *a)
{
	if (cost.rot_a)
	{
		while (cost.cost_a > 0)
		{
			ra(a);
			cost.cost_a--;
		}
	}
	else
	{
		while (cost.cost_a > 0)
		{
			rra(a);
			cost.cost_a--;
		}
	}
}

static void	exec_rot_b(t_move_cost cost, t_stack *b)
{
	if (cost.rot_b)
	{
		while (cost.cost_b > 0)
		{
			rb(b);
			cost.cost_b--;
		}
	}
	else
	{
		while (cost.cost_b > 0)
		{
			rrb(b);
			cost.cost_b--;
		}
	}
}

void	exec_cheapest_move(t_node *node, t_stack *a, t_stack *b)
{
	t_move_cost	cost;

	cost = calc_move_cost(node, a, b);
	if (cost.rot_a && cost.rot_b)
		exec_rr(cost, a, b);
	else if (!cost.rot_a && !cost.rot_b)
		exec_rrr(cost, a, b);
	else
	{
		exec_rot_a(cost, a);
		exec_rot_b(cost, b);
	}
	pb(b, a);
}
