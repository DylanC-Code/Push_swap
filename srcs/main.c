/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:45:35 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 17:47:20 by dcastor          ###   ########.fr       */
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

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_info *info)
{
	ft_sort_under_five(stack_a, stack_b, info);
	if (info->size_a <= 5)
		exit(0);
	find_lis(stack_a);
	get_lis(stack_a);
	a_to_b(stack_a, stack_b, info);
	b_to_a(stack_a, stack_b, info);
	index_stack(stack_a);
	min_in_top(stack_a, info);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_info	*info;
	char	*full_arg;
	char	**argv;

	if (ac > 1)
	{
		stack_init(&stack_a, &stack_b, &info);
		full_arg = check_arguments(ac, av);
		argv = ft_split(full_arg, ' ');
		check_valid_numbers(ac, argv);
		get_stack(&stack_a, argv, info, ac);
		sort_stack(&stack_a, &stack_b, info);
	}
	return (0);
}
