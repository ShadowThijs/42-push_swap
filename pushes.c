/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:52:45 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/23 15:52:45 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stddef.h>

bool	push(t_stack *a, t_stack *b)
{
	t_node	*head_b;
	t_node	*head_a;

	if (!b->head_node)
		return (0);
	head_b = b->head_node;
	head_a = a->head_node;
	a->head_node = head_b;
	if (head_b->next_node)
		head_b->next_node->prev_node = NULL;
	b->head_node = head_b->next_node;
	if (!head_a)
		a->head_node->next_node = NULL;
	else
		a->head_node->next_node = head_a;
	head_a->prev_node = head_b;
	
	return (1);
}
