/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 15:41:37 by dcastor          ###   ########.fr       */
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
	int				value;
	unsigned int	index;
	unsigned int	move_number;
	bool			above_median;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_sort_context
{
	int				values[1000];
	int				lis[1000];
	unsigned int	lis_len;
	int				pivot;
	t_node			*a_stack;
	unsigned int	a_len;
	t_node			*b_stack;
	unsigned int	b_len;
}					t_sort_context;

void				dlist_addback_node(t_node **head, t_node *new_node);
void				dlist_extract_node(t_node **head, t_node *node);
void				dlist_addfront_node(t_node **head, t_node *new_node);
size_t				stack_to_int_arr(t_node *head, int arr[]);
bool				is_in_lis(t_sort_context *ctx, int value);
t_node				*find_min_node(t_node *stack, size_t size);
t_status			parse_values(char *values[], t_node *stack);

/* Sort */
void				sort_stack(t_node *a_stack);
size_t				find_lis(int *src, int *dst, size_t size);
int					find_pivot(int arr[], size_t size);
void				find_indexes(t_sort_context *ctx);
void				push_non_lis_to_b(t_sort_context *ctx);
void				perform_cheapest_move(t_sort_context *ctx);
void				rotate_min_to_top(t_sort_context *ctx);
t_node				*find_cheapest_move(t_sort_context *ctx);

/* Commands */
void				ra(t_sort_context *ctx);
void				rb(t_sort_context *ctx);
void				rr(t_sort_context *ctx);
void				pb(t_sort_context *ctx);
void				pa(t_sort_context *ctx);
void				rrb(t_sort_context *ctx);
void				rra(t_sort_context *ctx);
void				rrr(t_sort_context *ctx);

/* TODO: To remove */
void				print_stack(t_node *head);

#endif
