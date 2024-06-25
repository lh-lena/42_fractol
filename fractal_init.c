/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:50:56 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/13 18:39:04 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->shift_y = 0.0;
	fractal->shift_x = 0.0;
	fractal->zoom = 1.0;
	fractal->max_itr = 80;
	fractal->c = 0;
	fractal->c_re = -0.8;
	fractal->c_im = 0.2;
}
