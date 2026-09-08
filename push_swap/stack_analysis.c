/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:10:54 by z                 #+#    #+#             */
/*   Updated: 2026/09/08 21:13:53 by z                ###   ########.fr       */
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

double	compute_disorder(const t_stack *stack)
{
	size_t			total_pairs;
	size_t			mistakes;
	const t_node	*outer;
	const t_node	*inner;

	if (stack->size < 2)
		return (0.0);
	total_pairs = 0;
	mistakes = 0;
	outer = stack->top;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->value > inner->value)
				mistakes += 1;
			total_pairs += 1;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return ((double)mistakes / total_pairs);
}

int	is_sorted(const t_stack *stack)
{
	const t_node	*ptr;

	ptr = stack->top;
	if (stack->size < 2)
		return (1);
	while (ptr->next)
	{
		if (ptr->next->value < ptr->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
