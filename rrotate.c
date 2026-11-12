/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   rrotate.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 12:40:35 by jjurado          #+#    #+#              */
/*   Updated: 2026/11/12 13:02:27 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **src)
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
