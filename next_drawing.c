/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:23:38 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/21 16:23:39 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void			move_to_center(t_point *current_point)
{
	current_point->x = current_point->x + WIDTH / 2;
	current_point->y = current_point->y + HEIGHT / 2;
}

static void		matrix_reset(t_env *e)
{
	int i;
	int	j;

	i = 0;
	while (i < e->l_nb)
	{
		j = 0;
		while (j < e->p_nb)
		{
			e->map[i][j].x = e->map[i][j].x_before;
			e->map[i][j].y = e->map[i][j].y_before;
			e->map[i][j].z = e->map[i][j].z_before;
			j++;
		}
		i++;
	}
}

void			tips(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 10, 0x0033CC, "ZOOM: - || +");
	mlx_string_put(e->mlx, e->win, 20, 30, 0x0033CC, "ROTATE_X: up || down");
	mlx_string_put(e->mlx, e->win, 20, 50, 0x0033CC, "ROTATE_Y: left || right");
	mlx_string_put(e->mlx, e->win, 20, 70, 0x0033CC, "ROTATE_Z: q || a");
	mlx_string_put(e->mlx, e->win, 20, 90, 0x0033CC, "DEPTH: w || s");
	mlx_string_put(e->mlx, e->win, 20, 110, 0x0033CC, "RESET_ALL: space");
	mlx_string_put(e->mlx, e->win, 20, 130, 0x0033CC, "COLOUR: 1 || 2 || 3");
}

void			draw_each_frame(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	matrix_reset(e);
	tips(e);
	transform(e);
	draw_all(e);
}

int				select_scale(t_env *e)
{
	int percent;
	int x_val;
	int y_val;
	int x_scale;
	int y_scale;

	percent = 80;
	x_val = (percent * WIDTH) / 100;
	y_val = (percent * HEIGHT) / 100;
	if (e->p_nb < 1 || e->l_nb < 1)
		return (0);
	x_scale = x_val / e->p_nb;
	y_scale = y_val / e->l_nb;
	if (x_scale > y_scale)
		e->scale = y_scale;
	else
		e->scale = x_scale;
	return (e->scale);
}
