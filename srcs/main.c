/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:50:28 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 21:37:08 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_status	check_args(int argc, char *argv[]);
t_status	parse_values(char *values[], t_node *nodes);
bool		has_value(t_node *head, int value);

void	print_stack(t_node *head)
{
	t_node	*first;

	first = head;
	__builtin_printf("Value %d\n", head->value);
	head = head->next;
	while (head)
	{
		__builtin_printf("Value %d\n", head->value);
		head = head->next;
		if (first == head)
			return ;
	}
}

int	main(int argc, char *argv[])
{
	t_node	nodes[1000];

	if (check_args(argc, argv) == ERROR)
		return (EXIT_FAILURE);
	if (argc == 2)
		argv = ft_split((const char *)argv[1], ' ');
	if (parse_values(&argv[1], nodes) == ERROR)
		return (EXIT_FAILURE);
	print_stack(nodes);
	return (0);
}

t_status	check_args(int argc, char *argv[])
{
	if (argc < 2)
		return (ERROR);
	if (argc == 2 && !argv[1][0])
		return (ERROR);
	return (SUCCESS);
}

t_status	parse_values(char *values[], t_node *nodes)
{
	size_t	i;
	long	nbr;

	i = -1;
	while (values[++i])
	{
		if (!is_valid_number(values[i]))
			return (ERROR);
		ft_bzero(nodes + i, sizeof(t_node));
		nbr = ft_atol(values[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (ERROR);
		nodes[i].value = nbr;
		if (i == 0)
			continue ;
		if (has_value(nodes, nodes[i].value))
			return (ERROR);
		dlist_addback_node(&nodes, nodes + i);
	}
	if (i == 0)
		return (ERROR);
	dlist_addback_node(&nodes, nodes);
	return (SUCCESS);
}

bool	has_value(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (true);
		head = head->next;
	}
	return (false);
}
