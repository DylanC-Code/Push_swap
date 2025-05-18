/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 12:50:21 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define ERROR -1
# define NOOP 0
# define SUCCESS 1

typedef int			t_status;

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

t_status			initialize_stack(t_node **head, char *nbrs[]);

void				free_stack(t_node *stack);

/* Node */
t_node				*create_node(long nbr);
void				add_node_to_back(t_node **head, t_node *node);
t_node				*find_last_node(t_node *head);

/* Stack */
size_t				stack_len(t_node *head);
bool				stack_sorted(t_node *head);
t_node				*find_max(t_node *head);

t_status			swap_a(t_node **p_stack);
t_status			swap_b(t_node **p_stack);
t_status			super_swap(t_node **p_a_stack, t_node **p_b_stack);

// t_status			push_a(t_stack *a_stack, t_stack *b_stack);
// t_status			push_b(t_stack *a_stack, t_stack *b_stack);

t_status			rotate(t_node **p_stack, char stack_name);
t_status			rotate_a(t_node **p_b_stack);
t_status			rotate_b(t_node **p_a_stack);
t_status			super_rotate(t_node **p_a_stack, t_node **b_stack);

// t_status			reverse_rotate_a(t_stack *a_stack);
// t_status			reverse_rotate_b(t_stack *b_stack);
// t_status			super_reverse_rotate(t_stack *a_stack, t_stack *b_stack);

#endif
