/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:08:44 by z                 #+#    #+#             */
/*   Updated: 2026/09/06 16:02:56 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

void				ps_lstadd_top(t_stack *stack, t_node *new);
t_node				*ps_node_new(int value);
void				ps_lstclear(t_stack *stack);
void				context_init(t_context *content);

int					is_valid_int(const char *str);
int					parse_numbers(t_context *ctx, int argc, char **argv,
						int start);
int					parse_flags(t_context *ctx, int argc, char **argv,
						int *start);

#endif
