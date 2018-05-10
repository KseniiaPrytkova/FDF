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
	int first = 0;
	int i = 0;
	int move_x = 40;
	int move_y = 40; 
	int scale_x = 40;
	int scale_y = 40;
	while (i <  e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{
			e->line_color = 8388352;
			e->x0 = move_x + (e->map[i][j].x * scale_x); // p0
			e->y0 = move_y + (e->map[i][j].y  * scale_y);	// p0
			if ( j  + 1 < e->p_nb )
			{
				e->x1 = move_x + (e->map[i][j + 1].x * scale_x); //p1
				e->y1 = move_y + (e->map[i][j + 1].y * scale_y); //p1
				bresenham_line(e);
			}
			if ( i + 1 < e->l_nb)
			{
				e->x1 = move_x + (e->map[i + 1][j].x * scale_x); //p1(vertical)
				e->y1 = move_y + (e->map[i + 1][j].y * scale_y); //p1(vertical)
				bresenham_line(e);
			}
			j++;
		}
		printf("\n");
		i++;
	}


	/* ************************************************************************** */
	mlx_loop(e->mlx);

	// while(1){};
	return (0);
}

