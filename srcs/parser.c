/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:38:02 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 09:59:52 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	has_value(t_node *head, int value);

t_status	parse_values(char *values[], t_node *stack)
{
	size_t	i;
	long	nbr;

	i = -1;
	while (values[++i])
	{
		if (!is_valid_number(values[i]))
			return (ERROR);
		ft_bzero(stack + i, sizeof(t_node));
		nbr = ft_atol(values[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (ERROR);
		stack[i].value = nbr;
		if (i == 0)
			continue ;
		if (has_value(stack, stack[i].value))
			return (ERROR);
		dlist_addback_node(&stack, stack + i);
	}
	if (i == 0)
		return (ERROR);
	dlist_addback_node(&stack, stack);
	return (SUCCESS);
}

static bool	has_value(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (true);
		head = head->next;
	}
	return (false);
}
