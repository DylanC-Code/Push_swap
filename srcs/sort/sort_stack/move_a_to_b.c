/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:53:04 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:15:13 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_node **stack, t_node *target_node, char stack_name);

void	move_a_to_b(t_node **a_stack, t_node **b_stack)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a_stack);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a_stack, b_stack, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a_stack, b_stack, cheapest_node);
	// else
	// {
	prep_for_push(a_stack, cheapest_node, 'a');
	prep_for_push(b_stack, cheapest_node->target_node, 'b');
	// }
	push_b(a_stack, b_stack);
}

void	move_b_to_a(t_node **p_b_stack, t_node **p_a_stack)
{
	prep_for_push(p_a_stack, (*p_b_stack)->target_node, 'a');
	push_a(p_a_stack, p_b_stack);
}

void	prep_for_push(t_node **stack, t_node *target_node, char stack_name)
{
	while (*stack != target_node)
	{
		if (target_node->above_median)
			rotate(stack, stack_name);
		else
			reverse_rotate(stack, stack_name);
	}
}
