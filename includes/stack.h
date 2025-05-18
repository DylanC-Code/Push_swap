/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:31:03 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/18 20:37:49 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

typedef struct s_node
{
	int				value;
	unsigned int	index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

void				dlist_addback_node(t_node **head, t_node *new_node);

#endif
