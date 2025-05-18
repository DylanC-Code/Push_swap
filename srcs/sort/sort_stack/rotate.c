/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:01:26 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:23:22 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_node **p_a_stack, t_node **p_b_stack,
		t_node *cheapest_node)
{
	while (*p_b_stack != cheapest_node->target_node
		&& *p_a_stack != cheapest_node)
		super_rotate(p_a_stack, p_b_stack);
	current_index(*p_a_stack);
	current_index(*p_b_stack);
}

void	reverse_rotate_both(t_node **p_a_stack, t_node **p_b_stack,
		t_node *cheapest_node)
{
	while (*p_b_stack != cheapest_node->target_node
		&& *p_a_stack != cheapest_node)
		super_reverse_rotate(p_a_stack, p_b_stack);
	current_index(*p_a_stack);
	current_index(*p_b_stack);
}
