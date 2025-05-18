/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:04:57 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:05:30 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_min_on_top(t_node **p_a_stack);

void	sort_stack(t_node **p_a_stack, t_node **p_b_stack)
{
	int	len_a;

	len_a = stack_len(*p_a_stack);
	if (len_a-- > 3 && !stack_sorted(*p_a_stack))
		push_b(p_a_stack, p_b_stack);
	if (len_a-- > 3 && !stack_sorted(*p_a_stack))
		push_b(p_a_stack, p_b_stack);
	while (len_a-- > 3 && !stack_sorted(*p_a_stack))
	{
		init_nodes_a(*p_a_stack, *p_b_stack);
		move_a_to_b(p_a_stack, p_b_stack);
	}
	sort_three(p_a_stack);
	while (*p_b_stack)
	{
		init_nodes_b(*p_b_stack, *p_a_stack);
		move_b_to_a(p_b_stack, p_a_stack);
	}
	current_index(*p_a_stack);
	bring_min_on_top(p_a_stack);
}

void	bring_min_on_top(t_node **p_a_stack)
{
	while ((*p_a_stack)->nbr != find_min(*p_a_stack)->nbr)
	{
		if (find_min(*p_a_stack)->above_median)
			rotate_a(p_a_stack);
		else
			reverse_rotate_a(p_a_stack);
	}
}
