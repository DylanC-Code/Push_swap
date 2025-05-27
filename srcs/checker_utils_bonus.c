/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:48:23 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/27 20:00:34 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	stack_init(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*info = malloc(sizeof(t_info));
	if (!*info)
		return (ERROR);
	(*info)->size_a = 0;
	(*info)->size_b = 0;
	return (SUCCESS);
}

int	check_space(char *string)
{
	int	i;

	i = 0;
	if (string[0] == '\0')
		return (1);
	while (string[i])
	{
		if (string[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	three_len_move(char *move)
{
	if (ft_strcmp(move, "ra\n") == 0)
		return (0);
	if (ft_strcmp(move, "rb\n") == 0)
		return (1);
	if (ft_strcmp(move, "sa\n") == 0)
		return (2);
	if (ft_strcmp(move, "sb\n") == 0)
		return (3);
	if (ft_strcmp(move, "rr\n") == 0)
		return (4);
	if (ft_strcmp(move, "pa\n") == 0)
		return (5);
	if (ft_strcmp(move, "pb\n") == 0)
		return (6);
	if (ft_strcmp(move, "ss\n") == 0)
		return (10);
	return (-1);
}

int	four_len_move(char *move)
{
	if (ft_strcmp(move, "rrr\n") == 0)
		return (7);
	if (ft_strcmp(move, "rra\n") == 0)
		return (8);
	if (ft_strcmp(move, "rrb\n") == 0)
		return (9);
	return (-1);
}

t_status	check_valid_move(char *move)
{
	int	length;

	length = ft_strlen(move);
	if (length == 3)
	{
		if (three_len_move(move) == -1)
			return (ft_error(), -1);
		else
			return (three_len_move(move));
	}
	else if (length == 4)
	{
		if (four_len_move(move) == -1)
			return (ft_error(), -1);
		else
			return (four_len_move(move));
	}
	return (ft_error(), -1);
}
