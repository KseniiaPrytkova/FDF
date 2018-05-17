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

int	key_exit(int keycode)
{
	if (keycode == 53)
	{
		exit(1);
	}
	return (-1);
}

void	line_fill_param(t_env *e, int x0, int y0, int x1, int y1)
{
	ARG_FROM_X = x0;
	ARG_FROM_Y = y0;
	ARG_TO_X = x1;
	ARG_TO_Y = y1;
}

t_point	fill_point(int x, int y, int z)
{
	t_point ret;
	ret.x = x;
	ret.y = y;
	ret.z = z;

	return (ret);
}

// void translate_all(t_env *e, int move_x, int move_y)
// {
// 	ARG_FROM_X += move_x;
// 	ARG_FROM_Y += move_y;
// 	ARG_TO_X += move_x;
// 	ARG_TO_Y += move_y;
// }

// void rotate_z(t_env *e, int angle)
// {
// 	float radian = angle * PI / 180;
// 	int x0, x1, y0, y1;

// 	x0 = ARG_FROM_X;
// 	y0 = ARG_FROM_Y;
// 	x1 = ARG_TO_X;
// 	y1 = ARG_TO_Y;
// 	ARG_FROM_X = x0 * cos(radian) - y0 * sin(radian);
// 	ARG_FROM_Y = x0 * sin(radian) + y0 * cos(radian);

// 	ARG_TO_X = x1 * cos(radian) - y1 * sin(radian);
// 	ARG_TO_Y = x1 * sin(radian) + y1 * cos(radian);
// }


void	rotate_x(t_env *e, int angle)
{
		float radian = angle * PI / 180;
		int i = 0;

		int tmp_y;

		while (i < 4)
		{
			tmp_y = e->points[i].y;

			e->points[i].y = e->points[i].y * cos(radian) - e->points[i].z * sin(radian);
			e->points[i].z = tmp_y * sin(radian) + e->points[i].z * cos(radian);
			i++;
		}
}

void	rotate_y(t_env *e, int angle)
{
		float radian = angle * PI / 180;

		int i = 0;

		int tmp_z;

		while (i < 4)
		{
			tmp_z = e->points[i].z;

			e->points[i].z = e->points[i].z * cos(radian) - e->points[i].x * sin(radian);
			e->points[i].x = tmp_z * sin(radian) + e->points[i].x * cos(radian);
			i++;
		}
}

void	rotate_z(t_env *e, int angle)
{
		float radian = angle * PI / 180;
		int i = 0;
		int tmp_x;

		while (i < 4)
		{
			tmp_x = e->points[i].x;

			e->points[i].x = e->points[i].x * cos(radian) - e->points[i].y * sin(radian);
			e->points[i].y = tmp_x * sin(radian) + e->points[i].y * cos(radian);
			i++;
		}
}


void	move_all(t_env *e, int move_x, int move_y)
{
	int i = 0;

	while (i < 4)
	{
		e->points[i].x += move_x;
		e->points[i].y += move_y;
		i++;
	}
}

void	draw_triangle(t_env *e, int size, int start)
{
	int 	end;

	end 	= start + size;

	e->points[0] = fill_point(start, start, start);
	e->points[1] = fill_point(end, start , start);
	e->points[2] = fill_point(start, end, start);
	e->points[3] = fill_point(start, start, end);

	rotate_z(e, e->tmp_angle);
	rotate_x(e, e->tmp_angle);
	rotate_y(e, e->tmp_angle);

	move_all(e, WIDTH/2, HEIGHT/2); //move to the center for a nice view!!! ^^
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

void	draw_line_and_rotate(t_env *e)
{
	e->points = malloc(sizeof(t_point) * 4);
	//move_all(e, -center_x, -center_y);

	draw_triangle(e, 100, 0);
	draw_triangle(e, 300, 0);
}

int key_draw(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 123)
	{
		e->tmp_angle -= 50;
	}
	if (keycode == 124)
	{
		e->tmp_angle += 50;
	}
	draw_line_and_rotate(e);
	return (1);
}

int loop_draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);

	e->tmp_angle += 1; //SPEEED!
	e->line_color = random() % 16581375;
	draw_line_and_rotate(e);
	return (1);
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

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");


	draw_line_and_rotate(e);

	e->tmp_angle = 0;
	mlx_key_hook(e->win, key_draw, e);
	mlx_key_hook(e->win, key_exit, e);
	mlx_loop_hook(e->mlx, loop_draw, e);
	mlx_loop(e->mlx);
	return (0);
}

