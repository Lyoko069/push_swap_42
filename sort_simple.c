/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_simple.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:33:22 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:55:59 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_data *d)
{
	int	size;

	size = ft_stack_size(d->a);
	while (size > 3 && !ft_is_sorted(d->a))
	{
		ft_move_to_top_a(d, ft_min_pos(d->a));
		if (ft_is_sorted(d->a))
			break ;
		pb(d);
		size--;
	}
	if (size == 3)
		ft_sort_three(d);
	while (d->b != NULL)
		pa(d);
}
