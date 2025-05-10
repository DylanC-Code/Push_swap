/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:31:07 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 16:43:04 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	swap_a(t_stack *stack);
t_status	swap_b(t_stack *stack);
t_status	super_swap(t_stack *a_stack, t_stack *b_stack);
t_status	swap(t_stack *stack, char stack_name);

/* =============== Definition ================ */

t_status	swap_a(t_stack *stack)
{
	return (swap(stack, 'a'));
}

t_status	swap_b(t_stack *stack)
{
	return (swap(stack, 'b'));
}

t_status	super_swap(t_stack *a_stack, t_stack *b_stack)
{
	if (swap_a(a_stack) == ERROR || swap_b(b_stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_status	swap(t_stack *stack, char stack_name)
{
	t_list *second;

	if (!stack)
		return (ERROR);
	ft_putchar_fd('s', STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	if (!stack->top || !stack->top->next)
		return (NOOP);
	second = stack->top->next;
	stack->top->next = second->next;
	second->next = stack->top;
	stack->top = second;
	return (SUCCESS);
}
