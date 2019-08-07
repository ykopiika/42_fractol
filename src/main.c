/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:23:26 by ykopiika          #+#    #+#             */
/*   Updated: 2019/05/14 13:23:29 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_name_frtl(t_frctl *frt, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	FRCTL = 10;
	if (len == 1 && str[0] >= '0' && str[0] <= '7')
		FRCTL = str[0] - '0';
	else if ((ft_strcmp("Julia", str) == 0))
		FRCTL = JULIA;
	else if ((ft_strcmp("Mandelbrot", str) == 0))
		FRCTL = MDLBRT;
	else if ((ft_strcmp("Burning_ship", str) == 0))
		FRCTL = BRNG_SHIP;
	else if ((ft_strcmp("Heart_mandelbrot", str) == 0))
		FRCTL = HEART_MDLBRT;
	else if ((ft_strcmp("Fish_mandelbrot", str) == 0))
		FRCTL = FISH_MDLBRT;
	else if ((ft_strcmp("Cubic_mandelbrot", str) == 0))
		FRCTL = CUBIC_MDLBRT;
	else if ((ft_strcmp("Arm_mandelbrot", str) == 0))
		FRCTL = ARM_MDLBRT;
	else if ((ft_strcmp("Triangle_mandelbrot", str) == 0))
		FRCTL = TRNGL_MDLBRT;
	if (FRCTL == 10)
		return (0);
	return (1);
}

static void	f_mlx_init(t_frctl *frt)
{
	MLX = mlx_init();
	if (!MLX)
		f_error(2);
	WIN = mlx_new_window(MLX, WIN_W, WIN_H, "fractol");
	if (!WIN)
		f_error(2);
	IMG_PTR = mlx_new_image(MLX, WIN_W, WIN_H);
	if (!IMG_PTR)
		f_error(2);
	IMG_DATA = (int *)mlx_get_data_addr(IMG_PTR, &frt->img_data.bpp,
			&frt->img_data.size, &frt->img_data.endian);
}

int			main(int ac, char **av)
{
	t_frctl	*frt;

	if (ac != 2)
		f_error(0);
	frt = (t_frctl *)malloc(sizeof(t_frctl));
	if (!frt)
		f_error(1);
	if (get_name_frtl(frt, av[1]) == 0)
		f_error(0);
	f_mlx_init(frt);
	f_value_frtl(frt);
	f_hook(frt);
	mlx_loop(MLX);
	return (0);
}
