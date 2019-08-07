/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_value_frtl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:30:39 by ykopiika          #+#    #+#             */
/*   Updated: 2019/05/27 16:30:42 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	f_set_standart(t_frctl *frt)
{
	FLAG.menu_color = 0;
	FLAG.menu = 1;
	FLAG.color = 0;
	FLAG.lock_julia = 0;
	FLAG.minus_plus = 0;
	VAL_A.max_i = 100;
	VAL_A.zoom = 0.8;
	VAL_A.mv_x = 0;
	VAL_A.mv_y = 0;
	VAL_A.count_zoom = 0;
	VAL_A.rgb.r = 9;
	VAL_A.rgb.g = 15;
	VAL_A.rgb.b = 8;
	VAL_A.const_color = 0;
	frt->frtl[0] = &f_julia;
	frt->frtl[1] = &f_mandelbrot;
	frt->frtl[2] = &f_burning_ship;
	frt->frtl[3] = &f_heart_mandelbrot;
	frt->frtl[4] = &f_fish_mandelbrot;
	frt->frtl[5] = &f_cubic_mandelbrot;
	frt->frtl[6] = &f_arm_mandelbrot;
	frt->frtl[7] = &f_trngl_mandelbrot;
}

void		f_value_frtl(t_frctl *frt)
{
	f_set_standart(frt);
	if (FRCTL == JULIA)
	{
		VAL_A.c_re = -0.7;
		VAL_A.c_im = 0.27015;
	}
	else if (FRCTL == MDLBRT)
		VAL_A.mv_x = -0.5;
	else if (FRCTL == BRNG_SHIP)
	{
		VAL_A.mv_x = -0.3;
		VAL_A.mv_y = -0.3;
	}
	else if (FRCTL == HEART_MDLBRT)
		VAL_A.mv_x = -0.4;
	else if (FRCTL == FISH_MDLBRT)
		VAL_A.mv_x = -0.6;
	VAL_B = VAL_A;
	f_print_frtl(frt, VAL_A, frt->frtl[FRCTL]);
}
