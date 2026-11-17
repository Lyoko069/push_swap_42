/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   index.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:10:00 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:10:00 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_stack *stack)
{
	t_stack	*node;
	t_stack	*cmp;

	node = stack;
	while (node != NULL)
	{
		node->index = 0;
		cmp = stack;
		while (cmp != NULL)
		{
			if (cmp->value < node->value)
				node->index++;
			cmp = cmp->next;
		}
		node = node->next;
	}
}
