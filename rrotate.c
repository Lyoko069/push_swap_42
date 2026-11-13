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

void	rra(t_stack **A)
{
	ft_reverse_rotate(A);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **B)
{
	ft_reverse_rotate(B);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **A, t_stack **B)
{
	ft_reverse_rotate(A);
	ft_reverse_rotate(B);
	write(1, "rrr\n", 4);
}
