/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlogtenb <tlogtenb@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:14:43 by tlogtenb          #+#    #+#             */
/*   Updated: 2025/11/20 22:15:22 by tlogtenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "operations.h"
# include "../libft/libft.h"
# include <stdbool.h>

bool	parse_arguments(int argc, char **argv, t_stack *stack_a);

#endif
