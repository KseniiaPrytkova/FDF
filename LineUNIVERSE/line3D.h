/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:23:27 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/18 16:23:29 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE3D_H
# define LINE3D_H
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

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			x_before;
	int			y_before;
	int			z_before;
	int			color;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			step_x;
	int			step_y;
	int			dx;
	int			dy;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			line_color;
	int			tmp_angle;
	t_point		*points;

}				t_env;

void			bresenham_line(t_env *e);

#endif
