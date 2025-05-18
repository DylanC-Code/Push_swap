/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:22:25 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 12:46:56 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_node *head)
{
	size_t	count;

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
