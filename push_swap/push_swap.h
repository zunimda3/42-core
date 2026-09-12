/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 10:08:44 by z                 #+#    #+#             */
/*   Updated: 2026/09/12 11:09:35 by z                ###   ########.fr       */
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

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}					t_operation;

typedef struct s_context
{
	t_stack			a;
	t_stack			b;
	t_strategy		strategy;
	int				bench_enabled;
	double			initial_disorder;
	size_t			counts[OP_COUNT];
	size_t			total;
}					t_context;

/* Initialize Context */
void				context_init(t_context *content);

/* Parse Flags & Numbers */
int					parse_flags(t_context *ctx, int argc, char **argv,
						int *start);
int					parse_numbers(t_context *ctx, int argc, char **argv,
						int start);

/* Operations for Linked Lists*/
t_node				*ps_lstnew(int value);
void				ps_lstadd_top(t_stack *stack, t_node *new);
void				ps_lstadd_back(t_stack *stack, t_node *node);
void				ps_lstclear(t_stack *stack);

/* Stack Analysis */
void				assign_ranks(t_stack *stack);
double				compute_disorder(const t_stack *stack);
int					is_sorted(const t_stack *stack);

/* Operation Definition */
void				swap(t_stack *stack);
void				push(t_stack *source, t_stack *destination);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);

/* Operation Executions */
void				execute_sa(t_context *ctx);
void				execute_pa(t_context *ctx);
void				execute_ra(t_context *ctx);
void				execute_rra(t_context *ctx);
void				execute_sb(t_context *ctx);
void				execute_pb(t_context *ctx);
void				execute_rb(t_context *ctx);
void				execute_rrb(t_context *ctx);
void				execute_ss(t_context *ctx);
void				execute_rr(t_context *ctx);
void				execute_rrr(t_context *ctx);

void				execute_operation(t_context *ctx, t_operation op);

/* Strategy Dispatch */
t_strategy			resolve_strategy(t_strategy requested, double disorder);
int					run_strategy(t_context *ctx);

void				run_simple(t_context *ctx);

#endif
