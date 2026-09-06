/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:04:22 by naamir            #+#    #+#             */
/*   Updated: 2026/08/05 16:04:23 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cleaner;
	t_list	*temp;

	if (!lst || !del)
		return ;
	cleaner = *lst;
	while (cleaner)
	{
		temp = cleaner;
		cleaner = cleaner->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
