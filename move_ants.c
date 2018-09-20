/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:23:36 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:38:13 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ants(t_path *path, t_lem *lem)
{
	int iter;
	int done;
	int ant;

	iter = 1;
	done = 0;
	while (!done)
	{
		ant = 0;
		while (ant < lem->ants)
		{
			done = print_ant(path, iter, ant, lem);
			ant++;
		}
		ft_putchar('\n');
		iter++;
	}
}

int		print_ant(t_path *path, int iter, int ant, t_lem *lem)
{
	int print;

	print = iter - ant;
	while (print > 0 && path)
	{
		if (print == 1)
		{
			ft_putstr("L");
			ft_putnbr(ant + 1);
			ft_putstr("-");
			ft_putstr(path->name);
			ft_putchar(' ');
			if (ant + 1 == lem->ants && strcmp(path->name, lem->final) == 0)
				return (1);
		}
		path = path->next;
		print--;
	}
	return (0);
}
