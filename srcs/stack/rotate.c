/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:18:43 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 15:57:00 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	rotate(t_node **p_stack, char stack_name);
t_status	rotate_a(t_node **p_a_stack);
t_status	rotate_b(t_node **p_b_stack);
t_status	super_rotate(t_node **p_a_stack, t_node **b_stack);

/* =============== Definition ================ */

t_status	rotate(t_node **p_stack, char stack_name)
{
	t_node	*last;
	t_node	*second;

	if (!p_stack)
		return (ERROR);
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (!(*p_stack) || !(*p_stack)->next)
		return (NOOP);
	last = find_last_node(*p_stack);
	second = (*p_stack)->next;
	(*p_stack)->next = NULL;
	last->next = *p_stack;
	*p_stack = second;
	return (SUCCESS);
}

t_status	rotate_a(t_node **p_a_stack)
{
	return (rotate(p_a_stack, 'a'));
}

t_status	rotate_b(t_node **p_b_stack)
{
	return (rotate(p_b_stack, 'b'));
}

t_status	super_rotate(t_node **p_a_stack, t_node **p_b_stack)
{
	if (rotate_a(p_a_stack) == ERROR || rotate_b(p_b_stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
