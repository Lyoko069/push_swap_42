/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/11 13:30:01 by jjurado          #+#    #+#              */
/*   Updated: 2026/11/12 13:19:31 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **src)
{
	t_stack	*first;
	t_stack	*second;

	if (*src == NULL || (*src)->next == NULL)
		return ;
	first = *src;
	second = (*src)->next;
	if (second->next != NULL)
	{
		first->next = second->next;
		(first->next)->prev = first;
	}
	else
		first->next = NULL;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*src = second;
}
