/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:40:35 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/13 11:07:51 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **src)
{
	t_stack	*last;

	if (src == NULL || *src == NULL || (*src)->next == NULL)
		return ;
	last = *src;
	while (last->next != NULL)
		last = last->next;
	(last->prev)->next = NULL;
	last->prev = NULL;
	last->next = *src;
	(*src)->prev = last;
	*src = last;
}

void	rra(t_data *d)
{
	ft_reverse_rotate(&d->a);
	d->count[RRA]++;
	write(1, "rra\n", 4);
}

void	rrb(t_data *d)
{
	ft_reverse_rotate(&d->b);
	d->count[RRB]++;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *d)
{
	ft_reverse_rotate(&d->a);
	ft_reverse_rotate(&d->b);
	d->count[RRR]++;
	write(1, "rrr\n", 4);
}
