/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:58:57 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/29 22:02:54 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	return (true);
}

bool	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	return (true);
}

bool	double_r_rotate(t_stack *a, t_stack *b)
{
	r_rotate(a);
	r_rotate(b);
	return (true);
}
