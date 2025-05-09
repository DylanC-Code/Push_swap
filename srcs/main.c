/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:05:54 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/09 14:49:15 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char const *argv[])
{
	if (!argc || !argv)
		return (1);
	__builtin_printf("Hello %ld \n", ft_abs(atoi(argv[1])));
	return (0);
}
