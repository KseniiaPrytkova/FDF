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
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line.h"

# define WIDTH 1200
# define HEIGHT 800
# define MARGIN 10 

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
	int			l_nb; /*количество строк в карте*/
	int			p_nb; /*количество точек в каждой строке*/
	t_point		**map;
	int			fd;
	char		*map_name; /*argv*/
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
}				t_env;

int				get_next_line(const int fd, char **line);
int				i_will_count_lines(t_env *e);
char			**ft_split(char *str);
void			i_will_read(t_env *e);
int				ft_atoi_base(char *nb, int base);
void			bresenham_line(t_env *e);

#endif
