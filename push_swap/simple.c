/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 10:04:01 by z                 #+#    #+#             */
/*   Updated: 2026/09/12 11:11:37 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	find_pos(t_node *current, int wanted_rank)
{
	size_t	pos;

	pos = 0;
	while (current->rank != wanted_rank)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

static void	push_to_b(t_context *ctx, size_t pos, int wanted_rank)
{
	if (pos <= ctx->a.size / 2)
	{
		while (ctx->a.top->rank != wanted_rank)
			execute_ra(ctx);
		execute_pb(ctx);
	}
	else
	{
		while (ctx->a.top->rank != wanted_rank)
			execute_rra(ctx);
		execute_pb(ctx);
	}
}

void	run_simple(t_context *ctx)
{
	int		wanted_rank;
	t_node	*current;
	size_t	pos;

	wanted_rank = 0;
	while (ctx->a.size > 1)
	{
		current = ctx->a.top;
		pos = find_pos(current, wanted_rank);
		push_to_b(ctx, pos, wanted_rank);
		wanted_rank++;
	}
	while (ctx->b.top)
		execute_pa(ctx);
}
