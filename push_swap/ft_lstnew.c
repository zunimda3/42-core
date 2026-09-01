/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:32:06 by z                 #+#    #+#             */
/*   Updated: 2026/09/01 21:39:32 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}
