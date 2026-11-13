/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjurado <jjurado@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:10:21 by jjurado           #+#    #+#             */
/*   Updated: 2026/11/13 11:13:01 by jjurado          ###   ########.fr       */
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

int		ft_parser_arg(char *argv, long *res);
void	sa(t_stack **A);
void	sb(t_stack **B);
void	ss(t_stack **A, t_stack **B);
void	pa(t_stack **A, t_stack **B);
void	pb(t_stack **A, t_stack **B);
void	ra(t_stack **A);
void	rb(t_stack **B);
void	rr(t_stack **A, t_stack **B);
void	rra(t_stack **A);
void	rrb(t_stack **B);
void	rrr(t_stack **A, t_stack **B);
#endif
