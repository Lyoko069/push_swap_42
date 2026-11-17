/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 12:10:21 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:22:42 by mavidal-        ###   ########.fr        */
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

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			count[OP_COUNT];
	t_strategy	strategy;
	int			strategy_set;
	int			bench;
	double		disorder;
}	t_data;

int		ft_parser_arg(char *argv, long *res);
int		ft_parse_flag(t_data *d, char *arg);
t_stack	*ft_new_node(int value);
void	ft_add_back(t_stack **stack, t_stack *node);
void	ft_free_stack(t_stack **stack);
int		ft_has_duplicate(t_stack *stack, int value);
int		ft_is_sorted(t_stack *stack);
void	ft_assign_index(t_stack *stack);
double	ft_compute_disorder(t_stack *a);
void	sa(t_data *d);
void	sb(t_data *d);
void	ss(t_data *d);
void	pa(t_data *d);
void	pb(t_data *d);
void	ra(t_data *d);
void	rb(t_data *d);
void	rr(t_data *d);
void	rra(t_data *d);
void	rrb(t_data *d);
void	rrr(t_data *d);
#endif
