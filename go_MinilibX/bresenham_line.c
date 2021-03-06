/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:05:37 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/06 20:05:38 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham_line.h"

/* if dy <= dx */
static	void		ft_draw_dx(t_env *e)
{
	/* PIXEL IS A BOX! LINE IS AN ABSTRACT SEQUENCE OF POINTS. */
	/* THE IDEA IS TO FIGURE OUT WHICH PIXEL IS CLOSER TO THE ABSTACT POINT. */
	/* ABSTACT POINT IS AN INFINATELY SMALL THAT'S WHY WE MAY COLOR ONLY THE PIXEL */
	/* (WHICH REPRESENTS THE POINT) */
	int	error; /* DISTANCE BEETWEN THE ABSTACT LINE AND THE NEXT PIXEL */
	int	i;
	int	x;
	int	y;

	error = (e->dy << 1) - e->dx;
	x = e->x0 + e->step_x; /* STEP TO THE NEXT PIX */
	y = e->y0;
	i = 1; /* NOT 0 cause we put the first pixel on the next */
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color); // PUT THE FIRST PIXEL */
	while (i <= e->dx) /* UNTILL Y < Y_MAX or UNTILL THE END OF THE */
	{
		if (error > 0) /* IF THE ABSTRACT  IS CLOSER TO THE NEXT PIXEL THAN CURRENT */
		{
			y += e->step_y; /* CURRENT PIXEL = NEW PIXEL */
			error += (e->dy - e->dx) << 1;
		}
		else
			error += e->dy << 1;
		mlx_pixel_put(e->mlx, e->win, x, y, e->line_color);
		x += e->step_x; /* EACH STEP X += STEP; */
		i++;
	}
}
/* if dy >= dx */
static	void		ft_draw_dy(t_env *e)
{
	int	error;
	int	i;
	int	x;
	int	y;

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
	e->dx = abs(e->x1 - e->x0); /* delta x */
	e->dy = abs(e->y1 - e->y0); /* delta y */
	e->step_x = e->x1 >= e->x0 ? 1 : -1; /* stepx if line (from left to right) = +1 ; else = -1 */
	e->step_y = e->y1 >= e->y0 ? 1 : -1; /* stepy if line (from up to down) = +1 ; else = -1 */
	if (e->dx > e->dy)
		ft_draw_dx(e);
	else
		ft_draw_dy(e);
}
