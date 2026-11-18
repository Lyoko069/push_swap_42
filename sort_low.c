/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_low.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 12:13:57 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 12:20:20 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lis(int *idx, int *len, int *prev, int n)
{
	int	i;
	int	j;
	int	best;

	best = 0;
	i = -1;
	while (++i < n)
	{
		len[i] = 1;
		prev[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (idx[j] < idx[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
		}
		if (len[i] > len[best])
			best = i;
	}
	return (best);
}

static void	ft_mark_keep(int *keep, int *prev, int best, int n)
{
	int	i;

	i = 0;
	while (i < n)
		keep[i++] = 0;
	while (best != -1)
	{
		keep[best] = 1;
		best = prev[best];
	}
}

static void	ft_fill_indexes(t_stack *stack, int *buf)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		buf[i++] = stack->index;
		stack = stack->next;
	}
}

void	ft_sort_low(t_data *d)
{
	int	n;
	int	*buf;

	n = ft_stack_size(d->a);
	buf = malloc(sizeof(int) * n * 3);
	if (buf == NULL)
	{
		ft_sort_medium(d);
		return ;
	}
	ft_fill_indexes(d->a, buf);
	ft_mark_keep(buf + n, buf + 2 * n, ft_lis(buf, buf + n, buf + 2 * n, n),
		n);
	ft_low_split(d, buf + n, n);
	free(buf);
	ft_low_merge(d);
}
