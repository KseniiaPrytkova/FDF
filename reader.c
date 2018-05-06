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

static void		free_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int		is_it_hex(char *str)
{
	unsigned char	ch;
	int				i;

	i = 0;
	if (*str == '0' && *(str + 1) == 'x')
	{
		str = str + 2;
		while (*str)
		{
			ch = (unsigned char)*str;
			if (ft_isalnum((int)ch) != 1)
				return (0);
			str++;
		}
		return (1);
	}
	else
		return (0);
}

static void		filler(t_point *map_vector, char **after_split, int i, int y)
{
	map_vector[i].x = i;
	map_vector[i].y = y;
	map_vector[i].z = ft_atoi(after_split[i]);
	map_vector[i].x_before = i;
	map_vector[i].y_before = y;
	map_vector[i].z_before = map_vector[i].z;
}

static t_point	*map_maker(char **after_split, int y, t_env *e, int i)
{
	t_point		*map_vector;
	char		*temp_box;

	if (!(map_vector = (t_point*)malloc(sizeof(t_point) * e->p_nb)))
		return (NULL);
	while (i < e->p_nb)
	{
		temp_box = after_split[i];
		if (ft_strlen(temp_box) >= 10)
		{
			temp_box++;
			if (*temp_box == ',')
			{
				temp_box++;
				if (is_it_hex(temp_box) == 1)
					map_vector[i].color = ft_atoi_base(temp_box + 2, 16);
			}
		}
		else if (ft_strlen(temp_box) < 10)
			map_vector[i].color = 0;
		filler(map_vector, after_split, i, y);
		i++;
	}
	return (map_vector);
}

void			i_will_read(t_env *e)
{
	char	*line;
	char	**after_split;
	int		counter;
	char	ch;
	int		i;

	counter = 0;
	i = 0;
	if (!(e->map = (t_point **)malloc(sizeof(t_point *) * e->l_nb + 1)))
		return ;
	while (counter < e->l_nb)
	{
		get_next_line(e->fd, &line);
		after_split = ft_split(line);
		e->map[counter] = map_maker(after_split, counter, e, i);
		counter++;
		free(line);
		free_array(after_split);
	}
	e->map[e->l_nb] = NULL;
}
