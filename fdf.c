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


int exit_x(void)
{
system("leaks a.out");
exit(1);
return (0);
}

int		main(int argc, char *argv[])
{
	t_env *e;
	int j;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putstr("BAD MALLOC");
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
		if (!(i_will_read(e)))
			return (0);
		// i_will_read(e);
		close(e->fd);
	}
	else
	{
		ft_putstr("GIVE ME A MAP!");
		return (0);
	}

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");

	i_will_init(e);
	transform(e);
	draw_all(e);

	mlx_key_hook(e->win, key_draw, e);
	mlx_hook(e->win, 2, 5, key_draw, e);

	// int mlx_hook(e->win, int x_event, int x_mask, int (*funct)(), void *param);
	// mlx_loop_hook(e->mlx, loop_draw, e);
	mlx_hook(e->win, 17, 1L << 17, exit_x, NULL);

	mlx_loop(e->mlx);
	return (0);
}

