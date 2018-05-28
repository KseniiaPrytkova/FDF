/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:16:19 by kprytkov          #+#    #+#             */
/*   Updated: 2018/04/18 18:16:20 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

# define WIDTH 		864
# define HEIGHT 	540
# define MARGIN 	10
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
	int		l_nb;
	int		p_nb;
	t_point		**map;
	int		fd;
	char		*map_name;
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
	int		move_x;
	int		move_y;
	int		move_z;
	int		scale_x;
	int		scale_y;
	int		scale_z;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		depth;
	int		color_change;
	int		scale;
	double		rad_x;
	double		rad_y;
	double		rad_z;
}			t_env;

int			get_next_line(const int fd, char **line);
int			i_will_count_lines(t_env *e);
char			**ft_split(char *str);
int			i_will_read(t_env *e);
int			is_it_hex(char *str);
int			ft_atoi_base(char *nb, int base);
void			bresenham_line(t_env *e);
void			i_will_init(t_env *e);
void			transform(t_env *e);
void			move_to_center(t_point *current_point);
void			draw_all(t_env *e);
int			key_draw(int keycode, t_env *e);
void			draw_each_frame(t_env *e);
int			select_scale(t_env *e);
void			tips(t_env *e);

#endif
