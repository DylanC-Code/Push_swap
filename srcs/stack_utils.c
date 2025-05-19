/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:49:22 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 17:49:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *s)
{
	if (s == NULL)
		return (1);
	else
		return (0);
}

void	push(t_stack **s, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->number = value;
	new_node->next = *s;
	*s = new_node;
}

int	pop(t_stack **s, int *value)
{
	t_stack	*tmp;

	if (is_empty(*s))
		return (1);
	*value = (*s)->number;
	tmp = *s;
	*s = (*s)->next;
	free(tmp);
	return (0);
}

int	fill_stack(t_stack **s, char *arg)
{
	int	value;

	value = ft_atoi(arg);
	push(s, value);
	return (value);
}
