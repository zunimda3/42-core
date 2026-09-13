/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:27:42 by naamir            #+#    #+#             */
/*   Updated: 2026/09/13 20:12:53 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	put_size_fd(size_t n, int fd)
{
	char	res;

	if (n >= 10)
		put_size_fd(n / 10, fd);
	res = n % 10 + '0';
	write(fd, &res, 1);
}

static void	print_disorder(const t_context *ctx)
{
	size_t	scaled;

	scaled = (size_t)(ctx->initial_disorder * 10000 + 0.5);
	write(2, "[bench] disorder: ", 18);
	put_size_fd((scaled / 100), 2);
	write(2, ".", 1);
	if (scaled % 100 < 10)
		write(2, "0", 1);
	put_size_fd((scaled % 100), 2);
	write(2, "%", 1);
	write(2, "\n", 1);
}

static void	print_strategy(const t_context *ctx)
{
	t_strategy	strategy;
	t_strategy	complexity;

	strategy = ctx->strategy;
	write(2, "[bench] strategy: ", 18);
	if (strategy == STRATEGY_SIMPLE)
		write(2, "Simple", 6);
	else if (strategy == STRATEGY_MEDIUM)
		write(2, "Medium", 6);
	else if (strategy == STRATEGY_COMPLEX)
		write(2, "Complex", 7);
	else
		write(2, "Adaptive", 8);
	write(2, " / ", 3);
	complexity = resolve_strategy(strategy, ctx->initial_disorder);
	if (complexity == STRATEGY_SIMPLE)
		write(2, "O(n²)", 6);
	else if (complexity == STRATEGY_MEDIUM)
		write(2, "O(n√n)", 8);
	else if (complexity == STRATEGY_COMPLEX)
		write(2, "O(n log n)", 10);
	write(2, "\n", 1);
}

static void	print_counts(const t_context *ctx)
{
	const char *const	labels[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	size_t				i;

	i = 0;
	while (i < OP_COUNT)
	{
		if (i == OP_SA || i == OP_RA)
			write(2, "[bench] ", 8);
		else
			write(2, "  ", 2);
		write(2, labels[i], ft_strlen(labels[i]));
		write(2, ": ", 2);
		put_size_fd(ctx->counts[i], 2);
		if (i == OP_PB || i == OP_RRR)
			write(2, "\n", 1);
		i++;
	}
}

void	print_benchmark(const t_context *ctx)
{
	print_disorder(ctx);
	print_strategy(ctx);
	write(2, "[bench] total_ops: ", 19);
	put_size_fd(ctx->total, 2);
	write(2, "\n", 1);
	print_counts(ctx);
}
