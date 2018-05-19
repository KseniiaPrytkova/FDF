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


void	matrix_reset(t_env *e)
{
	int i;
	int	j;

	i = 0;
	while (i <  e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{
			e->map[i][j].x = e->map[i][j].x_before;
			e->map[i][j].y = e->map[i][j].y_before;
			e->map[i][j].z = e->map[i][j].z_before;
			j++;
		}
		i++;
	}
}

void	draw_all(t_env *e)
{
	int i = 0;
	int j = 0;

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
}


void	draw_each_frame(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	matrix_reset(e);
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF, ft_itoa(e->angle_z));
	transform(e);
	draw_all(e);
}

int		loop_draw(t_env *e)
{
	//e->angle_z += 1;
	//e->angle_x += 1;
	e->angle_x += 1;
	draw_each_frame(e);
	return (0);
}

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
	else
	{
		ft_putstr("Give me a map!");
		return (0);
	}

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	/* ************************************************************************** */
	i_will_init(e);
	transform(e);
	draw_all(e);

	/* ************************************************************************** */

	mlx_key_hook(e->win, key_draw, e);
	//mlx_loop_hook(e->mlx, loop_draw, e);
	mlx_loop(e->mlx);
	return (0);
}

