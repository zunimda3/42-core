/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:32:51 by z                 #+#    #+#             */
/*   Updated: 2026/09/05 13:42:18 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
