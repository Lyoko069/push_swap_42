/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 10:51:05 by jjurado           #+#    #+#             */
/*   Updated: 2026/10/20 12:33:27 by jjurado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_parser(char c, va_list args)
{
	if (c == 'c' || c == '%')
	{
		if (c == '%')
			return (ft_putchar('%'));
		else
			return (ft_putchar(va_arg(args, int)));
	}
	else if (c == 's')
		return (ft_parser_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_parser_nbr(va_arg(args, int), c));
	else if (c == 'u' || c == 'x' || c == 'X')
		return (ft_parser_nbr(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_parser_nbr((unsigned long) va_arg(args, void *), c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_parser(format[++i], args);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
