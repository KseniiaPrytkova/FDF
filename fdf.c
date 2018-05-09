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
	}

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	for (int i = 0; i <= 50000; i++)
	{
		e->x0 = (WIDTH / 4 + random()) % (WIDTH - 1) - WIDTH / 4;
 		e->x1 = (random() % WIDTH - 1);
 		e->y0 = random() % HEIGHT - 1;
 		e->y1 = random() % HEIGHT - 1;
 		e->line_color = random();
 		mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color);
 		//bresenham_line(e);
	}
	mlx_loop(e->mlx);

	// while(1){};
	return (0);
}
