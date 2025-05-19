/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:29:17 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 19:46:11 by dcastor          ###   ########.fr       */
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
	free_argv(argv);
}

static void	free_argv(char **argv)
{
	size_t	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
