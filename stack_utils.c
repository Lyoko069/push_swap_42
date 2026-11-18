/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 12:23:43 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:23:05 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = node;
	node->prev = last;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	ft_has_duplicate(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
