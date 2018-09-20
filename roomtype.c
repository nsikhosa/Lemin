/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomtype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:26:12 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/03/19 17:17:14 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		arraylen(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int		roomtype(int num_ant, char **split, int type_last, t_room **rm)
{
	if (arraylen(split) != 3)
	{
		ft_putendl("ERROR");
		exit(1);
	}
	if ((!split[1] && !split[2]) ||
			!ft_isstrdigit(split[1]) || !ft_isstrdigit(split[2]))
		return (-1);
	add_room(rm, split[0]);
	if (type_last == 0)
	{
		(*rm)->ant_num = num_ant;
		(*rm)->isend = -1;
	}
	else if (type_last == 1)
		(*rm)->isend = 1;
	return (0);
}

t_path	*helper(t_lem *lem)
{
	t_path *p;

	p = NULL;
	while (lem->que != NULL)
	{
		lem->tmp_r = pop(&lem->que);
		lem->curr = get_room(lem->room, lem->tmp_r);
		if (ft_strcmp(lem->curr->name, lem->end->name) == 0)
			add_parent_path(lem->curr, &p);
		while (lem->curr->dependent)
		{
			lem->child = get_room(lem->room, lem->curr->dependent->name);
			if (!lem->child->checked)
			{
				lem->child->checked = 1;
				lem->child->node = lem->curr;
				add_to_queue(&lem->que, lem->child->name);
			}
			lem->curr->dependent = lem->curr->dependent->next;
		}
	}
	return (p);
}
