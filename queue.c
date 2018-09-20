/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:58:17 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:42:55 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_to_queue(t_queue **q, char *name)
{
	t_queue *current;

	current = *q;
	if (*q == NULL)
	{
		*q = (t_queue *)malloc(sizeof(t_queue));
		(*q)->name = name;
		(*q)->next = NULL;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (t_queue *)malloc(sizeof(t_queue));
		current->next->name = name;
		current->next->next = NULL;
	}
}

char	*pop(t_queue **q)
{
	char	*ret;
	t_queue	*temp;

	if (*q == NULL)
		return (NULL);
	temp = *q;
	ret = temp->name;
	*q = (*q)->next;
	free(temp);
	return (ret);
}
