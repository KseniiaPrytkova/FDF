/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:18:39 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 15:18:41 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.h"

/*variants of the final representation of the figure*/
int key_draw(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 53)
	{
		exit(1);
	}
	if (keycode == 123)
	{
		e->tmp_angle -= 1;
	}
	if (keycode == 124)
	{
		e->tmp_angle += 1;
	}
	draw_line_and_rotate(e);
	return (1);
}

int loop_draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->tmp_angle += 1; /*SPEEED!*/
	e->line_color = random() % 16581375;
	draw_line_and_rotate(e);
	return (1);
}

/*rotations*/
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
