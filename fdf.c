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

	if (!(e = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putstr("bad malloc");
		return (0);
	}
	e->l_nb = 0;
	e->map_name = argv[1];
	if (argc == 2)
	{
		e->fd = open(e->map_name, O_RDONLY);
		if (i_will_count_lines(e) == 1)
		{
			printf("THERE R %d LINES IN MAP:\n", e->l_nb);
			printf("GOOD MAP!\n");
		}
		else
			return (0);
		
		e->fd = open(argv[1], O_RDONLY);
		i_will_read(e);
		close(e->fd);

		//>>>>>>> PRINTING MAPS (print z)
		printf(">>>>>>>>>>>>>>>>>>>>>>>> Z\n");

		int i = 0;
		while (i <  e->l_nb)
		{
			int j = 0;
			while (j < e->p_nb)
			{
				printf("%4d", e->map[i][j].z);
				j++;
			}
			printf("\n");
			i++;
		}
		//>>>>>>>>>>

		//>>>>>>> PRINTING MAPS (print z)
		printf(">>>>>>>>>>>>>>>>>>>>>>>> color\n");

		i = 0;
		while (i <  e->l_nb)
		{
			int j = 0;
			while (j < e->p_nb)
			{
				printf("%4d", e->map[i][j].color);
				j++;
			}
			printf("\n");
			i++;
		}
		//>>>>>>>>>>

	}
	return (0);
}