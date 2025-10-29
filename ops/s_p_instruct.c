/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:47:16 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/29 22:52:23 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
	return (true);
}

bool	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
	return (true);
}

bool	ss(t_stack *a, t_stack *b)
{
	double_swap(a, b);
	write(1, "ss\n", 3);
	return (true);
}

bool	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
	return (true);
}

bool	pb(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pb\n", 3);
	return (true);
}
