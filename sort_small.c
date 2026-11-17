/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_small.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:29:55 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:55:57 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_data *d)
{
	int	first;
	int	second;
	int	third;

	first = d->a->value;
	second = d->a->next->value;
	third = d->a->next->next->value;
	if (first > second && first > third)
		ra(d);
	else if (second > first && second > third)
		rra(d);
	if (d->a->value > d->a->next->value)
		sa(d);
}

void	ft_sort_small(t_data *d)
{
	int	size;

	size = ft_stack_size(d->a);
	if (size == 2)
		sa(d);
	else if (size == 3)
		ft_sort_three(d);
	else
		ft_sort_simple(d);
}
