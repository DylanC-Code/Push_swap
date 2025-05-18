/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:33:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 23:38:26 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_addback_node(t_node **head, t_node *new_node)
{
	t_node	*next;

	next = *head;
	if (!next)
	{
		*head = new_node;
		return ;
	}
	while (next->next)
		next = next->next;
	next->next = new_node;
	new_node->prev = next;
}

size_t	stack_to_int_arr(t_node *head, int arr[])
{
	size_t	len;
	t_node	*next;

	len = 0;
	next = head;
	while (next)
	{
		arr[len++] = next->value;
		next = next->next;
		if (head == next)
			return (len);
	}
	return (len);
}
