/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:59:57 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 19:41:33 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_sb(t_context *ctx)
{
	if (ctx->b.size < 2)
		return ;
	swap(&ctx->b);
	write(1, "sb\n", 3);
	ctx->counts[OP_SB]++;
	ctx->total++;
}

void	execute_pb(t_context *ctx)
{
	if (ctx->a.size < 1)
		return ;
	push(&ctx->a, &ctx->b);
	write(1, "pb\n", 3);
	ctx->counts[OP_PB]++;
	ctx->total++;
}

void	execute_rb(t_context *ctx)
{
	if (ctx->b.size < 2)
		return ;
	rotate(&ctx->b);
	write(1, "rb\n", 3);
	ctx->counts[OP_RB]++;
	ctx->total++;
}

void	execute_rrb(t_context *ctx)
{
	if (ctx->b.size < 2)
		return ;
	reverse_rotate(&ctx->b);
	write(1, "rrb\n", 4);
	ctx->counts[OP_RRB]++;
	ctx->total++;
}
