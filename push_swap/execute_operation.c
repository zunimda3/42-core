/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:30:27 by z                 #+#    #+#             */
/*   Updated: 2026/09/07 19:34:53 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_operation(t_context *ctx, t_operation op)
{
	if (op == OP_SA)
		execute_sa(ctx);
	else if (op == OP_SB)
		execute_sb(ctx);
	else if (op == OP_SS)
		execute_ss(ctx);
	else if (op == OP_PA)
		execute_pa(ctx);
	else if (op == OP_PB)
		execute_pb(ctx);
	else if (op == OP_RA)
		execute_ra(ctx);
	else if (op == OP_RB)
		execute_rb(ctx);
	else if (op == OP_RR)
		execute_rr(ctx);
	else if (op == OP_RRA)
		execute_rra(ctx);
	else if (op == OP_RRB)
		execute_rrb(ctx);
	else if (op == OP_RRR)
		execute_rrr(ctx);
}
