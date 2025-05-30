/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:49:18 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/20 13:42:45 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack, t_info *info)
{
	t_stack	*max_stack;
	t_stack	*min_stack;

	index_stack(stack);
	max_stack = max_of_stack(*stack);
	min_stack = min_elem(*stack);
	if (stack_is_sorted(*stack) == SUCCESS)
		return ;
	if (max_stack->index == 1)
		sort_three_a(stack, info);
	else if (min_stack->index == 1)
		sort_three_b(stack, info);
	else
	{
		ft_rotate(stack, "ra\n", info);
		ft_swap(stack, "sa\n", info);
	}
}

void	sort_three_a(t_stack **stack, t_info *info)
{
	t_stack	*tmp_curr;
	t_stack	*tmp_next;

	tmp_curr = *stack;
	tmp_next = (*stack)->next;
	if (tmp_curr->number < tmp_next->next->number)
	{
		ft_reverse_rotate(stack, "rra\n", info);
		ft_swap(stack, "sa\n", info);
	}
	else
		ft_reverse_rotate(stack, "rra\n", info);
}

void	sort_three_b(t_stack **stack, t_info *info)
{
	t_stack	*tmp_curr;
	t_stack	*tmp_next;

	tmp_curr = *stack;
	tmp_next = (*stack)->next;
	if (tmp_curr->number < tmp_next->next->number)
		ft_swap(stack, "sa\n", info);
	else
		ft_rotate(stack, "ra\n", info);
}
