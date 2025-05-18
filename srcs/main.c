/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:05:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 12:42:41 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	check_args(int argc, char **argv);

int	main(int argc, char *argv[])
{
	t_node	*a_stack;
	t_node	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (check_args(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	if (argc == 2)
		argv = ft_split((const char *)argv, ' ');
	if (initialize_stack(&a_stack, &argv[1]) == ERROR)
		return (free_stack(a_stack), EXIT_FAILURE);
	if (!stack_sorted(a_stack))
	{
		if (stack_len(a_stack) == 2)
			swap_a(&a_stack);
		else if (stack_len(a_stack) == 3)
			sort_three(&a_stack);
	}
	free_stack(a_stack);
	return (EXIT_SUCCESS);
}

t_status	check_args(int argc, char **argv)
{
	if (argc < 2)
		return (ERROR);
	if (argc == 2 && !argv[1][0])
		return (ERROR);
	return (SUCCESS);
}
