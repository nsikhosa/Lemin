/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 10:31:27 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/03/19 17:12:20 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_room(void *room)
{
	t_list	*name;

	name = malloc(sizeof(t_list));
	if (name)
	{
		name->name = room;
		name->next = NULL;
	}
	return (name);
}
