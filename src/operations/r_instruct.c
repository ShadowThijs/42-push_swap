/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 22:52:29 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/10/29 22:54:46 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/operations.h"
#include <unistd.h>

bool	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
	return (true);
}

bool	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
	return (true);
}

bool	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	return (true);
}
