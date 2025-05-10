/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:05:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 14:28:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_value(void *content)
{
	const t_value	*v = content;

	__builtin_printf("V: %d, I: %d\n", v->value, v->index);
}

int	main(int argc, char *argv[])
{
	t_stack	*a_stack;

	(void)argc;
	a_stack = parse_strs_to_stack(++argv);
	if (!a_stack)
		return (process_error());
	if (radix_sort(a_stack) == ERROR)
		return (process_error()); // TODO: free_everythin
	__builtin_printf("Stack size %d\n", a_stack->size);
	ft_lstiter(a_stack->top, print_value);
	return (0);
}
