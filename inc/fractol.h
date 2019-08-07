/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:28:58 by ykopiika          #+#    #+#             */
/*   Updated: 2019/06/30 20:08:27 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>

# define MLX 			frt->mlx_data.mlx_ptr
# define WIN 			frt->mlx_data.win_ptr
# define IMG_PTR 		frt->img_data.img_ptr
# define IMG_DATA 		frt->img_data.img_data
# define FRCTL 			frt->frctl_id
# define FLAG 			frt->flag
# define VAL_A 			frt->value_a
# define VAL_B 			frt->value_b

# define KEY_ESCAPE			53
# define MOUSE_WHEEL_UP		5
# define MOUSE_WHEEL_DOWN	4
# define KEY_1				18
# define KEY_2				19
# define KEY_3				20
# define KEY_MINUS			27
# define KEY_EQUAL			24
# define KEY_Q				12
# define KEY_W				13
# define KEY_R				15
# define KEY_C				8
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_SPACE			49
# define KEY_4				21
# define KEY_TAB			48
# define KEY_A				0
# define KEY_S				1
# define KEY_Z				6

# define WIN_W 				1200
# define WIN_H 				800
# define MAX_ZOOM 			110
# define MIN_ZOOM 			-12
# define MIN_CNST_CLR		-40
# define MAX_CNST_CLR		40
# define THRDS				8

# define JULIA				0
# define MDLBRT				1
# define BRNG_SHIP			2
# define HEART_MDLBRT		3
# define FISH_MDLBRT		4
# define CUBIC_MDLBRT		5
# define ARM_MDLBRT			6
# define TRNGL_MDLBRT		7

# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF

typedef struct			s_re_im
{
	double				re;
	double				im;
}						t_re_im;

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct			s_vrbl
{
	int					i;
	int					x;
	int					y;
	int					clr;
	int					max_i;
	int					count_zoom;
	int					const_color;
	double				zoom;
	double				mv_x;
	double				mv_y;
	double				n_re;
	double				n_im;
	double				o_re;
	double				o_im;
	double				c_re;
	double				c_im;
	t_color				rgb;
	t_re_im				mouse;
}						t_vrbl;

typedef struct			s_img
{
	void				*img_ptr;
	int					*img_data;
	int					endian;
	int					size;
	int					bpp;
}						t_img;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_mlx;

typedef struct			s_flag
{
	int					lock_julia;
	int					color;
	int					minus_plus;
	int					menu;
	int					menu_color;
}						t_flag;

typedef struct			s_frctl
{
	int					frctl_id;
	t_img				img_data;
	t_mlx				mlx_data;
	t_vrbl				value_a;
	t_vrbl				value_b;
	t_vrbl				(*frtl[8])(t_vrbl);
	t_flag				flag;
}						t_frctl;

typedef struct			s_thrds
{
	int					start;
	int					end;
	t_frctl				*frt;
	t_vrbl				v;
	t_vrbl				(*f_frtl)(t_vrbl);
}						t_thrds;

int						f_key_press(int key, t_frctl *frt);
int						f_close(void *param);
t_vrbl					f_julia(t_vrbl v);
t_vrbl					f_mandelbrot(t_vrbl	v);
t_vrbl					f_burning_ship(t_vrbl v);
t_vrbl					f_heart_mandelbrot(t_vrbl v);
t_vrbl					f_fish_mandelbrot(t_vrbl v);
t_vrbl					f_cubic_mandelbrot(t_vrbl v);
t_vrbl					f_arm_mandelbrot(t_vrbl v);
t_vrbl					f_trngl_mandelbrot(t_vrbl v);
void					f_hook(t_frctl *frt);
void					f_error(int err_nb);
void					f_value_frtl(t_frctl *frt);
void					f_key_zoom(int key, t_frctl *frt);
void					f_key_move(int key, t_frctl *frt);
void					f_print(t_frctl *frt);
void					f_print_frtl(t_frctl *frt, t_vrbl v,
										t_vrbl (*fractal)(t_vrbl));

#endif
