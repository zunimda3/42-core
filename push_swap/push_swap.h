/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:08:44 by z                 #+#    #+#             */
/*   Updated: 2026/09/05 10:41:48 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	size_t			size;
}					t_stack;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}					t_strategy;

typedef struct s_context
{
	t_stack			a;
	t_stack			b;
	t_strategy		strategy;
	int				bench_enabled;
	double			initial_disorder;
}					t_context;

void				ft_lstadd_top(t_stack *stack, t_node *new);
t_node				*ft_lstnew(int value);
void				ft_lstclear(t_stack *stack);
void				context_init(t_context *content);

#endif
