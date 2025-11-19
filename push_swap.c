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
	t_node	*new_node;

	if (argc == 1)
		return (0);
	counter = 1;
	while (counter < argc)
	{
		if (!ft_strchr(argv[counter], ' '))
		{
			new_node = new_node(ft_atol(argv[counter]));
			printf("number %d: %d\n", counter, ft_atoi(argv[counter]));
		}
		else
		{
			temp = ft_split(argv[counter], ' ');
			split_counter = 0;
			while (temp[split_counter])
			{
				printf("number %d (part %d): %d\n", counter, split_counter + 1, ft_atoi(temp[split_counter]));
				split_counter++;
			}
		}
		counter++;
	}
	return (0);
}
