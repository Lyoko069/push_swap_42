/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:36:19 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:36:19 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_data *d)
{
	if (ft_stack_size(d->a) <= 5)
		ft_sort_small(d);
	else if (d->strategy == SIMPLE)
		ft_sort_simple(d);
	else
		ft_sort_simple(d);
}
