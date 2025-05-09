/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:05:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/09 17:25:30 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	parse_str(char *str, t_node **dest)
{
	t_node	*new;

	if (!is_valid_number(str))
		return (ERROR);
	if (ft_strlen(str) > 11)
		return (ERROR);
	new = malloc(sizeof(t_node));
	if (!new)
		return (ERROR);
	new->value = ft_atoi(str);
	new->next = NULL;
	if (!new->value)
		return (free(new), ERROR);
	*dest = new;
	return (SUCCESS);
}

t_status	check_double(int value, t_node *head)
{
	while (head && head->next)
	{
		if (value == head->value)
			return (ERROR);
		head = head->next;
	}
	return (SUCCESS);
}

t_status	parse_strs(t_stack *stack, char *strs[])
{
	t_node	*next;
	t_node	*new;

	new = NULL;
	next = NULL;
	stack->size = 0;
	stack->top = NULL;
	while (*strs)
	{
		if (parse_str(*strs, &new) == ERROR)
			return (ERROR);
		if (check_double(new->value, stack->top) == ERROR)
			return (ERROR);
		if (!next)
			next = new;
		else
			next->next = new;
		if (!stack->top)
			stack->top = new;
		next = new;
		stack->size++;
		strs++;
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_stack	a_stack;
	t_node	*next;

	(void)argc;
	if (parse_strs(&a_stack, ++argv) == ERROR)
		return (process_error());
	next = a_stack.top;
    __builtin_printf("Stack size %d\n", a_stack.size);
	while (next)
	{
		__builtin_printf("%d\n", next->value);
		next = next->next;
	}
	return (0);
}
