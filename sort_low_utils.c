/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_low_utils.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 12:20:20 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 12:20:20 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_pos(t_stack *stack)
{
	int	pos;
	int	max;
	int	max_pos;

	pos = 0;
	max = -1;
	max_pos = 0;
	while (stack != NULL)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

static int	ft_b_target_pos(t_stack *b, int index)
{
	t_stack	*cur;
	int		pos;
	int		best;
	int		best_pos;

	cur = b;
	pos = 0;
	best = -1;
	best_pos = -1;
	while (cur != NULL)
	{
		if (cur->index < index && cur->index > best)
		{
			best = cur->index;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	if (best_pos == -1)
		return (ft_max_pos(b));
	return (best_pos);
}

static int	ft_bottom_index(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index);
}

void	ft_low_split(t_data *d, int *keep, int n)
{
	int	i;
	int	last;

	last = n - 1;
	while (last >= 0 && keep[last])
		last--;
	i = 0;
	while (i <= last)
	{
		if (keep[i])
			ra(d);
		else
		{
			ft_move_to_top_b(d, ft_b_target_pos(d->b, d->a->index));
			pb(d);
		}
		i++;
	}
}

void	ft_low_merge(t_data *d)
{
	int	left;

	ft_move_to_top_a(d, ft_min_pos(d->a));
	ft_move_to_top_b(d, ft_max_pos(d->b));
	left = ft_stack_size(d->a);
	while (d->b != NULL)
	{
		if (left > 0 && ft_bottom_index(d->a) > d->b->index)
		{
			rra(d);
			left--;
		}
		else
			pa(d);
	}
	ft_move_to_top_a(d, ft_min_pos(d->a));
}
