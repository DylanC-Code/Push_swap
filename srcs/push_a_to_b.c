/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:48:43 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 17:48:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	a_to_b(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	int	size;

	size = info->size_a - (max_of_length(stack_a)->lis_len);
	while (size != 0)
	{
		if ((*stack_a)->lis == 1)
		{
			ft_rotate(stack_a, "ra\n", info);
		}
		else
		{
			ft_push(stack_a, stack_b, "pb\n");
			size--;
			info->size_a -= 1;
			info->size_b += 1;
		}
	}
}

int	ft_count_elem(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		count;

	count = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		count++;
		tmp_stack = tmp_stack->next;
	}
	return (count);
}
