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

#include "./includes/fdf.h"

void 	i_will_init(t_env *e)
{
	tips(e);
	e->move_x = WIDTH / 2;
	e->move_y = HEIGHT / 2;
	e->scale = select_scale(e);	

	e->angle_x = 0;
	e->angle_y = 0;
	e->angle_z = 0;
	e->depth = 0.3;
	e->color_change = 0;
}

static int		exit_x(void)
{
	system("leaks a.out");
	exit(1);
	return (0);
}

static void		to_do_list(t_env *e)
{
	i_will_init(e);
	transform(e);
	draw_all(e);
	mlx_key_hook(e->win, key_draw, e);
	mlx_hook(e->win, 2, 5, key_draw, e);
	mlx_hook(e->win, 17, 1L << 17, exit_x, NULL);
}

static int		i_work_with_argv(t_env *e, char *s, char *name)
{
	int fd;

	fd = open(s, O_DIRECTORY);
		if (fd >= 0)
			exit(0);
	e->fd = open(name, O_RDONLY);
	if (i_will_count_lines(e) != 1)
		return (0);
	if (e->p_nb < 1 || e->l_nb < 1)
		return (0);
	e->fd = open(s, O_RDONLY);
	if (!(i_will_read(e)))
		return (0);
	close(e->fd);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putstr("BAD MALLOC");
		return (0);
	}
	e->l_nb = 0;
	e->map_name = argv[1];
	if (argc == 2)
	{	
		if (!(i_work_with_argv(e, argv[1], e->map_name)))
			return (0);
	}
	else
	{
		ft_putstr("GIVE ME A MAP!");
		return (0);
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, e->map_name);
	to_do_list(e);
	mlx_loop(e->mlx);
	return (0);
}
