/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:57:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 11:59:39 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_sort_context *ctx)
{
	if (!ctx->b_stack || ctx->b_stack == ctx->b_stack->next)
		return ;
	ctx->b_stack = ctx->b_stack->prev;
	ft_putstr_fd("rrb\n", STDIN_FILENO);
}
