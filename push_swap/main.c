/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 09:47:59 by z                 #+#    #+#             */
/*   Updated: 2026/09/12 11:38:57 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prepare_and_sort(t_context *ctx, int argc, char **argv, int start)
{
	if (!parse_numbers(ctx, argc, argv, start))
		return (0);
	ctx->initial_disorder = compute_disorder(&ctx->a);
	assign_ranks(&ctx->a);
	return (run_strategy(ctx));
}

int	main(int argc, char **argv)
{
	t_context	context;
	int			ok;
	int			start;

	context_init(&context);
	ok = 1;
	start = 1;
	if (argc > 1)
	{
		ok = parse_flags(&context, argc, argv, &start);
		if (ok && start < argc)
			ok = prepare_and_sort(&context, argc, argv, start);
	}
	if (!ok)
		write(2, "Error\n", 6);
	ps_lstclear(&context.a);
	ps_lstclear(&context.b);
	return (0);
}
