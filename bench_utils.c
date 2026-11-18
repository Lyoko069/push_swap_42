/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_utils.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 12:43:19 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 12:43:19 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_err(const char *s)
{
	write(2, s, ft_strlen(s));
}

void	ft_putnbr_err(long n)
{
	char	c;

	if (n >= 10)
		ft_putnbr_err(n / 10);
	c = '0' + n % 10;
	write(2, &c, 1);
}

char	*ft_strategy_name(t_strategy strategy)
{
	if (strategy == SIMPLE)
		return ("Simple");
	if (strategy == MEDIUM)
		return ("Medium");
	if (strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*ft_class_name(t_strategy used)
{
	if (used == SIMPLE)
		return ("O(n^2)");
	if (used == MEDIUM)
		return ("O(n\xe2\x88\x9an)");
	if (used == COMPLEX)
		return ("O(n log n)");
	return ("O(n)");
}
