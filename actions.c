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

void guess_color(int keycode, t_env *e)
	{
		if (keycode == 18)
		{
			e->color_change = 0;
		}
		if (keycode == 19)
		{
			e->color_change = 1;
		}
		if (keycode == 20)
		{
			e->color_change = 2;
		}
		if (keycode == 21)
		{
			e->color_change = 3;
		}
		// e->color_change = 3;
	}

int key_draw(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		exit(1);
	}
	if (keycode == 24)
	{
		e->scale += 1;
	}
	if (keycode == 27)
	{
		if (e->scale != 0)
			e->scale -= 1;
	}
	if (keycode == 126)
	{
		e->angle_x += 5;

	}
	if (keycode == 125)
	{
		e->angle_x -= 5;
	}
	if (keycode == 123)
	{
		e->angle_y += 5;

	}
	if (keycode == 124)
	{
		e->angle_y -= 5;
	}
	if (keycode == 12)
	{
		e->angle_z += 5;
	}
	if (keycode == 0)
	{
		e->angle_z -= 5;
	}
	if (keycode == 13)
	{
		e->depth += 0.1;
	}
	if (keycode == 1)
	{
		e->depth -= 0.1;
	}
	
	if (keycode == 49)
	{
		i_will_init(e);
	}

	guess_color(keycode, e);

	draw_each_frame(e);
	return (-1);
}