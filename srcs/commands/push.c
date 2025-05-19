/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:20:09 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 14:04:38 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_sort_context *ctx)
{
	t_node	*to_move;

	if (!ctx->a_stack)
		return ;
	to_move = ctx->a_stack;
	dlist_extract_node(&(ctx->a_stack), to_move);
	dlist_addfront_node(&(ctx->b_stack), to_move);
	ctx->b_len++;
	ctx->a_len--;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

void	pa(t_sort_context *ctx)
{
	t_node	*to_move;

	if (!ctx->b_stack)
		return ;
	to_move = ctx->b_stack;
	dlist_extract_node(&(ctx->b_stack), to_move);
	dlist_addfront_node(&(ctx->a_stack), to_move);
	ctx->a_len++;
	ctx->b_len--;
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}
