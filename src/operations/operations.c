/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:52:55 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/29 22:04:18 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

bool	swap(t_stack *stack)
{
	t_node	*head;
	t_node	*next;

	if (!stack->head_node)
		return (false);
	head = stack->head_node;
	if (!head->next_node)
		return (false);
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
	return (true);
}

bool	push(t_stack *stack_1, t_stack *stack_2)
{
	if (!stack_2->head_node)
		return (false);
	if (stack_2->head_node == stack_2->last_node)
		single_node_push(stack_1, stack_2);
	else
		node_push(stack_1, stack_2);
	return (true);
}

bool	rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*last;

	if (!stack->head_node)
		return (false);
	if (stack->head_node == stack->last_node)
		return (true);
	head = stack->head_node;
	last = stack->last_node;
	if (head->next_node == last)
		two_node_rot(stack, head, last);
	else
		node_rot(stack, head, last);
	return (true);
}

bool	r_rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*last;

	if (!stack->head_node)
		return (false);
	if (stack->head_node == stack->last_node)
		return (true);
	head = stack->head_node;
	last = stack->last_node;
	if (head->next_node == last)
		two_node_rot(stack, head, last);
	else
		node_rrot(stack, head, last);
	return (true);
}
