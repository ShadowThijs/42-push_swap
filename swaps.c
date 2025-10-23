/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:29 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/23 15:50:57 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdbool.h>

bool	swap(t_stack *stack)
{
	t_node	*head;
	t_node	*next;

	if (!stack->head_node)
		return (0);
	head = stack->head_node;
	if (!head->next_node)
		return (0);
	next = head->next_node;
	if (next->next_node)
		next->next_node->prev_node = head;
	if (!next->next_node)
		stack->last_node = head;
	head->next_node = next->next_node;
	head->prev_node = next;
	next->next_node = head;
	next->prev_node = NULL;
	stack->head_node = next;
	return (1);
}

bool	double_swap(t_stack *a, t_stack *b)
{
	bool	a_swap;
	bool	b_swap;

	a_swap = swap(a);
	b_swap = swap(b);
	if (swap(a) && swap(b))
		return (1);
	return (0);
}
