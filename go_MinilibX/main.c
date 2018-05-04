#include "mlx.h"

int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 50, 40, 8388352);
	mlx_loop(mlx_ptr);
	return (0);
}