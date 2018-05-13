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
	e->move_x = 40;
	e->move_y = 40;
	e->move_z = 40;
	e->scale_x = 40;
	e->scale_y = 40;
	e->scale_z = 40;
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
			i_will_scale(&(e->map[i][j]), e);
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

// int	i_will_move(t_env *e, int i, int j)
// {
// 	e->x0 = e->move_x + e->current_point[i][j].x;
// 	e->y0 = e->move_y + e->current_point[i][j].y;
// 	if ( j  + 1 < e->p_nb )
// 	{
// 		e->x1 = e->move_x + e->current_point[i][j + 1].x; 
// 		e->y1 = e->move_y + e->current_point[i][j + 1].y;
// 		return (1);
// 	}
// 	if ( i + 1 < e->l_nb)
// 	{
// 		e->x1 = e->move_x + e->current_point[i + 1][j].x;
// 		e->y1 = e->move_x + e->current_point[i + 1][j].y;
// 		return (2);
// 	}
// 	return (0);
// }

// // void	i_will_draw()
// // {

// // }