/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:27:54 by z                 #+#    #+#             */
/*   Updated: 2026/09/05 10:36:18 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	context_init(t_context *context)
{
	context->a.top = NULL;
	context->a.size = 0;
	context->b.top = NULL;
	context->b.size = 0;
	context->strategy = STRATEGY_ADAPTIVE;
	context->bench_enabled = 0;
	context->initial_disorder = 0.0;
}
