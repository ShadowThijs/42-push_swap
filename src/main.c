/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:17:07 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/12/29 20:07:58 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/operations.h"
#include "../include/sorting.h"
#include "../include/parser.h"
#include <unistd.h>

int	run_checks(int argc, char **argv, t_stack *a)
{
	if (!parse_arguments(argc, argv, a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (a->size == 2)
	{
		if (a->head_node->number > a->last_node->number)
			sa(a);
		return (0);
	}
	if (a->size == 1)
		return (0);
	return (2);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	if (run_checks(argc, argv, a) != 2)
		return (run_checks(argc, argv, a));
	push_to_b(a, b);
	sort_list_three(a);
	move_to_a(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
