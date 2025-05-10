/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:04:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 16:20:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	radix_sort(t_stack *stack);
t_status	ranking(t_stack *stack);
int			*collect_values(t_stack *stack);
t_status	apply_rank(t_stack *stack, unsigned int rank, int value);

/* =============== Definition ================ */

t_status	radix_sort(t_stack *stack)
{
	if (!stack)
		return (NOOP);
	if (ranking(stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_status	ranking(t_stack *stack)
{
	int		*values;
	size_t	i;

	values = collect_values(stack);
	if (!values)
		return (ERROR);
	quick_sort(values, stack->size);
	i = -1;
	while (++i < stack->size)
		if (apply_rank(stack, i, values[i]) == ERROR)
			return (free(values), ERROR);
	return (free(values), SUCCESS);
}

int	*collect_values(t_stack *stack)
{
	t_value	*content;
	int		*values;
	t_list	*node;
	size_t	i;

	if (!stack)
		return (NULL);
	values = malloc(sizeof(int) * stack->size);
	if (!values)
		return (NULL);
	node = stack->top;
	i = 0;
	while (node)
	{
		content = node->content;
		values[i++] = content->value;
		node = node->next;
	}
	return (values);
}

t_status	apply_rank(t_stack *stack, unsigned int rank, int value)
{
	t_list	*node;
	t_value	*content;

	node = stack->top;
	while (node)
	{
		content = node->content;
		if (content->value == value)
		{
			content->index = rank;
			return (SUCCESS);
		}
		node = node->next;
	}
	return (ERROR);
}
