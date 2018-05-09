#include "fdf.h"

////////////////////// if dy <= dx
static	void		ft_draw_dx(t_env *e)
{
    // PIXEL IS A BOX! LINE IS AN ABSTRACT SEQUENCE OF POINTS. THE IDEA IS TO FIGURE OUT WHICH PIXEL IS CLOSER TO THE ABSTACT POINT. ABSTACT POINT IS AN INFINATELY SMALL THAT'S WHY WE MAY COLOR ONLY THE PIXEL (WHICH REPRESENTS THE POINT)
	int error; // DISTANCE BEETWEN THE ABSTACT LINE AND THE NEXT PIXEL
	int i;
	int x;
	int y;

	error = (e->dy << 1) - e->dx;
	x = e->x0 + e->step_x; // STEP TO THE NEXT PIX
	y = e->y0;
	i = 1; // NOT 0 cause we put the first pixel on the next 
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color); // PUT THE FIRST PIXEL
	while (i <= e->dx) // UNTILL Y < Y_MAX or UNTILL THE END OF THE 
	{
        if (error > 0) // IF THE ABSTRACT  IS CLOSER TO THE NEXT PIXEL THAN CURRENT
		{
			y += e->step_y; // CURRENT PIXEL = NEW PIXEL
            error += (e->dy - e->dx) << 1; // 
		}
		else
			error += e->dy << 1; // 
		mlx_pixel_put(e->mlx, e->win, x, y, e->line_color);
        x += e->step_x; // EACH STEP X += STEP;
		i++;
	}
}

////////////////////////

static	void		ft_draw_dy(t_env *e)
{
	int error;
	int i;
	int x;
	int y;

	error = (e->dx << 1) - e->dy;
	y = e->y0 + e->step_y;
	x = e->x0;
	i = 1;
	mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color); 
	while (i <= e->dy)
	{
		if (error > 0)
		{
			error += (e->dx - e->dy) << 1;
			x += e->step_x;
		}
		else
			error += e->dx << 1;
			mlx_pixel_put(e->mlx, e->win, x, y, e->line_color); 
		y += e->step_y;
		i++;
	}
}

void				ft_bresenham(t_env *e)
{
	e->dx = abs(e->x1 - e->x0); // delta x 
	e->dy = abs(e->y1 - e->y0); // delta y
    e->step_x = e->x1 >= e->x0 ? 1 : -1; // stepx if line (from left to right) = +1 ; else = -1
	e->step_y = e->y1 >= e->y0 ? 1 : -1; // stepy if line (from up to down) = +1 ; else = -1

	if (e->dx > e->dy)
		ft_draw_dx(e);
	else
		ft_draw_dy(e);
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
	t_env *e;

	e = malloc(sizeof(t_env));
	color_1 = 16777215;
	color_2 = 16711680;
	color_3 = 8388352;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 40, 8388352);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
// 		for(int j = 0; j < HEIGHT; j++)
// 		{
// 			e->x0 = 0 + WIDTH / 2;
// 			e->x1 = WIDTH;
// 			e->y0 = 0 + HEIGHT / 2;
// 			e->y1 = j;
// 			e->line_color = j;
// 			ft_bresenham(e);
// 		}
// 		for(int j = 0; j < HEIGHT; j++)
// 		{
// 			e->x0 = WIDTH / 2;
// 			e->x1 = 0;
// 			e->y0 = HEIGHT / 2;
// 			e->y1 = j;
// 			e->line_color = j;
// 			ft_bresenham(e);
// 		}

// ////////////////////////////////////////////////////

// 		for(int j = 0; j < WIDTH; j++)
// 		{
// 			e->x0 = WIDTH / 2;
// 			e->x1 = j;
// 			e->y0 = HEIGHT / 2;
// 			e->y1 = HEIGHT;
// 			e->line_color = 0xFFFF00 - j;
// 			ft_bresenham(e);
// 		}
// 		for(int j = 0; j < WIDTH; j++)
// 		{
// 			e->x0 = WIDTH / 2;
// 			e->x1 = j;
// 			e->y0 = HEIGHT / 2;
// 			e->y1 = 0;
// 			e->line_color = 0xFFFF00 - j;
// 			ft_bresenham(e);
// 		}

	for (int i = 0; i <= 50000; i++)
	{
		e->x0 = (WIDTH / 4 + random()) % (WIDTH - 1) - WIDTH / 4;
 		e->x1 = (random() % WIDTH - 1);
 		e->y0 = random() % HEIGHT - 1;
 		e->y1 = random() % HEIGHT - 1;
 		e->line_color = random();
 		mlx_pixel_put(e->mlx, e->win, e->x0, e->y0, e->line_color);
 		//ft_bresenham(e);
	}

	// ft_bresenham(20, 13, 40, 80, mlx_ptr, win_ptr, color_2);
	// ft_bresenham(80, 40 , 13, 20, mlx_ptr, win_ptr, color_3);
	
	mlx_loop(e->mlx);
	return (0);
}