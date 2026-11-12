/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rotate.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 13:32:39 by jjurado          #+#    #+#              */
/*   Updated: 2026/11/12 12:30:27 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **src)
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
