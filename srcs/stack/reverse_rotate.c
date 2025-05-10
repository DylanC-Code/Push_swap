/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:31:27 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 21:42:24 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	reverse_rotate(t_stack *stack, char stack_name);
t_status	reverse_rotate_a(t_stack *a_stack);
t_status	reverse_rotate_b(t_stack *b_stack);
t_status	super_reverse_rotate(t_stack *a_stack, t_stack *b_stack);

/* =============== Definition ================ */

t_status	reverse_rotate(t_stack *stack, char stack_name)
{
	t_list	*last;
	t_list	*previous;

	if (!stack)
		return (ERROR);
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	if (!stack->top || !stack->top->next)
		return (NOOP);
	previous = stack->top;
	while (previous && previous->next)
	{
		if (!previous->next->next)
			break ;
		previous = previous->next;
	}
	last = ft_lstlast(stack->top);
	ft_lstadd_front(&stack->top, last);
	previous->next = NULL;
	return (SUCCESS);
}

t_status	reverse_rotate_a(t_stack *a_stack)
{
	return (reverse_rotate(a_stack, 'a'));
}

t_status	reverse_rotate_b(t_stack *b_stack)
{
	return (reverse_rotate(b_stack, 'b'));
}

t_status	super_reverse_rotate(t_stack *a_stack, t_stack *b_stack)
{
	if (reverse_rotate_a(a_stack) == ERROR)
		return (ERROR);
	if (reverse_rotate_b(b_stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
