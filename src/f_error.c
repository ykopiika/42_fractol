/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:54:08 by ykopiika          #+#    #+#             */
/*   Updated: 2019/05/14 13:54:33 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_error(int err_nb)
{
	if (err_nb == 0)
	{
		ft_putendl("Usage : ./fractol <name or number of fractal>");
		ft_putendl("0. Julia\n1. Mandelbrot\n2. Burning_ship");
		ft_putendl("3. Heart_mandelbrot\n4. Fish_mandelbrot");
		ft_putendl("5. Cubic_mandelbrot\n6. Arm_mandelbrot");
		ft_putendl("7. Triangle_mandelbrot");
		exit(err_nb);
	}
	else if (err_nb == 1)
	{
		ft_putendl("Malloc failed");
		exit(err_nb);
	}
	else if (err_nb == 2)
	{
		ft_putendl("Get pointer from mlx_function failed");
		exit(err_nb);
	}
}
