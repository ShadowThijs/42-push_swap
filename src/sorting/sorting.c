/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:33:24 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/20 23:33:26 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include "../../include/sorting.h"
#include <limits.h>

void	sort_list_three(t_stack *a)
{
	long	first_a;
	long	next_a;
	long	last_a;

	first_a = a->head_node->number;
	next_a = a->head_node->next_node->number;
	last_a = a->last_node->number;
	if (first_a < next_a && next_a > last_a && first_a < last_a)
	{
		sa(a);
		ra(a);
	}
	else if (first_a > next_a && next_a < last_a && first_a < last_a)
		sa(a);
	else if (first_a < next_a && next_a > last_a && first_a > last_a)
		rra(a);
	else if (first_a > next_a && next_a < last_a && first_a > last_a)
		ra(a);
	else if (first_a > next_a && next_a > last_a && first_a > last_a)
	{
		sa(a);
		rra(a);
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	if (a->size > 3)
	{
		pb(b, a);
		pb(b, a);
	}
	while (a->size > 3)
	{
		cheapest = find_cheapest_node(a, b);
		exec_cheapest_move(cheapest, a, b);
	}
}
