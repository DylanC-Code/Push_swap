/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:45:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/09 22:01:53 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_stack	*parse_strs_to_stack(char *strs[]);
t_stack	*create_stack(void);
t_node	*new_node(char *str);
bool	has_value(t_node *head, int value);

/* =============== Definition =============== */

t_stack	*parse_strs_to_stack(char *strs[])
{
	t_stack	*stack;
	t_node	*last;
	t_node	*new;

	stack = create_stack();
	if (!stack)
		return (NULL);
	new = NULL;
	last = NULL;
	while (*strs)
	{
		new = new_node(*strs);
		if (!new || has_value(stack->top, new->value))
			return (NULL); // TODO: free everything
		if (!last)
			last = new;
		else
			last->next = new;
		if (!stack->top)
			stack->top = new;
		last = new;
		stack->size++;
		strs++;
	}
	return (stack);
}

bool	has_value(t_node *head, int value)
{
	while (head)
	{
		if (value == head->value)
			return (true);
		head = head->next;
	}
	return (false);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

t_node	*new_node(char *str)
{
	t_node	*node;

	if (!is_valid_number(str) || ft_strlen(str) > 11)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = ft_atoi(str);
	node->next = NULL;
	if (!node->value)
		return (free(node), NULL);
	return (node);
}
