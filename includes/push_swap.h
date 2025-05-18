/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 17:09:45 by dcastor          ###   ########.fr       */
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
void	print_stack(t_node *stack, const char *label); // TODOL: remove

/* Sort */
void				sort_three(t_node **p_stack);
void				sort_stack(t_node **p_a_stack, t_node **p_b_stack);
void				rotate_both(t_node **p_a_stack, t_node **p_b_stack,
						t_node *cheapest_node);
void				reverse_rotate_both(t_node **p_a_stack, t_node **p_b_stack,
						t_node *cheapest_node);
void				move_a_to_b(t_node **a_stack, t_node **b_stack);
void				move_b_to_a(t_node **p_b_stack, t_node **p_a_stack);

/* Node */
t_node				*create_node(long nbr);
void				add_node_to_back(t_node **head, t_node *node);
void				add_node_to_frond(t_node **head, t_node *new);
t_node				*find_last_node(t_node *head);

void				init_nodes_a(t_node *a_stack, t_node *b_stack);
void				init_nodes_b(t_node *b_stack, t_node *a_stack);

/* Stack */
int					stack_len(t_node *head);
bool				stack_sorted(t_node *head);
t_node				*find_max(t_node *head);
t_node				*find_min(t_node *head);
void				current_index(t_node *stack);
void				set_cheapest(t_node *stack);
t_node				*get_cheapest(t_node *stack);

t_status			swap_a(t_node **p_stack);
t_status			swap_b(t_node **p_stack);
t_status			super_swap(t_node **p_a_stack, t_node **p_b_stack);

t_status			push_a(t_node **p_a_stack, t_node **p_b_stack);
t_status			push_b(t_node **p_a_stack, t_node **p_b_stack);

t_status			rotate(t_node **p_stack, char stack_name);
t_status			rotate_a(t_node **p_a_stack);
t_status			rotate_b(t_node **p_b_stack);
t_status			super_rotate(t_node **p_a_stack, t_node **b_stack);

t_status			reverse_rotate(t_node **p_stack, char stack_name);
t_status			reverse_rotate_a(t_node **p_a_stack);
t_status			reverse_rotate_b(t_node **p_b_stack);
t_status			super_reverse_rotate(t_node **p_a_stack,
						t_node **p_b_stack);

#endif
