/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:33:41 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/12/29 20:08:25 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H

# define SORTING_H

# include "operations.h"

typedef struct s_search
{
	int	index;
	int	value;
}	t_search;
typedef struct s_move_cost
{
	int		cost_a;
	int		cost_b;
	bool	rot_a;
	bool	rot_b;
	int		total_cost;
}	t_move_cost;
typedef struct s_search_result
{
	int		index;
	long	value;
}	t_search_result;

void			sort_list_three(t_stack *a);
void			push_to_b(t_stack *a, t_stack *b);
int				get_index_node(t_node *node, t_stack *stack);
int				rot_costs(int index, int stack_size);
int				find_target_b(int value, t_stack *b);
bool			should_rot(int index, int stack_size);
t_move_cost		calc_move_cost(t_node *node, t_stack *a, t_stack *b);
t_node			*find_cheapest_node(t_stack *a, t_stack *b);
void			exec_cheapest_move(t_node *node, t_stack *a, t_stack *b);
void			move_to_a(t_stack *a, t_stack *b);
t_search_result	find_closest_bigger_in_a(long value, t_stack *a);
t_search_result	find_smallest_in_stack(t_stack *stack);
void			free_stack(t_stack *a);
void			free_node(t_stack *a, t_node *node);

#endif
