/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 10:13:14 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/24 19:30:12 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_data(t_data *d)
{
	int	i;

	d->a = NULL;
	d->b = NULL;
	d->strategy = ADAPTIVE;
	d->used = ADAPTIVE;
	d->strategy_set = 0;
	d->bench = 0;
	d->disorder = 0.0;
	d->words = NULL;
	i = 0;
	while (i < OP_COUNT)
	{
		d->count[i] = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	d;

	ft_init_data(&d);
	ft_parse_args(&d, argc, argv);
	if (d.a == NULL)
		return (0);
	d.disorder = ft_compute_disorder(d.a);
	ft_assign_index(d.a);
	ft_sort(&d);
	if (d.bench)
		ft_print_bench(&d);
	ft_free_stack(&d.a);
	ft_free_stack(&d.b);
	return (0);
}
