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
	int 	delta_x;
	int		delta_y;
	int 	length_x;
	int 	length_y;
	int 	max_length;
	// int		incline_Y;
	// int		incline_X;
	// incline_Y = 0;
	// incline_X = 0;

	delta_x = (x_1 - x_0 >= 0 ? 1 : -1);
    delta_y = (y_1 - y_0 >= 0 ? 1 : -1);

    length_x = abs(x_1 - x_0);
    length_y = abs(y_1 - y_0);
    max_length = ft_max(length_x, length_y, max_length);
      
    if (max_length == 0)
    {
		mlx_pixel_put(mlx_ptr, win_ptr, x_0, y_0, 8388352);
	}
 
	if (length_y <= length_x)
	{
		// Начальные значения
		int x = x_0;
		int y = y_0;
		int d = -length_x;

		// Основной цикл
		max_length++;
		while(max_length--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 8388352);
			x += delta_x;
			d += 2 * length_y;
			if (d > 0) 
			{
				d -= 2 * length_x;
				y += delta_y;
			}
		}
	}
	else
	{
		// Начальные значения
		int x = x_1;
		int y = y_1;
		int d = - length_y;
		
		// Основной цикл
		max_length++;
		while(max_length--)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 8388352);
			y += delta_y;
			d += 2 * length_x;
			if (d > 0)
			{
				d -= 2 * length_y;
				x += delta_x;
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
	ft_bresenham(50, 450, 30, 200, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}