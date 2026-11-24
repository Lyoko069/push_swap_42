/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   args.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mavidal- <mavidal-@student.42malaga.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/24 19:30:12 by mavidal-         #+#    #+#              */
/*   Updated: 2026/11/24 19:30:12 by mavidal-        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_data *d)
{
	ft_free_split(d->words);
	ft_free_stack(&d->a);
	ft_free_stack(&d->b);
	write(2, "Error\n", 6);
	exit(1);
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

static void	ft_parse_word(t_data *d, char *word)
{
	int	flag;

	flag = ft_parse_flag(d, word);
	if (flag == -1)
		ft_error(d);
	if (flag == 0)
		ft_add_number(d, word);
}

void	ft_parse_args(t_data *d, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		d->words = ft_split(argv[i], ' ');
		if (d->words == NULL || d->words[0] == NULL)
			ft_error(d);
		j = 0;
		while (d->words[j] != NULL)
		{
			ft_parse_word(d, d->words[j]);
			j++;
		}
		ft_free_split(d->words);
		d->words = NULL;
		i++;
	}
}
