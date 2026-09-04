/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:29:55 by z                 #+#    #+#             */
/*   Updated: 2026/09/02 15:39:10 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct t_stack
{
	t_node			*top;
	size_t			size;
}					t_stack;

void				ft_lstadd_top(t_stack *stack, t_node *new);
t_node				*ft_lstnew(int value);
void				ft_lstclear(t_stack *stack);

#endif
