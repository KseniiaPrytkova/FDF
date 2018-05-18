/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:03:10 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 14:03:11 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

void		move_all(t_env *e, int move_x, int move_y)
{
	int i = 0;
	while (i < 4)
	{
		e->points[i].x += move_x;
		e->points[i].y += move_y;
		i++;
	}
}

t_point		fill_point(int x, int y, int z)
{
	t_point ret;
	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

void		line_fill_param(t_env *e, int x0, int y0, int x1, int y1)
{
	ARG_FROM_X = x0;
	ARG_FROM_Y = y0;
	ARG_TO_X = x1;
	ARG_TO_Y = y1;
}

void		draw_line_and_rotate(t_env *e)
{
	e->points = malloc(sizeof(t_point) * 4);
	/*move_all(e, -center_x, -center_y);*/
	/*draw_triangle(e, 100, 0);*/
	draw_triangle(e, 300, 0);
}

void		draw_triangle(t_env *e, int size, int start)
{
	int 	end;

	end = start + size;
	e->line_color = 65280;
	e->points[0] = fill_point(start, start, start);
	e->points[1] = fill_point(end, start , start);
	e->points[2] = fill_point(start, end, start);
	e->points[3] = fill_point(start, start, end);

	rotate_z(e, e->tmp_angle);
	rotate_x(e, e->tmp_angle);
	rotate_y(e, e->tmp_angle);

	move_all(e, WIDTH/2, HEIGHT/2); /* move to the center for a nice view!!! ^^ */
	line_fill_param(e, e->points[0].x, e->points[0].y, e->points[1].x, e->points[1].y);
	bresenham_line(e);
	line_fill_param(e, e->points[1].x, e->points[1].y, e->points[2].x, e->points[2].y);
	bresenham_line(e);
	line_fill_param(e, e->points[2].x, e->points[2].y, e->points[0].x, e->points[0].y);
	bresenham_line(e);

	line_fill_param(e, e->points[0].x, e->points[0].y, e->points[3].x, e->points[3].y);
	bresenham_line(e);
	line_fill_param(e, e->points[1].x, e->points[1].y, e->points[3].x, e->points[3].y);
	bresenham_line(e);
	line_fill_param(e, e->points[2].x, e->points[2].y, e->points[3].x, e->points[3].y);
	bresenham_line(e);
}

int		main(void)
{
	t_env *e;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	e->tmp_angle = 0;
	draw_line_and_rotate(e);
	mlx_hook(e->win, 2, 5, key_draw, e);
	/*mlx_loop_hook(e->mlx, loop_draw, e);*/
	mlx_loop(e->mlx);
	return (0);
}
