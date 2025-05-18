/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:43:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:03:42 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **p_a_stack)
{
	t_node	*biggest_node;

	biggest_node = find_max(*p_a_stack);
	if (biggest_node == *p_a_stack)
		rotate_a(p_a_stack);
	else if ((*p_a_stack)->next == biggest_node)
		reverse_rotate_a(p_a_stack);
	if ((*p_a_stack)->nbr > (*p_a_stack)->next->nbr)
		swap_a(p_a_stack);
}
