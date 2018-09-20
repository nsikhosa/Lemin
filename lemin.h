/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 07:25:15 by nsikhosa          #+#    #+#             */
/*   Updated: 2018/01/26 15:16:23 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_path
{
	char			*name;
	struct s_path	*next;
}					t_path;

typedef struct		s_room
{
	char			*name;
	int				checked;
	int				isend;
	struct s_room	*dependent;
	struct s_room	*node;
	unsigned int	ant_num;
	struct s_room	*next;
}					t_room;

typedef struct		s_queue
{
	char			*name;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_lem
{
	t_queue			*que;
	char			*tmp_r;
	t_room			*curr;
	t_room			*room;
	t_room			*end;
	t_room			*child;
	t_path			*path;
	int				ants;
	char			*final;
	int				num_ant;
	char			**split;
	char			*line;
	int				type_last;
}					t_lem;

void				add_to_queue(t_queue **q, char *name);
void				add_room(t_room **rooms, char *name);
void				print_list(t_room *rooms);
void				print_q(t_queue *rooms);
t_room				*get_room(t_room *rooms, char *name);
void				link_rooms(t_room *rooms, char *r1, char *r2);
char				*pop(t_queue **q);
void				add_parent_path(t_room *root, t_path **path);
void				print_dependant(t_room *rooms);
t_room				*getstart(t_room *rooms);
t_room				*getend(t_room *rooms);
void				add_path(t_path **path, char *name);
int					ft_isstrdigit(char *name);
int					roomtype(int num_ant, char **split, int type_last,
		t_room **rm);
t_path				*helper(t_lem *lem);
int					read_from_file(t_room **rm, t_lem *lem);
void				move_ants(t_path *path, t_lem *lem);
void				free_rooms(t_room **rm);
void				free_path(t_path **path);
int					print_ant(t_path *path, int iter, int ant, t_lem *lem);
#endif
