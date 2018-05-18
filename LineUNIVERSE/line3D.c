/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:23:20 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 16:23:22 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line3D.h"

int	key_exit(int keycode)
{
	if (keycode == 53)
	{
		exit(1);
	}
	return (-1);
}

void translate_all(t_env *e, int move_x, int move_y)
{
	ARG_FROM_X += move_x;
	ARG_FROM_Y += move_y;
	ARG_TO_X += move_x;
	ARG_TO_Y += move_y;
}

void rotate_z(t_env *e, int angle)
{
	float radian = angle * PI / 180;
	int x0, x1, y0, y1;

	x0 = ARG_FROM_X;
	y0 = ARG_FROM_Y;
	x1 = ARG_TO_X;
	y1 = ARG_TO_Y;
	ARG_FROM_X = x0 * cos(radian) - y0 * sin(radian);
	ARG_FROM_Y = x0 * sin(radian) + y0 * cos(radian);

	ARG_TO_X = x1 * cos(radian) - y1 * sin(radian);
	ARG_TO_Y = x1 * sin(radian) + y1 * cos(radian);
}

void	line_fill_param(t_env *e, int x0, int y0, int x1, int y1)
{
	e->line_color = 0xFFFFFF;
	ARG_FROM_X = x0;
	ARG_FROM_Y = y0;
	ARG_TO_X = x1;
	ARG_TO_Y = y1;
}

void	draw_line_and_rotate(t_env *e)
{
	int length_x = 100;
	int length_y = 100;
	int center_x = length_x /2;
	int center_y = length_y /2;
	line_fill_param(e, 0, 0, length_x, length_y);
	/*translate_all(e, -center_x, -center_y);*/
	/*translate_all(e, 300, 300);*/
	rotate_z(e, e->tmp_angle);
	/*translate_all(e, +center_x, +center_y);*/

	/*FINAL DRAW*/
	translate_all(e, WIDTH/2, HEIGHT/2);
	bresenham_line(e);
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

	e->tmp_angle += 1; /*SPEEED!*/
	printf("%d\n", e->tmp_angle);
	draw_line_and_rotate(e);
	return (1);
}

int		main(void)
{
	t_env *e;
	
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");

	draw_line_and_rotate(e);
	e->tmp_angle = 0;
	/*mlx_key_hook(e->win, key_draw, e);*/
	mlx_loop_hook(e->mlx, loop_draw, e);

	mlx_key_hook(e->win, key_exit, e);
	mlx_loop(e->mlx);
	return (0);
}
