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
	int j;

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
	}

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	/* ************************************************************************** */

	i_will_init(e);
	// i_will_scale(e);
	// i_will_move(e);

	transform(e);
	int i = 0;
	while (i <  e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{
			e->line_color = 838835;
			ARG_FROM_X = e->map[i][j].x;
			ARG_FROM_Y = e->map[i][j].y;
			if (j + 1 < e->p_nb)
			{
				ARG_TO_X = e->map[i][j + 1].x; 
				ARG_TO_Y = e->map[i][j + 1].y;
				bresenham_line(e);


			}
			if (i + 1 < e->l_nb)
			{
				ARG_TO_X = e->map[i + 1][j].x; 
				ARG_TO_Y = e->map[i + 1][j].y;
				bresenham_line(e);
			}
			j++;
		}
		i++;
	}


	/* ************************************************************************** */
	mlx_loop(e->mlx);

	// while(1){};
	return (0);
}

