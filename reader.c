/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 20:48:00 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/28 20:48:01 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point *map_maker(char **after_split, int y, t_env *e)
{
	int		i;
	t_point *map_line;

	i = 0;
	if (!(map_line = (t_point*)malloc(sizeof(t_point) * e->p_nb)))
		return (NULL);
	while (i < e->p_nb)
	{
		map_line[i].x = i;
		map_line[i].y = y;
		map_line[i].z = ft_atoi(after_split[i]);
		map_line[i].x_before = i;
		map_line[i].y_before = y;
		map_line[i].z_before = map_line[i].z;
		i++;
	}
	return (map_line);
}

void 		i_will_read(t_env *e)
{
	char	*line;
	char 	**after_split;
	int 	counter;
	char 	ch;

	int i = 0;

	counter = 0;
	if (!(e->map = (t_point **)malloc(sizeof(t_point *) * e->l_nb + 1)))
		return ;
	while (counter < e->l_nb)
	{

		get_next_line(e->fd, &line);
		// after_split = ft_split(line, t_ene);
		after_split = ft_split(line);
		//>>>>>>>>>
		printf("i'm the nb of lines!!! %d\n", e->p_nb);
		while (i < e->p_nb)
		{
			printf("%s\n", after_split[i]);
			i++;
		}
		i = 0;
		//>>>>>>>>>
		// while (1){}

		// e->map[counter] = map_maker(after_split, counter, e);
		counter++;

	}
	e->map[e->l_nb] = NULL;
}
