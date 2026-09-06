/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:34:09 by naamir            #+#    #+#             */
/*   Updated: 2026/09/06 12:56:06 by naamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *str)
{
	if (!*str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (!*(str + 1))
			return (0);
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	is_in_a(t_context *ctx, int num)
{
	t_node	*ptr;

	ptr = ctx->a.top;
	while (ptr)
	{
		if (num == ptr->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static t_node	*validated_node(t_context *ctx, char *str)
{
	int		num;
	t_node	*new;

	if (!is_valid_int(str))
		return (NULL);
	num = ft_atoi(str);
	if (!is_in_a(ctx, num))
		return (NULL);
	new = ps_node_new(num);
	if (!new)
		return (NULL);
	return (new);
}

int	parse_numbers(t_context *ctx, int argc, char **argv, int start)
{
	t_node	*new;
	t_node	*tail;

	tail = NULL;
	while (start < argc)
	{
		new = validated_node(ctx, argv[start]);
		if (!new)
			return (0);
		if (tail)
			tail->next = new;
		else
			ctx->a.top = new;
		tail = new;
		ctx->a.size++;
		start++;
	}
	return (1);
}
