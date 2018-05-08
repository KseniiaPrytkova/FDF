#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

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

void	form_line_below(int x_0, int y_0, int x_1, int y_1, int dx, int dy, int yi, void *mlx_ptr, void *win_ptr, int color)
{
	int difference;
	int y;

	difference = 0;
	y = 0;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	difference = (2 * dy) - dx;
	y = y_0;

	int x = x_0;
	while (x < x_1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		if (difference > 0)
		{
			y = y + yi;
       		difference = difference - (2 * dx);
		}
		difference = difference + (2 * dy);
		x++;
	}
}

void	form_line_above(int x_0, int y_0, int x_1, int y_1, int dx, int dy, int xi, void *mlx_ptr, void *win_ptr, int color)
{
	int difference;
	int x;

	difference = 0;
	x = 0;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	difference = (2 * dx) - dy;
	x = x_0;

	int y = y_0;
	while (y < y_1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		if (difference > 0)
		{
			x = x + xi;
       		difference = difference - (2 * dy);
		}
		difference = difference + (2 * dx);
		y++;
	}
	
}

void 		ft_bresenham(int x_0, int y_0, int x_1, int y_1, void *mlx_ptr, void *win_ptr, int color)
{
	int 	dx;
	int		dy;
	int 	xi;
	int 	yi;
	
	dx = abs(x_1 - x_0);
	dy = abs(y_1 - y_0);
	xi = 1;
	yi = 1;
	if (dx == dy && dx <= 1 && dy <= 1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, color);
		return ;
	}
	else if (dy < dx)
	{
		if (x_0 > x_1)
      		form_line_below(x_1, y_1, x_0, y_0, dx, dy, yi, mlx_ptr, win_ptr, color);
    	else
      		form_line_below(x_0, y_0, x_1, y_1, dx, dy, yi, mlx_ptr, win_ptr, color);
	}
	else if (dy > dx)
	{
		if (y_0 > y_1)
      		form_line_above(x_1, y_1, x_0, y_0, dx, dy, xi, mlx_ptr, win_ptr, color);
    	else
      		form_line_above(x_0, y_0, x_1, y_1, dx, dy, xi, mlx_ptr, win_ptr, color);
	}

}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int color_1;
	int color_2;
	int color_3;

	color_1 = 16777215;
	color_2 = 16711680;
	color_3 = 8388352;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 40, 8388352);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);

	ft_bresenham(10, 50, 60, 20, mlx_ptr, win_ptr, color_1);
	// ft_bresenham(20, 13, 40, 80, mlx_ptr, win_ptr, color_2);
	// ft_bresenham(80, 40 , 13, 20, mlx_ptr, win_ptr, color_3);
	
	mlx_loop(mlx_ptr);
	return (0);
}