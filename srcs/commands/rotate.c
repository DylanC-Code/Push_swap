/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:11:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 11:16:30 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_sort_context *ctx)
{
	if (!ctx->a_stack || ctx->a_stack == ctx->a_stack->next)
		return ;
	ft_putstr_fd("ra\n", STDIN_FILENO);
	ctx->a_stack = ctx->a_stack->next;
}

void	rb(t_sort_context *ctx)
{
	if (!ctx->b_stack || ctx->b_stack == ctx->b_stack->next)
		return ;
	ft_putstr_fd("rb\n", STDIN_FILENO);
	ctx->b_stack = ctx->b_stack->next;
}
