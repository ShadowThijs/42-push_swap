/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 00:17:07 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/21 00:17:09 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/operations.h"
#include "../include/sorting.h"
#include "../include/parser.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!parse_arguments(argc, argv, stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (stack_a->size != 3)
	{
		pb(stack_b, stack_a);
	}
	sort_list_three(stack_a);
	return (0);
}
