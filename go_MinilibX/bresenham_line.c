/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:05:37 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/06 20:05:38 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int d_x, int d_y, int max_d)
{
	if (d_y < d_x)
		max_d = d_x;
	else if (d_y > d_x)
		max_d = d_y;
	else if (d_y == d_x)
		max_d = 0;
	return (max_d);
}

void 	ft_bresenham(int x_0, int x_1, int y_0, int y_1, void *mlx_ptr, void *win_ptr)
{
	int 	dx;
	int		dy;
	int 	s_x;
	int 	s_y;
	int 	max_delta;

	dx = abs(x_1 - x_0);
	if ((x_1 - x_0) >= 0)
		s_x = 1;
	else
		s_x = 0;
    
    dy = abs(y_1 - y_0);
    
    if ((y_1 - y_0) >= 0)
		s_y = 1;
	else
		s_y = 0; 
    max_delta = ft_max(dx, dy, max_delta);    
    if (max_delta == 0)
		mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 8388352);
	if (dy <= dx)
	{
		int x = x_0;
		int y = y_0;
		int d = -dx;

		max_delta = max_delta + 1;
		while(max_delta != 0)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 8388352);
			x = x + s_x;
			
			d = d + (2 * dy);
			if (d > 0) 
			{
				d = d - (2 * dx);
				y = y + s_y;
			}
			max_delta--;
		}
	}
	else
	{
		int x = x_1;
		int y = y_1;
		int d = -dy;

		max_delta = max_delta + 1;
		while(max_delta != 0)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 8388352);
			y = y + s_y;
			d = d + 2 * dx;
			if (d > 0)
			{
				d = d - (2 * dy);
				x = x + s_x;
			}
			max_delta--;
        }
	}
}
