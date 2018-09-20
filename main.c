/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:55:37 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:29:56 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lem	*init(void)
{
	t_lem *lem;

	lem = (t_lem *)malloc(sizeof(t_lem));
	lem->ants = 0;
	lem->que = NULL;
	lem->curr = NULL;
	lem->room = NULL;
	lem->tmp_r = NULL;
	lem->end = NULL;
	lem->child = NULL;
	lem->type_last = -2;
	return (lem);
}

int		main(void)
{
	t_lem	*lem;
	t_room	*rm;

	lem = init();
	if (read_from_file(&lem->room, lem) == -1)
	{
		ft_putendl("ERROR");
		return (0);
	}
	lem->curr = getstart(lem->room);
	lem->end = getend(lem->room);
	lem->ants = lem->curr->ant_num;
	lem->final = lem->end->name;
	lem->curr->checked = 1;
	add_to_queue(&lem->que, lem->curr->name);
	lem->path = helper(lem);
	move_ants(lem->path->next, lem);
	rm = lem->room;
	free(lem->que);
	free(lem);
	free_rooms(&lem->room);
	free_path(&lem->path);
	return (0);
}
