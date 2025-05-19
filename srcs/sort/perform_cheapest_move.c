/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_cheapest_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:12:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 15:12:28 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_forward(t_sort_context *ctx, t_node *cheapest, int i_a,
		int i_b)
{
	while (ctx->a_stack != cheapest->target && ctx->b_stack != cheapest)
	{
		rr(ctx);
		i_a--;
		i_b--;
	}
}

static void	rotate_both_reverse(t_sort_context *ctx, t_node *cheapest, int i_a,
		int i_b)
{
	while (ctx->a_stack != cheapest->target && ctx->b_stack != cheapest)
	{
		rrr(ctx);
		i_a++;
		i_b++;
	}
}

static void	rotate_both_stacks(t_sort_context *ctx, t_node *cheapest)
{
	int	i_a;
	int	i_b;
	int	half_a;
	int	half_b;

	i_a = cheapest->target->index;
	i_b = cheapest->index;
	half_a = ctx->a_len / 2;
	half_b = ctx->b_len / 2;
	if (i_a <= half_a && i_b <= half_b)
		rotate_both_forward(ctx, cheapest, i_a, i_b);
	else if (i_a > half_a && i_b > half_b)
		rotate_both_reverse(ctx, cheapest, i_a, i_b);
}

static void	finish_stack_rotation(t_sort_context *ctx, t_node *node, bool is_a)
{
	int	index;
	int	half;

	index = is_a ? node->target->index : node->index;
	half = is_a ? ctx->a_len / 2 : ctx->b_len / 2;
	while ((is_a && ctx->a_stack != node->target) || (!is_a
			&& ctx->b_stack != node))
	{
		if (index <= half)
			is_a ? ra(ctx) : rb(ctx);
		else
			is_a ? rra(ctx) : rrb(ctx);
	}
}

void	perform_cheapest_move(t_sort_context *ctx)
{
	t_node	*cheapest;

	cheapest = find_cheapest_move(ctx);
	rotate_both_stacks(ctx, cheapest);
	finish_stack_rotation(ctx, cheapest, false);
	finish_stack_rotation(ctx, cheapest, true);
	pa(ctx);
}
