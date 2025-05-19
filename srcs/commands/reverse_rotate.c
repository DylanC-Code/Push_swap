/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:57:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 15:08:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse_a(t_sort_context *ctx)
{
	if (!ctx->a_stack || ctx->a_stack == ctx->a_stack->next)
		return ;
	ctx->a_stack = ctx->a_stack->prev;
}

static void	rotate_reverse_b(t_sort_context *ctx)
{
	if (!ctx->b_stack || ctx->b_stack == ctx->b_stack->next)
		return ;
	ctx->b_stack = ctx->b_stack->prev;
}

void	rra(t_sort_context *ctx)
{
	rotate_reverse_a(ctx);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_sort_context *ctx)
{
	rotate_reverse_b(ctx);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_sort_context *ctx)
{
	rotate_reverse_a(ctx);
	rotate_reverse_b(ctx);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
