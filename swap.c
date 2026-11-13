/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:30:01 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/13 11:00:57 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **src)
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

void	sa(t_stack **A)
{
	ft_swap(A);
	write(1, "sa\n", 3);
}

void	sb(t_stack **B)
{
	ft_swap(B);
	write(1, "sb\n", 3);
}

void	ss(t_stack **A, t_stack **B)
{
	ft_swap(A);
	ft_swap(B);
	write(1, "ss\n", 3);
}
