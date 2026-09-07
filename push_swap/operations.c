/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:58:21 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 17:58:32 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (stack->size < 2)
		return ;
	a = stack->top;
	b = a->next;
	a->next = b->next;
	b->next = a;
	stack->top = b;
}

void	push(t_stack *source, t_stack *destination)
{
	t_node	*moved;

	if (!source->top)
		return ;
	moved = source->top;
	source->top = moved->next;
	moved->next = destination->top;
	destination->top = moved;
	source->size--;
	destination->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*moved;

	if (stack->size < 2)
		return ;
	moved = stack->top;
	stack->top = stack->top->next;
	moved->next = NULL;
	ps_lstadd_back(stack, moved);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*previous;

	if (stack->size < 2)
		return ;
	previous = stack->top;
	last = previous->next;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
