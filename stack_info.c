/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_info.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:29:55 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 12:20:20 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	ft_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	min = stack->value;
	pos = 0;
	min_pos = 0;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	ft_move_to_top_a(t_data *d, int pos)
{
	int	size;

	size = ft_stack_size(d->a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(d);
	}
	else
	{
		while (pos++ < size)
			rra(d);
	}
}

void	ft_move_to_top_b(t_data *d, int pos)
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
