/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:50:46 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 19:41:24 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_sa(t_context *ctx)
{
	if (ctx->a.size < 2)
		return ;
	swap(&ctx->a);
	write(1, "sa\n", 3);
	ctx->counts[OP_SA]++;
	ctx->total++;
}

void	execute_pa(t_context *ctx)
{
	if (ctx->b.size < 1)
		return ;
	push(&ctx->b, &ctx->a);
	write(1, "pa\n", 3);
	ctx->counts[OP_PA]++;
	ctx->total++;
}

void	execute_ra(t_context *ctx)
{
	if (ctx->a.size < 2)
		return ;
	rotate(&ctx->a);
	write(1, "ra\n", 3);
	ctx->counts[OP_RA]++;
	ctx->total++;
}

void	execute_rra(t_context *ctx)
{
	if (ctx->a.size < 2)
		return ;
	reverse_rotate(&ctx->a);
	write(1, "rra\n", 4);
	ctx->counts[OP_RRA]++;
	ctx->total++;
}
