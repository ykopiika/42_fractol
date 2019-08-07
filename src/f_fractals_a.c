/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fractals_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:29:18 by ykopiika          #+#    #+#             */
/*   Updated: 2019/05/27 14:29:21 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vrbl	f_julia(t_vrbl v)
{
	v.n_re = 1.5 * (v.x - WIN_W / 2) / (0.5 * v.zoom * WIN_W) + v.mv_x;
	v.n_im = (v.y - WIN_H / 2) / (0.5 * v.zoom * WIN_H) + v.mv_y;
	v.i = 0;
	while (v.i < v.max_i)
	{
		v.o_re = v.n_re;
		v.o_im = v.n_im;
		v.n_re = v.o_re * v.o_re - v.o_im * v.o_im + v.c_re;
		v.n_im = 2 * v.o_re * v.o_im + v.c_im;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}

t_vrbl	f_mandelbrot(t_vrbl v)
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
		v.n_re = v.o_re * v.o_re - v.o_im * v.o_im + v.c_re;
		v.n_im = 2 * v.o_re * v.o_im + v.c_im;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}

t_vrbl	f_burning_ship(t_vrbl v)
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
		v.n_re = v.o_re * v.o_re - v.o_im * v.o_im + v.c_re;
		v.n_im = 2 * fabs(v.o_re * v.o_im) + v.c_im;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}

t_vrbl	f_heart_mandelbrot(t_vrbl v)
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
		v.n_re = v.o_re * v.o_re - v.o_im * v.o_im + v.c_re;
		v.n_im = 2 * fabs(v.o_re) * v.o_im + v.c_im;
		if ((v.n_re * v.n_re + v.n_im * v.n_im) > 4)
			break ;
		v.i++;
	}
	return (v);
}
