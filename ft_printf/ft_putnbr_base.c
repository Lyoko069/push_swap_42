/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:35:33 by jjurado           #+#    #+#             */
/*   Updated: 2026/10/21 11:12:28 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long) base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += ft_putchar(base[nbr % base_len]);
	return (count);
}

int	ft_parser_nbr(unsigned long nbr, char c)
{
	if (c == 'd' || c == 'i')
	{
		if ((long) nbr < 0)
			return (ft_putchar('-')
				+ ft_putnbr_base((unsigned long)(-(long) nbr), "0123456789"));
		return (ft_putnbr_base(nbr, "0123456789"));
	}
	else if (c == 'u')
		return (ft_putnbr_base((unsigned int) nbr, "0123456789"));
	else if (c == 'p')
	{
		if (!nbr)
			return (ft_parser_str("(nil)"));
		return (ft_parser_str("0x") + ft_putnbr_base(nbr, "0123456789abcdef"));
	}
	else if (c == 'x')
		return (ft_putnbr_base((unsigned int) nbr, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base((unsigned int) nbr, "0123456789ABCDEF"));
	return (0);
}
