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

void	sort_list_three(t_stack *stack_a)
{
	long	first_a;
	long	next_a;
	long	last_a;

	first_a = stack_a->head_node->number;
	next_a = stack_a->head_node->next_node->number;
	last_a = stack_a->last_node->number;
	if (first_a < next_a && next_a > last_a && first_a < last_a)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (first_a > next_a && next_a < last_a && first_a < last_a)
		sa(stack_a);
	else if (first_a < next_a && next_a > last_a && first_a > last_a)
		rra(stack_a);
	else if (first_a > next_a && next_a < last_a && first_a > last_a)
		ra(stack_a);
	else if (first_a > next_a && next_a > last_a && first_a > last_a)
	{
		sa(stack_a);
		rra(stack_a);
	}
}
