/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:52:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 16:44:36 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_non_lis_to_b(t_sort_context *ctx)
{
	const size_t	size = ctx->a_len;
	size_t			i;

	// const size_t	max_to_push = size - ctx->lis_len;
	// size_t			pushed;
	// pushed = 0;
	i = -1;
	// while (++i < size && pushed < max_to_push)
	while (++i < size)
	{
		// if (is_in_lis(ctx, ctx->a_stack->value))
		// 	ra(ctx);
		// else if (ctx->a_stack->value > ctx->pivot)
		// {
		pb(ctx);
		// pushed++;
		// }
		// else
		// {
		// 	pb(ctx);
		// 	rb(ctx);
		// 	pushed++;
		// }
	}
}
