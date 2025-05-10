/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:49 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 14:30:07 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define ERROR -1
# define NOOP 0
# define SUCCESS 1

typedef int			t_status;

typedef struct s_value
{
	int				value;
	unsigned int	index;
}					t_value;

typedef struct s_stack
{
	t_list			*top;
	unsigned int	size;
}					t_stack;

int					process_error(void);
t_stack				*parse_strs_to_stack(char *strs[]);

/* Sort */
t_status			radix_sort(t_stack *stack);

#endif
