/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 20:12:19 by z                 #+#    #+#             */
/*   Updated: 2026/09/06 20:13:20 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *stack)
{
}

/*
  Create assign_ranks.c with this structure:

  outer = stack top

  while outer exists:
      rank = 0
      scan = stack top

      while scan exists:
          if scan value is smaller than outer value:
              increment rank
          advance scan

      assign rank to outer
      advance outer

  Important details:

  - reset rank to 0 for every outer node;
  - reset scan to stack->top for every outer node;
  - assign the rank only after the inner scan finishes;
  - never modify value, next, top, or size;
  - allocate and free nothing.

*/
