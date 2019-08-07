/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fractals_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:28:07 by ykopiika          #+#    #+#             */
/*   Updated: 2019/06/01 20:28:10 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vrbl	f_fish_mandelbrot(t_vrbl v)
{
	v.c_re = 1.5 * (v.x - WIN_W / 2) / (0.5 * v.zoom * WIN_W) + v.mv_x;
	v.c_im = (v.y - WIN_H / 2) / (0.5 * v.zoom * WIN_H) + v.mv_y;
	v.n_re = 0;
	v.n_im = 0;
	v.i = 0;
	while (v.i < v.max_i)
	{
		v.o_re = v.n_re;
		v.o_im = v.n_im;
		v.n_re = fabs(v.o_re * v.o_re - v.o_im * v.o_im) + v.c_re;
		v.n_im = 2 * v.o_re * v.o_im + v.c_im;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}

t_vrbl	f_cubic_mandelbrot(t_vrbl v)
{
	v.c_re = 1.5 * (v.x - WIN_W / 2) / (0.5 * v.zoom * WIN_W) + v.mv_x;
	v.c_im = (v.y - WIN_H / 2) / (0.5 * v.zoom * WIN_H) + v.mv_y;
	v.n_re = 0;
	v.n_im = 0;
	v.i = 0;
	while (v.i < v.max_i)
	{
		v.o_re = v.n_re;
		v.o_im = v.n_im;
		v.n_im = ((3 * v.o_re * v.o_re) - v.o_im * v.o_im) * v.o_im + v.c_im;
		v.n_re = (v.o_re * v.o_re - (v.o_im * v.o_im * 3)) * v.o_re + v.c_re;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}

t_vrbl	f_arm_mandelbrot(t_vrbl v)
{
	v.c_re = 1.5 * (v.x - WIN_W / 2) / (0.5 * v.zoom * WIN_W) + v.mv_x;
	v.c_im = (v.y - WIN_H / 2) / (0.5 * v.zoom * WIN_H) + v.mv_y;
	v.n_re = 0;
	v.n_im = 0;
	v.i = 0;
	while (v.i < v.max_i)
	{
		v.o_re = v.n_re;
		v.o_im = v.n_im;
		v.n_im = ((3 * v.o_re * v.o_re) - v.o_im * v.o_im) * v.o_im + v.c_im;
		v.n_re = -(v.o_re * v.o_re - (v.o_im * v.o_im * 3)) * v.o_re + v.c_re;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}

t_vrbl	f_trngl_mandelbrot(t_vrbl v)
{
	double resqr;
	double imsqr;

	v.c_re = 1.5 * (v.x - WIN_W / 2) / (0.5 * v.zoom * WIN_W) + v.mv_x;
	v.c_im = (v.y - WIN_H / 2) / (0.5 * v.zoom * WIN_H) + v.mv_y;
	v.n_re = 0;
	v.n_im = 0;
	v.i = 0;
	while (v.i < v.max_i)
	{
		v.o_re = v.n_re;
		v.o_im = v.n_im;
		imsqr = v.n_im * v.n_im;
		resqr = v.n_re * v.n_re;
		v.n_im = 4 * v.o_im * v.o_re * (resqr - imsqr) + v.c_re;
		v.n_re = (imsqr * imsqr + resqr * resqr) - 6 * resqr * imsqr + v.c_im;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}
