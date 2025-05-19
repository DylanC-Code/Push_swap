/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:43:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 14:48:08 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void				calculate_lis(t_lis_context *dst, t_node *stack);

void	print_lis(t_sort_context *ctx)
{
	size_t	i;

	i = -1;
	__builtin_printf("=== Lis ===\n");
	while (++i < ctx->lis_len)
		__builtin_printf("%d\n", ctx->lis[i]);
	__builtin_printf("===  ===\n");
}

void	init_b_stack(t_sort_context *ctx)
{
	size_t			i;
	const size_t	size = ctx->a_len;

	i = -1;
	// ft_putstr_fd("Stack a =====\n", STDIN_FILENO);
	// print_stack(ctx->a_stack);
	// ft_putstr_fd("=====\n", STDIN_FILENO);
	// print_lis(ctx);
	// __builtin_printf("Pivot %d\n", ctx->pivot);
	// __builtin_printf("==== Stack a of len %u ===== \n", ctx->a_len);
	while (++i < size)
	{
		if (ft_int_in_array(ctx->lis, ctx->lis_len, ctx->a_stack->value))
			ra(ctx);
		else if (ctx->a_stack->value > ctx->pivot)
			pb(ctx);
		else
		{
			pb(ctx);
			rb(ctx);
		}
	}
	// __builtin_printf("==== Stack a of len %u ===== \n", ctx->a_len);
	// print_stack(ctx->a_stack);
	// __builtin_printf("==== Stack b of len %u ======\n", ctx->b_len);
	// print_stack(ctx->b_stack);
}

t_node	*find_target(t_node *stack, unsigned int stack_size, int value)
{
	unsigned int	i;
	t_node			*current;
	t_node			*best_fit;

	i = 0;
	best_fit = stack;
	current = stack->next;
	while (++i < stack_size)
	{
		if (best_fit->value < value)
			best_fit = current;
		if (current->value > value && current->value < best_fit->value)
			best_fit = current;
		current = current->next;
	}
	return (best_fit);
}

t_node	*find_cheapest(t_sort_context *ctx)
{
	const unsigned int	b_median = (ctx->b_len) / 2;
	size_t				i;
	t_node				*current;
	t_node				*cheapest;

	i = -1;
	current = ctx->b_stack;
	cheapest = current;
	while (++i < ctx->b_len)
	{
		if (i < b_median)
			current->move_number = i;
		else
			current->move_number = ctx->b_len - i;
		current->target = find_target(ctx->a_stack, ctx->a_len, current->value);
		if (current->target->above_median)
			current->move_number += current->target->index;
		else
			current->move_number += (ctx->a_len - current->target->index);
		if (current->move_number < cheapest->move_number)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	print_targets(t_sort_context *ctx)
{
	size_t	i;
	t_node	*current;

	i = -1;
	current = ctx->b_stack;
	while (++i < ctx->b_len)
	{
		__builtin_printf("Value %d and target %d\n", current->value,
			current->target->value);
		current = current->next;
	}
}

void	move_b_to_a(t_sort_context *ctx)
{
	t_node	*cheapest;

	cheapest = find_cheapest(ctx);
	while (ctx->b_stack != cheapest)
	{
		if (cheapest->above_median)
			rb(ctx);
		else
			rrb(ctx);
	}
	while (ctx->a_stack != cheapest->target)
	{
		if (cheapest->target->above_median)
			ra(ctx);
		else
			rra(ctx);
	}
	pa(ctx);
}

t_node	*find_min(t_node *stack, size_t size)
{
	t_node	*min;
	size_t	i;

	i = 0;
	min = stack;
	stack = stack->next;
	while (++i < size)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	bring_min_to_top(t_sort_context *ctx)
{
	t_node	*min;

	min = find_min(ctx->a_stack, ctx->a_len);
	while (ctx->a_stack != min)
	{
		if (min->above_median)
			ra(ctx);
		else
			rra(ctx);
	}
}

void	sort_stack(t_node *a_stack)
{
	t_sort_context	ctx;

	ft_bzero(&ctx, sizeof(t_sort_context));
	ctx.a_stack = a_stack;
	ctx.a_len = stack_to_int_arr(a_stack, ctx.values);
	ctx.lis_len = find_lis(ctx.values, ctx.lis, ctx.a_len);
	ctx.pivot = find_pivot(ctx.values, ctx.a_len);
	init_b_stack(&ctx);
	while (ctx.b_len)
	{
		find_indexes(&ctx);
		// find_cheapest(&ctx);
		move_b_to_a(&ctx);
	}
	find_indexes(&ctx);
	bring_min_to_top(&ctx);
	// __builtin_printf("==== Stack a of len %u ===== \n", ctx.a_len);
	// print_stack(ctx.a_stack);
	// __builtin_printf("==== Stack b of len %u ======\n", ctx.b_len);
	// print_stack(ctx.b_stack);
}


