/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:46:53 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 16:06:11 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(long nbr);
void	add_node_to_back(t_node **head, t_node *node);
t_node	*find_last_node(t_node *head);

t_node	*create_node(long nbr)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	ft_bzero(new_node, sizeof(t_node));
	new_node->nbr = nbr;
	return (new_node);
}

void	add_node_to_back(t_node **head, t_node *node)
{
	t_node	*last;

	if (*head)
	{
		last = find_last_node(*head);
		last->next = node;
		node->prev = last;
		return ;
	}
	*head = node;
}

void	add_node_to_frond(t_node **head, t_node *new)
{
	new->next = *head;
	*head = new;
}

t_node	*find_last_node(t_node *head)
{
	while (head)
	{
		if (!head->next)
			return (head);
		head = head->next;
	}
	return (head);
}
