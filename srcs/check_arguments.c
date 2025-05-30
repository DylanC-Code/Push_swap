/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:48:03 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/21 11:41:39 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arg(char *s1, char *s2, int a)
{
	size_t	len;
	char	*join;
	size_t	i;
	size_t	k;

	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[k])
		join[i++] = s1[k++];
	k = 0;
	while (s2[k])
		join[i++] = s2[k++];
	join[i] = '\0';
	if (a == 0)
		free(s1);
	return (join);
}

t_stack	*max_of_stack(t_stack *stack)
{
	t_stack	*tmp_stack;
	t_stack	*max_stack;
	int		max;

	tmp_stack = stack;
	max = tmp_stack->number;
	max_stack = tmp_stack;
	while (tmp_stack)
	{
		if (tmp_stack->number > max)
		{
			max = tmp_stack->number;
			max_stack = tmp_stack;
		}
		tmp_stack = tmp_stack->next;
	}
	return (max_stack);
}

t_status	check_valid_numbers(int ac, char **av)
{
	int	i;

	ac = 0;
	while (av[ac])
		ac++;
	i = ac - 1;
	while (i >= 0)
	{
		if (check_number(av[i]) == ERROR)
			return (ERROR);
		i--;
	}
	return (SUCCESS);
}

t_status	get_stack(t_stack **stack_a, char **av, t_info *info, int ac)
{
	int	i;
	int	value;
	int	j;

	ac = 0;
	while (av[ac])
		ac++;
	j = ac - 1;
	i = ac - 1;
	while (i >= 0)
	{
		value = fill_stack(stack_a, av[i]);
		if (i < ac - 1 && check_duplicate(*stack_a, value))
			return (ft_error());
		(*stack_a)->lis_len = 1;
		(*stack_a)->prev = -1;
		(*stack_a)->index = j;
		(*stack_a)->lis = 0;
		info->size_a += 1;
		j--;
		i--;
	}
	return (SUCCESS);
}

char	*check_arguments(int ac, char **av)
{
	int		i;
	char	*full_arg;
	char	*tmp_char;

	i = 1;
	full_arg = NULL;
	tmp_char = NULL;
	while (i < ac)
	{
		if (check_space(av[i]) && !tmp_char)
			return (free(full_arg), NULL);
		else if (check_space(av[i]))
			return (ft_error(), free(full_arg), NULL);
		tmp_char = join_arg(av[i], " ", 1);
		full_arg = join_arg(full_arg, tmp_char, 0);
		free(tmp_char);
		i++;
	}
	return (full_arg);
}
