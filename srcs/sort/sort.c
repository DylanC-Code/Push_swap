/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:43:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 10:44:55 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// unsigned int	initialize_lis(int *lis[], t_node *stack);
// void				find_lis_in_stack(t_lis_context *dst, t_node *stack);
// void				find_lis_in_stack(int src[], int dst[], size_t size);

typedef struct s_lis_context
{
	int				values[1000];
	unsigned int	len;
}					t_lis_context;

typedef struct s_sort_context
{
	int				values[1000];
	unsigned int	size;
	int				lis[1000];
	unsigned int	lis_len;
	int				pivot;
}					t_sort_context;

// void				calculate_lis(t_lis_context *dst, t_node *stack);

void	sort_stacks(t_node *a_stack, t_node *b_stack)
{
	t_sort_context	ctx;
	size_t			i;

	ctx.size = stack_to_int_arr(a_stack, ctx.values);
	ctx.lis_len = find_lis(ctx.values, ctx.lis, ctx.size);
	__builtin_printf("Lis len %u\n", ctx.lis_len);
	i = -1;
	while (++i < ctx.lis_len)
		__builtin_printf("%lu: %d\n", i, ctx.lis[i]);
	ctx.pivot = find_pivot(ctx.values, ctx.size);
	(void)b_stack;
	// int		values[1000];
	// size_t	size;
	// int		lis[1000];
	// size_t	lis_len;
	// size = stack_to_int_arr(a_stack, values);
	// lis_len = ft_lis_len(values, size);
	// lis_len = initialize_lis(lis, a_stack);
}
