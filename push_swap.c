/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:53:09 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/19 21:44:46 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ops/operations.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		counter;
	char	**temp;
	int		split_counter;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_node	*node;

	if (argc == 1)
		return (0);
	counter = 1;
	stack_a = init_stack();
	stack_b = init_stack();
	while (counter < argc)
	{
		if (!ft_strchr(argv[counter], ' '))
		{
			node = new_node(ft_atol(argv[counter]));
			stack_add_back(stack_a, node);
			printf("number %d: %ld\n", counter, node->number);
		}
		else
		{
			temp = ft_split(argv[counter], ' ');
			split_counter = 0;
			while (temp[split_counter])
			{
				node = new_node(ft_atol(temp[split_counter]));
				stack_add_back(stack_a, node);
				printf("number %d (part %d): %ld\n", counter, split_counter + 1, node->number);
				split_counter++;
			}
		}
		counter++;
	}
	return (0);
}
