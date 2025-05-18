/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:43:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 12:48:28 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **p_stack)
{
	t_node	*biggest_node;

	biggest_node = find_max(*p_stack);
	if (biggest_node == *p_stack)
		rotate_a(p_stack);
    
}
