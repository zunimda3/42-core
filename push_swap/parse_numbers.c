/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naamir <naamir@42kl.edu.my>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:34:09 by naamir            #+#    #+#             */
/*   Updated: 2026/09/08 21:08:54 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	is_valid_int(const char *str)
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

static int	convert_int(const char *str, int *result)
{
	long long	value;
	long long	limit;
	int			sign;

	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	limit = INT_MAX;
	if (sign == -1)
		limit = -(long long)INT_MIN;
	value = 0;
	while (*str)
	{
		if (value > (limit - (*str - '0')) / 10)
			return (0);
		value = value * 10 + (*str - '0');
		str++;
	}
	*result = (int)(value * sign);
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

	if (!is_valid_int(str) || !convert_int(str, &num))
		return (NULL);
	if (!is_in_a(ctx, num))
		return (NULL);
	new = ps_lstnew(num);
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
