/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:43:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 11:18:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void				calculate_lis(t_lis_context *dst, t_node *stack);

void	init_b_stack(t_sort_context *ctx)
{
	size_t	i;

	i = -1;
	while (++i < ctx->size)
	{
		if (ft_int_in_array(ctx->lis, ctx->lis_len, ctx->a_stack->value))
			ra(ctx);
        else if (ctx->a_stack->value > ctx->pivot)
            pb(ctx);
        else {
            pb(ctx);
            rrb(ctx);
        }
	}
}

void	sort_stack(t_node *a_stack)
{
	t_sort_context	ctx;

	// size_t			i;
	ft_bzero(&ctx, sizeof(t_sort_context));
	ctx.a_stack = a_stack;
	ctx.size = stack_to_int_arr(a_stack, ctx.values);
	ctx.lis_len = find_lis(ctx.values, ctx.lis, ctx.size);
	ctx.pivot = find_pivot(ctx.values, ctx.size);
	init_b_stack(&ctx);
	// int		values[1000];
	// size_t	size;
	// int		lis[1000];
	// size_t	lis_len;
	// size = stack_to_int_arr(a_stack, values);
	// lis_len = ft_lis_len(values, size);
	// lis_len = initialize_lis(lis, a_stack);
}
