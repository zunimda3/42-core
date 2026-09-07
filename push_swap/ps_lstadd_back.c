/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 17:32:32 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 17:32:58 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_stack *stack, t_node *node)
{
	t_node	*ptr;

	ptr = stack->top;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
}
