/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:54:42 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 17:00:48 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	push_a(t_stack *a_stack, t_stack *b_stack);
t_status	push_b(t_stack *a_stack, t_stack *b_stack);

/* =============== Definition ================ */

t_status	push_a(t_stack *a_stack, t_stack *b_stack)
{
	if (!a_stack || !b_stack)
		return (ERROR);
	ft_putstr_fd("pa", STDOUT_FILENO);
	if (!b_stack->top)
		return (NOOP);
	ft_lstadd_front(&a_stack->top, b_stack->top);
	b_stack->top = b_stack->top->next;
	return (SUCCESS);
}

t_status	push_b(t_stack *a_stack, t_stack *b_stack)
{
	if (!a_stack || !b_stack)
		return (ERROR);
	ft_putstr_fd("pb", STDOUT_FILENO);
	if (!a_stack->top)
		return (NOOP);
	ft_lstadd_front(&b_stack->top, a_stack->top);
	a_stack->top = a_stack->top->next;
	return (SUCCESS);
}
