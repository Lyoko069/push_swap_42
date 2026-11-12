/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 13:28:46 by jjurado          #+#    #+#              */
/*   Updated: 2026/11/12 12:14:21 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **dest, t_stack **src)
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
