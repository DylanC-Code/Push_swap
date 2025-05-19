/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_indexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:02:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 13:08:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_indexes(t_sort_context *ctx)
{
	const unsigned int	b_median = ctx->b_len / 2;
	const unsigned int	a_median = ctx->a_len / 2;
	size_t				i;
	t_node				*current;

	i = -1;
	current = ctx->a_stack;
	while (++i < ctx->a_len)
	{
		current->index = i;
		if (i < a_median)
			current->above_median = true;
		current = current->next;
	}
	i = -1;
	current = ctx->b_stack;
	while (++i < ctx->b_len)
	{
		current->index = i;
		if (i < b_median)
			current->above_median = true;
		current = current->next;
	}
}
