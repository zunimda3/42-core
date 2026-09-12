/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_dispatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:36:33 by z                 #+#    #+#             */
/*   Updated: 2026/09/12 11:10:45 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_strategy(t_context *ctx)
{
	t_strategy	strategy;

	if (is_sorted(&ctx->a))
		return (1);
	strategy = resolve_strategy(ctx->strategy, ctx->initial_disorder);
	if (strategy == STRATEGY_SIMPLE)
	{
		run_simple(ctx);
		return (1);
	}
	else if (strategy == STRATEGY_MEDIUM)
		return (0);
	else
		return (0);
}

t_strategy	resolve_strategy(t_strategy requested, double disorder)
{
	if (requested == STRATEGY_ADAPTIVE)
	{
		if (disorder < 0.2)
			return (STRATEGY_SIMPLE);
		else if (disorder < 0.5)
			return (STRATEGY_MEDIUM);
		else
			return (STRATEGY_COMPLEX);
	}
	return (requested);
}
