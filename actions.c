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
		e->scale += 1;
		// e->scale += 5;
		// e->scale += 5;
		printf("%d\n",e->scale );
	}
	if (keycode == 27)
	{
		if (e->scale != 0)
			e->scale -= 1;

		// e->scale -= 5;
		// e->scale -= 5;
		printf("%d\n",e->scale );
	}
	if (keycode == 126)
	{
		e->angle_x += 5;
		// e->angle_y += 10;
		// e->angle_z += 3;
	}
	if (keycode == 125)
	{
		e->angle_x -= 5;
	}
	if (keycode == 123)
	{
		e->angle_y += 5;
		// e->angle_y += 10;
		// e->angle_z += 3;
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
	draw_each_frame(e);
	return (-1);
}