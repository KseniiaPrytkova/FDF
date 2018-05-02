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

int how_much_u_need(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' &&str[i] != '\n')
		i++;
	return (i);
}

char *make_home_for_hex(char *s, char *empty_box)
{
	int i;
	int j;
	int till;

	i = 0;
	j = 0;
	till = how_much_u_need(s);
	while (till > 0)
	{
		empty_box[i] = s[j];
		i++;
		j++;
		till--;
	}
	empty_box[i] = '\0';
	return (empty_box);
}

t_point *map_maker(char **after_split, int y, t_env *e)
{
	int		i;
	t_point *map_vector;
	char *str_holder;
	char *empty_box;

	i = 0;
	if (!(map_vector = (t_point*)malloc(sizeof(t_point) * e->p_nb)))
		return (NULL);
	while (i < e->p_nb)
	{
		str_holder = after_split[i];
		while (*str_holder)
		{
			if (*str_holder == ',' && *(str_holder + 1) == '0' && (*(str_holder + 2) == 'x' || *(str_holder + 2) == 'X'))
			{
				if (!(empty_box = (char*)malloc(sizeof(char) * (how_much_u_need(str_holder + 1) + 1))))
					return (0);
				empty_box = make_home_for_hex((str_holder + 1), empty_box);
				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>%s\n", empty_box );
				map_vector[i].color_box = ft_memalloc(how_much_u_need(empty_box) + 1);
				printf(">>>>>>>>>>>>>>+++%s\n", map_vector[i].color_box);
				map_vector[i].color_box = ft_strcpy(map_vector[i].color_box, empty_box);
				free (empty_box);
				printf("EMPTY BOX>>>> %s\n", map_vector[i].color_box);
			}
			else
				map_vector[i].color_box = NULL;
			str_holder++;
		}

		map_vector[i].x = i;
		map_vector[i].y = y;
		map_vector[i].z = ft_atoi(after_split[i]);
		map_vector[i].x_before = i;
		map_vector[i].y_before = y;
		map_vector[i].z_before = map_vector[i].z;
		printf("line %d  : %d %d %d %s\n", i, map_vector[i].x, map_vector[i].y, map_vector[i].z, map_vector[i].color_box);
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
