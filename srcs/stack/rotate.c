/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:18:43 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/11 16:13:33 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	rotate(t_stack *stack, char stack_name);
t_status	rotate_a(t_stack *b_stack);
t_status	rotate_b(t_stack *a_stack);
t_status	super_rotate(t_stack *a_stack, t_stack *b_stack);

/* =============== Definition ================ */

t_status	rotate(t_stack *stack, char stack_name)
{
	t_list	*last;
	t_list	*second;

	if (!stack)
		return (ERROR);
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (!stack->top || !stack->top->next)
		return (NOOP);
	last = ft_lstlast(stack->top);
	second = stack->top->next;
	stack->top->next = NULL;
	last->next = stack->top;
	stack->top = second;
	return (SUCCESS);
}

t_status	rotate_a(t_stack *a_stack)
{
	return (rotate(a_stack, 'a'));
}

t_status	rotate_b(t_stack *b_stack)
{
	return (rotate(b_stack, 'b'));
}

t_status	super_rotate(t_stack *a_stack, t_stack *b_stack)
{
	if (rotate_a(a_stack) == ERROR || rotate_b(b_stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
