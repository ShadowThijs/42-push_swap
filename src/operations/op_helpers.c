/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:53:05 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/29 21:58:26 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"

void	single_node_push(t_stack *stack_1, t_stack *stack_2)
{
	t_node	*head_a;
	t_node	*head_b;

	head_b = stack_2->head_node;
	stack_2->head_node = NULL;
	stack_2->last_node = NULL;
	stack_2->size = 0;
	if (!stack_1->head_node)
	{
		stack_1->head_node = head_b;
		stack_1->last_node = head_b;
		stack_1->size = 1;
		return ;
	}
	head_a = stack_1->head_node;
	head_a->prev_node = head_b;
	head_b->next_node = head_a;
	stack_1->head_node = head_b;
	stack_1->size += 1;
}

void	node_push(t_stack *stack_1, t_stack *stack_2)
{
	t_node	*head_a;
	t_node	*head_b;

	head_b = stack_2->head_node;
	head_a = stack_1->head_node;
	head_b->next_node->prev_node = NULL;
	stack_2->head_node = head_b->next_node;
	stack_2->size -= 1;
	stack_1->head_node = head_b;
	head_b->prev_node = NULL;
	if (!head_a)
	{
		stack_1->last_node = head_b;
		head_b->next_node = NULL;
		stack_1->size = 1;
		return ;
	}
	head_b->next_node = head_a;
	head_a->prev_node = head_b;
	stack_1->size += 1;
}

void	two_node_rot(t_stack *stack, t_node *head, t_node *last)
{
	last->prev_node = NULL;
	last->next_node = head;
	head->prev_node = last;
	head->next_node = NULL;
	stack->head_node = last;
	stack->last_node = head;
}

void	node_rot(t_stack *stack, t_node *head, t_node *last)
{
	t_node	*next;

	next = head->next_node;
	last->next_node = head;
	head->prev_node = last;
	next->prev_node = NULL;
	head->next_node = NULL;
	stack->head_node = next;
	stack->last_node = head;
}

void	node_rrot(t_stack *stack, t_node *head, t_node *last)
{
	t_node	*prev_last;

	prev_last = last->prev_node;
	last->prev_node = NULL;
	last->next_node = head;
	head->prev_node = last;
	prev_last->next_node = NULL;
	stack->head_node = last;
	stack->last_node = prev_last;
}
