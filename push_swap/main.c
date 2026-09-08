/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <naamir@42kl.edu.my>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 09:47:59 by z                 #+#    #+#             */
/*   Updated: 2026/09/08 19:42:58 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			ok = parse_numbers(&context, argc, argv, start);
			if (ok)
			{
				context.initial_disorder = compute_disorder(&context.a);
				assign_ranks(&context.a);
			}
		}
	}
	if (!ok)
		write(2, "Error\n", 6);
	ps_lstclear(&context.a);
	ps_lstclear(&context.b);
	return (0);
}
