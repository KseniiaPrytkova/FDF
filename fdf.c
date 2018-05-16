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

	// i_will_init(e);

	// transform(e);
	// int i = 0;
	// while (i <  e->l_nb)
	// {
	// 	j = 0;
	// 	while (j < e->p_nb)
	// 	{
	// 		e->line_color = 838835;
	// 		ARG_FROM_X = e->map[i][j].x;
	// 		ARG_FROM_Y = e->map[i][j].y;
	// 		if (j + 1 < e->p_nb)
	// 		{
	// 			ARG_TO_X = e->map[i][j + 1].x; 
	// 			ARG_TO_Y = e->map[i][j + 1].y;
	// 			bresenham_line(e);


	// 		}
	// 		if (i + 1 < e->l_nb)
	// 		{
	// 			ARG_TO_X = e->map[i + 1][j].x; 
	// 			ARG_TO_Y = e->map[i + 1][j].y;
	// 			bresenham_line(e);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }

	/* ************************************************************************** */
	int scale = 5;
	/* fields */
	e->line_color = 16777215;
	ARG_FROM_X = 0 + MARGIN;
	ARG_FROM_Y = 0 + MARGIN;
	ARG_TO_X = WIDTH - MARGIN;
	ARG_TO_Y = HEIGHT - (HEIGHT - MARGIN);
	bresenham_line(e);
	ARG_FROM_X = 0 + MARGIN;
	ARG_FROM_Y = 0 + MARGIN;
	ARG_TO_X = 0 + MARGIN;
	ARG_TO_Y = HEIGHT - MARGIN;
	bresenham_line(e);
	ARG_FROM_X = 0 + MARGIN;
	ARG_FROM_Y = HEIGHT - MARGIN;
	ARG_TO_X = WIDTH - MARGIN;
	ARG_TO_Y = HEIGHT - MARGIN;
	bresenham_line(e);
	ARG_FROM_X = WIDTH - MARGIN;
	ARG_FROM_Y = HEIGHT - MARGIN;
	ARG_TO_X = WIDTH - MARGIN;
	ARG_TO_Y = HEIGHT - (HEIGHT - MARGIN);
	bresenham_line(e);

	/* cross */
	e->line_color = 16776960;
	ARG_FROM_X = 0 + WIDTH / 2;
	ARG_FROM_Y = 0 + MARGIN;
	ARG_TO_X = 0 + WIDTH / 2;
	ARG_TO_Y = HEIGHT - MARGIN;
	bresenham_line(e);
	ARG_FROM_X = 0 + MARGIN;
	ARG_FROM_Y = 0 + HEIGHT / 2;
	ARG_TO_X = WIDTH - MARGIN;
	ARG_TO_Y = 0 + HEIGHT / 2;
	bresenham_line(e);


	/* triangle */
	int cx1, cx2, cx3;
	int cy1, cy2, cy3;

	e->line_color = 838835;
 	ARG_FROM_X = (0 * scale) + (WIDTH / 2 - scale);
 	printf("x0: %d\n", ARG_FROM_X);
	ARG_FROM_Y = (30 * scale) + (HEIGHT / 2 - scale);
	printf("y0: %d\n", ARG_FROM_Y);
	ARG_TO_X = (20 * scale) + (WIDTH / 2 - scale);
	printf("x1: %d\n", ARG_TO_X);
	ARG_TO_Y = (10 * scale) + (HEIGHT / 2 - scale);
	printf("y1: %d\n", ARG_TO_Y);
	// cx1 = (ARG_FROM_X + ARG_TO_X) / 2;
	// cy1 = (ARG_FROM_Y + ARG_TO_Y) / 2;
	bresenham_line(e);
	printf("---\n");
	ARG_FROM_X = (20 * scale) + (WIDTH / 2 - scale);
	printf("x0: %d\n", ARG_FROM_X);
	ARG_FROM_Y = (10 * scale) + (HEIGHT / 2 - scale);
	printf("y0: %d\n", ARG_FROM_Y);
	ARG_TO_X = (40 * scale) + (WIDTH / 2 - scale);
	printf("x1: %d\n", ARG_TO_X);
	ARG_TO_Y = (30 * scale) + (HEIGHT / 2 - scale);
	printf("y1: %d\n", ARG_TO_Y);
	// cx2 = (ARG_FROM_X + ARG_TO_X) / 2;
	// cy2 = (ARG_FROM_Y + ARG_TO_Y) / 2;
	bresenham_line(e);
	printf("---\n");
	ARG_FROM_X = (40 * scale) + (WIDTH / 2 - scale);
	printf("x0: %d\n", ARG_FROM_X);
	ARG_FROM_Y = (30 * scale) + (HEIGHT / 2 - scale);
	printf("y0: %d\n", ARG_FROM_Y);
	ARG_TO_X = (0 * scale) + (WIDTH / 2 - scale);
	printf("x1: %d\n", ARG_TO_X);
	ARG_TO_Y = (30 * scale) + (HEIGHT / 2 - scale);
	printf("y1: %d\n", ARG_TO_Y);
	// cx3 = (ARG_FROM_X + ARG_TO_X) / 2;
	// cy3 = (ARG_FROM_Y + ARG_TO_Y) / 2;
	bresenham_line(e);

	/* --- */
	// e->line_color = 16776960;
	// ARG_FROM_X = (0 * scale) + (WIDTH / 2 - scale);
	// ARG_FROM_Y = (30 * scale) + (HEIGHT / 2 - scale);
	// ARG_TO_X = cx2;
	// ARG_TO_Y = cy2;
	// bresenham_line(e);
	// ARG_FROM_X = (20 * scale) + (WIDTH / 2 - scale);
	// ARG_FROM_Y = (10 * scale) + (HEIGHT / 2 - scale);
	// ARG_TO_X = cx3;
	// ARG_TO_Y = cy3;
	// bresenham_line(e);
	// ARG_FROM_X = (40 * scale) + (WIDTH / 2 - scale);
	// ARG_FROM_Y = (30 * scale) + (HEIGHT / 2 - scale);
	// ARG_TO_X = cx1;
	// ARG_TO_Y = cy1;
	// bresenham_line(e);
	/* --- */





	mlx_loop(e->mlx);

	// while(1){};
	return (0);
}

