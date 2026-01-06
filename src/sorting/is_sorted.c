/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:35:36 by tlogtenb          #+#    #+#             */
/*   Updated: 2026/01/06 15:53:00 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

static bool	elem_in_b(t_stack *b)
{
	if (!b)
		return (false);
	if (b->size > 0)
		return (true);
	if (b->head_node == NULL && b->last_node == NULL)
		return (true);
	return (false);
}

bool	input_sorted(t_stack *a, t_stack *b)
{
	t_node	*head;
	t_node	*next;
	t_node	*last;

	if (b)
		return (elem_in_b(b));
	if (a->size <= 1)
		return (true);
	head = a->head_node;
	last = a->last_node;
	next = head->next_node;
	while (next != last)
	{
		if (head->number > next->number)
			return (false);
		head = next;
		next = head->next_node;
	}
	if (head->number > next->number)
		return (false);
	return (true);
}
