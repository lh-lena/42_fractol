/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:51:50 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/20 14:20:37 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = (img->line_length * y) + (x * (img->bpp / 8));
	*((unsigned int *)(pixel + img->addr)) = color;
}

int	ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			if (ft_strncmp(fractal->name, "julia", 6) == 0)
			{
				julia_calc(x, y, fractal);
			}
			else if (ft_strncmp(fractal->name, "mandelbrot", 11) == 0)
			{
				mandelbrot_calc(x, y, fractal);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, \
	fractal->img.mlx_img, 0, 0);
}
