/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:45:35 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/26 12:55:07 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	stack_init(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*info = malloc(sizeof(t_info));
	if (!(*info))
		return (ft_error());
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

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	ft_sort_under_five(stack_a, stack_b, info);
	if (info->size_a <= 5)
		return ;
	find_lis(stack_a);
	get_lis(stack_a);
	a_to_b(stack_a, stack_b, info);
	b_to_a(stack_a, stack_b, info);
	index_stack(stack_a);
	min_in_top(stack_a, info);
}

int	main(int ac, char **av)
{
	static t_stack	*stack_a = NULL;
	static t_stack	*stack_b = NULL;
	static t_info	*info = NULL;
	static char		*full_arg = NULL;
	static char		**argv = NULL;

	if (ac < 2)
		return (0);
	if (stack_init(&stack_a, &stack_b, &info) == ERROR)
		return (free(full_arg), free_savage(stack_a, stack_b, info, argv), 1);
	full_arg = check_arguments(ac, av);
	if (!full_arg)
		return (free(full_arg), free_savage(stack_a, stack_b, info, argv), 0);
	argv = ft_split(full_arg, ' ');
	if (!*argv)
		return (free(full_arg), free_savage(stack_a, stack_b, info, argv), 0);
	if (check_valid_numbers(ac, argv) == ERROR)
		return (free(full_arg), free_savage(stack_a, stack_b, info, argv), 1);
	if (!get_stack(&stack_a, argv, info, ac))
		return (free(full_arg), free_savage(stack_a, stack_b, info, argv), 1);
	sort_stack(&stack_a, &stack_b, info);
	return (free(full_arg), free_savage(stack_a, stack_b, info, argv), 0);
}
