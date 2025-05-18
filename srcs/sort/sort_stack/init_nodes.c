/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 13:28:39 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:25:41 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_node *a_stack, t_node *b_stack);
static void	set_target_b(t_node *b_stack, t_node *a_stack);
static void	cost_analysis_a(t_node *a_stack, t_node *b_stack);

void	init_nodes_a(t_node *a_stack, t_node *b_stack)
{
	current_index(a_stack);
	current_index(b_stack);
	set_target_a(a_stack, b_stack);
	cost_analysis_a(a_stack, b_stack);
	set_cheapest(a_stack);
}

void	init_nodes_b(t_node *b_stack, t_node *a_stack)
{
	current_index(a_stack);
	current_index(b_stack);
	set_target_b(b_stack, a_stack);
}

static void	set_target_a(t_node *a_stack, t_node *b_stack)
{
	t_node	*current_b;
	t_node	*target_node;
	long	best_match_index;

	while (a_stack)
	{
		best_match_index = LONG_MIN;
		current_b = b_stack;
		while (current_b)
		{
			if (current_b->nbr < a_stack->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a_stack->target_node = find_max(b_stack);
		else
			a_stack->target_node = target_node;
		a_stack = a_stack->next;
	}
}

static void	set_target_b(t_node *b_stack, t_node *a_stack)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	while (b_stack)
	{
		best_match_index = LONG_MAX;
		current_a = a_stack;
		while (current_a)
		{
			if (current_a->nbr > b_stack->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b_stack->target_node = find_min(a_stack);
		else
			b_stack->target_node = target_node;
		b_stack = b_stack->next;
	}
}

static void	cost_analysis_a(t_node *a_stack, t_node *b_stack)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a_stack);
	len_b = stack_len(b_stack);
	while (a_stack)
	{
		a_stack->push_cost = a_stack->index;
		if (!(a_stack->above_median))
			a_stack->push_cost = len_a - (a_stack->index);
		if (a_stack->target_node->above_median)
			a_stack->push_cost += a_stack->target_node->index;
		else
			a_stack->push_cost += len_b - (a_stack->target_node->index);
		a_stack = a_stack->next;
	}
}
