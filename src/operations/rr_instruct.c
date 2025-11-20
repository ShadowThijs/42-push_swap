/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:54:55 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/29 22:56:32 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include <unistd.h>

bool	rra(t_stack *a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
	return (true);
}

bool	rrb(t_stack *b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
	return (true);
}

bool	rrr(t_stack *a, t_stack *b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
	return (true);
}
