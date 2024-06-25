/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:01:19 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/13 19:50:45 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keypress(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		cross(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.9 * (0.5 / fractal->zoom));
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.9 * (0.5 / fractal->zoom));
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.9 * (0.5 / fractal->zoom));
	else if (keysym == XK_Down)
		fractal->shift_y += (0.9 * (0.5 / fractal->zoom));
	else if (keysym == XK_c)
		fractal->c += 5;
	else if (keysym == XK_p)
		random_julia(fractal);
	else if (keysym == XK_i)
		control_options();
	else if (keysym == XK_r)
		fractal_init(fractal);
	else if (keysym == XK_KP_Multiply)
		fractal->max_itr += 10;
	else if (keysym == XK_KP_Divide)
		fractal->max_itr -= 10;
	draw_fractal(fractal);
	return (0);
}

int	cross(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.mlx_img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit (EXIT_SUCCESS);
}

int	mouse(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	draw_fractal(fractal);
	return (0);
}
