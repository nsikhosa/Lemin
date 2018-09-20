/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:28:36 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 14:42:54 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_rooms(t_room **rm)
{
	while (*rm)
	{
		free(*rm);
		*rm = (*rm)->next;
	}
}

void	free_path(t_path **path)
{
	while (*path)
	{
		free(*path);
		*path = (*path)->next;
	}
}
