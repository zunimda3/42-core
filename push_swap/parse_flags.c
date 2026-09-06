/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 13:07:28 by naamir            #+#    #+#             */
/*   Updated: 2026/09/06 16:12:41 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(const char *arg, const char *flag)
{
	size_t	len;

	len = 0;
	while (flag[len])
		len++;
	if (ft_strncmp(arg, flag, len) != 0)
		return (0);
	return (arg[len] == '\0');
}

static void	set_flag(t_context *ctx, int type, int *status)
{
	if (type == 0)
	{
		if (ctx->bench_enabled)
			*status = 0;
		else
			ctx->bench_enabled = 1;
		return ;
	}
	if (ctx->strategy != STRATEGY_ADAPTIVE)
	{
		*status = 0;
		return ;
	}
	if (type == 1)
		ctx->strategy = STRATEGY_SIMPLE;
	else if (type == 2)
		ctx->strategy = STRATEGY_MEDIUM;
	else if (type == 3)
		ctx->strategy = STRATEGY_COMPLEX;
	else if (type == 4)
		ctx->strategy = STRATEGY_ADAPTIVE;
}

static int	flag_type(const char *arg)
{
	if (is_flag(arg, "--bench"))
		return (0);
	if (is_flag(arg, "--simple"))
		return (1);
	if (is_flag(arg, "--medium"))
		return (2);
	if (is_flag(arg, "--complex"))
		return (3);
	if (is_flag(arg, "--adaptive"))
		return (4);
	return (-1);
}

int	parse_flags(t_context *ctx, int argc, char **argv, int *start)
{
	int	i;
	int	status;
	int	type;

	status = 1;
	i = 1;
	while (i < argc && status == 1)
	{
		type = flag_type(argv[i]);
		if (type < 0)
		{
			*start = i;
			return (1);
		}
		set_flag(ctx, type, &status);
		i++;
	}
	*start = argc;
	return (status);
}
