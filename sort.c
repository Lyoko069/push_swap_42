/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:36:19 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 12:43:19 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_strategy	ft_choose(t_data *d)
{
	if (d->strategy != ADAPTIVE)
		return (d->strategy);
	if (d->disorder < 0.2)
		return (LOW);
	if (d->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	ft_sort(t_data *d)
{
	d->used = ft_choose(d);
	if (ft_is_sorted(d->a))
		return ;
	if (ft_stack_size(d->a) <= 5)
		ft_sort_small(d);
	else if (d->used == SIMPLE)
		ft_sort_simple(d);
	else if (d->used == MEDIUM)
		ft_sort_medium(d);
	else if (d->used == COMPLEX)
		ft_sort_complex(d);
	else
		ft_sort_low(d);
}
