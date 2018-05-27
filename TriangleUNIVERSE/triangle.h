/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:03:19 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 14:03:20 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 		1200
# define HEIGHT 	1200
# define PI 		3.14159265359
# define ARG_FROM_X	e->x0
# define ARG_FROM_Y	e->y0
# define ARG_TO_X	e->x1
# define ARG_TO_Y	e->y1

typedef struct		s_point
{
	int		x;
	int		y;
	int		z;
	int		x_before;
	int		y_before;
	int		z_before;
	int		color;
}			t_point;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	int		step_x;
	int		step_y;
	int		dx;
	int		dy;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		line_color;
	int		tmp_angle;
	t_point		*points;

}			t_env;

void			bresenham_line(t_env *e);
int			key_exit(int keycode);
int 			key_draw(int keycode, t_env *e);
int 			loop_draw(t_env *e);
void			rotate_x(t_env *e, int angle);
void			rotate_y(t_env *e, int angle);
void			rotate_z(t_env *e, int angle);
void			draw_triangle(t_env *e, int size, int start);
void			draw_line_and_rotate(t_env *e);
void			line_fill_param(t_env *e, int x0, int y0, int x1, int y1);
t_point			fill_point(int x, int y, int z);
void			move_all(t_env *e, int move_x, int move_y);

#endif
