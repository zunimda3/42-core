/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:03:34 by z                 #+#    #+#             */
/*   Updated: 2026/09/12 19:32:50 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	rot_cost(size_t index, size_t size)
{
	if (index < size - index)
		return (index);
	else
		return (size - index);
}

static size_t	nearest_member_index(t_stack *stack, int lo, int hi)
{
	size_t	size;
	size_t	best;
	t_node	*cursor;
	size_t	index;
	size_t	best_cost;

	index = 0;
	best = 0;
	size = stack->size;
	best_cost = size;
	cursor = stack->top;
	while (cursor)
	{
		if (cursor->rank >= lo && cursor->rank <= hi && rot_cost(index,
				size) < best_cost)
		{
			best = index;
			best_cost = rot_cost(index, size);
		}
		cursor = cursor->next;
		index++;
	}
	return (best);
}

static void	push_chunk_to_b(t_context *ctx, int lo, int hi)
{
	int		remaining;

	remaining = hi - lo + 1;
	while (remaining > 0)
	{
		if (ctx->a.top->rank >= lo && ctx->a.top->rank <= hi)
		{
			execute_pb(ctx);
			remaining--;
		}
		else
			execute_ra(ctx);
	}
}

static void	restore_from_b(t_context *ctx)
{
	int		wanted_rank;
	size_t	index;

	while (ctx->b.size > 0)
	{
		wanted_rank = (int)ctx->b.size - 1;
		index = nearest_member_index(&ctx->b, wanted_rank, wanted_rank);
		if (index <= ctx->b.size / 2)
			while (ctx->b.top->rank != wanted_rank)
				execute_rb(ctx);
		else
			while (ctx->b.top->rank != wanted_rank)
				execute_rrb(ctx);
		execute_pa(ctx);
	}
}

void	run_medium(t_context *ctx)
{
	int	size;
	int	width;
	int	lo;
	int	hi;

	size = (int)ctx->a.size;
	width = 1;
	while (width * width < size)
		width++;
	lo = 0;
	while (lo < size)
	{
		hi = lo + width - 1;
		if (hi >= size)
			hi = size - 1;
		push_chunk_to_b(ctx, lo, hi);
		lo = hi + 1;
	}
	restore_from_b(ctx);
}
