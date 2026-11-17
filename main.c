/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 10:13:14 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/17 13:22:28 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(t_data *d)
{
	ft_free_stack(&d->a);
	ft_free_stack(&d->b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	ft_init_data(t_data *d)
{
	int	i;

	d->a = NULL;
	d->b = NULL;
	d->strategy = ADAPTIVE;
	d->strategy_set = 0;
	d->bench = 0;
	d->disorder = 0.0;
	i = 0;
	while (i < OP_COUNT)
	{
		d->count[i] = 0;
		i++;
	}
}

static void	ft_add_number(t_data *d, char *arg)
{
	long	nbr;
	t_stack	*node;

	if (!ft_parser_arg(arg, &nbr))
		ft_error(d);
	if (ft_has_duplicate(d->a, (int) nbr))
		ft_error(d);
	node = ft_new_node((int) nbr);
	if (node == NULL)
		ft_error(d);
	ft_add_back(&d->a, node);
}

static void	ft_parse_args(t_data *d, int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	while (i < argc)
	{
		flag = ft_parse_flag(d, argv[i]);
		if (flag == -1)
			ft_error(d);
		if (flag == 0)
			ft_add_number(d, argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	d;

	ft_init_data(&d);
	ft_parse_args(&d, argc, argv);
	d.disorder = ft_compute_disorder(d.a);
	if (d.a == NULL || ft_is_sorted(d.a))
	{
		ft_free_stack(&d.a);
		return (0);
	}
	ft_assign_index(d.a);
	ft_free_stack(&d.a);
	ft_free_stack(&d.b);
	return (0);
}
