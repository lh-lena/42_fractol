/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:04:03 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/26 17:27:04 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_calc(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		temp_re;
	int			col;

	c.re = fractal->c_re;
	c.im = fractal->c_im;
	z.re = (x - W / 2) * 4 / (W * fractal->zoom) + fractal->shift_x;
	z.im = (y - H / 2) * 4 / (H * fractal->zoom) + fractal->shift_y;
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
	// fractal->color = ft_rgb(col * fractal->c, col * fractal->c, col);
	fractal->color = ft_rgb(col + fractal->c, col, col * fractal->c);
	if (fractal->itr == fractal->max_itr)
		ft_pixel_put(&fractal->img, x, y, 0x000000);
	else
		ft_pixel_put(&fractal->img, x, y, fractal->color);
}

void	random_julia(t_fractal *fractal)
{
	static double	a;
	static double	i;

	if (i < 2.0 && i > 0.0)
	{
		i += 0.005;
		a = i * PI;
		fractal->c_re = R * cos(a);
		fractal->c_im = R * sin(a);
	}
	else
	{
		i = 0.005;
		random_julia(fractal);
	}
}
