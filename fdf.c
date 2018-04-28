/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:16:09 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/18 18:16:10 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char *argv[])
{
	t_env *e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
	{
		ft_putstr("bad malloc");
		return (0);
	}
	e->l_nb = 0;
	e->map_name = argv[1];
	if (argc == 2)
	{
		e->fd = open(e->map_name, O_RDONLY);
		i_will_count_lines(e);
		printf("THERE R %d LINES IN MAP:\n", e->l_nb);
		if(e->l_nb != 0)
			printf("GOOD MAP!\n");
		
		e->fd = open(argv[1], O_RDONLY);
		i_will_read(e);
		close(e->fd);
		for (int i = 0; i < e->l_nb ; i++)
		{
			for (int j = 0; j < e->p_nb; i++)
			{
				printf("-x: %d -y: %d -z: %d", e->map[i][j].x, e->map[i][j].y, e->map[i][j].z);
			}
		}
	}
	return (0);
}