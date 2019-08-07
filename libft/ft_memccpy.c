/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:24:46 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/04 19:24:49 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	c1;
	size_t			i;

	i = 0;
	c1 = (unsigned char)c;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if ((unsigned char)s[i] == (unsigned char)c1)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
