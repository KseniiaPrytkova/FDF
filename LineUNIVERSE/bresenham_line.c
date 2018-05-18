/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:24:27 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 16:24:28 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line3D.h"

static	void		ft_draw_dx(t_env *e)
{
	int error;
	int i;
	int x;
	int y;

	error = (e->dy << 1) - e->dx;
	x = e->x0 + e->step_x;
	y = e->y0;
	i = 1;
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color);
	while (i <= e->dx)
	{
		if (error > 0)
		{
			y += e->step_y;
			error += (e->dy - e->dx) << 1; 
		}
		else
			error += e->dy << 1;
		mlx_pixel_put(e->mlx, e->win, x, y, e->line_color);
		x += e->step_x;
		i++;
	}
}

static	void		ft_draw_dy(t_env *e)
{
	int error;
	int i;
	int x;
	int y;

	error = (e->dx << 1) - e->dy;
	y = e->y0 + e->step_y;
	x = e->x0;
	i = 1;
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color); 
	while (i <= e->dy)
	{
		if (error > 0)
		{
			error += (e->dx - e->dy) << 1;
			x += e->step_x;
		}
		else
			error += e->dx << 1;
			mlx_pixel_put(e->mlx, e->win, x, y, e->line_color); 
		y += e->step_y;
		i++;
	}
}

void				bresenham_line(t_env *e)
{
	e->dx = abs(e->x1 - e->x0); 
	e->dy = abs(e->y1 - e->y0);
	e->step_x = e->x1 >= e->x0 ? 1 : -1;
	e->step_y = e->y1 >= e->y0 ? 1 : -1; 

	if (e->dx > e->dy)
		ft_draw_dx(e);
	else
		ft_draw_dy(e);
}
