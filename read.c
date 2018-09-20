/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:26:28 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:50:39 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_isstrdigit(char *name)
{
	while (*name)
	{
		if (!ft_isdigit(*name))
			return (0);
		name++;
	}
	return (1);
}

int		get_type(char *line)
{
	if (!line)
		return (-1);
	if (!ft_strcmp("##start", line))
		return (0);
	if (!ft_strcmp("##end", line))
		return (1);
	if (ft_strchr(line, '#') != NULL || line[0] == 'L')
		return (2);
	if (ft_strchr(line, '-') != NULL)
		return (3);
	return (4);
}

int		read_from_file(t_room **rm, t_lem *lem)
{
	get_next_line(0, &lem->line);
	if (lem->line == NULL)
		return (-1);
	ft_putendl(lem->line);
	lem->num_ant = ft_atoi(lem->line);
	while (get_next_line(0, &lem->line) == 1)
	{
		ft_putendl(lem->line);
		if (get_type(lem->line) == 4)
		{
			lem->split = ft_strsplit(lem->line, ' ');
			roomtype(lem->num_ant, lem->split, lem->type_last, rm);
		}
		else if (get_type(lem->line) == -1)
			return (-1);
		else if (get_type(lem->line) == 3)
		{
			lem->split = ft_strsplit(lem->line, '-');
			if (lem->split[0] && lem->split[1])
				link_rooms(*rm, lem->split[0], lem->split[1]);
		}
		lem->type_last = get_type(lem->line);
	}
	ft_putchar('\n');
	return (1);
}
