/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:45:44 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 14:10:03 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_stack	*parse_strs_to_stack(char *strs[]);
t_stack	*create_stack(void);
t_value	*new_value(char *str);
bool	has_value(t_list *head, int value);

/* =============== Definition ================ */

t_stack	*parse_strs_to_stack(char *strs[])
{
	t_stack	*stack;
	t_value	*new;
	t_list	*node;

	stack = create_stack();
	if (!stack)
		return (NULL);
	while (*strs)
	{
		new = new_value(*strs);
		if (!new || has_value(stack->top, new->value))
			return (NULL); // TODO: free everything
		node = ft_lstnew(new);
		if (!node)
			return (free(new), NULL); // TODO: free stack
		ft_lstadd_back(&stack->top, node);
		stack->size++;
		strs++;
	}
	return (stack);
}

bool	has_value(t_list *head, int value)
{
	t_value	*content;

	content = NULL;
	while (head)
	{
		content = head->content;
		if (value == content->value)
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

t_value	*new_value(char *str)
{
	t_value	*content;

	if (!is_valid_number(str) || ft_strlen(str) > 11)
		return (NULL);
	content = malloc(sizeof(t_value));
	if (!content)
		return (NULL);
	content->value = ft_atoi(str);
	content->index = 0;
	if (!content->value)
		return (free(content), NULL);
	return (content);
}
