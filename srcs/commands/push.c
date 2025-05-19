/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:20:09 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 11:44:57 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_sort_context *ctx)
{
	t_node	*to_move;

	// t_node
	if (!ctx->a_stack)
		return ;
	to_move = ctx->a_stack;
	dlist_extract_node(&(ctx->a_stack), to_move);
	dlist_addfront_node(&(ctx->b_stack), to_move);
	ft_putstr_fd("pb\n", STDIN_FILENO);
}
