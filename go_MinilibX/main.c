/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:09:01 by kprytkov          #+#    #+#             */
/*   Updated: 2018/05/09 18:09:02 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bresenham_line.h"

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
	int 	color;
	t_env 	*e;

	if (!(e = malloc(sizeof(t_env))))
		return (0);
	color = 8388352;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "mlx 42");
	// mlx_pixel_put(mlx_ptr, win_ptr, 50, 40, 8388352);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);

/* basic case */
/*	e->x0 = 0;														
	e->x1 = WIDTH;
	e->y0 = 0;
	e->y1 = HEIGHT;
	e->line_color = 8388352;
	bresenham_line(e);*/

/* when dy <= dx */
	for (int j = 0; j < HEIGHT; j++)
	{
		e->x0 = 0 + WIDTH / 2;
		e->x1 = WIDTH;
		e->y0 = 0 + HEIGHT / 2;
		e->y1 = j;
		e->line_color = j;
		bresenham_line(e);
	}	
	for (int j = 0; j < HEIGHT; j++)
	{
		e->x0 = WIDTH / 2;
		e->x1 = 0;
		e->y0 = HEIGHT / 2;
		e->y1 = j;
		e->line_color = j;
		bresenham_line(e);
	}

/* when dy >= dx */
	for(int j = 0; j < WIDTH; j++)
	{
		e->x0 = WIDTH / 2;
		e->x1 = j;
		e->y0 = HEIGHT / 2;
		e->y1 = HEIGHT;
		e->line_color = random();
		bresenham_line(e);
	}
	for(int j = 0; j < WIDTH; j++)
	{
		e->x0 = WIDTH / 2;
		e->x1 = j;
		e->y0 = HEIGHT / 2;
		e->y1 = 0;
		e->line_color = random();
		bresenham_line(e);
	}

	mlx_loop(e->mlx);
	return (0);
}
