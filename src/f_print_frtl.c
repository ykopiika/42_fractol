/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_frtl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 20:06:03 by ykopiika          #+#    #+#             */
/*   Updated: 2019/05/26 20:06:08 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	f_get_color(t_vrbl *v, t_frctl *frt)
{
	t_color	clr;
	double	modl;
	double	mu_cnst;
	double	cnst;

	modl = sqrt(v->n_re * v->n_re + v->n_im * v->n_im);
	mu_cnst = (double)v->i - (log(log(modl))) / log(2.0);
	cnst = mu_cnst / v->max_i;
	cnst += v->const_color * 0.01;
	clr.r = (unsigned char)((v->rgb.r) * (1 - cnst) * cnst * cnst * cnst * 255);
	clr.g = (unsigned char)((v->rgb.g) * (1 - cnst) * (1 - cnst) * cnst
			* cnst * 255);
	clr.b = (unsigned char)((v->rgb.b) * (1 - cnst) * (1 - cnst) * (1 - cnst)
			* cnst * 255);
	if (FLAG.color == 0)
		v->clr = (int)(clr.r) | (int)(clr.g) << 8
				| (int)(clr.b) << 16 | 0 << 24;
	else if (FLAG.color == 1)
		v->clr = (int)(clr.r) | (int)(clr.b) << 8
				| (int)(clr.g) << 16 | 0 << 24;
	else if (FLAG.color == 2)
		v->clr = (int)(clr.b) | (int)(clr.g) << 8
				| (int)(clr.r) << 16 | 0 << 24;
	return (v->clr);
}

static void	*print(void *thrds)
{
	t_thrds	*thrd;
	int		color;

	thrd = (t_thrds*)thrds;
	thrd->v.y = thrd->start;
	while (thrd->v.y < thrd->end)
	{
		thrd->v.x = 0;
		while (thrd->v.x < WIN_W)
		{
			thrd->v = thrd->f_frtl(thrd->v);
			if (thrd->v.i != thrd->v.max_i && thrd->v.i > 0)
				color = f_get_color(&thrd->v, thrd->frt);
			else
				color = 0;
			thrd->IMG_DATA[thrd->v.y * WIN_W + thrd->v.x] = color;
			thrd->v.x++;
		}
		thrd->v.y++;
	}
	return (thrds);
}

void		f_print_frtl(t_frctl *frt, t_vrbl v, t_vrbl (*fractal)(t_vrbl))
{
	t_thrds		thrds[THRDS];
	pthread_t	p_thr[THRDS];
	int			i;
	int			step;

	step = 0;
	i = -1;
	thrds[0].v = v;
	thrds[0].f_frtl = fractal;
	thrds[0].start = 0;
	thrds[0].end = 0;
	thrds[0].frt = frt;
	while (++i < THRDS)
	{
		if (i > 0)
			thrds[i] = thrds[i - 1];
		thrds[i].start = step;
		step += WIN_H / THRDS;
		thrds[i].end = step;
		pthread_create(&p_thr[i], NULL, print, &thrds[i]);
	}
	i = -1;
	while (++i < THRDS)
		pthread_join(p_thr[i], NULL);
	mlx_put_image_to_window(MLX, WIN, IMG_PTR, 0, 0);
}
