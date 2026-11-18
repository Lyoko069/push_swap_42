/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:19:12 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:20:44 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_compute_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double) mistakes / total_pairs);
}
