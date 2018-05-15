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
	e->move_x = 0;
	e->move_y = 0;
	e->move_z = 0;
	e->scale_x = 40;
	e->scale_y = 40;
	e->scale_z = 40;

	e->angle_x = 0;
	e->angle_y = 0;
	e->angle_z = 0;
}

void 	transform(t_env *e)
{
	int i;
	int	j;

	i = 0;
	while (i <  e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{
			i_will_rotate(&(e->map[i][j]), e);
			i_will_scale(&(e->map[i][j]), e);
			i_will_move(&(e->map[i][j]), e);
			
			// TODO : ROTATE
			// TODO : TRANSLATE
			j++;
		}
		i++;
	}
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

void	i_will_rotate(t_point *current_point, t_env *e)
{
	/* rotate_x*/
	current_point->x = (current_point->x + (e->p_nb / 2));
	current_point->y = ( (current_point->y + (e->l_nb / 2))  * cos(e->angle_x)) + current_point->z * sin(e->angle_x);
	current_point->z = (-(current_point->y + (e->l_nb / 2)) * sin(e->angle_x)) + current_point->z * cos(e->angle_x);

	/* rotate_y*/
	current_point->x = (((current_point->x + (e->p_nb / 2)) * cos(e->angle_y)) + (current_point->z * sin(e->angle_y)));
	current_point->y = (current_point->y + (e->l_nb / 2));
	current_point->z = (-(current_point->y + (e->l_nb / 2)) * sin(e->angle_y)) + (current_point->z * cos(e->angle_y));

	 // rotate_z
	current_point->x = (((current_point->x + (e->p_nb / 2)) * cos(e->angle_z)) + ((current_point->y + (e->l_nb / 2)) * sin(e->angle_z)));
	current_point->y = (-((current_point->x + (e->p_nb / 2))) * sin(e->angle_z)) + ((current_point->y + (e->l_nb / 2)) * cos(e->angle_z));
	current_point->z = current_point->z;
}
