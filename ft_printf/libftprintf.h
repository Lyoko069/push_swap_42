/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   libftprintf.h                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 11:23:16 by jjurado          #+#    #+#              */
/*   Updated: 2026/10/21 10:22:23 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_parser_str(const char *s);
size_t	ft_strlen(const char *s);
int		ft_parser_nbr(unsigned long nbr, char c);
#endif
