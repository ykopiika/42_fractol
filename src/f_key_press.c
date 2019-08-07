/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_key_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:21:51 by ykopiika          #+#    #+#             */
/*   Updated: 2019/06/20 18:21:53 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			f_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		f_print(t_frctl *frt)
{
	int color;
	int s;

	s = 1;
	f_print_frtl(frt, VAL_B, frt->frtl[FRCTL]);
	if (FLAG.menu == 0)
	{
		if (FLAG.menu_color == 0)
			color = RED;
		else if (FLAG.menu_color == 1)
			color = GREEN;
		else if (FLAG.menu_color == 2)
			color = BLUE;
		else
			color = WHITE;
		mlx_string_put(MLX, WIN, 4, 1, color, "zoom:          Q W "
											"or mouse wheel");
		mlx_string_put(MLX, WIN, 4, 17, color, "max iter:      A S");
		mlx_string_put(MLX, WIN, 4, 33, color, "reset:         R");
		mlx_string_put(MLX, WIN, 475, 1, color, "minus/plus"
													" for RGB/const:  - +");
		mlx_string_put(MLX, WIN, 475, 17, color, "RGB/const:     1 2 3 4");
		mlx_string_put(MLX, WIN, 940, 1, color, "color frctl/menu:    C/Z");
		mlx_string_put(MLX, WIN, 940, 17, color, "lock JULIA:        space");
	}
}

static void	change_rgb(int key, t_frctl *frt)
{
	if (key == KEY_1 || key == KEY_2 || key == KEY_3)
	{
		if (key == KEY_1 && FLAG.minus_plus == 1)
			VAL_B.rgb.r++;
		else if (key == KEY_2 && FLAG.minus_plus == 1)
			VAL_B.rgb.g++;
		else if (key == KEY_3 && FLAG.minus_plus == 1)
			VAL_B.rgb.b++;
		else if (key == KEY_1 && FLAG.minus_plus == 0)
			VAL_B.rgb.r--;
		else if (key == KEY_2 && FLAG.minus_plus == 0)
			VAL_B.rgb.g--;
		else if (key == KEY_3 && FLAG.minus_plus == 0)
			VAL_B.rgb.b--;
	}
	if (key == KEY_4)
	{
		if (FLAG.minus_plus == 1 && VAL_B.const_color < MAX_CNST_CLR)
			VAL_B.const_color++;
		if (FLAG.minus_plus == 0 && VAL_B.const_color > MIN_CNST_CLR)
			VAL_B.const_color--;
	}
	f_print(frt);
}

static void	iter_color(int key, t_frctl *frt)
{
	if (key == KEY_R)
		VAL_B = VAL_A;
	else if (key == KEY_C)
	{
		if (FLAG.color == 0)
			FLAG.color = 1;
		else if (FLAG.color == 1)
			FLAG.color = 2;
		else
			FLAG.color = 0;
	}
	else if (key == KEY_S || key == KEY_A)
	{
		if (key == KEY_S && VAL_B.max_i < 300)
			VAL_B.max_i += 5;
		if (key == KEY_A && VAL_B.max_i > 7)
			VAL_B.max_i -= 5;
	}
	else if (key == KEY_Z && (FLAG.menu_color == 0 || FLAG.menu_color == 2))
		FLAG.menu_color = (FLAG.menu_color == 0) ? 1 : 3;
	else if (key == KEY_Z && (FLAG.menu_color == 1 || FLAG.menu_color == 3))
		FLAG.menu_color = (FLAG.menu_color == 1) ? 2 : 0;
	f_print(frt);
}

int			f_key_press(int key, t_frctl *frt)
{
	if (key == KEY_ESCAPE)
		f_close(frt);
	if (key == KEY_W || key == KEY_Q)
		f_key_zoom(key, frt);
	if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN)
		f_key_move(key, frt);
	if (key == KEY_TAB)
	{
		FLAG.menu = (FLAG.menu == 0) ? 1 : 0;
		f_print(frt);
	}
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		change_rgb(key, frt);
	if (key == KEY_R || key == KEY_C || key == KEY_S || key == KEY_A)
		iter_color(key, frt);
	if (key == KEY_Z)
		iter_color(key, frt);
	if (key == KEY_SPACE)
		FLAG.lock_julia = (FLAG.lock_julia == 0) ? 1 : 0;
	if (key == KEY_EQUAL || key == KEY_MINUS)
		FLAG.minus_plus = (key == KEY_EQUAL) ? 1 : 0;
	return (0);
}
