/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:02:28 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:40:12 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_path(t_path **path, char *name)
{
	t_path *current;

	current = *path;
	if (*path == NULL)
	{
		(*path) = (t_path *)malloc(sizeof(t_path));
		(*path)->name = name;
		(*path)->next = NULL;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (t_path *)malloc(sizeof(t_path));
		current->next->name = name;
		current->next->next = NULL;
	}
}

void	add_parent_path(t_room *root, t_path **path)
{
	if (root == NULL)
		return ;
	add_parent_path(root->node, path);
	add_path(path, root->name);
}
