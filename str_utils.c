/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:54:05 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/13 20:07:53 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	control_options(void)
{
	ft_putstr("\n\t* * * WINDOW CONTROL OPTIONS * * *\n\n");
	ft_putstr("\tThe mouse wheel zooms in and out\n");
	ft_putstr("\tESC or Cross -> close the window\n");
	ft_putstr("\t'c' ----------> change colors\n");
	ft_putstr("\t'p' ----------> change Julia set\n");
	ft_putstr("\t'r' ----------> reset the view\n");
	ft_putstr("\t'i' ----------> show the window control options\n");
	ft_putstr("\t'*' ----------> increase the iteration\n");
	ft_putstr("\t'/' ----------> decrease the iteration\n\n");
}

void	show_options(void)
{
	write(1, "\n\tAvailable fractals:\n\n", 23);
	write(1, "\t- julia\n\n", 10);
	write(1, "\t- mandelbrot\n", 14);
	exit(1);
}
