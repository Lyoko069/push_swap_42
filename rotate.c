/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:32:39 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/13 11:07:57 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **src)
{
	t_stack	*first;
	t_stack	*last;

	if (src == NULL || *src == NULL || (*src)->next == NULL)
		return ;
	first = *src;
	last = *src;
	while (last->next != NULL)
		last = last->next;
	*src = first->next;
	(*src)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_data *d)
{
	ft_rotate(&d->a);
	d->count[RA]++;
	write(1, "ra\n", 3);
}

void	rb(t_data *d)
{
	ft_rotate(&d->b);
	d->count[RB]++;
	write(1, "rb\n", 3);
}

void	rr(t_data *d)
{
	ft_rotate(&d->a);
	ft_rotate(&d->b);
	d->count[RR]++;
	write(1, "rr\n", 3);
}
