/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:05:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/09 22:00:33 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char *argv[])
{
	t_stack	*a_stack;
	t_node	*next;

	(void)argc;
	a_stack = parse_strs_to_stack(++argv);
	if (!a_stack)
		return (process_error());
	next = a_stack->top;
	__builtin_printf("Stack size %d\n", a_stack->size);
	while (next)
	{
		__builtin_printf("%d\n", next->value);
		next = next->next;
	}
	return (0);
}
