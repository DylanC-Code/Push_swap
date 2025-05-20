/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:48:58 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/20 09:44:20 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *num)
{
	int	i;

	i = 0;
	if ((num[i] == '-' || num[i] == '+') && ft_strlen(num) > 1)
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_number(char *num)
{
	if (is_number(num))
		ft_error();
	if (is_integer(num))
		ft_error();
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		length;

	length = 0;
	tmp_stack = stack;
	while (tmp_stack)
	{
		if (tmp_stack->next && tmp_stack->number > tmp_stack->next->number)
			return (1);
		length++;
		tmp_stack = tmp_stack->next;
	}
	if (length == 0)
		return (1);
	return (0);
}
