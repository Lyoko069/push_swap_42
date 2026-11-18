/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_radix.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 11:50:15 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 11:50:15 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_sort_complex(t_data *d)
{
	int	size;
	int	bits;
	int	bit;
	int	i;

	size = ft_stack_size(d->a);
	bits = ft_max_bits(size);
	bit = 0;
	while (bit < bits && !ft_is_sorted(d->a))
	{
		i = 0;
		while (i < size)
		{
			if (((d->a->index >> bit) & 1) == 0)
				pb(d);
			else
				ra(d);
			i++;
		}
		while (d->b != NULL)
			pa(d);
		bit++;
	}
}
