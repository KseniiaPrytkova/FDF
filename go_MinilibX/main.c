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
		printf("y <= dx\n");
		int x = x_0;
		int y = y_0;
		int d = -dx;

		max_delta++;
		while(max_delta--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 8388352);
			printf("%d %d\n",x, y);
			x = x + s_x;
			d = d + (2 * dy);
			if (d > 0) 
			{
				d = d - (2 * dx);
				y = y + s_y;
			}
		}
	}
	else
	{
		int x = x_1;
		int y = y_1;
		int d = -dy;

		max_delta++;
		while(max_delta--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 8388352);
			y = y + s_y;
			d = d + 2 * dx;
			if (d > 0)
			{
				d = d - (2 * dy);
				x = x + s_x;
			}
        }
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

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 40, 8388352);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	ft_bresenham(3, 20, 6, 2, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}