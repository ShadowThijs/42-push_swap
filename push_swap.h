/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:59:50 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/23 15:19:43 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

typedef struct s_node
{
	int				number;
	struct s_node	*next_node;
	struct s_node	*prev_node;
}	t_node;
typedef struct s_stack
{
	t_node	*head_node;
	t_node	*last_node;
	int		size;
}	t_stack;

#endif // !PUSH_SWAP_H
