/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:33:40 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 21:06:14 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

