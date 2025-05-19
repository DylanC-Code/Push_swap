/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:50:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 14:52:38 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_in_lis(t_sort_context *ctx, int value)
{
	return (ft_int_in_array(ctx->lis, ctx->lis_len, value));
}

t_node	*find_min_node(t_node *stack, size_t size)
{
	t_node	*min;
	size_t	i;

	min = stack;
	i = 0;
	while (++i < size)
	{
		stack = stack->next;
		if (stack->value < min->value)
			min = stack;
	}
	return (min);
}

void	rotate_min_to_top(t_sort_context *ctx)
{
	t_node	*min;

	min = find_min_node(ctx->a_stack, ctx->a_len);
	while (ctx->a_stack != min)
	{
		if (min->above_median)
			ra(ctx);
		else
			rra(ctx);
	}
}
