/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:48:17 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/12 15:48:18 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static	void	points_from(t_env *e, int i, int j)
{
	ARG_FROM_X = e->map[i][j].x;
	ARG_FROM_Y = e->map[i][j].y;
}

static	void	linear(t_env *e, int i, int j, int y)
{
	int		p_half;
	int		l_half;
	double		z_val;

	e->rad_x = e->angle_x * M_PI / 180.0;
	e->rad_y = e->angle_y * M_PI / 180.0;
	e->rad_z = e->angle_z * M_PI / 180.0;
	p_half = e->map[i][j].x_before - e->p_nb / 2;
	l_half = y - e->l_nb / 2;
	z_val = (double)(e->map[i][j].z_before) * e->depth;
	e->map[i][j].x = e->scale *
	(p_half * cos(e->rad_y) * cos(e->rad_z) -
		l_half * sin(e->rad_z) * cos(e->rad_y) -
		z_val * sin(e->rad_y));
	e->map[i][j].y = e->scale *
	(p_half * (-sin(e->rad_x) * sin(e->rad_y) * cos(e->rad_z) +
		cos(e->rad_x) * sin(e->rad_z)) +
		l_half * (sin(e->rad_x) * sin(e->rad_y) * sin(e->rad_z) +
		cos(e->rad_x) * cos(e->rad_z)) +
		z_val * (-sin(e->rad_x)) * cos(e->rad_y));
}

void			transform(t_env *e)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	while (i < e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{
			y = e->map[i][j].y;
			linear(e, i, j, y);
			move_to_center(&(e->map[i][j]));
			j++;
		}
		i++;
	}
}

static void		set_color(t_env *e, int z, int color)
{
	int i;

	i = 0;

	if (color != 0)
		e->line_color = color;
	else
	{
		if (e->color_change == 0)
			e->line_color = 0x0033CC;
		else if (e->color_change == 1)
			e->line_color = 0x33673377 + (z * 10);
		else if (e->color_change == 2)
				e->line_color = random() % 16581375;
		else if (e->color_change == 3)
			e->line_color = 0xFFFFFF - (z * 20);
	}
}

void			draw_all(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (++i < e->l_nb)
	{
		j = 0;
		while (++j < e->p_nb)
		{
			set_color(e, e->map[i][j].z, e->map[i][j].color);
			points_from(e, i, j);
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
		}
	}
}
