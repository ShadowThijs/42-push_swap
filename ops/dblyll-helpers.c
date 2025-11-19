/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblyll-helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:13:38 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/19 21:26:07 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include <stdlib.h>

t_node	*new_node(long content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = content;
	node->next_node = NULL;
	node->prev_node = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->last_node = NULL;
	stack->head_node = NULL;
	stack->size = 0;
	return ;
}

void	stack_add_back(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	if (stack->size == 0 && stack->head_node == NULL
		&& stack->last_node == NULL)
	{
		stack->head_node = node;
		stack->last_node = node;
		stack->size = 1;
		return ;
	}
	stack->last_node->next_node = node;
	node->prev_node = stack->last_node;
	stack->last_node = node;
	stack->size += 1;
	return ;
}
