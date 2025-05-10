/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:04:00 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/10 16:24:56 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =============== Importation =============== */

#include "push_swap.h"

/* =============== Declaration =============== */

t_status	radix_sort(t_stack *stack);

/* =============== Definition ================ */

t_status	radix_sort(t_stack *stack)
{
	if (!stack)
		return (NOOP);
	if (ranking(stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
