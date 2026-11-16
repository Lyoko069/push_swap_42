/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:08:47 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/16 14:34:04 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack **src)
{
	t_stack	*tmp;
	int		i;

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
	if ((*src)->value > (*src)->next->value
		&& (*src)->value > (*src)->next->next->value)
		ra(src);
	else if ((*src)->next->value > (*src)->value
		&& (*src)->next->value > (*src)->next->next->value)
		rra(src);
	if ((*src)->value > (*src)->next->value)
		sa(src);
}

int	get_min_pos(t_stack **src)
{
	t_stack	*tmp;
	int		min_val;
	int		pos;
	int		min_pos;

	tmp = *src;
	min_val = tmp->value;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	sort_five(t_stack **A, t_stack **B)
{
	int	min_pos;

	while (ft_stacksize(A) > 3)
	{
		min_pos = get_min_pos(A);
		if (min_pos <= ft_stacksize(A) / 2)
		{
			while (min_pos-- > 0)
				ra(A);
		}
		else
		{
			while (min_pos++ < ft_stacksize(A))
				rra(A);
		}
		pb(A, B);
	}
	sort_three(A);
	while (*B)
		pa(A, B);
}
