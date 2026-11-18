/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/18 12:43:19 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/18 12:43:19 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_op(const char *name, int count)
{
	ft_putstr_err(name);
	ft_putstr_err(":  ");
	ft_putnbr_err(count);
}

static void	ft_print_disorder(double disorder)
{
	long	pct;

	pct = (long)(disorder * 10000 + 0.5);
	ft_putstr_err("[bench] disorder:  ");
	ft_putnbr_err(pct / 100);
	ft_putstr_err(".");
	if (pct % 100 < 10)
		ft_putstr_err("0");
	ft_putnbr_err(pct % 100);
	ft_putstr_err("%\n");
}

static void	ft_print_counts(int *count)
{
	ft_print_op("[bench] sa", count[SA]);
	ft_print_op("  sb", count[SB]);
	ft_print_op("  ss", count[SS]);
	ft_print_op("  pa", count[PA]);
	ft_print_op("  pb", count[PB]);
	ft_print_op("\n[bench] ra", count[RA]);
	ft_print_op("  rb", count[RB]);
	ft_print_op("  rr", count[RR]);
	ft_print_op("  rra", count[RRA]);
	ft_print_op("  rrb", count[RRB]);
	ft_print_op("  rrr", count[RRR]);
	ft_putstr_err("\n");
}

void	ft_print_bench(t_data *d)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += d->count[i++];
	ft_print_disorder(d->disorder);
	ft_putstr_err("[bench] strategy:  ");
	ft_putstr_err(ft_strategy_name(d->strategy));
	ft_putstr_err(" / ");
	ft_putstr_err(ft_class_name(d->used));
	ft_putstr_err("\n");
	ft_print_op("[bench] total_ops", total);
	ft_putstr_err("\n");
	ft_print_counts(d->count);
}
