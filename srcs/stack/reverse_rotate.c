/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:31:27 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 16:07:56 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	reverse_rotate(t_node **p_stack, char stack_name);
t_status	reverse_rotate_a(t_node **p_a_stack);
t_status	reverse_rotate_b(t_node **p_b_stack);
t_status	super_reverse_rotate(t_node **p_a_stack, t_node **p_b_stack);

/* =============== Definition ================ */

t_status	reverse_rotate(t_node **p_stack, char stack_name)
{
	t_node	*last;
	t_node	*previous;

	if (!p_stack)
		return (ERROR);
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(stack_name, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (!(*p_stack) || !(*p_stack)->next)
		return (NOOP);
	previous = *p_stack;
	while (previous && previous->next)
	{
		if (!previous->next->next)
			break ;
		previous = previous->next;
	}
	last = find_last_node(*p_stack);
	add_node_to_frond(p_stack, last);
	previous->next = NULL;
	return (SUCCESS);
}

t_status	reverse_rotate_a(t_node **p_a_stack)
{
	return (reverse_rotate(p_a_stack, 'a'));
}

t_status	reverse_rotate_b(t_node **p_b_stack)
{
	return (reverse_rotate(p_b_stack, 'b'));
}

t_status	super_reverse_rotate(t_node **p_a_stack, t_node **p_b_stack)
{
	if (reverse_rotate_a(p_a_stack) == ERROR)
		return (ERROR);
	if (reverse_rotate_b(p_b_stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
