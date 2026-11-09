/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:11:11 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/09 13:50:57 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

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
	while (argv[i] != '\0' && ft_isspace(argv[i]))
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			sig *= -1;
		i++;
	}
	while (argv[i] != '\0' && ft_isdigit(argv[i]))
	{
		nbr = (nbr * 10) + (argv[i] - '0');
		i++;
	}
	if (argv[i] != '\0' || (nbr > 2147483647 || nbr < -2147483648))
		return (0);
	*res = nbr;
	return (1);
}
