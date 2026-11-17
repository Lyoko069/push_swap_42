/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parser_arg.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/29 12:11:11 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:22:39 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_parser_arg(char *argv, long *res)
{
	int		i;
	long	nbr;
	int		sig;

	nbr = 0;
	i = 0;
	sig = 1;
	if (argv[i] == '-')
		sig = -1;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!ft_isdigit(argv[i]))
		return (0);
	while (ft_isdigit(argv[i]))
	{
		nbr = (nbr * 10) + (argv[i] - '0');
		if (nbr * sig > 2147483647 || nbr * sig < -2147483648)
			return (0);
		i++;
	}
	if (argv[i] != '\0')
		return (0);
	*res = nbr * sig;
	return (1);
}
