/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:04:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/11 16:16:44 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status		radix_sort(t_stack *stack);
unsigned int	find_radix_max(t_list *head);
void			sort_for_radix(t_stack *src_stack, t_stack *dst_stack,
					unsigned int radix);
void			empty_b_stack(t_stack *b_stack, t_stack *a_stack);

/* =============== Definition ================ */

t_status	radix_sort(t_stack *stack)
{
	t_stack			*b_stack;
	unsigned int	radix_shifter_max;
	unsigned int	radix_shifter;

	b_stack = create_stack();
	radix_shifter = 0;
	if (!stack || !b_stack)
		return (ERROR);
	radix_shifter_max = find_radix_max(stack->top);
	// __builtin_printf("Radix max %u\n", radix_shifter_max);
	if (ranking(stack) == ERROR)
		return (ERROR);
	while (stack->size && radix_shifter <= radix_shifter_max)
	{
		sort_for_radix(stack, b_stack, 1 << radix_shifter++);
		empty_b_stack(b_stack, stack);
	}
	return (SUCCESS);
}

void	empty_b_stack(t_stack *b_stack, t_stack *a_stack)
{
	if (!b_stack || !a_stack)
		return ;
	while (b_stack->top)
		push_a(a_stack, b_stack);
}

void	sort_for_radix(t_stack *src_stack, t_stack *dst_stack,
		unsigned int radix)
{
	const size_t	src_stack_size = src_stack->size;
	size_t			i;
	t_value			*content;

	i = -1;
	while (++i < src_stack_size)
	{
		content = src_stack->top->content;
		if (content->index & radix)
			rotate_a(src_stack);
		else
			push_b(src_stack, dst_stack);
	}
}

unsigned int	find_radix_max(t_list *head)
{
	unsigned int	radix_counter;
	unsigned int	radix_max;
	long			value;

	radix_max = 0;
	while (head)
	{
		value = ((t_value *)head->content)->value;
		radix_counter = 0;
		if (value < 0)
			value = -value;
		while (value)
		{
			radix_counter++;
			value = value >> 1;
		}
		if (radix_counter > radix_max)
			radix_max = radix_counter;
		head = head->next;
	}
	return (radix_max);
}
