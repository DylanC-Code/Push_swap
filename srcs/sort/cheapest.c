/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:53:48 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 15:41:28 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_best_target(t_node *stack, unsigned int size, int val)
{
	t_node	*cur;
	t_node	*best;
	size_t	i;

	i = 0;
	cur = stack->next;
	best = stack;
	while (++i < size)
	{
		if (best->value < val)
			best = cur;
		if (cur->value > val && cur->value < best->value)
			best = cur;
		cur = cur->next;
	}
	if (best->value < val)
		return (find_min_node(stack, size));
	return (best);
}

void	calculate_move_number(t_sort_context *ctx, t_node *node, size_t index)
{
	const size_t	median = ctx->b_len / 2;

	if (index < median)
		node->move_number = index;
	else
		node->move_number = ctx->b_len - index;
	node->target = find_best_target(ctx->a_stack, ctx->a_len, node->value);
	if (node->target->above_median)
		node->move_number += node->target->index;
	else
		node->move_number += ctx->a_len - node->target->index;
}

t_node	*find_cheapest_move(t_sort_context *ctx)
{
	t_node	*cur;
	t_node	*best;
	size_t	i;

	cur = ctx->b_stack;
	best = cur;
	i = 0;
	while (i < ctx->b_len)
	{
		calculate_move_number(ctx, cur, i);
		if (cur->move_number < best->move_number)
			best = cur;
		cur = cur->next;
		i++;
	}
	return (best);
}

// void	perform_cheapest_move(t_sort_context *ctx)
// {
// 	t_node	*cheapest;

// 	cheapest = find_cheapest_move(ctx);
// 	while (ctx->b_stack != cheapest)
// 	{
// 		if (cheapest->above_median)
// 			rb(ctx);
// 		else
// 			rrb(ctx);
// 	}
// 	while (ctx->a_stack != cheapest->target)
// 	{
// 		if (cheapest->target->above_median)
// 			ra(ctx);
// 		else
// 			rra(ctx);
// 	}
// 	pa(ctx);
// }

// void	perform_cheapest_move(t_sort_context *ctx)
// {
// 	t_node	*cheapest;
// 	int		i_a;
// 	int		i_b;
// 	int		half_a;
// 	int		half_b;

// 	cheapest = find_cheapest_move(ctx);
// 	i_a = cheapest->target->index;
// 	i_b = cheapest->index;
// 	half_a = ctx->a_len / 2;
// 	half_b = ctx->b_len / 2;
// 	while (ctx->a_stack != cheapest->target && ctx->b_stack != cheapest)
// 	{
// 		if (i_a <= half_a && i_b <= half_b)
// 		{
// 			rr(ctx);
// 			i_a--;
// 			i_b--;
// 		}
// 		else if (i_a > half_a && i_b > half_b)
// 		{
// 			rrr(ctx);
// 			i_a++;
// 			i_b++;
// 		}
// 		else
// 			break ;
// 	}
// }
