/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 23:30:31 by dcastor          ###   ########.fr       */
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

void				dlist_addback_node(t_node **head, t_node *new_node);
size_t				stack_to_int_arr(t_node *head, int arr[]);

t_status			parse_values(char *values[], t_node *stack);
void				sort_stacks(t_node *a_stack, t_node *b_stack);

#endif
