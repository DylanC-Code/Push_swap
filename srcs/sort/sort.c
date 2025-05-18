/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:43:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 00:00:54 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// unsigned int	initialize_lis(int *lis[], t_node *stack);

void	sort_stacks(t_node *a_stack, t_node *b_stack)
{
	int		values[1000];
	size_t	size;
	int		lis[1000];
	size_t	lis_len;

	size = stack_to_int_arr(a_stack, values);
	lis_len = ft_lis_len(values, size);
	// lis_len = initialize_lis(lis, a_stack);
}

// unsigned int	initialize_lis(int *lis[], t_node *stack)
// {
// }
