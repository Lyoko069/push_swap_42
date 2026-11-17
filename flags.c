/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   flags.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/17 13:15:20 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:22:03 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

static int	ft_set_strategy(t_data *d, t_strategy strategy)
{
	if (d->strategy_set)
		return (-1);
	d->strategy = strategy;
	d->strategy_set = 1;
	return (1);
}

int	ft_parse_flag(t_data *d, char *arg)
{
	if (!ft_strcmp(arg, "--bench"))
		d->bench = 1;
	else if (!ft_strcmp(arg, "--simple"))
		return (ft_set_strategy(d, SIMPLE));
	else if (!ft_strcmp(arg, "--medium"))
		return (ft_set_strategy(d, MEDIUM));
	else if (!ft_strcmp(arg, "--complex"))
		return (ft_set_strategy(d, COMPLEX));
	else if (!ft_strcmp(arg, "--adaptive"))
		return (ft_set_strategy(d, ADAPTIVE));
	else
		return (0);
	return (1);
}
