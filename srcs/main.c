/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:50:28 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 16:42:23 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	check_args(int argc, char *argv[]);

void	print_stack(t_node *head)
{
	t_node	*first;

	first = head;
	__builtin_printf("%d\n", head->value);
	head = head->next;
	while (head)
	{
		__builtin_printf("%d\n", head->value);
		head = head->next;
		if (first == head)
			return ;
	}
}

int	main(int argc, char *argv[])
{
	t_node	a_stack[1000];

	argv++;
	if (check_args(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	if (argc == 2)
		argv = ft_split((const char *)*argv, ' ');
	if (parse_values(argv, a_stack) == ERROR)
		return (EXIT_FAILURE);
	// __builtin_printf("===  ===\n");
	sort_stack(a_stack);
	return (0);
}

t_status	check_args(int argc, char *argv[])
{
	if (argc < 2)
		return (ERROR);
	if (argc == 2 && !argv[0][0])
		return (ERROR);
	return (SUCCESS);
}
