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

#include "fdf.h"

static void	matrix_reset(t_env *e)
{
	int i;
	int	j;

	i = 0;
	while (i <  e->l_nb)
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

// int		loop_draw(t_env *e)
// {
// 	e->angle_x += 1;
// 	draw_each_frame(e);
// 	return (0);
// }

void	draw_each_frame(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	matrix_reset(e);

	mlx_string_put(e->mlx, e->win, 20, 20, 0xFFFFFF,  ft_strjoin("x_angle:", ft_itoa(e->angle_x)));
	mlx_string_put(e->mlx, e->win, 20, 40, 0xFFFFFF,  ft_strjoin("y_angle:", ft_itoa(e->angle_y)));
	mlx_string_put(e->mlx, e->win, 20, 60, 0xFFFFFF,  ft_strjoin("z_angle:", ft_itoa(e->angle_z)));
	transform(e);
	draw_all(e);
}

int select_scale(t_env *e)
{
	int percent;
	int x_val;
	int y_val;
	int x_scale;
	int y_scale;

	percent = 60;
	x_val = (percent * WIDTH) / 100;
	printf("%d\n", x_val );
	y_val = (percent * HEIGHT) / 100;
	printf("%d\n", y_val );

	x_scale = x_val / e->p_nb;
	printf("%d\n", x_scale );

	y_scale = y_val / e->l_nb;
	printf("%d\n", y_val );
	if (x_scale > y_scale)
		e->scale = y_scale;
	else
		e->scale = x_scale;
	printf("scale:%d\n", e->scale );
	return (e->scale);
}