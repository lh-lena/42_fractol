/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:03:28 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/13 18:52:25 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp_re;
	int			col;

	z.re = 0.0;
	z.im = 0.0;
	c.re = ((x - W / 2) * 4 / (W * fractal->zoom)) + fractal->shift_x;
	c.im = ((y - H / 2) * 4 / (H * fractal->zoom)) + fractal->shift_y;
	fractal->itr = 0;
	while (fractal->itr < fractal->max_itr)
	{
		temp_re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp_re;
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		fractal->itr++;
	}
	col = 255 * fractal->itr / fractal->max_itr;
	fractal->color = ft_rgb(col + fractal->c, col, col * fractal->c);
	if (fractal->itr == fractal->max_itr)
		ft_pixel_put(&fractal->img, x, y, 0x000000);
	else
		ft_pixel_put(&fractal->img, x, y, fractal->color);
}
