/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:54:42 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/11 16:13:09 by dcastor          ###   ########.fr       */
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
	t_list	*b_top;

	if (!a_stack || !b_stack)
		return (ERROR);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	b_top = b_stack->top;
	if (!b_top)
		return (NOOP);
	b_stack->top = b_top->next;
	ft_lstadd_front(&a_stack->top, b_top);
	b_stack->size--;
	a_stack->size++;
	return (SUCCESS);
}

t_status	push_b(t_stack *a_stack, t_stack *b_stack)
{
	t_list	*a_top;

	if (!a_stack || !b_stack)
		return (ERROR);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	a_top = a_stack->top;
	if (!a_top)
		return (NOOP);
	a_stack->top = a_top->next;
	ft_lstadd_front(&b_stack->top, a_top);
	a_stack->size--;
	b_stack->size++;
	return (SUCCESS);
}
