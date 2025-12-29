/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:03:37 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/12/29 20:08:44 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include <stdlib.h>

void	free_node(t_stack *a, t_node *node)
{
	node->next_node = NULL;
	node->prev_node = NULL;
	free(node);
	node = NULL;
	a->size -= 1;
	return ;
}

void	free_stack(t_stack *a)
{
	t_node	*next;

	while (a->size > 0)
	{
		next = a->head_node->next_node;
		free_node(a, a->head_node);
		a->head_node = next;
	}
	a->head_node = NULL;
	a->last_node = NULL;
	free(a);
	a = NULL;
}
