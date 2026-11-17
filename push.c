/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:28:46 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/13 11:03:23 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	tmp->next = *dest;
	tmp->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = tmp;
	*dest = tmp;
}

void	pa(t_data *d)
{
	ft_push(&d->a, &d->b);
	d->count[PA]++;
	write(1, "pa\n", 3);
}

void	pb(t_data *d)
{
	ft_push(&d->b, &d->a);
	d->count[PB]++;
	write(1, "pb\n", 3);
}
