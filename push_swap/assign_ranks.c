/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 20:12:19 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 16:43:17 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *stack)
{
	t_node	*outer;
	t_node	*scan;
	size_t	rank;

	outer = stack->top;
	while (outer)
	{
		rank = 0;
		scan = stack->top;
		while (scan)
		{
			if (scan->value < outer->value)
				rank++;
			scan = scan->next;
		}
		outer->rank = rank;
		outer = outer->next;
	}
}
