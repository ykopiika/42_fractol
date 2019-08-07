/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:26:31 by ykopiika          #+#    #+#             */
/*   Updated: 2019/05/16 14:26:33 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		f_key_zoom(int key, t_frctl *frt)
{
	int expon;

	if (key == KEY_W && VAL_B.count_zoom < MAX_ZOOM)
		VAL_B.count_zoom++;
	else if (key == KEY_Q && VAL_B.count_zoom > MIN_ZOOM)
		VAL_B.count_zoom--;
	if (VAL_B.count_zoom < -12)
		return ;
	expon = abs(VAL_B.count_zoom);
	if (VAL_B.count_zoom >= 0)
		VAL_B.zoom = VAL_A.zoom * pow(1.5, expon);
	else
		VAL_B.zoom = VAL_A.zoom * pow(0.5, expon);
	f_print(frt);
}

void		f_key_move(int key, t_frctl *frt)
{
	VAL_B.mouse.re = 1.5 * ((WIN_W / 2.5) - (WIN_W / 2))
						/ (0.5 * VAL_B.zoom * WIN_W) + VAL_B.mv_x;
	VAL_B.mouse.im = ((WIN_H / 3) - WIN_H / 2)
						/ (0.5 * VAL_B.zoom * WIN_H) + VAL_B.mv_y;
	if (key == KEY_LEFT)
		VAL_B.mv_x -= VAL_B.mv_x - VAL_B.mouse.re;
	else if (key == KEY_RIGHT)
		VAL_B.mv_x += VAL_B.mv_x - VAL_B.mouse.re;
	else if (key == KEY_UP)
		VAL_B.mv_y -= VAL_B.mv_y - VAL_B.mouse.im;
	else if (key == KEY_DOWN)
		VAL_B.mv_y += VAL_B.mv_y - VAL_B.mouse.im;
	f_print(frt);
}

static int	mouse_press(int key, int x, int y, t_frctl *frt)
{
	if (key != MOUSE_WHEEL_UP && key != MOUSE_WHEEL_DOWN)
		return (0);
	VAL_B.mouse.re = 1.5 * ((double)x - (double)WIN_W / 2)
					/ (0.5 * VAL_B.zoom * WIN_W) + VAL_B.mv_x;
	VAL_B.mouse.im = ((double)y - (double)WIN_H / 2)
					/ (0.5 * VAL_B.zoom * WIN_H) + VAL_B.mv_y;
	VAL_B.mv_x -= VAL_B.mv_x - VAL_B.mouse.re;
	VAL_B.mv_y -= VAL_B.mv_y - VAL_B.mouse.im;
	if (key == MOUSE_WHEEL_UP)
		f_key_zoom(KEY_W, frt);
	else
		f_key_zoom(KEY_Q, frt);
	VAL_B.mouse.re = 1.5 * ((double)x - (double)WIN_W / 2)
					/ (0.5 * VAL_B.zoom * WIN_W) + VAL_B.mv_x;
	VAL_B.mouse.im = ((double)y - (double)WIN_H / 2)
					/ (0.5 * VAL_B.zoom * WIN_H) + VAL_B.mv_y;
	VAL_B.mv_x += VAL_B.mv_x - VAL_B.mouse.re;
	VAL_B.mv_y += VAL_B.mv_y - VAL_B.mouse.im;
	f_print(frt);
	return (0);
}

static int	mouse_move(int x, int y, t_frctl *frt)
{
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H || FRCTL != JULIA
		|| FLAG.lock_julia == 1 || VAL_B.zoom != VAL_A.zoom)
		return (0);
	VAL_B.c_im = (y * -1) * (2.4 / WIN_H) + 1.2;
	VAL_B.c_re = ((3.5 / WIN_W) * x) - 2.5;
	f_print(frt);
	return (0);
}

void		f_hook(t_frctl *frt)
{
	mlx_hook(WIN, 2, 0, f_key_press, (void *)frt);
	mlx_hook(WIN, 17, 0, f_close, (void *)0);
	mlx_hook(WIN, 4, 0, mouse_press, (void *)frt);
	mlx_hook(WIN, 6, 0, mouse_move, (void *)frt);
}
