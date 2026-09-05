/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:32:51 by z                 #+#    #+#             */
/*   Updated: 2026/09/05 10:38:52 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack *stack)
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
