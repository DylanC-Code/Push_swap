/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:33:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 11:56:55 by dcastor          ###   ########.fr       */
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
			return (len + 1);
	}
	return (len + 1);
}

void	dlist_extract_node(t_node **head, t_node *node)
{
	t_node	*next;

	next = *head;
	if (*head == node)
	{
		*head = node->next;
		if (node->prev)
			node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;
		return ;
	}
	while (next)
	{
		if (next == node && node->prev)
			node->prev->next = node->next;
		if (next == node && node->next)
			node->next->prev = node->prev;
		if (next == node)
			return ;
		next = next->next;
	}
}

void	dlist_addfront_node(t_node **head, t_node *new_node)
{
	t_node	*last;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
		return ;
	}
	last = (*head)->prev;
	new_node->next = *head;
	new_node->prev = last;
	last->next = new_node;
	(*head)->prev = new_node;
	*head = new_node;
}
