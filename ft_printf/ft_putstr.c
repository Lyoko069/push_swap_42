/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 11:55:48 by jjurado          #+#    #+#              */
/*   Updated: 2026/10/21 10:21:01 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putstr(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_parser_str(const char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	else
		return (ft_putstr(s));
}
