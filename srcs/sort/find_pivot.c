/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:42:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 10:46:14 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(int arr[], size_t size)
{
	int		tmp[1000];
	size_t	i;

	i = -1;
	while (++i < size)
		tmp[i] = arr[i];
	quick_sort(tmp, size);
	return (tmp[size / 2]);
}
