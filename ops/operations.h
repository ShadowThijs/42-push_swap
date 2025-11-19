/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:59:50 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/19 21:33:42 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H 

# define OPERATIONS_H

# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_node
{
	long			number;
	struct s_node	*next_node;
	struct s_node	*prev_node;
}	t_node;
typedef struct s_stack
{
	t_node	*head_node;
	t_node	*last_node;
	int		size;
}	t_stack;

bool	double_swap(t_stack *a, t_stack *b);
bool	swap(t_stack *stack);
bool	push(t_stack *a, t_stack *b);
void	two_node_rot(t_stack *a, t_node *head, t_node *last);
void	node_rot(t_stack *a, t_node *head, t_node *last);
void	node_rrot(t_stack *a, t_node *head, t_node *last);
bool	rotate(t_stack *a);
bool	r_rotate(t_stack *a);
void	single_node_push(t_stack *stack_1, t_stack *stack_2);
void	node_push(t_stack *stack_1, t_stack *stack_2);
bool	sa(t_stack *a);
bool	sb(t_stack *b);
bool	ss(t_stack *a, t_stack *b);
bool	pa(t_stack *a, t_stack *b);
bool	pb(t_stack *b, t_stack *a);
bool	ra(t_stack *a);
bool	rb(t_stack *b);
bool	rr(t_stack *a, t_stack *b);
bool	rra(t_stack *a);
bool	rrb(t_stack *b);
bool	rrr(t_stack *a, t_stack *b);
t_node	*new_node(long content);
void	init_stack(t_stack *stack);
void	stack_add_back(t_stack *stack, t_node *node);

#endif
