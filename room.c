/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:00:25 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:55:47 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_room(t_room **rooms, char *name)
{
	t_room *temp;

	if (*rooms == NULL)
	{
		(*rooms) = (t_room *)malloc(sizeof(t_room));
		(*rooms)->name = name;
		(*rooms)->dependent = NULL;
		(*rooms)->checked = 0;
		(*rooms)->node = NULL;
		(*rooms)->next = NULL;
		(*rooms)->isend = 0;
	}
	else
	{
		temp = (t_room *)malloc(sizeof(t_room));
		temp->name = name;
		temp->node = NULL;
		temp->next = *rooms;
		temp->checked = 0;
		temp->dependent = NULL;
		*rooms = temp;
		(*rooms)->isend = 0;
	}
}

t_room	*get_room(t_room *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strcmp(name, rooms->name) == 0)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room	*getstart(t_room *rooms)
{
	while (rooms)
	{
		if (rooms->isend == -1)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

t_room	*getend(t_room *rooms)
{
	while (rooms)
	{
		if (rooms->isend == 1)
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}

void	link_rooms(t_room *rooms, char *r1, char *r2)
{
	t_room *room1;
	t_room *room2;

	room1 = get_room(rooms, r1);
	room2 = get_room(rooms, r2);
	if (!room1 || !room2)
		return ;
	add_room(&room1->dependent, r2);
	add_room(&room2->dependent, r1);
}
