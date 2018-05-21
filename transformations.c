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

#include "fdf.h"


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
}

void move_to_center(t_point *current_point, t_env *e)
{

	current_point->x = current_point->x + WIDTH / 2;
	current_point->y = current_point->y + HEIGHT / 2;

}


static	void	linear(t_env *e, int i, int j, int y, double z_val)
{
	double rad_x = e->angle_x * M_PI / 180.0;
	double rad_y = e->angle_y * M_PI / 180.0;
	double rad_z  = e->angle_z * M_PI / 180.0;

	int p_half;
	int l_half;

	p_half = e->map[i][j].x_before - e->p_nb / 2;
	l_half = y - e->l_nb / 2;

	e->map[i][j].x = e->scale *
	(p_half * cos(rad_y) * cos(rad_z) - 
		l_half * sin(rad_z) * cos(rad_y) - 
		z_val * sin(rad_y));

	e->map[i][j].y = e->scale * 
	(p_half * (-sin(rad_x) * sin(rad_y) * cos(rad_z) + cos(rad_x) * sin(rad_z)) + 
		l_half * (sin(rad_x) * sin(rad_y) * sin(rad_z) + cos(rad_x) * cos(rad_z)) + 
		z_val * (-sin(rad_x)) * cos(rad_y));
}

void 	transform(t_env *e)
{
	int i;
	int	j;
	int y;
	double z_val;

	i = 0;
	while (i <  e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{

			y = e->map[i][j].y;
				z_val = (double)(e->map[i][j].z_before) * e->depth;
			linear(e, i, j ,y, z_val);	
			move_to_center(&(e->map[i][j]), e);

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

