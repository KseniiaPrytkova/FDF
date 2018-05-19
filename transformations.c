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

void	rotate_x(t_point *current_point, t_env *e, int angle)
{
		int i = 0;
		int tmp_y;

		while (i < 4)
		{
			tmp_y = current_point->y;

			current_point->y = current_point->y * cos(angle) - (current_point->z * e->depth) * sin(angle);

			i++;
		}
}

void	rotate_y(t_point *current_point, t_env *e, int angle)
{
		int i = 0;
		int tmp_z;

		while (i < 4)
		{
			tmp_z = current_point->z;
			current_point->x = (tmp_z * e->depth) * sin(angle) + current_point->x * cos(angle);
			i++;
		}
}

void	rotate_z(t_point *current_point, t_env *e, int angle)
{
		int i = 0;
		int tmp_x;

		while (i < 4)
		{
			tmp_x = current_point->x;

			current_point->x = current_point->x * cos(angle) - current_point->y * sin(angle);
			current_point->y = tmp_x * sin(angle) + current_point->y * cos(angle);
			i++;
		}
}

// void	i_will_rotate(t_point *current_point, t_env *e)
// {

// }

void 	i_will_init(t_env *e)
{
	e->move_x = WIDTH / 2;
	e->move_y = HEIGHT / 2;
	e->move_z = 0;
	e->scale_x = 40;
	e->scale_y = 40;
	e->scale_z = 40;
	e->scale = 40;

	e->angle_x = 0.1;
	e->angle_y = 0.1;
	e->angle_z = 0.1;
	e->depth = 0.1;
}



void	i_will_scale(t_point *current_point, t_env *e)
{
	current_point->x = current_point->x * e->scale_x;
	current_point->y = current_point->y * e->scale_y;
	current_point->z = current_point->z * e->scale_z;
}

void	i_will_move(t_point *current_point, t_env *e)
{
	current_point->x = current_point->x + e->move_x;
	current_point->y = current_point->y + e->move_y;
	current_point->z = current_point->z + e->move_z;
}


void move_on_half_back(t_point *current_point, t_env *e)
{

	current_point->x = current_point->x - e->p_nb / 2;
	current_point->y = current_point->y - e->l_nb / 2;
	// current_point->z = current_point->z - e->move_z;
}

void move_to_center(t_point *current_point, t_env *e)
{

	current_point->x = current_point->x + WIDTH / 2;
	current_point->y = current_point->y + HEIGHT / 2;
	// current_point->z = current_point->z - e->move_z;
}

// t_point	t_linear(t_env *e, t_point p)
// {
// 	t_point tmp;

// 	tmp.x = p.x;
// 	tmp.y = p.y;
// 	tmp.z = p.z;
// 	p.x = e->scale * 
// 	((tmp.x - e->p_nb / 2)
// 	* cos(e->angle_y)
// 	* cos(e->angle_z) - (tmp.y - e->l_nb / 2)
// 	* sin(e->angle_z) * cos(e->angle_y) - tmp.z
// 	* e->depth * sin(e->angle_y));


// 	p.y = e->scale * ((tmp.x - e->p_nb / 2)
// 	* (-sin(e->angle_x) * sin(e->angle_y)
// 	* cos(e->angle_z) + cos(e->angle_x) * sin(e->angle_z))
// 	+ (p.y - e->l_nb / 2) * (sin(e->angle_x) * sin(e->angle_y)
// 	* sin(e->angle_z) +
// 	cos(e->angle_x) * cos(e->angle_z)) + tmp.z
// 	* e->depth * (-sin(e->angle_x)) * cos(e->angle_y));
// 	return (p);
// }

static	void	linear(t_env *e, int i, int j, int y)
{
	e->map[i][j].x =
	e->scale * (
	(e->map[i][j].x_before - e->p_nb / 2) * cos(e->angle_y) *
	cos(e->angle_z) -
	(y - e->l_nb / 2) * sin(e->angle_z) *
	cos(e->angle_y) -
	e->map[i][j].z_before * e->depth * sin(e->angle_y));
	e->map[i][j].y =
	e->scale * ((e->map[i][j].x_before - e->p_nb / 2) *
	(-sin(e->angle_x) * sin(e->angle_y) * cos(e->angle_z) +
	cos(e->angle_x) * sin(e->angle_z)) + (y - e->l_nb / 2)
	* (sin(e->angle_x) * sin(e->angle_y) * sin(e->angle_z) +
	cos(e->angle_x) * cos(e->angle_z)) + e->map[i][j].z_before
	* e->depth * (-sin(e->angle_x)) * cos(e->angle_y));
}

void 	transform(t_env *e)
{
	int i;
	int	j;
	int y;
	// int half_x;
	// int half_y;

	// half_x = e->p_nb / 2;
	// half_y = e->l_nb / 2;
	i = 0;
	while (i <  e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{

			//move_on_half_back(&(e->map[i][j]), e);

			//rotate_z(&(e->map[i][j]), e, e->angle_z);
			y = e->map[i][j].y;
			linear(e, i, j ,y);
			//e->map[i][j] = t_linear(e, e->map[i][j]);
			//rotate_x(&(e->map[i][j]), e, e->angle_x);
			//i_will_scale(&(e->map[i][j]), e);
			//rotate_y(&(e->map[i][j]), e, e->angle_y);

	
			move_to_center(&(e->map[i][j]), e);



			// e->map[i][j].x += e->move_x;
			// e->map[i][j].y += e->move_y;



			// i_will_move(&(e->map[i][j]), e);
			
	
			j++;
		}
		i++;
	}
}


