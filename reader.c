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
	t_point *map_vector;
	i = 0;
	if (!(map_vector = (t_point*)malloc(sizeof(t_point) * e->p_nb)))
		return (NULL);
	while (i < e->p_nb)
	{
		map_vector[i].x = i;
		map_vector[i].y = y;
		map_vector[i].z = ft_atoi(after_split[i]);
		map_vector[i].x_before = i;
		map_vector[i].y_before = y;
		map_vector[i].z_before = map_vector[i].z;
		// printf("line %d  : %d %d %d\n", i, map_vector[i].x, map_vector[i].y, map_vector[i].z);
		i++;
	}
	return (map_vector);
}

void 		i_will_read(t_env *e)
{
	char	*line;
	char 	**after_split;
	int 	counter;
	char 	ch;

	int i = 0;
	int j = 0;

	counter = 0;
	if (!(e->map = (t_point **)malloc(sizeof(t_point *) * e->l_nb + 1)))
		return ;

	while (counter < e->l_nb)
	{

		get_next_line(e->fd, &line);
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

		e->map[counter] = map_maker(after_split, counter, e);
		counter++;

	}
	e->map[e->l_nb] = NULL;
}
