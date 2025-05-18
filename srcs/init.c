/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 11:06:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 15:50:00 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_status	initialize_stack(t_node **head, char *nbrs[]);
static bool	has_value(t_node *head, int value);

t_status	initialize_stack(t_node **head, char *nbrs[])
{
	long	converted_nbr;
	t_node	*new_node;

	while (nbrs && *nbrs)
	{
		if (!is_valid_number(*nbrs))
			return (ERROR);
		converted_nbr = ft_atol(*nbrs);
		if (converted_nbr > INT_MAX || converted_nbr < INT_MIN)
			return (ERROR);
		if (has_value(*head, converted_nbr))
			return (ERROR);
		new_node = create_node(converted_nbr);
		if (!new_node)
			return (ERROR);
		add_node_to_back(head, new_node);
		nbrs++;
	}
	return (SUCCESS);
}

static bool	has_value(t_node *head, int value)
{
	while (head)
	{
		if (value == head->nbr)
			return (true);
		head = head->next;
	}
	return (false);
}
