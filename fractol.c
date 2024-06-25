/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:30:10 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/13 19:39:45 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	check_set(char *str, t_fractal *fractal)
{
	if (ft_strncmp(str, "julia", 6) == 0)
	{
		fractal->name = "julia";
	}
	else if (ft_strncmp(str, "mandelbrot", 11) == 0)
	{
		fractal->name = "mandelbrot";
	}
	else
	{
		show_options();
		exit_fractal(fractal);
	}
}

void	window_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		malloc_error();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, W, H, \
	fractal->name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.mlx_img = mlx_new_image(fractal->mlx_ptr, W, H);
	if (fractal->img.mlx_img == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.mlx_img, \
		&fractal->img.bpp, &fractal->img.line_length, &fractal->img.endian);
	fractal_init(fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc != 2)
		show_options();
	check_set(argv[1], &fractal);
	window_init(&fractal);
	mlx_hook(fractal.win_ptr, KeyPress, KeyPressMask, &keypress, &fractal);
	mlx_hook(fractal.win_ptr, DestroyNotify, StructureNotifyMask, &cross, \
	&fractal);
	mlx_hook(fractal.win_ptr, ButtonPress, ButtonPressMask, &mouse, &fractal);
	draw_fractal(&fractal);
	control_options();
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
