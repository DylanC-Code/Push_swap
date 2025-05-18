/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:31:07 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 12:41:14 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	swap_a(t_node **p_stack);
t_status	swap_b(t_node **p_stack);
t_status	super_swap(t_node **p_a_stack, t_node **p_b_stack);
t_status	swap(t_node **p_stack, char stack_name);

/* =============== Definition ================ */

t_status	swap_a(t_node **p_stack)
{
	return (swap(p_stack, 'a'));
}

t_status	swap_b(t_node **p_stack)
{
	return (swap(p_stack, 'b'));
}

t_status	super_swap(t_node **p_a_stack, t_node **p_b_stack)
{
	if (swap_a(p_a_stack) == ERROR || swap_b(p_b_stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_status	swap(t_node **p_stack, char stack_name)
{
	t_node	*second;

	if (!p_stack)
		return (ERROR);
	ft_putchar_fd('s', STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	if (!*p_stack || !(*p_stack)->next)
		return (NOOP);
	second = (*p_stack)->next;
	(*p_stack)->next = second->next;
	second->next = *p_stack;
	*p_stack = second;
	return (SUCCESS);
}
