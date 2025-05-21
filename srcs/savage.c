/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:29:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/21 11:38:53 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_argv(char **argv);

void	free_savage(t_stack *a_stack, t_stack *b_stack, t_info *info,
		char **argv)
{
	t_stack	*next;
	t_stack	*prev;

	next = a_stack;
	free_argv(argv);
	while (next)
	{
		prev = next;
		next = next->next;
		free(prev);
	}
	next = b_stack;
	while (next)
	{
		prev = next;
		next = next->next;
		free(prev);
	}
	if (info)
		free(info);
}

static void	free_argv(char **argv)
{
	size_t	i;

	i = -1;
	while (argv && argv[++i])
		free(argv[i]);
	if (argv)
		free(argv);
}

void	print_savage(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b || stack_is_sorted(stack_a) == ERROR)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
