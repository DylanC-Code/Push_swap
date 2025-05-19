/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:11:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 15:09:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_sort_context *ctx)
{
	if (!ctx->a_stack || ctx->a_stack == ctx->a_stack->next)
		return ;
	ctx->a_stack = ctx->a_stack->next;
}

static void	rotate_b(t_sort_context *ctx)
{
	if (!ctx->b_stack || ctx->b_stack == ctx->b_stack->next)
		return ;
	ctx->b_stack = ctx->b_stack->next;
}

void	ra(t_sort_context *ctx)
{
	rotate_a(ctx);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_sort_context *ctx)
{
	rotate_b(ctx);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_sort_context *ctx)
{
	rotate_a(ctx);
	rotate_b(ctx);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
