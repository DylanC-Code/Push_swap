/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:54:42 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 16:52:34 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	push_a(t_node **p_a_stack, t_node **p_b_stack);
t_status	push_b(t_node **p_a_stack, t_node **p_b_stack);

/* =============== Definition ================ */

t_status	push_a(t_node **p_a_stack, t_node **p_b_stack)
{
	t_node	*b_top;

	if (!p_a_stack || !p_b_stack)
		return (ERROR);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	b_top = *p_b_stack;
	if (!b_top)
		return (NOOP);
	*p_b_stack = b_top->next;
	add_node_to_frond(p_a_stack, b_top);
	return (SUCCESS);
}

t_status	push_b(t_node **p_a_stack, t_node **p_b_stack)
{
	t_node	*a_top;

	if (!p_a_stack || !p_b_stack)
		return (ERROR);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	a_top = *p_a_stack;
	if (!a_top)
		return (NOOP);
	*p_a_stack = a_top->next;
	add_node_to_frond(p_b_stack, a_top);
	return (SUCCESS);
}
