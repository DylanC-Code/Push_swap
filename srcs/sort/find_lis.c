/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:20:46 by dcastor           #+#    #+#             */
/*   Updated: 2025/05/19 10:28:54 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_SIZE 1000

typedef struct s_lis_ctx
{
	int		*src;
	int		*dst;
	size_t	size;

	int		lis_vals[MAX_SIZE];
	size_t	prev[MAX_SIZE];
	size_t	indices[MAX_SIZE];
	size_t	len;
}			t_lis_ctx;

void		lis_reconstruct(t_lis_ctx *ctx);
void		lis_update(t_lis_ctx *ctx, size_t i);

size_t	find_lis(int *src, int *dst, size_t size)
{
	t_lis_ctx	ctx;
	size_t		i;

	if (!size || size > MAX_SIZE)
		return (0);
	ctx.src = src;
	ctx.dst = dst;
	ctx.size = size;
	ctx.len = 1;
	ctx.lis_vals[0] = src[0];
	ctx.indices[0] = 0;
	ctx.prev[0] = -1;
	i = 0;
	while (++i < size)
		lis_update(&ctx, i);
	lis_reconstruct(&ctx);
	return (ctx.len);
}

void	lis_reconstruct(t_lis_ctx *ctx)
{
	ssize_t	i;
	size_t	k;

	i = ctx->len - 1;
	k = ctx->indices[ctx->len - 1];
	while (i >= 0)
	{
		ctx->dst[i] = ctx->src[k];
		k = ctx->prev[k];
		i--;
	}
}

void	lis_update(t_lis_ctx *ctx, size_t i)
{
	size_t	pos;

	pos = ft_lower_bound(ctx->lis_vals, ctx->len, ctx->src[i]);
	ctx->lis_vals[pos] = ctx->src[i];
	ctx->indices[pos] = i;
	ctx->prev[i] = (pos > 0) ? ctx->indices[pos - 1] : (size_t)-1;
	if (pos == ctx->len)
		ctx->len++;
}
