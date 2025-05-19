/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:43:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 16:33:49 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	setup_sort_context(t_sort_context *ctx, t_node *a_stack);
// static void	sort_and_restore(t_sort_context *ctx);

void	sort_stack(t_node *a_stack)
{
	t_sort_context	ctx;

	setup_sort_context(&ctx, a_stack);
	push_non_lis_to_b(&ctx);
	// __builtin_printf("==== Stack a of len %u ===== \n", ctx.a_len);
	// print_stack(ctx.a_stack);
	// __builtin_printf("==== Stack b of len %u ======\n", ctx.b_len);
	// print_stack(ctx.b_stack);
	// sort_and_restore(&ctx);
}

void	print_lis(t_sort_context *ctx)
{
	size_t	i;

	i = -1;
	__builtin_printf("=== Lis ===\n");
	while (++i < ctx->lis_len)
		__builtin_printf("%d\n", ctx->lis[i]);
	__builtin_printf("===  ===\n");
}
static void	setup_sort_context(t_sort_context *ctx, t_node *a_stack)
{
	// print_stack(a_stack);
	ft_bzero(ctx, sizeof(t_sort_context));
	ctx->a_stack = a_stack;
	ctx->a_len = stack_to_int_arr(a_stack, ctx->values);
	ctx->lis_len = find_lis(ctx->values, ctx->lis, ctx->a_len);
	ctx->pivot = find_pivot(ctx->values, ctx->a_len);
	// print_lis(ctx);
}

// static void	sort_and_restore(t_sort_context *ctx)
// {
// 	while (ctx->b_len)
// 	{
// 		// __builtin_printf("==== Stack a of len %u ===== \n", ctx->a_len);
// 		// print_stack(ctx->a_stack);
// 		// __builtin_printf("==== Stack b of len %u ======\n", ctx->b_len);
// 		// print_stack(ctx->b_stack);
// 		find_indexes(ctx);
// 		perform_cheapest_move(ctx);
// 	}
// 	// __builtin_printf("==== Stack a of len %u ===== \n", ctx->a_len);
// 	// print_stack(ctx->a_stack);
// 	// __builtin_printf("==== Stack b of len %u ======\n", ctx->b_len);
// 	// print_stack(ctx->b_stack);
// 	find_indexes(ctx);
// 	rotate_min_to_top(ctx);
// 	// __builtin_printf("==== Stack a of len %u ===== \n", ctx->a_len);
// 	// print_stack(ctx->a_stack);
// 	// __builtin_printf("==== Stack b of len %u ======\n", ctx->b_len);
// 	// print_stack(ctx->b_stack);
// 	// __builtin_printf("==== FINITO ====\n");
// }
