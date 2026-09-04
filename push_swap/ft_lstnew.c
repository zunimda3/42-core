/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:32:06 by z                 #+#    #+#             */
/*   Updated: 2026/09/02 15:26:27 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*ft_lstnew(int value)
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
