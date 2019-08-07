/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:01:04 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/26 17:01:06 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_wr(int n, int d, char *r)
{
	int		n1;

	n1 = n;
	while (n / d == 0 && n != 0)
		d /= 10;
	while (d && n != 0)
	{
		if (n > 0)
			*r = (char)((n1 / d) + '0');
		else
			*r = (char)(((n1 / d) * (-1)) + '0');
		n1 -= (n1 / d) * d;
		r++;
		d /= 10;
	}
	return (r);
}

char		*ft_itoa(int n)
{
	char	*r;
	char	*ret;
	int		d;

	r = ft_strnew(ft_len_int(n));
	if (!r)
		return (NULL);
	ret = r;
	d = 1000000000;
	if (n == 0)
		*r = '0';
	if (n < 0)
		r++[0] = '-';
	r = ft_itoa_wr(n, d, r);
	return (ret);
}
