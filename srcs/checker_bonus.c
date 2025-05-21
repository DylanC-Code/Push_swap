/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:48:19 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/21 11:40:52 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_move(t_stack **s_a, t_stack **s_b, int move, t_info *info)
{
	if (move == 0)
		ft_rotate(s_a, "", info);
	else if (move == 1)
		ft_rotate(s_b, "", info);
	else if (move == 2)
		ft_swap(s_a, "", info);
	else if (move == 3)
		ft_swap(s_b, "", info);
	else if (move == 4)
		ft_rr(s_a, s_b, "", info);
	else if (move == 5)
	{
		ft_push(s_b, s_a, "");
		info->size_b -= 1;
		info->size_a += 1;
	}
	else
		perform_move_two(s_a, s_b, move, info);
}

void	perform_move_two(t_stack **s_a, t_stack **s_b, int move, t_info *info)
{
	if (move == 6)
	{
		ft_push(s_a, s_b, "");
		info->size_a -= 1;
		info->size_b += 1;
	}
	else if (move == 7)
		ft_rrr(s_a, s_b, "", info);
	else if (move == 8)
		ft_reverse_rotate(s_a, "", info);
	else if (move == 9)
		ft_reverse_rotate(s_b, "", info);
	else
		ft_ss(s_a, s_b, "", info);
}

t_status	check_moves(t_stack **stack_a, t_stack **stack_b, t_info *info,
		int fd)
{
	char	*move;
	int		move_type;

	move = get_next_line(fd);
	while (move)
	{
		move_type = check_valid_move(move);
		if (move_type == ERROR)
			return (free(move), ERROR);
		else
			perform_move(stack_a, stack_b, move_type, info);
		free(move);
		move = get_next_line(0);
	}
	return (free(move), SUCCESS);
}

int	main(int ac, char **av)
{
	static t_stack	*stack_a = NULL;
	static t_stack	*stack_b = NULL;
	static t_info	*info = NULL;
	static char		*full_arg = NULL;
	static char		**argv = NULL;

	if (ac > 1)
	{
		stack_init(&stack_a, &stack_b, &info);
		full_arg = check_arguments(ac, av);
		if (!full_arg)
			return (free_savage(stack_a, stack_b, info, argv), ft_error(), 0);
		argv = ft_split(full_arg, ' ');
		if (check_valid_numbers(ac, argv) == ERROR)
			return (free_savage(stack_a, stack_b, info, argv), free(full_arg),
				0);
		if (get_stack(&stack_a, argv, info, ac) == ERROR)
			return (free_savage(stack_a, stack_b, info, argv), free(full_arg),
				0);
		if (check_moves(&stack_a, &stack_b, info, 0) == ERROR)
			return (free_savage(stack_a, stack_b, info, argv), free(full_arg),
				0);
		print_savage(stack_a, stack_b);
	}
	return (free_savage(stack_a, stack_b, info, argv), free(full_arg), 0);
}
