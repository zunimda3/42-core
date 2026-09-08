/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 20:52:31 by z                 #+#    #+#             */
/*   Updated: 2026/09/08 21:22:21 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_lstnew(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->rank = -1;
	return (new);
}

void	ps_lstadd_top(t_stack *stack, t_node *new)
{
	new->next = stack->top;
	stack->top = new;
	stack->size += 1;
}

void	ps_lstadd_back(t_stack *stack, t_node *node)
{
	t_node	*ptr;

	ptr = stack->top;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
}

void	ps_lstclear(t_stack *stack)
{
	t_node	*cleaner;
	t_node	*temp;

	cleaner = stack->top;
	while (cleaner)
	{
		temp = cleaner;
		cleaner = cleaner->next;
		free(temp);
	}
	stack->top = NULL;
	stack->size = 0;
}
