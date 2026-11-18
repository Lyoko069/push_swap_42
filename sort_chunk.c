/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_chunk.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 11:34:40 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 11:34:40 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chunk_size(int size)
{
	int	root;

	root = 1;
	while ((root + 1) * (root + 1) <= size)
		root++;
	return (root * 3 / 2);
}

static void	ft_push_chunks(t_data *d, int chunk)
{
	int	i;

	i = 0;
	while (d->a != NULL)
	{
		if (d->a->index <= i)
		{
			pb(d);
			rb(d);
			i++;
		}
		else if (d->a->index <= i + chunk)
		{
			pb(d);
			i++;
		}
		else
			ra(d);
	}
}

static int	ft_index_pos(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack != NULL && stack->index != index)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	ft_move_to_top_b(t_data *d, int pos)
{
	int	size;

	size = ft_stack_size(d->b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(d);
	}
	else
	{
		while (pos++ < size)
			rrb(d);
	}
}

void	ft_sort_medium(t_data *d)
{
	ft_push_chunks(d, ft_chunk_size(ft_stack_size(d->a)));
	while (d->b != NULL)
	{
		ft_move_to_top_b(d, ft_index_pos(d->b, ft_stack_size(d->b) - 1));
		pa(d);
	}
}
