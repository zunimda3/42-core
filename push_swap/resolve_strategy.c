/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 19:55:06 by z                 #+#    #+#             */
/*   Updated: 2026/09/08 19:58:35 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
