/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_combined.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:05:47 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 19:42:08 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_ss(t_context *ctx)
{
	if (ctx->a.size < 2 && ctx->b.size < 2)
		return ;
	if (ctx->a.size < 2 || ctx->b.size < 2)
	{
		if (ctx->a.size >= 2)
			swap(&ctx->a);
		else
			swap(&ctx->b);
	}
	else if (ctx->a.size >= 2 && ctx->b.size >= 2)
	{
		swap(&ctx->a);
		swap(&ctx->b);
	}
	write(1, "ss\n", 3);
	ctx->counts[OP_SS]++;
	ctx->total++;
}

void	execute_rr(t_context *ctx)
{
	if (ctx->a.size < 2 && ctx->b.size < 2)
		return ;
	if (ctx->a.size < 2 || ctx->b.size < 2)
	{
		if (ctx->a.size >= 2)
			rotate(&ctx->a);
		else
			rotate(&ctx->b);
	}
	else if (ctx->a.size >= 2 && ctx->b.size >= 2)
	{
		rotate(&ctx->a);
		rotate(&ctx->b);
	}
	write(1, "rr\n", 3);
	ctx->counts[OP_RR]++;
	ctx->total++;
}

void	execute_rrr(t_context *ctx)
{
	if (ctx->a.size < 2 && ctx->b.size < 2)
		return ;
	if (ctx->a.size < 2 || ctx->b.size < 2)
	{
		if (ctx->a.size >= 2)
			reverse_rotate(&ctx->a);
		else
			reverse_rotate(&ctx->b);
	}
	else if (ctx->a.size >= 2 && ctx->b.size >= 2)
	{
		reverse_rotate(&ctx->a);
		reverse_rotate(&ctx->b);
	}
	write(1, "rrr\n", 4);
	ctx->counts[OP_RRR]++;
	ctx->total++;
}
