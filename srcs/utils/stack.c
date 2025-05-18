/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:22:25 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:09:28 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

bool	stack_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->nbr > head->next->nbr)
			return (false);
		head = head->next;
	}
	return (true);
}

t_node	*find_max(t_node *head)
{
	t_node	*max;

	max = head;
	while (head)
	{
		if (head->nbr > max->nbr)
			max = head;
		head = head->next;
	}
	return (max);
}

t_node	*find_min(t_node *head)
{
	t_node	*min;

	min = head;
	while (head)
	{
		if (head->nbr < min->nbr)
			min = head;
		head = head->next;
	}
	return (min);
}

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

t_node	*get_cheapest(t_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			break ;
		stack = stack->next;
	}
	return (stack);
}
