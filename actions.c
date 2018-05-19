/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:48:40 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 16:48:42 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_draw(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		exit(1);
	}
	if (keycode == 24)
	{
		e->scale_x += 1;
		e->scale_y += 1;
		e->scale_z += 1;
	}
	if (keycode == 27)
	{
		e->scale_x -= 0.1;
		e->scale_y -= 0.1;
		e->scale_z -= 0.1;
	}
	if (keycode == 126)
	{
		e->angle_x += 0.1;
		// e->angle_y += 10;
		// e->angle_z += 3;
	}
	if (keycode == 125)
	{
		e->angle_x -= 0.1;
	}
	draw_each_frame(e);
	return (-1);
}