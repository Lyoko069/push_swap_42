/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: jjurado <jjurado@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 12:10:21 by jjurado          #+#    #+#              */
/*   Updated: 2026/11/12 12:56:05 by jjurado         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libftprintf.h"

typedef struct s_list
{
	int				index;
	struct s_list	*prev;
	int				value;
	struct s_list	*next;
}	t_stack;

int	ft_parser_arg(char *argv, long *res);
#endif
