/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:32:35 by ohladkov          #+#    #+#             */
/*   Updated: 2024/08/01 12:32:08 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W	800
# define H	700
# define WIN_MANAGE "Press 'i' to see the window control options\n"
# define PI 3.141592654
# define R 0.7885
# define RE_START 1.4
# define RE_END 1.6
# define IM_START -0.1
# define IM_END 0.1

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_img {
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*name;
	int		color;
	double	shift_y;
	double	shift_x;
	double	zoom;
	int		itr;
	int		max_itr;
	int		c;
	double	c_im;
	double	c_re;
	t_img	img;
}			t_fractal;

void	exit_fractal(t_fractal *fractal);
int		keypress(int keysym, t_fractal *fractal);
int		cross(t_fractal *fractal);
int		mouse(int button, int x, int y, t_fractal *fractal);
void	window_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);
void	show_options(void);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	draw_fractal(t_fractal *fractal);
void	mandelbrot_calc(int x, int y, t_fractal *fractal);
void	julia_calc(int x, int y, t_fractal *fractal);
int		ft_rgb(int r, int g, int b);
void	random_julia(t_fractal *fractal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);
void	control_options(void);

#endif
