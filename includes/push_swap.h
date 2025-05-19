/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 11:16:50 by dcastor          ###   ########.fr       */
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
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_sort_context
{
	int				values[1000];
	unsigned int	size;
	int				lis[1000];
	unsigned int	lis_len;
	int				pivot;
	t_node			*a_stack;
	t_node			*b_stack;
}					t_sort_context;

void				dlist_addback_node(t_node **head, t_node *new_node);
size_t				stack_to_int_arr(t_node *head, int arr[]);

t_status			parse_values(char *values[], t_node *stack);

/* Sort */
void				sort_stack(t_node *a_stack);
size_t				find_lis(int *src, int *dst, size_t size);
int					find_pivot(int arr[], size_t size);

/* Commands */
void				ra(t_sort_context *ctx);
void				rb(t_sort_context *ctx);

#endif
