/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sorter.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/16 11:08:47 by jjurado          #+#    #+#              */
/*   Updated: 2026/11/16 13:13:29 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_stacksize(t_stack **src)
{
	t_stack			*tmp;
	unsigned int	i;

	tmp = *src;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	sort_three(t_stack **src)
{
	if (!src || !*src || !(*src)->next || !(*src)->next->next)
		return ;
	if ((*src)->value > (*src)->next->value && (*src)->value > (*src)->next->next->value)
		ra(src);
	else if ((*src)->next->value > (*src)->value && (*src)->next->value > (*src)->next->next->value)
		rra(src);
	if ((*src)->value > (*src)->next->value)
		sa(src);
}

void	sort_five(t_stack **A, t_stack **B)
{
	int	min_pos;

	min_pos = (*A)->index;
	while (ft_stacksize(A) > 3)
	{
		while ((*A)->next != NULL)
		{
			if ((*A)->value > (*A)->next->value)
				min_pos = (*A)->next->index;
			*A = (*A)->next;
		}
		if (min_pos <= ft_stacksize(A) / 2)
		{
			while (min_pos >= 0)
			{
				ra(A);
				min_pos--;
			}
		}
		else
		{
			while (min_pos < ft_stacksize(A))
			{
				rra(A);
				min_pos++;
			}
		}
		pb(A, B);
	}
	sort_three(A);
	while (*B)
	{
		pa(A, B);
		*B = (*B)->next;
	}
}
